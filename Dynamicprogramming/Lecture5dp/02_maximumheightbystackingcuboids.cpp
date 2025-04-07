#include<iostream>
using namespace std;
bool check(vector<int>& curr,vector<int>& prev){
    //curr - bde vala dbba 
    //prev - chota vala dbba
    if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) return true;
    else return false; 
}
 int solveusingSO(vector<vector<int> >& cuboids){
        int n = cuboids.size();
        //Step 1 - create two dp row vector array 
        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);
        //Step 2 - Analyze the base case by applying for loop

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1 ; prev--){
                int include = 0;
                if(prev == -1 || check(cuboids[curr],cuboids[prev])){
                    int heighttoadd = cuboids[curr][2];
                        include = heighttoadd + nextrow[curr + 1];
                }
                int exclude = 0 + nextrow[prev + 1];
                currrow[prev+1] = max(include,exclude);
            }
            //Shifting 
            nextrow = currrow;
        }
        return nextrow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cuboid : cuboids) sort(cuboid.begin(),cuboid.end());

        sort(cuboids.begin(),cuboids.end());
        int ans = solveusingSO(cuboids);
        return ans;
    }
int main(){
    int row;
    cout<<"Enter how many rows do you want in an array : ";
    cin>>row;
    int col;
    cout<<"Enter how many cols do you want in an array : ";
    cin>>col;
    vector<vector<int> > cuboids(row,vector<int>(col));
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cin>>cuboids[i][j];
        }
    }
    cout<<"Maximum height of stacked cuboids is : "<<maxHeight(cuboids)<<endl;
    return 0;
}
// 50 45 20 
// 95 37 53
// 45 23 12