/*
 * File:   main.c
 * Author: Erik
 *
 * Created on December 24, 2020, 10:36 AM
 */


// DSPIC33FJ12MC202 Configuration Bit Settings

// 'C' source line config statements

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Mode (Internal Fast RC (FRC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (Watchdog timer always enabled)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)
#pragma config LPOL = ON                // Motor Control PWM Low Side Polarity bit (PWM module low side output pins have active-high output polarity)
#pragma config HPOL = ON                // Motor Control PWM High Side Polarity bit (PWM module high side output pins have active-high output polarity)
#pragma config PWMPIN = ON              // Motor Control PWM Module Pin Mode bit (PWM module pins controlled by PORT register at device Reset)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

#include <xc.h>
#include <stdio.h>
#include <p33fj12mc202.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void init(void);
int i = 1, j = 0;
long int val0 = 0, val1 = 0, val2 = 0, val3 = 0, val4 = 0, val5 = 0, val6 = 0, val7 = 0;
void send(char*);
void int_to_char(int);
void send_char(char);
int buf0 = 0;


void __attribute__((__interrupt__, auto_psv)) _ISR _DefaultInterrupt(void)
{
    
    int ad0 = 0, ad1 = 0, ad2 = 0, ad3 = 0, ad4 = 0, ad5 = 0, ad6 = 0, ad7 = 0, ad8 = 0, ad9 = 0, adA = 0, adB = 0, adC = 0, adD = 0, adE = 0, adF = 0;
    if(IFS0bits.AD1IF)
    {
        IFS0bits.AD1IF = 0;
        ad0 = ADC1BUF0*100;
        ad1 = ADC1BUF1*100;
        ad2 = ADC1BUF2*100;
        ad3 = ADC1BUF3*100;
        ad4 = ADC1BUF4*100;
        ad5 = ADC1BUF5*100;
        ad6 = ADC1BUF6*100;
        ad7 = ADC1BUF7*100;
        ad8 = ADC1BUF8*100;
        ad9 = ADC1BUF9*100;
        adA = ADC1BUFA*100;
        adB = ADC1BUFB*100;
        adC = ADC1BUFC*100;
        adD = ADC1BUFD*100;
        adE = ADC1BUFE*100;
        adF = ADC1BUFF*100;
       
       int_to_char(ad1);
       int_to_char(ad2);
       int_to_char(ad3);
       int_to_char(ad4);
       int_to_char(ad5);
       int_to_char(ad6);
       int_to_char(ad7);
       int_to_char(ad8);
       int_to_char(ad9);
       int_to_char(adA);
       int_to_char(adB);
       int_to_char(adC);
       int_to_char(adD);
       int_to_char(adE);
       int_to_char(adF);
       return;
    }
    else
         return;
}

/*
void __attribute__((__interrupt__, auto_psv )) _ISR _ReceiveInterrupt (void)
{ 
    
    return;
}
*/
void main(void) {
    init();
    while(1);
    /*
    int n = 0, i = 0, k = 0;
    double m = 0, sine = 0;
    while(1)
    {   
        for(m = 0; m < 6.29; m += 0.01)
        {
            sine = sin(m);
            sine = sine*1000;
            int_to_char((int)sine);
            for(k = 0; k < 100; k++);
            n++;
            if(n == 100000){
              LATBbits.LATB12 = 1;        //wakeup
              for(i = 0; i < 10; i++);
              LATBbits.LATB12 = 0;
              for(i = 0; i < 10; i++);
              LATBbits.LATB12 = 1;
              n = 0;
           }
        }
        
        send_char('2');
        for(n = 0; n < 50; n++);
        send_char('3');
        for(n = 0; n < 50; n++);
        send_char('6');
        for(n = 0; n < 50; n++);
        send_char('9');
        for(n = 0; n < 50; n++);
         */
    return;
}
