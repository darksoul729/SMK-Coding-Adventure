// URL backend API
const apiUrl = "http://127.0.0.1:8080/products";

// Fungsi untuk mengambil semua produk
async function fetchProducts() {
  const response = await fetch(apiUrl);
  const products = await response.json();

  const tableBody = document.querySelector("#productTable tbody");
  tableBody.innerHTML = ""; // Kosongkan tabel sebelum menambahkan data baru

  products.forEach(product => {
    const row = document.createElement("tr");
    row.innerHTML = `
      <td>${product.id}</td>
      <td>${product.name}</td>
      <td>${product.price}</td>
      <td><button class="delete" onclick="deleteProduct(${product.id})">Delete</button></td>
    `;
    tableBody.appendChild(row);
  });
}

// Fungsi untuk menambahkan produk baru
document.getElementById("addProductForm").addEventListener("submit", async (e) => {
  e.preventDefault();

  const name = document.getElementById("name").value;
  const price = document.getElementById("price").value;

  const response = await fetch(apiUrl, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({ name, price: parseInt(price) }),
  });

  if (response.ok) {
    fetchProducts(); // Refresh the product list after adding
    document.getElementById("addProductForm").reset(); // Clear form fields
  }
});

// Fungsi untuk menghapus produk
async function deleteProduct(id) {
  const response = await fetch(`${apiUrl}/${id}`, {
    method: "DELETE",
  });

  if (response.ok) {
    fetchProducts(); // Refresh the product list after deleting
  }
}

// Ambil daftar produk saat halaman dimuat
window.onload = fetchProducts;
