<?php
	require("conexion.php");
	
	$sql1 = "SELECT * from `registros` ORDER BY id DESC LIMIT 1";
	$a = mysqli_query($link, $sql1);
	$resultActuales = mysqli_fetch_array($a);
	$hoy = $resultActuales['time'];
	echo '
	<h2 style="margin-left: 7%;">ACTUAL VALUES: '.$hoy.'</h2>
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
				<th>Wind Direction</th>
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
	$direccion = $resultActuales['direccion'];
	$strDireccion = ""; 
	switch($direccion){
		case 1: 
			$strDireccion = "N";
		break; 
		case 2: 
			$strDireccion = "N0";
		break;
		case 3: 
			$strDireccion = "O";
		break; 
		case 4: 
			$strDireccion = "SO";
		break; 
		case 5: 
			$strDireccion = "S";
		break; 
		case 6: 
			$strDireccion = "SE";
		break; 
		case 7: 
			$strDireccion = "E"; 
		break; 
		case 8: 
			$strDireccion = "NE"; 
		break; 
		default: 
			$strDireccion = "error";
		break; 
	}

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
				<td>$strDireccion</td>

			</tr>
		</table>

	";
?>


