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

    void TestCaseOne_InsertionSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(25);
        int primitiveArray[25] = { 11405, -2030, -13486, 10167, 7614, -5021, -5762, 4242, 4552, -448, -1413, 14589, -10984, 12251, -4663, 9062, 12086, -6067, 2643, 10735, -12253, -14064, -4377, -12317, -2556 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->InsertionSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(25);
        int resultPrimitiveArray[25] = { -14064, -13486, -12317, -12253, -10984, -6067, -5762, -5021, -4663, -4377, -2556, -2030, -1413, -448, 2643, 4242, 4552, 7614, 9062, 10167, 10735, 11405, 12086, 12251, 14589 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseTwo_InsertionSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(12);
        int primitiveArray[12] = { 5, 14, 10, 15, 1, -4, 0, 4, -7, 12, 9, -15 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->InsertionSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(12);
        int resultPrimitiveArray[12] = { -15, -7, -4, 0, 1, 4, 5, 9, 10, 12, 14, 15 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseThree_InsertionSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(7);
        int primitiveArray[7] = { -370, -805, -942, -271, -772, -403, -936 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->InsertionSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(7);
        int resultPrimitiveArray[7] = { -942, -936, -805, -772, -403, -370, -271 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseOne_ShellSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(15);
        int primitiveArray[15] = { 352, -3514, -7692, -1790, -1910, -2367, -4410, 2065, 997, -4392, 7949, 5570, -5547, 1697, -2301 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->ShellSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(15);
        int resultPrimitiveArray[15] = { -7692, -5547, -4410, -4392, -3514, -2367, -2301, -1910, -1790, 352, 997, 1697, 2065, 5570, 7949 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseTwo_ShellSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(25);
        int primitiveArray[25] = { -974, -942, -4, -332, -912, -374, -277, -196, -782, -342, -629, -185, -134, -794, -836, -728, -180, -44, -23, -231, -583, -10, -104, -175, -171 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->ShellSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(25);
        int resultPrimitiveArray[25] = { -974, -942, -912, -836, -794, -782, -728, -629, -583, -374, -342, -332, -277, -231, -196, -185, -180, -175, -171, -134, -104, -44, -23, -10, -4 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, SortedResultArray);
    }

    void TestCaseThree_ShellSortOneDimensionalArray_() {

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        int primitiveArray[5] = { 1948, 4364, 2861, 9108, 5134 };
        Array.SetOneDimensionalArray(primitiveArray);

        OneDimensionalArrayType<int> SortedResultArray = ArraySortingWorkFlow->ShellSortOneDimensionalArray(Array);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(5);
        int resultPrimitiveArray[5] = { 1948, 2861, 4364, 5134, 9108 };
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

    void Test_InsertionSortOneDimensionalArray_() {

        this->TestCaseOne_InsertionSortOneDimensionalArray_();
        this->TestCaseTwo_InsertionSortOneDimensionalArray_();
        this->TestCaseThree_InsertionSortOneDimensionalArray_();
    }

    void Test_ShellSortOneDimensionalArray_() {

        this->TestCaseOne_ShellSortOneDimensionalArray_();
        this->TestCaseTwo_ShellSortOneDimensionalArray_();
        this->TestCaseThree_ShellSortOneDimensionalArray_();
    }

    ~TestsOneDimensionalArraySortingWorkFlowObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOWTESTS_H
