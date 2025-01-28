//brute force of previous  smaller element then mere ko saara 
//pura pura check krna pdega left se right mein to n-1 comparison
//then n-2 comparison aise bhut comparison honge
// to yeh gndi approach to hm use nhi hi krenge

//kya mein yeh keh skta hu previous smaller element mein leftmost ka answer hmesha -1 hoga
//aise hi mein saara left se right jaata hua smaller element nikalunga

#include<iostream>
#include<vector>
using namespace std;
vector<int> prevsmallerelement(vector<int>& arr,vector<int>& ans){
    stack<int> st;
    st.push(-1);

    //loop iterate kro
    for(int i = 0 ; i < arr.size() ;i++){
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
    cout<<"Enter the number of elements that u want to take in the array : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];

    vector<int> ans(n);
    prevsmallerelement(v,ans);
    for(int i : ans) cout<<i<<" ";
    return 0;
}
// 8 4 6 2 3