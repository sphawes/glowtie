EESchema Schematic File Version 4
LIBS:glowtie-cache
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
L power1:+3.3V #PWR01
U 1 1 5A7EBE0A
P 6250 2850
F 0 "#PWR01" H 6250 2700 50  0001 C CNN
F 1 "+3.3V" H 6250 2990 50  0000 C CNN
F 2 "" H 6250 2850 50  0001 C CNN
F 3 "" H 6250 2850 50  0001 C CNN
	1    6250 2850
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR02
U 1 1 5A7EBE31
P 1350 3400
F 0 "#PWR02" H 1350 3150 50  0001 C CNN
F 1 "GND" H 1350 3250 50  0000 C CNN
F 2 "" H 1350 3400 50  0001 C CNN
F 3 "" H 1350 3400 50  0001 C CNN
	1    1350 3400
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR03
U 1 1 5A7EC5E8
P 7350 2300
F 0 "#PWR03" H 7350 2050 50  0001 C CNN
F 1 "GND" H 7350 2150 50  0000 C CNN
F 2 "" H 7350 2300 50  0001 C CNN
F 3 "" H 7350 2300 50  0001 C CNN
	1    7350 2300
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR04
U 1 1 5A7EC635
P 5150 2650
F 0 "#PWR04" H 5150 2400 50  0001 C CNN
F 1 "GND" H 5150 2500 50  0000 C CNN
F 2 "" H 5150 2650 50  0001 C CNN
F 3 "" H 5150 2650 50  0001 C CNN
	1    5150 2650
	1    0    0    -1  
$EndComp
$Comp
L device:C 10uF1
U 1 1 5A7EC73C
P 1900 2600
F 0 "10uF1" H 1925 2700 50  0000 L CNN
F 1 "C" H 1925 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1938 2450 50  0001 C CNN
F 3 "" H 1900 2600 50  0001 C CNN
	1    1900 2600
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR05
U 1 1 5A7EC773
P 1900 3400
F 0 "#PWR05" H 1900 3150 50  0001 C CNN
F 1 "GND" H 1900 3250 50  0000 C CNN
F 2 "" H 1900 3400 50  0001 C CNN
F 3 "" H 1900 3400 50  0001 C CNN
	1    1900 3400
	1    0    0    -1  
$EndComp
$Comp
L device:C 10uF2
U 1 1 5A7ECC46
P 5150 2450
F 0 "10uF2" H 5175 2550 50  0000 L CNN
F 1 "C" H 5175 2350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5188 2300 50  0001 C CNN
F 3 "" H 5150 2450 50  0001 C CNN
	1    5150 2450
	1    0    0    -1  
$EndComp
$Comp
L device:R_Small R2
U 1 1 5A7ECE11
P 2950 2500
F 0 "R2" H 2980 2520 50  0000 L CNN
F 1 "2K" H 2980 2460 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2950 2500 50  0001 C CNN
F 3 "" H 2950 2500 50  0001 C CNN
	1    2950 2500
	1    0    0    -1  
$EndComp
$Comp
L conn:TEST_1P J4
U 1 1 5A7ED126
P 10500 1200
F 0 "J4" H 10500 1470 50  0000 C CNN
F 1 "POGO_TX" H 10500 1400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 10700 1200 50  0001 C CNN
F 3 "" H 10700 1200 50  0001 C CNN
	1    10500 1200
	-1   0    0    1   
$EndComp
$Comp
L conn:TEST_1P J2
U 1 1 5A7ED196
P 10250 1300
F 0 "J2" H 10250 1570 50  0000 C CNN
F 1 "POGO_RX" H 10250 1500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 10450 1300 50  0001 C CNN
F 3 "" H 10450 1300 50  0001 C CNN
	1    10250 1300
	-1   0    0    1   
$EndComp
$Comp
L Worldsemi:WS2812B LED3
U 1 1 5A7ED761
P 3850 5250
F 0 "LED3" H 3850 5050 50  0000 C CNN
F 1 "WS2812B" H 3850 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 3850 4950 50  0001 C CNN
F 3 "" H 3850 5200 50  0001 C CNN
	1    3850 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED4
