#include<iostream>
#include<vector>
using namespace std;
bool checksorted(vector<int>& v,int index){
    //base case
    if(index >= v.size()) return true;

    //processing
    if(v[index] > v[index-1]){
        //aaga check krna pdega
        //by recursion
        bool aagakaans = checksorted(v,index+1);
        return aagakaans;
    } 
    else{
        //sorted nhi hai 
        //to return false
        return false;
    }

}
int main(){
    int n;
    cout<<"Enter the number of elements you want to take : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++) cin>>v[i];
    bool issorted = checksorted(v,1);
    if(issorted) cout<<"Array is sorted"<<endl;
    else cout<<"Array is not sorted"<<endl;
    return 0;
}