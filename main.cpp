#include "mbed.h"
#include "LCD_DISCO_F769NI.h"
#include <vector>
#include <list>
#include <memory>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

LCD_DISCO_F769NI lcd;
DigitalOut led_red(LED1);
DigitalOut led_green(LED2);

int main()
{
    led_green = 0;
    led_red = 1;
    
    lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"MBED EXAMPLE", CENTER_MODE);
    
    wait(2);

    lcd.Clear(LCD_COLOR_BLUE);
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(7), (uint8_t *)"How to program STM32F7", CENTER_MODE);
    lcd.DisplayStringAt(0, LINE(8), (uint8_t *)"using open source tools only?", CENTER_MODE);
    
    int clockX = 400;
    int clockY = 320;

    lcd.DrawCircle(clockX, clockY, 34);
    
    int hour = 1;
    double hourAngle = 12 / hour * 360 + 90;
    lcd.DrawLine(clockX, clockY, clockX + cos(hourAngle) * 15, clockY + sin(hourAngle) * 15);
    
    int minute = 51;
    double minuteAngle = 60 / minute * 360 + 90;
    lcd.DrawLine(clockX, clockY, clockX + cos(minuteAngle) * 25, clockY + sin(minuteAngle) * 25);

    led_green = 1;
    led_red = 0;

    while(1) {
    }
}
