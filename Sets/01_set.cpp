//set is  a collection of unique and sorted elements
//creation set<int> st;
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> st;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for(int i = 0; i < n;i++){
        int x;
        cout<<"Take element : ";
        cin>>x;
        st.insert(x);
    }
    for(auto it : st){
        cout<<it<<" ";
    }
    return 0;
}