U 1 1 5A7ED915
P 5100 5250
F 0 "LED4" H 5100 5050 50  0000 C CNN
F 1 "WS2812B" H 5100 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 5100 4950 50  0001 C CNN
F 3 "" H 5100 5200 50  0001 C CNN
	1    5100 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED5
U 1 1 5A7ED96F
P 6350 5250
F 0 "LED5" H 6350 5050 50  0000 C CNN
F 1 "WS2812B" H 6350 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 6350 4950 50  0001 C CNN
F 3 "" H 6350 5200 50  0001 C CNN
	1    6350 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED6
U 1 1 5A7ED9CB
P 7550 5250
F 0 "LED6" H 7550 5050 50  0000 C CNN
F 1 "WS2812B" H 7550 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 7550 4950 50  0001 C CNN
F 3 "" H 7550 5200 50  0001 C CNN
	1    7550 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED7
U 1 1 5A7EDA2D
P 8800 5250
F 0 "LED7" H 8800 5050 50  0000 C CNN
F 1 "WS2812B" H 8800 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 8800 4950 50  0001 C CNN
F 3 "" H 8800 5200 50  0001 C CNN
	1    8800 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED2
U 1 1 5A7EDA91
P 2650 5250
F 0 "LED2" H 2650 5050 50  0000 C CNN
F 1 "WS2812B" H 2650 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 2650 4950 50  0001 C CNN
F 3 "" H 2650 5200 50  0001 C CNN
	1    2650 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED1
U 1 1 5A7EDAF1
P 1450 5250
F 0 "LED1" H 1450 5050 50  0000 C CNN
F 1 "WS2812B" H 1450 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 1450 4950 50  0001 C CNN
F 3 "" H 1450 5200 50  0001 C CNN
	1    1450 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED8
U 1 1 5A7EDB51
P 10000 5250
F 0 "LED8" H 10000 5050 50  0000 C CNN
F 1 "WS2812B" H 10000 5350 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 10000 4950 50  0001 C CNN
F 3 "" H 10000 5200 50  0001 C CNN
	1    10000 5250
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED9
U 1 1 5A7EDC18
P 1450 6150
F 0 "LED9" H 1450 5950 50  0000 C CNN
F 1 "WS2812B" H 1450 6250 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 1450 5850 50  0001 C CNN
F 3 "" H 1450 6100 50  0001 C CNN
	1    1450 6150
	1    0    0    -1  
$EndComp
NoConn ~ 7150 6250
$Comp
L Worldsemi:WS2812B LED10
U 1 1 5A7EDCAA
P 2650 6150
F 0 "LED10" H 2650 5950 50  0000 C CNN
F 1 "WS2812B" H 2650 6250 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 2650 5850 50  0001 C CNN
F 3 "" H 2650 6100 50  0001 C CNN
	1    2650 6150
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED11
U 1 1 5A7EDD1C
P 3850 6150
F 0 "LED11" H 3850 5950 50  0000 C CNN
F 1 "WS2812B" H 3850 6250 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 3850 5850 50  0001 C CNN
F 3 "" H 3850 6100 50  0001 C CNN
	1    3850 6150
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED12
U 1 1 5A7EDD96
P 5050 6150
F 0 "LED12" H 5050 5950 50  0000 C CNN
F 1 "WS2812B" H 5050 6250 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 5050 5850 50  0001 C CNN
F 3 "" H 5050 6100 50  0001 C CNN
	1    5050 6150
	1    0    0    -1  
$EndComp
$Comp
L Worldsemi:WS2812B LED13
U 1 1 5A7EDE0F
P 6300 6150
F 0 "LED13" H 6300 5950 50  0000 C CNN
F 1 "WS2812B" H 6300 6250 50  0000 C CNN
F 2 "LEDs:LED_WS2812B-PLCC4" H 6300 5850 50  0001 C CNN
F 3 "" H 6300 6100 50  0001 C CNN
	1    6300 6150
	1    0    0    -1  
$EndComp
$Comp
L conn:TEST_1P J6
U 1 1 5AA59671
P 5400 3000
F 0 "J6" H 5400 3270 50  0000 C CNN
F 1 "GND_BATT1" H 5400 3200 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Big" H 5600 3000 50  0001 C CNN
F 3 "" H 5600 3000 50  0001 C CNN
	1    5400 3000
	-1   0    0    1   
