<?php
if(isset($_GET["uid"])) {
   	$uid = $_GET["uid"];

   	$servername = "localhost";
   	$username = "user";
   	$password = "******";
   	$database_name = "db_esp32";


   	$connection = new mysqli($servername, $username, $password, $database_name);
   	if ($connection->connect_error) {
      	die("MySQL connection failed: " . $connection->connect_error);
   	}
 
   	$sql = "SELECT firstName, lastName, status FROM `rfidUsers` WHERE rfidUid=$uid;";
   	$result = $connection->query($sql);

   	if ($result->num_rows > 0){
   		echo "true";
   	}
   	else
   	{
   		$sql = "INSERT INTO rfidUsers(rfidUid) VALUES ($uid);";
   		$connection->query($sql);
   		echo "false";
   	}
   	$connection->close();
} else {
   	echo "false";
}
?>