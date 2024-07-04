#include<iostream>
#include<vector>
using namespace std;
void snakeprintmatrix(vector<vector<int> > mat){
    int row = mat.size();
    int col = mat[0].size();
    //KEY POINT - ROW AND COLUMNS DOES NOT CHANGE IT REMAINS SAME
    for(int i = 0; i < row;i++){
        if((i&1)==0){
            // LEFT TO RIGHT JAANA SOCH KOI IDEA
            //MATLAB KI ROW WISE CHANGE HONA COLWISE NHI
            for(int j = 0; j < col;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        else{
            //RIGHT TO LEFT JAANA SOCH KOI IDEA
            //ROW WISE CHANGE HONGE COLWISE NHI 
            //THIS CONDITION IS IMPORTANT
            for(int j = col-1; j>=0 ; j--){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
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
    snakeprintmatrix(mat);
    return 0;
}
// 3 4
// 1 2 3 4 5 6 7 8 9 10 11 12