$EndComp
$Comp
L conn:TEST_1P J7
U 1 1 5AA59972
P 5650 2900
F 0 "J7" H 5650 3170 50  0000 C CNN
F 1 "GND_BATT2" H 5650 3100 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Big" H 5850 2900 50  0001 C CNN
F 3 "" H 5850 2900 50  0001 C CNN
	1    5650 2900
	-1   0    0    1   
$EndComp
$Comp
L conn:TEST_1P J8
U 1 1 5AA59CE0
P 5150 2150
F 0 "J8" H 5150 2420 50  0000 C CNN
F 1 "VBATT1" H 5150 2350 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Big" H 5350 2150 50  0001 C CNN
F 3 "" H 5350 2150 50  0001 C CNN
	1    5150 2150
	1    0    0    -1  
$EndComp
$Comp
L conn:TEST_1P J9
U 1 1 5AA59D8C
P 5450 2150
F 0 "J9" H 5450 2420 50  0000 C CNN
F 1 "VBATT2" H 5450 2350 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Big" H 5650 2150 50  0001 C CNN
F 3 "" H 5650 2150 50  0001 C CNN
	1    5450 2150
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR06
U 1 1 5AA5A961
P 6700 6400
F 0 "#PWR06" H 6700 6150 50  0001 C CNN
F 1 "GND" H 6700 6250 50  0000 C CNN
F 2 "" H 6700 6400 50  0001 C CNN
F 3 "" H 6700 6400 50  0001 C CNN
	1    6700 6400
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR07
U 1 1 5AA5A847
P 6250 3150
F 0 "#PWR07" H 6250 2900 50  0001 C CNN
F 1 "GND" H 6250 3000 50  0000 C CNN
F 2 "" H 6250 3150 50  0001 C CNN
F 3 "" H 6250 3150 50  0001 C CNN
	1    6250 3150
	1    0    0    -1  
$EndComp
$Comp
L device:C 1uF3
U 1 1 5AC3F7A8
P 6250 3000
F 0 "1uF3" H 6275 3100 50  0000 L CNN
F 1 "C" H 6275 2900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6288 2850 50  0001 C CNN
F 3 "" H 6250 3000 50  0001 C CNN
	1    6250 3000
	1    0    0    -1  
$EndComp
$Comp
L device:R R470
U 1 1 5AC3FC03
P 2650 3050
F 0 "R470" V 2730 3050 50  0000 C CNN
F 1 "R" V 2650 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 3050 50  0001 C CNN
F 3 "" H 2650 3050 50  0001 C CNN
	1    2650 3050
	0    1    1    0   
$EndComp
$Comp
L device:R R470_1
U 1 1 5AC3FCB1
P 2650 3300
F 0 "R470_1" V 2730 3300 50  0000 C CNN
F 1 "R" V 2650 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 3300 50  0001 C CNN
F 3 "" H 2650 3300 50  0001 C CNN
	1    2650 3300
	0    1    1    0   
$EndComp
$Comp
L device:R_Small R4
U 1 1 5B451119
P 10750 1350
F 0 "R4" H 10780 1370 50  0000 L CNN
F 1 "10K" H 10780 1310 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 10750 1350 50  0001 C CNN
F 3 "" H 10750 1350 50  0001 C CNN
	1    10750 1350
	1    0    0    -1  
$EndComp
$Comp
L power1:+3.3V #PWR08
U 1 1 5B4512A4
P 10750 750
F 0 "#PWR08" H 10750 600 50  0001 C CNN
F 1 "+3.3V" H 10750 890 50  0000 C CNN
F 2 "" H 10750 750 50  0001 C CNN
F 3 "" H 10750 750 50  0001 C CNN
	1    10750 750 
	1    0    0    -1  
$EndComp
$Comp
L device:R_Small R5
U 1 1 5B451545
P 11000 1350
F 0 "R5" H 11030 1370 50  0000 L CNN
F 1 "10K" H 11030 1310 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 11000 1350 50  0001 C CNN
F 3 "" H 11000 1350 50  0001 C CNN
	1    11000 1350
	1    0    0    -1  
