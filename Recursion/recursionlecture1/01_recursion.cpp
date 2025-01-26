//recursion - bookish - when a function calls itself directly / indirectly called recursion
//recursion means when solution of bigger problem depend on solution of choti problem of same type
// then we can apply recursion

//3 steps follow to solve the problem of recursion.
//step 1 =  assume fn is done - printN(n) 1 2 3 4 ...... n;
//step 2 =  one simpler case or we can say that recursive case - printN(n-1) 1 2 3 4 ..... n - 1 printf(" %d",n);
//step 3 =  base case n==0
//Write a recursive function to print first N natural number.
// #include<stdio.h>
// void printN(int n){
//     if(n>0){
//         printN(n-1);
//         printf(" %d",n);
//     }
// }
// int main(){
//     int n;
//     printf("Enter the value of n for which till u want that numbers will be print : ");
//     scanf("%d",&n);
//     printN(n);
//     getchar();
//     return 0;
// }



//programme to find first n natural numbers in reverse order 
// #include<stdio.h>
// void printReverseN(int n){
//     if(n>0){
//         printf(" %d",n);
//         printN(n-1);
//     }
// }
// int main(){
//     int n;
//     printf("Enter the value of n for which till u want that numbers will be print : ");
//     scanf("%d",&n);
//     printReverseN(n);
//     getchar();
//     return 0;
// }


// //programme to find first n odd natural numbers
//step 1 = printN(n) 1,3,5 .... 2 * n - 1;
//step 2 = printN(n-1) 1,3,5 .... (n-1) printf("%d",2*n-1);
//step 3 = base case n==0
// #include<stdio.h>
// void printOddN(int n){
//     if(n>0){
//         printOddN(n-1);
//         printf(" %d",2*n-1);
//     }
// }
// int main(){
//     int n;
//     printf("Enter the number till which u want to print the odd natural number : ");
//     scanf("%d",&n);
//     printOddN(n);
//     getchar();
//     return 0;
// }

// //programme to find first n odd natural numbers in reverse order
// //step 1 = printN(n)  2 * n - 1 .... 5.3.1;
// //step 2 = printN(n-1)  printf("%d",2*n-1) n-1 .. 5.3.1;
// //step 3 = base case n==0
// #include<stdio.h>
// void printreverseOddN(int n){
//     if(n>0){
//         printf(" %d",2*n-1);
//         printOddN(n-1);
//     }
// }
// int main(){
//     int n;
//     printf("Enter the number till which u want to print the odd natural number : ");
//     scanf("%d",&n);
//     printOddN(n);
//     getchar();
//     return 0;
// }




// //programme to find first n even natural numbers 
// //step 1 = printN(n) 2,4,6 .... 2 * n;
// //step 2 = printN(n-1) 2,4,6 .... n-1 printf("%d",2*n);
// //step 3 = base case n==0
// #include<stdio.h>
// void printevenN(int n){
//     if(n>0){
//         printevenN(n-1);
//         printf(" %d",2*n);
//     }
// }
// int main(){
//     int n;
//     printf("Enter the number till which u want to print the odd natural number : ");
//     scanf("%d",&n);
//     printevenN(n);
//     getchar();
//     return 0;
// }





// //programme to find first n even natural numbers in reverse order
// //step 1 = printN(n) 2*n ... 4,2;
// //step 2 = printN(n-1)  printf("%d",2*n) n-1 ... 4,2;
// //step 3 = base case n==0
// #include<stdio.h>
// void printevenReverseN(int n){
//     if(n>0){
//         printf(" %d",2*n);
//         printevenReverseN(n-1);
//     }
// }
// int main(){
//     int n;
//     printf("Enter the number till which u want to print the odd natural number : ");
//     scanf("%d",&n);
//     printevenReverseN(n);
//     getchar();
//     return 0;
// }


//recursive function to print square of first n natural number
#include<stdio.h>
void printSquareN(int n){
    if(n>0){
        printSquareN(n-1);
        printf(" %d",n*n);
    }
}
int main(){
    int n;
    printf("Enter the value for which till u want to print the squares : ");
    scanf("%d",&n);
    printSquareN(n);
    getchar();
    return 0;
}