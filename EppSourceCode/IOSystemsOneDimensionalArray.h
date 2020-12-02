//
// Created by cigan on 02.12.2020.
//

#ifndef EPLUSPLUS_IOSYSTEMONEDIMENSIONALARRAY_H
#define EPLUSPLUS_IOSYSTEMONEDIMENSIONALARRAY_H

#include "../PreprocessorDirectives/StandardLibrary.h"
#include "../PreprocessorDirectives/DefinedDirectives.h"
#include "../DataStructures/OneDimensionalArray.h"

template <class Type> class AbstractIOSystemsOneDimensionalArrayObject {

public:
    AbstractIOSystemsOneDimensionalArrayObject() = default;

    virtual OneDimensionalArrayType<Type> ReadOneDimensionalArray(unsigned int length) {}
    virtual OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFileWithGivenLength(char * fileName) {}

    virtual void OutputOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    virtual void OutputOneDimensionalArrayWithLength(OneDimensionalArrayType<Type> Array) {}
    virtual void OutputOneDimensionalArrayInFileWithLength(OneDimensionalArrayType<Type> Array, char * fileName) {}
    virtual void OutputOneDimensionalArrayInFile(OneDimensionalArrayType<Type> Array, char * fileName) {}

    ~AbstractIOSystemsOneDimensionalArrayObject() = default;
};

template <class Type> class IOSystemsOneDimensionalArray : public AbstractIOSystemsOneDimensionalArrayObject<Type> {

private:
    AbstractOneDimensionalArrayObject<Type> OneDimensionalArray;

    OneDimensionalArrayType<Type> GetArrayFromStdin(unsigned int length) {

        OneDimensionalArrayType<Type> Array;

        Array.SetLengthOfOneDimensionalArray(length);

        for (int iterator = 0; iterator < length; ++iterator)
            std::cin >> Array.GetOneDimensionalArray()[iterator];

        return Array;
    }

    OneDimensionalArrayType<Type> GetArrayFromStdFileIn(std::ifstream &File, unsigned int length) {

        OneDimensionalArrayType<Type> Array;
        Array.SetLengthOfOneDimensionalArray(length);

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            File >> Array.GetOneDimensionalArray()[iterator];
    }

    void PutsArrayInStdout(OneDimensionalArrayType<Type> Array) {

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            std::cout << Array.GetOneDimensionalArray()[iterator] << " ";
    }

    void PutsArrayInStdFileOut(std::ofstream &File, OneDimensionalArrayType<Type> Array) {

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            File << Array.GetOneDimensionalArray()[iterator];
    }

    void ValidateInputFile(std::ifstream &File) {

        if (!File.is_open())
            throw std::runtime_error("Unable to open file");
    }

    void ValidateOutputFile(std::ofstream &File) {

        if (!File.is_open())
            throw std::runtime_error("Unable to open file");
    }

    int ReadFirstElementFromFile(std::ifstream &File) {

        int firstElement;

        File >> firstElement;

        return firstElement;
    }

public:
    IOSystemsOneDimensionalArray() {

        OneDimensionalArray = OneDimensionalArrayFactoryObject<Type>::GetOneDimensionalArrayTypeObject();
    }

    OneDimensionalArrayType<Type> ReadOneDimensionalArray(unsigned int length) override {

        assert(length >= 0);

        OneDimensionalArrayType<Type> Array;

        Array = this->GetArrayFromStdin(length);

        return Array;
    }

    OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFileWithGivenLength(char * fileName) override {

        std::ifstream WorkingFile(fileName, std::ios::in);

        ValidateInputFile(WorkingFile);

        int firstElementOfTheFile = ReadFirstElementFromFile(WorkingFile);

        assert(firstElementOfTheFile >= 0);

        OneDimensionalArrayType<Type> Array;

        Array = GetArrayFromStdFileIn(WorkingFile, firstElementOfTheFile);

        WorkingFile.close();

        return Array;
    }

    void OutputOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        PutsArrayInStdout(Array);
    }

    void OutputOneDimensionalArrayWithLength(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetOneDimensionalArray() >= 0);

        std::cout << Array.GetLengthOfOneDimensionalArray() << std::endl;

        PutsArrayInStdout(Array);
    }

    void OutputOneDimensionalArrayInFileWithLength(OneDimensionalArrayType<Type> Array, char * fileName) override {

        assert(Array.GetOneDimensionalArray() >= 0);

        std::ofstream WorkingFile(fileName, std::ios::out);

        ValidateOutputFile(WorkingFile);

        WorkingFile << Array.GetLengthOfOneDimensionalArray() << '\n';

        PutsArrayInStdFileOut(WorkingFile, Array);

        WorkingFile.close();
    }

     void OutputOneDimensionalArrayInFile(OneDimensionalArrayType<Type> Array, char * fileName) override {

        assert(Array.GetOneDimensionalArray() >= 0);

        std::ofstream WorkingFile(fileName, std::ios::out);

        ValidateOutputFile(WorkingFile);

        PutsArrayInStdFileOut(WorkingFile, Array);

        WorkingFile.close();
    }

    ~IOSystemsOneDimensionalArray() = default;
};

template <class Type> class IOSystemsOneDimensionalArrayFactoryObject {

public:
    IOSystemsOneDimensionalArrayFactoryObject() = default;

    static AbstractIOSystemsOneDimensionalArrayObject<Type> GetIOSystemsOneDimensionalArrayObject() {

        return IOSystemsOneDimensionalArray<Type>();
    }

    ~IOSystemsOneDimensionalArrayFactoryObject() = default;
};

#endif //EPLUSPLUS_IOSYSTEMONEDIMENSIONALARRAY_H
