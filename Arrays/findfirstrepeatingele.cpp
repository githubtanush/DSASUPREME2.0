#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int findfirstrepeat(vector<int>& v){
    //Method 1 - brute force
    int n = v.size();
    // bool isRepeated = false;
    // for(int i = 0; i < n;i++){
    //     for(int j = i + 1; j < n;j++){
    //         if(v[i]==v[j]){
    //             isRepeated = true;
    //             return j;
    //         }
    //     }
    // }
    // return -1;

    //Method 2 - hashmap
    unordered_map<int,int> hash;
    for(int i = 0; i < n;i++){
        hash[v[i]]++;
    }
    for(int i = 0; i < n;i++){
        if(hash[v[i]]>1){
            return i+1;
        }
    }
    return -1;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int ans = findfirstrepeat(v);
    cout<<"First repeating element in the array is : "<<ans<<endl;
    return 0;
}
// 7
// 1 5 3 4 3 5 6
//index of first occurance that will be - 2