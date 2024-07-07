#include<iostream>
#include<vector>
using namespace std;
vector<int> factorial(int n){
    vector<int> ans;
    //pehle hmm esma 1 push krke rkhta hai vo multiplication ke liye thik hai
    ans.push_back(1);
    //carry ko 0 se initialize kr diya
    int carry = 0;
    //for loop start
    for(int i = 2;i <= n;i++){
        for(int j = 0; j < ans.size();j++){
            int x = ans[j]*i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while(carry){
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> ans = factorial(n);
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
//50
//output - 30414093201713378043612608166064768844377641568960512000000000000            