#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include <vector>
#include "InsertionSort.h"
using namespace std;
using std::vector;

/*
 * quickSort function 
 * find a pivot and compare the others with it 
 * smaller ones to the left and larger one to the right
 * then recursivly to make the elements sorted
 * 
 */
long long quickSort(vector<int> &input){
    long count=0;//initialize the comparison count
    if (input.size()>1){
        //make new vectors in order to push back
        vector<int>left;
        vector<int>same;
        vector<int>right;
        int pivot=input[input.size()/2];//find pivot to compare with elements
         //for loop here to check all the elements and compare with pivot
        for (auto i:input){
            if (i<pivot)
                left.push_back(std::move(i));
            else if (pivot<i)
                right.push_back(std::move(i));
            else
                same.push_back(std::move(i));
            count++;
        }

        //recursive functions
        count+=quickSort(left);
        count+=quickSort(right);
        std::move(begin(left),end(left),begin(input));
        std::move(begin(same),end(same),begin(input)+left.size());
        std::move(begin(right),end(right),end(input)-right.size());
        
    }
    return count;

}
#endif

