EESchema Schematic File Version 4
LIBS:LEDMatrix-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "mar. 31 mars 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 1095 2265
Connection ~ 1095 2615
Wire Wire Line
	1095 2615 1095 2965
Wire Wire Line
	1095 2965 1095 3315
Connection ~ 1095 2965
Wire Wire Line
	1095 2265 1095 2615
Wire Wire Line
	1095 2030 1095 2265
$Comp
L LEDMatrix-rescue:74HC595-74hc595LED U1
U 1 1 5E0E05C8
P 4670 3625
F 0 "U1" H 4329 4258 50  0000 C CNN
F 1 "74HC595" H 4329 4179 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 4670 3625 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4670 3625 50  0001 C CNN
	1    4670 3625
	1    0    0    -1  
$EndComp
Wire Wire Line
	2095 4265 1995 4265
Connection ~ 2095 4265
Wire Wire Line
	2095 4115 2095 4265
Wire Wire Line
	1995 4265 1895 4265
Connection ~ 1995 4265
Wire Wire Line
	1995 4115 1995 4265
Wire Wire Line
	1895 4265 1795 4265
Connection ~ 1895 4265
Wire Wire Line
	1895 4115 1895 4265
Wire Wire Line
	1795 4265 1795 4115
$Comp
L Device:R R13
U 1 1 5E0511A2
P 2095 3965
F 0 "R13" V 2045 3799 31  0000 C CNN
F 1 "R10k" V 2103 3965 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2025 3965 50  0001 C CNN
F 3 "~" H 2095 3965 50  0001 C CNN
	1    2095 3965
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5E040179
P 1995 3965
F 0 "R12" V 1945 3799 31  0000 C CNN
F 1 "R10k" V 2003 3965 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1925 3965 50  0001 C CNN
F 3 "~" H 1995 3965 50  0001 C CNN
	1    1995 3965
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 5E02F0E7
P 1895 3965
F 0 "R11" V 1845 3799 31  0000 C CNN
F 1 "R10k" V 1903 3965 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1825 3965 50  0001 C CNN
F 3 "~" H 1895 3965 50  0001 C CNN
	1    1895 3965
	1    0    0    -1  
$EndComp
Wire Wire Line
	2095 3315 2095 3815
Wire Wire Line
	1745 3315 2095 3315
Wire Wire Line
	1895 2615 1895 3815
Wire Wire Line
	1795 2265 1795 3815
Wire Wire Line
	1745 2265 1795 2265
Wire Wire Line
	1345 2265 1095 2265
Wire Wire Line
	1345 2615 1095 2615
Wire Wire Line
	1345 2965 1095 2965
Wire Wire Line
	1095 3315 1345 3315
Wire Wire Line
	1745 2615 1895 2615
Wire Wire Line
	1745 2965 1995 2965
$Comp
L Switch:SW_Push SW4
U 1 1 5E159C32
P 1545 3315
F 0 "SW4" H 1545 3600 50  0000 C CNN
F 1 "SW_Push" H 1545 3509 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 1545 3515 50  0001 C CNN
F 3 "~" H 1545 3515 50  0001 C CNN
	1    1545 3315
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5E159C2C
P 1545 2965
F 0 "SW3" H 1545 3250 50  0000 C CNN
F 1 "SW_Push" H 1545 3159 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 1545 3165 50  0001 C CNN
F 3 "~" H 1545 3165 50  0001 C CNN
	1    1545 2965
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5E14C4A5
P 1545 2615
F 0 "SW2" H 1545 2900 50  0000 C CNN
F 1 "SW_Push" H 1545 2809 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 1545 2815 50  0001 C CNN
F 3 "~" H 1545 2815 50  0001 C CNN
	1    1545 2615
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5E13E6DF
P 1545 2265
F 0 "SW1" H 1545 2550 50  0000 C CNN
F 1 "SW_Push" H 1545 2459 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 1545 2465 50  0001 C CNN
F 3 "~" H 1545 2465 50  0001 C CNN
	1    1545 2265
	1    0    0    -1  
