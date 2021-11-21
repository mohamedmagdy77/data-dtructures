#include "BinarySearchTree.h"
#include <iostream>

/**
 * insert data in the binary search tree
 * @param data to be inserted to the BST
 *
*/
template <typename T>
void BST<T>::insertNode(const T& data){
    Node *node = new Node(data);
    Node *Thru = root;
    if(root == '\0'){
        root = node;
        return;
    }
    while(Thru != '\0'){
        if(data <=  Thru->data){
            if(Thru->leftNode == '\0'){
                Thru->leftNode = node;
                break;
            }
            else
                Thru = Thru->leftNode;
        }
        else{
            if(Thru->rightNode == '\0'){
                Thru->rightNode = node;
                break;
            }
            else
                Thru = Thru->rightNode;
        }
    }
}

/**
 * searches for a specific data at the BST and print "Found!" in case this element exists in the BST
 * and "Not Found!" in case this element not in the BST.
 * @param data to be searched for at the BST
 *
*/
template <typename T>
void BST<T>::searchElement(const T& data){
    Node *Thru = root;
    while(Thru != '\0'){
        if(data == Thru->data){
            std::cout << "Found!\n";
            return;
        }
        else if(data < Thru->data){
            Thru = Thru->leftNode;
        }
        else{
            Thru = Thru->rightNode;
        }
    }
    std::cout << "Not Found!\n";
}

/**
 * find maximum element in the BST
 * @return the maximum element in the BST
 *
*/
template <typename T>
const T& BST<T>::findMax(void){
    Node *Thru = root;
    while(Thru->rightNode != '\0'){
        Thru = Thru->rightNode;
    }
    return Thru->data;
}

/**
 * find minimum element in the BST
 * @return the minimum element in the BST
 *
*/
template <typename T>
const T& BST<T>::findMin(void){
    Node *Thru = root;
    while(Thru->leftNode != '\0'){
        Thru = Thru->leftNode;
    }
    return Thru->data;
}

/**
 * find maximum of two numbers
 * @return the maximum number between the two numbers
 * @param  two integer numbers
 * @note  this function is not part of the BST class,
 *        it's only used with findHeightPrivate function
 *
*/
const int maxOfTwo(const int a, const int b){
    return a>=b? a : b;
}

/**
 * finds the height of the BST
 * @param  root pointer to the BST
 * @return height of BST
 * @note   this function is private to BST class
 *
*/
template <typename T>
int BST<T>::findHeightPrivate(Node *Thru){
    if(Thru == '\0')
        return -1;
    return maxOfTwo(findHeightPrivate(Thru->leftNode), findHeightPrivate(Thru->rightNode))+1;
}

/**
 * finds the height of the BST
 * @return height of BST
 * @note   it't only a wrapper function to findHeightPrivate function
 *
*/
template <typename T>
int BST<T>::findHeight(void){
    return findHeightPrivate(root);
}

/**
 * frees the BST after it's scope ends
 * @param  root pointer to the BST
 * @note  this function is private to the BST class, it's only called in the destructor
 *
*/
template <typename T>
void BST<T>::freeBST(Node *Thru){
    if(Thru != '\0'){
        freeBST(Thru->leftNode);
        freeBST(Thru->rightNode);
    }
    else if(Thru == '\0')
        return;
    delete Thru;
}

/**
 * @return the root pointer to BST
 *
*/
template <typename T>
typename BST<T>::Node *BST<T>::returnRoot(void){
    return root;
}

