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

    [[maybe_unused]] virtual unsigned int GetLengthOfOneDimensionalArray() {}
    [[maybe_unused]] virtual void SetLengthOfOneDimensionalArray(unsigned int length) {}

    [[maybe_unused]] virtual Type * GetOneDimensionalArray() {}
    [[maybe_unused]] virtual void SetOneDimensionalArray(Type * Array) {}

    ~AbstractOneDimensionalArrayObject() = default;
};

template <class Type> class OneDimensionalArrayType : public AbstractOneDimensionalArrayObject<Type> {

private:
    unsigned int _length {};
    Type * OneDimensionalArray = (Type * ) malloc(STANDARD_LENGTH * sizeof(Type));

public:
    OneDimensionalArrayType() = default;

    unsigned int GetLengthOfOneDimensionalArray() override;
    void SetLengthOfOneDimensionalArray(unsigned int length) override;

    Type * GetOneDimensionalArray() override;
    void SetOneDimensionalArray(Type * Array) override;

    ~OneDimensionalArrayType() = default;
};

template <class Type> unsigned int OneDimensionalArrayType<Type>::GetLengthOfOneDimensionalArray() {

    return this->_length;
}

template<class Type> void OneDimensionalArrayType<Type>::SetLengthOfOneDimensionalArray(unsigned int length) {

    this->_length = length;
}

template<class Type> Type *OneDimensionalArrayType<Type>::GetOneDimensionalArray() {

    return this->OneDimensionalArray;
}

template<class Type> void OneDimensionalArrayType<Type>::SetOneDimensionalArray(Type * Array) {

    this->OneDimensionalArray = Array;
}

template <class Type> class OneDimensionalArrayTypeFactoryObject {

public:
    OneDimensionalArrayTypeFactoryObject() = default;

    static std::shared_ptr<AbstractOneDimensionalArrayObject<Type>> GetOneDimensionalArrayTypeObject() {

        AbstractOneDimensionalArrayObject<Type> * instance = new OneDimensionalArrayType<Type>();

        return std::shared_ptr<AbstractOneDimensionalArrayObject<Type>>(instance);
    }

    ~OneDimensionalArrayTypeFactoryObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAY_H
