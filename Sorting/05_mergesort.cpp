// merge sort is also teach the divide and conquer technique and recursion
//1 case hm solve krenge baaki recursion bhaiya par chod do

//merge sort we divide the array in 2 parts how we divide mid = ( s + e )/2;
//Step 1  -  divide the array
//Step 2  -  recursion bhaiya
//Step 3  -  merge2sortedarray
//Dividde and conquer means phoot daalo or raaj kro

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Time and space complexity 
    // Array length + left array + right array + actual merge n time
// T(n) = k1 + T(n/2)+ T(n/2) + n * k;
// merge krna ka time n ka multiple ka hi kuch lg rah to n * k 
// T(n) = k1 + 2T(n/2) + n * k;
// 2T(n/2) = 2k1 + 2T(N/4) + n/2*k;
// .......
// .......
// T(1) = k1 + baki left right kt jayega + a * n * k
// T(n) = neglect constant + kt gya  + k neglect * a * n;
// T(n) = (a = logn) *n
// so it is T(n) = nlogN
//Space complexity = O(N);




// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include<iostream>
#include<vector>
using namespace std;

//Step 1 = break krlo left and right
//Step 2 = recursion lga do
//Step 3 = merge 2 sorted arrays

void merge(vector<int>& v, int s,int e){
    // mein merge krna chahta hu mid pass bhi kr skta hu nikal bhi skta hu
    int mid = ( s + e )/2;
    //left side ke array ki length nikalna ka liye 
    int n1 = mid - s + 1;
    //right side ke array ki length nikalna ka liye
    int n2 = e - mid;

    //create 2 temporary vectors for left and right 
    vector<int> l(n1),r(n2);

    //copy krla values from original array to left and right array 
    // ta mein ek alg to k index le lena as a 
    //starting index of left array values in original arrays
    int k = s;
    for(int i = 0; i < n1;i++){
        l[i] = v[k];
        k++;
    }
    //k nu mid + 1 lya taaki right array nu copy kr pawa
    k = mid + 1;
    for(int j = 0; j < n2;j++){
        r[j] = v[k];
        k++;
    }
    // hun mein 2 arrays bna chukya with nakli index ta ohnu temporary array vich pa chukya
    // left ta right de 
    // hun actual merge or sort da logic aayga 
    // hun socha left ch i hai right ch j ta jo chota ohnu pehla likhna hai

    // i esliye taaki leftarray mein traverse kr paau
    int i = 0;
    //j esliye taaki rightarray mein traverse kr paau
    int j = 0;
    //main array ka index k se shuru ho rah hai 
    k = s;

    //kbhi bhi mera index esse bahar nhi jaana chahiye common sense vali 
    // baat hai esse bahar gya to out of bound chla jayga
    while(i < n1 && j < n2){
        //ab simple si baat meini puchi kon si value choti hai
        if(l[i] < r[j]) {
            v[k] = l[i];
            i++,k++;
        }
        else{
            v[k] = r[j];
            j++,k++;
        }
    }

    //copy agr koi remaining element reh gya left array ch ta ohnu vi 
    //ehda andar insert kr de
    while(i < n1){
        v[k] = l[i];
        i++;
        k++;
    }
    //Same ki pta right array bch gya hove ta right array ch insert kr 
    //dene hai
    while(j < n2){
        v[k] = r[j];
        j++,k++;
    }
    //Te saada done ho gya merge the code
}

void mergesort(vector<int>& v, int s,int e){
    //base case - empty array ko sort krne ki need hai nhi na or single 
    //element ko bhi sort krne ki  need nhi hai to yeh hi hmara base case 
    // ho gya
    if(s>=e) return ;

    //find mid
    int mid = s + ( e - s )/2;
    // s -> mid -> left array
    // mid+1 -> e -> right array

    //recursion bhaiya ko bulao and 
    //left and right array ko sort krwao
    // recursive call for left array
    mergesort(v,s,mid);
    //recursive call for right array
    mergesort(v,mid+1,e);
    //merge 2 sorted arrays
    merge(v,s,e);

}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    for(int i : v) cout<<i<<" ";
    mergesort(v,0,n-1);
    cout<<endl;
    for(int i : v) cout<<i<<" ";
    return 0;
}  
// 6
//12 11 13 5 6 7