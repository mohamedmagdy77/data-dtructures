#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

template <typename T>
class List{
public:
    const T &operator[](unsigned index);
    void insertAtFront(const T &data);
    void deleteAtFront(void);
    void insertAtIndex(const T &data, unsigned index);
    void showTillIndex(int index);
    void deleteAtIndex(unsigned index);
    //const T &operator[](unsigned index);

    List(): head_('\0'){}
    ~List(){
        NodeList *Thru = head_;
        while(Thru != '\0'){
            NodeList *toDelete = Thru;
            Thru = Thru->next;
            delete toDelete;
            toDelete = '\0';
        }
    }

private:
    class NodeList{
    public:
        const T & data;
        NodeList *next;
        NodeList(const T & data): data(data), next('\0'){}
    };
    NodeList *head_;
    NodeList *find_(const T &data);
};

#include "linked_list.cpp"

#endif // LINKED_LIST_H_INCLUDED
