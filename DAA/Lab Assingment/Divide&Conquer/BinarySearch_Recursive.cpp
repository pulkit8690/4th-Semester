#include<iostream>
using namespace std;
int binSearch(int* a,int s,int e, int key)
{
    if(s>e)
    {
        return -1;
    }
    else
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
        return mid;
        if(key<mid)
        return binSearch(a,s,mid-1,key);
        else
        return binSearch(a,mid+1,e,key);
    }
}
int main()
{
    int a[5]={8,56,65,75,100};
    int result = binSearch(a,0,4,56);
    if(result==-1)
    {
        cout<<"NOT";
    }
    else
    {
        cout<<result;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
  
// // A recursive binary search function. It returns
// // location of x in given array arr[l..r] is present,
// // otherwise -1
// int binarySearch(int arr[], int l, int r, int x)
// {
//     if (r >= l) {
//         int mid = l + (r - l) / 2;
  
//         // If the element is present at the middle
//         // itself
//         if (arr[mid] == x)
//             return mid;
  
//         // If element is smaller than mid, then
//         // it can only be present in left subarray
//         if (arr[mid] > x)
//             return binarySearch(arr, l, mid - 1, x);
  
//         // Else the element can only be present
//         // in right subarray
//         return binarySearch(arr, mid + 1, r, x);
//     }
  
//     // We reach here when element is not
//     // present in array
//     return -1;
// }
  
// int main(void)
// {
//     int arr[] = { 2, 3, 4, 10, 40 };
//     int x = 10;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int result = binarySearch(arr, 0, n - 1, x);
//     (result == -1)
//         ? cout << "Element is not present in array"
//         : cout << "Element is present at index " << result;
//     return 0;
// }