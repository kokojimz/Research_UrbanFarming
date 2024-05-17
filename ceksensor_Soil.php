<?php
// Connect to database
$conn = mysqli_connect("localhost", "root", "", "websensorsoil");

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Read table sensor content
$sql = mysqli_query($conn, "SELECT * FROM sensor_sm ORDER BY id DESC LIMIT 1");

if ($sql) {
    $data = mysqli_fetch_array($sql);
    if ($data) {
        echo $data['nilai_sensor'];
    } else {
        echo "No data found.";
    }
} else {
    echo "Error in query execution: " . mysqli_error($conn);
}
