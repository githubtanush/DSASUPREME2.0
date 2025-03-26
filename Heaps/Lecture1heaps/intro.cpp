// Heap - It is a datastructure which is complete binary tree +
//  follow heap property

//C.B.T - Complete binary tree 

//     5      8     9
//    / \    /       \'
//   6   7  9         10

// first two trees are complete binary tree because it covers from left to right
// and the third which empty its left and filled from right is not validate heap property


//Heap follows 2 property 
// first property is minheap 
// second property is maxheap 

//minheap = It means that parent node element always less than their child node elements
//maxheap = It means that parent node element always greater than their child node elments


//real implementation of heap is done with array 
//but visualize with tree but implementation is done by array
//1 - based indexing // 0-based indexing two types of indexing is there


//1 - based indexing                    0-based indexing
//i -> i / 2 (parent node)              i -> i / 2 (parent node)
//left child -> 2 * i                   left child -> 2 * i + 1;
//right child -> 2 * i + 1              right child -> 2 * i + 2;

//heap - Visualize by tree and implement with array 

//insert 5 at the vacant position
//      100    
//     /   \   
//    50   60 
//   / \   / \'
//  40 30 20  vacnt insert 75

//1.) insert 75 into vacant and then 
//2.) place 75 to the correct position

//element bottom to top or top to bottom.
// This function generally known as heapify 
