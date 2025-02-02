// In celebrity problem there is a person who known to all but does not know any one at the party 
// hme find krna hai celebrity hai ki nhi 
// hme ek square n * n matrix di gyi hai 
// if element of row i and column j set 

// 0 1 0
// 0 0 0
// 0 1 0
//M[0][1] means 0th person knows 1st person
//m[i][j] means ith person knows the jth person 


//Method 1 - Brute force
// A.) Celebrity -> row all 0's 
// && 
// B.) Celebrity -> columns all 1's -> column 1 means all knows celebrity except diagonal element

//Algorithm - check rows and cols for each person[0,n]
//for(i(person) -> n-1){ -> O(N)
// row->(a) -> O(N)                 => O(N^2);
// col->(b) -> O(N)
//}


//Method 2 - Algorithm 
// 1.) put all persons in stack 
// 2.) while(st.size() != 1) A -> st.top() B -> st.top();
// if(A knows B) // means A is not the celebrity discard A  and b to be pushed again
// else // B A ko janta to B to pkka celebrity nhi hai to B is discarded
// 3.) That single person in a stack might be a celebrity let's verify it 
#include<iostream>
using namespace std;
