#include<iostream>
using namespace std;
void addre(string& num1,int p1,string& num2,int p2,string& ans,int carry){
        //Base case
        if(p1<0 && p2<0) {
            if(carry != 0){
                ans.push_back(carry + '0');
            }
            return ;
        }
        
        //ek case solve krdo 
        int n1 = (p1>=0 ? num1[p1] : '0') - '0';
        int n2 = (p2>=0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry ;
        int digit = csum % 10;
        carry = csum /10;
        ans.push_back(digit + '0');

        //Recursively
        addre (num1,p1-1,num2,p2-1,ans,carry);
    }
    string addStrings(string& num1, string& num2) {
    string ans = "";
    addre(num1,num1.size()-1,num2,num2.size()-1,ans,0);
    reverse(ans.begin(),ans.end());
    return ans;
    }
int main(){
    string num1;
    getline(cin,num1);
    string num2;
    getline(cin,num2);

    string ans = addStrings(num1,num2);
    cout<<"After adding the string formed will be : "<<ans<<endl;

    return 0;
}
//11
//123
//output - 134

//456
//77
//output - 533