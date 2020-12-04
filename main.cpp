#include "SystemTests/ObjectsTests.h"
#include "SystemTests/IOSystemsTests.h"
#include "SystemTests/OneDimensionalArrayWorkFlowTests.h"

int main() {

    TestsOneDimensionalArrayObject<int> ODAObject;
    TestsIOSystemsOneDimensionalArrayObject<int> IOSys;
    TestsOneDimensionalArrayWorkFlowObject<int> ArrayTestsInteger;
    TestsOneDimensionalArrayWorkFlowObject<float> ArrayTestsFloat;

    ODAObject.Test_Set_Get_Length_();
    ODAObject.Test_Set_Get_OneDimensionalArray_();

    // IOSys.Test_ReadAndOutputOneDimensionalArrayInConsole_();
    IOSys.Test_ReadAndOutputOneDimensionalArrayWithGivenLength_();
    IOSys.Test_ReadAndOutputOneDimensionalArrayFromFile_();

    NEWLINE();

    ArrayTestsInteger.Tests_GetMinimumValueFromOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetMaximumValueFromOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetElementsSumOfOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetElementsProductOfOneDimensionalArray_();
    ArrayTestsInteger.Tests_GetElementsSubtractionOfOneDimensionalArray_();

    ArrayTestsFloat.Tests_GetElementsDivisionOfOneDimensionalArray_();
    ArrayTestsFloat.Tests_GetElementsMeanOfOneDimensionalArray_();

    return 0;
}
