#include<iostream>
#include<vector>
using namespace std;
vector<int> queryResults(int limit, vector<vector<int>>& q) {
unordered_map<int,int> cols;   // Stores column frequencies
unordered_map<int,int> prev;   // Stores previous column of each key
vector<int> ans;               // Stores the result

for(auto& i : q){              // Iterating through each query
    if(prev.count(i[0]) > 0){  // If key already exists
        cols[prev[i[0]]]--;    // Reduce count of old column
        if(cols[prev[i[0]]] == 0) cols.erase(prev[i[0]]); // Remove if count is 0
    }
    prev[i[0]] = i[1];         // Update previous column
    cols[i[1]]++;              // Increase count of new column
    ans.push_back(cols.size()); // Store unique column count
}
return ans; 
}
int main(){
    int limit;
    cout<<"Enter the limit : ";
    cin>>limit;
    int row;
    cout<<"Enter the number of rows you want to take in array : ";
    cin>>row;
    vector<vector<int> > queries(row,vector<int>(2));
    for(int i = 0; i < row;i++){
        for(int j = 0;j < 2; j++){
            cin>>queries[i][j];
        }
    }
    vector<int> ans = queryResults(limit,queries);
    for(int i : ans) cout<<i<<" ";

    return 0;
}
//4
//4
// 1 4
// 2 5
// 1 3
// 3 4