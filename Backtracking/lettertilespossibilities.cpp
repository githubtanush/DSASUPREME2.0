#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& freq){
    int ans = 0;
    //he ek dbbe mein A->Z tk insert krna ka try krra hu 
    for(int i = 0; i < 26;i++){
        //character exist krta bhi hai ya nhi jisse answer mein push krna hai pehle yeh check krenge
        if(freq[i] != 0){
            //ek answer nikal gya
            ans++;
            //freq update
            freq[i]--;
            //baaki toh recursion sambhal lega
            int recursionkaans = solve(freq);
            //esko answer ke bich mein add krte hai 
            ans += recursionkaans;
            //backtracking
            freq[i]++;
        }
    }
    return ans;
}
int numtilepossiblity(string tiles){
    vector<int> freq(26,0);
    //count freq of characters
    for(auto ch: tiles) freq[ch-'A']++;
    int ans = solve(freq);
    return ans;
}
int main(){
    string tiles;
    getline(cin,tiles);
    int ans = numtilepossiblity(tiles);
    cout<<"The number of possibilites in letter tiles is : "<<ans<<endl;
    return 0;
}

//AAABBC
//188