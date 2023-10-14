//
// Created by Jake Gill on 9/28/2023.
//

#include "Parser.h"

bool Parser::executeCommand(AVLTree& myAVLTree, const string& line) {
    istringstream in(line);
    string command;
    in >> command;

    if (command == "insert") {
        string studentName;
        char firstQuote;

        in >> firstQuote;
        if (firstQuote == '\"') {
            getline(in, studentName, '\"');
        }
        else {
            cout << "unsuccessful" << endl;
            return false;
        }

        string studentId;
        in >> studentId;

        if (regex_match(studentName, verifyName) && regex_match(studentId, verifyID)) {
            studentName.erase(remove(studentName.begin(), studentName.end(), '\"'), studentName.end());
            if (myAVLTree.insert(stoi(studentId), studentName)) {
                cout << "successful" << endl;
                return true;
            }
            else {
                cout << "unsuccessful" << endl;
                return false;
            }
        }
        else {
            cout << "unsuccessful" << endl;
            return false;
        }
    }
    else if (command == "remove") {
        string studentId;

        in >> studentId;
        if (regex_match(studentId, verifyID)) {
            if (myAVLTree.remove(stoi(studentId))) {
                cout << "successful" << endl;
                return true;
            }
            else {
                cout << "unsuccessful" << endl;
                return false;
            }
        }
        else {
            cout << "unsuccessful" << endl;
            return false;
        }
    }
    else if (command == "search") {
        string studentNameOrID;
        char firstQuote;

        in >> firstQuote;
        if (firstQuote == '\"') {
            getline(in, studentNameOrID, '\"');
            if (regex_match(studentNameOrID, verifyName)) {
                studentNameOrID.erase(remove(studentNameOrID.begin(), studentNameOrID.end(), '\"'), studentNameOrID.end());
                if (!myAVLTree.searchName(studentNameOrID))
                    cout << "unsuccessful" << endl;
            } else {
                cout << "unsuccessful" << endl;
                return false;
            }
        } else {
            in.putback(firstQuote);
            in >> studentNameOrID;
            if (regex_match(studentNameOrID, verifyID)) {
                return myAVLTree.searchID(stoi(studentNameOrID));
            } else {
                cout << "unsuccessful" << endl;
                return false;
            }
        }
    }
    else if (command == "printInorder") {
        myAVLTree.printInorder();
        return true;
    }
    else if (command == "printPreorder") {
        myAVLTree.printPreorder();
        return true;
    }
    else if (command == "printPostorder") {
        myAVLTree.printPostorder();
        return true;
    }
    else if (command == "printLevelCount") {
        myAVLTree.printLevelCount();
        return true;
    }
    else if (command == "removeInorder") {
        try {
            int N;
            in >> N;
            if (myAVLTree.removeInOrder(N)) {
                cout << "successful" << endl;
            }
            else {
                cout << "unsuccessful" << endl;
            }
        }
        catch(invalid_argument &error) {
            cout << "unsuccessful" << endl;
        }
    }
    else {
        cout << "unsuccessful" << endl;
        return false;
    }
    return false;
}
