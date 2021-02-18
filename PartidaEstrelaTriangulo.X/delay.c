/*
 * File:   delay.c
 * Author: 21192694
 *
 * Created on 18 de Fevereiro de 2021, 15:59
 */


#include <xc.h>
#include "config.h"


void delay ( unsigned int t )
{
    while ( t )
    {
        --t;
        __delay_ms(1);
    }
}

