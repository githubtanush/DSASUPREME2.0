//What is Array ? - It is a datatype in which we store the data
// Array is a list of similar items
// It is a collection of elements
// It is a data structure
//It is a contiguous subarrray block


// #---------------------------------------------------------------------------------------------------------------------------------------------



//Why Array? - to not initialize a variable again and again 
//or we can say that instead making 10,000 variable we use the data structure in which we 
//store the 10,000 elements;

//by written like this int arr[10000];
//we have created the memory location of 10,0000 elements;
//if we create int array then 1location save 4 byte so 4 * 10,000 = 40,0000 size of array is created


// #---------------------------------------------------------------------------------------------------------------------------------------------


// //creation of array
// int memory[127]; //size = 4 * 127 = 508
// bool memory[500];//size = 1 * 500 = 500
// char memory [26]; //size = 1 * 26 = 26
// long num[500];//size = 8 * 500 = 4000
// short num[1000];//size = 4 * 1000 = 4000

// #---------------------------------------------------------------------------------------------------------------------------------------------

//Symbol table = int a = 5;
//int likhna se reality mein yeh hota hai ki ek block mein 5 store ho jata uska kuch address hoga
//then ek symbol table create hoga jisme mapping ki jaygi apka address ki apka symbol se 
//es tarah se symbol table create ho jayga
// so a map ho jayga 5 se
// #---------------------------------------------------------------------------------------------------------------------------------------------

// jitna dry run kroga utna sikhoga esliye jada se jada dry run krne ki koshish kro

// #---------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
// void printarray(int arr[],int n){
//     for(int i = 0; i < n;i++) cout<<arr[i]<<" ";//mostly for each loops iteration work mostly on vectors or dynamic arrays
// }
// #---------------------------------------------------------------------------------------------------------------------------------------------
bool linearsearch(int arr[],int target,int n){
    for(int i = 0; i < n;i++){
        if(target == arr[i]) return true;
    }
    return false;
}
int main(){
    //Static array = where size is fixed
    //ways to initialize array in cpp
    // int arr[] = {1,2,3,4,5};
    // int brr[5] = {1,2,34,4,5};
    // int crr[5] = {2,3};
    // //error 
    // int drr[2] = {1,2,3,44,5};

    //if we want to create the array on user input then 
    //int n;
    // cin>>n;
    // int arr[n]; BAD PRACTICE because ab maanlo mera c++ programme ko 
    //memory allocate hui hai 10 byte ki or hmna etna element likh diya ki 100 bytes ki space 
    //le rah to vo error through krega yeh glt ho jayga esliye yeh vali  practice ko bad practice maana
    //jata kyuki kya pata utni contiguous memory available hi na ho jitna yaah par demand krr rah hai
    //esliye es error ko htana ka liye hm use krte hai dynamic array ka 




// #---------------------------------------------------------------------------------------------------------------------------------------------
    // indexing in array this is 0-based indexing and last element is always at (n-1)index
    // int arr[5] = {5,8,9,12,13};
    // // cout<<arr[0]<<endl;
    // // cout<<arr[1]<<endl;
    // // cout<<arr[2]<<endl;
    // // cout<<arr[3]<<endl;
    // // cout<<arr[4]<<endl;
    
    // //print with for loop
    // int n = 5;
    // for(int i = 0; i < n;i++){
    //     cout<<arr[i]<<" ";
    // }

    // //Taking input in an array
    // int brr[5];
    // for(int i = 0 ; i < n;i++){
    //     cin>>arr[i];
    // }



// #---------------------------------------------------------------------------------------------------------------------------------------------
    //formula to find arr[i]
    //value at (base address + (datatype size * index));
    //let say example - we have the array of size 5
    // 2 at 104 index
    // 4 at 108 index 
    // 6 at 112 index
    // 8 at 116 index
    // 10 at 120 index

    // then if we find arr[2] we apply that formula like this 
    // arr[2] = value at(104 + (4 * 2));
    // arr[2] = value(104 +(8));
    // arr[2] = value(112);

// #---------------------------------------------------------------------------------------------------------------------------------------------
    //problem = 1.) 10 size array 2.) take input 3.) double up each value
    // int n = 10;
    // int arr[10];
    // for(int i = 0; i < n;i++){
    //     cin>>arr[i];
    // }
    // // for(int i = 0; i < n;i++) cout<<2*arr[i]<<" ";
    // for(int i : arr) cout<<2*i<<" ";


// #---------------------------------------------------------------------------------------------------------------------------------------------
    //problem = 1.) 5 size array 2.) 5 size input 3.) total sum print
    // int n = 5;
    // int brr[5];
    // int sum = 0;
    // for(int i= 0; i < n;i++) cin>>brr[i];
    // for(int i = 0; i < n;i++) sum += brr[i];
    // cout<<"Total sum for this elements is : "<<sum<<endl;

// #---------------------------------------------------------------------------------------------------------------------------------------------
    // // //Linear search in the array 
    // int arr[6] = {2,4,6,8,10,12};
    // int n = 6;
    // int target = 10;
    // bool flag = 0;
    // // 0 -> not found 1->found
    // for(int i = 0; i < n;i++){
    // if(arr[i] == target){
    //     cout<<i<<endl;
    //     flag = 1;
    //     break;
    // }
    // }
    // //ab agr target mila hota to loop ke bich mein se bahar aa jata or agr nhi mila hota
    // //to poora loop krke bahar aata ab hm yeh kaise pata lagay ki target mila ya nhi 
    // //to ab aata flag ka concept agr flag red gaadi aaga nhi jaaygi nhi to jaaygi
    // if(flag) cout<<"Found"<<endl;
    // else cout<<"Not Found"<<endl;





// #---------------------------------------------------------------------------------------------------------------------------------------------
//  Arrays and functions ek baat par gaath band lo ki jab jab array pass krenge tab tab uska size bhi pass krenge
// vector array ko pass by refrence krna pdta lekin int arr[] by default pass by refrence hi hota
// int n = 5;
// int arr[100];
// for(int i = 0; i < n;i++) cin>>arr[i];
// printarray(arr,n);

// #---------------------------------------------------------------------------------------------------------------------------------------------
    // int arr[5] = {2,4,6,8,10};
    // int n = 5;
    // int target = 10;
    // bool ans = linearsearch(arr,target,n);
    // if(ans) cout<<"Target Found"<<endl;
    // else cout<<"Target Not Found"<<endl;



    return 0;
}
// 1 2 3 4 5 6 7 8 9 10
// 2 4 6 8 10 12 14 16 18 20

