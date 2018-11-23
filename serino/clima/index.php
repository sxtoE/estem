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
		<div id="chartContainer" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer2" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer3" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer4" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer5" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer6" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer7" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer8" style="height: 300px; width: 100%;"></div>
		<div id="chartContainer9" style="height: 300px; width: 100%;"></div>


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
	<input type="hidden" id="oculto"/>
</div>



<script src="jquery.min.js"></script>
<script>jQuery.noConflict();</script>
<script src="canvas.min.js"></script>
<script src="dibujarSemanales.js"></script>

</body>
</html>