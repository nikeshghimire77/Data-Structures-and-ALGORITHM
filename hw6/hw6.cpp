
#include <cstdlib>
#include "Stack.cpp"
#include "Queue.cpp"
#include "ArgumentManager.h"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*
 * 
 */
void printStack(Stack &s) 
{
     bool flag ;
    for (int i = 0 ; i < s.size() ; i ++)
        cout<<i+1<<" |  " <<s.retrieve(s.size()-1-i,flag)<<" | " <<endl;
     cout<<endl ;
}
void printQueue(Queue &q)
{
    bool flag ;
    for (int i = 0 ; i < q.size() ; i ++)
        cout<<i+1<<" "<<q.retrieve(i,flag)<<" | " <<endl;
    cout<<endl ;
}
int main(int argc, char** argv) {

    ArgumentManager args;
    Stack stack;
    Queue queue;

    //    cout << "argc = " << argc;
    //    cout << " argv[0] =" << argv[0];
    //    cout << " argv[1] =" << argv[1];

    if (argc == 3) {
        args.parse(argc, argv);
    } else if (argc == 2) {

        args.parse(argv[1]);
    }

    string inputFileName = args.get("input");
    string outputFileName = args.get("output");

    // cout<<"\n inputFile = "<<inputFile<<" - outputFile = "<<outputFile<<endl ;

    ifstream inFile(inputFileName.c_str());
    ofstream outFile(outputFileName.c_str());

    string line;

    if (!inFile.is_open()) {
        cout << "Unable to open " << inFile << " file";
        exit(0);
    }
    string command, book;
    bool success;
    int stackCost, queueCost;

    while (getline(inFile, line)) {
        
        if (line.size() == 0 )  // empty line ,
            continue ; // in that case , continue with next line
        
        stackCost = 0;
        queueCost = 0;

        command = line.substr(0, line.find(" "));
        book = line.substr(line.find(" "), line.length());
     //   cout<<command<<" -- >"<<book<<endl ;
        
         if (command.compare("buy") == 0) {
            
                stack.push(book);
                queue.enqueue(book);
                
                
            } else if (command.compare("sale") == 0) {                              
               
               
                string topBook;
                string tempStack[stack.size()];
                int tempStackSize=0 ;
                bool found = false;
                int stackSize = stack.size();
                
                 for (int i = 0; i < stackSize; i++) {
                     
                   topBook = stack.top();
                   stack.pop();
                   stackCost++ ;
                    
                   if (book.compare(topBook) != 0) {
                        tempStack[tempStackSize++] = topBook;
                   }
                   else
                   {
                       found = true;
                        for (int j = 0; j < tempStackSize ; j ++) 
                              stack.push(tempStack[j]);                           
                        
                        break;
                   }
                 }
                
               
             
               
               if (!found) {
                       // after the unsuccessful search, the whole stack will reverse                                         
                        for (int j = 0; j < tempStackSize ; j ++) 
                              stack.push(tempStack[j]);                         
                      //  cout << book << " not found" << endl;
                        outFile << book << " not found" << endl;
                        continue;
                    }
                
              string frontBook;
              int queueSize = queue.size() ;
                
               string tempQueue[queueSize];
              
               int tempQueueSize= 0 ;;
               found = false;
                for (int i = 0; i < queueSize; i++) {
                    frontBook = queue.front();
                    queue.dequeue() ;   
                    queueCost ++ ;
                    if (book.compare(frontBook) != 0) {
                        tempQueue[tempQueueSize++]=frontBook;
                    } else {
                        found = true;
                        for (int j = 0; j < tempQueueSize; j++) {
                            queue.enqueue(tempQueue[j]);                           
                        }
                        break;
                    }
                }
               
               // cout <<book << "finding cost at stack: " << stackCost  << ", at queue: " << queueCost << endl;
               outFile <<book << "finding cost at stack: " << stackCost  << ", at queue: " << queueCost << endl;
            }
      
        
       
    }
    inFile.close();
    outFile.close() ;
    return 0;

}

