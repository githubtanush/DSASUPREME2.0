//next smallest element find krna matlab simply hmm ek kaam kr skta hai
//ki rightmost jaatein jaatein dekhenege ki us right ke liye smallest 
//element kon sa hai or vohi note krte jaayenge
//or agr smaller element nhi mila rightmost jaata jaata to hm -1 likh lenge

//brute force har ek element ke liye pura check krke aao 
//pura iterate kro first element ka liye n-1 comparison 
//aise hi krte jao or last element ka liye 1 comparison jo reh gya
//voh kro

//but agr mein ek stack ka use kru or direction right to left krdu to 
//vhi kaam easily ho jayga 
// har element single time stack mein aayga or pop ho jayga

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextsmallerelement(vector<int>& arr,vector<int>& ans){
    stack<int> st;
    st.push(-1);

    //loop iterate kro
    for(int i = arr.size()-1 ; i>=0 ;i--){
        int curr = arr[i];
        //answer find kro curr ke liye
        while(st.top() >= curr) st.pop();

        //store the element in answer
        ans[i] = st.top();

        //push current element into the stack 
        st.push(curr);
    }
    //answer return krdo
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements that u want to take : ";
    cin>>n;
    vector<int> v(n); 
    for(int i = 0; i < n;i++) cin>>v[i];
    vector<int> ans(n);
    nextsmallerelement(v,ans);
    for(int i : ans) cout<<i<<" ";
    return 0;
}
// 8 4 6 2 3