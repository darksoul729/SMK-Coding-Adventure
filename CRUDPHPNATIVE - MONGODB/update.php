<?php
require 'config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = new MongoDB\BSON\ObjectId($_POST['id']);
    $name = $_POST['name'];
    $email = $_POST['email'];

    $updateResult = $collection->updateOne(
        ['_id' => $id],
        ['$set' => ['name' => $name, 'email' => $email]]
    );

    echo "Data berhasil diperbarui";
}
?>
<form method="POST">
    <input type="text" name="id" placeholder="ID" required>
    <input type="text" name="name" placeholder="Nama" required>
    <input type="email" name="email" placeholder="Email" required>
    <button type="submit">Update</button>
</form>
