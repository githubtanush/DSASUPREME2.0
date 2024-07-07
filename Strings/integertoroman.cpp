#include<iostream>
#include<string>
using namespace std;
string inttoroman(int num){
    //sbse pehle ek string array bna lenge jisme roman ke saara characters rkh lenge jine baad mein map krenge
    string romanSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    //phir ek integer array bnayenge taaki map kr pay en sbko
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    //ek nyi string jo ki return hogi end mein value store krke
    string ans = "";
    for(int i = 0;i < 13;i++){
        while(num>=values[i]){
            ans += romanSymbols[i];
            num = num - values[i];
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number which u want to convert into Roman : ";
    cin>>n;
    string ans = inttoroman(n);
    cout<<"Roman number for this integer is :  "<<ans<<endl;
    return 0;
}
// input - 3749
// output - MMMDCCXLIX