$EndComp
$Comp
L conn:TEST_1P J5
U 1 1 5B45192B
P 10750 1600
F 0 "J5" H 10750 1870 50  0000 C CNN
F 1 "BOOT2" H 10750 1800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 10950 1600 50  0001 C CNN
F 3 "" H 10950 1600 50  0001 C CNN
	1    10750 1600
	-1   0    0    1   
$EndComp
$Comp
L device:R_Small R3
U 1 1 5B451B5E
P 10100 1900
F 0 "R3" H 10130 1920 50  0000 L CNN
F 1 "10K" H 10130 1860 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 10100 1900 50  0001 C CNN
F 3 "" H 10100 1900 50  0001 C CNN
	1    10100 1900
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR09
U 1 1 5B451F52
P 10100 2000
F 0 "#PWR09" H 10100 1750 50  0001 C CNN
F 1 "GND" H 10100 1850 50  0000 C CNN
F 2 "" H 10100 2000 50  0001 C CNN
F 3 "" H 10100 2000 50  0001 C CNN
	1    10100 2000
	1    0    0    -1  
$EndComp
$Comp
L device:R_Small R1
U 1 1 5B452071
P 7800 1100
F 0 "R1" H 7830 1120 50  0000 L CNN
F 1 "10K" H 7830 1060 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 7800 1100 50  0001 C CNN
F 3 "" H 7800 1100 50  0001 C CNN
	1    7800 1100
	1    0    0    -1  
$EndComp
Text GLabel 8050 1700 0    60   Input ~ 0
LED_SIG
Text GLabel 850  4900 2    60   Input ~ 0
LED_SIG
$Comp
L power1:+BATT #PWR010
U 1 1 5B452B4C
P 6250 2100
F 0 "#PWR010" H 6250 1950 50  0001 C CNN
F 1 "+BATT" H 6250 2240 50  0000 C CNN
F 2 "" H 6250 2100 50  0001 C CNN
F 3 "" H 6250 2100 50  0001 C CNN
	1    6250 2100
	1    0    0    -1  
$EndComp
$Comp
L power1:+BATT #PWR011
U 1 1 5B452C4C
P 2250 5100
F 0 "#PWR011" H 2250 4950 50  0001 C CNN
F 1 "+BATT" H 2250 5240 50  0000 C CNN
F 2 "" H 2250 5100 50  0001 C CNN
F 3 "" H 2250 5100 50  0001 C CNN
	1    2250 5100
	1    0    0    -1  
$EndComp
$Comp
L stephen:MCP1826S-3302E U2
U 1 1 5AA58DE1
P 6800 2350
F 0 "U2" H 6800 1950 60  0000 C CNN
F 1 "MCP1826S-3302E" H 6800 2050 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 6800 2350 60  0001 C CNN
F 3 "" H 6800 2350 60  0001 C CNN
	1    6800 2350
	1    0    0    -1  
$EndComp
$Comp
L conn:TEST_1P J11
U 1 1 5B455B0B
P 10550 2700
F 0 "J11" H 10550 2970 50  0000 C CNN
F 1 "POGO_GND" H 10550 2900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 10750 2700 50  0001 C CNN
F 3 "" H 10750 2700 50  0001 C CNN
	1    10550 2700
	1    0    0    -1  
$EndComp
$Comp
L conn:TEST_1P J10
U 1 1 5B455B9D
P 9950 2650
F 0 "J10" H 9950 2920 50  0000 C CNN
F 1 "POGO_3V3" H 9950 2850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 10150 2650 50  0001 C CNN
F 3 "" H 10150 2650 50  0001 C CNN
	1    9950 2650
	-1   0    0    1   
$EndComp
$Comp
L power1:+3.3V #PWR012
U 1 1 5B455ED1
P 9950 2650
F 0 "#PWR012" H 9950 2500 50  0001 C CNN
F 1 "+3.3V" H 9950 2790 50  0000 C CNN
F 2 "" H 9950 2650 50  0001 C CNN
F 3 "" H 9950 2650 50  0001 C CNN
	1    9950 2650
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR013
U 1 1 5B455F54
P 10550 2700
F 0 "#PWR013" H 10550 2450 50  0001 C CNN
F 1 "GND" H 10550 2550 50  0000 C CNN
F 2 "" H 10550 2700 50  0001 C CNN
F 3 "" H 10550 2700 50  0001 C CNN
	1    10550 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2450 1900 2450
