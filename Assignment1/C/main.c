#include<stdio.h>

void qsort2(int *a, int n){


}

void place_pivot(int *a, int n){

  int i=0;
  int j=0; 
  int pivot = *(a+(n-1)); 
  //printf("%d",pivot); // Works

  for(int j=0; j < n ; j++){
    
    if(a[j] < pivot){
      i++;
      
      // Swap
      int temp = *(a+i);
      a[i] = *(a+j);
      a[j] = temp;
      
    }
  }
}

// Works
void swap(int *a, int i, int j){

  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;

}

// Works 
void print(int *a, int n){

  for(int i=0; i < n ; i++){
    printf("%d,", a[i]);
  }

  //printf();
}


int main() {

  int array[] = {3,4,5,8,9,7};
  size_t n = sizeof(array) / sizeof(array[0]);
  //swap(array, 0, 1);
  place_pivot(array, n);
  print(array, n);

  return 0;
}