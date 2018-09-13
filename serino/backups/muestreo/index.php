<!DOCTYPE html>
<html>
<head>
	<title>Clima|CTS</title>
	<link href="reset.css" rel="stylesheet">
	<link href="estilos_index.css" rel="stylesheet">
	<meta charset="utf-8">
</head>
<body>
<div id="contenedor">

	<div id="encabezado">
		<!--Presentación de ESTEM-->
		<div id="imagenPresentacion">
			<img src="imagenCTS.png" id="imagenCTS"/>
		</div>
		<div id="textoPresentacion">
			<h1>ESTACIÓN METEOROLÓGICA</h1>
			<br/>
			<h2>Colegio Tecnológico del Sur</h2>
			<h4><i>-Desarrollos de Sexto Electrónica 2018-</i></h4>
		</div>
		<div id="derechaPresentacion">
			<a href="https://accounts.google.com" target="_blank">Tu correo del CTS</a><br/><br/>
			<a href="https://es-la.facebook.com/CTSBariloche/" target="_blank">Facebook CTS</a>
		</div>

	</div>	
	<button id="reloadActual">Reload</button>
	<div id="actuales">
		<!--Valores actuales de temperatura, humedad, presión, uv, viento, lluvia, airquality
		Se obtienen con javascript  | actualizado automatico cada 10 min
		-->

		
	</div>
	<div id="pronostico">
		<!--Pronostico del tiempo, no disponible aun-->


	</div>


	<div id="semanal">
		<!--Graficos históricos de la última semana-->
		<h2 style="margin-left: 5%;">WEATHER THIS WEEK:</h2>

		<div id="SG_temperatura">
			<img src="imagenCTS.png" id="imagenCTS"/>
			
			<h4>Temperatura vs tiempo</h4>
		</div>
		<div id="SG_presion">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Presion vs tiempo</h4>
		</div>
		<div id="SG_humedad">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Humedad vs tiempo</h4>
		</div>
		<div id="SG_viento">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Viento vs tiempo</h4>
		</div>
		<div id="SG_lluvia">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Lluvia vs tiempo</h4>
		</div>
		<div id="SG_dioxido">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Dióxido vs tiempo</h4>
		</div>
		<div id="SG_monoxido">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Monóxido vs tiempo</h4>
		</div>
		<div id="SG_amoniaco">
			<img src="imagenCTS.png" id="imagenCTS"/>
			<h4>Amoníaco vs tiempo</h4>
		</div>





	</div>

	<div id="busq_pers">
		<!--Buscar datos de forma personalizada, con distintos parámetros-->
		<h2 style="margin-left: 5%;">MAKE YOUR OWN GRAPH</h2>
		<div id="opciones">
			<!-- Seleccionar rango de fechas, magnitud!-->
			<form>

				<h3> 
					Magnitud: 
						<select name="select_magnitud" id="select_magnitud">
							<option name="temperatura" value="1">Temperatura</option>
							<option name="presion" value="2">Presión</option>
							<option name="humedad" value="3">Humedad</option>
							<option name="viento" value="4">Viento</option>
							<option name="lluvia" value="5">Lluvia</option>
							<option name="uv" value="6">UV</option>
							<option name="dioxido" value="7">Dióxido</option>
							<option name="amoniaco" value="8">Amoníaco</option>
							<option name="monoxido" value="9">Monóxido</option> 
						</select>
						<br/><br/>
					Desde: 
					<input type="date" name="desde" id="input_date_desde"/>
					<br/><br/>
				     Hasta: 
				    <input type="date" name="hasta" id="input_date_hasta"/>
				    <br/><br/>
					<input type="submit" name="graficar" value="graficar"/>
				</h3>
			</form>
			
		</div>
		<div id="ownGraph">
			<img src="imagenCTS.png" id="imagenCTS"/>
		</div>
	</div>

</div>

<script src="jquery.min.js"></script>
<script src="datosActuales.js"></script>
</body>
</html>