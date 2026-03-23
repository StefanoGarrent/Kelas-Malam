<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>cat lovers</title>
    <link rel="stylesheet" href="ubah.css">
  </head>
  <body>
    <?php
      $jenis = array('Garong', 'Anggora', 'Garfield');
      $deskripsi = array("ini kucing garong sangat ganas", "kucing anggora bulunya bagus", "kucing ini berwarna oranye");

    ?>


    <main class="container">
      <section class="pertama">
        <h1>Selamat Datang di Komunitas Cat lovers</h1>
        <p class="deskripsi">
          Lorem ipsum, dolor sit amet consectetur adipisicing elit. Maiores ducimus
          nam ullam assumenda unde, sed animi magnam accusantium fugiat! Minima
          corporis recusandae nisi. Porro inventore ducimus sunt eligendi, ad rerum?
        </p>
      </section>
      <section class="jenis">
        <h2>ini list jenis kucing</h2>
        <ul>
          <?php
            $i = 0;
            while ($i < 3) {

          ?>
          <li>
            <a
            href="">
            Kucing <?php echo $jenis[$i]; ?>
          </a>
          <p class="penjelasan"><?php echo $deskripsi[0]; ?>
          <?php 
              $deskripsi[$i];
              $i++;

          ?></p>
        <li>
          <?php } ?>
      </ul>
      </section>
    <section class="join">
      <h2>Mari Join Komunitas</h2>
      <form method="post" action="halo.html">
        <label for="nama" class="nama">Nama:</label>
        <input type="text" id="nama" name="nama">
        <label for="password" class="password">Password:</label>
        <input type="password" id="password" name="password">
        <input type="submit" value="kirim">
      </form>
    </section>
  </main>
  </body>
</html>
