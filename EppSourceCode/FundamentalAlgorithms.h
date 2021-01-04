//
// Created by cigan on 16.12.2020.
//

#ifndef EPLUSPLUS_FUNDAMENTALALGORITHMS_H
#define EPLUSPLUS_FUNDAMENTALALGORITHMS_H

class AbstractFundamentalAlgorithmsObject {

public:
    AbstractFundamentalAlgorithmsObject() = default;

    [[maybe_unused]] virtual unsigned int GetGaussSum(unsigned int factor) {}
    [[maybe_unused]] virtual unsigned int GetFactorialNumber(unsigned int factor) {}
    [[maybe_unused]] virtual unsigned int GetFactorialNumberRecursive(unsigned int factor) {}
    [[maybe_unused]] virtual unsigned int GetFibonacciNumberRecursive(unsigned int factor) {}
    [[maybe_unused]] virtual unsigned int GetFibonacciNumber(unsigned int factor) {}
    [[maybe_unused]] virtual int GetMannaPnueliNumber(unsigned int factor) {}
    [[maybe_unused]] virtual unsigned int GetAckermanNumber(unsigned int inferiorLimit, int superiorLimit) {}
    [[maybe_unused]] virtual unsigned int GetEulerNumber(unsigned int inferiorLimit, int superiorLimit) {}
    [[maybe_unused]] virtual unsigned int GetCatalanNumber(int factor) {}

    ~AbstractFundamentalAlgorithmsObject() = default;
};

class FundamentalAlgorithms : public AbstractFundamentalAlgorithmsObject {
private:
    void StepUpInFibonacciSequence(unsigned int & firstElement, unsigned int & secondElement);
    bool IsEulerConditionChecked(int inferiorLimit, int superiorLimit);
    unsigned int GetProductOfConsecutiveElements(unsigned int factor);

public:
    FundamentalAlgorithms() = default;

    unsigned int GetGaussSum(unsigned int factor) override;
    unsigned int GetFactorialNumber(unsigned int factor) override;
    unsigned int GetFactorialNumberRecursive(unsigned int factor) override;
    unsigned int GetFibonacciNumberRecursive(unsigned int factor) override;
    unsigned int GetFibonacciNumber(unsigned int factor) override;
    int GetMannaPnueliNumber(unsigned int factor) override;
    unsigned int GetAckermanNumber(unsigned int inferiorLimit, int superiorLimit) override;
    unsigned int GetEulerNumber(unsigned int inferiorLimit, int superiorLimit) override;
    unsigned int GetCatalanNumber(int factor) override;

    ~FundamentalAlgorithms() = default;
};

void FundamentalAlgorithms::StepUpInFibonacciSequence(unsigned int & firstElement, unsigned int & secondElement) {

    int result;

    result = firstElement + secondElement;
    firstElement = secondElement;
    secondElement = result;
}

bool FundamentalAlgorithms::IsEulerConditionChecked(int inferiorLimit, int superiorLimit) {

    return (superiorLimit == 0 || superiorLimit == inferiorLimit - 1);
}

unsigned int FundamentalAlgorithms::GetProductOfConsecutiveElements(unsigned int factor) {

    int result = 1;

    for (int it = 1; it <= factor; ++it)
        result *= it;

    return result;
}

unsigned int FundamentalAlgorithms::GetGaussSum(unsigned int factor) {

    assert(factor >= 0);

    return ( factor * (factor + 1) ) / 2;
}

unsigned int FundamentalAlgorithms::GetFactorialNumber(unsigned int factor) {

    assert(factor >= 0);

    if (factor == 0 || factor == 1) return 1;

    int result = this->GetProductOfConsecutiveElements(factor);

    return result;
}

unsigned int FundamentalAlgorithms::GetFactorialNumberRecursive(unsigned int factor) {

    assert(factor >= 0);

    if (factor == 0 || factor == 1) return 1;

    return factor * GetFactorialNumberRecursive(factor - 1);
}

unsigned int FundamentalAlgorithms::GetFibonacciNumberRecursive(unsigned int factor) {

    if (factor == 0) return 0;
    if (factor == 1) return 1;

    return GetFibonacciNumberRecursive(factor - 1) + GetFibonacciNumberRecursive(factor - 2);
}

unsigned int FundamentalAlgorithms::GetFibonacciNumber(unsigned int factor) {

    assert(factor >= 0);

    if (factor == 0) return 1;

    unsigned int firstElement = 0, secondElement = 1;

    for (int it = 2; it <= factor; ++it)
        this->StepUpInFibonacciSequence(firstElement, secondElement);

    return secondElement;
}

int FundamentalAlgorithms::GetMannaPnueliNumber(unsigned int factor) {

    if (factor >= 12) return factor - 1;

    return GetMannaPnueliNumber(GetMannaPnueliNumber(factor + 2));
}

unsigned int FundamentalAlgorithms::GetAckermanNumber(unsigned int inferiorLimit, int superiorLimit) {

    assert(inferiorLimit >= 0 && superiorLimit >= 0);

    if (inferiorLimit == 0) return superiorLimit + 1;
    if (superiorLimit == 0) return GetAckermanNumber(inferiorLimit - 1, 1);

    return GetAckermanNumber(inferiorLimit - 1, GetAckermanNumber(inferiorLimit, superiorLimit - 1));
}

unsigned int FundamentalAlgorithms::GetEulerNumber(unsigned int inferiorLimit, int superiorLimit) {

    if (this->IsEulerConditionChecked(inferiorLimit, superiorLimit)) return 1;

    return (
            (inferiorLimit - superiorLimit) *
            GetEulerNumber(inferiorLimit - 1, superiorLimit - 1) + (superiorLimit + 1) *
            GetEulerNumber(inferiorLimit - 1, superiorLimit)
    );
}

unsigned int FundamentalAlgorithms::GetCatalanNumber(int factor) {

    if (factor <= 1) return 1;

    int result = 0;

    for (size_t iterator = 0; iterator < factor; iterator++)
        result += GetCatalanNumber(iterator) * GetCatalanNumber(factor - iterator - 1);

    return result;
}

class FundamentalAlgorithmsFactoryObject {

public:
    FundamentalAlgorithmsFactoryObject() = default;

    static std::shared_ptr<AbstractFundamentalAlgorithmsObject> GetFundamentalAlgorithmsObject() {

        AbstractFundamentalAlgorithmsObject * instance = new FundamentalAlgorithms();

        return std::shared_ptr<AbstractFundamentalAlgorithmsObject>(instance);
    }

    ~FundamentalAlgorithmsFactoryObject() = default;
};

#endif //EPLUSPLUS_FUNDAMENTALALGORITHMS_H
