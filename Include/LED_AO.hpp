/*
 * LED_AO.hpp
 *
 *  Created on: Aug 10, 2023
 *      Author: pghole
 */

#ifndef LED_AO_HPP_
#define LED_AO_HPP_

#include "sst.hpp"

class LED_AO: public SST::Task
{
public:
  LED_AO(void);
  void init(SST::Evt const *const ie) override;
  void dispatch(SST::Evt const *const e) override;
};

#endif /* LED_AO_HPP_ */
