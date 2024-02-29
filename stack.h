#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);   
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};
// Uses Vector CTOR
template <typename T>
Stack<T>::Stack() : std::vector<T>()
{
}
// DSTOR
template <typename T>
Stack<T>::~Stack()
{
}
//Checks if Stack is empty
template <typename T>
bool Stack<T>::empty() const
{
    return std::vector<T>::empty();
}
// Gets size of stack
template <typename T>
size_t Stack<T>::size() const
{
    return std::vector<T>::size();
}
// Pushes item passed in to the back
template <typename T>
void Stack<T>::push(const T& item)
{
    return std::vector<T>::push_back(item);
}
// Removes the value present at the end or back 
template <typename T>
void Stack<T>::pop() // throws std::underflow_error if empty
{
    if (empty())
    {
        throw std::underflow_error("Stack is empty");
    }
    std::vector<T>::pop_back();
}
// Gets item at top of stack throws error if empty
template <typename T>
const T& Stack<T>::top() const
{
    if (empty())
    {
        throw std::underflow_error("Stack is empty");
    }
    return std::vector<T>::back();
}
#endif