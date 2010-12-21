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

// automatically generated --- do not edit

#include "cpu/pic_registers.h"
#include "cpu/pic18f2550_registers.h"

#ifndef NULL
#define NULL 0
#endif

static PICRegisterAlias __null_aliases[] = { { NULL, 0 } };
static PICRegisterBit __null_bits[] = { { NULL, 0 } };

static PICRegisterAlias __UFRM_aliases[] = {
    { "UFRML" , UFRML    },
    { "UFRMH" , UFRMH    },

    { NULL, 0 }
};

static PICRegisterBit __UIR_bits[] = {
    { "URSTIF"  , UIR_URSTIF     },
    { "UERRIF"  , UIR_UERRIF     },
    { "ACTVIF"  , UIR_ACTVIF     },
    { "TRNIF"   , UIR_TRNIF      },
    { "IDLEIF"  , UIR_IDLEIF     },
    { "STALLIF" , UIR_STALLIF    },
    { "SOFIF"   , UIR_SOFIF      },

    { NULL, 0 }
};

static PICRegisterBit __UIE_bits[] = {
    { "URSTIF"  , UIE_URSTIF     },
    { "UERRIF"  , UIE_UERRIF     },
    { "ACTVIF"  , UIE_ACTVIF     },
    { "TRNIF"   , UIE_TRNIF      },
    { "IDLEIF"  , UIE_IDLEIF     },
    { "STALLIF" , UIE_STALLIF    },
    { "SOFIF"   , UIE_SOFIF      },

    { NULL, 0 }
};

static PICRegisterBit __UEIR_bits[] = {
    { "PIDEF"   , UEIR_PIDEF     },
    { "CRC5EF"  , UEIR_CRC5EF    },
    { "CRC16EF" , UEIR_CRC16EF   },
    { "DFN8EF"  , UEIR_DFN8EF    },
    { "BTOEF"   , UEIR_BTOEF     },
    { "BTSEF"   , UEIR_BTSEF     },

    { NULL, 0 }
};

static PICRegisterBit __UEIE_bits[] = {
    { "PIDEF"   , UEIE_PIDEF     },
    { "CRC5EF"  , UEIE_CRC5EF    },
    { "CRC16EF" , UEIE_CRC16EF   },
    { "DFN8EF"  , UEIE_DFN8EF    },
    { "BTOEF"   , UEIE_BTOEF     },
    { "BTSEF"   , UEIE_BTSEF     },

    { NULL, 0 }
};

static PICRegisterBit __USTAT_bits[] = {
    { "PPBI"    , USTAT_PPBI     },
    { "DIR"     , USTAT_DIR      },
    { "ENDP0"   , USTAT_ENDP0    },
    { "ENDP1"   , USTAT_ENDP1    },
    { "ENDP2"   , USTAT_ENDP2    },
    { "ENDP3"   , USTAT_ENDP3    },

    { NULL, 0 }
};

static PICRegisterBit __UCON_bits[] = {
    { "SUSPND"  , UCON_SUSPND    },
    { "RESUME"  , UCON_RESUME    },
    { "USBEN"   , UCON_USBEN     },
    { "PKTDIS"  , UCON_PKTDIS    },
    { "SE0"     , UCON_SE0       },
    { "PPBRST"  , UCON_PPBRST    },

    { NULL, 0 }
};

static PICRegisterBit __UCFG_bits[] = {
    { "PPB0"    , UCFG_PPB0      },
    { "PPB1"    , UCFG_PPB1      },
    { "FSEN"    , UCFG_FSEN      },
    { "UTRDIS"  , UCFG_UTRDIS    },
    { "UPUEN"   , UCFG_UPUEN     },
    { "UOEMON"  , UCFG_UOEMON    },
    { "UTEYE"   , UCFG_UTEYE     },

    { NULL, 0 }
};

