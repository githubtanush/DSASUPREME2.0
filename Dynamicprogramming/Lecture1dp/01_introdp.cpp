//What is dynamic programming?
//if u forgot old mistakes then u replay 
//that mistakes again and again

//for example - if u ask 5 rupees how many tofees ?
// 3 rupees how many tofees?
// 1 rupees how many tofees?
//then u ask this this same 3 questions again and again then this is not good na ?
//because if we ask again and again means we repeat this mistakes again and again 
//so store them in one place so that we can't make same mistakes again and again 

//Dynamic programming is a programming technique which is 
// used when there are this 2 types of problem are there : 
// 1.) Overlapping subproblem
// 2.) Optimal substructure


//Overlapping subproblem means like 
//          f(4)
//         /     \'
//       f(3)     f(2) //at that line we find f(2)
//       /  \     /   \'
//     f(2) f(1) f(1) f(0) //but at that line we again find f(2)
//     / \    
//  f(1) f(0) // so these type of problems called 
//overlapping problem 


//Optimal substructre is that when the biggest 
//problem optimal solution depends
// on same type small problem optimal solution are 
//known as optimal substructure problem

//Dynamic programming - simply means same problem baar baar solve kr rah ho 
//Dp means ek baar jo meini problem solve kr di vo to mein dobara solve hi nhi krta 
// recursion kehta tha 1 case mera baaki tera
//Dp is just a storage used for storing a number only bss yeh yaad rkhna 

// We can do question in DP in three ways : 
// 1.) Top-Down approach - Recursion + memoization (recursive approach)
// 2.) Bottom-Up approach - Tabulation method (iterative approach)
// 3.) patterns - Space Optimization 

//Bottom-Up more prefer because in bottom there is no function-Overhead occur
// while in top-down there is recursive so function call overhead is involved

//Dp recursion ka chacha hai yeh yaad rkho bss