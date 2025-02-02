//count the reversal or minimum bracket reversal 
//string which consisting of only opening and closing bracket
// ()() => (())
// s = ")(())(((" => balanced string => ((())())
// (( => same character () -> 1
// )( => difference character 
// 3
//valid parenthesis nikalna ka liye mein stack use krta hu 
//kyuki yeh hme pair mein return krta

//valid parenthesis logic will be used -> I will removed valid pairs
//if stack is non-empty we will try to find reversal count
// )(())((( => 8 even pairs
// ((( => if odd size string return -1



// if ch == '(' push else if(s.empty == 0 && st.top()='(') st.pop();
// else push('ch')
  

// (( => same character -> () -> 1
// )( => different character -> () -> count 2
// ( => same character count += 1
// )( => count += 2;
#include<iostream>
using namespace std;
int countrev(string s){
    //if odd sized string then impossible to make pairs
    if(s.size() & 1) return -1;

    int ans = 0;
    stack<char> st;// character type ka stack bna liya 
    for(char ch : s){
        if(ch == '{') st.push(ch); // agr character apka opening bracket hai push krdo 
        else{
            if(!st.empty() && st.top() == '{') st.pop(); // agr stack empty nhi hai or uska stack ke top par opening braces hai to pair krdo
            else st.push(ch);//stack is still not empty 
        }
    }
    //if stack is still not empty, let's count reversals
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        if(a == b) ans += 1;
        else ans += 2;
    }
    return ans;
}
int main(){
    //string leni hai
    string s;
    //input lena s string ke andar
    getline(cin,s);
    int ans = countrev(s);
    cout<<"The reversible string is : "<<ans<<endl;
    return 0;
}

// }{{}}}}}
//{}}{{{