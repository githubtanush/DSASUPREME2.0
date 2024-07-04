#include<iostream>
#include<vector>
using namespace std;
void spiralprintmatrix(vector<vector<int> > mat){
    int row = mat.size();
    int col = mat[0].size();
    int count = 0;
    int tot_count = row * col;

    int startrow = 0;
    int startcol = 0;
    int endrow = row - 1;
    int endcol = col - 1;

    while(count < tot_count){
        //PRINT KRNA SHURU KRTE HAI PEHLE FIRST ROW AAYGI
        for(int i = startcol ; i <= endcol && count<tot_count ;i++){
            cout<<mat[startrow][i]<<" ";
            count++;
        }
        cout<<endl;
        startrow++;
        for(int i = startrow; i <= endrow && count < tot_count ;i++){
            cout<<mat[i][endcol]<<" ";
            count++;
        }
        cout<<endl;
        endcol--;
        for(int i = endcol; i>=startcol && count < tot_count ;i--){
            cout<<mat[endrow][i]<<" ";
            count++;
        }
        cout<<endl;
        endrow--;
        for(int i = endrow;i>=startrow && count < tot_count ;i--){
            cout<<mat[i][startcol]<<" ";
            count++;
        }
        cout<<endl;
        startcol++;
    }

}
int main(){
    int rows;
    cin>>rows;
    int cols;
    cin>>cols;
    vector<vector<int> > mat(rows,vector<int>(cols));
    for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    spiralprintmatrix(mat);
    return 0;
}
// 4 4
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16