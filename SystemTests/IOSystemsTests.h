//
// Created by cigan on 04.12.2020.
//

#ifndef EPLUSPLUS_IOSYSTEMSTESTS_H
#define EPLUSPLUS_IOSYSTEMSTESTS_H

#include "../EppSourceCode/IOSystemsOneDimensionalArray.h"
#include "../EppSourceCode/IOSystemMatrix.h"
#include "TestsSupport.h"

template <class Type> class TestsIOSystemsOneDimensionalArrayObject {
private:
    std::shared_ptr<AbstractIOSystemsOneDimensionalArrayObject<int>> IOSys;

    const char * STDIN_FILE_WITH_LENGTH = "EPPSystemTestingFiles/InputFiles/ArrayWithLength.txt";
    const char * STDIN_FILE_WITHOUT_LENGTH = "EPPSystemTestingFiles/InputFiles/ArrayWithoutLength.txt";
    const char * STDOUT_FILE_WITH_LENGTH = "EPPSystemTestingFiles/OutputFiles/OutputFileArrayWithLength.txt";
    const char * STDOUT_FILE_WITHOUT_LENGTH = "EPPSystemTestingFiles/OutputFiles/OutputFileArrayWithoutLength.txt";

public:
    TestsIOSystemsOneDimensionalArrayObject() {

        IOSys = IOSystemsOneDimensionalArrayFactoryObject<int>::GetIOSystemsOneDimensionalArray();
    }

    void Test_ReadAndOutputOneDimensionalArrayInConsole_() {

        OneDimensionalArrayType<Type> Array;

        Array = this->IOSys->ReadOneDimensionalArray(5);

        this->IOSys->OutputOneDimensionalArray(Array);
        NEWLINE();
        this->IOSys->OutputOneDimensionalArrayWithLength(Array);
    }

    void Test_ReadAndOutputOneDimensionalArrayWithGivenLength_() {

        OneDimensionalArrayType<Type> Array;

        Array = this->IOSys->ReadOneDimensionalArrayFromFileWithGivenLength(STDIN_FILE_WITH_LENGTH);

        this->IOSys->OutputOneDimensionalArrayInFileWithLength(Array, STDOUT_FILE_WITH_LENGTH);
    }

    void Test_ReadAndOutputOneDimensionalArrayFromFile_() {

        OneDimensionalArrayType<Type> Array;

        Array = this->IOSys->ReadOneDimensionalArrayFromFile(STDIN_FILE_WITHOUT_LENGTH);

        this->IOSys->OutputOneDimensionalArrayInFile(Array, STDOUT_FILE_WITHOUT_LENGTH);
    }

    ~TestsIOSystemsOneDimensionalArrayObject() = default;
};

template <class Type> class TestsIOSystemMatrixObject {

private:
    std::shared_ptr<AbstractIOSystemMatrixObject<int>> IOSys;

    const char * STDIN_FILE_WITH_LENGTH = "EPPSystemTestingFiles/InputFiles/MatrixWithLength.txt";
    const char * STDIN_FILE_WITHOUT_LENGTH = "EPPSystemTestingFiles/InputFiles/MatrixWithoutLength.txt";
    const char * STDOUT_FILE_WITH_LENGTH = "EPPSystemTestingFiles/OutputFiles/OutputFileMatrixWithLength.txt";
    const char * STDOUT_FILE_WITHOUT_LENGTH = "EPPSystemTestingFiles/OutputFiles/OutputFileMatrixWithoutLength.txt";

public:
    TestsIOSystemMatrixObject() {

        IOSys = IOSystemMatrixFactoryObject<Type>::GetIOMatrixObject();
    }

    void Test_ReadAndOutputMatrixInConsole_() {

        MatrixType<Type> Matrix;

        Matrix = this->IOSys->ReadMatrix(3, 3);

        this->IOSys->OutputMatrix(Matrix);
        NEWLINE();
        this->IOSys->OutputMatrixWithLength(Matrix);
    }

    ~TestsIOSystemMatrixObject() = default;
};

#endif //EPLUSPLUS_IOSYSTEMSTESTS_H
