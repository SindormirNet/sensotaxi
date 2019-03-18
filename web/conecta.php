<!-- Función y datos de conexón a la base de datos -->

<?php
$host="localhost"; //Servidor donde va ubicado la base de datos mysql
$usuario="usuarioDB"; //Nombre de usuario con acceso a la base de datos
$clave="CalveUsuarioDB"; // Contraseña del mismo.
$base="nombre DB";  //Nombre de la base de datos

function conectarBase ($host,$usuario,$clave,$base)
	{
	if (!$enlace= mysqli_connect($host,$usuario,$clave))
		{
		return false;
		}
	elseif (!mysqli_select_db($enlace , $base))
		{
		return false;
		}
	else 
		{
		return true;
		}
	}
?>
