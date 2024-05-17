<?php
// Connect to database
$conn = mysqli_connect("localhost", "root", "", "websensorsoil");
$value = $_GET['sensor'];

//update data in database from sensor
mysqli_query($conn, "INSERT INTO sensor_sm(nilai_sensor) VALUES('$value')");