$EndComp
Text GLabel 4895 6115 2    50   Input ~ 0
OE47
Wire Wire Line
	4570 6115 4895 6115
Wire Wire Line
	4570 6045 4570 6115
Text GLabel 4905 4415 2    50   Input ~ 0
OE45
Wire Wire Line
	4570 4415 4905 4415
Wire Wire Line
	4570 4325 4570 4415
Wire Wire Line
	3450 6165 4770 6165
Wire Wire Line
	3450 4480 4770 4480
Connection ~ 5945 2130
Wire Wire Line
	6395 2130 5945 2130
Wire Wire Line
	6395 4365 6395 2130
Wire Wire Line
	5945 4365 6395 4365
Wire Wire Line
	5945 4795 5945 4365
Connection ~ 5855 2230
Wire Wire Line
	5855 4315 6345 4315
Wire Wire Line
	6345 2230 5855 2230
Wire Wire Line
	6345 4315 6345 2230
Wire Wire Line
	5855 4795 5855 4315
Connection ~ 5755 2330
Wire Wire Line
	6295 2330 5755 2330
Wire Wire Line
	6295 4265 6295 2330
Wire Wire Line
	5755 4265 6295 4265
Wire Wire Line
	5755 4795 5755 4265
Wire Wire Line
	5655 2430 6245 2430
Connection ~ 5655 2430
Wire Wire Line
	5140 2430 5655 2430
Wire Wire Line
	6245 4215 6245 2430
Wire Wire Line
	5655 4215 6245 4215
Wire Wire Line
	5655 4795 5655 4215
Connection ~ 5555 2530
Wire Wire Line
	6195 2530 5555 2530
Wire Wire Line
	6195 4165 6195 2530
Wire Wire Line
	5555 4165 6195 4165
Wire Wire Line
	5555 4795 5555 4165
Connection ~ 5455 2630
Wire Wire Line
	6145 2630 5455 2630
Wire Wire Line
	6145 4115 6145 2630
Wire Wire Line
	5455 4115 6145 4115
Wire Wire Line
	5455 4795 5455 4115
Connection ~ 5355 2730
Wire Wire Line
	6095 2730 5355 2730
Wire Wire Line
	6095 4065 6095 2730
Wire Wire Line
	5355 4065 6095 4065
Wire Wire Line
	5355 4795 5355 4065
Connection ~ 5255 2830
Wire Wire Line
	6045 2830 5255 2830
Wire Wire Line
	6045 4015 6045 2830
Wire Wire Line
	5255 4015 6045 4015
Wire Wire Line
	5255 4795 5255 4015
Wire Wire Line
	5095 5645 5070 5645
Wire Wire Line
	5095 5545 5070 5545
Wire Wire Line
	5070 5445 5095 5445
Wire Wire Line
	5070 5345 5095 5345
Wire Wire Line
	5095 5245 5070 5245
Wire Wire Line
	5070 5145 5095 5145
Wire Wire Line
	5095 5045 5070 5045
Wire Wire Line
	5070 4945 5095 4945
Connection ~ 4570 4620
Wire Wire Line
	4245 4620 4570 4620
Wire Wire Line
	4245 2920 4245 4620
Wire Wire Line
	4570 2920 4245 2920
Wire Wire Line
	3645 3825 4270 3825
Connection ~ 3645 3825
Wire Wire Line
	3645 5545 4270 5545
Wire Wire Line
	3645 3825 3645 5545
Wire Wire Line
	2750 3825 3645 3825
$Comp
L LEDMatrix-rescue:LED8x8Matrix-led8x8matrix U4
U 1 1 5E1DC39C
P 5595 5295
F 0 "U4" H 5512 5399 50  0000 L CNN
F 1 "LED8x8Matrix" H 5354 5308 50  0000 L CNN
F 2 "LEDMatrixFootprint:LEDMatrix8x8" H 5745 5085 50  0001 C CNN
F 3 "" H 5745 5085 50  0001 C CNN
	1    5595 5295
	1    0    0    -1  
$EndComp
Text Label 3850 3530 2    60   ~ 0
51(MOSI)
Wire Wire Line
	5140 2730 5355 2730
