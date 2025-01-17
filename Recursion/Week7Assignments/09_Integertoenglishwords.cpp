#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,string> > mp = {{1000000000,"Billion"},{1000000,"Million"},{1000,"Thousand"},{100,"Hundred"},{90,"Ninety"},
{80,"Eighty"},{70,"Seventy"},{60,"Sixty"},{50,"Fifty"},{40,"Forty"},{30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},
{18,"Eighteen"},{17,"Seventeen"},{16,"Sixteen"},{15,"Fifteen"},{14,"Fourteen"},{13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},
{10,"Ten"},{9,"Nine"},{8,"Eight"},{7,"Seven"},{6,"Six"},{5,"Five"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}};

string numbertowords(int num){
    //base case
    if(num==0) return "Zero";

    //iterate
    for(auto it:mp){
        if(num>=it.first){
            string a = "";
            //kitne hundreds hai hme bus yeh count rkhna 
            //yeh thori count rkhna kitne kitne 20 hai kitne 15 hai vgera vgera
            //recursive case
            if(num>=100) a = numbertowords(num/it.first) + " ";
            string b = it.second;
            string c = "";
            if(num % it.first != 0){ //kyuki 20 15 jitne bhi yeh chota chota number hai en sab ke case
            // mein to 0 aajayga or vese bhi yeh aise hi return krne hai 
             c = " " + numbertowords(num % it.first) ;
            }
            return a + b + c;
        }
    }
    return "";
}
int main(){
    int num;
    cin>>num;
    string ans = numbertowords(num);
    cout<<"answer in english is : "<<ans<<endl;
    return 0;
}
// 1234567
// One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven