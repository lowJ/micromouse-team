EESchema Schematic File Version 4
LIBS:Micromouse-cache
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
L Micromouse-rescue:Teensy3.2-Teensy U1
U 1 1 5C02D961
P 8150 3850
F 0 "U1" H 8150 5437 60  0000 C CNN
F 1 "Teensy3.2" H 8150 5331 60  0000 C CNN
F 2 "" H 8150 3050 60  0000 C CNN
F 3 "" H 8150 3050 60  0000 C CNN
	1    8150 3850
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U2
U 1 1 5C02DD3C
P 8150 1100
F 0 "U2" H 8150 1342 50  0000 C CNN
F 1 "LM7805_TO220" H 8150 1251 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8150 1325 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 8150 1050 50  0001 C CNN
	1    8150 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1100 8850 1100
Text Label 8850 1100 0    50   ~ 0
5V
Text Label 9150 4650 0    50   ~ 0
5V
$Comp
L power:+BATT #PWR?
U 1 1 5C02E09A
P 6850 700
F 0 "#PWR?" H 6850 550 50  0001 C CNN
F 1 "+BATT" V 6865 827 50  0000 L CNN
F 2 "" H 6850 700 50  0001 C CNN
F 3 "" H 6850 700 50  0001 C CNN
	1    6850 700 
	0    -1   -1   0   
$EndComp
$Comp
L power:-BATT #PWR?
U 1 1 5C02E0EA
P 6850 1050
F 0 "#PWR?" H 6850 900 50  0001 C CNN
F 1 "-BATT" V 6865 1177 50  0000 L CNN
F 2 "" H 6850 1050 50  0001 C CNN
F 3 "" H 6850 1050 50  0001 C CNN
	1    6850 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6850 700  7850 700 
Wire Wire Line
	7850 700  7850 1100
Wire Wire Line
	8150 1400 6850 1400
Wire Wire Line
	6850 1400 6850 1050
Wire Wire Line
	7150 2550 6850 2550
Wire Wire Line
	6850 2550 6850 1400
Connection ~ 6850 1400
$Comp
L LED:SFH4550 D3
U 1 1 5C02E421
P 2600 1150
F 0 "D3" V 2504 1303 50  0000 L CNN
F 1 "SFH4550" V 2595 1303 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_IRGrey" H 2600 1325 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic3/00116140_0.pdf" H 2550 1150 50  0001 C CNN
	1    2600 1150
	0    1    1    0   
$EndComp
$Comp
L LED:SFH4550 D2
U 1 1 5C02E569
P 2000 1150
F 0 "D2" V 1904 1303 50  0000 L CNN
F 1 "SFH4550" V 1995 1303 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_IRGrey" H 2000 1325 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic3/00116140_0.pdf" H 1950 1150 50  0001 C CNN
	1    2000 1150
	0    1    1    0   
$EndComp
$Comp
L LED:SFH4550 D1
U 1 1 5C02E5A9
P 1400 1150
F 0 "D1" V 1304 1303 50  0000 L CNN
F 1 "SFH4550" V 1395 1303 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_IRGrey" H 1400 1325 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic3/00116140_0.pdf" H 1350 1150 50  0001 C CNN
	1    1400 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 950  2000 950 
Connection ~ 2000 950 
Wire Wire Line
	2000 950  2600 950 
Connection ~ 2600 950 
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5C02E9BC
P 1450 2600
F 0 "Q?" H 1640 2646 50  0000 L CNN
F 1 "Q_Photo_NPN" H 1640 2555 50  0000 L CNN
F 2 "" H 1650 2700 50  0001 C CNN
F 3 "~" H 1450 2600 50  0001 C CNN
	1    1450 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5C02EBF2
P 2350 2600
F 0 "Q?" H 2540 2646 50  0000 L CNN
F 1 "Q_Photo_NPN" H 2540 2555 50  0000 L CNN
F 2 "" H 2550 2700 50  0001 C CNN
F 3 "~" H 2350 2600 50  0001 C CNN
	1    2350 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5C02ED4F
P 3250 2600
F 0 "Q?" H 3440 2646 50  0000 L CNN
F 1 "Q_Photo_NPN" H 3440 2555 50  0000 L CNN
F 2 "" H 3450 2700 50  0001 C CNN
F 3 "~" H 3250 2600 50  0001 C CNN
	1    3250 2600
	-1   0    0    1   
$EndComp
Text Label 3400 950  0    50   ~ 0
GND
Text Label 6350 2550 2    50   ~ 0
GND
Connection ~ 6850 2550
Wire Wire Line
	2600 950  3400 950 
Text Label 7150 4050 2    50   ~ 0
3.3V
Wire Wire Line
	1350 2800 2250 2800
