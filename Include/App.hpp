/*
 * App.hpp
 *
 *  Created on: Aug 10, 2023
 *      Author: pghole
 */

#ifndef APP_HPP_
#define APP_HPP_

#include "sst.hpp"

namespace APP
{
  enum Signals
  {
    LED_ON, LED_OFF, MAX_SIG
  };
  struct LED_Evt
  {
    SST::Evt super;
    uint32_t pin; /*< Pin number  */
  };

}


#endif /* APP_HPP_ */
