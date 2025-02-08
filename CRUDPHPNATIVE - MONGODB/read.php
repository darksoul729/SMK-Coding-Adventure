<?php
require 'config.php';

$users = $collection->find();
foreach ($users as $user) {
    echo "ID: " . $user['_id'] . " - Nama: " . $user['name'] . " - Email: " . $user['email'] . "<br>";
}
?>
