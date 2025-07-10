#include<iostream>
using namespace std;
int solveusingrec(int n){
    // base case - mandatory
    // processing - optional 
    // recursive relation - mandatory 

    //base case
    if(n == 0 || n == 1) return n;

    //recursive relation 
    int ans = solveusingrec(n-1) + solveusingrec(n-2);
    return ans;
}
//Top-down appraoch - recursion + Memoization
//Top-down because we go highest to lowest not lowest to highest
int solveusingmem(int n,vector<int>& dp){
    //Top - down approach - Recursion + memoization
    //These have 3 steps 
    //Step 1 - creation of dp array 
    //Step 2 - store answer in dp array 
    //Step 3 - if answer existed then return the answer
    //Creation | Storage | Utilization

    //base case
    if(n == 0 || n == 1) return n;

    //Step 3 - if ans already exist then return ans;
    if(dp[n] != -1) return dp[n];

    
    //recursive relation 
    //Step 2 - bss answer variable ki jagah esko dp array mein store krenge
    dp[n] = solveusingmem(n-1,dp) + solveusingmem(n-2,dp);
    return dp[n];
}
//bottom-up appraoch - Tabulation method
//0 to n ki taraf solution build krte ja rah hai 
int solveusingtabulation(int n){
    //This also have included only 3 steps - 
    //Step 1 - create a dp array
    //Step 2 - fill initial data according to base case
    //Step 3 - bche hua dp array ko fill krdo according 
    // to using logic of recursive relation
    

    //Tabulation method ke andar firstly we fill intial data on the basis of base case manually 
    //bche hua dp array ko fill krdo using recusive relation 

    //Step 1 - create an array 
    vector<int> dp(n+1,-1);
    //Step 2 - Analyze base case and fill dp array 
    dp[0] = 0;
    if(n==0) return dp[0];
    dp[1] = 1;

    //Step 3 - fill the remaining array using recursion
    //size = n + 1 / index = 0->n / index fulfill -> 0 1
    // bcha hua array fill krdo 2->n
    for(int i = 2; i <= n; i++){
        //Copy paste the recursive logic 
        //replace recursive calls with dp array 
        // make sure dp array is using looping variable i
        dp[i] = dp[i-1] + dp[i-2];
    }

    //answer return krdo
    return dp[n];
}
int solveusingspaceoptimization(int n){
    //dp mein next element apne 1 piche vala or 2 piche vala par depend kr rah hai 
    //means hme 2 dbbo ki need pd rhi hai matlab 2 variable ki need pd rhi hai 
    // so can we store it into 2 variable instead of vector

    
    int prev = 0;
    if(n == 0) return 0;
    int curr = 1;
    if(n == 1) return 1;

    int ans;
    for(int i = 2; i <= n; i++){
        ans = curr + prev;
        //prev and curr ko to ek step se aaga bdao har baar
        prev = curr;
        curr = ans;
    }

    //answer return krdo
    return ans;
}
int fib(int n){
    // int ans = solveusingrec(n);
    // return ans;
    //For dp
    //Step 1 : create a dp array to store the answer 
    // vector<int> dp(n+1,-1);//size = n + 1 because we want to store the answer till n 
    // int ans = solveusingmem(n,dp);
    // // for(auto i : dp) cout<<i<<" ";
    // // 0 1 mein answer store nhi ho rah kyuki vo base case hai direct return ho ja rah 
    // return ans;

    // //Tabulation method 
    // int ans = solveusingtabulation(n);
    // return ans;

    int ans = solveusingspaceoptimization(n);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number for which till u find fibonnaci sequence : ";
    cin>>n;
    cout<<"The fibonnaci sequence of the number with addition is : "<<fib(n)<<endl;
    return 0;
}
//jab 1d dp hoti hai to 1d array bna lo 
//jab 2d dp hoti hai to 2d array bna lo
//jab 3d dp hoti hai to 3d array bna lo
//aise hi jitni dp hoti hai utna ka array bna lo
//jab hmne recursive call kiya to us recursive call mein 
//jitne parameters change hote hai utna ki hi dp hoti hai 
