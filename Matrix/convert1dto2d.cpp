#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //point to be remember
        if(original.size() != m*n) return {};
        //creating 2d array
        vector<vector<int> >twod(m,vector<int>(n));
        int index = 0;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n;j++){
                twod[i][j] = original[index++];
            }
        }
        return twod;
    }
int main(){
    int no;
    cin>>no;
    vector<int> original(no);
    for(int i = 0; i < no;i++){
        int data;
        cin>>data;
        original[i] = data;
    }
    int m;
    cout<<"Enter number of rows do you want : ";
    cin>>m;
    int n;
    cout<<"Enter number of cols do you want : ";
    cin>>n;
    vector<vector<int> >twodi = construct2DArray(original,m,n);
    for(auto i : twodi){
        for(auto j : i){
            cout<<j<<" ";
        }
    }
    return 0;
}
// 3 
// 1 2 3 
// 1
// 3


// 2
// 1 2
// 1 
// 1