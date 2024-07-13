#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int,bool> rowcheck;
unordered_map<int,bool> topdiagonal;
unordered_map<int,bool> bottomdiagonal;
void storesolution(vector<vector<char> >&board,vector<vector<string> >& ans){
    vector<string> tempsol;
    for(auto vec : board){
        string temp = "";
        for(auto ch:vec){
            temp.push_back(ch);
        }
        tempsol.push_back(temp);
    }
    ans.push_back(tempsol);
}
bool issafe(int row,int col,vector<vector<char> >& board){
    if(rowcheck[row]==true) return false;
    if(topdiagonal[col - row]==true) return false;
    if(bottomdiagonal[row + col]==true) return false;
    //place is safe
    return true;
}
void solve(vector<vector<char> >& board,vector<vector<string> >& ans,int n,int col){
    //base case
    if(col>=n){
        ///sarra column process hogay hai 
        //iska matlab we have a solution to store
        storesolution(board,ans);
        return ;
    }
    //main logic
    //is column k har row pr queen place krdena
    for(int row = 0; row < n;row++){
        if(issafe(row,col,board)){
            //queen place krdo
            board[row][col] = 'Q';
            //mark all the three direction where Q is placed
            rowcheck[row] = true;
            topdiagonal[col-row] = true;
            bottomdiagonal[row+col] = true;

            //Recursion chacha
            solve(board,ans,n,col+1);
            
            //backtrack
            board[row][col] = '.';
            rowcheck[row] = 0;
            topdiagonal[col-row] = 0;
            bottomdiagonal[row+col] = 0;
        }
    }
}
vector<vector<string>> solvenqueens(int n){
    vector<vector<string> >ans;
    vector<vector<char> > board(n,vector<char>(n,'.'));
    int col = 0;
    solve(board,ans,n,col);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<string> > ans = solvenqueens(n);
    for(int i = 0; i < ans.size();i++){
        for(int j = 0; j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}