#include "List.h"
#include<string>
using namespace std;

class Stack : public List
{
    public:
        void push(string book) 
        {
            insert(book , size() ) ;
        }
        void pop()
        {
             bool success = false ;
             remove(size()-1,success) ;  
        }
        string top()
        {
            bool success = false ;
            return retrieve(size()-1,success) ;
        }

    private:
};

