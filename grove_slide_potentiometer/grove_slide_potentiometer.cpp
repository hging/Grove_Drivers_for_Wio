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

#include "suli2.h"
#include "grove_slide_potentiometer.h"

GroveSlidePotentiometer::GroveSlidePotentiometer(int pin)
{
    this->io = (ANALOG_T *)malloc(sizeof(ANALOG_T));

    suli_analog_init(io, pin);
    time = millis();
    cnt_analog = 0;
    suli_pin_attach_interrupt_handler(io, &slide_interrupt_handler, SULI_CHANGE, this);
}

bool GroveSlidePotentiometer::read_analog(int *analog)
{
    *analog = suli_analog_read(io);
    return true;
}

bool GroveSlidePotentiometer::read_voltage(float *volt)
{
    *volt = suli_analog_voltage(io);
    return true;
}

static void slide_interrupt_handler(void *para)
{
    GroveSlidePotentiometer *g = (GroveSlidePotentiometer *)para;

    if (millis() - g->time < 10)
    {
        return;
    }
    g->time = millis();

    if (suli_analog_read(g->io) != g->cnt_analog)
    {
      g->cnt_analog = suli_analog_read(g->io);
      POST_EVENT_IN_INSTANCE(g, slide_changed, suli_analog_read(g->io));
    }
}