Connection ~ 2250 2800
Wire Wire Line
	2250 2800 3150 2800
Connection ~ 3150 2800
Wire Wire Line
	3150 2800 3850 2800
Wire Wire Line
	1350 2400 1350 2250
Text Label 3850 1800 0    50   ~ 0
GND
Text Label 3850 2800 0    50   ~ 0
3.3V
Wire Wire Line
	2250 2400 2250 2250
Wire Wire Line
	3150 2400 3150 2250
Wire Wire Line
	1350 2250 1650 2250
Wire Wire Line
	2250 2250 2550 2250
Wire Wire Line
	3150 2250 3450 2250
Text Label 1650 2250 0    50   ~ 0
AI1
Text Label 2550 2250 0    50   ~ 0
AI2
Text Label 3450 2250 0    50   ~ 0
AI3
$Comp
L Micromouse-rescue:SN754410-SN754410 IC1
U 1 1 5C032363
P 3450 4150
F 0 "IC1" H 3450 4817 50  0000 C CNN
F 1 "SN754410" H 3450 4726 50  0000 C CNN
F 2 "DIL16" H 3450 4150 50  0001 L BNN
F 3 "the sn754410 is a quadruple high-current half-h driver designed to provide bidirectional drive currents up to 1 a at ..." H 3450 4150 50  0001 L BNN
F 4 "Texas Instruments" H 3450 4150 50  0001 L BNN "Field4"
F 5 "None" H 3450 4150 50  0001 L BNN "Field5"
F 6 "Unavailable" H 3450 4150 50  0001 L BNN "Field6"
F 7 "None" H 3450 4150 50  0001 L BNN "Field7"
F 8 "SN754410" H 3450 4150 50  0001 L BNN "Field8"
	1    3450 4150
	1    0    0    -1  
$EndComp
Text Label 2950 4150 2    50   ~ 0
GND
Text Label 3950 4150 0    50   ~ 0
GND
Text Label 2950 3850 2    50   ~ 0
M1Control
Text Label 7150 5150 2    50   ~ 0
M1Control
Text Label 3950 4550 0    50   ~ 0
M2Control
Text Label 9150 5150 0    50   ~ 0
M2Control
Text Label 2950 3950 2    50   ~ 0
M1Forward
Text Label 2950 4450 2    50   ~ 0
M1Backward
Text Label 3950 4450 0    50   ~ 0
M2Backward
Text Label 3950 3950 0    50   ~ 0
M2Forward
$Comp
L Motor:Motor_DC M2
U 1 1 5C034E92
P 1700 5050
F 0 "M2" H 1858 5046 50  0000 L CNN
F 1 "Motor_DC" H 1858 4955 50  0000 L CNN
F 2 "" H 1700 4960 50  0001 C CNN
F 3 "~" H 1700 4960 50  0001 C CNN
	1    1700 5050
	0    1    1    0   
$EndComp
$Comp
L Motor:Motor_DC M1
U 1 1 5C0350D5
P 5000 3150
F 0 "M1" H 5158 3146 50  0000 L CNN
F 1 "Motor_DC" H 5158 3055 50  0000 L CNN
F 2 "" H 5000 3060 50  0001 C CNN
F 3 "~" H 5000 3060 50  0001 C CNN
	1    5000 3150
	0    -1   -1   0   
$EndComp
Text Label 7150 4550 2    50   ~ 0
AI1
Text Label 7150 4650 2    50   ~ 0
AI2
Text Label 7150 4750 2    50   ~ 0
AI3
Text Label 3950 3850 0    50   ~ 0
Vinput
Text Label 2950 4550 2    50   ~ 0
Vinput
$Comp
L motor_encoder:Encoder SW1
U 1 1 5CBECCBE
P 5050 4150
F 0 "SW1" H 5008 3764 50  0000 C CNN
F 1 "Encoder" H 5008 3673 50  0000 C CNN
F 2 "" H 4900 4310 50  0001 C CNN
F 3 "~" H 5050 4410 50  0001 C CNN
	1    5050 4150
	1    0    0    -1  
$EndComp
$Comp
L motor_encoder:Encoder SW2
U 1 1 5CBECD66
P 1650 4200
F 0 "SW2" H 1608 3722 50  0000 C CNN
F 1 "Encoder" H 1608 3813 50  0000 C CNN
F 2 "" H 1500 4360 50  0001 C CNN
F 3 "~" H 1650 4460 50  0001 C CNN
	1    1650 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 3850 5150 3550
Wire Wire Line
	5150 3550 5300 3550
Wire Wire Line
	5300 3550 5300 3150
Wire Wire Line
	4800 3150 4800 3550
Wire Wire Line
	4800 3550 5000 3550
Wire Wire Line
	5000 3550 5000 3850
