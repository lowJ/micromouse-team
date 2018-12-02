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
L Teensy:Teensy3.2 U?
U 1 1 5C02D961
P 8150 3850
F 0 "U?" H 8150 5437 60  0000 C CNN
F 1 "Teensy3.2" H 8150 5331 60  0000 C CNN
F 2 "" H 8150 3050 60  0000 C CNN
F 3 "" H 8150 3050 60  0000 C CNN
	1    8150 3850
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U?
U 1 1 5C02DD3C
P 8150 1100
F 0 "U?" H 8150 1342 50  0000 C CNN
F 1 "LM7805_TO220" H 8150 1251 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8150 1325 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 8150 1050 50  0001 C CNN
	1    8150 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1100 8850 1100
Text Label 8850 1100 0    50   ~ 0
Vinput
Text Label 9150 4650 0    50   ~ 0
Vinput
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
L LED:SFH4550 D?
U 1 1 5C02E421
P 2450 1150
F 0 "D?" V 2354 1303 50  0000 L CNN
F 1 "SFH4550" V 2445 1303 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_IRGrey" H 2450 1325 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic3/00116140_0.pdf" H 2400 1150 50  0001 C CNN
	1    2450 1150
	0    1    1    0   
$EndComp
$Comp
L LED:SFH4550 D?
U 1 1 5C02E569
P 1850 1150
F 0 "D?" V 1754 1303 50  0000 L CNN
F 1 "SFH4550" V 1845 1303 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_IRGrey" H 1850 1325 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic3/00116140_0.pdf" H 1800 1150 50  0001 C CNN
	1    1850 1150
	0    1    1    0   
$EndComp
$Comp
L LED:SFH4550 D?
U 1 1 5C02E5A9
P 1250 1150
F 0 "D?" V 1154 1303 50  0000 L CNN
F 1 "SFH4550" V 1245 1303 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_IRGrey" H 1250 1325 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic3/00116140_0.pdf" H 1200 1150 50  0001 C CNN
	1    1250 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 1250 2450 1250
Connection ~ 1850 1250
Wire Wire Line
	1850 1250 1250 1250
Connection ~ 2450 1250
Wire Wire Line
	2450 1250 1850 1250
Wire Wire Line
	1250 950  1850 950 
Connection ~ 1850 950 
Wire Wire Line
	1850 950  2450 950 
Connection ~ 2450 950 
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5C02E9BC
P 1200 2150
F 0 "Q?" H 1390 2196 50  0000 L CNN
F 1 "Q_Photo_NPN" H 1390 2105 50  0000 L CNN
F 2 "" H 1400 2250 50  0001 C CNN
F 3 "~" H 1200 2150 50  0001 C CNN
	1    1200 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5C02EBF2
P 2100 2150
F 0 "Q?" H 2290 2196 50  0000 L CNN
F 1 "Q_Photo_NPN" H 2290 2105 50  0000 L CNN
F 2 "" H 2300 2250 50  0001 C CNN
F 3 "~" H 2100 2150 50  0001 C CNN
	1    2100 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5C02ED4F
P 3000 2150
F 0 "Q?" H 3190 2196 50  0000 L CNN
F 1 "Q_Photo_NPN" H 3190 2105 50  0000 L CNN
F 2 "" H 3200 2250 50  0001 C CNN
F 3 "~" H 3000 2150 50  0001 C CNN
	1    3000 2150
	1    0    0    -1  
$EndComp
Text Label 3250 950  0    50   ~ 0
GND
Text Label 6750 2550 2    50   ~ 0
GND
Wire Wire Line
	6850 2550 6750 2550
Connection ~ 6850 2550
Wire Wire Line
	2450 950  3250 950 
Text Label 7150 4050 2    50   ~ 0
3.3V
Text Label 3250 1250 0    50   ~ 0
3.3V
Wire Wire Line
	1300 2350 2200 2350
Connection ~ 2200 2350
Wire Wire Line
	2200 2350 3100 2350
Connection ~ 3100 2350
Wire Wire Line
	3100 2350 3800 2350
