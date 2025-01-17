#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> asteroidcollision(vector<int>& asteroids){
    stack<int> st;
    for(auto ast : asteroids){
        bool destroy = false;//initially nothing to delete
        if(ast>0){
            st.push(ast);
        }
        else{
            //-ve asteroid
            if(st.empty() || (st.top()<0 && ast < 0)) st.push(ast);
            else{
                //collision
                while(!st.empty() && st.top()>0){
                    if(abs(ast)==st.top()){
                        destroy = true;
                        st.pop();
                        break;
                    }
                    else if(abs(ast) > st.top()){
                        st.pop();
                    }
                    else{
                        destroy = true;
                        break;
                    }
                }
                if(!destroy) st.push(ast);
            }
        }
    }
    vector<int> ans(st.size());
    for(int i = st.size()-1;i>=0;i--){
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
int main(){
    vector<int> asteroids ={-1,3,2,-3};
    vector<int> ans = asteroidcollision(asteroids);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}