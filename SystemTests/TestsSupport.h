//
// Created by cigan on 03.12.2020.
//

#ifndef EPLUSPLUS_TESTSSUPPORT_H
#define EPLUSPLUS_TESTSSUPPORT_H

#include "../PreprocessorDirectives/StandardLibrary.h"
#include "../PreprocessorDirectives/DefinedDirectives.h"
#include "../DataStructures/OneDimensionalArray.h"
#include "../DataStructures/Matrix.h"

template <class Type> class AbstractTestsSupportObject {

public:
    AbstractTestsSupportObject() = default;

    virtual void AssertOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {};
    virtual void AssertOneDimensionalArrayObjectWithPrimitive(OneDimensionalArrayType<Type> ArrayObject, Type PrimitiveArray[]) {};
    virtual void AssertTwoFloatingNumbers(float numberOne, float numberTwo, float EPSILON) {};
    virtual void AssertMatrixObjects(MatrixType<Type> FirstMatrix, MatrixType<Type> SecondMatrix) {};
    virtual void AssertMatrixObjectWithPrimitive(MatrixType<Type> MatrixObject, Type primitiveMatrix[][STANDARD_LENGTH]) {};

    ~AbstractTestsSupportObject() = default;
};

template <class Type> class TestsSupport : public AbstractTestsSupportObject<Type> {

private:
    bool CheckIfMatrixParametersArePositive(MatrixType<Type> Matrix) {

        return (Matrix.GetLineOfMatrix() > 0 && Matrix.GetColumnOfMatrix() > 0);
    }

    bool CheckIfMatricesLinesAreEqual(MatrixType<Type> FirstMatrix, MatrixType<Type> SecondMatrix) {

        return (FirstMatrix.GetLineOfMatrix() == SecondMatrix.GetLineOfMatrix());
    }

    bool CheckIfMatricesColumnsAreEqual(MatrixType<Type> FirstMatrix, MatrixType<Type> SecondMatrix) {

        return (FirstMatrix.GetColumnOfMatrix() == SecondMatrix.GetColumnOfMatrix());
    }

public:
    TestsSupport() = default;

    void AssertOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override {

        assert(FirstArray.GetOneDimensionalArray() > 0);
        assert(SecondArray.GetOneDimensionalArray() > 0);
        assert(FirstArray.GetOneDimensionalArray() == SecondArray.GetOneDimensionalArray());

        int CommonLength = FirstArray.GetLengthOfOneDimensionalArray();

        for (int iterator = 0; iterator < CommonLength; ++iterator)
            assert(FirstArray.GetOneDimensionalArray()[iterator] == SecondArray.GetOneDimensionalArray()[iterator]);
    }

    void AssertOneDimensionalArrayObjectWithPrimitive(OneDimensionalArrayType<Type> ArrayObject, Type PrimitiveArray[]) override {

        assert(ArrayObject.GetLengthOfOneDimensionalArray() > 0);

        for (int iterator = 0; iterator < ArrayObject.GetLengthOfOneDimensionalArray(); ++iterator)
            assert(ArrayObject.GetOneDimensionalArray()[iterator] == PrimitiveArray[iterator]);
    }

    void AssertTwoFloatingNumbers(float numberOne, float numberTwo, float EPSILON) override {

        assert(abs(numberOne - numberTwo) < EPSILON);
    }

    void AssertMatrixObjects(MatrixType<Type> FirstMatrix, MatrixType<Type> SecondMatrix) override {

        assert(this->CheckIfMatrixParametersArePositive(FirstMatrix));
        assert(this->CheckIfMatrixParametersArePositive(SecondMatrix));
        assert(this->CheckIfMatricesLinesAreEqual(FirstMatrix, SecondMatrix));
        assert(this->CheckIfMatricesColumnsAreEqual(FirstMatrix, SecondMatrix));

        int commonLine = FirstMatrix.GetLineOfMatrix();
        int commonColumn = FirstMatrix.GetColumnOfMatrix();

        for (int iterator = 0; iterator < commonLine; ++iterator)
            for (int jiterator = 0; jiterator < commonColumn; ++jiterator)
                assert(FirstMatrix.GetMatrix()[iterator][jiterator] == SecondMatrix.GetMatrix()[iterator][jiterator]);
    }

     void AssertMatrixObjectWithPrimitive(MatrixType<Type> MatrixObject, Type primitiveMatrix[][STANDARD_LENGTH]) override {

        assert(this->CheckIfMatrixParametersArePositive(MatrixObject));

        for (int iterator = 0; iterator < MatrixObject.GetLineOfMatrix(); ++iterator)
            for (int jiterator = 0; jiterator < MatrixObject.GetColumnOfMatrix(); ++jiterator)
                assert(MatrixObject.GetMatrix()[iterator][jiterator] == primitiveMatrix[iterator][jiterator]);
    }

    ~TestsSupport() = default;
};

template <class Type> class TestsSupportFactoryObject {

public:
    TestsSupportFactoryObject() = default;

    static std::shared_ptr<AbstractTestsSupportObject<Type>> GetTestsSupportObject() {

        AbstractTestsSupportObject<Type> * instance = new TestsSupport<Type>();

        return std::shared_ptr<AbstractTestsSupportObject<Type>>(instance);
    }

    ~TestsSupportFactoryObject() = default;
};

#endif //EPLUSPLUS_TESTSSUPPORT_H
