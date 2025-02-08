<?php
require 'config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = new MongoDB\BSON\ObjectId($_POST['id']);

    $deleteResult = $collection->deleteOne(['_id' => $id]);

    echo "Data berhasil dihapus";
}
?>
<form method="POST">
    <input type="text" name="id" placeholder="ID" required>
    <button type="submit">Hapus</button>
</form>
