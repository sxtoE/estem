<?php
	include("conexion.php");
	$cantRegistrosSemana = 120960;
	$cantRegistrosDia = 17280; //A un ritmo de 1 registro cada 5 segundos; 
	
	//Inicializamos vectores en vacío------------------
	
	$i3 = 0; 
	while($i3 < $cantRegistrosSemana){
		$L_temperatura[$i3] = 0; 
		$L_humedad[$i3] = 0; 
		$L_presion[$i3] = 0; 
		$L_lluvia[$i3] = 0; 
		$L_viento[$i3] = 0; 
		$L_uv[$i3] = 0; 
		$L_monoxido[$i3] = 0; 
		$L_dioxido[$i3] = 0; 
		$L_amoniaco[$i3] = 0; 
		$L_fechas[$i3] = 0; 
		
		$i3++;
	}
	
	
	
	$i0 = 0; 
	$i1 = 0; 
	$i2 = 0; 
	while($i0 < 7){
		$i1 = 0; 
		while($i1 < $cantRegistrosDia){
			$D_temperatura[$i0][$i2] = 0; 
			$D_humedad[$i0][$i2] = 0; 
			$D_presion[$i0][$i2] = 0; 
			$D_lluvia[$i0][$i2] = 0; 
			$D_viento[$i0][$i2] = 0; 
			$D_uv[$i0][$i2] = 0; 
			$D_monoxido[$i0][$i2] = 0; 
			$D_dioxido[$i0][$i2] = 0; 
			$D_amoniaco[$i0][$i2] = 0; 
			$i1++;
			$i2++;
		}
		$i0++;
	}
	
	//------------------------------------------------------------------------------------
	
	
	$sql1 = "SELECT * from `registros` order by id DESC limit $cantRegistrosSemana";  
	$r1 = mysqli_query($link, $sql1);
	
	
	
	while($k1 = mysqli_fetch_array($r1)){
		$L_temperatura[] = $k1['temperatura'];
		$L_presion[] = $k1['presion'];
		$L_humedad[] = $k1['humedad'];
		$L_uv[] = $k1['uv'];
		$L_viento[] = $k1['viento'];
		$L_lluvia[] = $k1['lluvia'];
		$L_dioxido[] = $k1['dioxido'];
		$L_monoxido[] = $k1['monoxido'];
		$L_amoniaco[] = $k1['amoniaco'];
		$L_fechas[] = $k1['time'];
	}
	
	//Arriba nos devolvieron un monton de registros, ahora separémoslos por día 
	
	
	$cont1 = 0; 
	$cont2 = 0; 
	$cont3 = 0; 
	while($cont1 < 7){
		$cont2 = 0; 
		while($cont2 < $cantRegistrosDia){
			$D_temperatura[$cont1][$cont2] = $L_temperatura[$cont3];
			$D_presion[$cont1][$cont2] = $L_presion[$cont3];
			$D_humedad[$cont1][$cont2] = $L_humedad[$cont3];
			$D_uv[$cont1][$cont2] = $L_uv[$cont3];
			$D_viento[$cont1][$cont2] = $L_viento[$cont3];
			$D_lluvia[$cont1][$cont2] = $L_lluvia[$cont3];
			$D_monoxido[$cont1][$cont2] = $L_monoxido[$cont3];
			$D_dioxido[$cont1][$cont2] = $L_dioxido[$cont3];
			$D_amoniaco[$cont1][$cont2] = $L_amoniaco[$cont3];
						
			$cont2++;
			$cont3++;
		}
		$cont1++;
	}
	
	//Ahora tenemos multiarrays donde [param1] es dia y [param2] es registro del dia 
	
	$R_temperatura[] = maximoDiario($D_temperatura, $cantRegistrosDia);
	$R_presion = maximoDiario($D_presion, $cantRegistrosDia);
	$R_humedad = maximoDiario($D_humedad, $cantRegistrosDia);
	$R_uv = maximoDiario($D_uv, $cantRegistrosDia);
	$R_viento = maximoDiario($D_viento, $cantRegistrosDia);
	$R_lluvia = maximoDiario($D_lluvia, $cantRegistrosDia);
	$R_monoxido = maximoDiario($D_monoxido, $cantRegistrosDia);
	$R_dioxido = maximoDiario($D_dioxido, $cantRegistrosDia);
	$R_amoniaco = maximoDiario($D_amoniaco, $cantRegistrosDia);
	
	
	
	
	
	

	
	$i0 = 0; 
	$i2 = 0; 
	while($i0 < count($L_fechas)){
		if($i0 % $cantRegistrosDia == 0){
			$R_fechas[$i2] = $L_fechas[$i0];
			$i2++;
		}		
		$i0++;
	}
	
	$prepararJson['temperatura'] = $R_temperatura;
	$prepararJson['humedad'] = $R_humedad;
	$prepararJson['presion'] = $R_presion;
	$prepararJson['viento'] = $R_viento;
	$prepararJson['uv'] = $R_uv;
	$prepararJson['lluvia'] = $R_lluvia;
	$prepararJson['dioxido'] = $R_dioxido;
	$prepararJson['monoxido'] = $R_monoxido;	
	$prepararJson['amoniaco'] = $R_amoniaco;
	$prepararJson['fechas'] = $R_fechas; 
	
	echo (json_encode($prepararJson));
	
	
	
	
	
	
	
	
	
	    function maximoDiario($arraysito, $cantRegistrosDia){
        //$arraysito[$dia][$posicion]
        $i = 0;
        $k = 0; 
        $dia = 0; 
        while($k < 7){
            $i = 0;
            $maximos[$k] = $arraysito[$k][$i]; 
            while($i < $cantRegistrosDia){
                if($arraysito[$k][$i] > $maximos[$k]){
                    //Es mas máximo que el máximo anterior
                    $maximos[$k] = $arraysito[$k][$i];
                }
                $i++;
            }
         $k++;   
        }
        return($maximos);
    }
    
  
    

    function minimoDiario($arraysito, $cantRegistrosDia){
        //$arraysito[$dia][$posicion]
        $i = 0;
        $k = 0; 
        $dia = 0; 
        while($k < 7){
            $i = 0;
            $minimos[$k] = $arraysito[$k][$i]; 
            while($i < $cantRegistrosDia){
                if($arraysito[$k][$i] < $minimos[$k]){
                    //Es mas máximo que el máximo anterior
                    $minimos[$k] = $arraysito[$k][$i];
                }

                $i++;
            }



         $k++;   
        }

        return($minimos);
    }

	
	
	
	
		
		
		
	




?>