#include<iostream>
#include<vector>
using namespace std;
void printarray(vector<int>& v,int n,int index){
    //base case
    if(index >= n) return ;

    //processing
    cout<<v[index]<<" ";
    
    //recursive call
    printarray(v,n,index+1);

}
bool searchinarray(vector<int>& v,int target,int index){
    //base case
    if(index>=v.size()) return false;

    //processing
    if(v[index] == target) return true;

    //recursive call
    return searchinarray(v,target,index+1);
}
void minnumberinarray(vector<int>& v,int index,int& mini){
    //base case
    if(index >= v.size()) return ;

    //processing
    if(v[index] < mini) mini = v[index];

    //recursive call
    return minnumberinarray(v,index+1,mini);
}
void maxnumberinarray(vector<int>& v,int index,int& maxi){
    //base case
    if(index >= v.size()) return ;

    //processing
    if(v[index] > maxi) maxi = v[index];

    //recursive call
    return maxnumberinarray(v,index+1,maxi);
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
    cout<<"Enter the target for the array : ";
    cin>>target;
    printarray(v,n,0);
    bool ans = searchinarray(v,target,0);
    if(ans) cout<<"Element exists in the array "<<endl;
    else cout<<"Element does not exists in the array "<<endl;

    int mini = INT_MAX;
    minnumberinarray(v,0,mini);
    cout<<"Minimum number the array is : "<<mini<<endl;

    int maxi = INT_MIN;
    maxnumberinarray(v,0,maxi);
    cout<<"Maximum number in the array is : "<<maxi<<endl;
    return 0;
}
// 8
// 1 2 3 4 5 6 7 8