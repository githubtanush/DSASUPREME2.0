#include <iostream>
using namespace std;
long merge(vector<int>& v,vector<int>& temp,int s,int mid,int e){
    int i = s;
    int j = mid + 1;
    int k = s;
    long c = 0;

    while(i <= mid && j <= e){
        if(v[i]<=v[j]) temp[k++] = v[i++];
        else{
        temp[k++] = v[j++]; // v[i] > v[j] inversion count ka case hai 
        c += mid - i + 1;
        }
    }
    while(i<=mid) temp[k++] = v[i++];
    while(j<=e) temp[k++] = v[j++];

    while(s <= e){
        v[s] = temp[s];
        ++s;
    }
    return c;
}
long mergesort(vector<int>& v,vector<int>& temp, int s,int e){
    if(s >= e) return 0;
    int mid = s + ( e - s )/2;
    long c = 0;
    c += mergesort(v,temp,s,mid);
    c += mergesort(v,temp,mid+1,e);
    c += merge(v,temp,s,mid,e);
    return c;
}
long countinversion(vector<int>& v){
    //Method 1 - brute approach 
    // we know time complexity is more O(N^2)
    // so we want to reduce the time complexity of the problem
    // int count = 0;  
    // for(int i = 0; i < v.size();i++){
    //     for(int j = i + 1; j < v.size();j++){
    //         count = v[i] > v[j] ? count + 1 : count;
    //     }
    // }
    // return count;

    //Method 2 - we solve it like merge sort we break (8,4,2,1)  to (8,4,2,1)
    // into (8,4) and (2,1) merge this - (4,8) and (1,2) so we merge (4,8,1,2)
    // then 8 , 4 , 2 , 1 is left only

    // kyuki return mujhe ek long hi krna hai 
    long c = 0; // store inversion count in this
    // when we do merge sort so we need a temporary array initialize with 0
    vector<int> temp(v.size(),0);
    c = mergesort(v,temp,0,v.size()-1);
    for(int i = 0; i < v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return c;
}
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    cout<<"Total number of inversions we want to do is : "<<countinversion(arr);

    return 0;
}
// 2 1 3 1 2