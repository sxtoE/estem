$(document).ready(function(){
	$("#reloadActual").click(function(event){
		event.preventDefault();
		 $.ajax({
          url:"server1.php",
          method:"POST",
          success: function (devol){
           $("#actuales").html(devol);
          }
        })


	});















});