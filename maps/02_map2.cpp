//perform 3 operations on maps with array 
//2 1 2 2 3 4 5 5
//1st operation.) calculate frequency
//2nd operation.) find 3 is present or not then count its frequency
//3rd operation.) erase krna 6


// unordered map mein hmm single ek string integer double  jeise simple data type ka liye
// map hogya jisme hmm pair ,vector bhi daal skte hai

#include<iostream>
using namespace std;
int main(){
    unordered_map<int,int> mp;
    int n;
    cout<<"Enter the size of the map : ";
    cin>>n;
    for(int i = 0; i < n;i++){
        int x;
        cout<<"Take element : ";
        cin>>x;
        mp[x]++;
    }

    for(auto it : mp){
        cout<<it.first<<" "<<it.second<<endl;
        int key = it.first;
        int value = mp[key];
        cout<<key<<" "<<value<<endl;
    }
    if(mp.find(3) != mp.end()){
        cout<<"3 is present"<<endl;
    }
    if(mp.find(6) != mp.end()){
        mp.erase(6);
    }
    return 0;
}
