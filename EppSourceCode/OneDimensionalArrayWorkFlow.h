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

    ~AbstractOneDimensionalArrayWorkFlowObject() = default;
};

template <class Type> class OneDimensionalArrayWorkFlow : public AbstractOneDimensionalArrayWorkFlowObject<Type> {
private:
    void CheckIfElementsOfArrayAreDifferentThanZero(OneDimensionalArrayType<Type> Array) {

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            assert(Array.GetOneDimensionalArray()[iterator] != 0);
    }

    unsigned int GetLengthOfNumber(unsigned int number) {

        unsigned int iterator = 0;

        while (number > 0) {

            iterator += 1;
            number /= 10;
        }

        return iterator;
    }

    unsigned int ReverseNumber(unsigned int number) {

        unsigned int result = 0;

        while (number > 0) {

            int digit = number % 10;
            result = result * 10 + digit;

            number /= 10;
        }

        return result;
    }

public:
    OneDimensionalArrayWorkFlow() = default;

    Type GetMinimumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        Type result = Array.GetOneDimensionalArray()[0];

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result = result > Array.GetOneDimensionalArray()[iterator] ? Array.GetOneDimensionalArray()[iterator] : result;

        return result;
    }

    Type GetMaximumValueFromOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        Type result = Array.GetOneDimensionalArray()[0];

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result = result < Array.GetOneDimensionalArray()[iterator] ? Array.GetOneDimensionalArray()[iterator] : result;

        return result;
    }

    Type GetElementsSumOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        Type result = 0;

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result += Array.GetOneDimensionalArray()[iterator];

        return result;
    }

    Type GetElementsProductOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        Type result = 1;

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result *= Array.GetOneDimensionalArray()[iterator];

        return result;
    }

    Type GetElementsSubtractionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        Type result = Array.GetOneDimensionalArray()[0];

        for (int iterator = 1; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result -= Array.GetOneDimensionalArray()[iterator];

        return result;
    }

    Type GetElementsDivisionOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        CheckIfElementsOfArrayAreDifferentThanZero(Array);

        Type result = Array.GetOneDimensionalArray()[0];

        for (int iterator = 1; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result /= Array.GetOneDimensionalArray()[iterator];

        return result;
    }

    Type GetElementsMeanOfOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        CheckIfElementsOfArrayAreDifferentThanZero(Array);

        Type result = 0;

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            result += Array.GetOneDimensionalArray()[iterator];

        result /= Array.GetLengthOfOneDimensionalArray();

        return result;
    }

    OneDimensionalArrayType<Type> InitialiseOneDimensionalArray(unsigned int length, Type initializer) override {

        assert(length >= 0);

        OneDimensionalArrayType<Type> Array;

        Array.SetLengthOfOneDimensionalArray(length);

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            Array.GetOneDimensionalArray()[iterator] = initializer;

        return Array;
    }

    OneDimensionalArrayType<Type> PushBackValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToAdd) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        OneDimensionalArrayType<Type> ResultArray = Array;

        unsigned int ExtendedLength = ResultArray.GetLengthOfOneDimensionalArray() + 1;
        unsigned int Index = ExtendedLength - 1;

        ResultArray.GetOneDimensionalArray()[Index] = ValueToAdd;

        return ResultArray;
    }

    bool IsValueInOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type ValueToSearch) override {
        
        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            if (Array.GetOneDimensionalArray()[iterator] == ValueToSearch)
                return true;

        return false;
    }

    OneDimensionalArrayType<Type> NormaliseOneDimensionalArray(unsigned int length) {

        OneDimensionalArrayType<Type> Array;

        Array.SetLengthOfOneDimensionalArray(length);

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            Array.GetOneDimensionalArray()[iterator] = 0;

        return Array;
    }

    OneDimensionalArrayType<Type> ConvertNumberToOneDimensionalArray(unsigned int numberToConvert) override {

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

    OneDimensionalArrayType<Type> BoostUpOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            Array.GetOneDimensionalArray()[iterator] *= factor;

        return Array;
    }

    OneDimensionalArrayType<Type> BoostDownOneDimensionalArray(OneDimensionalArrayType<Type> Array, Type factor) override {

        assert(Array.GetLengthOfOneDimensionalArray() >= 0);

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            Array.GetOneDimensionalArray()[iterator] /= factor;

        return Array;
    }


    ~OneDimensionalArrayWorkFlow() = default;
};

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
