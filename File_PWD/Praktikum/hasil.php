!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hasil Inputan</title>
</head>
<body>
    <h1>Data Mahasiswa</h1>
    <?php
        echo ("Nama: $_POST[Nama]<br>");
        echo ("NIM: $_POST[NIM]<br>");
        echo ("Prodi: $_POST[Prodi]<br>");
        echo ("Fakultas: $_POST[Fakultas]<br>");
        echo ("Angkatan: $_POST[Angkatan]<br>");
    ?>
</body>
</html>