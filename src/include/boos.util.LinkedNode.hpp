/** 
 * Element for linked lists.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2016 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_UTIL_LINKED_NODE_HPP_
#define BOOS_UTIL_LINKED_NODE_HPP_

#include "boos.util.Object.hpp"

namespace util
{  
  /** 
   * @param Type  data type of element.
   * @param Alloc heap memory allocator class.
   */
  template <typename Type, class Alloc=Allocator>
  class LinkedNode : public Object<Alloc>
  {
  
  public:
  
    /**
     * Constructor.
     *
     * Given element will be copied to self nodes structure by a copy constructor calling.
     *
     * @param element an user element of this node.
     */
    LinkedNode(const Type& element) :
      prev_    (this),
      next_    (this),
      index_   (0),
      element_ (element){
    }
  
    /**
     * Destructor.
     */
    virtual ~LinkedNode()
    {
      LinkedNode* node = this->next_;
      while(node->index_ != 0)
      {
        node->index_--;
        node = node->next_;
      }
      next_->prev_ = prev_;
      prev_->next_ = next_;
      prev_ = this;
      next_ = this;
    }
  
    /**
     * Inserts a new element after this.
     *
     * Method links a node after this and reindexes
     * chain of nodes starts from given node.
     *
     * @param node pointer to inserted node.
     */
    void after(LinkedNode* node)
    {
      link(node);
      node->index_ = index_;
      do{
        node->index_++;
        node = node->next_;
      }while(node->index_ != 0);
    }
  
    /**
     * Inserts a new element after this.
     *
     * Method links a node before this and reindexes
     * chain of nodes starts from this node.
     *
     * @param node pointer to inserted node.
     */
    void before(LinkedNode* node)
    {
      prev_->link(node);
      node->index_ = index_;
      node = this;
      do{
        node->index_++;
        node = node->next_;
      }while(node->index_ != 0);
    }

    /**
     * Returns previous element.
     *
     * @return previous element.
     */  
    LinkedNode* prev() const
    {
      return prev_;
    }
    
    /**
     * Returns next element.
     *
     * @return next element.
     */  
    LinkedNode* next() const
    {
      return next_;
    }

    /**
     * Returns the element.
     *
     * @return next element.
     */  
    Type element() const
    {
      return element_;
    }

    /**
     * Returns the element index.
     *
     * @return element index.
     */  
    int32 index() const
    {
      return index_;
    }
  
  private:
  
    /**
     * Links a given node after this.
     *
     * @param node pointer to linking node.
     */
    void link(LinkedNode* node)
    {
      next_->prev_ = node;
      node->next_ = next_;
      next_ = node;
      node->prev_ = this;
    }
  
    LinkedNode*             prev_;
    LinkedNode*             next_;
    int32                   index_;
    Type                    element_;
  
  };
}
#endif // BOOS_UTIL_LINKED_NODE_HPP_