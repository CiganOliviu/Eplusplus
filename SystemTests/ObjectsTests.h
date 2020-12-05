//
// Created by cigan on 03.12.2020.
//

#ifndef EPLUSPLUS_OBJECTSTESTS_H
#define EPLUSPLUS_OBJECTSTESTS_H

#include "../DataStructures/OneDimensionalArray.h"
#include "TestsSupport.h"

template <class Type> class TestsOneDimensionalArrayObject {

private:
    AbstractTestsSupportObject<Type> * Tests;
    TestsSupport<Type> TestsWorkFlow;

public:
    TestsOneDimensionalArrayObject() {

        Tests = &TestsWorkFlow;
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

        Tests->AssertOneDimensionalArrayObjectWithPrimitive(Array, primitiveArray);
    }

    ~TestsOneDimensionalArrayObject() = default;
};

#endif //EPLUSPLUS_OBJECTSTESTS_H
