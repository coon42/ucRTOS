EESchema Schematic File Version 4
LIBS:ucrtos-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ucrtos-rescue:nes_gamepad_02x03 J1
U 1 1 5A4D2E55
P 1400 1250
F 0 "J1" H 1450 1450 50  0000 C CNN
F 1 "nes_gamepad_02x03" H 1450 1050 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x03_P2.54mm_Vertical" H 1400 1250 50  0001 C CNN
F 3 "" H 1400 1250 50  0001 C CNN
	1    1400 1250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5A4D2EC1
P 1100 1650
F 0 "#PWR0101" H 1100 1400 50  0001 C CNN
F 1 "GND" H 1100 1500 50  0000 C CNN
F 2 "" H 1100 1650 50  0001 C CNN
F 3 "" H 1100 1650 50  0001 C CNN
	1    1100 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1050 1100 1150
Wire Wire Line
	1100 1150 1200 1150
Wire Wire Line
	1200 1350 1100 1350
Wire Wire Line
	1100 1350 1100 1650
$Comp
L power:VCC #PWR0102
U 1 1 5A4D2EAB
P 1100 1050
F 0 "#PWR0102" H 1100 900 50  0001 C CNN
F 1 "VCC" H 1100 1200 50  0000 C CNN
F 2 "" H 1100 1050 50  0001 C CNN
F 3 "" H 1100 1050 50  0001 C CNN
	1    1100 1050
	1    0    0    -1  
$EndComp
$Comp
L w_connectors:STM32F4_Discovery_Header J2
U 1 1 5C40F60D
P 4350 2600
F 0 "J2" H 4350 4193 60  0000 C CNN
F 1 "STM32F4_Discovery_Header" H 4350 4087 60  0000 C CNN
F 2 "w_conn_misc:stm32f4_discovery_header" H 4350 3981 60  0000 C CNN
F 3 "" H 4350 2950 60  0000 C CNN
	1    4350 2600
	1    0    0    -1  
$EndComp
$Comp
L Interface_UART:MAX485E U?
U 1 1 5C438854
P 4300 4800
F 0 "U?" H 4300 5478 50  0000 C CNN
F 1 "MAX485E" H 4300 5387 50  0000 C CNN
F 2 "" H 4300 4100 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 4300 4850 50  0001 C CNN
	1    4300 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J?
U 1 1 5C438977
P 9250 3650
F 0 "J?" H 9300 4067 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 9300 3976 50  0000 C CNN
F 2 "" H 9250 3650 50  0001 C CNN
F 3 "~" H 9250 3650 50  0001 C CNN
	1    9250 3650
	1    0    0    -1  
$EndComp
$Comp
L hy32d:HY32D J?
U 1 1 5C4ADF61
P 9000 2050
F 0 "J?" H 9050 3067 50  0000 C CNN
F 1 "HY32D" H 9050 2976 50  0000 C CNN
F 2 "" H 9000 2050 50  0001 C CNN
F 3 "~" H 9000 2050 50  0001 C CNN
	1    9000 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:SD_Card J?
U 1 1 5C4B7AD4
P 7000 2650
F 0 "J?" H 7000 3315 50  0000 C CNN
F 1 "SD_Card" H 7000 3224 50  0000 C CNN
F 2 "" H 7000 2650 50  0001 C CNN
F 3 "http://portal.fciconnect.com/Comergent//fci/drawing/10067847.pdf" H 7000 2650 50  0001 C CNN
	1    7000 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C4B8497
P 5250 1600
F 0 "#PWR?" H 5250 1350 50  0001 C CNN
F 1 "GND" H 5255 1427 50  0000 C CNN
F 2 "" H 5250 1600 50  0001 C CNN
F 3 "" H 5250 1600 50  0001 C CNN
	1    5250 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C4B84CB
P 3450 1700
F 0 "#PWR?" H 3450 1450 50  0001 C CNN
F 1 "GND" H 3455 1527 50  0000 C CNN
F 2 "" H 3450 1700 50  0001 C CNN
F 3 "" H 3450 1700 50  0001 C CNN
	1    3450 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C4B853E
P 3800 4000
F 0 "#PWR?" H 3800 3750 50  0001 C CNN
F 1 "GND" H 3805 3827 50  0000 C CNN
F 2 "" H 3800 4000 50  0001 C CNN
F 3 "" H 3800 4000 50  0001 C CNN
	1    3800 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C4B85B1
P 4900 4000
F 0 "#PWR?" H 4900 3750 50  0001 C CNN
F 1 "GND" H 4905 3827 50  0000 C CNN
F 2 "" H 4900 4000 50  0001 C CNN
F 3 "" H 4900 4000 50  0001 C CNN
	1    4900 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3750 3800 3800
Wire Wire Line
	3850 3800 3800 3800
Connection ~ 3800 3800
Wire Wire Line
	3800 3800 3800 4000
Wire Wire Line
	4900 3750 4900 3800
Wire Wire Line
	4850 3800 4900 3800
Connection ~ 4900 3800
Wire Wire Line
	4900 3800 4900 4000
Wire Wire Line
	4850 1400 5250 1400
Wire Wire Line
	4900 1350 5250 1350
Wire Wire Line
	5250 1350 5250 1400
