//
// Created by vscilab on 11/19/2018.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H

#include <cstdint>
#include <algorithm>    // std::swap

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

    template<class T>
    void mergesort(T array[], size_t size) {
        int64_t arraySize = size+1;
//    sort
        for(size_t i = 0; i < arraySize; i+=2) {
            if (i+1 == arraySize) {
                break;
                } else if (i > i+1){
                std::swap(array[i], array[i + 1]);
                }
            }

//    merge
        //setting exponent for j
        for(size_t i = 2; 2 < arraySize; i++){
            //setting the section size to be analyzed
            for(size_t j = 0; j < arraySize; (j += pow(2, i))){
                size_t x = 0;
                size_t y = x + 1;
                size_t mid = (j + pow(2, i)) + (x * pow(2, y));
                size_t tempSize = (j + pow(2, i));
                T *tempArray = new T[tempSize];
                size_t leftPtr = j;
                size_t rightPtr = mid;
                //the merge code for sorting the values and putting it into the temporary array
                for(size_t k = 0; k < tempSize; k++){
                    //if right side value doesn't exist, skip the step
                    if(rightPtr >= arraySize){
                        rightPtr++;
                        continue;
                    }
                    //if left side value doesn't exist, skip the step
                    else if(leftPtr >= arraySize){
                        leftPtr++;
                        continue;
                    }
                    // when the left side is out of values, copy values from right to the temporary array
                    else if(leftPtr >= mid){
                        tempArray[k] = array[rightPtr];
                        rightPtr++;
                    }
                    // when the right side is out of values, copy values from left to the temporary array
                    else if(rightPtr >= tempSize){
                        tempArray[k] = array[leftPtr];
                        leftPtr++;
                    }
                    //if the left value is greater than the right value, copy the left value to the temporary array
                    else if(array[leftPtr] > array[rightPtr]){
                        tempArray[k] = array[leftPtr];
                        leftPtr++;
                    }
                    //if the right value is greater than the left value, copy the right value to the temporary array
                    else if(array[leftPtr] < array[rightPtr]){
                        tempArray[k] = array[rightPtr];
                        rightPtr++;
                    }
                }
                // the merge code for replacing the real array values with the sorted temporary array values
                for(size_t m = 0; m < tempSize; m++){
                    array[m] = tempArray[m];
                }
                //return the memory
                delete [] tempArray;
            }
        }
    }
}}}}

#endif //EX04_MERGESORT_MERGESORT_H
