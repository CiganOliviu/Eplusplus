//
// Created by cigan on 04.12.2020.
//

#ifndef EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOW_H
#define EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOW_H

#include "../DataStructures/OneDimensionalArray.h"

template <class Type> class AbstractOneDimensionalArrayWorkFlowObject {

public:
    AbstractOneDimensionalArrayWorkFlowObject() = default;

    [[maybe_unused]] virtual Type GetMinimumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual Type GetMaximumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual Type GetElementsSumOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual Type GetElementsProductOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual Type GetElementsSubtractionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual Type GetElementsDivisionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual Type GetElementsMeanOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> InitialiseOneDimensionalArray(unsigned int length, Type initializer) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> PushBackValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToAdd) {}
    [[maybe_unused]] virtual bool IsValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToSearch) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> NormaliseOneDimensionalArray(unsigned int length) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> ConvertNumberToOneDimensionalArray(unsigned int numberToConvert) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> BoostUpOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> BoostDownOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> GetSumOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> GetSubtractionOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> GetDivisionOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> GetProductOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {}

    ~AbstractOneDimensionalArrayWorkFlowObject() = default;
};

template <class Type> class OneDimensionalArrayWorkFlow : public AbstractOneDimensionalArrayWorkFlowObject<Type> {
private:
    void CheckIfElementsOfArrayAreDifferentThanZero(OneDimensionalArrayType<Type> Array);
    unsigned int GetLengthOfNumber(unsigned int number);
    unsigned int ReverseNumber(unsigned int number);

public:
    OneDimensionalArrayWorkFlow() = default;

    Type GetMinimumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    Type GetMaximumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    Type GetElementsSumOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    Type GetElementsProductOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    Type GetElementsSubtractionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    Type GetElementsDivisionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    Type GetElementsMeanOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    OneDimensionalArrayType<Type> InitialiseOneDimensionalArray(unsigned int length, Type initializer) override;
    OneDimensionalArrayType<Type> PushBackValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToAdd) override;
    bool IsValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToSearch) override;
    OneDimensionalArrayType<Type> NormaliseOneDimensionalArray(unsigned int length) override;
    OneDimensionalArrayType<Type> ConvertNumberToOneDimensionalArray(unsigned int numberToConvert) override;
    OneDimensionalArrayType<Type> BoostUpOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) override;
    OneDimensionalArrayType<Type> BoostDownOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) override;
    OneDimensionalArrayType<Type> GetSumOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override;
    OneDimensionalArrayType<Type> GetSubtractionOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override;
    OneDimensionalArrayType<Type> GetDivisionOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override;
    OneDimensionalArrayType<Type> GetProductOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) override;

    ~OneDimensionalArrayWorkFlow() = default;
};

template <class Type> void OneDimensionalArrayWorkFlow<Type>::CheckIfElementsOfArrayAreDifferentThanZero(OneDimensionalArrayType<Type> Array) {

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        assert(Array.GetOneDimensionalArray()[iterator] != 0);
}

template <class Type> unsigned int OneDimensionalArrayWorkFlow<Type>::GetLengthOfNumber(unsigned int number) {

    unsigned int iterator = 0;

    while (number > 0) {

        iterator += 1;
        number /= 10;
    }

    return iterator;
}

