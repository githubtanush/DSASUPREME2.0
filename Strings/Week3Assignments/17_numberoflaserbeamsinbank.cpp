#include<iostream>
#include<vector>
#include<string>
using namespace std;
int countdevices(string& binary){
    //hmm count kr rah hai ki hr row mein kitni laser beams hai 
    int c = 0;
    for(auto b: binary)
        c += b - '0';
    return c;
}
int laserbeams(vector<string>& s){
    //hm ek array bnayenge jisme hmm devices ka count rkh ske
    vector<int> devices;
    for(auto row : s){
        //hmna ek ek karke string array ko integer array mein  convert krliya uska count krke
        devices.push_back(countdevices(row));
    }
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