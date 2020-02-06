#include<stdio.h>
void swap(int * i, int* j);
void qsort(int *a, int i, int j);
int place_pivot(int *a, int left, int right);




void qsort2(int *a, int n){

  qsort(a, 0, n-1);

}

void qsort(int *a, int start, int end){

  
    // Get pivot

  if(start<end){
    int sub_n_val = end - start;
    int pivot = place_pivot(a,start,end);
    

    qsort(a, 0, pivot -1);
    qsort(a, pivot+1, end);
  }

  

}

// Works 
void print(int *a, int n){

  for(int i=0; i < n ; i++){
    printf("%d,", a[i]);
  }
}



int place_pivot(int *a, int left, int right){

  int i=left-1;

  int pivot = a[right];
  

  for(int j=left; j < right; j++){

    if(a[j] <= pivot){
      
      i++;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[right],&a[i+1]);

  
  //print(a,right);

  return i + 1; // return pivot position
}

// Works
//void swap(int *a, int i, int j){
void swap(int * i, int* j){

  int temp = *i;
  *i = *j;
  *j = temp;

}



  //printf();



int main() {

  int array[] = {3,4,5,8,9,7};
  size_t n = sizeof(array) / sizeof(array[0]);
  //swap(array, 0, 1);
  print(array, n);
  printf("\n");
  qsort2(array, n);
  print(array, n);

  return 0;
}