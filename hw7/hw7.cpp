
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ArgumentManager.h"
#include "AVL.h"

using namespace std;

int main(int argc, char** argv) {
    ArgumentManager args;

    if (argc == 4) {
        args.parse(argc, argv);
    } else if (argc == 2) {

        args.parse(argv[1]);
    }

    string inputFileName = args.get("value");
    string commandFileName = args.get("command");
    string outputFileName = args.get("output");

    ifstream inputFile(inputFileName.c_str());
    ifstream commandFile(commandFileName.c_str());
    fstream  outputFile(outputFileName.c_str(),ios::out);

    if (!inputFile.is_open()) {
        cout << "Unable to open " << inputFileName << " file";
        exit(0);
    }

    if (!commandFile.is_open()) {
        cout << "Unable to open " << commandFileName << " file";
        exit(0);
    }

    AVL avlTree;
    
    string inputLine;
    while (getline(inputFile, inputLine)) {

        if (inputLine.size() == 0) // empty line ,
            continue; // in that case , continue with next line

      //  cout << line << endl;

        string token;
        std::istringstream tokenStream(inputLine);
        while (std::getline(tokenStream, token, ' ')) {
           // cout << token << endl;
            avlTree.insert(stoi(token)) ;
        }

    }
    inputFile.close() ;
     
    string commandLine;
    while (getline(commandFile, commandLine)) {

        if (commandLine.size() == 0) // empty line ,
            continue; // in that case , continue with next line
      
        
      //  cout << commandLine << endl;
        std::istringstream commandLineStream(commandLine);
        string first, second ;
        commandLineStream>>first>>second ;
        if (first.compare("Inorder")==0)
            avlTree.inorderTraversal(outputFile);
        else if (first.compare("Preorder")==0)
            avlTree.preorderTraversal(outputFile);
        else if (first.compare("Postorder")==0)
            avlTree.postorderTraversal(outputFile);
        else if (first.compare("Level")==0)
            avlTree.printGivenLevel(stoi(second),outputFile) ;
    }

   
    commandFile.close();
    outputFile.close() ;
    
    return 0;
}