Wire Wire Line
	5140 2630 5455 2630
Connection ~ 3450 4480
Wire Wire Line
	4770 6165 4770 6045
Wire Wire Line
	3450 4480 3450 6165
Wire Wire Line
	4570 4620 4770 4620
Wire Wire Line
	4570 4620 4570 4745
Wire Wire Line
	4770 4620 4770 4745
$Comp
L LEDMatrix-rescue:74HC595-74hc595LED U2
U 1 1 5E188F0A
P 4670 5345
F 0 "U2" H 4329 5978 50  0000 C CNN
F 1 "74HC595" H 4329 5899 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 4670 5345 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4670 5345 50  0001 C CNN
	1    4670 5345
	1    0    0    -1  
$EndComp
Wire Wire Line
	4570 2920 4570 2030
Connection ~ 4570 2920
Wire Wire Line
	4770 2920 4570 2920
Wire Wire Line
	4770 3025 4770 2920
Wire Wire Line
	4270 3530 4270 3425
Wire Wire Line
	2750 3630 2750 3825
Wire Wire Line
	4570 3025 4570 2920
Wire Wire Line
	4770 4480 4770 4325
Wire Wire Line
	3450 3730 3450 4265
Wire Wire Line
	2950 3630 2750 3630
Wire Wire Line
	5255 2830 5255 3075
Wire Wire Line
	5140 2830 5255 2830
$Comp
L Device:R R8
U 1 1 5DFD6C82
P 4990 2830
F 0 "R8" V 4940 2677 31  0000 C CNN
F 1 "R100" V 4998 2830 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2830 50  0001 C CNN
F 3 "~" H 4990 2830 50  0001 C CNN
	1    4990 2830
	0    1    1    0   
$EndComp
Wire Wire Line
	5355 3075 5355 2730
Wire Wire Line
	5455 3075 5455 2630
Wire Wire Line
	5555 2530 5555 3075
Wire Wire Line
	5140 2530 5555 2530
Wire Wire Line
	5655 3075 5655 2430
Wire Wire Line
	5755 2330 5755 3075
Wire Wire Line
	5140 2330 5755 2330
Wire Wire Line
	5855 2230 5140 2230
Wire Wire Line
	5855 3075 5855 2230
Wire Wire Line
	5945 2130 5945 3075
Wire Wire Line
	5140 2130 5945 2130
$Comp
L Device:R R7
U 1 1 5DFA15C3
P 4990 2730
F 0 "R7" V 4940 2583 31  0000 C CNN
F 1 "R100" V 4998 2730 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2730 50  0001 C CNN
F 3 "~" H 4990 2730 50  0001 C CNN
	1    4990 2730
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5DF9C06C
P 4990 2630
F 0 "R6" V 4940 2480 31  0000 C CNN
F 1 "R100" V 4998 2630 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2630 50  0001 C CNN
F 3 "~" H 4990 2630 50  0001 C CNN
	1    4990 2630
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5DF96B98
P 4990 2530
F 0 "R5" V 4940 2382 31  0000 C CNN
F 1 "R100" V 4998 2530 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2530 50  0001 C CNN
F 3 "~" H 4990 2530 50  0001 C CNN
	1    4990 2530
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5DF9150E
P 4990 2430
F 0 "R4" V 4940 2283 31  0000 C CNN
F 1 "R100" V 4998 2430 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2430 50  0001 C CNN
F 3 "~" H 4990 2430 50  0001 C CNN
	1    4990 2430
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5DF8BD91
P 4990 2330
F 0 "R3" V 4940 2185 31  0000 C CNN
F 1 "R100" V 4998 2330 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2330 50  0001 C CNN
F 3 "~" H 4990 2330 50  0001 C CNN
	1    4990 2330
	0    1    1    0   
$EndComp
Wire Wire Line
	5070 3925 5095 3925
Wire Wire Line
	5070 3825 5095 3825
Wire Wire Line
	5070 3725 5095 3725
Wire Wire Line
	5070 3625 5095 3625
Wire Wire Line
	5070 3525 5095 3525
