//
// Created by cigan on 16.12.2020.
//

#ifndef EPLUSPLUS_FUNDAMENTALALGORITHMSTESTS_H
#define EPLUSPLUS_FUNDAMENTALALGORITHMSTESTS_H

#include "../EppSourceCode/FundamentalAlgorithms.h"

class TestsFundamentalAlgorithmsObject {
private:
    std::shared_ptr<AbstractFundamentalAlgorithmsObject> Algorithms;

public:
    TestsFundamentalAlgorithmsObject() {

        Algorithms = FundamentalAlgorithmsFactoryObject::GetFundamentalAlgorithmsObject();
    }

    void Test_GetGaussSum_() {

        assert(this->Algorithms->GetGaussSum(5) == 15);
        assert(this->Algorithms->GetGaussSum(6) == 21);
        assert(this->Algorithms->GetGaussSum(1) == 1);
    }

    void Test_GetFactorialNumber_() {

        assert(this->Algorithms->GetFactorialNumber(5) == 120);
        assert(this->Algorithms->GetFactorialNumber(7) == 5040);
        assert(this->Algorithms->GetFactorialNumber(0) == 1);

    }

    void Test_GetFactorialNumberRecursive_() {

        assert(this->Algorithms->GetFactorialNumber(5) == 120);
        assert(this->Algorithms->GetFactorialNumber(7) == 5040);
        assert(this->Algorithms->GetFactorialNumber(0) == 1);
    }

    void Test_GetFibonacciNumberRecursive_() {

        assert(this->Algorithms->GetFibonacciNumberRecursive(10) == 55);
        assert(this->Algorithms->GetFibonacciNumberRecursive(14) == 377);
        assert(this->Algorithms->GetFibonacciNumberRecursive(1) == 1);
    }

    void Test_GetFibonacciNumber_() {

        assert(this->Algorithms->GetFibonacciNumber(10) == 55);
        assert(this->Algorithms->GetFibonacciNumber(14) == 377);
        assert(this->Algorithms->GetFibonacciNumber(1) == 1);
    }

    void Test_GetMannaPnueliNumber_() {

        assert(this->Algorithms->GetMannaPnueliNumber(8) == 11);
        assert(this->Algorithms->GetMannaPnueliNumber(15) == 14);
    }

    void Test_GetAckermanNumber_() {

        assert(this->Algorithms->GetAckermanNumber(1, 2) == 4);
    }

    void Test_GetEulerNumber_() {

        assert(this->Algorithms->GetEulerNumber(3, 1) == 4);
    }

    void Test_GetCatalanNumber_() {

        assert(this->Algorithms->GetCatalanNumber(3) == 5);
    }

    ~TestsFundamentalAlgorithmsObject() = default;
};

#endif //EPLUSPLUS_FUNDAMENTALALGORITHMSTESTS_H
