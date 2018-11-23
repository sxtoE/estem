<?php
    require("conexion.php");
    $cantRegistros168hs = 120960; //Si se hace un registro cada 5 minutos, 168 hs son 2016 registros. 
    
    $sql2 = "SELECT * from `registros` ORDER BY id DESC LIMIT $cantRegistros168hs";
    $a = mysqli_query($link, $sql2);
    $r = 0; 
    while($resultadosArray = mysqli_fetch_array($a)){
        if($r % 17280 == 0){$A_time[] = $resultadosArray['time'];}
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
    }

  
    //Tenemos todos los arrays con 2016 registros cada uno. 
    //Precisamos 7 arrays por cada uno, así dividimos por día. 
    $n2 = 0; 
    $n3 = 0; 

    while($n2 < 7){

        $n = 0; 
        while($n < 17280){
            $D_temperatura[$n2][$n] = $A_temperatura[$n3];
            $D_humedad[$n2][$n] = $A_humedad[$n3];
            $D_presion[$n2][$n] = $A_presion[$n3];
            $D_uv[$n2][$n] = $A_uv[$n3];
            $D_viento[$n2][$n] = $A_viento[$n3];
            $D_lluvia[$n2][$n] = $A_lluvia[$n3];
            $D_dioxido[$n2][$n] = $A_dioxido[$n3];
            $D_monoxido[$n2][$n] = $A_monoxido[$n3];
            $D_amoniaco[$n2][$n] = $A_amoniaco[$n3];
           

            
           
           
           
            $n++;
            $n3++;
        }
        $n2++;
            
    }   
    
    
    $maxTemperatura = maximoDiario($D_temperatura);
    $maxHumedad = maximoDiario($D_humedad);
    $maxPresion = maximoDiario($D_presion);
    $maxUv = maximoDiario($D_uv);
    $maxViento = maximoDiario($D_viento);
    $maxLluvia = maximoDiario($D_lluvia);
    $maxDioxido = maximoDiario($D_dioxido);
    $maxMonoxido = maximoDiario($D_monoxido);
    $maxAmoniaco = maximoDiario($D_amoniaco);



    $armarJson['temperatura'] = $maxTemperatura;
    $armarJson['humedad'] = $maxHumedad; 
    $armarJson['presion'] = $maxPresion; 
    $armarJson['uv'] = $maxUv; 
    $armarJson['viento'] = $maxViento; 
    $armarJson['lluvia'] = $maxLluvia; 
    $armarJson['dioxido'] = $maxDioxido; 
    $armarJson['monoxido'] = $maxMonoxido; 
    $armarJson['amoniaco'] = $maxAmoniaco; 

    
    echo json_encode($armarJson);












    



    function maximoDiario($arraysito){
        //$arraysito[$dia][$posicion]
        $i = 0;
        $k = 0; 
        $dia = 0; 
        while($k < 7){
            $i = 0;
            $maximos[$k] = $arraysito[$k][$i]; 
            while($i < 17280){
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
    
  
    

    function minimoDiario($arraysito){
        //$arraysito[$dia][$posicion]
        $i = 0;
        $k = 0; 
        $dia = 0; 
        while($k < 7){
            $i = 0;
            $minimos[$k] = $arraysito[$k][$i]; 
            while($i < 17280){
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