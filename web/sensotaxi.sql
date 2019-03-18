-- Este es el código para definir o generar la base de datos en un servidor mysql
 
-- VersiÃ³n del servidor: 5.7.19
-- VersiÃ³n de PHP: 7.1.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `sensotaxi`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `datos`
--

DROP TABLE IF EXISTS `datos`;
CREATE TABLE IF NOT EXISTS `datos` (
  `Indice` int(11) NOT NULL AUTO_INCREMENT,
  `ID` int(11) NOT NULL,
  `Fecha` date NOT NULL,
  `Hora` time(1) NOT NULL,
  `Latitud` double DEFAULT NULL,
  `Longitud` double DEFAULT NULL,
  `gps_alt` float DEFAULT NULL,
  `Sonido` int(11) DEFAULT NULL,
  `Gravedad` int(11) DEFAULT NULL,
  `Luz` int(11) DEFAULT NULL,
  `Gases` int(11) DEFAULT NULL,
  `CO2` int(11) DEFAULT NULL,
  `Temperatura` float DEFAULT NULL,
  `Humedad` int(11) DEFAULT NULL,
  `Presion` float DEFAULT NULL,
  `Altitud` float DEFAULT NULL,
  KEY `Indice` (`Indice`)
) ENGINE=MyISAM AUTO_INCREMENT=2687 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish2_ci;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
