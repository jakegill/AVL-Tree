#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//
//TEST_CASE("Five incorrect Commands", "[AVLTree, Parser]") {
//    AVLTree tree;
//    Parser parsedInput;
//    REQUIRE(parsedInput.executeCommand(tree, "insert \"A11y\" 45679999") == false);
//    REQUIRE(parsedInput.executeCommand(tree, "insert 45679999 \"A11y\"") == false);
//    REQUIRE(parsedInput.executeCommand(tree, "remove \"John\"") == false);
//    REQUIRE(parsedInput.executeCommand(tree, "insert \"A11y\" 45679999") == false);
//    REQUIRE(parsedInput.executeCommand(tree, "insert \"Jake\" 123") == false);
//}
//
//TEST_CASE("Edge Cases", "[AVLTree, Parser]") {
//    AVLTree tree;
//    Parser parsedInput;
//    REQUIRE(parsedInput.executeCommand(tree, "remove 45674567") == false); //Non-existent node.
//    REQUIRE(parsedInput.executeCommand(tree, "search 45674567") == false);
//    REQUIRE(parsedInput.executeCommand(tree, "printLevelCount") == true); // Empty tree should be 0.
//}
//
//TEST_CASE("Rotation Cases", "[AVLTree, Parser]") {
//    AVLTree LLtree; //Right Rotation
//    Parser parsedInput;
//    REQUIRE(parsedInput.executeCommand(LLtree, "insert \"Right\" 30000000") == true);
//    REQUIRE(parsedInput.executeCommand(LLtree, "insert \"Root\" 20000000") == true);
//    REQUIRE(parsedInput.executeCommand(LLtree, "insert \"Left\" 10000000") == true);
//    cout << "Right rotation, expect output: Left, Root, Right. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(LLtree, "printInorder") == true);
//
//    AVLTree RRtree; //Left Rotation
//    REQUIRE(parsedInput.executeCommand(RRtree, "insert \"Left\" 10000000") == true);
//    REQUIRE(parsedInput.executeCommand(RRtree, "insert \"Root\" 20000000") == true);
//    REQUIRE(parsedInput.executeCommand(RRtree, "insert \"Right\" 30000000") == true);
//    cout << "Left rotation, expect output: Left, Root, Right. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(RRtree, "printInorder") == true);
//
//
//    AVLTree LRtree; // Left-Right Rotation
//    REQUIRE(parsedInput.executeCommand(LRtree, "insert \"Right\" 30000000") == true);
//    REQUIRE(parsedInput.executeCommand(LRtree, "insert \"Left\" 10000000") == true);
//    REQUIRE(parsedInput.executeCommand(LRtree, "insert \"Root\" 20000000") == true);
//    cout << "Left-Right rotation, expect output: Left, Root, Right. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(LRtree, "printInorder") == true);
//
//
//    AVLTree RLtree; // Right-Left Rotation
//    REQUIRE(parsedInput.executeCommand(RLtree, "insert \"Left\" 10000000") == true);
//    REQUIRE(parsedInput.executeCommand(RLtree, "insert \"Right\" 30000000") == true);
//    REQUIRE(parsedInput.executeCommand(RLtree, "insert \"Root\" 20000000") == true);
//    cout << "Right-Left rotation, expect output: Left, Root, Right. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(RLtree, "printInorder") == true);
//}
//
//TEST_CASE("Deletion Cases", "[AVLTree, Parser]") {
//    Parser parsedInput;
//
//    AVLTree noChild; // Leaf Node
//    REQUIRE(parsedInput.executeCommand(noChild, "insert \"Head\" 20000000") == true);
//    REQUIRE(parsedInput.executeCommand(noChild, "insert \"Left\" 10000000") == true);
//    REQUIRE(parsedInput.executeCommand(noChild, "remove 10000000") == true);
//    cout << "Leaf node deletion, expected output: Head. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(noChild, "printInorder"));
//
//    AVLTree oneChild; //
//    REQUIRE(parsedInput.executeCommand(oneChild, "insert \"Head\" 40000000") == true);
//    REQUIRE(parsedInput.executeCommand(oneChild, "insert \"Left\" 30000000") == true);
//    REQUIRE(parsedInput.executeCommand(oneChild, "insert \"Right\" 50000000") == true);
//    REQUIRE(parsedInput.executeCommand(oneChild, "insert \"SubRight\" 60000000") == true);
//    REQUIRE(parsedInput.executeCommand(oneChild, "remove 50000000") == true);
//    cout << "Single child deletion, expected output: Left, Head, SubRight. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(oneChild, "printInorder"));
//
//    AVLTree twoChild; // Delete Root with two children
//    REQUIRE(parsedInput.executeCommand(twoChild, "insert \"Head\" 20000000") == true);
//    REQUIRE(parsedInput.executeCommand(twoChild, "insert \"Left\" 10000000") == true);
//    REQUIRE(parsedInput.executeCommand(twoChild, "insert \"Right\" 30000000") == true);
//    REQUIRE(parsedInput.executeCommand(twoChild, "remove 20000000") == true);
//    cout << "Two children deletion, expected output: Left, Right. Actual output: ";
//    REQUIRE(parsedInput.executeCommand(twoChild, "printInorder"));
//}
//
//TEST_CASE("Bulk Insert and Remove", "[AVLTree, Parser]") {
//    AVLTree tree;
//    Parser parsedInput;
//    string numbers[100] = {
//            "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
//            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty",
//            "TwentyOne", "TwentyTwo", "TwentyThree", "TwentyFour", "TwentyFive", "TwentySix", "TwentySeven", "TwentyEight", "TwentyNine", "Thirty",
//            "ThirtyOne", "ThirtyTwo", "ThirtyThree", "ThirtyFour", "ThirtyFive", "ThirtySix", "ThirtySeven", "ThirtyEight", "ThirtyNine", "Forty",
//            "FortyOne", "FortyTwo", "FortyThree", "FortyFour", "FortyFive", "FortySix", "FortySeven", "FortyEight", "FortyNine", "Fifty",
//            "FiftyOne", "FiftyTwo", "FiftyThree", "FiftyFour", "FiftyFive", "FiftySix", "FiftySeven", "FiftyEight", "FiftyNine", "Sixty",
//            "SixtyOne", "SixtyTwo", "SixtyThree", "SixtyFour", "SixtyFive", "SixtySix", "SixtySeven", "SixtyEight", "SixtyNine", "Seventy",
//            "SeventyOne", "SeventyTwo", "SeventyThree", "SeventyFour", "SeventyFive", "SeventySix", "SeventySeven", "SeventyEight", "SeventyNine", "Eighty",
//            "EightyOne", "EightyTwo", "EightyThree", "EightyFour", "EightyFive", "EightySix", "EightySeven", "EightyEight", "EightyNine", "Ninety",
//            "NinetyOne", "NinetyTwo", "NinetyThree", "NinetyFour", "NinetyFive", "NinetySix", "NinetySeven", "NinetyEight", "NinetyNine", "OneHundred"
//    };
//    for (int i = 10000001; i <= 10000100; ++i) {
//        tree.insert(i, numbers[i-10000001]);
//    }
//    REQUIRE(parsedInput.executeCommand(tree, "printInorder")); // Should read like a number line from 1-100
//    random_device numberGenerator;
//    mt19937 gen(numberGenerator());
//    uniform_int_distribution<> dis(10000001, 10000100);
//    for (int i=0; i<10; i++) {
//        int randomStudentID = dis(gen);
//        string command = "remove " + to_string(randomStudentID);
//        parsedInput.executeCommand(tree, command);
//    }
//    REQUIRE(parsedInput.executeCommand(tree, "printInorder")); // Should read like a number line despite with some missing values.
//}