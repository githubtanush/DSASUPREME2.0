#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int> cookranks,int np,int mid){
    int currP = 0; //current initial prata count
    for(int i = 0; i < cookranks.size();i++){
        int r = cookranks[i] , j = 1;
        int timetaken = 0;
        while(true){
            if(timetaken + j * r <= mid){
                ++currP;
                timetaken += j * r;
                ++j;
            }
            else{
                break;
            }
        }
        if(currP >= np){
            return true;
        }
    }
    return false;
}
int minTimetocompleteorder(vector<int> cooksranks,int np){
    int s = 0;
    int highestRank = *max_element(cooksranks.begin(),cooksranks.end());
    int e = highestRank * ( np * (np+1))/2;
    int ans = -1;
    while(s<=e){
        int mid = (s + e)>>1;
        if(ispossible(cooksranks,np,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int np,nc;
        cin>>np>>nc;
    vector<int> cooksranks;
    while(nc--){
        int r;
        cin>>r;
        cooksranks.push_back(r);
    }
    cout<<endl;
    cout<<minTimetocompleteorder(cooksranks,np)<<endl;
    }
    return 0;
}
//Input - 
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

//output - 
// 12
// 36
// 1