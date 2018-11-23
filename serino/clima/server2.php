<?php
    require("conexion.php");
	require("functions.php");
    $cantRegistros168hs = 120960; //Si se hace un registro cada 5 segundos, 168 hs son 120960 registros. 
    $cantidadRegistrosPorDia = 17280;
	$sql2 = "SELECT * from `registros` ORDER BY id DESC LIMIT $cantRegistros168hs";
    $a = mysqli_query($link, $sql2);
    $r = 0; 
    $i4 = 0; 
	
	$counter_initer = 0; 
	while($counter_initer < 130000){
		$A_time[$counter_initer]=0;
		$A_temperatura[$counter_initer] = 0; 
        $A_humedad[$counter_initer] = 0; 
        $A_presion[$counter_initer] = 0; 
        $A_uv[$counter_initer] = 0; 
        $A_viento[$counter_initer] = 0; 
        $A_lluvia[$counter_initer] = 0; 
        $A_dioxido[$counter_initer] = 0; 
        $A_monoxido[$counter_initer] = 0; 
        $A_amoniaco[$counter_initer] = 0; 
			
		
		$counter_initer++;
	} 
    while($resultadosArray = mysqli_fetch_array($a)){
        if($r % $cantidadRegistrosPorDia == 0){$A_time[] = $resultadosArray['time'];}
		
		$A_temperatura[] = $resultadosArray['temperatura'];
        $A_humedad[] = $resultadosArray['humedad'];
        $A_presion[] = $resultadosArray['presion'];
        $A_uv[] = $resultadosArray['uv'];
        $A_viento[] = $resultadosArray['viento'];
        $A_lluvia[] = $resultadosArray['lluvia'];
        $A_dioxido[] = $resultadosArray['dioxido'];
        $A_monoxido[] = $resultadosArray['monoxido'];
        $A_amoniaco[] = $resultadosArray['amoniaco'];
        $r++;
    }   //Hasta aquí tenemos los arrays con 120960 registros, todo correcto. 
		//Excepto el de $A_time que tiene 7 registros
		 
		 
		 
		 
    $i1 = 0; 
    $i2 = 0;    
    $i3 = 0; 
    $constante1 = $cantRegistros168hs / 168;    //Es decir cuantos registros por hora. 
    $i4 = 0; 
    $i5 = 0; 
	
	
	
    while($i4 < 168){
        if($i4 % 24 == 0){
            $fechasGraf[$i5] = $A_time[$i4];
			
            $i5++;
        }
        $i4++;
    }
       
     
    

    //Aquí abajo procedemos a calcular el promedio de cada variable climática cada hora. 
    $k = 0; 
  /*  while($k <= 167){ //Inicializamos los arrays de promedios en vacíos
        $A_prom_time[$k] = 0; 
        $A_prom_temperatura[$k] = 0; 
        $A_prom_humedad[$k] = 0; 
        $A_prom_presion[$k] = 0; 
        $A_prom_uv[$k] = 0;
        $A_prom_viento[$k] = 0; 
        $A_prom_lluvia[$k] = 0; 
        $A_prom_dioxido[$k] = 0; 
        $A_prom_monoxido[$k] = 0; 
        $A_prom_amoniaco[$k] = 0;
        $k++;
    }
    
    $i1 = 0; 
    while($i1 <= 167){
        $i2 = 0;     
        while($i2 <= $constante1 -1 ){
            $A_prom_temperatura[$i1] = $A_prom_temperatura[$i1] + $A_temperatura[$i3];
            $A_prom_humedad[$i1] = $A_prom_humedad[$i1] + $A_humedad[$i3];
            $A_prom_presion[$i1] = $A_prom_presion[$i1] + $A_presion[$i3];
            $A_prom_uv[$i1] = $A_prom_uv[$i1] + $A_uv[$i3];
            $A_prom_viento[$i1] = $A_prom_viento[$i1] + $A_viento[$i3];
            $A_prom_lluvia[$i1] = $A_prom_lluvia[$i1] + $A_lluvia[$i3];
            $A_prom_dioxido[$i1] = $A_prom_dioxido[$i1] + $A_dioxido[$i3];
            $A_prom_monoxido[$i1] = $A_prom_monoxido[$i1] + $A_monoxido[$i3];
            $A_prom_amoniaco[$i1] = $A_prom_amoniaco[$i1] + $A_amoniaco[$i3];
            $i2++;
            $i3++;
        }
        $A_prom_temperatura[$i1] = $A_prom_temperatura[$i1] / $constante1; 
        $A_prom_humedad[$i1] = $A_prom_humedad[$i1] / $constante1; 
        $A_prom_presion[$i1] = $A_prom_presion[$i1] / $constante1; 
        $A_prom_uv[$i1] = $A_prom_uv[$i1] / $constante1; 
        $A_prom_viento[$i1] = $A_prom_viento[$i1] / $constante1; 
        $A_prom_lluvia[$i1] = $A_prom_lluvia[$i1] / $constante1; 
        $A_prom_dioxido[$i1] = $A_prom_dioxido[$i1] / $constante1; 
        $A_prom_monoxido[$i1] = $A_prom_monoxido[$i1] / $constante1; 
        $A_prom_amoniaco[$i1] = $A_prom_amoniaco[$i1] / $constante1; 
        
       

        //Redondeamos para que no molesten los decimales
       $A_prom_temperatura[$i1] = round($A_prom_temperatura[$i1],0);
       $A_prom_humedad[$i1] = round($A_prom_humedad[$i1],0);
       $A_prom_presion[$i1] = round($A_prom_presion[$i1],0);
       $A_prom_uv[$i1] = round($A_prom_uv[$i1],0);
       $A_prom_viento[$i1] = round($A_prom_viento[$i1],0);
       $A_prom_lluvia[$i1]  = round($A_prom_lluvia[$i1],0);
       $A_prom_dioxido[$i1] = round($A_prom_dioxido[$i1],0);
       $A_prom_monoxido[$i1] = round($A_prom_monoxido[$i1],0);
       $A_prom_amoniaco[$i1] = round($A_prom_amoniaco[$i1],0);

        $i1++;
    }

    //En los arrays del tipo $A_prom_amoniaco tenemos 168 registros cada uno es el valor de su variable por hora. 
    
*/

        $prepararParaJson['temperatura'] =  $A_temperatura;
        $prepararParaJson['humedad'] = $A_humedad; 
        $prepararParaJson['presion'] = $A_presion;
        $prepararParaJson['uv'] = $A_uv;
        $prepararParaJson['viento'] = $A_viento;
        $prepararParaJson['lluvia'] = $A_lluvia; 
        $prepararParaJson['dioxido'] = $A_dioxido; 
        $prepararParaJson['monoxido'] = $A_monoxido; 
        $prepararParaJson['amoniaco'] = $A_amoniaco; 

        //Llamo a las funciones para sacar maximo y minimo, y las meto en dos posiciones del json 

        //Guardo en el array $maximos[] los valores maximos de cada variable climática en la semana    
        $maximos[0] = maximoDelArray($A_temperatura);
        $maximos[1] = maximoDelArray($A_humedad);
        $maximos[2] = maximoDelArray($A_presion);
        $maximos[3] = maximoDelArray($A_uv);
        $maximos[4] = maximoDelArray($A_viento);
        $maximos[5] = maximoDelArray($A_lluvia);
        $maximos[6] = maximoDelArray($A_dioxido);
        $maximos[7] = maximoDelArray($A_monoxido);
        $maximos[8] = maximoDelArray($A_amoniaco);
        
        $prepararParaJson['maximos'] = $maximos;    //Preparo el json con maximos

        //Guardo en el array $minimos[] los valores minimos de cada variable climática en la semana
        $minimos[0] = minimoDelArray($A_temperatura);
        $minimos[1] = minimoDelArray($A_humedad);
        $minimos[2] = minimoDelArray($A_presion);
        $minimos[3] = minimoDelArray($A_uv);
        $minimos[4] = minimoDelArray($A_viento);
        $minimos[5] = minimoDelArray($A_lluvia);
        $minimos[6] = minimoDelArray($A_dioxido);
        $minimos[7] = minimoDelArray($A_monoxido);
        $minimos[8] = minimoDelArray($A_amoniaco);

        $prepararParaJson['minimos'] = $minimos;//Preparo el json con minimos

        $prepararParaJson['time'] = $A_time;    //Preparo el json con time
		
        $i = 0; 
        while($i < 7){
            $fechasImportantes[$i] = substr($fechasGraf[$i],0,10);
			
            $i++;
        }
        $prepararParaJson['fechasGraf'] = $fechasImportantes;
        

        //En este superpaquete json están todos los datos
        
       echo json_encode($prepararParaJson);
		
		
        
       
        function maximoDelArray($arraysito){
            $a = $arraysito[0];
            $b = count($arraysito); 
            $i = 0; 
            while($i < $b){
                if($arraysito[$i] > $a){
                    $a = $arraysito[$i];
                }
                $i++;
            }
            return($a);      //Devuelve la posición del array donde está el valor máximo
        }
        function minimoDelArray($arraysito){
            $a = $arraysito[0];
            $b = count($arraysito);
            $i = 0; 
            while($i < $b){
                if($arraysito[$i] < $a){
                    $a = $arraysito[$i];
                }
                $i++;
            }
            return($a);       //Devuelve la posición del array donde está el valor mínimo
        }

    
    
    


?>