#include<iostream>
#include<vector>
using namespace std;
bool ispossiblesolution(vector<int>& stalls,int k,int mid){
    //Can we place k cows with atleast mid distance between cows
    int c = 1;
    int pos = stalls[0];
    for(int i = 1; i < stalls.size();i++){
        if(stalls[i]-pos >= mid){
            c++;
            pos = stalls[i]; //One more cow has been placed
        }
        if(c==k) return true;
    }
    return false;
}
int solve(int n,int k,vector<int> stalls){
sort(stalls.begin(),stalls.end());
int s = 0;
int e = stalls[stalls.size()-1] - stalls[0];
int ans = -1;
while(s<=e){
    int mid = ( s + e ) >> 1;
    if(ispossiblesolution(stalls,k,mid)){
        ans = mid ;
        s = mid + 1;
    }
    else e = mid - 1;
}
return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> stalls(n);
    for(int i = 0; i < n;i++){
        cin>>stalls[i];
    }
    int ans = solve(n,k,stalls);
    cout<<"Minimum distance of maximum which u place between two cows is : "<<ans<<endl;
    return 0;
}
//Input - 
// 5
// 3
// 1 2 4 8 9 

//output  - 3