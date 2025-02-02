#include<iostream>
#include<vector>
#include<string>
using namespace std;
//hr row mein kitne number of security device hai yeh pata hone chahiye
// jeise 1st mein 3 hai
// 2nd mein 0
// 3rd mein 2
// 4th mein 1

// 3 0 2 1 => 3 * 0 + 3 * 2  = 6 
//ith row => multiply plus 0 * 2 + = 0
// 2 * 1 = 2 
// 6 + 2 = 8

// 0 1 1 0 0 1 => 3
// 0 0 0 0 0 0 => 0
// 0 1 0 1 0 0 => 2
// 0 0 1 0 0 0 => 1
// 1 1 1 0 1 1 => 5

// 3 * 0 + 3 * 2 = 6
// 0 * 2 = 0
// 2 * 1 = 2 
// 1 * 5 = 5

// 6 + 0 + 2 + 5 = 13

//matlab jeise hi mere pass koi security device vali row aagyi to mein ruk 
// jaunga


int countdevices(string& binary){
    //hmm count kr rah hai ki hr row mein kitni laser beams hai 
    int count = 0;
    for(auto b: binary)
        count += b - '0';
    return count;
}
int laserbeams(vector<string>& s){
    //hm ek array bnayenge jisme hmm devices ka count rkh ske
    vector<int> devices;
    for(auto row : s){
        //hmna ek ek karke string array ko integer array mein  convert krliya uska count krke
        devices.push_back(countdevices(row));
    }
    //hmne ek array bna liya jisme security devices ka count hai
    // for example security device for 1st row = 3 / 2nd row = 0
    // so array is like 3 | 0 | 2 | 1 | 5
    
    int beams = 0;
    for(int i = 0;i<devices.size();i++){
            int j = i + 1;
        while(j < devices.size()){
            beams += devices[i]*devices[j];
            if(devices[j]==0)  j++;
            else break;
        }
    }
    return beams;
}
int main(){
    vector<string> s;
    string temp;
    cout<<"To stop inserting in this array write (END) : ";
    while(cin>>temp){
        if(temp=="END") break;
        s.push_back(temp);
    }
    int ans = laserbeams(s);
    cout<<"Laser beams will act at : "<<ans<<endl;
    return 0;
}
// 011001 000000 010100 001000