Wire Wire Line
	5070 3425 5095 3425
Wire Wire Line
	5070 3325 5095 3325
Wire Wire Line
	5070 3225 5095 3225
$Comp
L LEDMatrix-rescue:LED8x8Matrix-led8x8matrix U3
U 1 1 5DECADD9
P 5595 3575
F 0 "U3" H 5512 3679 50  0000 L CNN
F 1 "LED8x8Matrix" H 5354 3588 50  0000 L CNN
F 2 "LEDMatrixFootprint:LEDMatrix8x8" H 5745 3365 50  0001 C CNN
F 3 "" H 5745 3365 50  0001 C CNN
	1    5595 3575
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x18_Odd_Even P1
U 1 1 56D743B5
P 3150 2930
F 0 "P1" H 3150 3880 50  0000 C CNN
F 1 "Digital" V 3150 2930 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Socket_Strip_Arduino_2x18" H 3150 1880 50  0001 C CNN
F 3 "" H 3150 1880 50  0000 C CNN
	1    3150 2930
	1    0    0    1   
$EndComp
Wire Wire Line
	2950 3530 2750 3530
Text Label 3840 3630 2    60   ~ 0
53(SS1)
Text Label 3750 3230 2    60   ~ 0
45
Text Label 3750 3130 2    60   ~ 0
43
Text Label 3750 3030 2    60   ~ 0
41
Text Label 3750 2930 2    60   ~ 0
39
Text Label 3750 2830 2    60   ~ 0
37
Text Label 3750 2730 2    60   ~ 0
35
Text Label 3750 2630 2    60   ~ 0
33
Text Label 3750 2430 2    60   ~ 0
29
Text Label 3750 2530 2    60   ~ 0
31
Text Label 3750 2330 2    60   ~ 0
27
Text Label 3750 2230 2    60   ~ 0
25
Text Label 3750 2130 2    60   ~ 0
23
Text Label 3000 3520 2    60   ~ 0
50(MISO)
Text Label 2750 3430 2    60   ~ 0
48
Text Label 2750 3330 2    60   ~ 0
46
Text Label 2750 3230 2    60   ~ 0
44
Text Label 2750 3130 2    60   ~ 0
42
Text Label 2750 3030 2    60   ~ 0
40
Text Label 2750 2930 2    60   ~ 0
38
Text Label 2750 2730 2    60   ~ 0
34
Text Label 2750 2630 2    60   ~ 0
32
Text Label 2750 2530 2    60   ~ 0
30
Text Label 2750 2430 2    60   ~ 0
28
Text Label 2750 2330 2    60   ~ 0
26
Text Label 2750 2230 2    60   ~ 0
24
Text Label 2750 2130 2    60   ~ 0
22
$Comp
L Switch:SW_Push SW5
U 1 1 5E1667AF
P 1545 3665
F 0 "SW5" H 1545 3950 50  0000 C CNN
F 1 "SW_Push" H 1545 3859 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 1545 3865 50  0001 C CNN
F 3 "~" H 1545 3865 50  0001 C CNN
	1    1545 3665
	1    0    0    -1  
$EndComp
Wire Wire Line
	1095 3665 1345 3665
Connection ~ 1095 3315
Wire Wire Line
	1095 3315 1095 3665
Wire Wire Line
	1745 3665 2195 3665
$Comp
L Device:R R14
U 1 1 5E07364D
P 2195 3965
F 0 "R14" V 2145 3799 31  0000 C CNN
F 1 "R10k" V 2203 3965 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2125 3965 50  0001 C CNN
F 3 "~" H 2195 3965 50  0001 C CNN
	1    2195 3965
	1    0    0    -1  
$EndComp
Wire Wire Line
	2195 4265 2095 4265
Connection ~ 2195 4265
Wire Wire Line
	2195 4115 2195 4265
Wire Wire Line
	1795 2265 1795 2130
Connection ~ 1795 2265
Wire Wire Line
	1895 2230 1895 2615
Connection ~ 1895 2615
Wire Wire Line
	1995 2330 1995 2965
