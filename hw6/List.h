
#ifndef LIST_H
#define LIST_H


#include<string>
#define MAX_SIZE 1000

using namespace std;

class List
{
    
private :
    int s;
    string books[MAX_SIZE] ;
public  :
    List()
    {
        s = 0 ;
    }    
    bool empty() 
    {
        return false ;
    }
    
    int size()
    {
        return s  ;
    }
    
    void insert(string x , int pos) 
    {
        if ( ( pos < 0 || pos > MAX_SIZE-1) || s == MAX_SIZE)
            return ;
        else
        {
            if (s == 0)
                 books[0] = x ; 
            else if (pos == s)
                 books[s] = x ;
            else
            {
               for (int i = s ; i > pos ; i--)
                   books[i] = books[i-1] ;
                books[pos] = x ; 
            }
                        
            s++ ;
        }
    }
    
    
    string remove(int pos, bool &success) 
    {
        
        success = true  ;        
        string book  ; 
        if (  s == 0 || pos < 0 || pos > s-1  )            
            success = false ;
        else
        {
           book =  books[pos] ;
           
           for (int i = pos ; i < s ; i ++ )
                  books[i] = books[i+1] ;
           
           books[s-1].clear()  ; // remove last elent
           s-- ;
        }
        
        return book ;
        
    }
    
    string retrieve(int pos, bool &success)     
    {
        success = true  ;
        
        string book  ; 
        if ( ( pos < 0 || pos > 9999 ) || pos > s-1 )            
            success = false ;
        else        
           book =  books[pos] ;
                             
        return book  ;
    }
    
};


#endif /* LIST_H */

