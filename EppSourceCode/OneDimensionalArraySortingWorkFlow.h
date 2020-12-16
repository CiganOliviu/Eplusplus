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
    void InterchangeValues(Type * FirstParameter, Type * SecondParameter);
    bool IsIndexBiggerThanZeroAndArrayBiggerThanIntermediate(int iterator, Type intermediate, OneDimensionalArrayType<Type> Array);
    void StartInterchangingValues(int & iterator, Type intermediate, OneDimensionalArrayType<Type> Array);
    void ProcessInterchangeIfPossible(int iterator, Type step, OneDimensionalArrayType<Type> Array);

public:
    OneDimensionalArraySortingWorkFlow() = default;

    OneDimensionalArrayType<Type> BubbleSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    OneDimensionalArrayType<Type> MinimumValueSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    OneDimensionalArrayType<Type> InsertionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    OneDimensionalArrayType<Type> SelectionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;
    OneDimensionalArrayType<Type> ShellSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) override;

    ~OneDimensionalArraySortingWorkFlow() = default;
};

template <class Type> void OneDimensionalArraySortingWorkFlow<Type>::InterchangeValues(Type * FirstParameter, Type * SecondParameter) {

    * FirstParameter = * FirstParameter + * SecondParameter;
    * SecondParameter = * FirstParameter - * SecondParameter;
    * FirstParameter = * FirstParameter - * SecondParameter;
}

template <class Type> bool OneDimensionalArraySortingWorkFlow<Type>::IsIndexBiggerThanZeroAndArrayBiggerThanIntermediate(int iterator, Type intermediate, OneDimensionalArrayType<Type> Array) {

    return iterator >= 0 && Array.GetOneDimensionalArray()[iterator] > intermediate;
}

template <class Type> void OneDimensionalArraySortingWorkFlow<Type>::StartInterchangingValues(int & iterator, Type intermediate, OneDimensionalArrayType<Type> Array) {

    while (this->IsIndexBiggerThanZeroAndArrayBiggerThanIntermediate(iterator, intermediate, Array)) {

        Array.GetOneDimensionalArray()[iterator + 1] = Array.GetOneDimensionalArray()[iterator];
        iterator -= 1;
    }
}

template <class Type> void OneDimensionalArraySortingWorkFlow<Type>::ProcessInterchangeIfPossible(int iterator, Type step, OneDimensionalArrayType<Type> Array) {

    while (iterator >= 0) {

        if (Array.GetOneDimensionalArray()[iterator] > Array.GetOneDimensionalArray()[iterator + step]) {
            this->InterchangeValues(&Array.GetOneDimensionalArray()[iterator], &Array.GetOneDimensionalArray()[iterator + step]);
            iterator -= step;

        } else iterator -= 1;
    }
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArraySortingWorkFlow<Type>::BubbleSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() > 0);

    OneDimensionalArrayType<Type> Result = Array;

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray() - 1; ++iterator)
        for (int jiterator = 0; jiterator < Array.GetLengthOfOneDimensionalArray() - iterator - 1; ++jiterator)
            if (Array.GetOneDimensionalArray()[jiterator] > Array.GetOneDimensionalArray()[jiterator + 1])
                this->InterchangeValues(&Array.GetOneDimensionalArray()[jiterator], &Array.GetOneDimensionalArray()[jiterator + 1]);

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArraySortingWorkFlow<Type>::MinimumValueSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() > 0);

    OneDimensionalArrayType<Type> Result = Array;

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray() - 1; ++iterator)
        for (int jiterator = iterator + 1; jiterator < Array.GetLengthOfOneDimensionalArray(); ++jiterator)
            if (Array.GetOneDimensionalArray()[iterator] > Array.GetOneDimensionalArray()[jiterator])
                this->InterchangeValues(&Array.GetOneDimensionalArray()[iterator], &Array.GetOneDimensionalArray()[jiterator]);

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArraySortingWorkFlow<Type>::InsertionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() > 0);

    OneDimensionalArrayType<Type> Result = Array;
    Type intermediate;
    int jiterator;

    for (int iterator = 1; iterator < Result.GetLengthOfOneDimensionalArray(); ++iterator) {

        intermediate = Result.GetOneDimensionalArray()[iterator];
        jiterator = iterator - 1;

        this->StartInterchangingValues(jiterator, intermediate, Array);

        Result.GetOneDimensionalArray()[jiterator + 1] = intermediate;
    }

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArraySortingWorkFlow<Type>::SelectionSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetLengthOfOneDimensionalArray() > 0);

    OneDimensionalArrayType<Type> Result = Array;

    for (int iterator = 0; iterator < Array.GetLengthOfOneDimensionalArray(); ++iterator)
        for (int jiterator = iterator + 1; jiterator < Array.GetLengthOfOneDimensionalArray(); ++jiterator)
            if (Array.GetOneDimensionalArray()[iterator] > Array.GetOneDimensionalArray()[jiterator])
                this->InterchangeValues(&Array.GetOneDimensionalArray()[iterator], &Array.GetOneDimensionalArray()[jiterator]);

    return Result;
}

template <class Type> OneDimensionalArrayType<Type> OneDimensionalArraySortingWorkFlow<Type>::ShellSortOneDimensionalArray(OneDimensionalArrayType<Type> Array) {

    assert(Array.GetOneDimensionalArray() > 0);

    OneDimensionalArrayType<Type> Result = Array;
    Type step;
    int jiterator;

    step = Result.GetLengthOfOneDimensionalArray() / 2;

    while (step > 0) {

        for (int iterator = step; iterator < Result.GetLengthOfOneDimensionalArray(); ++iterator) {

            jiterator = iterator - step;
            ProcessInterchangeIfPossible(jiterator, step, Result);
        }

        step /= 2;
    }

    return Result;
}

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
