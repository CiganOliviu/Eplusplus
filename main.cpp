#include "DataStructures/OneDimensionalArray.h"
#include "EppSourceCode/IOSystemsOneDimensionalArray.h"

int main() {

    AbstractOneDimensionalArrayObject<int> * AbstractArray;
    OneDimensionalArrayType<int> Array;

    AbstractArray = &Array;

    AbstractIOSystemsOneDimensionalArrayObject<int> * AbstractIOSystem;
    IOSystemsOneDimensionalArray<int> IOSystem;

    Array = IOSystem.ReadOneDimensionalArray(5);
    IOSystem.OutputOneDimensionalArray(Array);

    return 0;
}
