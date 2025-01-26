#include<iostream>
#include<vector>
using namespace std;
// void printdigits(int n){
//     //base case
//     if(n == 0) return ;

//     //doing head recursion we in these because we first printing 4 then 2 
//     // then 1 then 5
//     //recursive relation


//     //processing
//     int digit = n % 10;
//     //update the n
//     n = n/10;

//     //recursive call
//     printdigits(n);

//     //processing
//     cout<<digit<<endl;

// }


// void printdigits(int n,vector<int>& ans){
//     //base case
//     if(n == 0) return ;

//     //doing head recursion we in these because we first printing 4 then 2 
//     // then 1 then 5
//     //recursive relation


//     //processing
//     int digit = n % 10;
//     //update the n
//     n = n/10;

//     //recursive call
//     printdigits(n,ans);

//     //processing
//     ans.push_back(digit);
// }

//input - vector - 4217 then output number = 4217
void printnum(int n,vector<int>& ans,int& num,int index){
    //base case
    if(index>=ans.size()) return ;

    //processing
    num = num * 10 + ans[index];

    //recursive relation
    printnum(n,ans,num,index+1);
}
int main(){
    // int n;
    // cout<<"Enter the number : ";
    // cin>>n;
    // // printdigits(n);
    // vector<int> ans;
    // // printdigits(n,ans);
    // for(int i : ans) cout<<i<<" ";

    int n;
    cout<<"Enter the number of elements you want to take : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    int num = 0;
    printnum(n,v,num,0);
    cout<<"The number is : "<<num<<endl;
    return 0;
}