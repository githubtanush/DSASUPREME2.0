#include<iostream>
#include<vector>
using namespace std;
bool binarysearch(vector<vector<int> >& arr,int target){
    // int m = arr.size();
    // int n = arr[0].size();
    // int tot = m * n;
    // int s = 0;
    // int e = tot - 1;
    // while( s <= e ){
    //     int mid = s + ( e - s )/2;
    //     int rowindex = mid / n;
    //     int colindex = mid % n;
    //     int currele = arr[rowindex][colindex];
    //     if(currele == target) return true;
    //     else if(currele < target) s = mid + 1;
    //     else e = mid - 1;
    // }
    // return false;

    int row = arr.size();
    int col = arr[0].size();
    // int tot = row * col;
    int i = 0 , j = col - 1;
    while(i < row && j >= 0 ){
        if(arr[i][j]==target) return true;
        else if(arr[i][j] > target) j--;
        else i++;
    }
    return false;

}
int main(){
    int row;
    cin>>row;
    int col;
    cin>>col;
    vector<vector<int> > arr(row,vector<int>(col));
    for(int i = 0 ; i < row;i++){
        for(int j = 0; j < col;j++)
            cin>>arr[i][j];
    }
    int target;
    cin>>target;
    bool ans = binarysearch(arr,target);
    if(ans) cout<<"Element is present"<<endl;
    else cout<<"Element is not present"<<endl;
    return 0;
}
// 3
// 3
// 1 2 3 
// 4 5 6 
// 7 8 9
// 5