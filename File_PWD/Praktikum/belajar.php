<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Belajar PHP</title>
</head>
<body>
    <?php
    $nama = "Reza";
    $tanggal = date("d F Y");
    
    echo "Hari ini saya belajar bahasa PHP <br>";
    echo("Nama: $nama Arab<br>");
    echo("Tanggal: $tanggal");
    ?>
    <h2>Form data mahasiswa</h2>
    <form action="hasil.php" method="post">
        Nama: <input type="text" name="Nama"><br><br>
        NIM: <input type="text" name="NIM"><br><br>
        Prodi: <input type="text" name="Prodi"><br><br>
        Fakultas: <input type="text" name="Fakultas"><br><br>
        Angkatan: <input type="text" name="angkatan"><br><br>
        <input type="Submit"> <input type="Reset">
    </form>
    <br><br>
    <?php
    $hari = date('d');
    $harga = 100;
    $pengunjung = 12;

    /*
    if($hari =="Tuesday"){
     echo "Hari yang menyenangkan";
    }else {
     echo "Hari yang melelahkan";
    }
*/
    echo ("jumlah pengunjung hari ini : $pengunjung <br>");
    echo "total pendapatan : ";  
    echo $harga * $pengunjung;
    ?>

</body>
</html>