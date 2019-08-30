#include <iostream>
#include <queue>
using namespace std; 
  
void interleave(queue<int> &q) 
{ 
    queue <int> a;
    queue <int> b;
    int n = q.size();
    for( int i = 0 ; i < n/2 ; i++ ){
         a.push(q.front());
         q.pop();
    }
     for( int i = 0 ; i < n/2 ; i++ ){
         b.push(q.front());
         q.pop();
    }

    for( int i = 0 ; i < n/2 ; i++ ){
       q.push(a.front());
       q.push(b.front());
       a.pop();
       b.pop();
    }
} 
  
int main() 
{ 
    int n;
    cin >> n;
    queue<int> q; 
    for (int i = 0; i < n; i++)
    {
        int x ;
        cin >> x ;
        q.push(x);
    }  
           
    interleave(q); 
  
    for (int i = 0; i < n; i++) 
    { 
        cout << q.front() << endl ;
        q.pop();
    } 
} 