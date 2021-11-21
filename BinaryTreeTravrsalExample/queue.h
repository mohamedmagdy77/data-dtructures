#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <typename T>
class Queue{
public:
    void enqueue(const T& data);
    const T& dequeue(void);
    const T& frontQueue(void);
    void sohwToIndex(int index);
    bool isQueueEmpty(void);

    Queue(): head_('\0'), tail_('\0'){}
    ~Queue(){
        QueueNode *Thru = head_;
        while(Thru != '\0'){
            QueueNode *toDelete = Thru;
            Thru = Thru->next;
            delete toDelete;
            toDelete = '\0';
        }
    }

private:
    class QueueNode{
    public:
        const T& data;
        QueueNode * next;
        QueueNode(const T& data): data(data),next('\0'){}
    };
    QueueNode * head_;
    QueueNode * tail_;
};

#include "queue.cpp"

#endif // QUEUE_H_INCLUDED
