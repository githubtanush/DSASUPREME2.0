#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Car{
    public:
            int pos,speed;
            Car(int p,int s) : pos(p),speed(s) {};
};
static bool mycomp(Car& a,Car& b){
    return a.pos < b.pos;
}
int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i = 0; i < position.size();i++){
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),mycomp);
        stack<float> st;
        for(auto car : cars){
            float time = (target - car.pos)/((float)car.speed);
            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
int main(){
    int target  = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int ans = carFleet(target,position,speed);
    cout<<"The car fleet is : "<<ans<<endl;
}
// output = 3;