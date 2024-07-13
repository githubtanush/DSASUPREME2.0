#include<iostream>
#include<vector>
using namespace std;
bool issafe(int row,int col,char value,vector<vector<char> >& board){
    //same row me vo na ho
    //same column me vo na ho 
    //same 3*3 matrix mein vo na ho 
    int n = board.size();
    //row check 
    for(int i = 0; i < n;i++){
        if(board[row][i]==value) return false;
    }
    //column check 
    for(int i = 0; i < n ;i++){
        if(board[i][col]==value) return false;
    }
    //3*3 box ko check krlo
    for(int i = 0; i < n;i++){
        // yaah pr hi glti hoti hai 
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == value) return false;
    }
    //place is safe
    return true;
}
bool solvehelper(vector<vector<char> >& board){
    int n = board.size();
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            //empty cell check kro
            if(board[i][j]=='.'){
                //try krenge = insert krne ko 
                for(char ch = '1'; ch<='9';ch++){
                    if(issafe(i,j,ch,board)){
                        //place krdo 
                        board[i][j] = ch;
                        //recursion
                        bool recursionkaans = solvehelper(board);
                        if(recursionkaans == true) return true;
                        //else recursion ka ans nhi lapaya
                        //iska matlab jo character apne insert kiya vo glt hai 
                        //iska matlab backtrack krdo or vapas aa jao
                        else board[i][j] = '.';
                    }
                }
            return false;
            }
        }
    }
    return true;
}
void solvesudoku(vector<vector<char> >& board){
    solvehelper(board);
}
int main(){
    int row;
    cin>>row;
    int col;
    cin>>col;
    vector<vector<char> >board(row,vector<char>(col));
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cin>>board[i][j];
        }
    }
    solvesudoku(board);
    cout<<endl;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// 3
// 3
// 2 8 . 
// . . 5
// . 7 9


// 9
// 9
// 5 3 . . 7 . . . .
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . 2 8 .
// . . . 4 1 9 . . 5
// . . . . 8 . . 7 9