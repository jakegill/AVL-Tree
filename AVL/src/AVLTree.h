//
// Created by Jake Gill on 9/28/2023.
//
#ifndef AVL_AVL_H
#define AVL_AVL_H
#include <string>
#include <iostream>
using namespace std;

class AVLTree {
private:
    struct Node {
        string studentName;
        int studentID;
        Node* left;
        Node* right;
        int height;
        Node(int& id, string& name);
    };
    Node* root = nullptr;

    /*---- Helper functions ----*/
    int getHeight(Node* head);
    void updateHeight(Node* head);
    int calcBalanceFactor(Node* head);
    Node* rotateLeft(Node* head);
    Node* rotateRight(Node* head);
    Node* insertHelper(Node* head, int& studentID, string& studentName);
    void preOrderHelper(Node* head, string& outputString);
    void inOrderHelper(Node* head, string& outputString);
    void postOrderHelper(Node* head, string& outputString);
    Node* searchIDHelper(Node* head, int studentID);
    bool searchNameHelper(Node* head, string studentName);
    Node* removeHelper(Node* head, int id, bool& successfulRemoval);
    bool removeInOrderHelper(Node*& head, int& traversalCount, int N, bool& successfulRemoval);
    void destructorHelper(Node* head);

public:
    /*---- Functionality ----*/
    bool insert(int studentID, string studentName);
    void printPreorder();
    void printInorder();
    void printPostorder();
    void printLevelCount();
    bool searchID(int id);
    bool searchName(string name);
    bool remove(int id);
    bool removeInOrder(int n);
    ~AVLTree();
};
#endif //AVL_AVL_H