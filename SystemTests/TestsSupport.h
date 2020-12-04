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

    virtual void AssertOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {};
    virtual void AssertOneDimensionalArrayObjectWithPrimitive(OneDimensionalArrayType<Type> ArrayObject, int PrimitiveArray[]) {};
    virtual void AssertTwoFloatingNumbers(float numberOne, float numberTwo) {};

    ~AbstractTestsSupportObject() = default;
};

template <class Type> class TestsSupport : public AbstractTestsSupportObject<Type> {

private:
    AbstractOneDimensionalArrayObject<Type> Array;

public:
    TestsSupport() {

        Array = OneDimensionalArrayTypeFactoryObject<Type>::GetOneDimensionalArrayTypeObject();
    }

    void AssertOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override {

        assert(FirstArray.GetOneDimensionalArray() > 0);
        assert(SecondArray.GetOneDimensionalArray() > 0);
        assert(FirstArray.GetOneDimensionalArray() == SecondArray.GetOneDimensionalArray());

        int CommonLength = FirstArray.GetLengthOfOneDimensionalArray();

        for (int iterator = 0; iterator < CommonLength; ++iterator)
            assert(FirstArray.GetOneDimensionalArray()[iterator] == SecondArray.GetOneDimensionalArray()[iterator]);
    }

    void AssertOneDimensionalArrayObjectWithPrimitive(OneDimensionalArrayType<Type> ArrayObject, int PrimitiveArray[]) override {

        assert(ArrayObject.GetLengthOfOneDimensionalArray() > 0);

        for (int iterator = 0; iterator < ArrayObject.GetLengthOfOneDimensionalArray(); ++iterator)
            assert(ArrayObject.GetOneDimensionalArray()[iterator] == PrimitiveArray[iterator]);
    }

    void AssertTwoFloatingNumbers(float numberOne, float numberTwo) override {

        assert(abs(numberOne - numberTwo) < 1e-9);
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
