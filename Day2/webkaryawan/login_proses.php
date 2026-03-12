<?php
    session_start();
    $query=new mysqli('localhost', 'root', '', 'hr');

    $email= $_POST['email'];
    $password=$_POST['password'];

    $data=mysqli_query($query, "select * from admin where email='$email' and password='$password'")
    or die(mysqli_error($query));

    $cek=mysqli_num_rows($data);

    if($cek>0){
        $_SESSION['email']= $email;
        $_SESSION['password']=$password;
        header("location:session.php");
    }else{
        header("location:login.php?pesan=gagal");
    }
?>