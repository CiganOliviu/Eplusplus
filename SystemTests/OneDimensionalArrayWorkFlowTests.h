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

    void TestCaseOne_PushBackValueInOneDimensionalArray_() {

        int primitiveArray[7] = { 1, 2, 3, 4, 5, 6, 7 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->PushBackValueInOneDimensionalArray(Array, 8);

        int primitiveResultArray[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseTwo_PushBackValueInOneDimensionalArray_() {

        int primitiveArray[4] = { -1, -2, -3, -4, };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(4);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->PushBackValueInOneDimensionalArray(Array, -2345);

        int primitiveResultArray[8] = { -1, -2, -3, -4, -2345 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseThree_PushBackValueInOneDimensionalArray_() {

        int primitiveArray[2] = { -12334, -12334 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(2);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->PushBackValueInOneDimensionalArray(Array, -12334);

        int primitiveResultArray[8] = { -12334, -12334, -12334 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseOne_IsValueInOneDimensionalArray_() {

        int primitiveArray[7] = { 1, 2, 3, 4, 5, 6, 7 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(7);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(this->ArrayWorkFlow->IsValueInOneDimensionalArray(Array, 5) == true);
    }

    void TestCaseTwo_IsValueInOneDimensionalArray_() {

        int primitiveArray[4] = { -1, -2, -3, -4, };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(4);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(this->ArrayWorkFlow->IsValueInOneDimensionalArray(Array, 5) == false);
    }

    void TestCaseThree_IsValueInOneDimensionalArray_() {

        int primitiveArray[5] = { 0, -12334, -12334, 0, 0 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        assert(this->ArrayWorkFlow->IsValueInOneDimensionalArray(Array, 0) == true);
    }

    void TestCaseOne_NormaliseOneDimensionalArray_() {

        int primitiveArray[5] = { 0, 0, 0, 0, 0 };
        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->NormaliseOneDimensionalArray(5);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseTwo_NormaliseOneDimensionalArray_() {

        int primitiveArray[7] = { 0, 0, 0, 0, 0, 0, 0 };
        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->NormaliseOneDimensionalArray(7);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseThree_NormaliseOneDimensionalArray_() {

        int primitiveArray[4] = { 0, 0, 0, 0 };
        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->NormaliseOneDimensionalArray(4);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseOne_ConvertNumberToOneDimensionalArray_() {

        int primitiveArray[5] = { 1, 2, 3, 4, 5 };

        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->ConvertNumberToOneDimensionalArray(12345);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseTwo_ConvertNumberToOneDimensionalArray_() {

        int primitiveArray[5] = { 5, 4, 3, 2, 1 };

        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->ConvertNumberToOneDimensionalArray(54321);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseThree_ConvertNumberToOneDimensionalArray_() {

        int primitiveArray[7] = { 1, 0, 4, 0, 0 };

        OneDimensionalArrayType<int> Array;

        Array = this->ArrayWorkFlow->ConvertNumberToOneDimensionalArray(10400);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    void TestCaseOne_BoostUpOneDimensionalArray_() {

        int primitiveArray[5] = { 1, 2, 3, 4, 5 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->BoostUpOneDimensionalArray(Array, 5);

        int primitiveResultArray[5] = { 5, 10, 15, 20, 25 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseTwo_BoostUpOneDimensionalArray_() {

        int primitiveArray[5] = { 0, 0, 0, 0, 0 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->BoostUpOneDimensionalArray(Array, 300);

        int primitiveResultArray[5] = { 0, 0, 0, 0, 0 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseThree_BoostUpOneDimensionalArray_() {

        int primitiveArray[5] = { 1, 1, 0, 4, 5 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->BoostUpOneDimensionalArray(Array, 10);

        int primitiveResultArray[5] = { 10, 10, 0, 40, 50 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseOne_BoostDownOneDimensionalArray_() {

        int primitiveArray[5] = { 10, 12, 30, 40, 50 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->BoostDownOneDimensionalArray(Array, 2);

        int primitiveResultArray[5] = { 5, 6, 15, 20, 25 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseTwo_BoostDownOneDimensionalArray_() {

        int primitiveArray[5] = { 0, 0, 0, 0, 0 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->BoostDownOneDimensionalArray(Array, 300);

        int primitiveResultArray[5] = { 0, 0, 0, 0, 0 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseThree_BoostDownOneDimensionalArray_() {

        int primitiveArray[5] = { 100, 105, 110, 150, 190 };

        OneDimensionalArrayType<int> Array;
        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        Array = this->ArrayWorkFlow->BoostDownOneDimensionalArray(Array, 5);

        int primitiveResultArray[5] = { 20, 21, 22, 30, 38 };

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveResultArray);
    }

    void TestCaseOne_GetSumOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(5);
        int firstPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(5);
        int secondPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetSumOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(5);
        int resultPrimitiveArray[5] = { 2, 4, 6, 8, 10 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseTwo_GetSumOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(3);
        int firstPrimitiveArray[3] = { 0, 0, 0 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(3);
        int secondPrimitiveArray[3] = { -2, 5, -6 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetSumOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(3);
        int resultPrimitiveArray[3] = { -2, 5, -6 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }


    void TestCaseThree_GetSumOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(4);
        int firstPrimitiveArray[4] = { 12, -213, 432, -6456 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(4);
        int secondPrimitiveArray[4] = { -12, 213, -432, 6456 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetSumOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(4);
        int resultPrimitiveArray[4] = { 0, 0, 0, 0 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseOne_GetSubtractionOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(5);
        int firstPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(5);
        int secondPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetSubtractionOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(5);
        int resultPrimitiveArray[5] = { 0, 0, 0, 0, 0 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseTwo_GetSubtractionOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(3);
        int firstPrimitiveArray[3] = { 0, 0, 0 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(3);
        int secondPrimitiveArray[3] = { -2, 5, -6 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetSubtractionOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(3);
        int resultPrimitiveArray[3] = { 2, -5, 6 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseThree_GetSubtractionOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(4);
        int firstPrimitiveArray[4] = { 12, -213, 432, -6456 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(4);
        int secondPrimitiveArray[4] = { -12, 213, -432, 6456 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetSubtractionOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(4);
        int resultPrimitiveArray[4] = { 24, -426, 864, -12912 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseOne_GetDivisionOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(5);
        int firstPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(5);
        int secondPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetDivisionOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(5);
        int resultPrimitiveArray[5] = { 1, 1, 1, 1, 1 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseTwo_GetDivisionOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(3);
        int firstPrimitiveArray[3] = { 0, 0, 0 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(3);
        int secondPrimitiveArray[3] = { -2, 5, -6 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetDivisionOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(3);
        int resultPrimitiveArray[3] = { 0, 0, 0 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseThree_GetDivisionOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(4);
        int firstPrimitiveArray[4] = { 12, -213, 432, -6456 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(4);
        int secondPrimitiveArray[4] = { 2, 3, 4, 5 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetDivisionOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(4);
        int resultPrimitiveArray[4] = { 6, -71, 108, -1291 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseOne_GetProductOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(5);
        int firstPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(5);
        int secondPrimitiveArray[5] = { 1, 2, 3, 4, 5 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetProductOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(5);
        int resultPrimitiveArray[5] = { 1, 4, 9, 16, 25 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    void TestCaseTwo_GetProductOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(3);
        int firstPrimitiveArray[3] = { 0, 0, 0 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(3);
        int secondPrimitiveArray[3] = { -2, 5, -6 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetProductOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(3);
        int resultPrimitiveArray[3] = { 0, 0, 0 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }


    void TestCaseThree_GetProductOfOneDimensionalArrayObjects_() {

        OneDimensionalArrayType<int> FirstArray;
        FirstArray.SetLengthOfOneDimensionalArray(4);
        int firstPrimitiveArray[4] = { 12, -213, 432, -6456 };
        FirstArray.SetOneDimensionalArray(firstPrimitiveArray);

        OneDimensionalArrayType<int> SecondArray;
        SecondArray.SetLengthOfOneDimensionalArray(4);
        int secondPrimitiveArray[4] = { 2, 3, 4, 5 };
        SecondArray.SetOneDimensionalArray(secondPrimitiveArray);

        OneDimensionalArrayType<int> FunctionResultArray = this->ArrayWorkFlow->GetProductOfOneDimensionalArrayObjects(FirstArray, SecondArray);

        OneDimensionalArrayType<int> ResultArray;
        ResultArray.SetLengthOfOneDimensionalArray(4);
        int resultPrimitiveArray[4] = { 24, -639, 1728, -32280 };
        ResultArray.SetOneDimensionalArray(resultPrimitiveArray);

        this->Tests->AssertOneDimensionalArrayObjects(ResultArray, FunctionResultArray);
    }

    std::shared_ptr<AbstractOneDimensionalArrayWorkFlowObject<Type>> ArrayWorkFlow;
    std::shared_ptr<AbstractTestsSupportObject<Type>> Tests;

public:
    TestsOneDimensionalArrayWorkFlowObject() {

        ArrayWorkFlow = OneDimensionalArrayWorkFlowFactoryObject<Type>::GetOneDimensionalArrayWorkFlowObject();
        Tests = TestsSupportFactoryObject<Type>::GetTestsSupportObject();
    }

    void Test_GetMinimumValueFromOneDimensionalArray_() {

        this->TestCaseOne_GetMinimumValueFromOneDimensionalArray_();
        this->TestCaseTwo_GetMinimumValueFromOneDimensionalArray_();
        this->TestCaseThree_GetMinimumValueFromOneDimensionalArray_();
    }

    void Test_GetMaximumValueFromOneDimensionalArray_() {

        this->TestCaseOne_GetMaximumValueFromOneDimensionalArray_();
        this->TestCaseTwo_GetMaximumValueFromOneDimensionalArray_();
        this->TestCaseThree_GetMaximumValueFromOneDimensionalArray_();
    }

    void Test_GetElementsSumOfOneDimensionalArray_() {

        this->TestCaseOne_GetElementsSumOfOneDimensionalArray_();
        this->TestCaseTwo_GetElementsSumOfOneDimensionalArray_();
        this->TestCaseThree_GetElementsSumOfOneDimensionalArray_();
    }

    void Test_GetElementsProductOfOneDimensionalArray_() {

        this->TestCaseOne_GetElementsProductOfOneDimensionalArray_();
        this->TestCaseTwo_GetElementsProductOfOneDimensionalArray_();
        this->TestCaseThree_GetElementsProductOfOneDimensionalArray_();
    }

    void Test_GetElementsSubtractionOfOneDimensionalArray_() {

        this->TestCaseOne_GetElementsSubtractionOfOneDimensionalArray_();
        this->TestCaseTwo_GetElementsSubtractionOfOneDimensionalArray_();
        this->TestCaseThree_GetElementsSubtractionOfOneDimensionalArray_();
    }

    void Test_GetElementsDivisionOfOneDimensionalArray_() {

        this->TestCaseOne_GetElementsDivisionOfOneDimensionalArray_();
        this->TestCaseTwo_GetElementsDivisionOfOneDimensionalArray_();
        this->TestCaseThree_GetElementsDivisionOfOneDimensionalArray_();
    }

    void Test_GetElementsMeanOfOneDimensionalArray_() {

        this->TestCaseOne_GetElementsMeanOfOneDimensionalArray_();
        this->TestCaseTwo_GetElementsMeanOfOneDimensionalArray_();
        this->TestCaseThree_GetElementsMeanOfOneDimensionalArray_();
    }

    void Test_InitialiseOneDimensionalArray_() {

        this->TestCaseOne_InitialiseOneDimensionalArray_();
        this->TestCaseTwo_InitialiseOneDimensionalArray_();
        this->TestCaseThree_InitialiseOneDimensionalArray_();
    }

    void Test_PushBackValueInOneDimensionalArray_() {

        this->TestCaseOne_PushBackValueInOneDimensionalArray_();
        this->TestCaseTwo_PushBackValueInOneDimensionalArray_();
        this->TestCaseThree_PushBackValueInOneDimensionalArray_();
    }

    void Test_IsValueInOneDimensionalArray_() {

        this->TestCaseOne_IsValueInOneDimensionalArray_();
        this->TestCaseTwo_IsValueInOneDimensionalArray_();
        this->TestCaseThree_IsValueInOneDimensionalArray_();
    }

    void Test_NormaliseOneDimensionalArray_() {

        this->TestCaseOne_NormaliseOneDimensionalArray_();
        this->TestCaseTwo_NormaliseOneDimensionalArray_();
        this->TestCaseThree_NormaliseOneDimensionalArray_();
    }

    void Test_ConvertNumberToOneDimensionalArray_() {

        this->TestCaseOne_ConvertNumberToOneDimensionalArray_();
        this->TestCaseTwo_ConvertNumberToOneDimensionalArray_();
        this->TestCaseThree_ConvertNumberToOneDimensionalArray_();
    }

    void Test_BoostUpOneDimensionalArray_() {

        this->TestCaseOne_BoostUpOneDimensionalArray_();
        this->TestCaseTwo_BoostUpOneDimensionalArray_();
        this->TestCaseThree_BoostUpOneDimensionalArray_();
    }

    void Test_BoostDownOneDimensionalArray_() {

        this->TestCaseOne_BoostDownOneDimensionalArray_();
        this->TestCaseTwo_BoostDownOneDimensionalArray_();
        this->TestCaseThree_BoostDownOneDimensionalArray_();
    }

    void Test_GetSumOfOneDimensionalArrayObjects_() {

        this->TestCaseOne_GetSumOfOneDimensionalArrayObjects_();
        this->TestCaseTwo_GetSumOfOneDimensionalArrayObjects_();
        this->TestCaseThree_GetSumOfOneDimensionalArrayObjects_();
    }

    void Test_GetSubtractionOfOneDimensionalArrayObjects_() {

        this->TestCaseOne_GetSubtractionOfOneDimensionalArrayObjects_();
        this->TestCaseTwo_GetSubtractionOfOneDimensionalArrayObjects_();
        this->TestCaseThree_GetSubtractionOfOneDimensionalArrayObjects_();
    }

    void Test_GetDivisionOfOneDimensionalArrayObjects_() {

        this->TestCaseOne_GetDivisionOfOneDimensionalArrayObjects_();
        this->TestCaseTwo_GetDivisionOfOneDimensionalArrayObjects_();
        this->TestCaseThree_GetDivisionOfOneDimensionalArrayObjects_();
    }

    void Test_GetProductOfOneDimensionalArrayObjects_() {

        this->TestCaseOne_GetProductOfOneDimensionalArrayObjects_();
        this->TestCaseTwo_GetProductOfOneDimensionalArrayObjects_();
        this->TestCaseThree_GetProductOfOneDimensionalArrayObjects_();
    }

    ~TestsOneDimensionalArrayWorkFlowObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOWTESTS_H