Connection ~ 1995 2965
Wire Wire Line
	1995 2965 1995 3815
Wire Wire Line
	2095 2430 2095 3315
Connection ~ 2095 3315
Wire Wire Line
	4780 2530 4840 2530
Wire Wire Line
	4780 2630 4840 2630
Wire Wire Line
	4780 2730 4840 2730
Wire Wire Line
	4780 2830 4840 2830
$Comp
L Device:R R1
U 1 1 5DF02DCD
P 4990 2130
F 0 "R1" V 4940 1988 31  0000 C CNN
F 1 "R100" V 4998 2130 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2130 50  0001 C CNN
F 3 "~" H 4990 2130 50  0001 C CNN
	1    4990 2130
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5DF86757
P 4990 2230
F 0 "R2" V 4940 2087 31  0000 C CNN
F 1 "R100" V 4998 2230 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4920 2230 50  0001 C CNN
F 3 "~" H 4990 2230 50  0001 C CNN
	1    4990 2230
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 5E01E05F
P 1795 3965
F 0 "R10" V 1745 3799 31  0000 C CNN
F 1 "R10k" V 1803 3965 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1725 3965 50  0001 C CNN
F 3 "~" H 1795 3965 50  0001 C CNN
	1    1795 3965
	1    0    0    -1  
$EndComp
Text Label 2750 2830 2    60   ~ 0
36
Wire Wire Line
	2555 2830 2950 2830
Wire Wire Line
	2555 2730 2950 2730
Wire Wire Line
	2555 2630 2950 2630
Wire Wire Line
	2555 2530 2950 2530
Wire Wire Line
	4780 2430 4840 2430
Wire Wire Line
	4840 2330 4780 2330
Wire Wire Line
	4780 2230 4840 2230
Wire Wire Line
	4840 2130 4780 2130
Text GLabel 4780 2830 0    50   Input ~ 0
Q8
Text GLabel 4780 2730 0    50   Input ~ 0
Q7
Text GLabel 4780 2630 0    50   Input ~ 0
Q6
Text GLabel 4780 2530 0    50   Input ~ 0
Q5
Text GLabel 4780 2430 0    50   Input ~ 0
Q4
Text GLabel 4780 2330 0    50   Input ~ 0
Q3
Text GLabel 4780 2230 0    50   Input ~ 0
Q2
Text GLabel 4780 2130 0    50   Input ~ 0
Q1
Text GLabel 3860 2330 2    50   Input ~ 0
Q6
Text GLabel 3860 2430 2    50   Input ~ 0
Q8
Text GLabel 2625 2130 0    50   Input ~ 0
Q1
Text GLabel 2625 2230 0    50   Input ~ 0
Q3
Text GLabel 2625 2330 0    50   Input ~ 0
Q5
Text GLabel 2625 2430 0    50   Input ~ 0
Q7
Wire Wire Line
	2555 2930 2950 2930
Wire Wire Line
	2555 3030 2950 3030
Wire Wire Line
	2555 3130 2950 3130
Wire Wire Line
	2555 3230 2950 3230
Wire Wire Line
	3750 3030 3450 3030
Text Label 2990 3625 2    60   ~ 0
52(SCK)
Wire Wire Line
	2195 3665 2195 3815
Wire Wire Line
	1795 2130 2245 2130
Text GLabel 2245 2130 2    50   Input ~ 0
IN1
Text GLabel 2245 2230 2    50   Input ~ 0
IN2
Wire Wire Line
	1895 2230 2245 2230
Wire Wire Line
	1995 2330 2245 2330
Wire Wire Line
	2095 2430 2245 2430
Text GLabel 2245 2330 2    50   Input ~ 0
IN3
Text GLabel 2245 2430 2    50   Input ~ 0
IN4
Wire Wire Line
	2195 3665 2300 3665
Connection ~ 2195 3665
Text GLabel 2300 3665 2    50   Input ~ 0
IN5
Wire Wire Line
	3450 2230 3860 2230
Wire Wire Line
	3450 2330 3860 2330
Wire Wire Line
	3450 2430 3860 2430
