#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mergesort(int[], int);
int* merge(int*, int, int*, int);
void printArray(int[], int);
int main(){
	int arr[3] = {7,6,2};
	int i;
	mergesort(arr, 3);

	printArray(arr, 3);
}

void mergesort(int array[], int size){
	if(size <= 1) return;
	int lsize =0;
	int rsize = 0;
	int i;
	int middle = size/2;
	int * left = (int*) malloc(sizeof(int) * size);
	int * right = (int*) malloc(sizeof(int) * size);
	int * result;

	
	for(i=0; i < size; i++){
		if(i < middle){
			left[lsize] = array[i];
			lsize++;
		}
		else{
			right[rsize] = array[i];
			rsize++;
		}
	}

	mergesort(left, lsize);
	mergesort(right, rsize);
	result = merge(left, lsize, right, rsize);
	
	memcpy(array, result, size* sizeof(int));
	free(result);

}

int * merge(int* left, int lsize, int* right, int rsize){
	int* result = (int*) malloc(sizeof(int) * (lsize + rsize));
	int rpos = 0;
	int lpos = 0;
	int resultpos = 0;
	while(resultpos < (lsize+rsize)){
		if(lsize - lpos > 0 && rsize - rpos > 0){
			if(left[lpos] <= right[rpos]){
				result[resultpos++] = left[lpos++];
			}
			else{
				result[resultpos++] = right[rpos++];
			}
		}
		else if(lsize - lpos > 0){
			result[resultpos++] = left[lpos++];
		}
		else if(rsize - rpos > 0){
			result[resultpos++] = right[rpos++];
		}
	}
	
	free(left);
	free(right);
	return result;

}

void printArray(int array[], int size){
	int i;
	printf("%s", "[");
	for(i=0; i<size; i++){
		printf("%d,", array[i]);
	}
	printf("%s\n", "]");
}

