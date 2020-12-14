//
// Created by cigan on 13.12.2020.
//

#ifndef EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOW_H
#define EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOW_H

#include "../DataStructures/OneDimensionalArray.h"

template <class Type> class AbstractOneDimensionalArraySortingWorkFlowObject {

public:
    AbstractOneDimensionalArraySortingWorkFlowObject() = default;

    [[maybe_unused]] virtual OneDimensionalArrayType<Type> BubbleSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> MinimumValueSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> InsertionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> SelectionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}
    [[maybe_unused]] virtual OneDimensionalArrayType<Type> ShellSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {}

    ~AbstractOneDimensionalArraySortingWorkFlowObject() = default;
};

template <class Type> class OneDimensionalArraySortingWorkFlow : public AbstractOneDimensionalArraySortingWorkFlowObject<Type> {
private:
    void InterchangeValues(Type * FirstParameter, Type * SecondParameter) {

        * FirstParameter = * FirstParameter + * SecondParameter;
        * SecondParameter = * FirstParameter - * SecondParameter;
        * FirstParameter = * FirstParameter - * SecondParameter;
    }

public:
    OneDimensionalArraySortingWorkFlow() = default;

    OneDimensionalArrayType<Type> BubbleSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() > 0);

        OneDimensionalArrayType<Type> Result = Array;

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray() - 1; ++iterator)
            for (int jiterator = 0; jiterator < Array.GetLengthOfOneDimensionalArray() - iterator - 1; ++jiterator)
                if (Array.GetOneDimensionalArray()[jiterator] > Array.GetOneDimensionalArray()[jiterator + 1])
                    InterchangeValues(&Array.GetOneDimensionalArray()[jiterator], &Array.GetOneDimensionalArray()[jiterator + 1]);

        return Result;
    }

    OneDimensionalArrayType<Type> MinimumValueSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() > 0);

        OneDimensionalArrayType<Type> Result = Array;

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray() - 1; ++iterator)
            for (int jiterator = iterator + 1; jiterator < Array.GetLengthOfOneDimensionalArray(); ++jiterator)
                if (Array.GetOneDimensionalArray()[iterator] > Array.GetOneDimensionalArray()[jiterator])
                    InterchangeValues(&Array.GetOneDimensionalArray()[iterator], &Array.GetOneDimensionalArray()[jiterator]);

        return Result;
    }

    OneDimensionalArrayType<Type> InsertionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

    }

    OneDimensionalArrayType<Type> SelectionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

        assert(Array.GetLengthOfOneDimensionalArray() > 0);

        OneDimensionalArrayType<Type> Result = Array;

        for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
            for (int jiterator = iterator + 1; jiterator < Array.GetLengthOfOneDimensionalArray(); ++jiterator)
                if (Array.GetOneDimensionalArray()[iterator] > Array.GetOneDimensionalArray()[jiterator])
                    InterchangeValues(&Array.GetOneDimensionalArray()[iterator], &Array.GetOneDimensionalArray()[jiterator]);

        return Result;
    }

    OneDimensionalArrayType<Type> ShellSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override {

    }

    ~OneDimensionalArraySortingWorkFlow() = default;
};

template <class Type> class OneDimensionalArraySortingWorkFlowFactoryObject {

public:
    OneDimensionalArraySortingWorkFlowFactoryObject() = default;

    static std::shared_ptr<AbstractOneDimensionalArraySortingWorkFlowObject<Type>> GetOneDimensionalArraySortingWorkFlowObject() {

        AbstractOneDimensionalArraySortingWorkFlowObject<Type> * instance = new OneDimensionalArraySortingWorkFlow<Type>();

        return std::shared_ptr<AbstractOneDimensionalArraySortingWorkFlowObject<Type>>(instance);
    }

    ~OneDimensionalArraySortingWorkFlowFactoryObject() = default;
};

#endif //EPLUSPLUS_ONEDIMENSIONALARRAYSORTINGWORKFLOW_H
