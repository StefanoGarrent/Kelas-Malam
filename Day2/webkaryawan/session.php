<?php

session_start();
if(empty($_SESSION['email']))
{
    header("location:login.php?pesan=belum_login");
}

?>

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Halaman Utama</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
  </head>
  <body>
    <h1> Hai, <?= $_SESSION['email']?>! </h1>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
    <br>
    <h3>Data Karyawan</h3>
    <a href="logout.php">Logout</a>
    <table border=1>
        <tr>
            <th>Nama Karyawan</th>
            <th>No. Handphone</th>
            <th>Gaji</th>
            <th>Departemen</th>
        </tr>
        <?php
        include('koneksi.php');
        $data=mysqli_query($connect, 
        "SELECT e.first_name, e.last_name, e.phone_number,
        e.salary, d.department_name FROM employees e
        INNER JOIN departments d ON e.department_id=d.department_id");

        while($karyawan=mysqli_fetch_array($data))
        {?>
        <tr>
            <td> <?= $karyawan['first_name']?> <?= $karyawan['last_name']?> </td>
            <td> <?= $karyawan['phone_number']?> </td>
            <td> <?= $karyawan['salary']?> </td>
            <td> <?= $karyawan['department_name']?> </td> 
        </tr>

        <?php } ?>
    </table>
</body>
</html>