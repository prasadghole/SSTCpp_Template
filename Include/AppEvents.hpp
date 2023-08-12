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
  class LED_Evt : public SST::Evt
  {
  public:
    uint32_t pin; /*< Pin number  */
    LED_Evt(SST::Evt s, uint32_t p): Evt(s),pin(p)
    {

    }

  };

}


#endif /* APP_HPP_ */