static PICRegisterBit __UEP0_bits[] = {
    { "EPSTALL" , UEP0_EPSTALL   },
    { "EPINEN"  , UEP0_EPINEN    },
    { "EPOUTEN" , UEP0_EPOUTEN   },
    { "EPCONDIS", UEP0_EPCONDIS  },
    { "EPHSHK"  , UEP0_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP1_bits[] = {
    { "EPSTALL" , UEP1_EPSTALL   },
    { "EPINEN"  , UEP1_EPINEN    },
    { "EPOUTEN" , UEP1_EPOUTEN   },
    { "EPCONDIS", UEP1_EPCONDIS  },
    { "EPHSHK"  , UEP1_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP2_bits[] = {
    { "EPSTALL" , UEP2_EPSTALL   },
    { "EPINEN"  , UEP2_EPINEN    },
    { "EPOUTEN" , UEP2_EPOUTEN   },
    { "EPCONDIS", UEP2_EPCONDIS  },
    { "EPHSHK"  , UEP2_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP3_bits[] = {
    { "EPSTALL" , UEP3_EPSTALL   },
    { "EPINEN"  , UEP3_EPINEN    },
    { "EPOUTEN" , UEP3_EPOUTEN   },
    { "EPCONDIS", UEP3_EPCONDIS  },
    { "EPHSHK"  , UEP3_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP4_bits[] = {
    { "EPSTALL" , UEP4_EPSTALL   },
    { "EPINEN"  , UEP4_EPINEN    },
    { "EPOUTEN" , UEP4_EPOUTEN   },
    { "EPCONDIS", UEP4_EPCONDIS  },
    { "EPHSHK"  , UEP4_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP5_bits[] = {
    { "EPSTALL" , UEP5_EPSTALL   },
    { "EPINEN"  , UEP5_EPINEN    },
    { "EPOUTEN" , UEP5_EPOUTEN   },
    { "EPCONDIS", UEP5_EPCONDIS  },
    { "EPHSHK"  , UEP5_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP6_bits[] = {
    { "EPSTALL" , UEP6_EPSTALL   },
    { "EPINEN"  , UEP6_EPINEN    },
    { "EPOUTEN" , UEP6_EPOUTEN   },
    { "EPCONDIS", UEP6_EPCONDIS  },
    { "EPHSHK"  , UEP6_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP7_bits[] = {
    { "EPSTALL" , UEP7_EPSTALL   },
    { "EPINEN"  , UEP7_EPINEN    },
    { "EPOUTEN" , UEP7_EPOUTEN   },
    { "EPCONDIS", UEP7_EPCONDIS  },
    { "EPHSHK"  , UEP7_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP8_bits[] = {
    { "EPSTALL" , UEP8_EPSTALL   },
    { "EPINEN"  , UEP8_EPINEN    },
    { "EPOUTEN" , UEP8_EPOUTEN   },
    { "EPCONDIS", UEP8_EPCONDIS  },
    { "EPHSHK"  , UEP8_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP9_bits[] = {
    { "EPSTALL" , UEP9_EPSTALL   },
    { "EPINEN"  , UEP9_EPINEN    },
    { "EPOUTEN" , UEP9_EPOUTEN   },
    { "EPCONDIS", UEP9_EPCONDIS  },
    { "EPHSHK"  , UEP9_EPHSHK    },

    { NULL, 0 }
};

static PICRegisterBit __UEP10_bits[] = {
    { "EPSTALL" , UEP10_EPSTALL  },
    { "EPINEN"  , UEP10_EPINEN   },
    { "EPOUTEN" , UEP10_EPOUTEN  },
    { "EPCONDIS", UEP10_EPCONDIS },
    { "EPHSHK"  , UEP10_EPHSHK   },

    { NULL, 0 }
};

static PICRegisterBit __UEP11_bits[] = {
    { "EPSTALL" , UEP11_EPSTALL  },
    { "EPINEN"  , UEP11_EPINEN   },
    { "EPOUTEN" , UEP11_EPOUTEN  },
    { "EPCONDIS", UEP11_EPCONDIS },
    { "EPHSHK"  , UEP11_EPHSHK   },

    { NULL, 0 }
};

static PICRegisterBit __UEP12_bits[] = {
    { "EPSTALL" , UEP12_EPSTALL  },
    { "EPINEN"  , UEP12_EPINEN   },
    { "EPOUTEN" , UEP12_EPOUTEN  },
    { "EPCONDIS", UEP12_EPCONDIS },
    { "EPHSHK"  , UEP12_EPHSHK   },

    { NULL, 0 }
};

static PICRegisterBit __UEP13_bits[] = {
    { "EPSTALL" , UEP13_EPSTALL  },
    { "EPINEN"  , UEP13_EPINEN   },
    { "EPOUTEN" , UEP13_EPOUTEN  },
    { "EPCONDIS", UEP13_EPCONDIS },
    { "EPHSHK"  , UEP13_EPHSHK   },

    { NULL, 0 }
};

static PICRegisterBit __UEP14_bits[] = {
    { "EPSTALL" , UEP14_EPSTALL  },
    { "EPINEN"  , UEP14_EPINEN   },
    { "EPOUTEN" , UEP14_EPOUTEN  },
    { "EPCONDIS", UEP14_EPCONDIS },
    { "EPHSHK"  , UEP14_EPHSHK   },

    { NULL, 0 }
};

static PICRegisterBit __UEP15_bits[] = {
    { "EPSTALL" , UEP15_EPSTALL  },
    { "EPINEN"  , UEP15_EPINEN   },
    { "EPOUTEN" , UEP15_EPOUTEN  },
    { "EPCONDIS", UEP15_EPCONDIS },
    { "EPHSHK"  , UEP15_EPHSHK   },

    { NULL, 0 }
};

static PICRegisterBit __PORTA_bits[] = {
    { "RA0"     , PORTA_RA0      },
    { "RA1"     , PORTA_RA1      },
    { "RA2"     , PORTA_RA2      },
    { "RA3"     , PORTA_RA3      },
    { "RA4"     , PORTA_RA4      },
    { "RA5"     , PORTA_RA5      },
    { "RA6"     , PORTA_RA6      },

    { NULL, 0 }
};

static PICRegisterBit __PORTB_bits[] = {
    { "RB0"     , PORTB_RB0      },
    { "RB1"     , PORTB_RB1      },
    { "RB2"     , PORTB_RB2      },
    { "RB3"     , PORTB_RB3      },
    { "RB4"     , PORTB_RB4      },
    { "RB5"     , PORTB_RB5      },
    { "RB6"     , PORTB_RB6      },
    { "RB7"     , PORTB_RB7      },

    { NULL, 0 }
};

static PICRegisterBit __PORTC_bits[] = {
    { "RC0"     , PORTC_RC0      },
    { "RC1"     , PORTC_RC1      },
    { "RC2"     , PORTC_RC2      },
    { "RC4"     , PORTC_RC4      },
    { "RC5"     , PORTC_RC5      },
    { "RC6"     , PORTC_RC6      },
    { "RC7"     , PORTC_RC7      },

    { NULL, 0 }
};

static PICRegisterBit __PORTE_bits[] = {
    { "RE3"     , PORTE_RE3      },

    { NULL, 0 }
};

static PICRegisterBit __LATA_bits[] = {
    { "LATA0"   , LATA_LATA0     },
    { "LATA1"   , LATA_LATA1     },
    { "LATA2"   , LATA_LATA2     },
    { "LATA3"   , LATA_LATA3     },
    { "LATA4"   , LATA_LATA4     },
    { "LATA5"   , LATA_LATA5     },
    { "LATA6"   , LATA_LATA6     },

    { NULL, 0 }
};

static PICRegisterBit __LATB_bits[] = {
    { "LATB0"   , LATB_LATB0     },
    { "LATB1"   , LATB_LATB1     },
    { "LATB2"   , LATB_LATB2     },
    { "LATB3"   , LATB_LATB3     },
    { "LATB4"   , LATB_LATB4     },
    { "LATB5"   , LATB_LATB5     },
    { "LATB6"   , LATB_LATB6     },
    { "LATB7"   , LATB_LATB7     },

    { NULL, 0 }
};

static PICRegisterBit __LATC_bits[] = {
    { "LATC0"   , LATC_LATC0     },
    { "LATC1"   , LATC_LATC1     },
    { "LATC2"   , LATC_LATC2     },
    { "LATC6"   , LATC_LATC6     },
    { "LATC7"   , LATC_LATC7     },

    { NULL, 0 }
};

static PICRegisterBit __TRISA_bits[] = {
    { "TRISA0"  , TRISA_TRISA0   },
    { "TRISA1"  , TRISA_TRISA1   },
    { "TRISA2"  , TRISA_TRISA2   },
    { "TRISA3"  , TRISA_TRISA3   },
    { "TRISA4"  , TRISA_TRISA4   },
    { "TRISA5"  , TRISA_TRISA5   },
    { "TRISA6"  , TRISA_TRISA6   },

    { NULL, 0 }
};

static PICRegisterBit __TRISB_bits[] = {
    { "TRISB0"  , TRISB_TRISB0   },
    { "TRISB1"  , TRISB_TRISB1   },
    { "TRISB2"  , TRISB_TRISB2   },
    { "TRISB3"  , TRISB_TRISB3   },
    { "TRISB4"  , TRISB_TRISB4   },
    { "TRISB5"  , TRISB_TRISB5   },
    { "TRISB6"  , TRISB_TRISB6   },
    { "TRISB7"  , TRISB_TRISB7   },

    { NULL, 0 }
};

static PICRegisterBit __TRISC_bits[] = {
    { "TRISC0"  , TRISC_TRISC0   },
    { "TRISC1"  , TRISC_TRISC1   },
    { "TRISC2"  , TRISC_TRISC2   },
    { "TRISC6"  , TRISC_TRISC6   },
    { "TRISC7"  , TRISC_TRISC7   },

    { NULL, 0 }
};

static PICRegisterBit __OSCTUNE_bits[] = {
    { "TUN0"    , OSCTUNE_TUN0   },
    { "TUN1"    , OSCTUNE_TUN1   },
    { "TUN2"    , OSCTUNE_TUN2   },
    { "TUN3"    , OSCTUNE_TUN3   },
    { "TUN4"    , OSCTUNE_TUN4   },
    { "INTSRC"  , OSCTUNE_INTSRC },

    { NULL, 0 }
};

static PICRegisterBit __PIE1_bits[] = {
    { "TMR1IE"  , PIE1_TMR1IE    },
    { "TMR2IE"  , PIE1_TMR2IE    },
    { "CCP1IE"  , PIE1_CCP1IE    },
    { "SSPIE"   , PIE1_SSPIE     },
    { "TXIE"    , PIE1_TXIE      },
    { "RCIE"    , PIE1_RCIE      },
    { "ADIE"    , PIE1_ADIE      },

    { NULL, 0 }
};

static PICRegisterBit __PIR1_bits[] = {
    { "TMR1IF"  , PIR1_TMR1IF    },
    { "TMR2IF"  , PIR1_TMR2IF    },
    { "CCP1IF"  , PIR1_CCP1IF    },
    { "SSPIF"   , PIR1_SSPIF     },
    { "TXIF"    , PIR1_TXIF      },
    { "RCIF"    , PIR1_RCIF      },
    { "ADIF"    , PIR1_ADIF      },

    { NULL, 0 }
};

static PICRegisterBit __IPR1_bits[] = {
    { "TMR1IP"  , IPR1_TMR1IP    },
    { "TMR2IP"  , IPR1_TMR2IP    },
    { "CCP1IP"  , IPR1_CCP1IP    },
    { "SSPIP"   , IPR1_SSPIP     },
    { "TXIP"    , IPR1_TXIP      },
    { "RCIP"    , IPR1_RCIP      },
    { "ADIP"    , IPR1_ADIP      },

    { NULL, 0 }
};

static PICRegisterBit __PIE2_bits[] = {
    { "CCP2IE"  , PIE2_CCP2IE    },
    { "TMR3IE"  , PIE2_TMR3IE    },
    { "HLVDIE"  , PIE2_HLVDIE    },
    { "BCLIE"   , PIE2_BCLIE     },
    { "EEIE"    , PIE2_EEIE      },
    { "USBIE"   , PIE2_USBIE     },
    { "CMIE"    , PIE2_CMIE      },
    { "OSCFIE"  , PIE2_OSCFIE    },

    { NULL, 0 }
};

static PICRegisterBit __PIR2_bits[] = {
    { "CCP2IF"  , PIR2_CCP2IF    },
    { "TMR3IF"  , PIR2_TMR3IF    },
    { "HLVDIF"  , PIR2_HLVDIF    },
    { "BCLIF"   , PIR2_BCLIF     },
    { "EEIF"    , PIR2_EEIF      },
    { "USBIF"   , PIR2_USBIF     },
    { "CMIF"    , PIR2_CMIF      },
    { "OSCFIF"  , PIR2_OSCFIF    },

    { NULL, 0 }
};

static PICRegisterBit __IPR2_bits[] = {
    { "CCP2IP"  , IPR2_CCP2IP    },
    { "TMR3IP"  , IPR2_TMR3IP    },
    { "HLVDIP"  , IPR2_HLVDIP    },
    { "BCLIP"   , IPR2_BCLIP     },
    { "EEIP"    , IPR2_EEIP      },
    { "USBIP"   , IPR2_USBIP     },
    { "CMIP"    , IPR2_CMIP      },
    { "OSCFIP"  , IPR2_OSCFIP    },

    { NULL, 0 }
};

static PICRegisterBit __EECON1_bits[] = {
    { "RD"      , EECON1_RD      },
    { "WR"      , EECON1_WR      },
    { "WREN"    , EECON1_WREN    },
    { "WRERR"   , EECON1_WRERR   },
    { "FREE"    , EECON1_FREE    },
    { "CFGS"    , EECON1_CFGS    },
    { "EEPGD"   , EECON1_EEPGD   },

    { NULL, 0 }
};

static PICRegisterBit __RCSTA_bits[] = {
    { "RX9D"    , RCSTA_RX9D     },
    { "OERR"    , RCSTA_OERR     },
    { "FERR"    , RCSTA_FERR     },
    { "ADDEN"   , RCSTA_ADDEN    },
    { "CRNE"    , RCSTA_CRNE     },
    { "SREN"    , RCSTA_SREN     },
    { "RX9"     , RCSTA_RX9      },
    { "SPEN"    , RCSTA_SPEN     },

    { NULL, 0 }
};

static PICRegisterBit __TXSTA_bits[] = {
    { "TX9D"    , TXSTA_TX9D     },
    { "TRMT"    , TXSTA_TRMT     },
    { "BRGH"    , TXSTA_BRGH     },
    { "SENDB"   , TXSTA_SENDB    },
    { "SYNC"    , TXSTA_SYNC     },
    { "TXEN"    , TXSTA_TXEN     },
    { "TX9"     , TXSTA_TX9      },
    { "CSRC"    , TXSTA_CSRC     },

    { NULL, 0 }
};

static PICRegisterAlias __SPBRG_aliases[] = {
    { "SPBRGH", SPBRGH   },

    { NULL, 0 }
};

static PICRegisterBit __T3CON_bits[] = {
    { "TMR3ON"  , T3CON_TMR3ON   },
    { "TMR3CS"  , T3CON_TMR3CS   },
    { "T3SYNC"  , T3CON_T3SYNC   },
    { "T3CCP1"  , T3CON_T3CCP1   },
    { "T3CKPS0" , T3CON_T3CKPS0  },
    { "T3CKPS1" , T3CON_T3CKPS1  },
    { "T3CCP2"  , T3CON_T3CCP2   },
    { "RD16"    , T3CON_RD16     },

    { NULL, 0 }
};

static PICRegisterAlias __TMR3_aliases[] = {
    { "TMR3L" , TMR3L    },
    { "TMR3H" , TMR3H    },

    { NULL, 0 }
};

static PICRegisterBit __CMCON_bits[] = {
    { "CM0"     , CMCON_CM0      },
    { "CM1"     , CMCON_CM1      },
    { "CM2"     , CMCON_CM2      },
    { "CIS"     , CMCON_CIS      },
    { "C1INV"   , CMCON_C1INV    },
    { "C2INV"   , CMCON_C2INV    },
    { "C1OUT"   , CMCON_C1OUT    },
    { "C2OUT"   , CMCON_C2OUT    },

    { NULL, 0 }
};

static PICRegisterBit __CVRCON_bits[] = {
    { "CVR0"    , CVRCON_CVR0    },
    { "CVR1"    , CVRCON_CVR1    },
    { "CVR2"    , CVRCON_CVR2    },
    { "CVR3"    , CVRCON_CVR3    },
    { "CVRSS"   , CVRCON_CVRSS   },
    { "CVRR"    , CVRCON_CVRR    },
    { "CVROE"   , CVRCON_CVROE   },
    { "CVREN"   , CVRCON_CVREN   },

    { NULL, 0 }
};

static PICRegisterBit __ECCP1AS_bits[] = {
    { "PSSAC0"  , ECCP1AS_PSSAC0 },
    { "PSSAC1"  , ECCP1AS_PSSAC1 },
    { "ECCPAS0" , ECCP1AS_ECCPAS0 },
    { "ECCPAS1" , ECCP1AS_ECCPAS1 },
    { "ECCPAS2" , ECCP1AS_ECCPAS2 },
    { "ECCPAS3" , ECCP1AS_ECCPAS3 },

    { NULL, 0 }
};

static PICRegisterBit __ECCP1DEL_bits[] = {
    { "PRSEN"   , ECCP1DEL_PRSEN },

    { NULL, 0 }
};

static PICRegisterBit __BAUDCON_bits[] = {
    { "ABDEN"   , BAUDCON_ABDEN  },
    { "WUE"     , BAUDCON_WUE    },
    { "BRG16"   , BAUDCON_BRG16  },
    { "TXCKP"   , BAUDCON_TXCKP  },
    { "RXDTP"   , BAUDCON_RXDTP  },
    { "RCIDL"   , BAUDCON_RCIDL  },
    { "ABDOVF"  , BAUDCON_ABDOVF },

    { NULL, 0 }
};

static PICRegisterBit __CCP2CON_bits[] = {
    { "CCP2M0"  , CCP2CON_CCP2M0 },
    { "CCP2M1"  , CCP2CON_CCP2M1 },
    { "CCP2M2"  , CCP2CON_CCP2M2 },
    { "CCP2M3"  , CCP2CON_CCP2M3 },
    { "DC2B0"   , CCP2CON_DC2B0  },
    { "DC2B1"   , CCP2CON_DC2B1  },

    { NULL, 0 }
};

static PICRegisterAlias __CCPR2_aliases[] = {
    { "CCPR2L", CCPR2L   },
    { "CCPR2H", CCPR2H   },

    { NULL, 0 }
};

static PICRegisterBit __CCP1CON_bits[] = {
    { "CCP1M0"  , CCP1CON_CCP1M0 },
    { "CCP1M1"  , CCP1CON_CCP1M1 },
    { "CCP1M2"  , CCP1CON_CCP1M2 },
    { "CCP1M3"  , CCP1CON_CCP1M3 },
    { "DC1B0"   , CCP1CON_DC1B0  },
    { "DC1B1"   , CCP1CON_DC1B1  },

    { NULL, 0 }
};

static PICRegisterAlias __CCPR1_aliases[] = {
    { "CCPR1L", CCPR1L   },
    { "CCPR1H", CCPR1H   },

    { NULL, 0 }
};

static PICRegisterBit __ADCON2_bits[] = {
    { "ADCS0"   , ADCON2_ADCS0   },
    { "ADCS1"   , ADCON2_ADCS1   },
    { "ADCS2"   , ADCON2_ADCS2   },
    { "ACQT0"   , ADCON2_ACQT0   },
    { "ACQT1"   , ADCON2_ACQT1   },
    { "ACQT2"   , ADCON2_ACQT2   },
    { "ADFM"    , ADCON2_ADFM    },

    { NULL, 0 }
};

static PICRegisterBit __ADCON1_bits[] = {
    { "PCFG0"   , ADCON1_PCFG0   },
    { "PCFG1"   , ADCON1_PCFG1   },
    { "PCFG2"   , ADCON1_PCFG2   },
    { "PCFG3"   , ADCON1_PCFG3   },
    { "VCFG0"   , ADCON1_VCFG0   },
    { "VCFG1"   , ADCON1_VCFG1   },

    { NULL, 0 }
};

static PICRegisterBit __ADCON0_bits[] = {
    { "ADON"    , ADCON0_ADON    },
    { "GO"      , ADCON0_GO      },
    { "CHS0"    , ADCON0_CHS0    },
    { "CHS1"    , ADCON0_CHS1    },
    { "CHS2"    , ADCON0_CHS2    },
    { "CHS3"    , ADCON0_CHS3    },

    { NULL, 0 }
};

static PICRegisterAlias __ADRES_aliases[] = {
    { "ADRESL", ADRESL   },
    { "ADRESH", ADRESH   },

    { NULL, 0 }
};

static PICRegisterBit __SSPCON2_bits[] = {
    { "SEN"     , SSPCON2_SEN    },
    { "RSEN"    , SSPCON2_RSEN   },
    { "ADMSK1"  , SSPCON2_ADMSK1 },
    { "PEN"     , SSPCON2_PEN    },
    { "ADMSK2"  , SSPCON2_ADMSK2 },
    { "RCEN"    , SSPCON2_RCEN   },
    { "ADMSK3"  , SSPCON2_ADMSK3 },
    { "ACKEN"   , SSPCON2_ACKEN  },
    { "ADMSK4"  , SSPCON2_ADMSK4 },
    { "ACKDT"   , SSPCON2_ACKDT  },
    { "ADMSK5"  , SSPCON2_ADMSK5 },
    { "ACKSTAT" , SSPCON2_ACKSTAT },
    { "GCEN"    , SSPCON2_GCEN   },

    { NULL, 0 }
};

static PICRegisterBit __SSPCON1_bits[] = {
    { "SSPM0"   , SSPCON1_SSPM0  },
    { "SSPM1"   , SSPCON1_SSPM1  },
    { "SSPM2"   , SSPCON1_SSPM2  },
    { "SSPM3"   , SSPCON1_SSPM3  },
    { "CKP"     , SSPCON1_CKP    },
    { "SSPEN"   , SSPCON1_SSPEN  },
    { "SSPOV"   , SSPCON1_SSPOV  },
    { "WCOL"    , SSPCON1_WCOL   },

    { NULL, 0 }
};

static PICRegisterBit __SSPSTAT_bits[] = {
    { "BF"      , SSPSTAT_BF     },
    { "UA"      , SSPSTAT_UA     },
    { "R"       , SSPSTAT_R      },
    { "S"       , SSPSTAT_S      },
    { "P"       , SSPSTAT_P      },
    { "D"       , SSPSTAT_D      },
    { "CKE"     , SSPSTAT_CKE    },
    { "SMP"     , SSPSTAT_SMP    },

    { NULL, 0 }
};

static PICRegisterBit __T2CON_bits[] = {
    { "T2CKPS0" , T2CON_T2CKPS0  },
    { "T2CKPS1" , T2CON_T2CKPS1  },
    { "TMR2ON"  , T2CON_TMR2ON   },
    { "T2OUTPS0", T2CON_T2OUTPS0 },
    { "T2OUTPS1", T2CON_T2OUTPS1 },
    { "T2OUTPS2", T2CON_T2OUTPS2 },
    { "T2OUTPS3", T2CON_T2OUTPS3 },

    { NULL, 0 }
};

static PICRegisterBit __T1CON_bits[] = {
    { "TMR1ON"  , T1CON_TMR1ON   },
    { "TMR1CS"  , T1CON_TMR1CS   },
    { "T1SYNC"  , T1CON_T1SYNC   },
    { "T1OSCEN" , T1CON_T1OSCEN  },
    { "T1CKPS0" , T1CON_T1CKPS0  },
    { "T1CKPS1" , T1CON_T1CKPS1  },
    { "T1RUN"   , T1CON_T1RUN    },
    { "RD16"    , T1CON_RD16     },

    { NULL, 0 }
};

static PICRegisterAlias __TMR1_aliases[] = {
    { "TMR1L" , TMR1L    },
    { "TMR1H" , TMR1H    },

    { NULL, 0 }
};

static PICRegisterBit __RCON_bits[] = {
    { "BOR"     , RCON_BOR       },
    { "POR"     , RCON_POR       },
    { "PD"      , RCON_PD        },
    { "TO"      , RCON_TO        },
    { "RI"      , RCON_RI        },
    { "SBOREN"  , RCON_SBOREN    },
    { "IPEN"    , RCON_IPEN      },

    { NULL, 0 }
};

static PICRegisterBit __WDTCON_bits[] = {
    { "SWDTEN"  , WDTCON_SWDTEN  },

    { NULL, 0 }
};

static PICRegisterBit __HLVDCON_bits[] = {
    { "HLVDL0"  , HLVDCON_HLVDL0 },
    { "HLVDL1"  , HLVDCON_HLVDL1 },
    { "HLVDL2"  , HLVDCON_HLVDL2 },
    { "HLVDL3"  , HLVDCON_HLVDL3 },
    { "HLVDEN"  , HLVDCON_HLVDEN },
    { "IRVST"   , HLVDCON_IRVST  },
    { "VDIRMAG" , HLVDCON_VDIRMAG },

    { NULL, 0 }
};

static PICRegisterBit __OSCCON_bits[] = {
    { "SCS0"    , OSCCON_SCS0    },
    { "SCS1"    , OSCCON_SCS1    },
    { "IOFS"    , OSCCON_IOFS    },
    { "OSTS"    , OSCCON_OSTS    },
    { "IRCF0"   , OSCCON_IRCF0   },
    { "IRCF1"   , OSCCON_IRCF1   },
    { "IRCF2"   , OSCCON_IRCF2   },
    { "IDLEN"   , OSCCON_IDLEN   },

    { NULL, 0 }
};

static PICRegisterBit __T0CON_bits[] = {
    { "T0PS0"   , T0CON_T0PS0    },
    { "T0PS1"   , T0CON_T0PS1    },
    { "T0PS2"   , T0CON_T0PS2    },
    { "PSA"     , T0CON_PSA      },
    { "T0SE"    , T0CON_T0SE     },
    { "T0CS"    , T0CON_T0CS     },
    { "T08BIT"  , T0CON_T08BIT   },
    { "TMR0ON"  , T0CON_TMR0ON   },

    { NULL, 0 }
};

static PICRegisterAlias __TMR0_aliases[] = {
    { "TMR0L" , TMR0L    },
    { "TMR0H" , TMR0H    },

    { NULL, 0 }
};

static PICRegisterBit __STATUS_bits[] = {
    { "C"       , STATUS_C       },
    { "DC"      , STATUS_DC      },
    { "Z"       , STATUS_Z       },
    { "OV"      , STATUS_OV      },
    { "N"       , STATUS_N       },

    { NULL, 0 }
};

static PICRegisterAlias __FSR2_aliases[] = {
    { "FSR2L" , FSR2L    },
    { "FSR2H" , FSR2H    },

    { NULL, 0 }
};

static PICRegisterAlias __FSR1_aliases[] = {
    { "FSR1L" , FSR1L    },
    { "FSR1H" , FSR1H    },

    { NULL, 0 }
};

static PICRegisterAlias __FSR0_aliases[] = {
    { "FSR0L" , FSR0L    },
    { "FSR0H" , FSR0H    },

    { NULL, 0 }
};

static PICRegisterBit __INTCON3_bits[] = {
    { "INT1IF"  , INTCON3_INT1IF },
    { "INT2IF"  , INTCON3_INT2IF },
    { "INT1IE"  , INTCON3_INT1IE },
    { "INT2IE"  , INTCON3_INT2IE },
    { "INT1IP"  , INTCON3_INT1IP },
    { "INT2IP"  , INTCON3_INT2IP },

    { NULL, 0 }
};

static PICRegisterBit __INTCON2_bits[] = {
    { "RBIP"    , INTCON2_RBIP   },
    { "TMR0IP"  , INTCON2_TMR0IP },
    { "INTEDG2" , INTCON2_INTEDG2 },
    { "INTEDG1" , INTCON2_INTEDG1 },
    { "INTEDG0" , INTCON2_INTEDG0 },
    { "RBPU"    , INTCON2_RBPU   },

    { NULL, 0 }
};

static PICRegisterBit __INTCON_bits[] = {
    { "RBIF"    , INTCON_RBIF    },
    { "INT0IF"  , INTCON_INT0IF  },
    { "TMR0IF"  , INTCON_TMR0IF  },
    { "RBIE"    , INTCON_RBIE    },
    { "INT0IE"  , INTCON_INT0IE  },
    { "TMR0IE"  , INTCON_TMR0IE  },
    { "PEIE"    , INTCON_PEIE    },
    { "GIEL"    , INTCON_GIEL    },
    { "GIE"     , INTCON_GIE     },
    { "GIEH"    , INTCON_GIEH    },

    { NULL, 0 }
};

static PICRegisterAlias __PROD_aliases[] = {
    { "PRODL" , PRODL    },
    { "PRODH" , PRODH    },

    { NULL, 0 }
};

static PICRegisterAlias __TBLPTR_aliases[] = {
    { "TBLPTRL", TBLPTRL  },
    { "TBLPTRH", TBLPTRH  },
    { "TBLPTRU", TBLPTRU  },

    { NULL, 0 }
};

static PICRegisterAlias __PCL_aliases[] = {
    { "PCL"   , PCL      },
    { "PCLATH", PCLATH   },
    { "PCLATU", PCLATU   },

    { NULL, 0 }
};

static PICRegisterBit __STKPTR_bits[] = {
    { "SP0"     , STKPTR_SP0     },
    { "SP1"     , STKPTR_SP1     },
    { "SP2"     , STKPTR_SP2     },
    { "SP3"     , STKPTR_SP3     },
    { "SP4"     , STKPTR_SP4     },
    { "STKUNF"  , STKPTR_STKUNF  },
    { "STKFUL"  , STKPTR_STKFUL  },

    { NULL, 0 }
};

static PICRegisterAlias __TOS_aliases[] = {
    { "TOSL"  , TOSL     },
    { "TOSH"  , TOSH     },
    { "TOSU"  , TOSU     },

    { NULL, 0 }
};

PICRegister pic18f2550_register_file[] = {
    { "UFRM"      , UFRM      , 2, 0x000007FF, 0x000007FF, __null_bits    , __UFRM_aliases     },
    { "UIR"       , UIR       , 1, 0x0000007F, 0x0000007F, __UIR_bits     , __null_aliases     },
    { "UIE"       , UIE       , 1, 0x0000007F, 0x0000007F, __UIE_bits     , __null_aliases     },
    { "UEIR"      , UEIR      , 1, 0x0000009F, 0x0000009F, __UEIR_bits    , __null_aliases     },
    { "UEIE"      , UEIE      , 1, 0x0000009F, 0x0000009F, __UEIE_bits    , __null_aliases     },
    { "USTAT"     , USTAT     , 1, 0x0000007E, 0x0000007E, __USTAT_bits   , __null_aliases     },
    { "UCON"      , UCON      , 1, 0x0000007E, 0x0000007E, __UCON_bits    , __null_aliases     },
    { "UADDR"     , UADDR     , 1, 0x0000007F, 0x0000007F, __null_bits    , __null_aliases     },
    { "UCFG"      , UCFG      , 1, 0x000000DF, 0x000000DF, __UCFG_bits    , __null_aliases     },
    { "UEP0"      , UEP0      , 1, 0x0000001F, 0x0000001F, __UEP0_bits    , __null_aliases     },
    { "UEP1"      , UEP1      , 1, 0x0000001F, 0x0000001F, __UEP1_bits    , __null_aliases     },
    { "UEP2"      , UEP2      , 1, 0x0000001F, 0x0000001F, __UEP2_bits    , __null_aliases     },
    { "UEP3"      , UEP3      , 1, 0x0000001F, 0x0000001F, __UEP3_bits    , __null_aliases     },
    { "UEP4"      , UEP4      , 1, 0x0000001F, 0x0000001F, __UEP4_bits    , __null_aliases     },
    { "UEP5"      , UEP5      , 1, 0x0000001F, 0x0000001F, __UEP5_bits    , __null_aliases     },
    { "UEP6"      , UEP6      , 1, 0x0000001F, 0x0000001F, __UEP6_bits    , __null_aliases     },
    { "UEP7"      , UEP7      , 1, 0x0000001F, 0x0000001F, __UEP7_bits    , __null_aliases     },
    { "UEP8"      , UEP8      , 1, 0x0000001F, 0x0000001F, __UEP8_bits    , __null_aliases     },
    { "UEP9"      , UEP9      , 1, 0x0000001F, 0x0000001F, __UEP9_bits    , __null_aliases     },
    { "UEP10"     , UEP10     , 1, 0x0000001F, 0x0000001F, __UEP10_bits   , __null_aliases     },
    { "UEP11"     , UEP11     , 1, 0x0000001F, 0x0000001F, __UEP11_bits   , __null_aliases     },
    { "UEP12"     , UEP12     , 1, 0x0000001F, 0x0000001F, __UEP12_bits   , __null_aliases     },
    { "UEP13"     , UEP13     , 1, 0x0000001F, 0x0000001F, __UEP13_bits   , __null_aliases     },
    { "UEP14"     , UEP14     , 1, 0x0000001F, 0x0000001F, __UEP14_bits   , __null_aliases     },
    { "UEP15"     , UEP15     , 1, 0x0000001F, 0x0000001F, __UEP15_bits   , __null_aliases     },
    { "PORTA"     , PORTA     , 1, 0x0000007F, 0x0000007F, __PORTA_bits   , __null_aliases     },
    { "PORTB"     , PORTB     , 1, 0x000000FF, 0x000000FF, __PORTB_bits   , __null_aliases     },
    { "PORTC"     , PORTC     , 1, 0x000000F7, 0x000000F7, __PORTC_bits   , __null_aliases     },
    { "PORTE"     , PORTE     , 1, 0x00000008, 0x00000008, __PORTE_bits   , __null_aliases     },
    { "LATA"      , LATA      , 1, 0x0000007F, 0x0000007F, __LATA_bits    , __null_aliases     },
    { "LATB"      , LATB      , 1, 0x000000FF, 0x000000FF, __LATB_bits    , __null_aliases     },
    { "LATC"      , LATC      , 1, 0x000000C7, 0x000000C7, __LATC_bits    , __null_aliases     },
    { "TRISA"     , TRISA     , 1, 0x0000007F, 0x0000007F, __TRISA_bits   , __null_aliases     },
    { "TRISB"     , TRISB     , 1, 0x000000FF, 0x000000FF, __TRISB_bits   , __null_aliases     },
    { "TRISC"     , TRISC     , 1, 0x000000C7, 0x000000C7, __TRISC_bits   , __null_aliases     },
    { "OSCTUNE"   , OSCTUNE   , 1, 0x00000097, 0x00000097, __OSCTUNE_bits , __null_aliases     },
    { "PIE1"      , PIE1      , 1, 0x0000007F, 0x0000007F, __PIE1_bits    , __null_aliases     },
    { "PIR1"      , PIR1      , 1, 0x0000007F, 0x0000007F, __PIR1_bits    , __null_aliases     },
    { "IPR1"      , IPR1      , 1, 0x0000007F, 0x0000007F, __IPR1_bits    , __null_aliases     },
    { "PIE2"      , PIE2      , 1, 0x000000FF, 0x000000FF, __PIE2_bits    , __null_aliases     },
    { "PIR2"      , PIR2      , 1, 0x000000FF, 0x000000FF, __PIR2_bits    , __null_aliases     },
    { "IPR2"      , IPR2      , 1, 0x000000FF, 0x000000FF, __IPR2_bits    , __null_aliases     },
    { "EECON1"    , EECON1    , 1, 0x000000DF, 0x000000DF, __EECON1_bits  , __null_aliases     },
    { "EECON2"    , EECON2    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "EEDATA"    , EEDATA    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "EEADR"     , EEADR     , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "RCSTA"     , RCSTA     , 1, 0x000000FF, 0x000000FF, __RCSTA_bits   , __null_aliases     },
    { "TXSTA"     , TXSTA     , 1, 0x000000FF, 0x000000FF, __TXSTA_bits   , __null_aliases     },
    { "TXREG"     , TXREG     , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "RCREG"     , RCREG     , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "SPBRG"     , SPBRG     , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __SPBRG_aliases    },
    { "T3CON"     , T3CON     , 1, 0x000000FF, 0x000000FF, __T3CON_bits   , __null_aliases     },
    { "TMR3"      , TMR3      , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __TMR3_aliases     },
    { "CMCON"     , CMCON     , 1, 0x000000FF, 0x000000FF, __CMCON_bits   , __null_aliases     },
    { "CVRCON"    , CVRCON    , 1, 0x000000FF, 0x000000FF, __CVRCON_bits  , __null_aliases     },
    { "ECCP1AS"   , ECCP1AS   , 1, 0x000000FC, 0x000000FC, __ECCP1AS_bits , __null_aliases     },
    { "ECCP1DEL"  , ECCP1DEL  , 1, 0x00000080, 0x00000080, __ECCP1DEL_bits, __null_aliases     },
    { "BAUDCON"   , BAUDCON   , 1, 0x000000FB, 0x000000FB, __BAUDCON_bits , __null_aliases     },
    { "CCP2CON"   , CCP2CON   , 1, 0x0000003F, 0x0000003F, __CCP2CON_bits , __null_aliases     },
    { "CCPR2"     , CCPR2     , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __CCPR2_aliases    },
    { "CCP1CON"   , CCP1CON   , 1, 0x0000003F, 0x0000003F, __CCP1CON_bits , __null_aliases     },
    { "CCPR1"     , CCPR1     , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __CCPR1_aliases    },
    { "ADCON2"    , ADCON2    , 1, 0x000000BF, 0x000000BF, __ADCON2_bits  , __null_aliases     },
    { "ADCON1"    , ADCON1    , 1, 0x0000003F, 0x0000003F, __ADCON1_bits  , __null_aliases     },
    { "ADCON0"    , ADCON0    , 1, 0x0000003F, 0x0000003F, __ADCON0_bits  , __null_aliases     },
    { "ADRES"     , ADRES     , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __ADRES_aliases    },
    { "SSPCON2"   , SSPCON2   , 1, 0x000000FF, 0x000000FF, __SSPCON2_bits , __null_aliases     },
    { "SSPCON1"   , SSPCON1   , 1, 0x000000FF, 0x000000FF, __SSPCON1_bits , __null_aliases     },
    { "SSPSTAT"   , SSPSTAT   , 1, 0x000000FF, 0x000000FF, __SSPSTAT_bits , __null_aliases     },
    { "SSPADD"    , SSPADD    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "SSPBUF"    , SSPBUF    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "T2CON"     , T2CON     , 1, 0x0000007F, 0x0000007F, __T2CON_bits   , __null_aliases     },
    { "PR2"       , PR2       , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "TMR2"      , TMR2      , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "T1CON"     , T1CON     , 1, 0x000000FF, 0x000000FF, __T1CON_bits   , __null_aliases     },
    { "TMR1"      , TMR1      , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __TMR1_aliases     },
    { "RCON"      , RCON      , 1, 0x000000DF, 0x000000DF, __RCON_bits    , __null_aliases     },
    { "WDTCON"    , WDTCON    , 1, 0x00000001, 0x00000001, __WDTCON_bits  , __null_aliases     },
    { "HLVDCON"   , HLVDCON   , 1, 0x0000007F, 0x0000007F, __HLVDCON_bits , __null_aliases     },
    { "OSCCON"    , OSCCON    , 1, 0x000000FF, 0x000000FF, __OSCCON_bits  , __null_aliases     },
    { "T0CON"     , T0CON     , 1, 0x000000FF, 0x000000FF, __T0CON_bits   , __null_aliases     },
    { "TMR0"      , TMR0      , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __TMR0_aliases     },
    { "STATUS"    , STATUS    , 1, 0x0000001F, 0x0000001F, __STATUS_bits  , __null_aliases     },
    { "FSR2"      , FSR2      , 2, 0x00000FFF, 0x00000FFF, __null_bits    , __FSR2_aliases     },
    { "PLUSW2"    , PLUSW2    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "PREINC2"   , PREINC2   , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "POSTDEC2"  , POSTDEC2  , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "POSTINC2"  , POSTINC2  , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "INDF2"     , INDF2     , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "BSR"       , BSR       , 1, 0x0000000F, 0x0000000F, __null_bits    , __null_aliases     },
    { "FSR1"      , FSR1      , 2, 0x00000FFF, 0x00000FFF, __null_bits    , __FSR1_aliases     },
    { "PLUSW1"    , PLUSW1    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "PREINC1"   , PREINC1   , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "POSTDEC1"  , POSTDEC1  , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "POSTINC1"  , POSTINC1  , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "INDF1"     , INDF1     , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "WREG"      , WREG      , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "FSR0"      , FSR0      , 2, 0x00000FFF, 0x00000FFF, __null_bits    , __FSR0_aliases     },
    { "PLUSW0"    , PLUSW0    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "PREINC0"   , PREINC0   , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "POSTDEC0"  , POSTDEC0  , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "POSTINC0"  , POSTINC0  , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "INDF0"     , INDF0     , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "INTCON3"   , INTCON3   , 1, 0x000000DB, 0x000000DB, __INTCON3_bits , __null_aliases     },
    { "INTCON2"   , INTCON2   , 1, 0x000000F5, 0x000000F5, __INTCON2_bits , __null_aliases     },
    { "INTCON"    , INTCON    , 1, 0x000000FF, 0x000000FF, __INTCON_bits  , __null_aliases     },
    { "PROD"      , PROD      , 2, 0x0000FFFF, 0x0000FFFF, __null_bits    , __PROD_aliases     },
    { "TABLAT"    , TABLAT    , 1, 0x000000FF, 0x000000FF, __null_bits    , __null_aliases     },
    { "TBLPTR"    , TBLPTR    , 3, 0x000003FF, 0x000003FF, __null_bits    , __TBLPTR_aliases   },
    { "PCL"       , PCL       , 3, 0x001FFFFF, 0x001FFFFF, __null_bits    , __PCL_aliases      },
    { "STKPTR"    , STKPTR    , 1, 0x000000DF, 0x000000DF, __STKPTR_bits  , __null_aliases     },
    { "TOS"       , TOS       , 3, 0x001FFFFF, 0x001FFFFF, __null_bits    , __TOS_aliases      },

    { NULL, 0, 0, 0, 0, NULL, NULL }
};

