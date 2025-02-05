package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"

	"github.com/gorilla/mux"
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

// Definisikan struct yang akan menjadi model
type Product struct {
	ID    uint   `json:"id"`
	Name  string `json:"name"`
	Price int    `json:"price"`
}



var db *gorm.DB
var err error

// Initialize DB
func InitDB() {
	// Menghubungkan ke database SQLite
	database, err := gorm.Open(sqlite.Open("product.db"), &gorm.Config{})
	if err != nil {
		log.Fatal("Gagal terhubung ke database:", err)
	}

	// Auto-migrate untuk membuat tabel jika belum ada
	database.AutoMigrate(&Product{})
	db = database
}

// Create Product
func createProduct(w http.ResponseWriter, r *http.Request) {
	var product Product
	decoder := json.NewDecoder(r.Body)
	if err := decoder.Decode(&product); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}
	db.Create(&product)
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusCreated)
	json.NewEncoder(w).Encode(product)
}

// Read All Products
func getAllProducts(w http.ResponseWriter, r *http.Request) {
	var products []Product
	db.Find(&products)
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(products)
}

// Read Single Product
func getProduct(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	var product Product
	if err := db.First(&product, params["id"]).Error; err != nil {
		http.Error(w, "Product not found", http.StatusNotFound)
		return
	}
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(product)
}

// Update Product
func updateProduct(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	var product Product
	if err := db.First(&product, params["id"]).Error; err != nil {
		http.Error(w, "Product not found", http.StatusNotFound)
		return
	}

	decoder := json.NewDecoder(r.Body)
	if err := decoder.Decode(&product); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	db.Save(&product)
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(product)
}

// Delete Product
func deleteProduct(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	if err := db.Delete(&Product{}, params["id"]).Error; err != nil {
		http.Error(w, "Product not found", http.StatusNotFound)
		return
	}
	w.WriteHeader(http.StatusNoContent)
}

func main() {
	InitDB()

	// Inisialisasi router
	r := mux.NewRouter()

	r.PathPrefix("/static/").Handler(http.StripPrefix("/static/", http.FileServer(http.Dir("./static"))))

	// Routes
	r.HandleFunc("/products", createProduct).Methods("POST")
	r.HandleFunc("/products", getAllProducts).Methods("GET")
	r.HandleFunc("/products/{id}", getProduct).Methods("GET")
	r.HandleFunc("/products/{id}", updateProduct).Methods("PUT")
	r.HandleFunc("/products/{id}", deleteProduct).Methods("DELETE")

	// Jalankan server
	fmt.Println("Server berjalan pada port 8080...")
	log.Fatal(http.ListenAndServe(":8080", r))
}
