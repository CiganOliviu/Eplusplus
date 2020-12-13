//
// Created by cigan on 13.12.2020.
//

#ifndef EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOWTESTS_H
#define EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOWTESTS_H

#include "../EppSourceCode/OneDimensionalArraySortingWorkFlow.h"

template <class Type> class TestsOneDimensionalArraySortingWorkFlowObject {

private:

    void TestCaseOne_BubbleSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(4);
        int primitiveArray[4] = { 12, -213, 432, -6456 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->BubbleSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(4);
        int resultPrimitiveArray[4] = { -6456, -213, 12, 432 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseTwo_BubbleSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(7);
        int primitiveArray[7] = { 7, 6, 5, 4, 3, 2, 1 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->BubbleSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(7);
        int resultPrimitiveArray[7] = { 1, 2, 3, 4, 5, 6, 7 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseThree_BubbleSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(4);
        int primitiveArray[4] = { 0, 0, 0, -1 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->BubbleSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(4);
        int resultPrimitiveArray[4] = { -1, 0, 0, 0 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    std::shared_ptr<AbstractOneDimensionalArraySortingWorkFlowObject<Type>> ArraySortingWorkFlow;
    std::shared_ptr<AbstractTestsSupportObject<Type>> Tests;

public:
    TestsOneDimensionalArraySortingWorkFlowObject() {

        ArraySortingWorkFlow = OneDimensionalArraySortingWorkFlowFactoryObject<Type>::GetOneDimensionalArraySortingWorkFlowObject();
        Tests = TestsSupportFactoryObject<Type>::GetTestsSupportObject();
    }

    void Test_BubbleSortOneDimensionalArray_() {

        this->TestCaseOne_BubbleSortOneDimensionalArray_();
        this->TestCaseTwo_BubbleSortOneDimensionalArray_();
        this->TestCaseThree_BubbleSortOneDimensionalArray_();
    }

    ~TestsOneDimensionalArraySortingWorkFlowObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOWTESTS_H
