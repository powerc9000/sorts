#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quicksort(int[], int, int);
void swap(int[], int, int);
int partition(int[], int, int, int);
int randInt(int, int);

int main(){
	int arr[] = {4,5,23,12,4,6,334,65,3,43,5};
	int i;
	//have to give it the starting and ending index of the array so it knows
	quicksort(arr, 0, 10);
	for(i=0; i<11; i++){
		printf("%d\n", arr[i]);
	}
	return 1;
}

//Gets a pivots and then calls partition
void quicksort(int array[], int left, int right){
	//A 1 element array is already sorted so if we get where left === right we have our base case
	if(left < right){
		//pick a pivot to swap items around on its just the middle of the section of the array we are working with
		int pvt = (right+left)/2;
		//puts all values smaller than pivot to the left of it and all values larger to the right of it.
		int pvtNew = partition(array, left, right, pvt);
		//call quicksort on the left side of the array (not including the pivot) hence the pvtNew -1
		quicksort(array, left, pvtNew-1);
		//call quicksort on the upper half of the array (not including the pivot) hence the pvtNew + 1;
		quicksort(array, pvtNew+1, right);
	}
}

//Swaps Elements in an array so like [5,1] would swap to [1,5]
void swap(int array[], int left, int right){
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

//puts all values smaller than pivot to the left of it and all values larger to the right of it.
int partition(int array[], int left, int right, int pivot){
	int pivotVal = array[pivot];
	//This index will be where the pivot ends up at in the array.
	int sidx = left;
	int i;
	//put the pivot at the end of the section of the array we are working with
	swap(array, pivot, right);
	for(i =left; i<right; i++){
		if(array[i] < pivotVal){
			swap(array,i,sidx);
			//keep track of how many swaps we made so we can move the pivot where is needs to go
			//Some examples if no swaps were made sidx = left+0; That means all elements were larger than it. so it goes at the very left
			//if 2 elements are smaller than it sidx = left+2 so it goes in 3rd from the left
			sidx++;
		}
	}
	//put the pivot where it needs to be (all elements smaller than it to the left all larger to the right)
	swap(array, right, sidx);
	return sidx;
}
