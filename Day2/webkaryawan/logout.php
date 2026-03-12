<?php
session_start();
session_destroy();//menghancurkan session saat ini

header("location:login.php?pesan=logout");
?>