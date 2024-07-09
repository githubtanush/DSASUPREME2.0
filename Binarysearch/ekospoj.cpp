#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossiblesolution(vector<long long int>trees,long long int m,long long int mid){
    long long int woodcollected = 0;
    for(int i = 0; i < trees.size();i++){
        if(trees[i]>mid){
            woodcollected += trees[i]-mid;
        }
    }
    return woodcollected>=m;
}
long long int maxsawbladeheight(vector<long long int>& trees,long long int m){
    long long int s= 0,e,ans = -1;
    e = *max_element(trees.begin(),trees.end());
    while(s<=e){
        long long int mid = s + ( e - s)/2;
        if(ispossiblesolution(trees,m,mid)){
            ans = mid ;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;

}
int main(){
    long long int n,m;
    cin>>n>>m;
    vector<long long int> trees;
    while(n--){
    long long int height;
    cin>>height;
    trees.push_back(height);
    }
    cout<<maxsawbladeheight(trees,m)<<endl;
    return 0;
}
// 4 7
// 20 15 10 17