#include<iostream>
#include<vector>
using namespace std;
int missingelementfromarraywithduplicates(vector<int>& v){
    //METHOD 1 - NEGATIVE MARKING METHOD
    int n = v.size();
    // int ans = -1;
    // for(int i = 0; i < n;i++){
    //     //create new index from the element of array and use it 
    //     int index = abs(v[i]);

    //     //MARK VISITED IF THEY NOT THEN 
    //     // HMARA INDEX 1 SE SHURU HO RAH HAI 
    //     //BUT ACTUALLY ARRAY KE INDEX 0 SE SHURU HO RAH HAI ESLIYE HMM ARRAY MEIN INDEX-1 KR DENGE
    //     if(v[index-1] > 0){
    //         v[index-1] *= -1;
    //     }
    // }
    //     //ALL POSITIVE INTEGERS
    //     for(int i = 0;i < n;i++){
    //         if(v[i]>0){
    //            ans = i+1;
    //            break;
    //         }
    //     }
    // return ans;

    ///METHOD 2 - SWAPPING AND SORTING
    int ans = -1;
    int i = 0;
    while(i < n){
        int index = v[i]-1;
        if(v[i] != v[index]){
            swap(v[i],v[index]);
        }
        else{
            i++;
        }
        cout<<"For"<<i<<"iteration : "<<" ";
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    for(int i = 0 ; i < n;i++){
        if(v[i] != i+1){
            ans = i+1;
            break;
        }
    }
    return ans;

}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int ans = missingelementfromarraywithduplicates(v);
    cout<<"Missing element in this duplicate array is : "<<ans<<endl;
    return 0;
}
//5
//1 3 5 3 4
//5 3 3 3 1
