//
// Created by cigan on 04.12.2020.
//

#ifndef EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H
#define EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H

#include "../EppSourceCode/OneDimensionalArrayWorkFlow.h"
#include "TestsSupport.h"

template <class Type> class TestsOneDimensionalArrayWorkFlowObject {

private:
    AbstractOneDimensionalArrayWorkFlowObject<Type> * ArrayWorkFlow;
    OneDimensionalArrayWorkFlow<Type> Workflow;
    AbstractTestsSupportObject<Type> Tests;

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

        this->Tests.AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 0.009722222);
    }

    void TestCaseTwo_GetElementsDivisionOfOneDimensionalArray_() {

        float primitiveArray[3] = { 12345, 1234 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests.AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 10.004051864);
    }

    void TestCaseThree_GetElementsDivisionOfOneDimensionalArray_() {

        float primitiveArray[4] = { 12334.432, 2, 54, 3};

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(4);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests.AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 38.067901235);
    }

    void TestCaseOne_GetElementsMeanOfOneDimensionalArray_() {

        float primitiveArray[7] = { 7.5, 6.2, 5.5, 4.2, 3.9, 2.432, 1.32 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests.AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 4.436);
    }

    void TestCaseTwo_GetElementsMeanOfOneDimensionalArray_() {

        float primitiveArray[3] = { 12345, 1234 };

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests.AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 6789.5);
    }

    void TestCaseThree_GetElementsMeanOfOneDimensionalArray_() {

        float primitiveArray[4] = { 12334.432, 2, 54, 3};

        OneDimensionalArrayType<float> Array;

        Array.SetLengthOfOneDimensionalArray(4);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests.AssertTwoFloatingNumbers(ArrayWorkFlow->GetElementsDivisionOfOneDimensionalArray(Array), 3098.358);
    }

public:
    TestsOneDimensionalArrayWorkFlowObject() {

        ArrayWorkFlow = &Workflow;
        Tests = TestsSupportFactoryObject<Type>::GetTestsSupportObject();
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

    ~TestsOneDimensionalArrayWorkFlowObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H
