#include<iostream>
#include<vector>
using namespace std;
int solve(vector<vector<char> >& matrix,int i,int j ,int row,int col,int& maxi){
//base case
if(i>=row || j>=col) return 0;

//explore all 3 possible directions
//check right direction that there are any 1
int right = solve(matrix,i,j+1,row,col,maxi);
//check diagonally direction that there are any 1
int diagonal = solve(matrix,i+1,j+1,row,col,maxi);
//check downwards direction that there are any 1
int down = solve(matrix,i+1,j,row,col,maxi);

//check can we build square from current position or not 
if(matrix[i][j]=='1'){
    int ans = 1 + min(right,min(diagonal,down));
    //yeh hm hmesha bhul jaata hai esko yaad rkhna
    maxi = max(maxi,ans);
    return ans;
}
else{
    return 0;
}
}
int maximalsquare(vector<vector<char> >& matrix){
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;
    int ans = solve(matrix,i,j,row,col,maxi);
    return maxi*maxi;
}
int main(){
    int rows ;
    cin>>rows;
    int cols;
    cin>>cols;
    vector<vector<char> >matrix (rows,vector<char>(cols));
    for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols;j++){
            cin>>matrix[i][j];
        }
    }
    int ans = maximalsquare(matrix);
    cout<<"Maximum square can found from this matrix is : "<<ans<<endl;
    return 0;
}
//Input - 
// 4
// 5
// 1 0 1 0 0 
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

//Output - 
// 4

//Input - 
// 2
// 2
// 0 1 
// 1 0

//Output - 
// 1

//Input - 
// 1
// 1
// 0

//Output -
// 0