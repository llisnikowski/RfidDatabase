<?php
if(isset($_GET["uid"])) {
   	$uid = $_GET["uid"];

   	$servername = "localhost";
   	$username = "user";
   	$password = "*****";
   	$database_name = "db_esp32";
	
   	$connection = new mysqli($servername, $username, $password, $database_name);
   	if ($connection->connect_error) {
      	die("MySQL connection failed: " . $connection->connect_error);
   	}
   	  	
   	$sql = "SELECT firstName, lastName, status FROM `rfidUsers` WHERE rfidUid=$uid;";
   	$result = $connection->query($sql);
  	
   	if ($result->num_rows > 0){
   		$firstRow = $result->fetch_assoc();
   		$status;
   		switch ($firstRow["status"]) {
    	case "unknown":
        	$status = "0";
        	break;
    	case "no access":
        	$status = "1";
        	break;
    	case "full access":
        	$status = "2";
        	break;
		}
   		echo $firstRow["firstName"].";".$firstRow["lastName"].";".$status.";" ;
   	}
   	else{
   		echo " ; ; ; ;";
   	}

   	$connection->close();
   	
   	
} else {
   	echo " ; ; ; ;";
}
?>