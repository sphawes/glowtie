EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:allegro
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
LIBS:bosch
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:deeplocal
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ESP8266
LIBS:ftdi
LIBS:gennum
LIBS:graphic_symbols
LIBS:hc11
LIBS:infineon
LIBS:intersil
LIBS:ir
LIBS:Lattice
LIBS:leds
LIBS:LEM
LIBS:logic_programmable
LIBS:maxim
LIBS:mechanical
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic24mcu
LIBS:microchip_pic32mcu
LIBS:modules
LIBS:motor_drivers
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:nxp
LIBS:onsemi
LIBS:Oscillators
LIBS:Power_Management
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:RFSolutions
LIBS:sensors
LIBS:silabs
LIBS:stephen
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:triac_thyristor
LIBS:ttl_ieee
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:zetex
LIBS:Zilog
EELAYER 25 0
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
L CONN_01X05 P?
U 1 1 5B8D58CF
P 8450 3150
F 0 "P?" H 8450 3450 50  0000 C CNN
F 1 "CONN_01X05" V 8550 3150 50  0000 C CNN
F 2 "" H 8450 3150 50  0000 C CNN
F 3 "" H 8450 3150 50  0000 C CNN
	1    8450 3150
	1    0    0    -1  
$EndComp
$Comp
L SW_Push_Open SW?
U 1 1 5B8D5987
P 7500 2950
F 0 "SW?" H 7500 3050 50  0000 C CNN
F 1 "reset" H 7500 2875 50  0000 C CNN
F 2 "" H 7500 3150 50  0001 C CNN
F 3 "" H 7500 3150 50  0001 C CNN
	1    7500 2950
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW?
U 1 1 5B8D59C4
P 7200 3800
F 0 "SW?" H 7200 3970 50  0000 C CNN
F 1 "programToggle" H 7200 3600 50  0000 C CNN
F 2 "" H 7200 3800 50  0001 C CNN
F 3 "" H 7200 3800 50  0001 C CNN
	1    7200 3800
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 P?
U 1 1 5B8D5A19
P 5950 3150
F 0 "P?" H 5950 3500 50  0000 C CNN
F 1 "CONN_01X06" V 6050 3150 50  0000 C CNN
F 2 "" H 5950 3150 50  0000 C CNN
F 3 "" H 5950 3150 50  0000 C CNN
	1    5950 3150
	-1   0    0    1   
$EndComp
$EndSCHEMATC
