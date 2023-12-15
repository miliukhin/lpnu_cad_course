-- MariaDB dump 10.19-11.1.2-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: music_store
-- ------------------------------------------------------
-- Server version	11.1.2-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `bowed`
--

DROP TABLE IF EXISTS `bowed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bowed` (
  `size` float DEFAULT NULL,
  `id` int(11) NOT NULL,
  `id_product` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_product` (`id_product`),
  CONSTRAINT `bowed_ibfk_1` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bowed`
--

LOCK TABLES `bowed` WRITE;
/*!40000 ALTER TABLE `bowed` DISABLE KEYS */;
INSERT INTO `bowed` VALUES
(4.9,1002,2009),
(4,1016,2008),
(4,1042,2005),
(4,1043,2006),
(4,1044,2007),
(4,1046,2010),
(4.3,1102,2003),
(4.7,1132,2004),
(4.2,3302,2001),
(4.5,6502,2002);
/*!40000 ALTER TABLE `bowed` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `buyer`
--

DROP TABLE IF EXISTS `buyer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `buyer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `fname` varchar(255) DEFAULT NULL,
  `mname` varchar(255) DEFAULT NULL,
  `lname` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `buyer`
--

LOCK TABLES `buyer` WRITE;
/*!40000 ALTER TABLE `buyer` DISABLE KEYS */;
INSERT INTO `buyer` VALUES
(1,'John','John','Doe'),
(2,'Jane','Dominique','Smith'),
(3,'Robert','Charles','Johnson'),
(4,'Sarah','Donald','Duck'),
(5,'Michael','Fred','Brown'),
(6,'Emily','Michael','Jones'),
(7,'William','Gregory','Davis'),
(8,'Olivia','Howard','Miller'),
(9,'James','Ivan','Wilson'),
(10,'Ava','George','Moore');
/*!40000 ALTER TABLE `buyer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employee` (
  `id` int(11) NOT NULL,
  `fname` varchar(255) DEFAULT NULL,
  `mname` varchar(255) DEFAULT NULL,
  `lname` varchar(255) DEFAULT NULL,
  `salary` float DEFAULT NULL,
  `position` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES
(0,'Edward','Joseph','Turner',45005,'salesperson'),
(230,'Daniel','Eric','Young',70005,'salesperson'),
(1001,'Richard','Charles','Hall',50005,'salesperson'),
(1020,'Mary','Donald','Garcia',45005,'salesperson'),
(1111,'Helen','Johann','King',70005,'technician'),
(1234,'Susan','Fmeow','Wright',60005,'salesperson'),
(2101,'Linda','Bob','Clark',55005,'supervisor'),
(4321,'George','George','Harris',55005,'salesperson'),
(9999,'Karen','Heeeeeeeee','Lee',50005,'salesperson');
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_old`
--

DROP TABLE IF EXISTS `employee_old`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employee_old` (
  `id` int(11) NOT NULL,
  `fname` varchar(255) DEFAULT NULL,
  `mname` varchar(255) DEFAULT NULL,
  `lname` varchar(255) DEFAULT NULL,
  `salary` float DEFAULT NULL,
  `position` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
 PARTITION BY HASH (`id`)
PARTITIONS 4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_old`
--

LOCK TABLES `employee_old` WRITE;
/*!40000 ALTER TABLE `employee_old` DISABLE KEYS */;
INSERT INTO `employee_old` VALUES
(0,'Edward','Joseph','Turner',45000,'salesperson'),
(1020,'Mary','Donald','Garcia',45000,'salesperson'),
(1001,'Richard','Charles','Hall',50000,'salesperson'),
(2101,'Linda','Bob','Clark',55000,'supervisor'),
(4321,'George','George','Harris',55000,'salesperson'),
(230,'Daniel','Eric','Young',70000,'salesperson'),
(1102,'David','Alfred','Anderson',60000,'manager'),
(1234,'Susan','Fmeow','Wright',60000,'salesperson'),
(1111,'Helen','Johann','King',70000,'technician'),
(9999,'Karen','Heeeeeeeee','Lee',50000,'salesperson');
/*!40000 ALTER TABLE `employee_old` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `guitar`
--

DROP TABLE IF EXISTS `guitar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guitar` (
  `scaled_length` float DEFAULT NULL,
  `length` float DEFAULT NULL,
  `width` float DEFAULT NULL,
  `strings` int(11) DEFAULT NULL,
  `frets` int(11) DEFAULT NULL,
  `id` int(11) NOT NULL,
  `id_product` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_product` (`id_product`),
  CONSTRAINT `guitar_ibfk_1` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guitar`
--

LOCK TABLES `guitar` WRITE;
/*!40000 ALTER TABLE `guitar` DISABLE KEYS */;
INSERT INTO `guitar` VALUES
(25.5,41,14,6,22,890891,1001),
(24.75,39,13,6,24,890892,1002),
(26,42,15,6,22,890893,1003),
(25,40,14,6,21,890894,1004),
(25.5,41,14,6,24,890895,1005),
(22.5,36,11,5,20,890896,1006),
(23,37,12,6,22,890897,1007),
(24.5,39,14,6,20,890898,1008),
(25,40,15,7,22,890899,1009),
(24,38,13,6,21,890900,1010);
/*!40000 ALTER TABLE `guitar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `john_order_dates`
--

DROP TABLE IF EXISTS `john_order_dates`;
/*!50001 DROP VIEW IF EXISTS `john_order_dates`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `john_order_dates` AS SELECT
 1 AS `id`,
  1 AS `date` */;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `manufacturer`
--

DROP TABLE IF EXISTS `manufacturer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `manufacturer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `address_code` int(11) NOT NULL,
  `phone` int(11) NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `manufacturer`
--

LOCK TABLES `manufacturer` WRITE;
/*!40000 ALTER TABLE `manufacturer` DISABLE KEYS */;
INSERT INTO `manufacturer` VALUES
(1,12345,952341234,'GuitarCo'),
(2,54321,683245678,'MusicMakers'),
(3,98765,982349876,'SoundWave'),
(4,12312,952387645,'ibanjek'),
(5,56789,952423345,'jackdaughter'),
(6,43210,982346789,'Kurt'),
(7,24680,953433421,'Chibson'),
(8,13579,982435342,'bender'),
(9,86420,953448769,'MusicMagic'),
(10,97531,952431122,'NotePerfect');
/*!40000 ALTER TABLE `manufacturer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `material`
--

DROP TABLE IF EXISTS `material`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `material` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `material`
--

LOCK TABLES `material` WRITE;
/*!40000 ALTER TABLE `material` DISABLE KEYS */;
INSERT INTO `material` VALUES
(1,'Oak'),
(2,'Acacia'),
(3,'Mahagoni'),
(4,'Rosewood'),
(5,'Maple'),
(6,'Plastic'),
(7,'Steel'),
(8,'Brass'),
(9,'Copper'),
(10,'Bronze'),
(11,'Fiberboard'),
(12,'Carbon Fiber');
/*!40000 ALTER TABLE `material` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order_details`
--

DROP TABLE IF EXISTS `order_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `order_details` (
  `quantity_of_goods` int(11) DEFAULT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_order` int(11) NOT NULL,
  `id_product` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_order` (`id_order`),
  KEY `id_product` (`id_product`),
  CONSTRAINT `order_details_ibfk_1` FOREIGN KEY (`id_order`) REFERENCES `order_sheet` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `order_details_ibfk_2` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order_details`
--

LOCK TABLES `order_details` WRITE;
/*!40000 ALTER TABLE `order_details` DISABLE KEYS */;
INSERT INTO `order_details` VALUES
(5,1,1,1001),
(3,2,1,2001),
(4,3,2,1002),
(1,4,2,1003),
(6,5,3,1004),
(7,6,3,1005),
(1,7,4,2001),
(1,8,5,2002),
(3,9,6,1001),
(1,10,7,1007),
(4,12,7,1003);
/*!40000 ALTER TABLE `order_details` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`sasha`@`localhost`*/ /*!50003 trigger sold_items_updater before insert on order_details
	for each row
	set @items_sold = @items_sold + new.quantity_of_goods */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `order_sheet`
--

DROP TABLE IF EXISTS `order_sheet`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `order_sheet` (
  `date` datetime DEFAULT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_buyer` int(11) DEFAULT NULL,
  `id_seller` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_buyer` (`id_buyer`),
  KEY `id_seller` (`id_seller`),
  CONSTRAINT `order_sheet_ibfk_1` FOREIGN KEY (`id_buyer`) REFERENCES `buyer` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `order_sheet_ibfk_2` FOREIGN KEY (`id_seller`) REFERENCES `employee` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order_sheet`
--

LOCK TABLES `order_sheet` WRITE;
/*!40000 ALTER TABLE `order_sheet` DISABLE KEYS */;
INSERT INTO `order_sheet` VALUES
('2023-10-13 10:00:00',1,1,2101),
('2023-10-13 11:00:00',2,2,2101),
('2023-10-13 12:00:00',3,3,1001),
('2023-10-13 13:00:00',4,4,1020),
('2023-10-13 14:00:00',5,5,230),
('2023-10-13 15:00:00',6,6,1234),
('2023-10-13 16:00:00',7,7,4321),
('2023-10-13 17:00:00',8,8,9999),
('2023-10-13 18:00:00',9,9,0),
('2023-10-13 19:00:00',10,10,0);
/*!40000 ALTER TABLE `order_sheet` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `orders_23_10`
--

DROP TABLE IF EXISTS `orders_23_10`;
/*!50001 DROP VIEW IF EXISTS `orders_23_10`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `orders_23_10` AS SELECT
 1 AS `date`,
  1 AS `id`,
  1 AS `id_buyer`,
  1 AS `id_seller` */;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `product`
--

DROP TABLE IF EXISTS `product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `quantity` int(11) DEFAULT NULL,
  `price` float DEFAULT NULL,
  `name` varchar(255) NOT NULL,
  `id_manufacturer` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_manufacturer` (`id_manufacturer`),
  CONSTRAINT `product_ibfk_1` FOREIGN KEY (`id_manufacturer`) REFERENCES `manufacturer` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=9099 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `product`
--

LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;
INSERT INTO `product` VALUES
(1001,100,1431.17,'\"GAGA\" Electric Guitar',5),
(1002,50,1908.23,'\"Malyatko\" Electric Guitar',4),
(1003,75,715.573,'\"Spine\" Double-Neck Acoustic Guitar',7),
(1004,20,310.068,'\"Shredder\" Electric Guitar',8),
(1005,45,1788.97,'Ibanjek G1958 Electric Guitar',4),
(1006,45,1788.97,'Ibanjek G6958 Electric Guitar',4),
(1007,45,1788.97,'Ibanjek G2958 Electric Guitar',4),
(1008,45,1788.97,'Ibanjek G3958 Electric Guitar',4),
(1009,45,1788.97,'Ibanjek G4958 Electric Guitar',4),
(1010,45,1788.97,'Ibanjek G5958 Electric Guitar',4),
(2001,25,834.839,'\"chipupino\" violin',9),
(2002,25,834.839,'\"bambino\" violin',9),
(2003,25,834.839,'\"cupipi\" violin',9),
(2004,25,834.839,'\"strtok\" violin',9),
(2005,25,834.839,'\"strcmp\" violin',9),
(2006,25,834.839,'\"strcat\" violin',9),
(2007,25,834.839,'\"DROP\" violin',9),
(2008,25,834.839,'\"SELECT\" violin',9),
(2009,25,834.839,'\"DELETE\" violin',9),
(2010,25,834.839,'\"ALTER\" violin',9),
(3303,55,2146.77,'funny-looking cello',9),
(6060,30,477.041,'\"Shimamimu\" Flute',4),
(9003,25,834.839,'bow',10),
(9093,60,954.105,'\"Jazzmaster\" Pick',6),
(9097,40,1192.64,'Cool Pick',5);
/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `product_has_material`
--

DROP TABLE IF EXISTS `product_has_material`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product_has_material` (
  `id_product` int(11) NOT NULL,
  `id_material` int(11) NOT NULL,
  `part_name` varchar(45) DEFAULT NULL,
  KEY `id_product` (`id_product`),
  KEY `id_material` (`id_material`),
  CONSTRAINT `product_has_material_ibfk_1` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `product_has_material_ibfk_2` FOREIGN KEY (`id_material`) REFERENCES `material` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `product_has_material`
--

LOCK TABLES `product_has_material` WRITE;
/*!40000 ALTER TABLE `product_has_material` DISABLE KEYS */;
INSERT INTO `product_has_material` VALUES
(1001,1,'fretboard'),
(1001,2,'body'),
(1001,3,'neck'),
(1002,2,'fretboard'),
(1002,1,'body'),
(1002,5,'neck'),
(1003,4,'fretboard'),
(1003,1,'body'),
(1003,5,'neck'),
(1004,4,'fretboard'),
(1004,4,'body'),
(1004,4,'neck');
/*!40000 ALTER TABLE `product_has_material` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Final view structure for view `john_order_dates`
--

/*!50001 DROP VIEW IF EXISTS `john_order_dates`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb3 */;
/*!50001 SET character_set_results     = utf8mb3 */;
/*!50001 SET collation_connection      = utf8mb3_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `john_order_dates` AS select `order_sheet`.`id` AS `id`,`order_sheet`.`date` AS `date` from `order_sheet` where `order_sheet`.`id_buyer` in (select `buyer`.`id` from `buyer` where `buyer`.`fname` like 'john') */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `orders_23_10`
--

/*!50001 DROP VIEW IF EXISTS `orders_23_10`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb3 */;
/*!50001 SET character_set_results     = utf8mb3 */;
/*!50001 SET collation_connection      = utf8mb3_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `orders_23_10` AS select `order_sheet`.`date` AS `date`,`order_sheet`.`id` AS `id`,`order_sheet`.`id_buyer` AS `id_buyer`,`order_sheet`.`id_seller` AS `id_seller` from `order_sheet` where `order_sheet`.`date` regexp '2023-10' */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-11-10 23:25:37
