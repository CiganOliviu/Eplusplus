//
// Created by cigan on 04.12.2020.
//

#ifndef EPLUSPLUS_IOSYSTEMSTESTS_H
#define EPLUSPLUS_IOSYSTEMSTESTS_H

#include "../EppSourceCode/IOSystemsOneDimensionalArray.h"
#include "TestsSupport.h"

template <class Type> class TestsIOSystemsOneDimensionalArrayObject {
private:
    AbstractIOSystemsOneDimensionalArrayObject<Type> * IOSys;
    IOSystemsOneDimensionalArray<Type> IO;
    AbstractTestsSupportObject<Type> Tests;

    const char * STDIN_FILE_WITH_LENGTH = "EPPSystemTestingFiles/InputFiles/ArrayWithLength.txt";
    const char * STDIN_FILE_WITHOUT_LENGTH = "EPPSystemTestingFiles/InputFiles/ArrayWithoutLength.txt";
    const char * STDOUT_FILE_WITH_LENGTH = "EPPSystemTestingFiles/OutputFiles/OutputFileArrayWithLength.txt";
    const char * STDOUT_FILE_WITHOUT_LENGTH = "EPPSystemTestingFiles/OutputFiles/OutputFileArrayWithoutLength.txt";

public:
    TestsIOSystemsOneDimensionalArrayObject() {

        IOSys = &IO;
        Tests = TestsSupportFactoryObject<Type>::GetTestsSupportObject();
    }

    void Test_ReadAndOutputOneDimensionalArrayInConsole_() {

        OneDimensionalArrayType<Type> Array;

        Array = IOSys->ReadOneDimensionalArray(5);

        IOSys->OutputOneDimensionalArray(Array);
        NEWLINE();
        IOSys->OutputOneDimensionalArrayWithLength(Array);
    }

    void Test_ReadAndOutputOneDimensionalArrayWithGivenLength_() {

        OneDimensionalArrayType<Type> Array;

        Array = IOSys->ReadOneDimensionalArrayFromFileWithGivenLength(STDIN_FILE_WITH_LENGTH);

        IOSys->OutputOneDimensionalArrayInFileWithLength(Array, STDOUT_FILE_WITH_LENGTH);
    }

    void Test_ReadAndOutputOneDimensionalArrayFromFile_() {

        OneDimensionalArrayType<Type> Array;

        Array = IOSys->ReadOneDimensionalArrayFromFile(STDIN_FILE_WITHOUT_LENGTH);

        IOSys->OutputOneDimensionalArrayInFile(Array, STDOUT_FILE_WITHOUT_LENGTH);
    }

    ~TestsIOSystemsOneDimensionalArrayObject() = default;
};

#endif //EPLUSPLUS_IOSYSTEMSTESTS_H