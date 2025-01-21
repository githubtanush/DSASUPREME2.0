#include<iostream>
using namespace std;
int garbagecollection(vector<string>& garbage, vector<int>& travel){
    //picking time calculation
    int pickp = 0;
    int pickm = 0;
    int pickg = 0;

    int travelp = 0;
    int travelg = 0;
    int travelm = 0;

    int lastp = 0;
    int lastm = 0;
    int lastg = 0;
    
    for(int i = 0; i < garbage.size();i++){
            string s = garbage[i];
            for(char ch : garbage[i]){
                if(ch == 'P'){
                    pickp++;
                    lastp = i;
                }
                else if(ch == 'G'){
                    pickg++;
                    lastg = i;
                }
                else if(ch == 'M'){
                    pickm++;
                    lastm = i;
                }
            }
        }

        for(int i = 0; i < lastp;i++){
            travelp += travel[i];
        }
        for(int i = 0; i < lastg;i++){
            travelg += travel[i];
        }
        for(int i = 0; i < lastm;i++){
            travelm += travel[i];
        }
        
        int ans = (pickp + travelp) + (pickg + travelg) + (pickm + travelm);
        return ans;
}
int main(){
    int n;
    cout<<"Enter the size of the garbage vector : ";
    cin>>n;
    vector<string> garbage(n);
    for(int i = 0; i < garbage.size();i++){
        cin>>garbage[i];
    }

    int size ; 
    cout<<"Enter the size of the traverl array : ";
    cin>>size;
    vector<int> travel(size);
    for(int i = 0; i < size;i++){
        cin>>travel[i];
    }

    int ans = garbagecollection(garbage,travel);
    cout<<"Total time taken by the garbage gaadi is : "<<ans<<endl;

    return 0;
}
// 4
// G P GP GG
// 3
// 2 4 3