Wire Wire Line
	1300 1950 1300 1800
Text Label 3800 1500 0    50   ~ 0
GND
Text Label 3800 2350 0    50   ~ 0
3.3V
Wire Wire Line
	2200 1950 2200 1800
Wire Wire Line
	1300 1500 2200 1500
Connection ~ 2200 1500
Wire Wire Line
	3100 1950 3100 1800
Wire Wire Line
	2200 1500 3100 1500
Connection ~ 3100 1500
Wire Wire Line
	3100 1500 3800 1500
Wire Wire Line
	1300 1800 1600 1800
Connection ~ 1300 1800
Wire Wire Line
	1300 1800 1300 1500
Wire Wire Line
	2200 1800 2500 1800
Connection ~ 2200 1800
Wire Wire Line
	2200 1800 2200 1500
Wire Wire Line
	3100 1800 3400 1800
Connection ~ 3100 1800
Wire Wire Line
	3100 1800 3100 1500
Text Label 1600 1800 0    50   ~ 0
AI1
Text Label 2500 1800 0    50   ~ 0
AI2
Text Label 3400 1800 0    50   ~ 0
AI3
$Comp
L SN754410:SN754410 IC?
U 1 1 5C032363
P 2450 3950
F 0 "IC?" H 2450 4617 50  0000 C CNN
F 1 "SN754410" H 2450 4526 50  0000 C CNN
F 2 "DIL16" H 2450 3950 50  0001 L BNN
F 3 "the sn754410 is a quadruple high-current half-h driver designed to provide bidirectional drive currents up to 1 a at ..." H 2450 3950 50  0001 L BNN
F 4 "Texas Instruments" H 2450 3950 50  0001 L BNN "Field4"
F 5 "None" H 2450 3950 50  0001 L BNN "Field5"
F 6 "Unavailable" H 2450 3950 50  0001 L BNN "Field6"
F 7 "None" H 2450 3950 50  0001 L BNN "Field7"
F 8 "SN754410" H 2450 3950 50  0001 L BNN "Field8"
	1    2450 3950
	1    0    0    -1  
$EndComp
Text Label 1950 3950 2    50   ~ 0
GND
Text Label 2950 3950 0    50   ~ 0
GND
Text Label 2950 4050 0    50   ~ 0
GND
Text Label 1950 4050 2    50   ~ 0
GND
Text Label 1950 3650 2    50   ~ 0
M1Control
Text Label 7150 5150 2    50   ~ 0
M1Control
Text Label 2950 4350 0    50   ~ 0
M2Control
Text Label 9150 5150 0    50   ~ 0
M2Control
Text Label 1950 3750 2    50   ~ 0
M1Forward
Text Label 1950 4250 2    50   ~ 0
M1Backward
Text Label 2950 4250 0    50   ~ 0
M2Backward
Text Label 2950 3750 0    50   ~ 0
M2Forward
$Comp
L Motor:Motor_DC M?
U 1 1 5C034E92
P 1700 6050
F 0 "M?" H 1858 6046 50  0000 L CNN
F 1 "Motor_DC" H 1858 5955 50  0000 L CNN
F 2 "" H 1700 5960 50  0001 C CNN
F 3 "~" H 1700 5960 50  0001 C CNN
	1    1700 6050
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M?
U 1 1 5C0350D5
P 3350 6050
F 0 "M?" H 3508 6046 50  0000 L CNN
F 1 "Motor_DC" H 3508 5955 50  0000 L CNN
F 2 "" H 3350 5960 50  0001 C CNN
F 3 "~" H 3350 5960 50  0001 C CNN
	1    3350 6050
	1    0    0    -1  
$EndComp
Text Label 7150 4550 2    50   ~ 0
AI1
Text Label 7150 4650 2    50   ~ 0
AI2
Text Label 7150 4750 2    50   ~ 0
AI3
Text Label 2950 3650 0    50   ~ 0
Vinput
Text Label 1950 4350 2    50   ~ 0
Vinput
$EndSCHEMATC
