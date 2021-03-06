/** 
 * Target processor interrupts factory.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2016 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.target.InterruptController.hpp"

namespace target
{
  /**
   * Supervisor exception.
   *
   * @param source interrupt source.
   * @return branch address.
   */
  int32 InterruptController::supervisor(int32 source)
  {
    int32 size = 4 * (0x1 << aintc_->vsr.bit.size);
    return aintc_->vbr.bit.base + source * size;
  }  
  
  /**
   * HW interrupt handle routing.
   *
   * @param channel interrupt channel.
   */
  void InterruptController::handler(int32 channel)
  {
    register Context* ctx = &context_[channel];
    #ifdef BOOS_NESTED_INT
    register bool is = ctx->disable();
    globalEnable(true);
    #endif    
    ctx->handler->main();
    #ifdef BOOS_NESTED_INT
    globalDisable();
    ctx->enable(is);
    #endif     
  } 
   
  /**
   * ARM Interrupt Controller (no boot).
   */
  registers::Aintc* InterruptController::aintc_;  

  /**
   * Hi level interrupt channels (no boot).
   */        
  InterruptController::Context InterruptController::context_[InterruptController::NUMBER_CHANNELS];      

  /**
   * Low level interrupts context table (no boot).
   */    
  InterruptController::ContextLow* InterruptController::contextLow_;
  
  /**
   * The kernel configuration (no boot).
   */
  const Configuration* InterruptController::config_;  
}
