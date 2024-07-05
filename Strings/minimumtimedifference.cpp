#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int converttomins(string& mins){
    //hm minute mein convert kr rah hai to hm pehle string ko integer mein laayenge stoi function se
    //and then usme substring pass krenge
    int hr = stoi(mins.substr(0,2));
    int min = stoi(mins.substr(3,2));
    //abhi to hr and min sirf integer mein aay unko minutes mein convert krne ke liye hmm es formula ka use krenge
    return ((60 * hr)+ min);

}
int findmindifference(vector<string>& timepoints){
    //now ab hmee difference nikalna to pehle hmmm minute mein le aaynga hour ki jagah 
    vector<int> mins;
    for(auto mini: timepoints){
        mins.push_back(converttomins(mini));
    }
    //minutes mein convert hone ke baad hmm esa sort kr lenge
    sort(mins.begin(),mins.end());
    //ek answer initialize krlenge intmax se kyuki hmme minimum difference nikalna hai 
    int ans = INT_MAX;

    // then ab hmm compare krenge ki minimum difference kitna hai 
    for(int i = 0; i < mins.size()-1;i++)
            ans = min(ans,mins[i+1]-mins[i]);
        
    //if agr 24:00 or 0:00 bje vali side se koi jada km minimum difference hua phir kyu sidhi side vala mindifference nikala
    //so esliye jo mins array par 0 position par pda hai usme 1440 plus krke usko jo last position par sort krke 
    // khra hai usse subtract kr dena taki enka bhi difference pata lg jaay agr yeh km nikla to that is also a valid result
    //loop chlana ki need nhi first or last ko minus krna hai bss
    int lastdiff = mins[0] + 1440 - mins[mins.size()-1];
    ans = min(ans,lastdiff);

    return ans;
}
int main(){
    vector<string> s;
    string tempo;
    cout<<"When u stop to take an input write (END) in capital letters : ";
    while(getline(cin,tempo)){
        if(tempo=="END") break;
        s.push_back(tempo);
    }
    int ans = findmindifference(s);
    cout<<"The minimum time difference in minutes will be : "<<ans<<endl;

    return 0;
}
// 23:59 00:00
// 00:00 23:59 00:00