Wire Wire Line
	1900 5050 1900 4700
Wire Wire Line
	1900 4700 1700 4700
Wire Wire Line
	1700 4700 1700 4500
Wire Wire Line
	1400 5050 1400 4700
Wire Wire Line
	1400 4700 1550 4700
Wire Wire Line
	1550 4700 1550 4500
Wire Wire Line
	1650 3900 2500 3900
Wire Wire Line
	2500 3900 2500 4250
Wire Wire Line
	2500 4250 2950 4250
Wire Wire Line
	5050 4500 4550 4500
Wire Wire Line
	4550 4500 4550 4250
Wire Wire Line
	4550 4250 3950 4250
Wire Wire Line
	5050 4450 5050 4500
Text Label 7150 4850 2    50   ~ 0
D17
Text Label 7150 4950 2    50   ~ 0
D18
Text Label 1350 4300 2    50   ~ 0
D17
Text Label 5350 4250 0    50   ~ 0
D18
Wire Wire Line
	2950 4050 1950 4050
Wire Wire Line
	1950 4050 1950 4100
Wire Wire Line
	2950 4350 1950 4350
Wire Wire Line
	1950 4350 1950 4300
Wire Wire Line
	3950 4050 4750 4050
Wire Wire Line
	3950 4350 4750 4350
Wire Wire Line
	4750 4350 4750 4250
Text Label 1950 4200 0    50   ~ 0
5V
Text Label 4750 4150 3    50   ~ 0
5V
Text Label 7150 2650 2    50   ~ 0
D0
Text Label 7150 2750 2    50   ~ 0
D1
Text Label 7150 2850 2    50   ~ 0
D2
Text Label 1400 1550 3    50   ~ 0
D0
Text Label 2000 1550 3    50   ~ 0
D1
Text Label 2600 1550 3    50   ~ 0
D2
$Comp
L Device:R R3
U 1 1 5CC01A8F
P 3150 2100
F 0 "R3" H 3220 2146 50  0000 L CNN
F 1 "R" H 3220 2055 50  0000 L CNN
F 2 "" V 3080 2100 50  0001 C CNN
F 3 "~" H 3150 2100 50  0001 C CNN
	1    3150 2100
	1    0    0    -1  
$EndComp
Connection ~ 3150 2250
$Comp
L Device:R R2
U 1 1 5CC01AFA
P 2250 2100
F 0 "R2" H 2320 2146 50  0000 L CNN
F 1 "R" H 2320 2055 50  0000 L CNN
F 2 "" V 2180 2100 50  0001 C CNN
F 3 "~" H 2250 2100 50  0001 C CNN
	1    2250 2100
	1    0    0    -1  
$EndComp
Connection ~ 2250 2250
$Comp
L Device:R R1
U 1 1 5CC01B62
P 1350 2100
F 0 "R1" H 1420 2146 50  0000 L CNN
F 1 "R" H 1420 2055 50  0000 L CNN
F 2 "" V 1280 2100 50  0001 C CNN
F 3 "~" H 1350 2100 50  0001 C CNN
	1    1350 2100
	1    0    0    -1  
$EndComp
Connection ~ 1350 2250
Wire Wire Line
	1350 1800 2250 1800
Wire Wire Line
	1350 1950 1350 1800
Wire Wire Line
	2250 1950 2250 1800
Connection ~ 2250 1800
Wire Wire Line
	2250 1800 3150 1800
Wire Wire Line
	3150 1950 3150 1800
Connection ~ 3150 1800
Wire Wire Line
	3150 1800 3850 1800
$Comp
L Device:R R4
U 1 1 5CC0A77D
P 1400 1400
F 0 "R4" H 1470 1446 50  0000 L CNN
F 1 "R" H 1470 1355 50  0000 L CNN
F 2 "" V 1330 1400 50  0001 C CNN
F 3 "~" H 1400 1400 50  0001 C CNN
	1    1400 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5CC0A7FE
P 2000 1400
F 0 "R5" H 2070 1446 50  0000 L CNN
F 1 "R" H 2070 1355 50  0000 L CNN
F 2 "" V 1930 1400 50  0001 C CNN
F 3 "~" H 2000 1400 50  0001 C CNN
	1    2000 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5CC0A889
P 2600 1400
F 0 "R6" H 2670 1446 50  0000 L CNN
F 1 "R" H 2670 1355 50  0000 L CNN
F 2 "" V 2530 1400 50  0001 C CNN
F 3 "~" H 2600 1400 50  0001 C CNN
	1    2600 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2550 6850 2550
Text Notes 650  2100 0    50   ~ 0
R1-3 = 1.8kΩ\n
Text Notes 700  1400 0    50   ~ 0
R4-6 = 120Ω\n
$EndSCHEMATC
