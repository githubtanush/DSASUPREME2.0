#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> commonelements(vector<int>& arr,vector<int>& brr,vector<int>& crr){
    int n1 = arr.size();
    int n2 = brr.size();
    int n3 = crr.size();

    vector<int> ans;
    set<int> st;
    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i < n1 && j < n2 && k< n3){
        if(arr[i]==brr[j] && brr[j]==crr[k]){
            st.insert(arr[i]);
            i++;
            j++;
            k++;
        }
        else if(arr[i]< brr[j]){
            i++;
        }
        else if(brr[j]< crr[k]){
            j++;
        }
        else {
            k++;
        }
    }
    for(auto i : st){
       ans.push_back(i);
    }
    return ans;

}
int main(){
    cout<<"1st Array : ";
    vector<int> arr;
    int n1;
    cin>>n1;
    arr.resize(n1);
    for(int i = 0; i < n1;i++){
        cin>>arr[i];
    }
    cout<<"2nd Array : ";
    vector<int> brr;
    int n2;
    cin>>n2;
    brr.resize(n2);
    for(int i = 0; i < n2;i++){
        cin>>brr[i];
    }
    cout<<"3rd Array : ";
    vector<int> crr;
    int n3;
    cin>>n3;
    crr.resize(n3);
    for(int i = 0; i < n3;i++){
        cin>>crr[i];
    }
    vector<int> ans = commonelements(arr,brr,crr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}

// 6 
// 1 5 10 20 40 80
// 5
// 6 7 20 80 100
// 8
// 3 4 15 20 30 70 80 120