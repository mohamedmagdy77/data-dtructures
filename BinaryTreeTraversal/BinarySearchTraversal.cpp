#include "BinarySearchTree.h"
#include "queue.h"
#include <iostream>

template <typename T>
void BST<T>::init_qr(void){
    qr.enqueue(root);
}

/**
 * print the binary tree in level order traversal using recursion
 * @note you have to push root to qr queue using the previous function before calling
 *       this function
 *
*/
template <typename T>
void BST<T>::levelOrderTraversalRecursive(void){
    Node *Thru = qr.dequeue();
    std::cout << Thru->data << " ";
    if(Thru->leftNode != '\0')
        qr.enqueue(Thru->leftNode);
    if(Thru->rightNode != '\0')
        qr.enqueue(Thru->rightNode);
    if(qr.isQueueEmpty())
        return;
    levelOrderTraversalRecursive();
}

/**
 * print the binary tree in level order traversal
 *
*/
template <typename T>
void BST<T>::levelOrderTraversal(void){
    if(root == '\0')
        return;
    Queue<Node*> q1;
    q1.enqueue(root);
    while(!q1.isQueueEmpty()){
        Node *Thru = q1.dequeue();
        std::cout << Thru->data << " ";
        if(Thru->leftNode != '\0')
            q1.enqueue(Thru->leftNode);
        if(Thru->rightNode != '\0')
            q1.enqueue(Thru->rightNode);
    }
    std::cout << std::endl;
}

/**
 * print the binary tree in pre-order traversal
 * @param root pointer to the binary tree
 *
*/
template <typename T>
void BST<T>::PreOrderTraversal(Node *Thru){
    if(Thru == '\0')
        return;
    std::cout << Thru->data << " ";
    PreOrderTraversal(Thru->leftNode);
    PreOrderTraversal(Thru->rightNode);
}

/**
 * print the binary tree in in-order traversal
 * @param root pointer to the binary tree
 *
*/
template <typename T>
void BST<T>::InOrderTraversal(Node *Thru){
    if(Thru == '\0')
        return;
    InOrderTraversal(Thru->leftNode);
    std::cout << Thru->data << " ";
    InOrderTraversal(Thru->rightNode);
}

/**
 * print the binary tree in post-order traversal
 * @param root pointer to the binary tree
 *
*/
template <typename T>
void BST<T>::PostOrderTraversal(Node *Thru){
    if(Thru == '\0')
        return;
    PostOrderTraversal(Thru->leftNode);
    PostOrderTraversal(Thru->rightNode);
    std::cout << Thru->data << " ";
}
