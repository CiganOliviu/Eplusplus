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
    OneDimensionalArrayType<Type> GetArrayFromStdin(unsigned int length);
    OneDimensionalArrayType<Type> GetArrayWithGivenLengthFromStdFileIn(std::ifstream &File, unsigned int length);
    OneDimensionalArrayType<Type> GetArrayFromStdFileIn(std::ifstream &File);

    void PutsArrayInStdout(OneDimensionalArrayType<Type> Array);
    void PutsArrayInStdFileOut(std::ofstream &File, OneDimensionalArrayType<Type> Array);

    void CheckIfInputFileIsEmpty(std::ifstream &File);
    void CheckIfInputFileIsOpen(std::ifstream &File);
    void CheckIfOutputFileIsOpen(std::ofstream &File);

    int ReadFirstElementFromFile(std::ifstream &File);

public:
    IOSystemsOneDimensionalArray() = default;

    OneDimensionalArrayType<Type> ReadOneDimensionalArray(unsigned int length) override;
    OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFileWithGivenLength(const char * fileName) override;
    OneDimensionalArrayType<Type> ReadOneDimensionalArrayFromFile(const char * fileName) override;

    void OutputOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    void OutputOneDimensionalArrayWithLength(OneDimensionalArrayType<Type> Array) override;
    void OutputOneDimensionalArrayInFileWithLength(OneDimensionalArrayType<Type> Array, const char * fileName) override;

    void OutputOneDimensionalArrayInFile(OneDimensionalArrayType<Type> Array, const char * fileName) override;

    ~IOSystemsOneDimensionalArray() = default;
};

template<class Type> OneDimensionalArrayType<Type> IOSystemsOneDimensionalArray<Type>::GetArrayFromStdin(unsigned int length) {

    OneDimensionalArrayType<Type> Array;

    Array.SetLengthOfOneDimensionalArray(length);

    for (unsigned int iterator = 0; iterator < length; ++iterator)
        std::cin >> Array.GetOneDimensionalArray()[iterator];

    return Array;
}

template<class Type> OneDimensionalArrayType<Type> IOSystemsOneDimensionalArray<Type>::GetArrayWithGivenLengthFromStdFileIn(std::ifstream &File, unsigned int length) {

    OneDimensionalArrayType<Type> Array;
    Array.SetLengthOfOneDimensionalArray(length);

    for (unsigned int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        File >> Array.GetOneDimensionalArray()[iterator];

    return Array;
}

template<class Type> OneDimensionalArrayType<Type> IOSystemsOneDimensionalArray<Type>::GetArrayFromStdFileIn(std::ifstream &File) {

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

template<class Type> void IOSystemsOneDimensionalArray<Type>::PutsArrayInStdout(OneDimensionalArrayType<Type> Array) {

    for (unsigned int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        std::cout << Array.GetOneDimensionalArray()[iterator] << " ";
}

template<class Type> void IOSystemsOneDimensionalArray<Type>::PutsArrayInStdFileOut(std::ofstream &File, OneDimensionalArrayType<Type> Array) {

    for (unsigned int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        File << Array.GetOneDimensionalArray()[iterator] << " ";
}

template<class Type> void IOSystemsOneDimensionalArray<Type>::CheckIfInputFileIsEmpty(std::ifstream &File) {

    if (File.tellg() < 0)
        throw std::out_of_range("Unable to read from empty file");

}

template<class Type> void IOSystemsOneDimensionalArray<Type>::CheckIfInputFileIsOpen(std::ifstream &File) {

    if (!File.is_open())
        throw std::runtime_error("Unable to open file");
}

template<class Type> void IOSystemsOneDimensionalArray<Type>::CheckIfOutputFileIsOpen(std::ofstream &File) {

    if (!File.is_open())
        throw std::runtime_error("Unable to open file");
}

template<class Type> int IOSystemsOneDimensionalArray<Type>::ReadFirstElementFromFile(std::ifstream &File) {

    int firstElement;

    File >> firstElement;

    return firstElement;
}

template<class Type> OneDimensionalArrayType<Type> IOSystemsOneDimensionalArray<Type>::ReadOneDimensionalArray(unsigned int length) {

    assert(length >= 0);

    OneDimensionalArrayType<Type> Array = this->GetArrayFromStdin(length);

    return Array;
}

template<class Type> OneDimensionalArrayType<Type> IOSystemsOneDimensionalArray<Type>::ReadOneDimensionalArrayFromFileWithGivenLength(const char * fileName) {

    std::ifstream WorkingFile(fileName, std::ios::in);

    this->CheckIfInputFileIsOpen(WorkingFile);
    this->CheckIfInputFileIsEmpty(WorkingFile);

    int firstElementOfTheFile = this->ReadFirstElementFromFile(WorkingFile);

    assert(firstElementOfTheFile >= 0);

    OneDimensionalArrayType<Type> Array = this->GetArrayWithGivenLengthFromStdFileIn(WorkingFile, firstElementOfTheFile);

    WorkingFile.close();

    return Array;
}

template<class Type> OneDimensionalArrayType<Type> IOSystemsOneDimensionalArray<Type>::ReadOneDimensionalArrayFromFile(const char * fileName) {

    std::ifstream WorkingFile(fileName, std::ios::in);

    this->CheckIfInputFileIsOpen(WorkingFile);
    this->CheckIfInputFileIsEmpty(WorkingFile);

    OneDimensionalArrayType<Type> Array = this->GetArrayFromStdFileIn(WorkingFile);

    WorkingFile.close();

    return Array;
}

template<class Type> void IOSystemsOneDimensionalArray<Type>::OutputOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    this->PutsArrayInStdout(Array);
}

template<class Type> void IOSystemsOneDimensionalArray<Type>::OutputOneDimensionalArrayWithLength(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetOneDimensionalArray() >= 0);

    std::cout << Array.GetLengthOfOneDimensionalArray() << std::endl;

    this->PutsArrayInStdout(Array);
}

template<class Type> void IOSystemsOneDimensionalArray<Type>::OutputOneDimensionalArrayInFileWithLength(OneDimensionalArrayType<Type> Array, const char * fileName) {

    assert(Array.GetOneDimensionalArray() >= 0);

    std::ofstream WorkingFile(fileName, std::ios::out);

    this->CheckIfOutputFileIsOpen(WorkingFile);

    WorkingFile << Array.GetLengthOfOneDimensionalArray() << '\n';

    this->PutsArrayInStdFileOut(WorkingFile, Array);

    WorkingFile.close();
}

template<class Type> void IOSystemsOneDimensionalArray<Type>:: OutputOneDimensionalArrayInFile(OneDimensionalArrayType<Type> Array, const char * fileName) {

    assert(Array.GetOneDimensionalArray() >= 0);

    std::ofstream WorkingFile(fileName, std::ios::out);

    this->CheckIfOutputFileIsOpen(WorkingFile);

    this->PutsArrayInStdFileOut(WorkingFile, Array);

    WorkingFile.close();
}

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
