#include<iostream>
#include<vector>
using namespace std;
int missingelementfromarraywithduplicates(vector<int>& v){
    //    //Method 1 - using hashmap
   int n = v.size();
   //    int missing = -1;
   //    int repeating = -1;
   //    vector<int> freq(n+1,false);
   //    for(int i = 0 ; i < n;i++){
   //     freq[v[i]]++;
   //    }
   //    for(int i = 1; i <= n;i++){
   //     if(freq[i] == 0) missing = i;
   //     if(freq[i] == 2) repeating = i;
   //    }
   //    return {missing,repeating};

   
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

    //Method 4 - Maths method
    // int s = ( n * (n + 1 ) ) / 2 ; //Finding sum of the n natural numbers
    // int sq = ( n * ( n + 1 ) * ( 2 * n + 1 ) ) / 6; // find the sum of squares of n natural numbers
    // int missing = 0  , repeating = 0; // missing and repeating set to be 0
    // for(int i = 0; i < n;i++){ //traverse the loop 
    //     s -= v[i];  
    //     sq -= v[i] * v[i];
    // }
    // missing = (s + sq/s)/2;
    // repeating = missing - s;
    // return {repeating,missing};

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
