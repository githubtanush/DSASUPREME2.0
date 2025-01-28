//implement krna min stack
//minstack push / pop / top / getsize sab se sab operation O(1) mein krta
// chay koi se bhi operation ho vo sab O(1) mein kr deta


//question yeh keh rah we create one stack which is done push / pop /
// top or min in only O(1) time

//Minstack class 
//Minstack() - constructor
// push (vect) // top()
// pop()    // getmin()

//creating the pair by 
// pair<int,int> p = make_pair();
// p.first = 4;
// p.second = 5

//vector<pair<int,int> > means vector jiske andar do data store kr rah hu
//minimum element we define by the rightmost element
//mein rightmost element ke hisab se btaunga ki minimum element kya h?
// jab bhi top element maanga jayga  to pair ka first element
// return hoga lekin jab bhi minimum element maana jayga to pair ka second variable share kiya jayga

//agr make_pair likhna hai to mere ko shuru se hi pehle se hi 
// saari values insert krke deni hogi
// lekin agr make_pair use nhi kiya toh mujhe pair ka name.first 
//and then pair ka name.second yeh sb likh ke values insert krni hogi
 

#include<iostream>
#include<vector>
using namespace std;
class MinStack{
    public:
        vector<pair<int,int> > st;
        MinStack(){

        }

        void push(int val){
            if(st.empty()){
                //it means i am inserting the first element
                pair<int,int> p;
                p.first = val;
                p.second = val;
                st.push_back(p);
            }
            else{
                pair<int,int> p;
                p.first = val;
                int puranamin = st.back().second;
                p.second = min(puranamin,val);
                st.push_back(p);
            }
        }

        void pop(){
            //rightmost element ko pop krwa do 
            // par check kr lena element hai ya nhi 
            //kyuki ho skta hai na underflow hi ho jay
            st.pop_back();
        }
        
        int top(){
            pair<int,int> rightmostpair = st.back();
            return rightmostpair.first;
        }
        int getmin(){
            pair<int,int> rightmostpair = st.back();
            return rightmostpair.second;
        }

};
int main(){
    MinStack m; // here we created a minstack  
    return 0;  
}