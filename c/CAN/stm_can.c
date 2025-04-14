#include "stm32f4xx.h"

// Define ADC channels for high and low rails
const uint8_t HIGH_CHANNEL = 0; // AIN0
const uint8_t LOW_CHANNEL = 1;   // AIN1

// Define the LED pin (green)
const uint16_t LED_PIN = GPIO_ToggleBit(GPIOC, GPIO_Pin_7);

void measure_voltage(uint16_t *high, uint16_t *low) {
    // Enable ADC clock
    RCC->AHBENR |= RCC_AHBENR_ADC1EN;

    // Configure ADC channels for single-ended measurement
    ADC1->CCR &= ~(ADC_CCR_ADCK_EN | ADC_CCR_MODE);
    ADC1->SMP = 0x7FF; // Sample time: 12 cycles (default)
    ADC1->CFGR |= (HIGH_CHANNEL << 16) | LOW_CHANNEL;
    ADC1->CCR |= ADC_CCR_ADCK_EN;

    // Convert ADC values to voltage
    *high = ADC1->DR >> 3; // Map 12-bit ADC value to voltage on HIGH_CHANNEL
    *low = ADC1->DHR12D1 >> 3; // Map 12-bit ADC value to voltage on LOW_CHANNEL

    // Disable ADC clock
    RCC->AHBENR &= ~RCC_AHBENR_ADC1EN;
}

void check_conditions(void) {
    uint16_t high, low;

    measure_voltage(&high, &low);

    if ((high >= 1500 && high <= 3500) && (low >= 500 && low <= 2500)) {
        // Green LED solid on
        GPIO_SetBits(GPIOC, LED_PIN);
    } else {
        // Blink green LED off and on
        while (1) {
            GPIO_ResetBits(GPIOC, LED_PIN);
            __WFI(); // Low-power wait for interrupt
            GPIO_SetBits(GPIOC, LED_PIN);
            __WFI();
        }
    }
}

void system_tick(void) {
    static uint32_t tick_count = 0;

    ++tick_count;
    if (tick_count >= 1000) { // Check conditions every 1 second
        check_conditions();
        tick_count = 0; // Reset count for next iteration
    }
}
