#include "stm32f3xx.h"

// Quick and dirty delay
static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}

int main (void) {
    // Turn on the GPIOE peripheral
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;

    // Put pins in general purpose mode
    GPIOE->MODER  |= GPIO_MODER_MODER8_0;
    GPIOE->MODER  |= GPIO_MODER_MODER9_0;
    GPIOE->MODER  |= GPIO_MODER_MODER10_0;
    GPIOE->MODER  |= GPIO_MODER_MODER11_0;
    GPIOE->MODER  |= GPIO_MODER_MODER12_0;
    GPIOE->MODER  |= GPIO_MODER_MODER13_0;
    GPIOE->MODER  |= GPIO_MODER_MODER14_0;
    GPIOE->MODER  |= GPIO_MODER_MODER15_0;

    unsigned int waitTime = 300; 

    while (1) {
        // Reset the state of pin 8 to output low
        GPIOE->BSRR = GPIO_BSRR_BR_8;
        delay(waitTime);
        // Set the state of pin 8 to output high
        GPIOE->BSRR = GPIO_BSRR_BS_8;
        delay(waitTime);

        // Reset the state of pin 8 to output low
        GPIOE->BSRR = GPIO_BSRR_BR_9;
        delay(waitTime);
        // Set the state of pin 8 to output high
        GPIOE->BSRR = GPIO_BSRR_BS_9;
        delay(waitTime);

        // Reset the state of pin 8 to output low
        GPIOE->BSRR = GPIO_BSRR_BR_10;
        delay(waitTime);
        // Set the state of pin 8 to output high
        GPIOE->BSRR = GPIO_BSRR_BS_10;
        delay(waitTime);

        // Reset the state of pin 8 to output low
        GPIOE->BSRR = GPIO_BSRR_BR_11;
        delay(waitTime);
        // Set the state of pin 8 to output high
        GPIOE->BSRR = GPIO_BSRR_BS_11;
        delay(waitTime);
    }

    // Return 0 to satisfy compiler
    return 0;
}
