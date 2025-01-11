#include<iostream>
#include<string>
using namespace std;
string reverseonlyletters(string& s){
    int low = 0;
    int high = s.size()-1;

    while(low<high){
        if(isalpha(s[low]) && isalpha(s[high])){
            swap(s[low],s[high]);
            low++;
            high--;
        }
        else if(!isalpha(s[low])) low++;
         //h vala alphabet nhi hai toh high-- 
         else high--;
    }
    return s;

}
int main(){
    string s;
    getline(cin,s);
    string ans = reverseonlyletters(s);
    cout<<"After reversing only the letters of the string it will return : "<<ans<<endl;
    return 0;
}
// Test1ng-Leet=code-Q!
// Qedo1ct-eeLg=ntse-T!