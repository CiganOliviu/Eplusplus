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

    void TestCaseOne_MinimumValueSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(7);
        int primitiveArray[7] = { -7, -6, -5, -4, -3, -2, -1 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->MinimumValueSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(7);
        int resultPrimitiveArray[7] = { -7, -6, -5, -4, -3, -2, -1 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseTwo_MinimumValueSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(10);
        int primitiveArray[10] = { 7334, 6226, 4710, 42, 6953, 8079, -7317, 8688, 7975, 2105 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->MinimumValueSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(10);
        int resultPrimitiveArray[10] = { -7317, 42, 2105, 4710, 6226, 6953, 7334, 7975, 8079, 8688 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseThree_MinimumValueSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(20);
        int primitiveArray[20] = { 7300, -3516, -2677, 359, 3333, 9427, 4058, -1976, -9800, 7399, -2931, -248, -8500, 5616, 8287, -5138, -5245, 5162, 134, 8427 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->MinimumValueSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(20);
        int resultPrimitiveArray[20] = { -9800, -8500, -5245, -5138, -3516, -2931, -2677, -1976, -248, 134, 359, 3333, 4058, 5162, 5616, 7300, 7399, 8287, 8427, 9427 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseOne_SelectionSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(20);
        int primitiveArray[20] = { -23, 138, 101, 119, -50, -50, 143, -150, 19, -8, -59, 91, -57, -100, 13, 96, 31, 62, 40, 21 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->SelectionSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(20);
        int resultPrimitiveArray[20] = { -150, -100, -59, -57, -50, -50, -23, -8, 13, 19, 21, 31, 40, 62, 91, 96, 101, 119, 138, 143 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseTwo_SelectionSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        int primitiveArray[5] = { -7114, -2703, 1851, 2523, 14291 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->SelectionSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(5);
        int resultPrimitiveArray[5] = { -7114, -2703, 1851, 2523, 14291 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseThree_SelectionSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(7);
        int primitiveArray[7] = { 9710, -14742, -13967, -12403, 6024, 10904, 7733 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->SelectionSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(7);
        int resultPrimitiveArray[7] = { -14742, -13967, -12403, 6024, 7733, 9710, 10904 };
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

    void Test_MinimumValueSortOneDimensionalArray_() {

        this->TestCaseOne_MinimumValueSortOneDimensionalArray_();
        this->TestCaseTwo_MinimumValueSortOneDimensionalArray_();
        this->TestCaseThree_MinimumValueSortOneDimensionalArray_();
    }

    void Test_SelectionSortOneDimensionalArray_() {

        this->TestCaseOne_SelectionSortOneDimensionalArray_();
        this->TestCaseTwo_SelectionSortOneDimensionalArray_();
        this->TestCaseThree_SelectionSortOneDimensionalArray_();
    }

    ~TestsOneDimensionalArraySortingWorkFlowObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOWTESTS_H
