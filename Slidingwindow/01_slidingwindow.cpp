//fixed size window = 10 20 30 40 50 60 70
// window size = 2
// 10 20 / 20 30 / 30 40 / 40 50 / 50 60 / 60 70 
//kya mujhe pta hai meri pehli window gurrantedly utna size ki hi bnegi 

//2 Steps - 
// process first 'k' elements - initial state
// process remaining windows  - removal addition ans store

#include<iostream>
#include<vector>
#include<deque>
using namespace std;
// vector<int> maxslidingwindow(vector<int>& v, int k ){
//     deque<int> dq;// mujhe deque ki need pdegi
//     vector<int> ans; // mere ko answer mein store krna to yeh bhi rkhna pdega

//     // process first k elements 
//     for(int i = 0; i < k;i++){
//         // jo bhi number chote h current element se , unhe remove krdo
//         while(!dq.empty() && (v[dq.back()] < v[i])) dq.pop_back();

//         dq.push_back(i);
//     }
//     //storing answer for first window
//     ans.push_back(v[dq.front()]);

//     //process remaining windows 
//     for(int i = k ; i < v.size();i++){
//         //removal / addition / ans store
//         if(!dq.empty() && i-dq.front() >= k) dq.pop_front();
//         //addition 
//         while(!dq.empty() && v[dq.back()] < v[i]) dq.pop_back();

//         dq.push_back(i);
//         //ans store
//         ans.push_back(v[dq.front()]);
//     }
//     return ans;

// }

vector<int> maxslidingwindow(vector<int>& v,int& k){
    
}
int main(){
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int k ;
    cout<<"Enter the sliding window size : ";
    cin>>k;
    vector<int> ans = maxslidingwindow(v,k);
    return 0;
}