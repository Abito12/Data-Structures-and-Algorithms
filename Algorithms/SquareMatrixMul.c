#include <stdio.h>
#include <stdlib.h>

int *SquareMatrixMul(int *A, int *B,int n){
  int i,j,k;
  int offset1, offset2,offset3;
  int sum;
  int *C = malloc(sizeof(int)*n*n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      sum = 0;
      for(k=0;k<n;k++){
        offset1 = i * n + k;
        offset2 = k * n + j;
        sum += A[offset1] * B[offset2];
      }
      offset3 = i * n + j;
      C[offset3] = sum;
    }
  }
  return C;
}


int main(){
  int n,i,j,k;
  //Dynamically allocating 2d arrays
  int *A = malloc(n*n*sizeof(int));
  int *B = malloc(n*n*sizeof(int));

  printf("Enter order of matrix\n");
  scanf("%d", &n);
  printf("Input first matrix\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      k = i*n + j;
      scanf("%d", &A[k]);
    }
  }
  printf("Input second matrix\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      k = i*n + j;
      scanf("%d", &B[k]);
    }
  }
  
  int *C = SquareMatrixMul(A, B, n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      k = i*n + j;
      printf("%d ", C[k]);
    }
    printf("\n");
  }
}
