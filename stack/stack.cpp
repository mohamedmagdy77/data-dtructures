#include "stack.h"

template <typename T>
void Stack<T>::push(const T& data){
    StackNode *node = new StackNode(data);
    node->next = head_;
    head_ = node;
}

template <typename T>
const T& Stack<T>::pop(void){
    StackNode *node = head_;
    const T& data_ = head_->data;
    head_ = head_->next;
    delete node;
    node = '\0';
    return data_;
}

template <typename T>
const T& Stack<T>::topStack(void){
    return head_->data;
}

template <typename T>
bool Stack<T>::isStackEmpty(void){
    return (head_ == '\0')? true : false;
}

template <typename T>
void Stack<T>::sohwToIndex(int index){
    StackNode *Thru = head_;
    unsigned counter=0;
    while(Thru != '\0' && index >= 0){
        index--;
        std::cout << "Stack[" << counter << "]: " << Thru->data << std::endl;
        Thru = Thru->next;
        counter++;
    }
    if(index >= 0){
        std::cout << "Stack has only " << counter << " elements!\n";
    }
}
