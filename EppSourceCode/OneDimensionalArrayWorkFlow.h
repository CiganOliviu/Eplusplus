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

    ~AbstractOneDimensionalArrayWorkFlowObject() = default;
};

template <class Type> class OneDimensionalArrayWorkFlow : public AbstractOneDimensionalArrayWorkFlowObject<Type> {
private:
    void CheckIfElementsOfArrayAreDifferentThanZero(OneDimensionalArrayType<Type> Array) {

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            assert(Array.GetOneDimensionalArray()[iterator] != 0);
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

    ~OneDimensionalArrayWorkFlow() = default;
};

template <class Type> class OneDimensionalArrayWorkFlowFactoryObject {

public:
    OneDimensionalArrayWorkFlowFactoryObject() = default;

    static AbstractOneDimensionalArrayWorkFlowObject<Type> GetOneDimensionalArrayWorkFlowObject() {

        return OneDimensionalArrayWorkFlow<Type>();
    }

    ~OneDimensionalArrayWorkFlowFactoryObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYWORKFLOW_H
