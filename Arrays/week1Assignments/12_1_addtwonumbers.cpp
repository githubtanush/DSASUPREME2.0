#include<iostream>
using namespace std;
string calc(int arr[1000],int n,int brr[1000],int m){
    int carry = 0;
    int i = n - 1;
    int j = m - 1;
    string ans;
    //meini ek ek krke sbke element plus kiya 
    while(i>=0 && j>=0){
        int x = arr[i] + brr[j] + carry ;
        int digit = x%10;
        ans.push_back(digit+'0');
        carry = x/10;
        i--;
        j--;
    }
    //agr arr ka kuch bch gya ho or brr khatam ho gya ho
    while(i>=0){
        int x = arr[i] + 0 + carry ;
        int digit = x%10;
        ans.push_back(digit+'0');
        carry = x/10;
        i--;
    }
    //agr brr ka kuch bch gya ho or arr khatam ho gya ho 
    while(j>=0){
        int x = 0 + brr[j] + carry ;
        int digit = x%10;
        ans.push_back(digit+'0');
        carry = x/10;
        j--;
    }
    //string bnakar return krna hai 
    if(carry){
        ans.push_back(carry+'0');
    }
    //agr intially kuch zeroes hai add krna ka baad number mein to voh nhi store hona chahiye 
    //int mein to asa manage nhi krna pdta but string mein hma manage krna pdta
    while(ans[ans.size()-1]=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int arr[1000];
    int n;
    cin>>n;
    for(int i = 0; i  < n;i++){
        cin>>arr[i];
    }
    int brr[1000];
    int m;
    cin>>m;
    for(int i = 0; i  < m;i++){
        cin>>brr[i];
    }
    string ans = calc(arr,n,brr,m);
    cout<<"The sum of this two strings will be : "<<ans<<endl;
    return 0;
}         
// 6
// 0 9 0 0 3 5
// 6
// 0 0 0 2 2 7