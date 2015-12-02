#ifndef _VERIFYSORT_H_
#define _VERIFYSORT_H_
#include <vector>
using namespace std;


bool verifySort(vector<int> &input){
    //for loop here to check every elements in input vector
    for (int i=1; i<input.size();i++ ){
        if (input[i-1]>input[i]){
            return false;//if a number smaller than previous one,return false
        }
    }
    return true;//all the elements are sorted
}

#endif
