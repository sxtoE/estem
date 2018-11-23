<?php
/*
    date('d') //dia del mes
    date('m') //mes actual
    date('Y') //Año actual con 4 digitos
    date('h') //Horario de 24 horas con ceros
    
*/

$link = mysqli_connect("LOCALHOST", "root", "", "estem");
$restador = -20160;  //Cantidad de minutos hace una semana hasta ahora
$fecha_actual = date("Y-m-d H:i:s");
$ks = 0; 
$contador = 0; 
$nuevito = 15; 
$blabla = false; 
while($restador <= 0){
    $pedacito = $restador." minutes";

    $fecha_modified = strtotime($pedacito,strtotime($fecha_actual));

    $fecha_modified = date("Y-m-d H:i:s", $fecha_modified); //En fecha_principio empieza hoy - 336 hs
    $itime = $fecha_modified;
    
    if($ks % 5 == 0){
        //Quiere decir que pasaron 5 minutos 
        
        /*
        generar valores para: 
        temperatura
        humedad
        presion
        uv
        viento
        lluvia
        dioxido
        monoxido
        amoniaco
        */



        

        if($nuevito > 22){
            $blabla = false; 
        }
        if($nuevito < 14){
            $blabla = true; 
        }
        
        if($blabla == false){
            $nuevito--;
        }else{
            $nuevito++;
        }


        $temperatura = $nuevito; 

       // $temperatura = round(rand(-100,100));
        $humedad = round(rand(0,100));
        $presion = round(rand(500, 1500));
        $uv = round(rand(0,100));
        $viento = round(rand(0,300));
        $lluvia = round(rand(0,300));
        $dioxido = round(rand(0,100));
        $monoxido = round(rand(0,100));
        $amoniaco = round(rand(0,100));

        $sql1 = "INSERT INTO registros (`time`,`temperatura`,`humedad`,`presion`,`uv`,`viento`,`lluvia`,`dioxido`,`monoxido`,`amoniaco`) VALUES ('$itime','$temperatura','$humedad','$presion','$uv','$viento','$lluvia','$dioxido','$monoxido','$amoniaco')";

        mysqli_query($link, $sql1);

       
    }

    $ks++;
    if($ks == 500000){
        $ks = 5; 
    }



    $restador++;
}











?>