<?php
require 'config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];

    $insertResult = $collection->insertOne([
        'name' => $name,
        'email' => $email
    ]);

    echo "Data berhasil ditambahkan dengan ID: " . $insertResult->getInsertedId();
}
?>
<form method="POST">
    <input type="text" name="name" placeholder="Nama" required>
    <input type="email" name="email" placeholder="Email" required>
    <button type="submit">Tambah</button>
</form>
