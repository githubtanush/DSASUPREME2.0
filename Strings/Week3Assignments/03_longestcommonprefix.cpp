#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longestcommonprefix(vector<string>& strs){
    string ans;
    //iterate krne ke liye i variable jruri hai
    int i = 0;
    while(true){
        //current character 0 le liya
        char curr_ch = 0;
        for(auto str: strs){
            //agr kisi bhi string ka size out of bound ho gya toh esliye
            if(i>=str.size()){
                //out of bound
                curr_ch = 0;
                break;
            }
            //just started
            if(curr_ch==0){
                curr_ch = str[i];
            }
            else if(str[i] != curr_ch){
                curr_ch = 0;
                break;
            }
        }
        if(curr_ch == 0) break;

        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}
int main(){
    vector<string> s;
    string temp;
    cout<<"To stop inserting in this array write (END) : ";
    while(cin>>temp){
        if(temp=="END") break;
        s.push_back(temp);
    }
    string ans = longestcommonprefix(s);
    cout<<"Longest common prefix in the string s is : "<<ans<<endl;
    return 0;
}
// flower flow flight