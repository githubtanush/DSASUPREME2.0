#include<iostream>
#include<vector>
using namespace std;
int removeduplicates(vector<int>& v){
    //USE OF TWO POINTERS IN VERY GREAT WAY TO SOLVE THIS
    int i = 0;
    int j = 1;
    while(i<v.size()){
        if(v[i]==v[j]){
            i++;
        }
        else{
            //matlab ki different aa gay 
            //then 
            j++;
            v[j] = v[i];
            i++;
        }
    }
    int k  =  j+1;
    return k;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int ans = removeduplicates(v);
    cout<<"Size of the unique element array is : "<<ans<<endl;
    return 0;
}
// 10 
// 0 0 1 1 1 2 2 3 3 4