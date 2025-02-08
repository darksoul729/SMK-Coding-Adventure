<?php
require 'vendor/autoload.php'; // Memastikan MongoDB sudah terinstal dengan Composer

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->selectDatabase("crud_db");
$collection = $database->selectCollection("users");

$action = isset($_GET['action']) ? $_GET['action'] : '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Proses tambah atau update data
    $name = $_POST['name'];
    $email = $_POST['email'];

    if ($action == 'add') {
        // Menambahkan user baru
        $insertResult = $collection->insertOne([
            'name' => $name,
            'email' => $email
        ]);
        $message = "User berhasil ditambahkan dengan ID: " . $insertResult->getInsertedId();
    } elseif ($action == 'update' && isset($_POST['id'])) {
        // Update user
        $id = new MongoDB\BSON\ObjectId($_POST['id']);
        $updateResult = $collection->updateOne(
            ['_id' => $id],
            ['$set' => ['name' => $name, 'email' => $email]]
        );
        $message = "User berhasil diperbarui.";
    }
}

// Menghapus data
if (isset($_GET['delete'])) {
    $id = new MongoDB\BSON\ObjectId($_GET['delete']);
    $deleteResult = $collection->deleteOne(['_id' => $id]);
    $message = "User berhasil dihapus.";
}

// Ambil data user untuk ditampilkan
$users = $collection->find();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>MongoDB User Management</title>
    <!-- Menambahkan Tailwind CSS via CDN -->
    <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100 font-sans">

    <div class="container mx-auto p-6">

        <h1 class="text-3xl font-bold text-center mb-6">User Management</h1>

        <!-- Pesan jika ada aksi -->
        <?php if (isset($message)): ?>
            <div class="bg-green-500 text-white p-3 rounded mb-4"><?= $message ?></div>
        <?php endif; ?>

        <!-- Form untuk menambah atau memperbarui user -->
        <h2 class="text-xl font-semibold mb-4"><?= $action == 'update' ? 'Update' : 'Add' ?> User</h2>
        <form method="POST" class="space-y-4">
            <?php if ($action == 'update' && isset($_GET['id'])): ?>
                <input type="hidden" name="id" value="<?= $_GET['id'] ?>">
            <?php endif; ?>
            <div>
                <label for="name" class="block text-sm font-medium text-gray-700">Name</label>
                <input type="text" name="name" required class="mt-1 block w-full px-4 py-2 border border-gray-300 rounded-md shadow-sm focus:outline-none focus:ring-2 focus:ring-blue-500" />
            </div>
            <div>
                <label for="email" class="block text-sm font-medium text-gray-700">Email</label>
                <input type="email" name="email" required class="mt-1 block w-full px-4 py-2 border border-gray-300 rounded-md shadow-sm focus:outline-none focus:ring-2 focus:ring-blue-500" />
            </div>
            <button type="submit" class="mt-4 w-full bg-blue-500 text-white py-2 px-4 rounded-md hover:bg-blue-600"><?= $action == 'update' ? 'Update' : 'Add' ?> User</button>
        </form>

        <h2 class="text-xl font-semibold mt-8 mb-4">List of Users</h2>
        <table class="min-w-full bg-white border border-gray-300 rounded-md">
            <thead>
                <tr class="bg-gray-200">
                    <th class="px-4 py-2 text-left">ID</th>
                    <th class="px-4 py-2 text-left">Name</th>
                    <th class="px-4 py-2 text-left">Email</th>
                    <th class="px-4 py-2 text-left">Actions</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($users as $user): ?>
                    <tr>
                        <td class="px-4 py-2"><?= $user['_id'] ?></td>
                        <td class="px-4 py-2"><?= $user['name'] ?></td>
                        <td class="px-4 py-2"><?= $user['email'] ?></td>
                        <td class="px-4 py-2">
                            <a href="?action=update&id=<?= $user['_id'] ?>" class="text-blue-500 hover:text-blue-700">Edit</a> |
                            <a href="?delete=<?= $user['_id'] ?>" onclick="return confirm('Are you sure?')" class="text-red-500 hover:text-red-700">Delete</a>
                        </td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
    </div>

</body>
</html>
