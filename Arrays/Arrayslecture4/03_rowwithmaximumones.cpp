// 03_rowwithmaximumones
#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int> >& arr){
    for(int i = 0; i < arr.size();i++){
        for(int j = 0; j < arr[i].size();j++){
            cin>>arr[i][j];
        }
    }
}
//we store the minimum index and maximum count in the array and return 
vector<int> maximumones(vector<vector<int> >& arr){
    //We initialize the variable count so we store that
    // the maximum count of one in variable count and 
    //initialize it with INT_MIN
    //I make one more variable and that variable i used to store the index of the array
    int rowindex = INT_MIN;
    //finally we make one variable that where we match previous value is bigger than  present value or not
    int onecount = INT_MIN;
    //we make one vector in which we store the index of the vector and count of the one's 
    vector<int> ans;
    //we start the loop 
    for(int i = 0; i < arr.size();i++){
        int count = 0;
        for(int j = 0;j < arr[i].size();j++){
            if(arr[i][j] == 1) count++;
        }
        if(count > onecount){
            onecount = count;
            rowindex = i;
        }
    }   
    ans.push_back(onecount);
    ans.push_back(rowindex);
    return ans;
}
int main(){
    int rows;
    cout<<"How many number of rows you want to take : ";
    cin>>rows;
    int cols;
    cout<<"How many number of cols you want to take : ";
    cin>>cols;
    vector<vector<int> > arr(rows,vector<int>(cols));
    input(arr);
    vector<int> answer = maximumones(arr);
    for(int i : answer){
        cout<<i<<" ";
    }
    return 0;
}
//5
//4
// 1 0 0 0 
// 0 1 1 0
// 0 1 1 0
// 1 1 1 0
// 0 0 1 0