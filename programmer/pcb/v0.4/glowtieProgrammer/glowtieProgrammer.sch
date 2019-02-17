EESchema Schematic File Version 4
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
L Connector:Conn_01x06_Female J2
U 1 1 5C5F9093
P 5200 4300
F 0 "J2" V 5047 3912 50  0000 R CNN
F 1 "Conn_01x06_Female" V 5138 3912 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 5200 4300 50  0001 C CNN
F 3 "~" H 5200 4300 50  0001 C CNN
	1    5200 4300
	0    -1   1    0   
$EndComp
$Comp
L Connector:Conn_01x05_Female J1
U 1 1 5C5F9234
P 5200 3200
F 0 "J1" V 5140 2912 50  0000 R CNN
F 1 "Conn_01x05_Female" V 5049 2912 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 5200 3200 50  0001 C CNN
F 3 "~" H 5200 3200 50  0001 C CNN
	1    5200 3200
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_SPDT SW1
U 1 1 5C5F95ED
P 5500 3600
F 0 "SW1" V 5546 3412 50  0000 R CNN
F 1 "SW_SPDT" V 5455 3412 50  0000 R CNN
F 2 "Buttons_Switches_SMD:SW_SPDT_PCM12" H 5500 3600 50  0001 C CNN
F 3 "" H 5500 3600 50  0001 C CNN
	1    5500 3600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5300 4100 5300 3900
Wire Wire Line
	5300 3900 5200 3900
Wire Wire Line
	5200 3900 5200 3400
Wire Wire Line
	5100 4100 5100 3400
Wire Wire Line
	5200 4100 5200 4000
Wire Wire Line
	5200 4000 5000 4000
Wire Wire Line
	5000 4000 5000 3400
Wire Wire Line
	5300 3850 5500 3850
Wire Wire Line
	5500 3850 5500 4100
Wire Wire Line
	5300 3400 5300 3850
Wire Wire Line
	5500 3850 5500 3800
Connection ~ 5500 3850
$EndSCHEMATC
