#include<iostream>
#include<set>
#include<vector>
using namespace std;
//brute force (naive solution) - when we iterate from each and every pair of element
//mst approach - 2 pointer approach
//different pairs chahiye to use set for take distinct pairs

int bs(vector<int>& nums,int s,int x){
    //x is that element in the nums which we find to make nums[j]-nums[i] == k
    int e = nums.size()-1;
    while (s <= e ){
        //finding mid
        int mid = s + ( e - s )/2;
        //if nums[mid] equals that x element
        if(nums[mid]==x) return mid;
        //if that x element greater than the nums[mid]
        else if( x > nums[mid] ) s = mid + 1;
        //else mid - 1;
        else e = mid - 1;
    }
    return -1;
}
int findpairs(vector<int>& nums,int k ){
    //method 1 - brute force(naive force)
    // set<pair<int,int> > ans;
    //     int n = nums.size();
    //     for(int i = 0; i < n;i++){
    //         for(int j = i + 1; j < n;j++){
    //             int diff = abs(nums[i]-nums[j]);
    //             if(diff == k){
    //                 ans.insert({nums[i],nums[j]});
    //             }
    //         }
    //     }
    //     return ans.size();

    // //method 2 - two pointer approach
    // ios::sync_with_stdio(0);
    //     cin.tie(0);
    //     //simply firstly we sort the array 
    //     sort(nums.begin(),nums.end());
    //     //we declare count variable to track the unique pairs
    //     int count = 0;
    //     //ek set declare krunga jisme unique pairs ko rkhunga
    //     set<pair<int,int> > ans;
    //     //then we initalize the two pointer with i = 0 j = 1
    //     //so that we find unique pairs in the array 
    //     int i = 0, j = 1;
    //     //mein j ko less than array ka size tk check krunga
    //     while( j < nums.size() ){
    //         //mein difference find krunga or check krunga ki vo k ke brabar hai ya nhi
    //         int diff = nums[j] - nums[i];
    //         //agr difference k ke brabar hua toh
    //         //ans mein store krunga 
    //         //or i , j ko aaga bda dunga
    //         if(diff == k){
    //         ans.insert({nums[i],nums[j]});
    //         cout<<nums[i]<<" "<<nums[j]<<endl;
    //             i++;
    //             j++;
    //         }
    //         //agr difference bda hua toh mein simply sirf i ko aaga bdaunga
    //         else if(diff > k ){
    //             i++;
    //         }
    //         //nhi to j ko aaga bda dunga
    //         else{
    //             j++;
    //         }
    //     // agr i j ko brabar hua turant usko aaga bda do kyuki i j ka brabar ho gya toh unique pairs ni aayenge
    //     if(i==j) j++;
    //     }
    //     return ans.size();

    //Method 3 - binary search
        //pehle to mein sort hi krunga 
        sort(nums.begin(),nums.end());
        //then mein jaadu krunga matlab set name ka ans array lunga or usme unique pairs ko insert krwaunga
        set<pair<int,int> > ans;
        //then mein for loop chlaunga array ke end tak traverse krne ke liye
        for(int i = 0; i < nums.size();i++){
            //phir mein binary search mein check krunga
            //main thing we use in binary search is that nums[i] + k 
            //how we find these 
            //we simply take nums[j]-nums[i] = k
            //we simply solve this to nums[j] = nums[i] + k ;
            //Then there we will able to apply binary search
            if(bs(nums,i+1,nums[i] + k) != -1) ans.insert({nums[i],nums[i] + k});
        }
        return ans.size();
    }
//T.C - O(Nlogn);
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Give the input to the array : ";
    for(int i = 0;i < n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    int k;
    cout<<"Enter how many unique pairs of what difference do you want : ";
    cin>>k;
    int ans = findpairs(nums,k);
    cout<<"The number of unique pairs are : "<<ans<<endl;
    return 0;
}

// 5 
// 1 1 3 4 5 