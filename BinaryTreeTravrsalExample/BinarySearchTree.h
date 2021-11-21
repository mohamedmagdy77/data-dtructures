#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "queue.h"

template <typename T>
class BST{
private:
    class Node{
    public:
        const T& data;
        Node *leftNode;
        Node *rightNode;
        Node(const T& idata): data(idata), leftNode('\0'), rightNode('\0'){}
    };
    Node *root;
    Queue<Node*> qr;
    void freeBST(Node *Thru);
    int findHeightPrivate(Node *Thru);
public:
    BST(): root('\0'){}
    ~BST(){
        freeBST(root);
    }
    void insertNode(const T& data);
    void searchElement(const T& data);
    const T& findMax(void);
    const T& findMin(void);
    int findHeight(void);
    Node *returnRoot(void);
    void init_qr(void);
    void levelOrderTraversalRecursive(void);
    void levelOrderTraversal(void);
    void PreOrderTraversal(Node *Thru);
    void InOrderTraversal(Node *Thru);
    void PostOrderTraversal(Node *Thru);
};

#include "BinarySearchTree.cpp"
#include "BinarySearchTraversal.cpp"


#endif // BINARYSEARCHTREE_H_INCLUDED
