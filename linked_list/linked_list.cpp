#include "linked_list.h"
#include <iostream>

/**
 * get data from list through index like an array example (list[1])
 * @param List index
 * @return data stored at this index
 *
*/
template <typename T>
const T & List<T>::operator[](unsigned index){
    NodeList *Thru = head_;
    while(Thru->next != '\0' && index > 0){
        Thru = Thru->next;
        index--;
    }
    return Thru->data;
}

/**
 * create node at the front of the list
 * @param data to be stored at the node
 *
*/
template <typename T>
void List<T>::insertAtFront(const T &data){
    NodeList *node = new NodeList(data);
    node->next = head_;
    head_ = node;
}

/**
 * delete the node at the front of the list
 *
*/
template <typename T>
void List<T>::deleteAtFront(void){
    NodeList *head_copy = head_;
    delete head_;
    head_ = head_copy->next;
}

/**
 * find specific data from the list
 * @param data to be searched for at the list
 * @return pointer to the node contains the data
 *
*/
template <typename T>
typename List<T>::NodeList* List<T>::find_(const T &data){
    NodeList *Thru = head_;
    while(Thru != '\0'){
        if(Thru->data == data){return Thru;}
        Thru = Thru->next;
    }
    return '\0';
}

/**
 * create node at the front of the list
 * @param data to be stored at the node
 * @param index to store data in
 *
*/
template <typename T>
void List<T>::insertAtIndex(const T &data, unsigned index){
    // for inserting at front of list
    if(index == 0){
        insertAtFront(data);
        return;
    }
    // for any index bigger than 0
    NodeList *Thru = head_;
    while(Thru != '\0' && index > 1){
        Thru = Thru->next;
        index--;
    }
    // if index is larger than List size
    if(Thru == '\0' && index > 0){
        std::cout << "Error: large number passed to insertAtIndex function!" << std::endl;
        return;
    }
    NodeList *node = new NodeList(data);
    NodeList *Thru_copy = Thru->next;
    Thru->next = node;
    node->next = Thru_copy;
}

/**
 * delete the node at the index passed from the list
 * @param index of the node to be deleted
 *
*/
template <typename T>
void List<T>::deleteAtIndex(unsigned index){
    if(index == 0){
        deleteAtFront();
        return;
    }
    NodeList *Thru = head_;
    while(Thru != '\0' && index > 1){
        Thru = Thru->next;
        index--;
    }
    NodeList *Thru_previous_ = Thru;
    Thru = Thru->next;
    Thru_previous_->next = Thru->next;
    delete Thru;
    Thru = '\0';
}

/**
 * displays the list nodes from the front to the specified index
 * @param index remarks the last node to be displayed
 *
*/
template <typename T>
void List<T>::showTillIndex(int index){
    NodeList *Thru = head_;
    unsigned counter=0;
    while(Thru != '\0' && index >= 0){
        index--;
        std::cout << "List[" << counter << "]: " << Thru->data << std::endl;
        Thru = Thru->next;
        counter++;
    }
    if(index >= 0){
        std::cout << "List has only " << counter << " elements!\n";
    }
}

/*template <typename T>
const T & List<T>::operator[](unsigned index){
    NodeList *Thru = head_;
    while(Thru != '\0' && index > 0){
        Thru = Thru->next;
        index--;
    }
    return &(Thru->data);
}
*/


