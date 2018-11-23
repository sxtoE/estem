//Arrays wich have 2016  values for semanal graphs
var promTemperatura = [];
var promPresion = []; 
var promPresion = [];
var promUv = [];
var promViento = [];
var promLluvia = [];
var promDioxido = [];
var promMonoxido = [];
var promAmoniaco = [];

var fechas = []; //Fechas has 7 days only
var nana = false;

//Object received from json of semanal data
var objectSemanal = 0; 


jQuery(document).ready(function($){
	actualizarActuales();
	actualizarSemanalesFechas();  
	
	setInterval(actualizarActuales, 600000);
	setInterval(actualizarSemanalesFechas, 600000);

	function actualizarActuales(){
      $.ajax({
           url:"server1.php",
           method:"POST",
           success: function (devol){
           $("#actuales").html(devol);
           listoDibujeActuales = true; 
           if(listoDibujeActuales == true){
			   actualizarSemanalesFechas();
	        }
         }
	  });
	}
	
	function actualizarSemanalesFechas(){
		$.ajax({
			type:"POST",
			dataType: "json",
			url: "server2.php",
			success: function(data){
				objectSemanal = data;
				fechas = objectSemanal.fechasGraf;
				console.log(fechas);
				actualizarSemanalesClima();
				
			}
		});	
	}

	function actualizarSemanalesClima(){
		$.ajax({
			type:"POST",
			dataType: "json",
			url: "server3.php",
			success: function(data1){
				var objectReceived = data1;
				promTemperatura = objectReceived.temperatura; 
				promPresion = objectReceived.presion; 
				promHumedad = objectReceived.humedad; 
				promViento = objectReceived.viento; 
				promUv = objectReceived.uv; 
				promViento = objectReceived.viento; 
				promLluvia = objectReceived.lluvia; 
				promDioxido = objectReceived.dioxido; 
				promMonoxido = objectReceived.monoxido; 
				promAmoniaco = objectReceived.amoniaco; 
				
				
				dibujarSemanales();
			}
		});
	}


});			

function dibujarSemanales(){
	
	var chart = new CanvasJS.Chart("chartContainer", {
		animationEnabled: true,
		title:{
			text: "Daily High Temperature Last Week"
		},
		axisX: {
			valueFormatString: "DD MMM,YY"
		},
		axisY: {
			title: "Temperature (in °C)",
			includeZero: false,
			suffix: " °C"
		},
		legend:{
			cursor: "pointer",
			fontSize: 16,
			itemclick: toggleDataSeries
		},
		toolTip:{
			shared: true
		},
		data: [{
			name: "Bariloche Rolando 654",
			type: "spline",
			yValueFormatString: "#0.## °C",
			showInLegend: true,
			dataPoints: [
				{ x: new Date(fechas[6]), y: parseInt(promTemperatura[6])},
				{ x : new Date(fechas[5]), y: parseInt(promTemperatura[5])},
		
				{ x: new Date(fechas[4]), y: parseInt(promTemperatura[4])},
				{ x: new Date(fechas[3]), y: parseInt(promTemperatura[3])},
				{ x: new Date(fechas[2]), y: parseInt(promTemperatura[2])},
				{ x: new Date(fechas[1]), y: parseInt(promTemperatura[1])},
				{ x: new Date(fechas[0]), y: parseInt(promTemperatura[0])},
				
			]
		}]
	
	});
	

	
	chart.render();


	var chart2 = new CanvasJS.Chart("chartContainer2", {
		animationEnabled: true,
		title:{
			text: "Daily High Humidity Last Week"
		},
		axisX: {
			valueFormatString: "DD MMM,YY"
		},
		axisY: {
			title: "Humidity in %",
			includeZero: true,
			suffix: " %"
		},
		legend:{
			cursor: "pointer",
			fontSize: 16,
			itemclick: toggleDataSeries
		},
		toolTip:{
			shared: true
		},
		data: [{
			name: "Bariloche Rolando 654",
			type: "spline",
			yValueFormatString: "#0.## %",
			showInLegend: true,
			dataPoints: [
				{ x: new Date(fechas[6]), y: parseInt(promHumedad[6])},
				{ x : new Date(fechas[5]), y: parseInt(promHumedad[5])},
		
				{ x: new Date(fechas[4]), y: parseInt(promHumedad[4])},
				{ x: new Date(fechas[3]), y: parseInt(promHumedad[3])},
				{ x: new Date(fechas[2]), y: parseInt(promHumedad[2])},
				{ x: new Date(fechas[1]), y: parseInt(promHumedad[1])},
				{ x: new Date(fechas[0]), y: parseInt(promHumedad[0])},
				
			]
		}]
	
	});
	

	
	chart2.render();




	var chart3 = new CanvasJS.Chart("chartContainer3", {
		animationEnabled: true,
		title:{
			text: "Daily High Pressure Last Week"
		},
		axisX: {
			valueFormatString: "DD MMM,YY"
		},
		axisY: {
			title: "Presion in Hp",
			includeZero: true,
			suffix: " hP"
		},
		legend:{
			cursor: "pointer",
			fontSize: 16,
			itemclick: toggleDataSeries
		},
		toolTip:{
			shared: true
		},
		data: [{
			name: "Bariloche Rolando 654",
			type: "spline",
			yValueFormatString: "#0.## hP",
			showInLegend: true,
			dataPoints: [
				{ x: new Date(fechas[6]), y: parseInt(promPresion[6])},
				{ x : new Date(fechas[5]), y: parseInt(promPresion[5])},
		
				{ x: new Date(fechas[4]), y: parseInt(promPresion[4])},
				{ x: new Date(fechas[3]), y: parseInt(promPresion[3])},
				{ x: new Date(fechas[2]), y: parseInt(promPresion[2])},
				{ x: new Date(fechas[1]), y: parseInt(promPresion[1])},
				{ x: new Date(fechas[0]), y: parseInt(promPresion[0])},
				
			]
		}]
	
	});
	

	
	chart3.render();

	var chart4 = new CanvasJS.Chart("chartContainer4", {
		animationEnabled: true,
		title:{
			text: "Daily High Uv %"
		},
		axisX: {
			valueFormatString: "DD MMM,YY"
		},
		axisY: {
			title: "Ultraviolet Radiation in %",
			includeZero: true,
			suffix: " %"
		},
		legend:{
			cursor: "pointer",
			fontSize: 16,
			itemclick: toggleDataSeries
		},
		toolTip:{
			shared: true
		},
		data: [{
			name: "Bariloche Rolando 654",
			type: "spline",
			yValueFormatString: "#0.## %",
			showInLegend: true,
			dataPoints: [
				{ x: new Date(fechas[6]), y: parseInt(promUv[6])},
				{ x: new Date(fechas[5]), y: parseInt(promUv[5])},		
				{ x: new Date(fechas[4]), y: parseInt(promUv[4])},
				{ x: new Date(fechas[3]), y: parseInt(promUv[3])},
				{ x: new Date(fechas[2]), y: parseInt(promUv[2])},
				{ x: new Date(fechas[1]), y: parseInt(promUv[1])},
				{ x: new Date(fechas[0]), y: parseInt(promUv[0])},
				
			]
		}]
	
	});
	

	
	chart4.render();

















	
	function toggleDataSeries(e){
		if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
			e.dataSeries.visible = false;
		}
		else{
			e.dataSeries.visible = true;
		}
		chart.render();
		chart2.render();
	}







}
