#include<iostream>
#include<vector>
using namespace std;
int countingdearrangements(int n){
    //Base case
    if(n==1 || n==2) return n-1;
    
    //if we take 1 element from array and uski ith position hmna fix krdi 
    //then hmara pass ek equation aaygi and that equation is : (n-1) * countingdearrangements(n-1);
    //and then maanlo hmne uss ith position ke element ko 1st element se swap kr dia 
    //then swap krne ke baad do element ki position fix hogi matlab n-2 element reh gay solve krna then 
    //equation form is : (n-1) * countingdearrangements(n-2);
    // and then we return this 
    return (n-1)*(countingdearrangements(n-1) + countingdearrangements(n-2));
}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    int ans = countingdearrangements(n);
    cout<<ans<<endl;
    return 0;
}