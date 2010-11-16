/*
  Copyright (C) 2010, Nuno Subtil

  This file is part of Teppic.

  Teppic is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Teppic is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Teppic.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined (__PIC_REGISTER_FILE__)
#error multiple register file headers included
#else
#define __PIC_REGISTER_FILE__
#endif

// PIC18F2550 processor register definition file
// Generated from p18f2550.inc in the gputils package

// This header file defines configurations, registers, and other useful
// bits of information for the PIC18F2550 microcontroller.  These names
// are taken to match the data sheets as closely as possible.

#define __PIC18F2550__

// ==========================================================================
// 
//        Register Definitions
// 
// ==========================================================================

// ----- Register Files -----------------------------------------------------
#define UFRM              0x0F66
#define UFRML             0x0F66
#define UFRMH             0x0F67
#define UIR               0x0F68
#define UIE               0x0F69
#define UEIR              0x0F6A
#define UEIE              0x0F6B
#define USTAT             0x0F6C
#define UCON              0x0F6D
#define UADDR             0x0F6E
#define UCFG              0x0F6F
#define UEP0              0x0F70
#define UEP1              0x0F71
#define UEP2              0x0F72
#define UEP3              0x0F73
#define UEP4              0x0F74
#define UEP5              0x0F75
#define UEP6              0x0F76
#define UEP7              0x0F77
#define UEP8              0x0F78
#define UEP9              0x0F79
#define UEP10             0x0F7A
#define UEP11             0x0F7B
#define UEP12             0x0F7C
#define UEP13             0x0F7D
#define UEP14             0x0F7E
#define UEP15             0x0F7F
#define PORTA             0x0F80
#define PORTB             0x0F81
#define PORTC             0x0F82
#define PORTE             0x0F84
#define LATA              0x0F89
#define LATB              0x0F8A
#define LATC              0x0F8B
#define DDRA              0x0F92
#define TRISA             0x0F92
#define DDRB              0x0F93
#define TRISB             0x0F93
#define DDRC              0x0F94
#define TRISC             0x0F94
#define OSCTUNE           0x0F9B
#define PIE1              0x0F9D
#define PIR1              0x0F9E
#define IPR1              0x0F9F
#define PIE2              0x0FA0
#define PIR2              0x0FA1
#define IPR2              0x0FA2
#define EECON1            0x0FA6
#define EECON2            0x0FA7
#define EEDATA            0x0FA8
#define EEADR             0x0FA9
#define RCSTA             0x0FAB
#define TXSTA             0x0FAC
#define TXREG             0x0FAD
#define RCREG             0x0FAE
#define SPBRG             0x0FAF
#define SPBRGH            0x0FB0
#define T3CON             0x0FB1
#define TMR3L             0x0FB2
#define TMR3H             0x0FB3
#define CMCON             0x0FB4
#define CVRCON            0x0FB5
#define CCP1AS            0x0FB6
#define ECCP1AS           0x0FB6
#define CCP1DEL           0x0FB7
#define ECCP1DEL          0x0FB7
#define BAUDCON           0x0FB8
#define CCP2CON           0x0FBA
#define CCPR2             0x0FBB
#define CCPR2L            0x0FBB
#define CCPR2H            0x0FBC
#define CCP1CON           0x0FBD
#define CCPR1             0x0FBE
#define CCPR1L            0x0FBE
#define CCPR1H            0x0FBF
#define ADCON2            0x0FC0
#define ADCON1            0x0FC1
#define ADCON0            0x0FC2
#define ADRES             0x0FC3
#define ADRESL            0x0FC3
#define ADRESH            0x0FC4
#define SSPCON2           0x0FC5
#define SSPCON1           0x0FC6
#define SSPSTAT           0x0FC7
#define SSPADD            0x0FC8
#define SSPBUF            0x0FC9
#define T2CON             0x0FCA
#define PR2               0x0FCB
#define TMR2              0x0FCC
#define T1CON             0x0FCD
#define TMR1L             0x0FCE
#define TMR1H             0x0FCF
#define RCON              0x0FD0
#define WDTCON            0x0FD1
#define HLVDCON           0x0FD2
#define LVDCON            0x0FD2
#define OSCCON            0x0FD3
#define T0CON             0x0FD5
#define TMR0L             0x0FD6
#define TMR0H             0x0FD7
#define STATUS            0x0FD8
#define FSR2L             0x0FD9
#define FSR2H             0x0FDA
#define PLUSW2            0x0FDB
#define PREINC2           0x0FDC
#define POSTDEC2          0x0FDD
#define POSTINC2          0x0FDE
#define INDF2             0x0FDF
#define BSR               0x0FE0
#define FSR1L             0x0FE1
#define FSR1H             0x0FE2
#define PLUSW1            0x0FE3
#define PREINC1           0x0FE4
#define POSTDEC1          0x0FE5
#define POSTINC1          0x0FE6
#define INDF1             0x0FE7
#define WREG              0x0FE8
#define FSR0L             0x0FE9
#define FSR0H             0x0FEA
#define PLUSW0            0x0FEB
#define PREINC0           0x0FEC
#define POSTDEC0          0x0FED
#define POSTINC0          0x0FEE
#define INDF0             0x0FEF
#define INTCON3           0x0FF0
#define INTCON2           0x0FF1
#define INTCON            0x0FF2
#define PROD              0x0FF3
#define PRODL             0x0FF3
#define PRODH             0x0FF4
#define TABLAT            0x0FF5
#define TBLPTR            0x0FF6
#define TBLPTRL           0x0FF6
#define TBLPTRH           0x0FF7
#define TBLPTRU           0x0FF8
//#define PC                0x0FF9
#define PCL               0x0FF9
#define PCLATH            0x0FFA
#define PCLATU            0x0FFB
#define STKPTR            0x0FFC
#define TOS               0x0FFD
#define TOSL              0x0FFD
#define TOSH              0x0FFE
#define TOSU              0x0FFF

// ----- UFRML Bits -----------------------------------------------------
#define FRM0              0x0000
#define FRM1              0x0001
#define FRM2              0x0002
#define FRM3              0x0003
#define FRM4              0x0004
#define FRM5              0x0005
#define FRM6              0x0006
#define FRM7              0x0007

// ----- UFRMH Bits -----------------------------------------------------
#define FRM8              0x0000
#define FRM9              0x0001
#define FRM10             0x0002

// ----- UIR Bits -----------------------------------------------------
#define URSTIF            0x0000
#define UERRIF            0x0001
#define ACTVIF            0x0002
#define TRNIF             0x0003
#define IDLEIF            0x0004
#define STALLIF           0x0005
#define SOFIF             0x0006

// ----- UIE Bits -----------------------------------------------------
#define URSTIE            0x0000
#define UERRIE            0x0001
#define ACTVIE            0x0002
#define TRNIE             0x0003
#define IDLEIE            0x0004
#define STALLIE           0x0005
#define SOFIE             0x0006

// ----- UEIR Bits -----------------------------------------------------
#define PIDEF             0x0000
#define CRC5EF            0x0001
#define CRC16EF           0x0002
#define DFN8EF            0x0003
#define BTOEF             0x0004
#define BTSEF             0x0007

// ----- UEIE Bits -----------------------------------------------------
#define PIDEE             0x0000
#define CRC5EE            0x0001
#define CRC16EE           0x0002
#define DFN8EE            0x0003
#define BTOEE             0x0004
#define BTSEE             0x0007

// ----- USTAT Bits -----------------------------------------------------
#define PPBI              0x0001
#define DIR               0x0002
#define ENDP0             0x0003
#define ENDP1             0x0004
#define ENDP2             0x0005
#define ENDP3             0x0006

// ----- UCON Bits -----------------------------------------------------
#define SUSPND            0x0001
#define RESUME            0x0002
#define USBEN             0x0003
#define PKTDIS            0x0004
#define SE0               0x0005
#define PPBRST            0x0006

// ----- UADDR Bits -----------------------------------------------------
#define ADDR0             0x0000
#define ADDR1             0x0001
#define ADDR2             0x0002
#define ADDR3             0x0003
#define ADDR4             0x0004
#define ADDR5             0x0005
#define ADDR6             0x0006

// ----- UCFG Bits -----------------------------------------------------
#define PPB0              0x0000
#define PPB1              0x0001
#define FSEN              0x0002
#define UTRDIS            0x0003
#define UPUEN             0x0004
#define UOEMON            0x0006
#define UTEYE             0x0007

// ----- UEP0 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP1 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP2 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP3 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP4 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP5 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP6 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP7 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP8 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP9 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP10 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP11 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP12 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP13 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP14 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- UEP15 Bits -----------------------------------------------------
#define EPSTALL           0x0000
#define EPINEN            0x0001
#define EPOUTEN           0x0002
#define EPCONDIS          0x0003
#define EPHSHK            0x0004

// ----- PORTA Bits -----------------------------------------------------
#define RA0               0x0000
#define RA1               0x0001
#define RA2               0x0002
#define RA3               0x0003
#define RA4               0x0004
#define RA5               0x0005
#define RA6               0x0006
#define AN0               0x0000
#define AN1               0x0001
#define AN2               0x0002
#define AN3               0x0003
#define T0CKI             0x0004
#define AN4               0x0005
#define OSC2              0x0006
#define VREFM             0x0002
#define VREFP             0x0003
#define LVDIN             0x0005
#define HLVDIN            0x0005

// ----- PORTB Bits -----------------------------------------------------
#define RB0               0x0000
#define RB1               0x0001
#define RB2               0x0002
#define RB3               0x0003
#define RB4               0x0004
#define RB5               0x0005
#define RB6               0x0006
#define RB7               0x0007
#define INT0              0x0000
#define INT1              0x0001
#define INT2              0x0002
#define PGM               0x0005
#define PGC               0x0006
#define PGD               0x0007

// ----- PORTC Bits -----------------------------------------------------
#define RC0               0x0000
#define RC1               0x0001
#define RC2               0x0002
#define RC4               0x0004
#define RC5               0x0005
#define RC6               0x0006
#define RC7               0x0007
#define T1OSO             0x0000
#define T1OSI             0x0001
#define CCP1              0x0002
#define TX                0x0006
#define RX                0x0007
#define T13CKI            0x0000
#define P1A               0x0002
#define CK                0x0006
#define DT                0x0007

// ----- PORTE Bits -----------------------------------------------------
#define RE3               0x0003

// ----- LATA Bits -----------------------------------------------------
#define LATA0             0x0000
#define LATA1             0x0001
#define LATA2             0x0002
#define LATA3             0x0003
#define LATA4             0x0004
#define LATA5             0x0005
#define LATA6             0x0006

// ----- LATB Bits -----------------------------------------------------
#define LATB0             0x0000
#define LATB1             0x0001
#define LATB2             0x0002
#define LATB3             0x0003
#define LATB4             0x0004
#define LATB5             0x0005
#define LATB6             0x0006
#define LATB7             0x0007

// ----- LATC Bits -----------------------------------------------------
#define LATC0             0x0000
#define LATC1             0x0001
#define LATC2             0x0002
#define LATC6             0x0006
#define LATC7             0x0007

// ----- DDRA Bits -----------------------------------------------------
#define RA0               0x0000
#define RA1               0x0001
#define RA2               0x0002
#define RA3               0x0003
#define RA4               0x0004
#define RA5               0x0005
#define RA6               0x0006

// ----- TRISA Bits -----------------------------------------------------
#define TRISA0            0x0000
#define TRISA1            0x0001
#define TRISA2            0x0002
#define TRISA3            0x0003
#define TRISA4            0x0004
#define TRISA5            0x0005
#define TRISA6            0x0006

// ----- DDRB Bits -----------------------------------------------------
#define RB0               0x0000
#define RB1               0x0001
#define RB2               0x0002
#define RB3               0x0003
#define RB4               0x0004
#define RB5               0x0005
#define RB6               0x0006
#define RB7               0x0007

// ----- TRISB Bits -----------------------------------------------------
#define TRISB0            0x0000
#define TRISB1            0x0001
#define TRISB2            0x0002
#define TRISB3            0x0003
#define TRISB4            0x0004
#define TRISB5            0x0005
#define TRISB6            0x0006
#define TRISB7            0x0007

// ----- DDRC Bits -----------------------------------------------------
#define RC0               0x0000
#define RC1               0x0001
#define RC2               0x0002
#define RC6               0x0006
#define RC7               0x0007

// ----- TRISC Bits -----------------------------------------------------
#define TRISC0            0x0000
#define TRISC1            0x0001
#define TRISC2            0x0002
#define TRISC6            0x0006
#define TRISC7            0x0007

// ----- OSCTUNE Bits -----------------------------------------------------
#define TUN0              0x0000
#define TUN1              0x0001
#define TUN2              0x0002
#define TUN3              0x0003
#define TUN4              0x0004
#define INTSRC            0x0007

// ----- PIE1 Bits -----------------------------------------------------
#define TMR1IE            0x0000
#define TMR2IE            0x0001
#define CCP1IE            0x0002
#define SSPIE             0x0003
#define TXIE              0x0004
#define RCIE              0x0005
#define ADIE              0x0006

// ----- PIR1 Bits -----------------------------------------------------
#define TMR1IF            0x0000
#define TMR2IF            0x0001
#define CCP1IF            0x0002
#define SSPIF             0x0003
#define TXIF              0x0004
#define RCIF              0x0005
#define ADIF              0x0006

// ----- IPR1 Bits -----------------------------------------------------
#define TMR1IP            0x0000
#define TMR2IP            0x0001
#define CCP1IP            0x0002
#define SSPIP             0x0003
#define TXIP              0x0004
#define RCIP              0x0005
#define ADIP              0x0006

// ----- PIE2 Bits -----------------------------------------------------
#define CCP2IE            0x0000
#define TMR3IE            0x0001
#define LVDIE             0x0002
#define BCLIE             0x0003
#define EEIE              0x0004
#define USBIE             0x0005
#define CMIE              0x0006
#define OSCFIE            0x0007
#define HLVDIE            0x0002

// ----- PIR2 Bits -----------------------------------------------------
#define CCP2IF            0x0000
#define TMR3IF            0x0001
#define LVDIF             0x0002
#define BCLIF             0x0003
#define EEIF              0x0004
#define USBIF             0x0005
#define CMIF              0x0006
#define OSCFIF            0x0007
#define HLVDIF            0x0002

// ----- IPR2 Bits -----------------------------------------------------
#define CCP2IP            0x0000
#define TMR3IP            0x0001
#define LVDIP             0x0002
#define BCLIP             0x0003
#define EEIP              0x0004
#define USBIP             0x0005
#define CMIP              0x0006
#define OSCFIP            0x0007
#define HLVDIP            0x0002

// ----- EECON1 Bits -----------------------------------------------------
#define RD                0x0000
#define WR                0x0001
#define WREN              0x0002
#define WRERR             0x0003
#define FREE              0x0004
#define CFGS              0x0006
#define EEPGD             0x0007

// ----- RCSTA Bits -----------------------------------------------------
#define RX9D              0x0000
#define OERR              0x0001
#define FERR              0x0002
#define ADDEN             0x0003
#define CREN              0x0004
#define SREN              0x0005
#define RX9               0x0006
#define SPEN              0x0007
#define ADEN              0x0003

// ----- TXSTA Bits -----------------------------------------------------
#define TX9D              0x0000
#define TRMT              0x0001
#define BRGH              0x0002
#define SENDB             0x0003
#define SYNC              0x0004
#define TXEN              0x0005
#define TX9               0x0006
#define CSRC              0x0007

// ----- T3CON Bits -----------------------------------------------------
#define TMR3ON            0x0000
#define TMR3CS            0x0001
#define T3SYNC            0x0002
#define T3CCP1            0x0003
#define T3CKPS0           0x0004
#define T3CKPS1           0x0005
#define T3CCP2            0x0006
#define RD16              0x0007
#define T3NSYNC           0x0002
#define NOT_T3SYNC        0x0002

// ----- CMCON Bits -----------------------------------------------------
#define CM0               0x0000
#define CM1               0x0001
#define CM2               0x0002
#define CIS               0x0003
#define C1INV             0x0004
#define C2INV             0x0005
#define C1OUT             0x0006
#define C2OUT             0x0007

// ----- CVRCON Bits -----------------------------------------------------
#define CVR0              0x0000
#define CVR1              0x0001
#define CVR2              0x0002
#define CVR3              0x0003
#define CVREF             0x0004
#define CVRR              0x0005
#define CVROE             0x0006
#define CVREN             0x0007
#define CVRSS             0x0004

// ----- CCP1AS Bits -----------------------------------------------------
#define PSSAC0            0x0002
#define PSSAC1            0x0003
#define ECCPAS0           0x0004
#define ECCPAS1           0x0005
#define ECCPAS2           0x0006
#define ECCPASE           0x0007

// ----- ECCP1AS Bits -----------------------------------------------------
#define PSSAC0            0x0002
#define PSSAC1            0x0003
#define ECCPAS0           0x0004
#define ECCPAS1           0x0005
#define ECCPAS2           0x0006
#define ECCPASE           0x0007

// ----- CCP1DEL Bits -----------------------------------------------------
#define PRSEN             0x0007

// ----- ECCP1DEL Bits -----------------------------------------------------
#define PRSEN             0x0007

// ----- BAUDCON Bits -----------------------------------------------------
#define ABDEN             0x0000
#define WUE               0x0001
#define BRG16             0x0003
#define SCKP              0x0004
#define RCIDL             0x0006
#define ABDOVF            0x0007
#define TXCKP             0x0004
#define RXDTP             0x0005
#define RCMT              0x0006

// ----- CCP2CON Bits -----------------------------------------------------
#define CCP2M0            0x0000
#define CCP2M1            0x0001
#define CCP2M2            0x0002
#define CCP2M3            0x0003
#define DC2B0             0x0004
#define DC2B1             0x0005

// ----- CCP1CON Bits -----------------------------------------------------
#define CCP1M0            0x0000
#define CCP1M1            0x0001
#define CCP1M2            0x0002
#define CCP1M3            0x0003
#define DC1B0             0x0004
#define DC1B1             0x0005

// ----- ADCON2 Bits -----------------------------------------------------
#define ADCS0             0x0000
#define ADCS1             0x0001
#define ADCS2             0x0002
#define ACQT0             0x0003
#define ACQT1             0x0004
#define ACQT2             0x0005
#define ADFM              0x0007

// ----- ADCON1 Bits -----------------------------------------------------
#define PCFG0             0x0000
#define PCFG1             0x0001
#define PCFG2             0x0002
#define PCFG3             0x0003
#define VCFG0             0x0004
#define VCFG1             0x0005

// ----- ADCON0 Bits -----------------------------------------------------
#define ADON              0x0000
#define GO_DONE           0x0001
#define CHS0              0x0002
#define CHS1              0x0003
#define CHS2              0x0004
#define CHS3              0x0005
#define DONE              0x0001
#define GO                0x0001
#define NOT_DONE          0x0001

// ----- SSPCON2 Bits -----------------------------------------------------
#define SEN               0x0000
#define RSEN              0x0001
#define PEN               0x0002
#define RCEN              0x0003
#define ACKEN             0x0004
#define ACKDT             0x0005
#define ACKSTAT           0x0006
#define GCEN              0x0007

// ----- SSPCON1 Bits -----------------------------------------------------
#define SSPM0             0x0000
#define SSPM1             0x0001
#define SSPM2             0x0002
#define SSPM3             0x0003
#define CKP               0x0004
#define SSPEN             0x0005
#define SSPOV             0x0006
#define WCOL              0x0007

// ----- SSPSTAT Bits -----------------------------------------------------
#define BF                0x0000
#define UA                0x0001
#define R_W               0x0002
#define S                 0x0003
#define P                 0x0004
#define D_A               0x0005
#define CKE               0x0006
#define SMP               0x0007
#define I2C_READ          0x0002
#define I2C_START         0x0003
#define I2C_STOP          0x0004
#define I2C_DAT           0x0005
#define NOT_W             0x0002
#define NOT_A             0x0005
#define NOT_WRITE         0x0002
#define NOT_ADDRESS       0x0005
#define READ_WRITE        0x0002
#define DATA_ADDRESS      0x0005
#define R                 0x0002
#define D                 0x0005

// ----- T2CON Bits -----------------------------------------------------
#define T2CKPS0           0x0000
#define T2CKPS1           0x0001
#define TMR2ON            0x0002
#define T2OUTPS0          0x0003
#define T2OUTPS1          0x0004
#define T2OUTPS2          0x0005
#define T2OUTPS3          0x0006

// ----- T1CON Bits -----------------------------------------------------
#define TMR1ON            0x0000
#define TMR1CS            0x0001
#define T1SYNC            0x0002
#define T1OSCEN           0x0003
#define T1CKPS0           0x0004
#define T1CKPS1           0x0005
#define T1RUN             0x0006
#define RD16              0x0007
#define NOT_T1SYNC        0x0002

// ----- RCON Bits -----------------------------------------------------
#define NOT_BOR           0x0000
#define NOT_POR           0x0001
#define NOT_PD            0x0002
#define NOT_TO            0x0003
#define NOT_RI            0x0004
#define SBOREN            0x0006
#define NOT_IPEN          0x0007
#define BOR               0x0000
#define POR               0x0001
#define PD                0x0002
#define TO                0x0003
#define RI                0x0004
#define IPEN              0x0007

// ----- WDTCON Bits -----------------------------------------------------
#define SWDTEN            0x0000
#define SWDTE             0x0000

// ----- HLVDCON Bits -----------------------------------------------------
#define LVDL0             0x0000
#define LVDL1             0x0001
#define LVDL2             0x0002
#define LVDL3             0x0003
#define LVDEN             0x0004
#define IRVST             0x0005
#define LVV0              0x0000
#define LVV1              0x0001
#define LVV2              0x0002
#define LVV3              0x0003
#define BGST              0x0005
#define HLVDL0            0x0000
#define HLVDL1            0x0001
#define HLVDL2            0x0002
#define HLVDL3            0x0003
#define HLVDEN            0x0004
#define VDIRMAG           0x0007
#define IVRST             0x0005

// ----- LVDCON Bits -----------------------------------------------------
#define LVDL0             0x0000
#define LVDL1             0x0001
#define LVDL2             0x0002
#define LVDL3             0x0003
#define LVDEN             0x0004
#define IRVST             0x0005
#define LVV0              0x0000
#define LVV1              0x0001
#define LVV2              0x0002
#define LVV3              0x0003
#define BGST              0x0005
#define HLVDL0            0x0000
#define HLVDL1            0x0001
#define HLVDL2            0x0002
#define HLVDL3            0x0003
#define HLVDEN            0x0004
#define VDIRMAG           0x0007
#define IVRST             0x0005

// ----- OSCCON Bits -----------------------------------------------------
#define SCS0              0x0000
#define SCS1              0x0001
#define IOFS              0x0002
#define OSTS              0x0003
#define IRCF0             0x0004
#define IRCF1             0x0005
#define IRCF2             0x0006
#define IDLEN             0x0007
#define FLTS              0x0002

// ----- T0CON Bits -----------------------------------------------------
#define T0PS0             0x0000
#define T0PS1             0x0001
#define T0PS2             0x0002
#define PSA               0x0003
#define T0SE              0x0004
#define T0CS              0x0005
#define T08BIT            0x0006
#define TMR0ON            0x0007

// ----- STATUS Bits -----------------------------------------------------
#define C                 0x0000
#define DC                0x0001
#define Z                 0x0002
#define OV                0x0003
#define N                 0x0004

// ----- INTCON3 Bits -----------------------------------------------------
#define INT1IF            0x0000
#define INT2IF            0x0001
#define INT1IE            0x0003
#define INT2IE            0x0004
#define INT1IP            0x0006
#define INT2IP            0x0007
#define INT1F             0x0000
#define INT2F             0x0001
#define INT1E             0x0003
#define INT2E             0x0004
#define INT1P             0x0006
#define INT2P             0x0007

// ----- INTCON2 Bits -----------------------------------------------------
#define RBIP              0x0000
#define TMR0IP            0x0002
#define INTEDG2           0x0004
#define INTEDG1           0x0005
#define INTEDG0           0x0006
#define NOT_RBPU          0x0007
#define T0IP              0x0002
#define RBPU              0x0007

// ----- INTCON Bits -----------------------------------------------------
#define RBIF              0x0000
#define INT0IF            0x0001
#define TMR0IF            0x0002
#define RBIE              0x0003
#define INT0IE            0x0004
#define TMR0IE            0x0005
#define PEIE              0x0006
#define GIE               0x0007
#define INT0F             0x0001
#define T0IF              0x0002
#define INT0E             0x0004
#define T0IE              0x0005
#define GIEL              0x0006
#define GIEH              0x0007

// ----- STKPTR Bits -----------------------------------------------------
#define STKPTR0           0x0000
#define STKPTR1           0x0001
#define STKPTR2           0x0002
#define STKPTR3           0x0003
#define STKPTR4           0x0004
#define STKUNF            0x0006
#define STKFUL            0x0007

// ==========================================================================
// 
//        RAM Definitions
// 
// ==========================================================================
// ==========================================================================
// 
//    IMPORTANT: For the PIC18 devices, the __CONFIG directive has been
//               superseded by the CONFIG directive.  The following settings
//               are available for this device.
// 
//    PLL Prescaler Selection bits:
//      PLLDIV = 1           No prescale (4 MHz oscillator input drives PLL directly)
//      PLLDIV = 2           Divide by 2 (8 MHz oscillator input)
//      PLLDIV = 3           Divide by 3 (12 MHz oscillator input)
//      PLLDIV = 4           Divide by 4 (16 MHz oscillator input)
//      PLLDIV = 5           Divide by 5 (20 MHz oscillator input)
//      PLLDIV = 6           Divide by 6 (24 MHz oscillator input)
//      PLLDIV = 10          Divide by 10 (40 MHz oscillator input)
//      PLLDIV = 12          Divide by 12 (48 MHz oscillator input)
// 
//    CPU System Clock Postscaler:
//      CPUDIV = OSC1_PLL2   [OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
//      CPUDIV = OSC2_PLL3   [OSC1/OSC2 Src: /2][96 MHz PLL Src: /3]
//      CPUDIV = OSC3_PLL4   [OSC1/OSC2 Src: /3][96 MHz PLL Src: /4]
//      CPUDIV = OSC4_PLL6   [OSC1/OSC2 Src: /4][96 MHz PLL Src: /6]
// 
//    USB Clock Selection bit (used in Full Speed USB mode only; UCFG:FSEN = 1):
//      USBDIV = 1           USB clock source comes directly from the primary oscillator block with no postscale
//      USBDIV = 2           USB clock source comes from the 96 MHz PLL divided by 2
// 
//    Oscillator Selection bits:
//      FOSC = XT_XT         XT oscillator, XT used by USB
//      FOSC = XTPLL_XT      XT oscillator, PLL enabled, XT used by USB
//      FOSC = ECIO_EC       External clock, port function on RA6, EC used by USB
//      FOSC = EC_EC         External clock, CLKOUT on RA6, EC used by USB
//      FOSC = ECPLLIO_EC    External clock, PLL enabled, port function on RA6, EC used by USB
//      FOSC = ECPLL_EC      External clock, PLL enabled, CLKOUT on RA6, EC used by USB
//      FOSC = INTOSCIO_EC   Internal oscillator, port function on RA6, EC used by USB
//      FOSC = INTOSC_EC     Internal oscillator, CLKOUT on RA6, EC used by USB
//      FOSC = INTOSC_XT     Internal oscillator, XT used by USB
//      FOSC = INTOSC_HS     Internal oscillator, HS used by USB
//      FOSC = HS            HS oscillator, HS used by USB
//      FOSC = HSPLL_HS      HS oscillator, PLL enabled, HS used by USB
// 
//    Fail-Safe Clock Monitor Enable bit:
//      FCMEN = OFF          Fail-Safe Clock Monitor disabled
//      FCMEN = ON           Fail-Safe Clock Monitor enabled
// 
//    Internal/External Oscillator Switchover bit:
//      IESO = OFF           Oscillator Switchover mode disabled
//      IESO = ON            Oscillator Switchover mode enabled
// 
//    Power-up Timer Enable bit:
//      PWRT = ON            PWRT enabled
//      PWRT = OFF           PWRT disabled
// 
//    Brown-out Reset Enable bits:
//      BOR = OFF            Brown-out Reset disabled in hardware and software
//      BOR = SOFT           Brown-out Reset enabled and controlled by software (SBOREN is enabled)
//      BOR = ON_ACTIVE      Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
//      BOR = ON             Brown-out Reset enabled in hardware only (SBOREN is disabled)
// 
//    Brown-out Voltage bits:
//      BORV = 0             Maximum setting
//      BORV = 1             
//      BORV = 2             
//      BORV = 3             Minimum setting
// 
//    USB Voltage Regulator Enable bit:
//      VREGEN = OFF         USB voltage regulator disabled
//      VREGEN = ON          USB voltage regulator enabled
// 
//    Watchdog Timer Enable bit:
//      WDT = OFF            HW Disabled - SW Controlled
//      WDT = ON             HW Enabled - SW Disabled
// 
//    Watchdog Timer Postscale Select bits:
//      WDTPS = 1            1:1
//      WDTPS = 2            1:2
//      WDTPS = 4            1:4
//      WDTPS = 8            1:8
//      WDTPS = 16           1:16
//      WDTPS = 32           1:32
//      WDTPS = 64           1:64
//      WDTPS = 128          1:128
//      WDTPS = 256          1:256
//      WDTPS = 512          1:512
//      WDTPS = 1024         1:1024
//      WDTPS = 2048         1:2048
//      WDTPS = 4096         1:4096
//      WDTPS = 8192         1:8192
//      WDTPS = 16384        1:16384
//      WDTPS = 32768        1:32768
// 
//    MCLR Pin Enable bit:
//      MCLRE = OFF          RE3 input pin enabled; MCLR disabled
//      MCLRE = ON           MCLR pin enabled; RE3 input pin disabled
// 
//    Low-Power Timer 1 Oscillator Enable bit:
//      LPT1OSC = OFF        Timer1 configured for higher power operation
//      LPT1OSC = ON         Timer1 configured for low-power operation
// 
//    PORTB A/D Enable bit:
//      PBADEN = OFF         PORTB<4:0> pins are configured as digital I/O on Reset
//      PBADEN = ON          PORTB<4:0> pins are configured as analog input channels on Reset
// 
//    CCP2 MUX bit:
//      CCP2MX = OFF         CCP2 input/output is multiplexed with RB3
//      CCP2MX = ON          CCP2 input/output is multiplexed with RC1
// 
//    Stack Full/Underflow Reset Enable bit:
//      STVREN = OFF         Stack full/underflow will not cause Reset
//      STVREN = ON          Stack full/underflow will cause Reset
// 
//    Single-Supply ICSP Enable bit:
//      LVP = OFF            Single-Supply ICSP disabled
//      LVP = ON             Single-Supply ICSP enabled
// 
//    Extended Instruction Set Enable bit:
//      XINST = OFF          Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
//      XINST = ON           Instruction set extension and Indexed Addressing mode enabled
// 
//    Background Debugger Enable bit:
//      DEBUG = ON           Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
//      DEBUG = OFF          Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
// 
//    Code Protection bit Block 0:
//      CP0 = ON             Block 0 (000800-001FFFh) code-protected
//      CP0 = OFF            Block 0 (000800-001FFFh) not code-protected
// 
//    Code Protection bit Block 1:
//      CP1 = ON             Block 1 (002000-003FFFh) code-protected
//      CP1 = OFF            Block 1 (002000-003FFFh) not code-protected
// 
//    Code Protection bit Block 2:
//      CP2 = ON             Block 2 (004000-005FFFh) code-protected
//      CP2 = OFF            Block 2 (004000-005FFFh) not code-protected
// 
//    Code Protection bit Block 3:
//      CP3 = ON             Block 3 (006000-007FFFh) code-protected
//      CP3 = OFF            Block 3 (006000-007FFFh) not code-protected
// 
//    Boot Block Code Protection bit:
//      CPB = ON             Boot block (000000-0007FFh) code-protected
//      CPB = OFF            Boot block (000000-0007FFh) not code-protected
// 
//    Data EEPROM Code Protection bit:
//      CPD = ON             Data EEPROM code-protected
//      CPD = OFF            Data EEPROM not code-protected
// 
//    Write Protection bit Block 0:
//      WRT0 = ON            Block 0 (000800-001FFFh) write-protected
//      WRT0 = OFF           Block 0 (000800-001FFFh) not write-protected
// 
//    Write Protection bit Block 1:
//      WRT1 = ON            Block 1 (002000-003FFFh) write-protected
//      WRT1 = OFF           Block 1 (002000-003FFFh) not write-protected
// 
//    Write Protection bit Block 2:
//      WRT2 = ON            Block 2 (004000-005FFFh) write-protected
//      WRT2 = OFF           Block 2 (004000-005FFFh) not write-protected
// 
//    Write Protection bit Block 3:
//      WRT3 = ON            Block 3 (006000-007FFFh) write-protected
//      WRT3 = OFF           Block 3 (006000-007FFFh) not write-protected
// 
//    Boot Block Write Protection bit:
//      WRTB = ON            Boot block (000000-0007FFh) write-protected
//      WRTB = OFF           Boot block (000000-0007FFh) not write-protected
// 
//    Configuration Register Write Protection bit:
//      WRTC = ON            Configuration registers (300000-3000FFh) write-protected
//      WRTC = OFF           Configuration registers (300000-3000FFh) not write-protected
// 
//    Data EEPROM Write Protection bit:
//      WRTD = ON            Data EEPROM write-protected
//      WRTD = OFF           Data EEPROM not write-protected
// 
//    Table Read Protection bit Block 0:
//      EBTR0 = ON           Block 0 (000800-001FFFh) protected from table reads executed in other blocks
//      EBTR0 = OFF          Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
// 
//    Table Read Protection bit Block 1:
//      EBTR1 = ON           Block 1 (002000-003FFFh) protected from table reads executed in other blocks
//      EBTR1 = OFF          Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
// 
//    Table Read Protection bit Block 2:
//      EBTR2 = ON           Block 2 (004000-005FFFh) protected from table reads executed in other blocks
//      EBTR2 = OFF          Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
// 
//    Table Read Protection bit Block 3:
//      EBTR3 = ON           Block 3 (006000-007FFFh) protected from table reads executed in other blocks
//      EBTR3 = OFF          Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
// 
//    Boot Block Table Read Protection:
//      EBTRB = ON           Boot block (000000-0007FFh) protected from table reads executed in other blocks
//      EBTRB = OFF          Boot block (000000-0007FFh) not protected from table reads executed in other blocks
// 
// ==========================================================================
// ==========================================================================
// 
//        Configuration Bits
// 
//    NAME            Address
//    CONFIG1L        300000h
//    CONFIG1H        300001h
//    CONFIG2L        300002h
//    CONFIG2H        300003h
//    CONFIG3H        300005h
//    CONFIG4L        300006h
//    CONFIG5L        300008h
//    CONFIG5H        300009h
//    CONFIG6L        30000Ah
//    CONFIG6H        30000Bh
//    CONFIG7L        30000Ch
//    CONFIG7H        30000Dh
// 
// ==========================================================================

//  The following is an assignment of address values for all of the
//  configuration registers for the purpose of table reads
#define _CONFIG1L         0x300000
#define _CONFIG1H         0x300001
#define _CONFIG2L         0x300002
#define _CONFIG2H         0x300003
#define _CONFIG3H         0x300005
#define _CONFIG4L         0x300006
#define _CONFIG5L         0x300008
#define _CONFIG5H         0x300009
#define _CONFIG6L         0x30000A
#define _CONFIG6H         0x30000B
#define _CONFIG7L         0x30000C
#define _CONFIG7H         0x30000D

// ----- CONFIG1L Options --------------------------------------------------
#define _PLLDIV_1_1L          0xF8
#define _PLLDIV_2_1L          0xF9
#define _PLLDIV_3_1L          0xFA
#define _PLLDIV_4_1L          0xFB
#define _PLLDIV_5_1L          0xFC
#define _PLLDIV_6_1L          0xFD
#define _PLLDIV_10_1L         0xFE
#define _PLLDIV_12_1L         0xFF
#define _CPUDIV_OSC1_PLL2_1L  0xE7
#define _CPUDIV_OSC2_PLL3_1L  0xEF
#define _CPUDIV_OSC3_PLL4_1L  0xF7
#define _CPUDIV_OSC4_PLL6_1L  0xFF
#define _USBDIV_1_1L          0xDF
#define _USBDIV_2_1L          0xFF

// ----- CONFIG1H Options --------------------------------------------------
#define _FOSC_XT_XT_1H        0xF0
#define _FOSC_XTPLL_XT_1H     0xF2
#define _FOSC_ECIO_EC_1H      0xF4
#define _FOSC_EC_EC_1H        0xF5
#define _FOSC_ECPLLIO_EC_1H   0xF6
#define _FOSC_ECPLL_EC_1H     0xF7
#define _FOSC_INTOSCIO_EC_1H  0xF8
#define _FOSC_INTOSC_EC_1H    0xF9
#define _FOSC_INTOSC_XT_1H    0xFA
#define _FOSC_INTOSC_HS_1H    0xFB
#define _FOSC_HS_1H           0xFC
#define _FOSC_HSPLL_HS_1H     0xFE
#define _FCMEN_OFF_1H         0xBF
#define _FCMEN_ON_1H          0xFF
#define _IESO_OFF_1H          0x7F
#define _IESO_ON_1H           0xFF

// ----- CONFIG2L Options --------------------------------------------------
#define _PWRT_ON_2L           0xFE
#define _PWRT_OFF_2L          0xFF
#define _BOR_OFF_2L           0xF9
#define _BOR_SOFT_2L          0xFB
#define _BOR_ON_ACTIVE_2L     0xFD
#define _BOR_ON_2L            0xFF
#define _BORV_0_2L            0xE7
#define _BORV_1_2L            0xEF
#define _BORV_2_2L            0xF7
#define _BORV_3_2L            0xFF
#define _VREGEN_OFF_2L        0xDF
#define _VREGEN_ON_2L         0xFF

// ----- CONFIG2H Options --------------------------------------------------
#define _WDT_OFF_2H           0xFE
#define _WDT_ON_2H            0xFF
#define _WDTPS_1_2H           0xE1
#define _WDTPS_2_2H           0xE3
#define _WDTPS_4_2H           0xE5
#define _WDTPS_8_2H           0xE7
#define _WDTPS_16_2H          0xE9
#define _WDTPS_32_2H          0xEB
#define _WDTPS_64_2H          0xED
#define _WDTPS_128_2H         0xEF
#define _WDTPS_256_2H         0xF1
#define _WDTPS_512_2H         0xF3
#define _WDTPS_1024_2H        0xF5
#define _WDTPS_2048_2H        0xF7
#define _WDTPS_4096_2H        0xF9
#define _WDTPS_8192_2H        0xFB
#define _WDTPS_16384_2H       0xFD
#define _WDTPS_32768_2H       0xFF

// ----- CONFIG3H Options --------------------------------------------------
#define _MCLRE_OFF_3H         0x7F
#define _MCLRE_ON_3H          0xFF
#define _LPT1OSC_OFF_3H       0xFB
#define _LPT1OSC_ON_3H        0xFF
#define _PBADEN_OFF_3H        0xFD
#define _PBADEN_ON_3H         0xFF
#define _CCP2MX_OFF_3H        0xFE
#define _CCP2MX_ON_3H         0xFF

// ----- CONFIG4L Options --------------------------------------------------
#define _STVREN_OFF_4L        0xFE
#define _STVREN_ON_4L         0xFF
#define _LVP_OFF_4L           0xFB
#define _LVP_ON_4L            0xFF
#define _XINST_OFF_4L         0xBF
#define _XINST_ON_4L          0xFF
#define _DEBUG_ON_4L          0x7F
#define _DEBUG_OFF_4L         0xFF

// ----- CONFIG5L Options --------------------------------------------------
#define _CP0_ON_5L            0xFE
#define _CP0_OFF_5L           0xFF
#define _CP1_ON_5L            0xFD
#define _CP1_OFF_5L           0xFF
#define _CP2_ON_5L            0xFB
#define _CP2_OFF_5L           0xFF
#define _CP3_ON_5L            0xF7
#define _CP3_OFF_5L           0xFF

// ----- CONFIG5H Options --------------------------------------------------
#define _CPB_ON_5H            0xBF
#define _CPB_OFF_5H           0xFF
#define _CPD_ON_5H            0x7F
#define _CPD_OFF_5H           0xFF

// ----- CONFIG6L Options --------------------------------------------------
#define _WRT0_ON_6L           0xFE
#define _WRT0_OFF_6L          0xFF
#define _WRT1_ON_6L           0xFD
#define _WRT1_OFF_6L          0xFF
#define _WRT2_ON_6L           0xFB
#define _WRT2_OFF_6L          0xFF
#define _WRT3_ON_6L           0xF7
#define _WRT3_OFF_6L          0xFF

// ----- CONFIG6H Options --------------------------------------------------
#define _WRTB_ON_6H           0xBF
#define _WRTB_OFF_6H          0xFF
#define _WRTC_ON_6H           0xDF
#define _WRTC_OFF_6H          0xFF
#define _WRTD_ON_6H           0x7F
#define _WRTD_OFF_6H          0xFF

// ----- CONFIG7L Options --------------------------------------------------
#define _EBTR0_ON_7L          0xFE
#define _EBTR0_OFF_7L         0xFF
#define _EBTR1_ON_7L          0xFD
#define _EBTR1_OFF_7L         0xFF
#define _EBTR2_ON_7L          0xFB
#define _EBTR2_OFF_7L         0xFF
#define _EBTR3_ON_7L          0xF7
#define _EBTR3_OFF_7L         0xFF

// ----- CONFIG7H Options --------------------------------------------------
#define _EBTRB_ON_7H          0xBF
#define _EBTRB_OFF_7H         0xFF
#define _DEVID1           0x3FFFFE
#define _DEVID2           0x3FFFFF
#define _IDLOC0           0x200000
#define _IDLOC1           0x200001
#define _IDLOC2           0x200002
#define _IDLOC3           0x200003
#define _IDLOC4           0x200004
#define _IDLOC5           0x200005
#define _IDLOC6           0x200006
#define _IDLOC7           0x200007
