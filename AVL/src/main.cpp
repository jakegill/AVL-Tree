#include "AVLTree.h"
#include "Parser.h"

int main(){
    AVLTree myAVLTree;
    Parser parsedInput;
    string commandCount;
    getline(cin, commandCount);

    for (int i=0; i<stoi(commandCount); i++) {
        string line;
        getline(cin, line);
        parsedInput.executeCommand(myAVLTree, line);
    }

    return 0;
}

