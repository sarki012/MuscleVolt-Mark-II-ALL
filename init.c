/*
 * File:   init.c
 * Author: Erik Sarkinen
 *
 * Created on Dec. 24, 2020 10:42am
 */

#include <xc.h>
#include <stdio.h>
#include <p33fj12mc202.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void init(void)
{
    int m = 0, n = 0;
   // OSCCON=0b11101111;  //Clock frequency with 4X PLL = 16 Mhz
    RPINR18 = 0b0000100100001000;   // /U1CTS = RP9 U1RX = RP8
    RPOR3 = 0b0000001100000100;     // U1TX = RP7, /U1RTS = RP6
    TRISBbits.TRISB6 = 0;       // /RTS output
    TRISBbits.TRISB7 = 0;       //TX
    TRISBbits.TRISB8 = 1;       //RX
    TRISBbits.TRISB9 = 1;       // /CTS input
    TRISBbits.TRISB10 = 0;      //Reset
    TRISBbits.TRISB11 = 0;      //SW Button
    TRISBbits.TRISB12 = 0;      //Wakeup
    TRISBbits.TRISB13 = 0;      //TX Indicate
    TRISBbits.TRISB2 = 0;       //EAN
    TRISBbits.TRISB3 = 0;       //P2_4
    TRISBbits.TRISB14 = 0;      //P2_0
   
    PORTBbits.RB6 = 0;      //Set RTS initially to 0
    
    //LATBbits.LATB12 = 1;        //wakeup
    LATBbits.LATB11 = 1;        //SW button
    LATBbits.LATB10 = 1;        //reset
    
    /*
    LATBbits.LATB10 = 1;        //reset (active low)
    for(n = 0; n < 100; n++);
    LATBbits.LATB10 = 0;
    for(n = 0; n < 100; n++);
    LATBbits.LATB10 = 1;        //Reset
     
     */
    //Set up Bluetooth  EEPROM programming   Normal
    LATBbits.LATB2 = 0;     //EAN  0           0
    LATBbits.LATB3 = 1;     //P2_4 1           1 
    LATBbits.LATB14 = 1;    //P2_0 0           1
    
     /*
    LATBbits.LATB10 = 1;        //reset (active low)
    for(n = 0; n < 100; n++);
    LATBbits.LATB10 = 0;
    for(n = 0; n < 100; n++);
    LATBbits.LATB10 = 1;        //Reset
     */ 
    
    
    U1MODEbits.UARTEN = 1;      //UART1 is enabled
    U1MODEbits.USIDL = 0;       //Continue module operation in Idle mode
    U1MODEbits.IREN = 0;        //IrDA encoder and decoder disabled
    U1MODEbits.RTSMD = 0;       //U1RTS pin in flow control mode
    U1MODEbits.UEN1 = 1;    
    U1MODEbits.UEN0 = 1;        //TX RX and BCLK pins are enabled and used, /CTS pin controlled by port latches *****DOUBLE CHECK
    U1MODEbits.WAKE = 1;
    U1MODEbits.LPBACK = 0;
    U1MODEbits.ABAUD = 0;
    U1MODEbits.URXINV = 0;      //Idle state is '0'
    U1MODEbits.BRGH = 1;        //High Speed
    U1MODEbits.PDSEL1 = 0;
    U1MODEbits.PDSEL0 = 0;      //8-bit data, no parity
    U1MODEbits.STSEL = 0;       //One stop bit
    
    U1STAbits.UTXISEL1 = 0;
    U1STAbits.UTXISEL0 = 1;     //Interrupt when the last character is shifted out of the Transmit Shift Register ****Double Check
    U1STAbits.UTXINV = 0;       //Idle State is 0
    U1STAbits.UTXBRK = 0;       //Sync Break transmission disabled or completed
    U1STAbits.UTXEN = 1;        //Transmit enabled
    U1STAbits.URXISEL1 = 0;
    U1STAbits.URXISEL0 = 0;     //Interrupt is set on when one char is in the buffer
    U1STAbits.ADDEN = 0;          //Address detect mode disabled
    U1STAbits.RIDLE = 0;        //Receiver is active
    U1STAbits.PERR = 0;         //Parity Error
    
    OSCCON = 0b0000000011000000;    //FRC 7.37 MHz
    U1BRG = 7;                      //BAUD RATE 115,200
    
    IEC0bits.U1TXIE = 0;        //No transmit interrupt (We poll TRMT)
  //  IEC0bits.U1RXIE = 1;        //UART receive interrupt enabled
   // IPC2bits.U1RXIP2 = 1;
   // IPC2bits.U1RXIP1 = 1;
   // IPC2bits.U1RXIP0 = 1;       //Highest priority
    
 //  TRISBbits.TRISB10 = 0;
    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 1;      //TX Indicate
    
    LATBbits.LATB11 = 1;        //SWButton High = Power On
    
    LATBbits.LATB12 = 1;        //Wakeup
 //   LATBbits.LATB10 = 1;
 //   LATBbits.LATB10 = 0;
//    for(m = 0; m < 100; m++);
  //  LATBbits.LATB10 = 1;
    
    
    //A -> D Setup
    AD1CON1bits.ADON = 1;   //ADC is Operating
    AD1CON1bits.ADSIDL = 0; //Continue operation in idle mode
    AD1CON1bits.AD12B = 0;  //10 bit
    AD1CON1bits.FORM0 = 0;
    AD1CON1bits.FORM1 = 0;  //Integer
    AD1CON1bits.SSRC0 = 1;
    AD1CON1bits.SSRC1 = 1;
    AD1CON1bits.SSRC2 = 1;  //Internal counter ends sampling and starts conversion (auto-convert)
    AD1CON1bits.ASAM = 1;   //Sampling begins immediately after last conversion
    AD1CON1bits.SAMP = 1;   //ADC sample enable bit
    
    AD1CON2bits.VCFG0 = 0;
    AD1CON2bits.VCFG1 = 0;
    AD1CON2bits.VCFG2 = 0;      //Voltage reference AVDD and AVSS
   // AD1CON2bits.CSCNA = 1;      //Scan inputs
    AD1CON2bits.CHPS0 = 0;
    AD1CON2bits.CHPS1 = 0;      //Converts CH0
    AD1CON2bits.BUFM = 1;       // Starts filling first half of buffer on first interrupt and the second half of buffer on next interrupt
    AD1CON2bits.SMPI0 = 1;
    AD1CON2bits.SMPI1 = 1;
    AD1CON2bits.SMPI2 = 1;
    AD1CON2bits.SMPI3 = 1;      //Interrupts at the completion of 16th conversion
    AD1CON2bits.ALTS = 0;       //Always uses channel input selects for sample A
    
    TRISAbits.TRISA0 = 1;       //Input
    AD1PCFGL = 0x0000;
    AD1CON3bits.ADRC = 1;       //ADC internal RC clock
    
    AD1CHS0bits.CH0SB0 = 0;
    AD1CHS0bits.CH0SB1 = 0;
    AD1CHS0bits.CH0SB2 = 0;
    AD1CHS0bits.CH0SB3 = 0;
    AD1CHS0bits.CH0SB4 = 0;
    
    AD1CHS0bits.CH0SA0 = 0;
    AD1CHS0bits.CH0SA1 = 0;
    AD1CHS0bits.CH0SA2 = 0;
    AD1CHS0bits.CH0SA3 = 0;
    AD1CHS0bits.CH0SA4 = 0;
    
    IEC0bits.AD1IE = 1;         //Interrupt request enabled
    IPC3bits.AD1IP0 = 0;
    IPC3bits.AD1IP1 = 1;
    IPC3bits.AD1IP2 = 1;        //Priority = 6   
    
    return;
}
