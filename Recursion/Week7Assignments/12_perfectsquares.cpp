#include<iostream>
using namespace std;
int numsquarehelper(int n){
    //base case
    if(n==0) return 1;
    if(n<0) return 0;

    int i = 1;
    //ek answer variable int max se initialize krdo taaki baar baar answer mein change krne ho to kaam aay
    int ans = INT_MAX;
    //ek last kaha tak iterate krna uske liye end tak sqrt kon si honi chahiye vo lao 
    int end = sqrt(n);
    //loop mein iterate krenge kyuki without loop to just 1 hi case ka answer solve hoga only
    while(i<=end){
        //perfectsquare find krenge 
    int perfectsquare = i * i;
    //ek case hmne kr diya baaki recursion dekh lega
    int  numberofperfectsquare = 1 + numsquarehelper(n-perfectsquare);
    // agr ans bda hai toh answer ko chota number par le aao 
    // kyuki hme chota se chota numbers ka sequence chahiye jo sqrt bna rah ho 
    if(numberofperfectsquare<ans) ans = numberofperfectsquare;
                    i++;
    }
    return ans;

}
int numsquares(int n){
    return numsquarehelper(n)-1;
}

int main(){
    int n;
    cin>>n;
    int ans = numsquares(n);
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}
// Testcase
// Input - 
// 13
// output - 
// 2
// input - 
// 12
// output - 
// 3