Wire Wire Line
	1900 2750 1900 3300
Connection ~ 1900 2450
Wire Wire Line
	1350 3400 1350 3050
Wire Wire Line
	5150 2650 5150 2600
Connection ~ 5150 2650
Wire Wire Line
	1850 5250 2050 5250
Wire Wire Line
	2050 5250 2050 5350
Wire Wire Line
	2050 5350 2250 5350
Wire Wire Line
	3050 5250 3250 5250
Wire Wire Line
	3250 5250 3250 5350
Wire Wire Line
	3250 5350 3450 5350
Wire Wire Line
	4250 5250 4500 5250
Wire Wire Line
	4500 5250 4500 5350
Wire Wire Line
	4500 5350 4700 5350
Wire Wire Line
	5500 5250 5750 5250
Wire Wire Line
	5750 5250 5750 5350
Wire Wire Line
	5750 5350 5950 5350
Wire Wire Line
	6750 5250 7000 5250
Wire Wire Line
	7000 5250 7000 5350
Wire Wire Line
	7000 5350 7150 5350
Wire Wire Line
	7950 5250 8150 5250
Wire Wire Line
	8150 5250 8150 5350
Wire Wire Line
	8150 5350 8400 5350
Wire Wire Line
	9200 5250 9400 5250
Wire Wire Line
	9400 5250 9400 5350
Wire Wire Line
	9400 5350 9600 5350
Wire Wire Line
	10400 5250 10700 5250
Wire Wire Line
	10700 5250 10700 5750
Wire Wire Line
	10700 5750 750  5750
Wire Wire Line
	750  5750 750  6250
Wire Wire Line
	750  6250 1050 6250
Wire Wire Line
	650  5500 1850 5500
Wire Wire Line
	10400 5500 10400 5350
Wire Wire Line
	1850 5350 1850 5500
Connection ~ 1850 5500
Wire Wire Line
	3050 5350 3050 5500
Connection ~ 3050 5500
Wire Wire Line
	4250 5350 4250 5500
Connection ~ 4250 5500
Wire Wire Line
	5500 5350 5500 5500
Connection ~ 5500 5500
Wire Wire Line
	6750 5350 6750 5500
Connection ~ 6750 5500
Wire Wire Line
	7950 5350 7950 5500
Connection ~ 7950 5500
Wire Wire Line
	9200 5350 9200 5500
Connection ~ 9200 5500
Wire Wire Line
	650  5500 650  6400
Wire Wire Line
	650  6400 1850 6400
Wire Wire Line
	1850 6250 1850 6400
Connection ~ 1850 6400
Connection ~ 3050 6400
Connection ~ 4250 6400
Wire Wire Line
	5450 6250 5450 6400
Connection ~ 5450 6400
Wire Wire Line
	6700 6400 6700 6250
Connection ~ 6700 6400
Wire Wire Line
	1050 6150 1050 6000
Wire Wire Line
	1050 6000 2250 6000
Wire Wire Line
	11000 5100 11000 6000
Wire Wire Line
	1050 5100 2250 5100
Wire Wire Line
	1050 5100 1050 5250
Wire Wire Line
	2250 5250 2250 5100
Connection ~ 2250 5100
Wire Wire Line
	3450 5250 3450 5100
Connection ~ 3450 5100
Connection ~ 2250 6000
Connection ~ 3450 6000
Wire Wire Line
	5900 6150 5900 6000
Connection ~ 5900 6000
Wire Wire Line
	9600 5250 9600 5100
Connection ~ 9600 5100
Wire Wire Line
	8400 5100 8400 5250
Connection ~ 8400 5100
Wire Wire Line
	7150 5250 7150 5100
Connection ~ 7150 5100
Wire Wire Line
	5950 5250 5950 5100
Connection ~ 5950 5100
Wire Wire Line
	4700 5250 4700 5100
Connection ~ 4700 5100
Wire Wire Line
	1850 6150 2050 6150
Wire Wire Line
	5450 6150 5650 6150
Wire Wire Line
	5650 6150 5650 6250
Wire Wire Line
	5650 6250 5900 6250
