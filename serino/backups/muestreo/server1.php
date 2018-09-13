<?php
	require("conexion.php");

	$sql1 = "SELECT * from `registros` ORDER BY id DESC LIMIT 1";
	$a = mysqli_query($link, $sql1);
	$resultActuales = mysqli_fetch_array($a);
	echo '
	<h2 style="margin-left: 7%;">ACTUAL VALUES:</h2>
		<table>
			<tr>
				<th>Temp[°C]</th>
				<th>Pressure[]</th>
				<th>Humidity[%]</th>
				<th>UV[%]</th>
				<th>Wind[Km/h]</th>
				<th>Rain[mm]</th>
				<th>Monoxide[]</th>
				<th>Dioxide[]</th>
				<th>Ammonia[]</th>
			</tr>
	';

	$temperatura = $resultActuales['temperatura'];
	$presion = $resultActuales['presion'];
	$humedad = $resultActuales['humedad'];
	$uv = $resultActuales['uv'];
	$viento = $resultActuales['viento'];
	$lluvia = $resultActuales['lluvia'];
	$monoxido = $resultActuales['monoxido'];
	$dioxido = $resultActuales['dioxido'];
	$amoniaco = $resultActuales['amoniaco'];

	echo "

			<tr>
				<td>$temperatura</td>
				<td>$presion</td>
				<td>$humedad</td>
				<td>$uv</td>
				<td>$viento</td>
				<td>$lluvia</td>
				<td>$monoxido</td>
				<td>$dioxido</td>
				<td>$amoniaco</td>

			</tr>
		</table>

	";
?>


