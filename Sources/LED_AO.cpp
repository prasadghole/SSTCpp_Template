/*
 * LED_AO.cpp
 *
 *  Created on: Aug 10, 2023
 *      Author: pghole
 */

#include "LED_AO.hpp"
#include "AppEvents.hpp"
#include "bsp.hpp"

LED_AO::LED_AO(void)
{
}

void LED_AO::init(const SST::Evt *const ie)
{
}

void LED_AO::dispatch(const SST::Evt *const e)
{
  switch(e->sig)
  {
  case APP::LED_ON:
    BSP::ledOn();
    break;
  case APP::LED_OFF:
    BSP::ledOff();
    break;

  }
}
