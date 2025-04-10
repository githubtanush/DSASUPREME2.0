#include<iostream>
#include<vector>
using namespace std;
int solveusingrec(int capacity,vector<int>& wt,vector<int>& profit,int index){
    //base case
    int  n = wt.size();
    // if(index == n-1) if(wt[index] <= capacity) return profit[index];
    // else return 0;
    if(index >= n) return 0;

    //inclusion / exclusion
    int include = 0;
    if(wt[index] <= capacity) include = profit[index] + solveusingrec(capacity-wt[index],wt,profit,index+1);
    int exclude = 0 + solveusingrec(capacity,wt,profit,index+1);

    return max(include,exclude);
}
int solveusingmem(int capacity,vector<int>& wt,vector<int>& profit,int index,vector<vector<int> >& dp){
    //base case
    int  n = wt.size();
    // if(index == n-1) if(wt[index] <= capacity) return profit[index];
    // else return 0;
    if(index >= n) return 0;
    //Step 3 - check answer exists or not 
    if(dp[capacity][index] != -1) return dp[capacity][index];

    //inclusion / exclusion
    int include = 0;
    if(wt[index] <= capacity) 
        include = profit[index] + solveusingmem(capacity-wt[index],wt,profit,index+1,dp);
    int exclude = 0 + solveusingmem(capacity,wt,profit,index+1,dp);

    dp[capacity][index] = max(include,exclude);
    return dp[capacity][index];
}
int solveusingtabulation(int w,vector<int>& wt,vector<int>& profit,int index){
    int n = wt.size();
    //Step 1 - create a dp array 
    vector<vector<int> > dp(w+1,vector<int> (n+1,-1));

    //Step 2 - initialize the base values 
    for(int row = 0; row <= w; row++)
        dp[row][n] = 0;

    for(int i = 0 ; i <= w; i++){
        //yeh for loop meini ulta chla diya  0 to n means answer ka 
        //build hua hoga n par apne code wise answer nth col meini produce kiya
        for(int j = n - 1 ; j >= 0; j--){
            //inclusion / exclusion 
            int include = 0;
            if(wt[j] <= i)
                include = profit[j] + dp[i-wt[j]][j+1];
            int exclude = 0 + dp[i][j+1];
            dp[i][j] = max(include,exclude);
        }
    }
    return dp[w][0];
}
int solveUsingTabulationSO(int capacity, vector<int>& wt, vector<int>& profit, int index) {
    int n = wt.size();
	vector<int> next(capacity+1, 0);
	vector<int> curr(capacity+1, -1);


	for(int j=n-1; j>=0; j--) {
		for(int i=0; i<=capacity; i++) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + next[i-wt[j]];
			}
			int exclude = 0 + next[i];
			curr[i] = max(include, exclude);
		}
		//shifting
		next = curr;
	}
	return curr[capacity];
}
int main(){
    int capacity;
    cout<<"Enter the capacity of the knapsack : ";
    cin>>capacity;

    int n1;
    cout<<"Enter the size of the weight array : ";
    cin>>n1;
    vector<int> wt(n1);
    for(int i = 0; i < n1;i++) cin>>wt[i];

    int n2;
    cout<<"Enter the size of the profit array : ";
    cin>>n2;
    vector<int> profit(n2);
    for(int i = 0; i < n2;i++) cin>>profit[i];

    int index = 0;
    // int ans = solveusingrec(capacity,wt,profit,index);
    //Step 1 - create dp array 
    // vector<vector<int> >dp(capacity+1,vector<int>(n1+1,-1));
    // int ans = solveusingmem(capacity,wt,profit,index,dp);
    // int ans = solveusingtabulation(capacity,wt,profit,index);
    int ans = solveUsingTabulationSO(capacity,wt,profit,index);
    cout<<"Max Profit : "<<ans<<endl;
    return 0;
}
// 50 
// 3 
// 10 20 30 
// 3
// 60 100 120