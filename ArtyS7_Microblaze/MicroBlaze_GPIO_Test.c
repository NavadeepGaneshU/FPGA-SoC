/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "sleep.h"

#define GPIO
#define XPAR_GPIO_0_DEVIC_ID	XPAR_AXI_GPIO_0_DEVICE_ID
#define LED_CHANNEL 0x01
#define PB_CHANNEL 0x02

XGpio	Gpio_LED2;	//instantiate GPIO driver

int main()
{
    u32 Status;
    u32 Buttons;
    init_platform();
    print("LED Test\n\r");

    Status = XGpio_Initialize(&Gpio_LED2, XPAR_GPIO_0_DEVICE_ID);
    if(Status != XST_SUCCESS)
    {
    	xil_printf("GPIO initialization failed\r\n");
    	return XST_FAILURE;
    }

    //Set GPIO directions
    XGpio_SetDataDirection(&Gpio_LED2, LED_CHANNEL, 0x0); //set output
    XGpio_SetDataDirection(&Gpio_LED2, PB_CHANNEL, 0x1);  //set input

    print("Push Buttons to light LEDs");

    //Main driver code
    while(1)
    {
    	//For blinking LED
    	XGpio_DiscreteWrite(&Gpio_LED2, LED_CHANNEL, 0x0);
    	sleep(1);
    	XGpio_DiscreteWrite(&Gpio_LED2, LED_CHANNEL, 0x1);
        sleep(1);
        
        
        //For GPIO pushbutton toggling
    	Buttons = XGpio_DiscreteRead(&Gpio_LED2, PB_CHANNEL);
    	XGpio_DiscreteWrite(&Gpio_LED2, LED_CHANNEL, Buttons);
    	usleep(100);
        
    }
}
