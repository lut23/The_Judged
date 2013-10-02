#include<stdlib.h>
int sumArraySizes(int num_arrays,int* sizes){
  int sum =0;
  int i;
  for(i=0;i<num_arrays;i++){
    sum+=sizes[i];
}
  return sum;
}
int max(int size, int* arr){
  int i;
  int max = arr[0];
  for(i=1;i<size;i++){
    if(max < arr[i]){
      max = arr[i];
    }
  }
  return max;
}
int* countSort(int size,int* arr){
  int largest = max(size, arr);
  int* countArr = (int*)calloc(largest+1,sizeof(int));
  int i;
  for(i=0; i<=largest;i++){
    countArr[i]=0;
  }
  for(i=0;i<size;i++){
    countArr[arr[i]]+=1;
  }
  int uniq = 0;
  for(i=0; i<=largest;i++){
    if(countArr[i] !=0){
      uniq+=1;
    }
  }
  int* uniqSorted = (int*)calloc((uniq+1),sizeof(int));
  int j =1;
  uniqSorted[0]=uniq;
  for(i=0;i <= largest;i++){
     if(countArr[i] !=0){
      uniqSorted[j]=i;
      j++;
    }
  }
  free(countArr);
  return uniqSorted;
}
int* array_merge(int num_arrays, int* sizes, int** values){
  int* sumArr = (int*)calloc(sumArraySizes(num_arrays,sizes),sizeof(int));
  int i;
  int j;
  int k = 0;
  for(i=0;i<num_arrays;i++){
    for(j=0;j<sizes[i];j++){
      sumArr[k]= values[i][j];
      k++;
    }
  }
  int* sorted = countSort(k,sumArr);
  free(sumArr);
  return sorted;
}
