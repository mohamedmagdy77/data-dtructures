#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED


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
};

#include "BinarySearchTree.cpp"


#endif // BINARYSEARCHTREE_H_INCLUDED