Connection ~ 5250 1400
Wire Wire Line
	3800 1350 3450 1350
Wire Wire Line
	3450 1350 3450 1400
Connection ~ 3450 1400
Wire Wire Line
	3800 1450 3300 1450
Wire Wire Line
	3450 1400 3450 1550
Wire Wire Line
	3850 1500 3300 1500
Wire Wire Line
	3300 1500 3300 1450
Connection ~ 3300 1450
Wire Wire Line
	3300 1250 3300 1450
Connection ~ 3450 1550
Wire Wire Line
	3450 1400 3850 1400
Wire Wire Line
	3450 1550 3800 1550
Wire Wire Line
	3450 1550 3450 1700
$Comp
L power:+5V #PWR?
U 1 1 5C4BA20C
P 5450 1250
F 0 "#PWR?" H 5450 1100 50  0001 C CNN
F 1 "+5V" H 5465 1423 50  0000 C CNN
F 2 "" H 5450 1250 50  0001 C CNN
F 3 "" H 5450 1250 50  0001 C CNN
	1    5450 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1450 5450 1450
Wire Wire Line
	5450 1450 5450 1250
Wire Wire Line
	5250 1400 5250 1600
Wire Wire Line
	4850 1500 5450 1500
Wire Wire Line
	5450 1500 5450 1450
Connection ~ 5450 1450
$Comp
L power:GND #PWR?
U 1 1 5C4BAAFF
P 3450 2550
F 0 "#PWR?" H 3450 2300 50  0001 C CNN
F 1 "GND" H 3455 2377 50  0000 C CNN
F 2 "" H 3450 2550 50  0001 C CNN
F 3 "" H 3450 2550 50  0001 C CNN
	1    3450 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 2450 3450 2450
Wire Wire Line
	3450 2450 3450 2550
$Comp
L power:VCC #PWR?
U 1 1 5C4BBDAB
P 3300 1250
F 0 "#PWR?" H 3300 1100 50  0001 C CNN
F 1 "VCC" H 3317 1423 50  0000 C CNN
F 2 "" H 3300 1250 50  0001 C CNN
F 3 "" H 3300 1250 50  0001 C CNN
	1    3300 1250
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C4BBE25
P 5250 2200
F 0 "#PWR?" H 5250 2050 50  0001 C CNN
F 1 "VCC" H 5267 2373 50  0000 C CNN
F 2 "" H 5250 2200 50  0001 C CNN
F 3 "" H 5250 2200 50  0001 C CNN
	1    5250 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2350 5250 2200
Wire Wire Line
	4900 2350 5250 2350
$Comp
L power:GND #PWR?
U 1 1 5C4BC5D8
P 5900 3250
F 0 "#PWR?" H 5900 3000 50  0001 C CNN
F 1 "GND" H 5905 3077 50  0000 C CNN
F 2 "" H 5900 3250 50  0001 C CNN
F 3 "" H 5900 3250 50  0001 C CNN
	1    5900 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2550 5900 2550
Wire Wire Line
	5900 2550 5900 2850
$Comp
L power:VCC #PWR?
U 1 1 5C4BCA57
P 5950 2050
F 0 "#PWR?" H 5950 1900 50  0001 C CNN
F 1 "VCC" H 5967 2223 50  0000 C CNN
F 2 "" H 5950 2050 50  0001 C CNN
F 3 "" H 5950 2050 50  0001 C CNN
	1    5950 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2650 5950 2650
Wire Wire Line
	5950 2650 5950 2050
Wire Wire Line
	5900 2850 6100 2850
Connection ~ 5900 2850
Wire Wire Line
	5900 2850 5900 3250
Text Label 6150 1750 2    50   ~ 0
SDIO_CD
Wire Wire Line
	5750 2350 6100 2350
Text Label 5750 2950 2    50   ~ 0
D0
Text Label 5750 3050 2    50   ~ 0
D1
Text Label 5750 2250 2    50   ~ 0
D2
Wire Wire Line
	5750 2250 6100 2250
Wire Wire Line
	5750 2950 6100 2950
Wire Wire Line
	5750 3050 6100 3050
Text Label 5750 2750 2    50   ~ 0
SDIO_CK
Wire Wire Line
	5750 2750 6100 2750
Text Label 5750 2350 2    50   ~ 0
D3
Text Label 5750 2450 2    50   ~ 0
SDIO_CMD
Wire Wire Line
	5750 2450 6100 2450
Text Label 8050 2450 0    50   ~ 0
SDIO_CD
Wire Wire Line
	7900 2450 8050 2450
NoConn ~ 7900 2550
Wire Wire Line
	7900 2850 8050 2850
Wire Wire Line
	8050 2850 8050 3050
Wire Wire Line
	7900 2750 8050 2750
Wire Wire Line
	8050 2750 8050 2850
Connection ~ 8050 2850
$Comp
L power:GND #PWR?
U 1 1 5C4C38DF
P 8050 3050
F 0 "#PWR?" H 8050 2800 50  0001 C CNN
F 1 "GND" H 8055 2877 50  0000 C CNN
F 2 "" H 8050 3050 50  0001 C CNN
F 3 "" H 8050 3050 50  0001 C CNN
	1    8050 3050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
