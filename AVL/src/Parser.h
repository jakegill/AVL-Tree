//
// Created by Jake Gill on 9/28/2023.
//

#ifndef AVL_PARSER_H
#define AVL_PARSER_H
#include <regex>
#include <fstream>
#include <sstream>
#include "AVLTree.h"

class Parser {
private:
    regex verifyName;
    regex verifyID;
public:
    Parser() : verifyName("^[A-Za-z \"]+$"), verifyID("^\\d{8}$") {};
    bool executeCommand(AVLTree& tree, const string& line);
};

#endif //AVL_PARSER_H
