#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_
#include <vector>
using namespace std;
using std::vector;

/*
 * insertionSort function 
 * builds the final sorted array one item at a time.
 * 
 */
long long insertionSort(vector<int> &input){
    
    //initialize the elements
    int i=0;
    int j=0;
    int temp=0;
    long len=0;
    long count=0;
    len=input.size();
    
//for loop here to check every elements in the input vector
    for (i=1;i<len;i++){
        for (i=1;i<len;++i){
            j=i;
            while (j>0 && input[j-1]>input[j]){
                temp=input[j];
                input[j]=input[j-1];
                input[j-1]=temp;
                j--;   
                count+=1;
            }    
        }
    }
    return count;
    
}
#endif
