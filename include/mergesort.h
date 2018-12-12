//
// Created by vscilab on 11/19/2018.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H

#include <cstdint>
#include <algorithm>    // std::swap
#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

    template<class T>

    void mergesort(T array[], size_t size) {
        int64_t arraySize = size;
//    sort
        for (size_t i = 0; i < arraySize; i++) {
            std::cout << "Before sort: " << array[i] << std::endl;
        }
        for (size_t i = 0; i < arraySize; i += 2) {
            std::cout << "i = " << i << ", i+1 = " << i + 1 << ", arraySize = " << arraySize << std::endl;
            if (i + 1 == arraySize) {
                break;
            } else if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
            }

        }
        for (size_t i = 0; i < arraySize; i++) {
            std::cout << "After sort: " << array[i] << std::endl;
        }

//    merge
        //setting exponent for j
        int y = 1;
        T *tempArray;
        for (size_t i = 2; i < 4; i++, y++) {
            //setting the section size to be analyzed
            int x = 0;
            std::cout << "i = " << i << ", x = " << x << ", y = " << y << ", arraySize = " <<
                      arraySize << std::endl;
            for (size_t j = 0; j < arraySize + 2; (j += pow(2, i)), x++) {
                size_t mid = (j + pow(2, i)) / 2 + (x * pow(2, y));
                size_t tempSize = (pow(2, i));
                std::cout << "before alloc: "<< tempSize << std::endl;
                tempArray = new T[tempSize];
                std::cout << "after alloc" << std::endl;
                size_t leftPtr = j;
                size_t rightPtr = mid;
                std::cout << "i = " << i << ", j = " << j << ", x = " << x << ", y = " << y << ", mid = " << mid <<
                          ", tempSize = " << tempSize << ", leftPtr = " << leftPtr << ", rightPtr = " << rightPtr <<
                          ", arraySize = " << arraySize << std::endl;
                //the merge code for sorting the values and putting it into the temporary array
                for (size_t k = 0; k < tempSize; k++) {
                    // when the left side is out of values, copy values from right to the temporary array
                    if (leftPtr >= mid) {
                        tempArray[k] = array[rightPtr];
                        rightPtr++;
                        std::cout << "rightPtr = " << rightPtr << ", mid = " << mid << std::endl<< std::endl;
                        std::cout << "the value that went into temp array is: " << tempArray[k] << std::endl << std::endl;
                    }
                        // when the right side is out of values, copy values from left to the temporary array
                    else if (rightPtr >= tempSize) {
                        tempArray[k] = array[leftPtr];
                        leftPtr++;
                        std::cout << "leftPtr = " << leftPtr << ", tempSize = " << tempSize << std::endl << std::endl;
                        std::cout << "the value that went into temp array is: " << tempArray[k] << std::endl << std::endl;
                    }
                        //if right side value doesn't exist, skip the step
                    else if (rightPtr >= arraySize) {
                        rightPtr++;
                        k--;
                        std::cout << "rightPtr = " << rightPtr << ", arraySize = " << arraySize << std::endl << std::endl;
                        std::cout << "the value that went into temp array is: nothing" << std::endl << std::endl;
                    }
                        //if left side value doesn't exist, skip the step
                    else if (leftPtr >= arraySize) {
                        leftPtr++;
                        k--;
                        std::cout << "leftPtr = " << leftPtr << ", arraySize = " << arraySize << std::endl << std::endl;
                        std::cout << "the value that went into temp array is: nothing" << std::endl << std::endl;
                    }
/*                    // when the left side is out of values, copy values from right to the temporary array
                    else if(leftPtr >= mid){
                        tempArray[k] = array[rightPtr];
                        rightPtr++;
                        std::cout << "rightPtr = " << rightPtr << ", mid = " << mid << std::endl;
                    }
                    // when the right side is out of values, copy values from left to the temporary array
                    else if(rightPtr >= tempSize){
                        tempArray[k] = array[leftPtr];
                        leftPtr++;
                        std::cout << "leftPtr = " << leftPtr << ", tempSize = " << tempSize << std::endl;
                    }*/
                        //if the left value is greater than the right value, copy the left value to the temporary array
                    else if (array[leftPtr] < array[rightPtr]) {
                        tempArray[k] = array[leftPtr];
                        leftPtr++;
                        std::cout << "leftPtr = " << leftPtr << ", rightPtr = " << rightPtr << std::endl << std::endl;
                        std::cout << "the value that went into temp array is: " << tempArray[k] << std::endl << std::endl;
                    }
                        //if the right value is greater than the left value, copy the right value to the temporary array
                    else if (array[leftPtr] > array[rightPtr]) {
                        tempArray[k] = array[rightPtr];
                        rightPtr++;
                        std::cout << "rightPtr = " << rightPtr << ", leftPtr = " << leftPtr << std::endl << std::endl;
                        std::cout << "the value that went into temp array is: " << tempArray[k] << std::endl << std::endl;
                    }
                }
            }
        }
        // the merge code for replacing the real array values with the sorted temporary array values
        for (size_t m = 0; m < arraySize; m++) {
            array[m] = tempArray[m];
            std::cout << "m = " << m << ", arraySize = " << arraySize << std::endl << std::endl;
            std::cout << "the value of m is " << array[m] << std::endl << std::endl;
        }
    }
}}}}

#endif //EX04_MERGESORT_MERGESORT_H
