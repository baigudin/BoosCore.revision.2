/** 
 * Target processor interrupts factory.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2016 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.target.Interrupt.hpp"
#include "boos.target.InterruptController.hpp"

namespace target
{
  /**
   * Returns the interrupt interface of a target processor.
   *
   * @return target processor interrupt interface.
   */
  ::target::Interrupt* Interrupt::create()
  {
    return new InterruptController();
  }
  
  /**
   * Returns the interrupt interface of a target processor.
   *
   * @param handler pointer to user class which implements an interrupt handler interface.
   * @param source  available interrupt source.     
   * @return target processor interrupt interface.
   */
  ::target::Interrupt* Interrupt::create(::api::Task& handler, int32 source)
  {
    return new InterruptController(handler, source);
  }
  
  /**
   * Disables all maskable interrupts.
   *
   * @return global interrupts enable bit value before method was called.
   */
  bool Interrupt::globalDisable()
  {
    return InterruptController::globalDisable();
  }
  
  /**
   * Enables all maskable interrupts.
   *
   * @param status the returned status by disable method.
   */
  void Interrupt::globalEnable(bool status)
  {
    InterruptController::globalEnable(status);
  }
}
