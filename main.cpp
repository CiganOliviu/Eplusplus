#include "SystemTests/ObjectsTests.h"
#include "SystemTests/IOSystemsTests.h"
#include "SystemTests/OneDimensionalArrayWorkFlowTests.h"

void RunODAObjectTests() {

    TestsOneDimensionalArrayObject<int> ODAObject;

    ODAObject.Test_Set_Get_Length_();
    ODAObject.Test_Set_Get_OneDimensionalArray_();
}

void RunIOTests() {

    TestsIOSystemsOneDimensionalArrayObject<int> IOSys;

    IOSys.Test_ReadAndOutputOneDimensionalArrayInConsole_();
    IOSys.Test_ReadAndOutputOneDimensionalArrayWithGivenLength_();
    IOSys.Test_ReadAndOutputOneDimensionalArrayFromFile_();
}

void RunOneDimensionalArrayWorkFlowTests() {

    TestsOneDimensionalArrayWorkFlowObject<int> ArrayTestsInteger;
    TestsOneDimensionalArrayWorkFlowObject<float> ArrayTestsFloat;

    ArrayTestsInteger.Tests_GetMinimumValueFromOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetMaximumValueFromOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetElementsSumOfOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetElementsProductOfOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetElementsSubtractionOfOneDimensionalArray_();

    ArrayTestsFloat.Tests_GetElementsDivisionOfOneDimensionalArray_();
    ArrayTestsFloat.Tests_GetElementsMeanOfOneDimensionalArray_();

    ArrayTestsInteger.Tests_InitialiseOneDimensionalArray_();
}

int main() {

    RunODAObjectTests();
    // This suit of tests require console input, run it AFTER YOU READ THE CODE FROM IT! Delete this comment if out of date.
    // RunIOTests();
    RunOneDimensionalArrayWorkFlowTests();

    return 0;
}