Wire Wire Line
	3450 2530 3860 2530
Text GLabel 3860 2930 2    50   Input ~ 0
IN5
Wire Wire Line
	3450 2130 3860 2130
Wire Wire Line
	2950 3730 2950 4265
Wire Wire Line
	2950 4265 3450 4265
Connection ~ 2950 4265
Connection ~ 3450 4265
Wire Wire Line
	3450 4265 3450 4480
$Comp
L Device:Speaker LS1
U 1 1 5DEF4DE8
P 2805 4490
F 0 "LS1" H 2975 4486 50  0000 L CNN
F 1 "Speaker" H 2975 4395 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" H 2805 4290 50  0001 C CNN
F 3 "~" H 2795 4440 50  0001 C CNN
	1    2805 4490
	1    0    0    -1  
$EndComp
Text GLabel 3850 3330 2    50   Input ~ 0
SPK
Wire Wire Line
	2625 2130 2950 2130
Wire Wire Line
	2950 4265 2195 4265
Wire Wire Line
	2195 4265 2195 4590
Wire Wire Line
	2195 4590 2605 4590
Wire Wire Line
	2605 4490 2550 4490
Text GLabel 2550 4490 0    50   Input ~ 0
SPK
Text GLabel 3860 2130 2    50   Input ~ 0
Q2
Text GLabel 3860 2230 2    50   Input ~ 0
Q4
Wire Wire Line
	2625 2230 2950 2230
Wire Wire Line
	2625 2330 2950 2330
Wire Wire Line
	2625 2430 2950 2430
Text GLabel 3860 2730 2    50   Input ~ 0
IN2
Text GLabel 3860 2630 2    50   Input ~ 0
IN3
Text GLabel 3860 2530 2    50   Input ~ 0
IN4
Text GLabel 3860 2830 2    50   Input ~ 0
IN1
Wire Wire Line
	1095 2030 2950 2030
Wire Wire Line
	3450 2030 3450 1850
Wire Wire Line
	3450 1850 2950 1850
Wire Wire Line
	2950 1850 2950 2030
Connection ~ 3450 2030
Connection ~ 2950 2030
Wire Wire Line
	3450 2630 3860 2630
Wire Wire Line
	3450 2730 3860 2730
Wire Wire Line
	3450 2830 3860 2830
Wire Wire Line
	4270 5350 4050 5350
Text GLabel 4050 5350 0    50   Input ~ 0
SS2
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5DF2FD67
P 2030 5435
F 0 "J1" H 2110 5427 50  0000 L CNN
F 1 "Conn_01x02" H 2110 5336 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2030 5435 50  0001 C CNN
F 3 "~" H 2030 5435 50  0001 C CNN
	1    2030 5435
	1    0    0    -1  
$EndComp
Text GLabel 2555 3230 0    50   Input ~ 0
OE45
Text GLabel 2555 3130 0    50   Input ~ 0
OE47
Text GLabel 2555 3330 0    50   Input ~ 0
SS2
Wire Wire Line
	2555 3330 2950 3330
Wire Wire Line
	2555 3430 2950 3430
Wire Wire Line
	3450 2930 3860 2930
Text Label 3750 3420 2    60   ~ 0
49
Wire Wire Line
	3450 3630 3840 3630
Text Label 3750 3330 2    60   ~ 0
47
Wire Wire Line
	3450 3330 3850 3330
Wire Wire Line
	3450 2030 4570 2030
Wire Wire Line
	3450 3130 3750 3130
Wire Wire Line
	3750 3230 3450 3230
Wire Wire Line
	3450 3430 3750 3430
Wire Wire Line
	4270 3630 4200 3630
Text GLabel 2555 3430 0    50   Input ~ 0
SS1
Text GLabel 4200 3630 0    50   Input ~ 0
SS1
Wire Wire Line
	3450 3530 3950 3530
Wire Wire Line
	3950 3530 3950 5145
Wire Wire Line
	3950 5145 4270 5145
Connection ~ 3950 3530
Wire Wire Line
	3950 3530 4270 3530
$EndSCHEMATC
