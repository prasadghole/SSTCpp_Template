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
    LED_Evt(SST::Signal sig, uint32_t p)
    {
      this->sig = sig;
      pin = p;
    }

  private:
    uint32_t pin; /*< Pin number  */
  };

}


#endif /* APP_HPP_ */
