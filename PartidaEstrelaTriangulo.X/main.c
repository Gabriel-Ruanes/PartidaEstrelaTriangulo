/*
 * File:   main.c
 * Author: 21192694
 *
 * Created on 18 de Fevereiro de 2021, 15:36
 */


#include <xc.h>
#include "config.h"
#include "contatores.h"
#include "delay.h"

void main(void) 
{
    int estado = 0;
    int t;
    
    while ( 1 )
    {
        switch ( estado )
        {
            case 0:
                    contatores_init();
                    estado = 1;
                    break;
                    
            case 1:
                    if ( botao_S1() == 1 )
                        estado = 2;
                    break;
                    
            case 2:
                    k1(1);
                    k2(1);
                    k3(0);
                    t = 3000;
                    estado = 3;
                    break;
                    
            case 3:
                    delay(1);
                    --t;
                    if ( t <= 0 )
                        estado = 4;
                    break;
                    
            case 4:
                    k1(1);
                    k2(0);
                    k3(1);
                    if ( botao_S0() == 1 )
                        estado = 5;
                    break;
                    
            case 5:
                    k1(0);
                    k2(0);
                    k3(0);
                    estado = 1;
                    break;
        }
    }
}
