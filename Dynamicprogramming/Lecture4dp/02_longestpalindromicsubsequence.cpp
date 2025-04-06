#include<iostream>
using namespace std;
int solveusingrec(string& a,string& b,int i,int j){
    //Basecase
    if(i >= a.length()) return 0;
    if(j >= b.length()) return 0;

    int ans = 0;
    //Case 1 - if character matches then move i and j
    if(a[i] == b[j]) ans = 1 + solveusingrec(a,b,i+1,j+1);
    //Case 2 - if character does not match 
    else ans = 0 + max(solveusingrec(a,b,i+1,j),solveusingrec(a,b,i,j+1));

    return ans;
}
int solveusingmem(string& a,string& b,int i,int j,vector<vector<int> >& dp){
    //Basecase
    if(i >= a.length()) return 0;
    if(j >= b.length()) return 0;

    //Step 3 - check if answer exists or not
    if(dp[i][j] != -1) return dp[i][j];

    //Step 2 - store in dp array 
    int ans = 0;
    //Case 1 - if character matches then move i and j
    if(a[i] == b[j]) ans = 1 + solveusingmem(a,b,i+1,j+1,dp);
    //Case 2 - if character does not match 
    else ans = 0 + max(solveusingmem(a,b,i+1,j,dp),solveusingmem(a,b,i,j+1,dp));

    dp[i][j] = ans;

    return dp[i][j];
}
int solveusingtabulation(string& a,string& b){
    //Step 1 - make vector according to parameter change simply means create 2d vector
    vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,0));

    //Step 2 - Applying iterative approach by using for loop 
    //recursion code 0->n-1 i.e tabulation code n-1->0
    for(int i = a.length()-1; i>=0;i--){
        for(int j = b.length()-1;j>=0;j--){
            int ans = 0;
            if(a[i]==b[j]) ans = 1 + dp[i+1][j+1];
            else ans = 0 + max(dp[i][j+1],dp[i+1][j]);

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveusingSO(string& a,string& b){
    //Step 1 :- Create 2 columns array 
    vector<int> curr(a.length()+1,0);
    vector<int> next(a.length()+1,0);

    //Step 2 :- Applying for loop 
    for(int j = b.length()-1;j>=0;j--){
        for(int i = a.length()-1;i>=0;i--){
            int ans = 0;
            if(a[i] == b[j]) ans = 1 + next[i+1];
            else ans = 0 + max(curr[i+1],next[i]);
            curr[i] = ans;
        }
        //Shifting
        next = curr;
    }
    return next[0];
}
int longestpalindromicsubsequence(string& s){
    string a = s;
    reverse(a.begin(),a.end());
    int ans = solveusingtabulation(s,a);
    return ans;
}
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"Longest Palindromic Subsequence for this string is : "<<longestpalindromicsubsequence(s)<<endl;
    return 0;
}