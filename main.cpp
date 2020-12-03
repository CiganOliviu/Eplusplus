#include "DataStructures/OneDimensionalArray.h"
#include "EppSourceCode/IOSystemsOneDimensionalArray.h"

int main() {

       AbstractOneDimensionalArrayObject<int> * AbstractArray;
       OneDimensionalArrayType<int> Array;

       AbstractArray = &Array;

       AbstractIOSystemsOneDimensionalArrayObject<int> * AbstractIOSystem;
       IOSystemsOneDimensionalArray<int> IOSystem;

    return 0;
}
