jQuery(document).ready(function($){
  actualizarActuales();
  setInterval(actualizarActuales, 600000);


  function actualizarActuales(){
      $.ajax({
           url:"server1.php",
           method:"POST",
           success: function (devol){
            $("#actuales").html(devol);
           }
         });
      }



});
















