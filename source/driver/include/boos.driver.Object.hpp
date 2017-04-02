/** 
 * Root class of the driver namespace class hierarchy.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_OBJECT_HPP_
#define BOOS_DRIVER_OBJECT_HPP_

#include "boos.Object.hpp"
#include "boos.driver.Allocator.hpp"

namespace driver
{
  /** 
   * @param Alloc heap memory allocator class.
   */ 
  template <class Alloc=Allocator>
  class Object : public ::Object<Alloc>
  {
    typedef ::Object<Alloc> Parent;  
    
  public:

    /** 
     * Constructor.
     */  
    Object() : Parent()
    {
    }     
    
    /** 
     * Copy constructor.
     *
     * @param obj reference to source object.
     */ 
    Object(const Object& obj) : Parent(obj)
    {
    }
    
    /** 
     * Destructor.
     */    
    virtual ~Object(){}     
    
    /** 
     * Assignment operator.
     *
     * @param obj reference to source object.
     * @return reference to this object.     
     */  
    Object& operator =(const Object& obj)
    {
      Parent::operator=(obj);
      return *this;
    }
    
  };
}
#endif // BOOS_DRIVER_OBJECT_HPP_

