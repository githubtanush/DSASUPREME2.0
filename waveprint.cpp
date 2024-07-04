#include<iostream>
#include<vector>
using namespace std;
void waveprintmatrix(vector<vector<int> > mat){
    int row = mat.size();
    int col = mat[0].size();
    for(int j = 0; j < col;j++){
        // AGAR EVEN NUMBER HAI TAAH - TOP TO BOTTOM
        if((j&1) == 0){
        for(int i = 0; i < row ; i++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        }
        //IF ODD NUMBER - BOTTOM TO TOP
        else {
            for(int i = row-1; i>=0 ;i--){
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
    waveprintmatrix(mat);
    return 0;
}
// 3 4
// 1 2 3 4 5 6 7 8 9 10 11 12