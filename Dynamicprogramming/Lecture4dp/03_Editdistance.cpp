#include<iostream>
using namespace std;
int solveusingrec(string& a,string& b,int i ,int j){
    if(i >= a.length()) return b.length()-j;
    if(j >= b.length()) return a.length()-i;

    int ans = 0;
    if(a[i] == b[j]) ans = 0 + solveusingrec(a,b,i+1,j+1);
    else{
        //insert
        int option1 = 1 + solveusingrec(a,b,i,j+1);
        //remove 
        int option2 = 1 + solveusingrec(a,b,i+1,j);
        //replace
        int option3 = 1 + solveusingrec(a,b,i+1,j+1);

        //minimum 
        ans = min(option1,min(option2,option3));
    }
    return ans;
}
  int solveusingmem(string& a,string& b,int i ,int j,vector<vector<int> >& dp){
    if(i >= a.length()) return b.length()-j;
    if(j >= b.length()) return a.length()-i;

    //Step 3 - check if already exists or not?
    if(dp[i][j] != -1) return dp[i][j];

    
    int ans = 0;
    if(a[i] == b[j]) ans = 0 + solveusingmem(a,b,i+1,j+1,dp);
    else{
        //insert
        int option1 = 1 + solveusingmem(a,b,i,j+1,dp);
        //remove 
        int option2 = 1 + solveusingmem(a,b,i+1,j,dp);
        //replace
        int option3 = 1 + solveusingmem(a,b,i+1,j+1,dp);

        //minimum 
        ans = min(option1,min(option2,option3));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int solveusingtabulation(string& a,string& b){
    //Step 1 - make 2d vector
    vector<vector<int> > dp(a.length()+1,vector<int>(b.length()+1,0));
    //Step 2 - Analyze base case
    for(int col = 0; col <= b.length();col++) dp[a.length()][col] = b.length()-col;
    for(int row = 0; row <= a.length();row++) dp[row][b.length()] = a.length()-row;

    for(int i = a.length()-1;i>=0;i--){
        for(int j = b.length()-1;j>=0;j--){
             int ans = 0;
    if(a[i] == b[j]) ans = 0 + solveusingmem(a,b,i+1,j+1,dp);
    else{
        //insert
        int option1 = 1 + solveusingmem(a,b,i,j+1,dp);
        //remove 
        int option2 = 1 + solveusingmem(a,b,i+1,j,dp);
        //replace
        int option3 = 1 + solveusingmem(a,b,i+1,j+1,dp);

        //minimum 
        ans = min(option1,min(option2,option3));
    }
    dp[i][j] = ans;
        }
    }
    return dp[0][0];

}
int solveusingSO(string& a,string& b){
//Step 1 - create two columns
vector<int> curr(a.length()+1,0);
vector<int> next(a.length()+1,0);
    //Step 2 - Analyze base case
    //esse bilkul mat bhulna yhi line abhi tumhara pattern break krne vali hai 
    // for(int col = 0; col <= b.length();col++) dp[a.length()][col] = b.length()-col;
    //most important line which is used in further for loops not in that
    for(int row = 0; row <= a.length();row++) next[row]= a.length()-row;

    for(int j = b.length()-1;j>=0;j--){
        //most important line 
        //har naye column ke last dbbe mein column insert kro 
        curr[a.length()] = b.length()-j;
        for(int i = a.length()-1;i>=0;i--){
            int ans = 0;
            if(a[i] == b[j]) ans = 0 + next[i+1];
            else{
                //replace
                int replace = 1 + next[i+1];
                //insert
                int insert = 1 + next[i];
                //remove
                int remove = 1 + curr[i+1];

                //minimum 
                ans = min(replace,min(insert,remove));
            }
        curr[i] = ans;
        }
        //shifting
        next = curr;
    }
    return next[0];
}
int minDistance(string word1, string word2) {
    int i = 0;
    int j = 0;
    //Step 1 :- Create 2D dp
    // vector<vector<int> > dp(word1.length()+1,vector<int>(word2.length()+1,-1));
    // int ans = solveusingrec(word1,word2,i,j);
    // int ans = solveusingmem(word1,word2,i,j,dp);
    // int ans = solveusingtabulation(word1,word2);
    int ans = solveusingSO(word1,word2);
    return ans;
}
int main(){
    string word1;
    cout<<"Enter the first string which you want to check that is matching or not : ";
    cin>>word1;
    string word2;
    cout<<"Enter the second string which you want to check that is matching or not : ";
    cin>>word2;
    cout<<"Minimum number of Operations performed to make string 1 and string 2 words to be equal is : "<<minDistance(word1,word2)<<endl;
    return 0;
}
//horse 
//ros 