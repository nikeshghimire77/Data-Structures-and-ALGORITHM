
#include "List.h"
#include<string>
using namespace std;

class Queue : public List
{
    public:
        void enqueue(string book) 
        {
            insert(book , 0 ) ;
        }
        void dequeue()
        {
             bool success = false ;
             remove(size()-1,success) ;  
        }
        string front()
        {
            bool success = false ;
            return retrieve(size()-1,success) ;
        }

    private:
};

