#include "queue.h"

template <typename T>
void Queue<T>::enqueue(const T& data){
    QueueNode* node = new QueueNode(data);
    if(head_ == '\0'){
        head_ = node;
        tail_ = node;
        return;
    }
    tail_->next = node;
    tail_ = node;
}

template <typename T>
const T& Queue<T>::dequeue(void){
    QueueNode* node = head_;
    const T& data_ = node->data;
    head_ = head_->next;
    delete node;
    node = '\0';
    return data_;
}

template <typename T>
const T& Queue<T>::frontQueue(void){
    return head_->data;
}

template <typename T>
bool Queue<T>::isQueueEmpty(void){
    return (head_ == '\0')? true : false;
}

template <typename T>
void Queue<T>::sohwToIndex(int index){
    QueueNode *Thru = head_;
    unsigned counter=0;
    while(Thru != '\0' && index >= 0){
        index--;
        std::cout << "Queue[" << counter << "]: " << Thru->data << std::endl;
        Thru = Thru->next;
        counter++;
    }
    if(index >= 0){
        std::cout << "Queue has only " << counter << " elements!\n";
    }
}


