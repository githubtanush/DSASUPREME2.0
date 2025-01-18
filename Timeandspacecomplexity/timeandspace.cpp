//what is time complexity ?
//1.) Amount of time taken by an algorithm to run as a function of length of input.
//example - for(int i = 0; i < n;i++){ //operation cout <<"Hello"<<endl;} 
//means we can say that timecomplexity depend on the length of the input if we increase the 
//n so time complexity also increases means esme time complexity ka matlab yhi hai ki apki algorithm
//cpu ka kitna time waste kr rahi hai matlab yeh apka actual time nhi hota yeh time complexity ka 
//matlab hai apka cpu operations and in the generic way we defined apka jo yeh time hai na 
//voh directly proportional hai eski input ki length par eski input ki length par time 
//complexity depend krti hai
// so time complexity is directly proportional to the length of the input 
// T.C = O(n)




//why we study Time and space complexity ?
// 1.) Good computer engineer always thinks about the complexity of the code written by him.
// 2.) Resources are limited.
// 3.) Measure algorithm to make efficient programs. example - algo a and algo b which is best
// 4.) Asked by interviewer after every solution you give.


//What is Space Complexity ?
// 1.) Amount of space taken by an algorithm to run as a function of length of input
// time complexity as a function of length of input hoti hai same aise hi 
// space complexity as a function of lenght of input hoti hai 


// example - int ab = new int[n]


//Units to Represent Complexity 
// 1.) Big O: Upper bound / Worst case
// 2.) Theta 0: Average case
// 3.) Omega Ω: Lower bound / best case 

// example - search in array of length 6 and given element 1 2 3 4 5 6 
// item found - 1  we can find 1 in O(1)
//but same time we can find 6 in O(n)
// so big o means your's algorithm max to max how many time will take so big o is better representation
// worst case - O(n) best case - O(1) average case - O(N/2)
// worst case jada use krta hai kyuki hm yhi dekhna chahta hai ki jab bura se bura time aata
//to apki algorithm keise chlti hai worst se worst case mein how that your algorithm will work
// so we will talk more on big O


//Big O: Complexities
//1.) Constant time: O(1) graph - number of cpu operations vs n 0-3,1-3,2-3
//2.) Linear time: O(N) graph - number of cpu operations vs n 1-1,2-2,3-3
//3.) Logarithmic time: O(logN) graph - number of cpu operations vs n 1-2,2-4,3-9
//4.) Quadratic time: O(N^2)
//5.) Cubic time: O(N^3)


//example - f(n) = 2n^2 + 3n => O(2n^2) => O(n^2)
// f(n/4) = O(N/4) = O(N)


//least to more complexity - 
// O(1),O(logN),O(sqrt(N)),O(N),O(NlogN),O(N^2),O(N^3),O(2^n),O(N!),O(N^n)
//Least complexity - O(1)
//Most complexity - O(N^n);


//array = 1/2/3/4/5/6/7
//Linear search - O(N);
//Binary search - O(logN);
//N->N/2->N/4->N/8 ________ -> N/2^k
//N = 2 ^ k
//logN = log2^K
//k = logN



//find time complexity ->
//for{},for{} => O(N) + O(M) => O(N);
//for{for{}},for{} =>O(N*N) + O(N)=> O(N^2);
//for{for{}} =>O(N*N) => O(N^2);

//Space complexity ->
//array[5] =>O(1);
//int *a = new int[N] =>O(N);
//int *b = new int[N^2] =>O(N^2);


//least to more complexity - 
// O(1),O(logN),O(sqrt(N)),O(N),O(NlogN),O(N^2),O(N^3),O(2^n),O(N!),O(N^n)
//Least complexity - O(1)
//Most complexity - O(N^n);