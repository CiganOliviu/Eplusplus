#include "SystemTests/ObjectsTests.h"
#include "SystemTests/IOSystemsTests.h"
#include "SystemTests/OneDimensionalArrayWorkFlowTests.h"
#include "SystemTests/OneDimensionalArraySortingWorkFlowTests.h"

void RunObjectsTests() {

    TestsOneDimensionalArrayObject<int> ODAObject;
    TestsMatrixObject<int> MatrixObject;

    ODAObject.Test_Set_Get_Length_();
    ODAObject.Test_Set_Get_OneDimensionalArray_();

    MatrixObject.Test_Set_Get_Line_();
    MatrixObject.Test_Set_Get_Column_();
    MatrixObject.Test_Set_Get_Matrix_();
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

    ArrayTestsInteger.Test_GetMinimumValueFromOneDimensionalArray_();
    ArrayTestsInteger.Test_GetMaximumValueFromOneDimensionalArray_();
    ArrayTestsInteger.Test_GetElementsSumOfOneDimensionalArray_();
    ArrayTestsInteger.Test_GetElementsProductOfOneDimensionalArray_();
    ArrayTestsInteger.Test_GetElementsSubtractionOfOneDimensionalArray_();

    ArrayTestsFloat.Test_GetElementsDivisionOfOneDimensionalArray_();
    ArrayTestsFloat.Test_GetElementsMeanOfOneDimensionalArray_();

    ArrayTestsInteger.Test_InitialiseOneDimensionalArray_();
    ArrayTestsInteger.Test_PushBackValueInOneDimensionalArray_();
    ArrayTestsInteger.Test_IsValueInOneDimensionalArray_();
    ArrayTestsInteger.Test_NormaliseOneDimensionalArray_();
    ArrayTestsInteger.Test_ConvertNumberToOneDimensionalArray_();
    ArrayTestsInteger.Test_BoostUpOneDimensionalArray_();
    ArrayTestsInteger.Test_BoostDownOneDimensionalArray_();

    ArrayTestsInteger.Test_GetSumOfOneDimensionalArrayObjects_();
    ArrayTestsInteger.Test_GetSubtractionOfOneDimensionalArrayObjects_();
    ArrayTestsInteger.Test_GetDivisionOfOneDimensionalArrayObjects_();
    ArrayTestsInteger.Test_GetProductOfOneDimensionalArrayObjects_();
}

void RunOneDimensionalArraySortingWorkFlowTests() {

    TestsOneDimensionalArraySortingWorkFlowObject<int> ArraySortTests;

    ArraySortTests.Test_BubbleSortOneDimensionalArray_();
}

int main() {

    RunObjectsTests();
    // This suit of tests require console input, run it AFTER YOU READ THE CODE FROM IT! Delete this comment if out of date.
    // RunIOTests();
    RunOneDimensionalArrayWorkFlowTests();
    RunOneDimensionalArraySortingWorkFlowTests();

    return 0;
}
