//
// Created by Jake Gill on 9/28/2023.
//

#include "AVLTree.h"

//-------- struct Node --------//
AVLTree::Node::Node(int& id, string& name) {
    this->studentID = id;
    this->studentName = name;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

//-------- Public AVLTree Functionality --------//
bool AVLTree::insert(int studentID, string studentName) {
    this->root = insertHelper(this->root, studentID, studentName);
    if (this->root)
        return true;
    else
        return false;
}

void AVLTree::printPreorder() {
    string outputString;
    preOrderHelper(this->root, outputString);
    if (!outputString.empty()) {
        outputString = outputString.substr(0, outputString.length() - 2); // Remove last comma
    }
    cout << outputString << endl;
}

void AVLTree::printInorder() {
    string outputString;
    inOrderHelper(this->root, outputString);
    if (!outputString.empty()) {
        outputString = outputString.substr(0, outputString.length() - 2);
    }
    cout << outputString << endl;
}

void AVLTree::printPostorder() {
    string outputString;
    postOrderHelper(this->root, outputString);
    if (!outputString.empty()) {
        outputString = outputString.substr(0, outputString.length() - 2);
    }
    cout << outputString << endl;
}

void AVLTree::printLevelCount() {
    if (root)
        cout << root->height << endl;
    else
        cout << "0" << endl;
}

bool AVLTree::searchName(string studentName) {
    return searchNameHelper(this->root, studentName);
}

bool AVLTree::searchID(int id) {
    if (searchIDHelper(this->root, id)) {
        cout << searchIDHelper(this->root, id)->studentName << endl;
        return true;
    }
    else {
        cout << "unsuccessful" << endl;
        return false;
    }
}

bool AVLTree::remove(int id) {
    bool successfulRemoval = false;
    this->root = removeHelper(this->root, id, successfulRemoval);
    calcBalanceFactor(this->root);
    updateHeight(this->root);
    return successfulRemoval;
}

bool AVLTree::removeInOrder(int N) {
    bool successfulRemoval = false;
    int traversalCount = 0;
    removeInOrderHelper(this->root, traversalCount, N, successfulRemoval);
    return successfulRemoval;
}

//-------- Private Helper Functions --------//
int AVLTree::getHeight(Node* head) {
    return (head) ? head->height : 0;
}

void AVLTree::updateHeight(Node* head) {
    if (head) {
        head->height = 1 + max(getHeight(head->left), getHeight(head->right));
    }
}

int AVLTree::calcBalanceFactor(Node* head) {
    if (!head) return 0;
    int leftHeight = (head->left) ? head->left->height : 0;
    int rightHeight = (head->right) ? head->right->height : 0;
    return leftHeight - rightHeight;
}

AVLTree::Node* AVLTree::rotateLeft(Node* head) {
    Node* grandChild = head->right->left;
    Node* newParent = head->right;
    newParent->left = head;
    head->right = grandChild;

    updateHeight(head);
    updateHeight(newParent);

    return newParent;
}

AVLTree::Node* AVLTree::rotateRight(Node* head) {
    Node* grandChild = head->left->right;
    Node* newParent = head->left;
    newParent->right = head;
    head->left = grandChild;

    updateHeight(head);
    updateHeight(newParent);

    return newParent;
}

AVLTree::Node* AVLTree::insertHelper(Node* head, int& studentID, string& studentName) {
    if (head == nullptr) {
        return new Node (studentID, studentName);
    }
    else if (studentID < head->studentID) {
        head->left = insertHelper(head->left, studentID, studentName);
    }
    else {
        head->right = insertHelper(head->right, studentID, studentName);
    }
    updateHeight(head);

    int balanceFactor = calcBalanceFactor(head);
    if (balanceFactor < -1) {
        if (calcBalanceFactor(head->right) > 0) {
            head->right = rotateRight(head->right);
            head = rotateLeft(head);
        }
        else {
            head = rotateLeft(head);
        }
    }
    else if (balanceFactor > 1) {
        if (calcBalanceFactor(head->left) < 0) {
            head->left = rotateLeft(head->left);
            head = rotateRight(head);
        }
        else {
            head = rotateRight(head);
        }
    }
    return head;
}

void AVLTree::preOrderHelper(Node* head, string& outputString) {
    if (head == nullptr) return;
    outputString += head->studentName + ", ";
    preOrderHelper(head->left, outputString);
    preOrderHelper(head->right, outputString);
}

void AVLTree::inOrderHelper(Node* head, string& outputString) {
    if (head == nullptr) return;
    inOrderHelper(head->left, outputString);
    outputString += head->studentName + ", ";
    inOrderHelper(head->right, outputString);
}

void AVLTree::postOrderHelper(Node* head, string& outputString) {
    if (head == nullptr) return;
    postOrderHelper(head->left, outputString);
    postOrderHelper(head->right, outputString);
    outputString += head->studentName + ", ";
}

AVLTree::Node* AVLTree::searchIDHelper(Node* head, int id) {
    if (!head) {
        return nullptr;
    }
    if (head->studentID == id) {
        return head;
    }
    else if (id < head->studentID) {
        return searchIDHelper(head->left, id);
    }
    else {
        return searchIDHelper(head->right, id);
    }
}

bool AVLTree::searchNameHelper(Node* head, string name) {
    if (!head) {
        return false;
    }

    bool foundLeft = searchNameHelper(head->left, name);
    bool foundCurrent = (head->studentName == name);
    bool foundRight = searchNameHelper(head->right, name);

    if (foundCurrent) {
        cout << head->studentID << endl;
    }

    return foundLeft || foundCurrent || foundRight;
}

AVLTree::Node* AVLTree::removeHelper(Node* head, int id, bool& successfulRemoval) {
    if (!head) return head;

    if (id < head->studentID) {
        head->left = removeHelper(head->left, id, successfulRemoval);
    }
    else if (id > head->studentID) {
        head->right = removeHelper(head->right, id, successfulRemoval);
    }
    else {
        successfulRemoval = true;
        if (!head->left || !head->right) {
            Node* tempNode = head->left ? head->left : head->right;

            if (!tempNode) {
                delete head;
                return nullptr;
            }
            else {
                head->studentID = tempNode->studentID;
                head->studentName = tempNode->studentName;
                if (head->left == tempNode) {
                    head->left = tempNode->left ? tempNode->left : tempNode->right;
                } else {
                    head->right = tempNode->left ? tempNode->left : tempNode->right;
                }
                delete tempNode;
            }
        }
        else {
            Node* tempNode = head->right;
            while (tempNode->left) {
                tempNode = tempNode->left;
            }
            int successorID = tempNode->studentID;
            string successorName = tempNode->studentName;
            head->right = removeHelper(head->right, successorID, successfulRemoval);
            head->studentID = successorID;
            head->studentName =successorName;
        }

        updateHeight(head);
        int balance = calcBalanceFactor(head);
        if (balance > 1) {
            if (calcBalanceFactor(head->left) < 0) {
                head->left = rotateLeft(head->left);
            }
            head = rotateRight(head);
        }
        else if (balance < -1) {
            if (calcBalanceFactor(head->right) > 0) {
                head->right = rotateRight(head->right);
            }
            head = rotateLeft(head);
        }
    }
    return head;
}

bool AVLTree::removeInOrderHelper(Node*& head, int& traversalCount, int N, bool& successfulRemoval) {
    if (!head)
        return false;

    if (removeInOrderHelper(head->left, traversalCount, N, successfulRemoval))
        return true;

    if (traversalCount == N) {
        head = removeHelper(head, head->studentID, successfulRemoval);
        return true;
    }
    traversalCount++;

    return removeInOrderHelper(head->right, traversalCount, N, successfulRemoval);
}

void AVLTree::destructorHelper(Node* head) { // Post order
    if (head == nullptr) return;
    destructorHelper(head->left);
    destructorHelper(head->right);
    delete head;
}

AVLTree::~AVLTree() {
    destructorHelper(this->root);
}
