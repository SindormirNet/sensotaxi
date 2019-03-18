<!-- web de recogida de datos y transmisión a la base de datos cuyos datos de conexxión van en el archivo "conecta.php" -->

<?php
// Incluimos los datos de conexión y las funciones:
include("conecta.php");
// Usamos esas variables:
if (conectarBase($host,$usuario,$clave,$base)) 
	{
//Validamos que hayan llegado estas variables, y que no esten vacias:
	if (isset($_GET["id"], $_GET["gps_date"], $_GET["gps_hour"], $_GET["gps_long"]) and $_GET["id"] !="" and $_GET["gps_date"]!="" and $_GET["gps_hour"]!="" and $_GET["gps_long"]!="" )	
		{
//traspasamos a variables locales, para evitar complicaciones con las comillas:
		$IDp = $_GET["id"];
		$Horap = $_GET["gps_hour"];
		$Fechap = $_GET["gps_date"];
		$Latp = $_GET["gps_lat"];
		$Longp = $_GET["gps_long"];
		$GPS_Altp = $_GET["gps_alt"];
		$Sonidop = $_GET["sound"];
		$Gravp = $_GET["bounce"];
		$Luzp = $_GET["ligth"];
		$Gasp = $_GET["mq135"];
		$CO2p = $_GET["mq132"];
		$Tempp = $_GET["temp"];
		$Hump = $_GET["hum"];
		$Presp = $_GET["pres"];
		$Altp = $_GET["alt"];
//Preparamos la orden SQL
		$consulta = "INSERT INTO datos (ID,Fecha,Hora,Longitud,Latitud,gps_alt,Sonido,Gravedad,Luz,Gases,CO2,Temperatura,Humedad,Presion,Altitud) 
			VALUES ('$IDp','$Fechap','$Horap','$Longp','$Latp','$GPS_Altp','$Sonidop','$Gravp','$Luzp','$Gasp','$CO2p','$Tempp','$Hump','$Presp','$Altp')";
		//echo "<p>ID: ";
		//echo $IDp;
		//echo " Hora: ";
		//echo $Horap;
		//echo " Fecha: ";
		//echo $Fechap;
		//echo " </p>";
		$enlace2= mysqli_connect($host,$usuario,$clave,$base);
		if (mysqli_query($enlace2 , $consulta) )
			{
			echo "<p>Ok</p>"; 
			}
		else 
			{
			echo "<p>No se agregó...</p>";
			}
		}
	else 
		{
		echo '<p>Faltan datos esenciales.</p>';
		}
	} 
else {
	echo"<p>Servicio interrumpido</p>";
	}
$enlace2->close();
?>