Wire Wire Line
	6700 6150 6950 6150
Wire Wire Line
	6950 6150 6950 6250
Wire Wire Line
	6950 6250 7150 6250
Wire Wire Line
	850  4900 850  5350
Wire Wire Line
	850  5350 1050 5350
Connection ~ 5150 2300
Wire Wire Line
	3050 6250 3050 6400
Wire Wire Line
	2050 6150 2050 6250
Wire Wire Line
	2050 6250 2250 6250
Wire Wire Line
	2250 6150 2250 6000
Connection ~ 4650 6000
Wire Wire Line
	4650 6150 4650 6000
Wire Wire Line
	4450 6250 4650 6250
Wire Wire Line
	4250 6150 4450 6150
Wire Wire Line
	4450 6150 4450 6250
Wire Wire Line
	4250 6250 4250 6400
Wire Wire Line
	3450 6150 3450 6000
Wire Wire Line
	3250 6250 3450 6250
Wire Wire Line
	3250 6150 3250 6250
Wire Wire Line
	3050 6150 3250 6150
Wire Wire Line
	2950 3050 2950 3300
Wire Wire Line
	2800 3050 2950 3050
Wire Wire Line
	2950 3300 2800 3300
Connection ~ 2950 3050
Wire Wire Line
	2200 3050 2200 2450
Connection ~ 2200 2450
Wire Wire Line
	2200 3300 1900 3300
Connection ~ 1900 3300
Wire Wire Line
	9850 1200 10500 1200
Wire Wire Line
	10750 750  10750 1250
Wire Wire Line
	11000 750  11000 1250
Wire Wire Line
	7550 750  7800 750 
Wire Wire Line
	9850 1800 10100 1800
Wire Wire Line
	10100 2000 9850 2000
Wire Wire Line
	9850 2000 9850 1900
Wire Wire Line
	7800 1000 7800 750 
Connection ~ 10750 750 
Wire Wire Line
	7550 1900 7550 750 
Wire Wire Line
	7800 1200 7800 1400
Wire Wire Line
	7800 1400 8050 1400
Connection ~ 7800 750 
Wire Wire Line
	9850 1300 10250 1300
Wire Wire Line
	9850 1600 10750 1600
Wire Wire Line
	10750 1600 10750 1450
Wire Wire Line
	9850 1700 10550 1700
Wire Wire Line
	10550 1700 10550 1950
Wire Wire Line
	10550 1950 11000 1950
Wire Wire Line
	11000 1950 11000 1450
Wire Wire Line
	5650 2300 5150 2300
Wire Wire Line
	5150 2150 5450 2150
Wire Wire Line
	5650 2650 5650 2900
Wire Wire Line
	5650 2900 5400 2900
Wire Wire Line
	5400 2900 5400 3000
Wire Wire Line
	2950 2650 3500 2650
Wire Wire Line
	5850 2300 6250 2300
Wire Wire Line
	5650 2000 5650 2150
Connection ~ 5650 2150
Connection ~ 5450 2150
Wire Wire Line
	5850 2300 5850 3150
Wire Wire Line
	5850 3150 6250 3150
Wire Wire Line
	6100 2850 6250 2850
Wire Wire Line
	6250 2500 6100 2500
$Comp
L conn:USB_OTG J1
U 1 1 5B88211B
P 1350 2650
F 0 "J1" H 1150 3100 50  0000 L CNN
F 1 "USB_OTG" H 1150 3000 50  0000 L CNN
F 2 "Connectors:USB_Micro-B" H 1500 2600 50  0001 C CNN
F 3 "" H 1500 2600 50  0001 C CNN
	1    1350 2650
	1    0    0    -1  
$EndComp
$Comp
L battery_management:MCP73831-2-OT U1
U 1 1 5B8822AC
P 3500 2250
F 0 "U1" H 3200 2500 50  0000 L CNN
F 1 "MCP73831-2-OT" H 3550 2500 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 3550 2000 50  0001 L CIN
F 3 "" H 3350 2200 50  0001 C CNN
	1    3500 2250
	1    0    0    -1  
