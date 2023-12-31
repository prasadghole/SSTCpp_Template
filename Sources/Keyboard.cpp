/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Main Module Header */
#include "Keyboard.hpp"

#include "../Include/AppEvents.hpp"
#include "Globals.hpp"
#include "stm32f3xx.h"

/* Private Module Includes */
// #include "{__name__}_private.h"        // either this
// #include "sl_unit_test_facilitator.h"  // or this

/***********************************************************************************************************************
 *
 *                                                   D E F I N E S
 *
 **********************************************************************************************************************/

#define B1_PIN 13
/***********************************************************************************************************************
 *
 *                                                  T Y P E D E F S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                             P R I V A T E   F U N C T I O N   D E C L A R A T I O N S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                                  P R I V A T E   D A T A   D E F I N I T I O N S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                                         P R I V A T E   F U N C T I O N S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                                          P U B L I C   F U N C T I O N S
 *
 **********************************************************************************************************************/
/**
 * @brief
 *
 */
void PVD_IRQHandler(void)
{
  LEDAO.activate();
}
/**
 * @brief
 *
 */
void ButtonDebounceHandler(void)
{
  static struct ButtonsDebouncing
  {
    uint32_t depressed;
    uint32_t previous;
  } buttons =
  { 0U, 0U };
  uint32_t current = ~GPIOC->IDR;
  /* read GPIO PortC */uint32_t tmp = buttons.depressed;
  /* save the debounced depressed */buttons.depressed |= (buttons.previous
      & current); /* set depressed */
  buttons.depressed &= (buttons.previous | current); /* clear released */
  buttons.previous = current; /* update the history */
  tmp ^= buttons.depressed; /* changed debounced depressed */
  if ((tmp & (1U << B1_PIN)) != 0U)
  {
    /* debounced B1 state changed? */
    if ((buttons.depressed & (1U << B1_PIN)) != 0U)
    {
      /* depressed? */
      static const APP::LED_Evt event(APP::LED_ON,13);
      LEDAO.post(&event);
    }
    else
    {
      /* B1 is released */
      static const APP::LED_Evt event(APP::LED_OFF,13);
      LEDAO.post(&event);

    }

  }
}



