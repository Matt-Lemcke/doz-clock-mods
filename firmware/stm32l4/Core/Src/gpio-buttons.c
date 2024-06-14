/*
 * gpio-buttons.c
 *
 *  Created on: Jan. 14, 2024
 *      Author: Matt L.
 */

#include "gpio-buttons.h"
#include "event_queue.h"

#define BTN_LONG_HOLD_MS    1000
#define BTN_SHORT_PRESS_MS  100

typedef struct button_t
{
    BtnId id;
    uint16_t pin;
    GPIO_TypeDef *port;
}Button;

static Button buttons[NUM_BUTTONS] =
{
        {.id = B_DISPLAY, .pin = BTN1_IN_Pin,     .port = BTN1_IN_GPIO_Port},
        {.id = B_DOZ,     .pin = BTN2_IN_Pin,     .port = BTN2_IN_GPIO_Port},
        {.id = B_TRAD,    .pin = BTN3_IN_Pin,     .port = BTN3_IN_GPIO_Port},
        {.id = B_LEFT,    .pin = BTN4_IN_Pin,     .port = BTN4_IN_GPIO_Port},
        {.id = B_RIGHT,   .pin = BTN5_IN_Pin,     .port = BTN5_IN_GPIO_Port},
        {.id = B_UP,      .pin = BTN6_IN_Pin,     .port = BTN6_IN_GPIO_Port},
        {.id = B_DOWN,    .pin = BTN7_IN_Pin,     .port = BTN7_IN_GPIO_Port},
        {.id = B_ALARM,   .pin = BTN8_IN_Pin,     .port = BTN8_IN_GPIO_Port},
        {.id = B_TIMER,   .pin = BTN9_IN_Pin,     .port = BTN9_IN_GPIO_Port},
        {.id = B_VOLUP,   .pin = BTN10_IN_Pin,    .port = BTN10_IN_GPIO_Port},
        {.id = B_VOLDOWN, .pin = BTN11_IN_Pin,    .port = BTN11_IN_GPIO_Port},
        {.id = B_CANCEL,  .pin = BTN12_IN_Pin,    .port = BTN12_IN_GPIO_Port},
};
static Button *active_btn;
static uint32_t hold_time_ms = 0;
static uint8_t btn_released = 0;

void Buttons_Init(void)
{
    active_btn = NULL;
    hold_time_ms = 0;
    btn_released = 0;
}

void Buttons_GpioCallback(uint16_t pin)
{
    if (active_btn != NULL)
    {
        if (active_btn->pin == pin)
        {
            // Status change of active button
            if (HAL_GPIO_ReadPin(active_btn->port, active_btn->pin) == GPIO_PIN_RESET)
            {
                // Falling edge
                btn_released = 1;
            }
        }
    }
    else if (!btn_released)
    {
        // Status change of inactive button
        for(int i = 0; i < NUM_BUTTONS; i++)
        {
            if(pin == buttons[i].pin)
            {
                // Button is valid

                if (HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin) == GPIO_PIN_SET)
                {
                    // Rising edge
                    hold_time_ms = 0;
                    btn_released = 0;
                    active_btn = buttons + i;
                }
            }
        }
    }
}

void Buttons_TimerCallback(uint32_t period_ms)
{
    if (active_btn != NULL)
    {
        // Button is being monitored
        if(btn_released)
        {
            // Button has already been released
            if(hold_time_ms < BTN_LONG_HOLD_MS)
            {
                // Short press trigger
                EventQ_TriggerButtonEvent(active_btn->id, SHORT);
            }
            active_btn = NULL;
            hold_time_ms = 0;
            btn_released = 0;
        }
        else if(hold_time_ms < BTN_LONG_HOLD_MS)
        {
            // Button is pressed, waiting to see if it's a long press
            hold_time_ms += period_ms;
            if (hold_time_ms >= BTN_LONG_HOLD_MS)
            {
                // long press trigger
                EventQ_TriggerButtonEvent(active_btn->id, LONG);
            }
        }
    }
}
