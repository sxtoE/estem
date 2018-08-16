<?php
	$link = mysqli_connect("localhost","root","","estem");

	if((isset($_GET['temperatura'])) && (isset($_GET['humedad'])) && (isset($_GET['presion'])) && (isset($_GET['uv'])) && (isset($_GET['viento'])) && (isset($_GET['lluvia'])) && (isset($_GET['dioxido'])) && (isset($_GET['monoxido'])) && (isset($_GET['amoniaco'])) ){

		$temperatura = $_GET['temperatura'];
		$humedad = $_GET['humedad'];
		$presion = $_GET['presion'];
		$uv = $_GET['uv'];
		$viento = $_GET['viento'];
		$lluvia = $_GET['lluvia'];
		$dioxido = $_GET['dioxido'];
		$monoxido = $_GET['monoxido'];
		$amoniaco = $_GET['amoniaco'];


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