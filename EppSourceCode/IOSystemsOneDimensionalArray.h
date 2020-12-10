//
// Created by cigan on 02.12.2020.
//

#ifndef EPLUSPLUS_IOSYSTEMONEDIMENSIONALARRAY_H
#define EPLUSPLUS_IOSYSTEMONEDIMENSIONALARRAY_H

#include "../DataStructures/OneDimensionalArray.h"

template <class Type> class AbstractIOSystemsOneDimensionalArrayObject {

public:
    AbstractIOSystemsOneDimensionalArrayObject() = default;

    [[maybe_unused]] virtual OneDimensionalArrayType<Type> ReadOneDimensionalArray(unsigned int length) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFileWithGivenLength(const char * fileName) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFile(const char * fileName) {}

    [[maybe_unused]] virtual void OutputOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual void OutputOneDimensionalArrayWithLength(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual void OutputOneDimensionalArrayInFileWithLength(OneDimensionalArrayType<Type> Array, const char * fileName) {}

    [[maybe_unused]] virtual void OutputOneDimensionalArrayInFile(OneDimensionalArrayType<Type> Array, const char * fileName) {}

    ~AbstractIOSystemsOneDimensionalArrayObject() = default;
};

template <class Type> class IOSystemsOneDimensionalArray : public AbstractIOSystemsOneDimensionalArrayObject<Type> {

private:
    OneDimensionalArrayType<Type> GetArrayFromStdin(unsigned int length) {

        OneDimensionalArrayType<Type> Array;

        Array.SetLengthOfOneDimensionalArray(length);

        for (unsigned int iterator = 0; iterator < length; ++iterator)
            std::cin >> Array.GetOneDimensionalArray()[iterator];

        return Array;
    }

    OneDimensionalArrayType<Type> GetArrayWithGivenLengthFromStdFileIn(std::ifstream &File, unsigned int length) {

        OneDimensionalArrayType<Type> Array;
        Array.SetLengthOfOneDimensionalArray(length);

        for (unsigned int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            File >> Array.GetOneDimensionalArray()[iterator];

        return Array;
    }

    OneDimensionalArrayType<Type> GetArrayFromStdFileIn(std::ifstream &File) {

        OneDimensionalArrayType<Type> Array;
        Type data;
        unsigned int iterator = 0;

        while (File >> data) {

            Array.GetOneDimensionalArray()[iterator] = data;
            iterator += 1;
        }

        Array.SetLengthOfOneDimensionalArray(iterator);

        return Array;
    }

    void PutsArrayInStdout(OneDimensionalArrayType<Type> Array) {

        for (unsigned int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            std::cout << Array.GetOneDimensionalArray()[iterator] << " ";
    }

    void PutsArrayInStdFileOut(std::ofstream &File, OneDimensionalArrayType<Type> Array) {

        for (unsigned int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            File << Array.GetOneDimensionalArray()[iterator] << " ";
    }

    void CheckIfInputFileIsEmpty(std::ifstream &File) {

        if (File.tellg() < 0)
            throw std::out_of_range("Unable to read from empty file");

    }

    void CheckIfInputFileIsOpen(std::ifstream &File) {

        if (!File.is_open())
            throw std::runtime_error("Unable to open file");
    }

    void CheckIfOutputFileIsOpen(std::ofstream &File) {

        if (!File.is_open())
            throw std::runtime_error("Unable to open file");
    }

    int ReadFirstElementFromFile(std::ifstream &File) {

        int firstElement;

        File >> firstElement;

        return firstElement;
    }

public:
    IOSystemsOneDimensionalArray() = default;

    OneDimensionalArrayType<Type> ReadOneDimensionalArray(unsigned int length) override {

        assert(length >= 0);

        OneDimensionalArrayType<Type> Array = this->GetArrayFromStdin(length);

        return Array;
    }

    OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFileWithGivenLength(const char * fileName) override {

        std::ifstream WorkingFile(fileName, std::ios::in);

        this->CheckIfInputFileIsOpen(WorkingFile);
        this->CheckIfInputFileIsEmpty(WorkingFile);

        int firstElementOfTheFile = this->ReadFirstElementFromFile(WorkingFile);

        assert(firstElementOfTheFile >= 0);

        OneDimensionalArrayType<Type> Array = this->GetArrayWithGivenLengthFromStdFileIn(WorkingFile, firstElementOfTheFile);

        WorkingFile.close();

        return Array;
    }

    OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFile(const char * fileName) override {

        std::ifstream WorkingFile(fileName, std::ios::in);

        this->CheckIfInputFileIsOpen(WorkingFile);
        this->CheckIfInputFileIsEmpty(WorkingFile);

        OneDimensionalArrayType<Type> Array = this->GetArrayFromStdFileIn(WorkingFile);

        WorkingFile.close();

        return Array;
    }

    void OutputOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        this->PutsArrayInStdout(Array);
    }

    void OutputOneDimensionalArrayWithLength(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetOneDimensionalArray() >= 0);

        std::cout << Array.GetLengthOfOneDimensionalArray() << std::endl;

        this->PutsArrayInStdout(Array);
    }

    void OutputOneDimensionalArrayInFileWithLength(OneDimensionalArrayType<Type> Array, const char * fileName) override {

        assert(Array.GetOneDimensionalArray() >= 0);

        std::ofstream WorkingFile(fileName, std::ios::out);

        this->CheckIfOutputFileIsOpen(WorkingFile);

        WorkingFile << Array.GetLengthOfOneDimensionalArray() << '\n';

        this->PutsArrayInStdFileOut(WorkingFile, Array);

        WorkingFile.close();
    }

     void OutputOneDimensionalArrayInFile(OneDimensionalArrayType<Type> Array, const char * fileName) override {

        assert(Array.GetOneDimensionalArray() >= 0);

        std::ofstream WorkingFile(fileName, std::ios::out);

         this->CheckIfOutputFileIsOpen(WorkingFile);

         this->PutsArrayInStdFileOut(WorkingFile, Array);

        WorkingFile.close();
    }

    ~IOSystemsOneDimensionalArray() = default;
};

template <class Type> class IOSystemsOneDimensionalArrayFactoryObject {

public:
    IOSystemsOneDimensionalArrayFactoryObject() = default;

    static std::shared_ptr<AbstractIOSystemsOneDimensionalArrayObject<Type>> GetIOSystemsOneDimensionalArray() {

        AbstractIOSystemsOneDimensionalArrayObject<Type> * instance = new IOSystemsOneDimensionalArray<Type>();

        return std::shared_ptr<AbstractIOSystemsOneDimensionalArrayObject<Type>>(instance);
    }

    ~IOSystemsOneDimensionalArrayFactoryObject() = default;
};

#endif //EPLUSPLUS_IOSYSTEMONEDIMENSIONALARRAY_H
