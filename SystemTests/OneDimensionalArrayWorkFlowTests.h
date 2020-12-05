//
// Created by cigan on 04.12.2020.
//

#ifndef EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H
#define EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H

#include "../EppSourceCode/OneDimensionalArrayWorkFlow.h"
#include "TestsSupport.h"

template <class Type> class TestsOneDimensionalArrayWorkFlowObject {

private:
    void TestCaseOne_GetMinimumValueFromOneDimensionalArray_() {

        int primitiveArray[7] = { 12, -12, 3124, -3425, 44, 12343, -90438 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetMinimumValueFromOneDimensionalArray(Array) == -90438);
    }

    void TestCaseTwo_GetMinimumValueFromOneDimensionalArray_() {

        int primitiveArray[2] = { 1234, 12345 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetMinimumValueFromOneDimensionalArray(Array) == 1234);
    }

    void TestCaseThree_GetMinimumValueFromOneDimensionalArray_() {

        int primitiveArray[10] = { -1, -2, -3, -4, -5, -6, -7, -200, 0, 213};

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(10);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetMinimumValueFromOneDimensionalArray(Array) == -200);
    }

    void TestCaseOne_GetMaximumValueFromOneDimensionalArray_() {

        int primitiveArray[7] = { 12, -12, 3124, -3425, 44, 12343, -90438 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetMaximumValueFromOneDimensionalArray(Array) == 12343);
    }

    void TestCaseTwo_GetMaximumValueFromOneDimensionalArray_() {

        int primitiveArray[2] = { 1234, 12345 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetMaximumValueFromOneDimensionalArray(Array) == 12345);
    }

    void TestCaseThree_GetMaximumValueFromOneDimensionalArray_() {

        int primitiveArray[10] = { -1, -2, -3, -4, -5, -6, -7, -200, 0, 213};

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(10);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetMaximumValueFromOneDimensionalArray(Array) == 213);
    }

    void TestCaseOne_GetElementsSumOfOneDimensionalArray_() {

        int primitiveArray[7] = { 1, 2, 3, 4, 5, 6, 7 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsSumOfOneDimensionalArray(Array) == 28);
    }

    void TestCaseTwo_GetElementsSumOfOneDimensionalArray_() {

        int primitiveArray[2] = { 1234, 12345 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsSumOfOneDimensionalArray(Array) == 13579);
    }

    void TestCaseThree_GetElementsSumOfOneDimensionalArray_() {

        int primitiveArray[10] = { -1, -2, -3, -4, -5, -6, -7, -200, 0, 213};

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(10);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsSumOfOneDimensionalArray(Array) == -15);
    }

    void TestCaseOne_GetElementsProductOfOneDimensionalArray_() {

        int primitiveArray[7] = { 1, 2, 3, 4, 5, 6, 7 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsProductOfOneDimensionalArray(Array) == 5040);
    }

    void TestCaseTwo_GetElementsProductOfOneDimensionalArray_() {

        int primitiveArray[3] = { 1234, 12345, 0 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(3);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsProductOfOneDimensionalArray(Array) == 0);
    }

    void TestCaseThree_GetElementsProductOfOneDimensionalArray_() {

        int primitiveArray[5] = { -1, -2, -200, 1, 213};

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsProductOfOneDimensionalArray(Array) == -85200);
    }

    void TestCaseOne_GetElementsSubtractionOfOneDimensionalArray_() {

        int primitiveArray[7] = { 1, 2, 3, 4, 5, 6, 7 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsSubtractionOfOneDimensionalArray(Array) == -26);
    }

    void TestCaseTwo_GetElementsSubtractionOfOneDimensionalArray_() {

        int primitiveArray[3] = { 1234, 12345, 0 };

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(3);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsSubtractionOfOneDimensionalArray(Array) == -11111);
    }

    void TestCaseThree_GetElementsSubtractionOfOneDimensionalArray_() {

        int primitiveArray[5] = { -1, -2, -200, 1, 213};

        OneDimensionalArrayType<int> Array;

        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(ArrayWorkFlow->GetElementsSubtractionOfOneDimensionalArray(Array) == -13);
    }

    void TestCaseOne_GetElementsDivisionOfOneDimensionalArray_() {

        float primitiveArray[7] = { 7, 6, 5, 4, 3, 2, 1 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 0.0097f, 0.005f);
    }

    void TestCaseTwo_GetElementsDivisionOfOneDimensionalArray_() {

        float primitiveArray[3] = { 12345, 1234 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 10.004f, 0.005f);
    }

    void TestCaseThree_GetElementsDivisionOfOneDimensionalArray_() {

        float primitiveArray[4] = { 12334.432, 2, 54, 3};

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(4);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 38.0679f, 0.005f);
    }

    void TestCaseOne_GetElementsMeanOfOneDimensionalArray_() {

        float primitiveArray[7] = { 7.5, 6.2, 5.5, 4.2, 3.9, 2.432, 1.32 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsMeanOfOneDimensionalArray(Array), 4.436, 0.001f);
    }

    void TestCaseTwo_GetElementsMeanOfOneDimensionalArray_() {

        float primitiveArray[3] = { 12345, 1234 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsMeanOfOneDimensionalArray(Array), 6789.5f, 0.001f);
    }

    void TestCaseThree_GetElementsMeanOfOneDimensionalArray_() {

        float primitiveArray[4] = { 12334.432, 2, 54, 3};

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(4);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsMeanOfOneDimensionalArray(Array), 3098.35f, 0.01f);
    }

    void TestCaseOne_InitialiseOneDimensionalArray_() {

        int primitiveArray[7] = { 0, 0, 0, 0, 0, 0, 0 };

        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->InitialiseOneDimensionalArray(7, 0);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseTwo_InitialiseOneDimensionalArray_() {

        int primitiveArray[10] = { 13, 13, 13, 13, 13, 13, 13, 13 , 13, 13 };

        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->InitialiseOneDimensionalArray(10, 13);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseThree_InitialiseOneDimensionalArray_() {

        int primitiveArray[2] = { -12334, -12334 };

        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->InitialiseOneDimensionalArray(2, -12334);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    AbstractOneDimensionalArrayWorkFlowObject<Type> * ArrayWorkFlow;
    OneDimensionalArrayWorkFlow<Type> ArraysWorkflow;
    AbstractTestsSupportObject<Type> * Tests;
    TestsSupport<Type> TestsWorkFlow;

public:
    TestsOneDimensionalArrayWorkFlowObject() {

        ArrayWorkFlow = &ArraysWorkflow;
        Tests = &TestsWorkFlow;
    }

    void Tests_GetMinimumValueFromOneDimensionalArray_() {

        TestCaseOne_GetMinimumValueFromOneDimensionalArray_();
        TestCaseTwo_GetMinimumValueFromOneDimensionalArray_();
        TestCaseThree_GetMinimumValueFromOneDimensionalArray_();
    }

    void Tests_GetMaximumValueFromOneDimensionalArray_() {

        TestCaseOne_GetMaximumValueFromOneDimensionalArray_();
        TestCaseTwo_GetMaximumValueFromOneDimensionalArray_();
        TestCaseThree_GetMaximumValueFromOneDimensionalArray_();
    }

    void Tests_GetElementsSumOfOneDimensionalArray_() {

        TestCaseOne_GetElementsSumOfOneDimensionalArray_();
        TestCaseTwo_GetElementsSumOfOneDimensionalArray_();
        TestCaseThree_GetElementsSumOfOneDimensionalArray_();
    }

    void Tests_GetElementsProductOfOneDimensionalArray_() {

        TestCaseOne_GetElementsProductOfOneDimensionalArray_();
        TestCaseTwo_GetElementsProductOfOneDimensionalArray_();
        TestCaseThree_GetElementsProductOfOneDimensionalArray_();
    }

    void Tests_GetElementsSubtractionOfOneDimensionalArray_() {

        TestCaseOne_GetElementsSubtractionOfOneDimensionalArray_();
        TestCaseTwo_GetElementsSubtractionOfOneDimensionalArray_();
        TestCaseThree_GetElementsSubtractionOfOneDimensionalArray_();
    }

    void Tests_GetElementsDivisionOfOneDimensionalArray_() {

        TestCaseOne_GetElementsDivisionOfOneDimensionalArray_();
        TestCaseTwo_GetElementsDivisionOfOneDimensionalArray_();
        TestCaseThree_GetElementsDivisionOfOneDimensionalArray_();
    }

    void Tests_GetElementsMeanOfOneDimensionalArray_() {

        TestCaseOne_GetElementsMeanOfOneDimensionalArray_();
        TestCaseTwo_GetElementsMeanOfOneDimensionalArray_();
        TestCaseThree_GetElementsMeanOfOneDimensionalArray_();
    }

    void Tests_InitialiseOneDimensionalArray_() {

        TestCaseOne_InitialiseOneDimensionalArray_();
        TestCaseTwo_InitialiseOneDimensionalArray_();
        TestCaseThree_InitialiseOneDimensionalArray_();
    }

    ~TestsOneDimensionalArrayWorkFlowObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H
