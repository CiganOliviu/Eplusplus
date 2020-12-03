//
// Created by cigan on 03.12.2020.
//

#ifndef EPLUSPLUS_TESTSSUPPORT_H
#define EPLUSPLUS_TESTSSUPPORT_H

#include "../PreprocessorDirectives/StandardLibrary.h"
#include "../PreprocessorDirectives/DefinedDirectives.h"
#include "../DataStructures/OneDimensionalArray.h"

template <class Type> class AbstractTestsSupportObject {

public:
    AbstractTestsSupportObject() = default;

    virtual void AssertOneDimensionalArrays(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {};

    ~AbstractTestsSupportObject() = default;
};

template <class Type> class TestsSupport : public AbstractTestsSupportObject<Type> {

private:
    AbstractOneDimensionalArrayObject<Type> Array;

public:
    TestsSupport() {

        Array = OneDimensionalArrayFactoryObject<Type>::GetOneDimensionalArrayTypeObject();
    }

    void AssertOneDimensionalArrays(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override {

        assert(FirstArray.GetOneDimensionalArray() > 0);
        assert(SecondArray.GetOneDimensionalArray() > 0);
        assert(FirstArray.GetOneDimensionalArray() == SecondArray.GetOneDimensionalArray());

        int CommonLength = FirstArray.GetLengthOfOneDimensionalArray();

        for (int iterator = 0; iterator < CommonLength; ++iterator)
            assert(FirstArray.GetOneDimensionalArray()[iterator] == SecondArray.GetOneDimensionalArray()[iterator]);
    }

    ~TestsSupport() = default;
};

template <class Type> class TestsSupportFactoryObject {

public:
    TestsSupportFactoryObject() = default;

    static AbstractTestsSupportObject<Type> GetTestsSupportObject() {

        return TestsSupport<Type>();
    }

    ~TestsSupportFactoryObject() = default;
};

#endif //EPLUSPLUS_TESTSSUPPORT_H
