#include<iostream>
using namespace std;
// void bubblesort(vector<int>& v){
//     for(int i = 0; i < v.size();i++){
//         for(int j = 0 ; j < v.size()-i-1; j++){
//             if(v[j] > v[j+1]) swap(v[j],v[j+1]);
//         }
//     }
// }
void insertionsort(vector<int>& v){
    int n = v.size();
    //i = 0 nu chod denda
    for(int i = 1; i < v.size();i++){
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;//insertion
    }
}
void selectionsort(vector<int>& v){
    
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    for(int i : arr) cout<<i<<" ";
    // bubblesort(arr);
    insertionsort(arr);
    cout<<endl;
    for(int i : arr) cout<<i<<" ";
    return 0;
}