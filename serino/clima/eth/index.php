<?php
	$link = mysqli_connect("localhost","root","","estem");
	/*
		GETS: 
		temperatura
		humedad
		presion
		uv
		viento
		lluvia
		dioxido
		monoxido
		amoniaco
		direccion
	
	*/


	if((isset($_GET['temperatura'])) && (isset($_GET['humedad'])) && (isset($_GET['presion'])) && (isset($_GET['uv'])) && (isset($_GET['viento'])) && (isset($_GET['lluvia'])) && (isset($_GET['dioxido'])) && (isset($_GET['monoxido'])) && (isset($_GET['amoniaco'])) && (isset($_GET['direccion'])) ){

		$temperatura = $_GET['temperatura'];
		$humedad = $_GET['humedad'];
		$presion = $_GET['presion'];
		$uv = $_GET['uv'];
		$viento = $_GET['viento'];
		$lluvia = $_GET['lluvia'];
		$dioxido = $_GET['dioxido'];
		$monoxido = $_GET['monoxido'];
		$amoniaco = $_GET['amoniaco'];
		$direccion = $_GET['direccion'];
	
		$sql1 = "INSERT INTO registros (`temperatura`,`humedad`,`presion`,`uv`,`viento`,`lluvia`,`dioxido`,`monoxido`,`amoniaco`,`direccion`) VALUES ('$temperatura','$humedad','$presion','$uv','$viento','$lluvia','$dioxido','$monoxido','$amoniaco','$direccion')";

		mysqli_query($link, $sql1);	




	}



	




?>
<!DOCTYPE html>
<html>
<head>
	<title>Sender Code</title>
</head>
<body>




	<h1>Lamento informarte, que tu codigo esta funcionando perfecto</h1>


</body>
</html>