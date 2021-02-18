#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <typename T>
class Stack{
public:
    void push(const T& data);
    const T& pop(void);
    const T& topStack(void);
    bool isStackEmpty(void);
    void sohwToIndex(int index);

    Stack(): head_('\0'){}
    ~Stack(){
        StackNode *Thru = head_;
        while(Thru != '\0'){
            StackNode *todelete = Thru;
            Thru = Thru->next;
            delete todelete;
            todelete = '\0';
        }
    }

private:
    class StackNode{
    public:
        const T& data;
        StackNode *next;
        StackNode(const T& data): data(data), next('\0'){}
    };
    StackNode *head_;
};

#include "stack.cpp"

#endif // STACK_H_INCLUDED
