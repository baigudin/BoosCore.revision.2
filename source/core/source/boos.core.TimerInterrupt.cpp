/** 
 * Hardware timer interrupt resource.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2014-2016 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.core.TimerInterrupt.hpp"
#include "boos.target.Interrupt.hpp" 
#include "boos.target.Timer.hpp"

namespace core
{
  /** 
   * Constructor.
   */     
  TimerInterrupt::TimerInterrupt() :
    Interrupt (),
    Timer     (){
    setConstruct( construct(NULL) );
  }

  /** 
   * Constructor.
   *
   * @param handler user class which implements an interrupt handler interface.
   */     
  TimerInterrupt::TimerInterrupt(::api::Task& handler) : 
    Interrupt (),
    Timer     (){
    setConstruct( construct(&handler) );
  }

  /**
   * Constructor.
   *
   * @param handler user class which implements an interrupt handler interface.
   * @param number  available timer number for interrupting.
   */     
  TimerInterrupt::TimerInterrupt(::api::Task& handler, int32 number) : 
    Interrupt (),
    Timer     (number){
    setConstruct( construct(&handler) );    
  }

  /**
   * Destructor.
   */
  TimerInterrupt::~TimerInterrupt()
  {
  }
  
  /**
   * Constructor.
   *
   * @param handler user class which implements an interrupt handler interface.
   * @return true if object has been constructed successfully.     
   */     
  bool TimerInterrupt::construct(::api::Task* handler)
  {
    if(!isConstructed()) return false;
    if(!ResTim::extension().isInterrupting()) return false;
    if(handler == NULL) return true;
    return ResInt::extension().setHandler(*handler, ResTim::extension().interrupSource());
  }
  
  /**
   * Tests if this object has been constructed.
   *
   * @return true if object has been constructed successfully.
   */    
  bool TimerInterrupt::isConstructed() const  
  {
    if(!ResInt::isConstructed()) return false;
    if(!ResTim::isConstructed()) return false;    
    return true;
  }
  
  /**
   * Sets the object constructed flag.
   *
   * @param flag constructed flag.
   */      
  void TimerInterrupt::setConstruct(bool flag)
  {
    ResInt::setConstruct(flag);
    ResTim::setConstruct(flag);    
  }  
}
