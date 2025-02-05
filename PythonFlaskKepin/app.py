from flask import Flask, render_template, request, jsonify
app = Flask(__name__)

# Simulasi database menggunakan list
data = []

@app.route('/')
def index():
    return render_template('index.html')

# Endpoint untuk mendapatkan semua data
@app.route('/items', methods=['GET'])
def get_items():
    return jsonify(data), 200

# Endpoint untuk menambahkan item
@app.route('/items', methods=['POST'])
def add_item():
    item = request.get_json()
    data.append(item)
    return jsonify(item), 201

# Endpoint untuk memperbarui item berdasarkan index
@app.route('/items/<int:index>', methods=['PUT'])
def update_item(index):
    if index < 0 or index >= len(data):
        return jsonify({"error": "Item not found"}), 404
    item = request.get_json()
    data[index] = item
    return jsonify(item), 200

# Endpoint untuk menghapus item berdasarkan index
@app.route('/items/<int:index>', methods=['DELETE'])
def delete_item(index):
    if index < 0 or index >= len(data):
        return jsonify({"error": "Item not found"}), 404
    deleted_item = data.pop(index)
    return jsonify(deleted_item), 200

if __name__ == '__main__':
    app.run(debug=True)
