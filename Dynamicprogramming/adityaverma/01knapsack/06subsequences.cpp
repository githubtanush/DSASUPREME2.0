#include<iostream>
using namespace std;
void subsequences(vector<int>& arr){
    int n = arr.size();
    vector<vector<int> > sub;
    for(int mask = 0; mask < (1 << n) ; mask++){
        vector<int> series;
        for(int j = 0; j < n ;j++){
            if(mask & ( 1 << j)) series.push_back(arr[j]);
        }
        sub.push_back(series);
    }
    for(auto i : sub){
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) cin>>arr[i];
    subsequences(arr);
    return 0;
}