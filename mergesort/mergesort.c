#include <stdlib.h>
#include <stdbool.h>

void mergesort(int size, int values[]){
  mergesortRange(values, 0, size);
}

bool needsSorting(int rage){
  return (rage >= 2);
}

void mergeRanges(int values[],int startIndex, int midPoint, int endIndex){
  int rangeSize = endIndex - startIndex;
  int* destination = (int*)calloc(rangeSize,sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;

  while(firstIndex < midPoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      ++firstIndex;
    } else {
      destination[copyIndex] = values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
  }

  while(firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }

   while (secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
    }

   int i;
   for (i = 0; i < rangeSize; ++i) {
    values[i + startIndex] = destination[i];
    }
   free(destination);
}

void mergesortRange(int values[], int startIndex, int endIndex){
  int rangeSize = endIndex - startIndex;
  int midPoint;
  if(needsSorting(rangeSize)){
    midPoint = (startIndex+endIndex)/2;
    mergesortRange(values,startIndex,midPoint);
    mergesortRange(values,midPoint,endIndex);
    mergeRanges(values,startIndex,midPoint,endIndex);
  }
}