$EndComp
$Comp
L switches:SW_SPDT SW1
U 1 1 5B88237B
P 5850 1900
F 0 "SW1" H 5850 2070 50  0000 C CNN
F 1 "SW_SPDT" H 5850 1700 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPDT_PCM12" H 5850 1900 50  0001 C CNN
F 3 "" H 5850 1900 50  0001 C CNN
	1    5850 1900
	-1   0    0    1   
$EndComp
$Comp
L device:LED D2
U 1 1 5B8823EC
P 2350 3300
F 0 "D2" H 2350 3400 50  0000 C CNN
F 1 "LED" H 2350 3200 50  0000 C CNN
F 2 "LEDs:LED_0805" H 2350 3300 50  0001 C CNN
F 3 "" H 2350 3300 50  0001 C CNN
	1    2350 3300
	1    0    0    -1  
$EndComp
$Comp
L device:LED D1
U 1 1 5B882698
P 2350 3050
F 0 "D1" H 2350 3150 50  0000 C CNN
F 1 "LED" H 2350 2950 50  0000 C CNN
F 2 "LEDs:LED_0805" H 2350 3050 50  0001 C CNN
F 3 "" H 2350 3050 50  0001 C CNN
	1    2350 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 2450 2400 1950
Wire Wire Line
	2400 1950 3500 1950
Wire Wire Line
	3500 2650 3500 2550
Wire Wire Line
	3900 3050 3900 2350
Wire Wire Line
	2950 2400 2950 2350
Wire Wire Line
	2950 2350 3100 2350
Wire Wire Line
	2950 2650 2950 2600
Connection ~ 3500 2650
Wire Wire Line
	3900 2150 4550 2150
Wire Wire Line
	4550 2150 4550 2300
Wire Wire Line
	6250 2100 6150 2100
Wire Wire Line
	6150 2100 6150 1900
Wire Wire Line
	6150 1900 6050 1900
$Comp
L ESP8266:ESP-12F U3
U 1 1 5B450BD3
P 8950 1500
F 0 "U3" H 8950 1400 50  0000 C CNN
F 1 "ESP-12F" H 8950 1600 50  0000 C CNN
F 2 "ESP8266:ESP-12E_SMD" H 8950 1500 50  0001 C CNN
F 3 "" H 8950 1500 50  0001 C CNN
	1    8950 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 2450 2200 2450
Wire Wire Line
	5150 2650 5650 2650
Wire Wire Line
	1850 5500 3050 5500
Wire Wire Line
	3050 5500 4250 5500
Wire Wire Line
	4250 5500 5500 5500
Wire Wire Line
	5500 5500 6750 5500
Wire Wire Line
	6750 5500 7950 5500
Wire Wire Line
	7950 5500 9200 5500
Wire Wire Line
	9200 5500 10400 5500
Wire Wire Line
	1850 6400 3050 6400
Wire Wire Line
	3050 6400 4250 6400
Wire Wire Line
	4250 6400 5450 6400
Wire Wire Line
	5450 6400 6700 6400
Wire Wire Line
	2250 5100 3450 5100
Wire Wire Line
	3450 5100 4700 5100
Wire Wire Line
	2250 6000 3450 6000
Wire Wire Line
	3450 6000 4650 6000
Wire Wire Line
	9600 5100 11000 5100
Wire Wire Line
	8400 5100 9600 5100
Wire Wire Line
	7150 5100 8400 5100
Wire Wire Line
	5950 5100 7150 5100
Wire Wire Line
	4700 5100 5950 5100
Wire Wire Line
	5150 2300 4550 2300
Wire Wire Line
	4650 6000 5900 6000
Wire Wire Line
	2950 3050 3900 3050
Wire Wire Line
	2200 2450 2400 2450
Wire Wire Line
	1900 3300 1900 3400
Wire Wire Line
	10750 750  11000 750 
Wire Wire Line
	7800 750  10750 750 
Wire Wire Line
	5650 2150 5650 2300
Wire Wire Line
	5450 2150 5650 2150
Wire Wire Line
	7550 1900 8050 1900
Wire Wire Line
	6100 2500 6100 2850
Wire Wire Line
	3500 2650 5150 2650
Wire Wire Line
	5900 6000 11000 6000
Connection ~ 5650 2900
Connection ~ 6250 2100
Connection ~ 6250 2850
Connection ~ 6250 3150
$EndSCHEMATC
