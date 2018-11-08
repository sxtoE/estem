<?php
	$link = mysqli_connect("localhost","root","","estem");

	/*
	Direcciones viento: 
	1 norte
	2 noroeste
	3 oeste
	4 suroeste
	5 sur
	6 sureste
	7 este
	8 noreste
	0 error. 

	*/

	if((isset($_GET['temperatura'])) && (isset($_GET['humedad'])) && (isset($_GET['presion'])) && (isset($_GET['uv'])) && (isset($_GET['viento'])) && (isset($_GET['lluvia'])) && (isset($_GET['dioxido'])) && (isset($_GET['monoxido'])) && (isset($_GET['amoniaco'])) && (isset($_GET['direccion']))){

		$temperatura = $_GET['temperatura'];
		$humedad = $_GET['humedad'];
		$presion = $_GET['presion'];
		$uv = $_GET['uv'];
		$viento = $_GET['viento'];
		$lluvia = $_GET['lluvia'];
		$dioxido = $_GET['dioxido'];
		$monoxido = $_GET['monoxido'];
		$amoniaco = $_GET['amoniaco'];
		$dirviento = $_GET['direccion'];

		$sql1 = "INSERT INTO registros (`temperatura`,`humedad`,`presion`,`uv`,`viento`,`lluvia`,`dioxido`,`monoxido`,`amoniaco`) VALUES ('$temperatura','$humedad','$presion','$uv','$viento','$lluvia','$dioxido','$monoxido','$amoniaco')";

		mysqli_query($link, $sql1);




	}



	




?>
<!DOCTYPE html>
<html>
<head>
	<title>Hola, soy matu</title>
</head>
<body>




	<h1>Lamento informarte, que tu codigo esta funcionando perfecto</h1>


</body>
</html>