template <class Type> unsigned int OneDimensionalArrayWorkFlow<Type>::ReverseNumber(unsigned int number) {

    unsigned int result = 0;

    while (number > 0) {

        int digit = number % 10;
        result = result * 10 + digit;

        number /= 10;
    }

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>::GetMinimumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    Type result = Array.GetOneDimensionalArray()[0];

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result = result > Array.GetOneDimensionalArray()[iterator] ? Array.GetOneDimensionalArray()[iterator] : result;

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>::GetMaximumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    Type result = Array.GetOneDimensionalArray()[0];

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result = result < Array.GetOneDimensionalArray()[iterator] ? Array.GetOneDimensionalArray()[iterator] : result;

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>:: GetElementsSumOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    Type result = 0;

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result += Array.GetOneDimensionalArray()[iterator];

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>:: GetElementsProductOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    Type result = 1;

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result *= Array.GetOneDimensionalArray()[iterator];

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>:: GetElementsSubtractionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    Type result = Array.GetOneDimensionalArray()[0];

    for (int iterator = 1; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result -= Array.GetOneDimensionalArray()[iterator];

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>:: GetElementsDivisionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    this->CheckIfElementsOfArrayAreDifferentThanZero(Array);

    Type result = Array.GetOneDimensionalArray()[0];

    for (int iterator = 1; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result /= Array.GetOneDimensionalArray()[iterator];

    return result;
}

template <class Type> Type OneDimensionalArrayWorkFlow<Type>:: GetElementsMeanOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    this->CheckIfElementsOfArrayAreDifferentThanZero(Array);

    Type result = 0;

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        result += Array.GetOneDimensionalArray()[iterator];

    result /= Array.GetLengthOfOneDimensionalArray();

    return result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::InitialiseOneDimensionalArray(unsigned int length, Type initializer) {

    assert(length >= 0);

    OneDimensionalArrayType<Type> Array;

    Array.SetLengthOfOneDimensionalArray(length);

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        Array.GetOneDimensionalArray()[iterator] = initializer;

    return Array;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::PushBackValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToAdd) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    OneDimensionalArrayType<Type> ResultArray = Array;

    unsigned int ExtendedLength = ResultArray.GetLengthOfOneDimensionalArray() + 1;
    unsigned int Index = ExtendedLength - 1;

    ResultArray.GetOneDimensionalArray()[Index] = ValueToAdd;

    return ResultArray;
}

template <class Type> bool OneDimensionalArrayWorkFlow<Type>::IsValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToSearch) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        if (Array.GetOneDimensionalArray()[iterator] == ValueToSearch)
            return true;

    return false;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::NormaliseOneDimensionalArray(unsigned int length) {

    OneDimensionalArrayType<Type> Array;

    Array.SetLengthOfOneDimensionalArray(length);

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        Array.GetOneDimensionalArray()[iterator] = 0;

    return Array;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::ConvertNumberToOneDimensionalArray(unsigned int numberToConvert) {

    OneDimensionalArrayType<Type> Array;
    Array.SetLengthOfOneDimensionalArray(this->GetLengthOfNumber(numberToConvert));

    numberToConvert = this->ReverseNumber(numberToConvert);

    unsigned int iterator = 0;

    while (numberToConvert > 0) {

        unsigned int Digit = numberToConvert % 10;

        Array.GetOneDimensionalArray()[iterator] = Digit;
        iterator += 1;

        numberToConvert /= 10;
    }

    return Array;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::BoostUpOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        Array.GetOneDimensionalArray()[iterator] *= factor;

    return Array;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::BoostDownOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) {

    assert(Array.GetLengthOfOneDimensionalArray() >= 0);

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        Array.GetOneDimensionalArray()[iterator] /= factor;

    return Array;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::GetSumOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {

    assert(FirstArray.GetLengthOfOneDimensionalArray() > 0);
    assert(SecondArray.GetLengthOfOneDimensionalArray() > 0);
    assert(FirstArray.GetLengthOfOneDimensionalArray() == SecondArray.GetLengthOfOneDimensionalArray());

    OneDimensionalArrayType<Type> Result;
    Result.SetLengthOfOneDimensionalArray(FirstArray.GetLengthOfOneDimensionalArray());

    for (int iterator = 0; iterator < Result.GetLengthOfOneDimensionalArray(); ++iterator)
        Result.GetOneDimensionalArray()[iterator] = FirstArray.GetOneDimensionalArray()[iterator] + SecondArray.GetOneDimensionalArray()[iterator];

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::GetSubtractionOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {

    assert(FirstArray.GetLengthOfOneDimensionalArray() > 0);
    assert(SecondArray.GetLengthOfOneDimensionalArray() > 0);
    assert(FirstArray.GetLengthOfOneDimensionalArray() == SecondArray.GetLengthOfOneDimensionalArray());

    OneDimensionalArrayType<Type> Result;
    Result.SetLengthOfOneDimensionalArray(FirstArray.GetLengthOfOneDimensionalArray());

    for (int iterator = 0; iterator < Result.GetLengthOfOneDimensionalArray(); ++iterator)
        Result.GetOneDimensionalArray()[iterator] = FirstArray.GetOneDimensionalArray()[iterator] - SecondArray.GetOneDimensionalArray()[iterator];

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::GetDivisionOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {

    assert(FirstArray.GetLengthOfOneDimensionalArray() > 0);
    assert(SecondArray.GetLengthOfOneDimensionalArray() > 0);
    assert(FirstArray.GetLengthOfOneDimensionalArray() == SecondArray.GetLengthOfOneDimensionalArray());

    OneDimensionalArrayType<Type> Result;
    Result.SetLengthOfOneDimensionalArray(FirstArray.GetLengthOfOneDimensionalArray());

    for (int iterator = 0; iterator < Result.GetLengthOfOneDimensionalArray(); ++iterator)
        Result.GetOneDimensionalArray()[iterator] = FirstArray.GetOneDimensionalArray()[iterator] / SecondArray.GetOneDimensionalArray()[iterator];

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArrayWorkFlow<Type>::GetProductOfOneDimensionalArrayObjects(OneDimensionalArrayType<Type> FirstArray, OneDimensionalArrayType<Type> SecondArray) {

    assert(FirstArray.GetLengthOfOneDimensionalArray() > 0);
    assert(SecondArray.GetLengthOfOneDimensionalArray() > 0);
    assert(FirstArray.GetLengthOfOneDimensionalArray() == SecondArray.GetLengthOfOneDimensionalArray());

    OneDimensionalArrayType<Type> Result;
    Result.SetLengthOfOneDimensionalArray(FirstArray.GetLengthOfOneDimensionalArray());

    for (int iterator = 0; iterator < Result.GetLengthOfOneDimensionalArray(); ++iterator)
        Result.GetOneDimensionalArray()[iterator] = FirstArray.GetOneDimensionalArray()[iterator] * SecondArray.GetOneDimensionalArray()[iterator];

    return Result;
}

template <class Type> class OneDimensionalArrayWorkFlowFactoryObject {

public:
    OneDimensionalArrayWorkFlowFactoryObject() = default;

    static std::shared_ptr<AbstractOneDimensionalArrayWorkFlowObject<Type>> GetOneDimensionalArrayWorkFlowObject() {

        AbstractOneDimensionalArrayWorkFlowObject<Type> * instance = new OneDimensionalArrayWorkFlow<Type>();

        return std::shared_ptr<AbstractOneDimensionalArrayWorkFlowObject<Type>>(instance);
    }

    ~OneDimensionalArrayWorkFlowFactoryObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOW_H
