/*
 * grove_button.h
 *
 * Copyright (c) Hging.
 * Website    : www.hging.net
 * Author     : Hging (hging3@gmail.com)
 *
 * The MIT License (MIT)
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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef __GROVE_SLIDE_POTENTIOMETER_H__
#define __GROVE_SLIDE_POTENTIOMETER_H__

#include "suli2.h"

//GROVE_NAME        "Grove-Slide-Potentiometer"
//SKU               101020036
//IF_TYPE           ANALOG
//IMAGE_URL         https://raw.githubusercontent.com/Seeed-Studio/Grove_Drivers_for_Wio/static/images/grove-Button.jpg
//DESCRIPTION       "The Grove Generic Analog In can read external analog value, range on 0~1023."
//WIKI_URL          https://seeeddoc.github.io/Grove-Slide_Potentiometer/
//ADDED_AT          "2017-08-11"
//AUTHOR            "Hging"

class GroveSlidePotentiometer
{
public:
    GroveSlidePotentiometer(int pin);

    /**
     * Read the ADC measurement of a generic analog device. The full range is 0~1023.
     *
     * @param analog - The measurement of ADC, 0~1023
     *
     * @return bool
     */
    bool read_analog(int *analog);
    /**
     * Read the voltage of the measuring point.
     *
     * @param volt - unit: V
     *
     * @return bool
     */
    bool read_voltage(float *volt);
    /**
     * Event which is triggered when the button is pressed,
     * event data is the number of PIN where the button is attached.
     */
    
    DEFINE_EVENT(slide_changed, SULI_EDT_INT);
    uint32_t time;
    ANALOG_T *io;
    uint32_t cnt_analog;
};

static void slide_interrupt_handler(void *para);

#endif
