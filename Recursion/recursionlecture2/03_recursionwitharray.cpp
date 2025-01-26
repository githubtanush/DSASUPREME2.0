#include<iostream>
#include<vector>
using namespace std;
void printeven(vector<int>& v,int index,vector<int>& ans){
    //base case
    if(index >= v.size()) return ;

    //processing
    if(v[index]%2==0) ans.push_back(v[index]);

    //recursive relation
    return printeven(v,index+1,ans);
}
// void printalloccurranceoftarget(vector<int>& v,int index,int target){
//     //base case
//     if(index >= v.size()) return ;

//     //processing
//     if(v[index] == target) cout<<index<<" ";

//     //recursive relation
//     return printalloccurranceoftarget(v,index+1,target);
// }
vector<int> printalloccurranceoftarget(vector<int>& v, int index,int target){
    //vector return krna esliye vector bnana pdega pehle
    vector<int> ans;

    //base case
    if(index >= v.size()) return ans;

    //processing
    if(v[index]==target) ans.push_back(index);
    
    //recursive relation
    vector<int> aagakaans = printalloccurranceoftarget(v,index+1,target);

    // Combine current results with the results from the recursion
    ans.insert(ans.end(), aagakaans.begin(), aagakaans.end());

    return ans; 
}
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int target;
    cout<<"Enter the target : ";
    cin>>target;
    vector<int> answer = printalloccurranceoftarget(v,0,target);
    for(int i : answer) cout<<i<<" ";
    cout<<endl;
    vector<int> ans;
    printeven(v,0,ans);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}
// 8
// 1 2 3 3 3 4 5 6