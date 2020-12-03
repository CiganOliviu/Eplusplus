//
// Created by cigan on 03.12.2020.
//

#ifndef EPLUSPLUS_OBJECTSTESTS_H
#define EPLUSPLUS_OBJECTSTESTS_H

#include "TestsSupport.h"

template <class Type> class TestsOneDimensionalArrayObject {

private:
    AbstractTestsSupportObject<Type> Tests;

public:
    TestsOneDimensionalArrayObject() {

        Tests = TestsSupportFactoryObject<Type>::GetTestsSupportObject();
    }

    void TestSet_Get_Length() {

        OneDimensionalArrayType<Type> Array;

        Array.SetLengthOfOneDimensionalArray(5);

        assert(Array.GetLengthOfOneDimensionalArray() == 5);
    }

    ~TestsOneDimensionalArrayObject() = default;
};

#endif //EPLUSPLUS_OBJECTSTESTS_H
