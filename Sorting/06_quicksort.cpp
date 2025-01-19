//quick sort - given an unsorted array 
// 7 | 2 | 1 | 8 | 6 | 3 | 5 | 4
//simply we choose one pivot element such that the elements to the right
//of pivot > a[pivot]
// element left of pivot element < a[pivot]
// we make partition as such as posssible that in the left of pivot all element are 
// small and in the right of the pivot all the larger elements than pivot

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// quick sort simple and good logic is take one pivot element and in the left of pivot 
// take all small elements and in the right of pivot take larger elements

// array -> 7 | 2 | 1 | 8 | 6 | 3 | 5 | 4

// pivot = end
// 1.) pivot = 7
// 2.) i = start - 1 , j = start;
// 3.) a[pivot] = 4;