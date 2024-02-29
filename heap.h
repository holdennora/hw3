#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m;
  std::vector<T> heapArray;
  PComparator comparator;

  size_t getParentIndex(size_t childIndex) const;
  size_t getChildIndex(size_t parentIndex, size_t childNum) const;
  void heapifyUp(size_t index);
  void heapifyDown(size_t index);


};

// Add implementation of member functions here
// CTOR
template <typename T, typename PComparator>
Heap<T,PComparator> :: Heap(int m, PComparator c)
    : m(m), comparator(c)
{
}
//DSTOR
template <typename T, typename PComparator>
Heap<T,PComparator> :: ~Heap()
{
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return heapArray[0];

}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heapArray[0], heapArray.back());
  heapArray.pop_back();
  heapifyDown(0);
}
//SIZE
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heapArray.size();
}
// Empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heapArray.empty();
}
//PUSH
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heapArray.push_back(item);
  size_t currIndex = heapArray.size() - 1;
  heapifyUp(currIndex);  

}
//Child Index
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::getChildIndex(size_t parentIndex, size_t childNum) const
{
  return m * parentIndex + childNum + 1;
}
//Parent index
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::getParentIndex(size_t childIndex) const
{
  return ( childIndex -1 ) / m;
}
//Heapify up
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t index)
{
  size_t curr = index;
  size_t parent = getParentIndex(curr);

  while (curr > 0 && comparator(heapArray[curr], heapArray[parent]))
  {
    std::swap(heapArray[curr], heapArray[parent]);
    curr = parent;
    parent = getParentIndex(curr);
  }
}
//Heapify down
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t index)
{
  size_t curr = index;

  while (true)
  {
    size_t smallest = curr;
    for ( int i = 0; i < m; i++)
    {
      size_t child = getChildIndex(curr, i);

      if (child < heapArray.size() && comparator(heapArray[child], heapArray[smallest]))
      {
        smallest = child;
      }
    }
    if (smallest != curr)
    {
      std::swap(heapArray[curr], heapArray[smallest]);
      curr = smallest;
    }
    else
    {
      break;
    }
  }
}
#endif

