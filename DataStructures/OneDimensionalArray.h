//
// Created by cigan on 02.12.2020.
//

#ifndef EPLUSPLUS_ONEDIMENSIONALARRAY_H
#define EPLUSPLUS_ONEDIMENSIONALARRAY_H

#include "../PreprocessorDirectives/StandardLibrary.h"
#include "../PreprocessorDirectives/DefinedDirectives.h"

template <class Type> class AbstractOneDimensionalArrayObject {

public:
    AbstractOneDimensionalArrayObject() = default;

    virtual unsigned int GetLengthOfOneDimensionalArray() {}
    virtual void SetLengthOfOneDimensionalArray(unsigned int length) {}

    virtual Type * GetOneDimensionalArray() {}
    virtual void SetOneDimensionalArray(Type * Array) {}

    ~AbstractOneDimensionalArrayObject() = default;
};

template <class Type> class OneDimensionalArrayType : public AbstractOneDimensionalArrayObject<Type> {

private:
    unsigned int _length {};
    Type * OneDimensionalArray = (Type * ) malloc(STANDARD_LENGTH * sizeof(Type));

public:
    OneDimensionalArrayType() = default;

    unsigned int GetLengthOfOneDimensionalArray() {

        return this->_length;
    }

    void SetLengthOfOneDimensionalArray(unsigned int length) {

        this->_length = length;
    }

    Type * GetOneDimensionalArray() {

        return this->OneDimensionalArray;
    }

    void SetOneDimensionalArray(Type * Array) {

        this->OneDimensionalArray = Array;
    }

    ~OneDimensionalArrayType() = default;
};

template <class Type> class OneDimensionalArrayTypeFactoryObject {

public:
    OneDimensionalArrayTypeFactoryObject() = default;

    static AbstractOneDimensionalArrayObject<Type> GetOneDimensionalArrayTypeObject() {

        return OneDimensionalArrayType<Type>();
    }

    ~OneDimensionalArrayTypeFactoryObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAY_H
