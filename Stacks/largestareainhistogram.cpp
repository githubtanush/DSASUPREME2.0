#include<iostream>//to include all input output files
#include<vector>//to include the vector array
#include<stack>//to include the stack parameters
using namespace std;// to give information that we use standard cin cout

vector<int> nextsmallerelement(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);

        for(int i = arr.size()-1; i >=0; i--){
            int curr = arr[i];
            //answer find kro curr ke liye
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
}


// to finding that how much i extend we find the previous smaller elements that how long they have
vector<int> prevsmallerelement(vector<int> arr){
    vector<int> ans(arr.size());
    stack<int> st;
        st.push(-1);

        for(int i = 0; i < arr.size(); i++){
            int curr = arr[i];
            //answer find kro curr ke liye
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;




}
//find the largest rectangle area covered in histogram
int largestrectanglearea(vector<int>& heights){
    vector<int> next = nextsmallerelement(heights);

    for(int i = 0; i < next.size();i++){
        if(next[i]==-1) next[i] = heights.size();
    }
        
    vector<int> prev = prevsmallerelement(heights);

    vector<int> area(next.size());

    for(int i = 0; i < next.size();i++){
        int width = next[i]-prev[i]-1;
        int length = heights[i];
        int currArea = width*length;
        area[i] = currArea;
    }
    int maxi = INT_MIN;
    for(int i = 0; i < area.size();i++){
        maxi = max(maxi,area[i]);
    }
    return maxi;

}
int main(){
    int n;
    cout<<"Enter the size of the height array : ";
    cin>>n;
    vector<int> height(n);
    for(int i = 0; i < n;i++){
        cin>>height[i];
    }
int answer = largestrectanglearea(height);
cout<<"Maximum Area Covered In The Histogram is : "<<answer<<endl;
    return 0;
}
// 6
// 2 1 5 6 2 3 