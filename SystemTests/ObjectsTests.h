//
// Created by cigan on 03.12.2020.
//

#ifndef EPLUSPLUS_OBJECTSTESTS_H
#define EPLUSPLUS_OBJECTSTESTS_H

#include "../DataStructures/OneDimensionalArray.h"
#include "../DataStructures/Matrix.h"
#include "TestsSupport.h"

template <class Type> class TestsOneDimensionalArrayObject {

private:
    std::shared_ptr<AbstractTestsSupportObject<int>> Tests;

public:
    TestsOneDimensionalArrayObject() {

        Tests = TestsSupportFactoryObject<int>::GetTestsSupportObject();
    }

    void Test_Set_Get_Length_() {

        OneDimensionalArrayType<Type> Array;

        Array.SetLengthOfOneDimensionalArray(5);

        assert(Array.GetLengthOfOneDimensionalArray() == 5);
    }

    void Test_Set_Get_OneDimensionalArray_() {

        OneDimensionalArrayType<Type> Array;
        Type primitiveArray[5] = {1, 2, 3, 4, 5};

        Array.SetLengthOfOneDimensionalArray(5);
        Array.SetOneDimensionalArray(primitiveArray);

        this->Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    ~TestsOneDimensionalArrayObject() = default;
};

template <class Type> class TestsMatrixObject {

private:
    std::shared_ptr<AbstractTestsSupportObject<int>> Tests;

public:
    TestsMatrixObject() {

        Tests = TestsSupportFactoryObject<Type>::GetTestsSupportObject();
    }

    void Test_Set_Get_Line_() {

        MatrixType<Type> Array;

        Array.SetLineOfMatrix(5);

        assert(Array.GetLineOfMatrix() == 5);
    }

    void Test_Set_Get_Column_() {

        MatrixType<Type> Array;

        Array.SetColumnOfMatrix(5);

        assert(Array.GetColumnOfMatrix() == 5);
    }

    void Test_Set_Get_Matrix_() {

        Type primitiveMatrix[][STANDARD_LENGTH] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

        MatrixType<Type> Array;
        Array.SetLineOfMatrix(3);
        Array.SetColumnOfMatrix(3);
        Array.SetMatrix(primitiveMatrix);

        this->Tests->AssertMatrixObjectWithPrimitive(Array, primitiveMatrix);
    }

    ~TestsMatrixObject() = default;
};

#endif //EPLUSPLUS_OBJECTSTESTS_H
