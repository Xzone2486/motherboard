 #include <lpc17xx.h>

void delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for(i = 0; i < ms; i++)
        for(j = 0; j < 50000; j++);
}

/* start the main program */
int main()
{
    SystemInit();   // Clock and PLL configuration
    LPC_PINCON->PINSEL4 = 0x000000;   // Configure the PORT2 Pins as GPIO
    LPC_GPIO2->FIODIR = 0xFFFFFFFF;   // Configure the PORT2 pins as OUTPUT

    while(1)
    {
        LPC_GPIO2->FIOSET = 0xFFFFFFFF;   // Make all the Port pins high
        delay_ms(100);

        LPC_GPIO2->FIOCLR = 0xFFFFFFFF;   // Make all the Port pins low
        delay_ms(100);
    }
}

