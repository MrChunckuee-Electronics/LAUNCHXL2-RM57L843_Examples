/** @file HL_sys_main.c 
*   @brief Application main file
*   @date 07-July-2017
*   @version 04.07.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2016 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */

/*******************************************************************************
 *
 * RM57L843: Basic GIO example
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       RM57L843
 * Complier:        CCS 7.2.0.00013 & HALCoGen 04.07.00
 * Author:          Pedro S�nchez Ram�rez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Peque�o ejemplo sobre GIOs, LED3 (GIOB_7) se configuro para
 *                  que se encienda desde el inicio, si detecta que se ha pulsado
 *                  el boton A (GIOB_4) se apaga y LED2 (GIOB_6) enciende de forma
 *                  intermitente cada 500ms, si se vuelve a pulsar A, se detiene
 *                  y LED3 cambia de estado.
 *******************************************************************************
 * Rev.     Date        Comment
 *  v0.00   14/06/2018  - Creaci�n del firmware
 ******************************************************************************/

/* USER CODE END */

/* Include Files */

#include "HL_sys_common.h"

/* USER CODE BEGIN (1) */
#include "HL_gio.h"
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
void MCU_DelaySeg(float time);
/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
    unsigned char boton=0;
    gioInit();
    while(1){
        if(gioGetBit(gioPORTB,4) == 0 ){
            boton^=0xFF;
            if(boton)
                gioSetBit(gioPORTB,7,0);
            else
                gioSetBit(gioPORTB,7,1);
            while(gioGetBit(gioPORTB,4) == 0);
            MCU_DelaySeg(5e-3);
           }
        if(boton){
            gioToggleBit(gioPORTB, 6);
            MCU_DelaySeg(500e-3);
        }
    }
/* USER CODE END */

    //return 0;
}


/* USER CODE BEGIN (4) */

/*******************************************************************************
 * Function:        void MCU_DelaySeg (float time)
 * Description:     Esta funcion genera retardos en el orden de segundos.
 * Precondition:    None
 * Parameters:      time = tiempo en milisegundos
 * Return Values:   None
 * Remarks:         Funcion tomada de Martin Valencia @ElectronAplica
 * *****************************************************************************/
void MCU_DelaySeg (float time){
    int long c, x_time = (int long) (1.36e7 * time);
    for (c=0; c <= 2 * x_time; c++){
    }
}

/* USER CODE END */
