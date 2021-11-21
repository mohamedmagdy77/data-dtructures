#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BST<char> bt1;
    bt1.insertNode('F');
    bt1.insertNode('D');
    bt1.insertNode('J');
    bt1.insertNode('B');
    bt1.insertNode('E');
    bt1.insertNode('G');
    bt1.insertNode('K');
    //bt1.insertNode('A');
    bt1.insertNode('C');
    bt1.insertNode('I');
    bt1.insertNode('H');
    bt1.insertNode('A');
    std::cout << "level order: ";
    bt1.levelOrderTraversal();
    std::cout << "pre order  : ";
    bt1.PreOrderTraversal(bt1.returnRoot());
    std::cout << std::endl;
    std::cout << "in order   : ";
    bt1.InOrderTraversal(bt1.returnRoot());
    std::cout << std::endl;
    std::cout << "post order : ";
    bt1.PostOrderTraversal(bt1.returnRoot());
    std::cout << std::endl;
    bt1.init_qr();
    std::cout << "level order recursion: ";
    bt1.levelOrderTraversalRecursive();
    std::cout << std::endl;
    return 0;
}
