function quicksort(array){
	quick_sort(array, 0, array.length-1);
}
function quick_sort(array, left, right){
	if(left < right){
		var pvt = randInt(left, right);
		var pvtNew = partition(array, left, right, pvt);
		quick_sort(array, left, pvtNew -1);
		quick_sort(array, pvtNew+1, right);
	}
	
}
function partition(array, left, right, pivot){
	var pval = array[pivot];
	var sidx;
	swap(array, pivot, right);
	sidx = left;
	for(var i=left; i<right; i++){
		if(array[i] < pval){
			swap(array, sidx, i)
			sidx += 1;
		}
	}
	swap(array, sidx, right);
	return sidx;
}
function swap(array, idx, idx2){
	var temp = array[idx];
	array[idx] = array[idx2];
	array[idx2] = temp
}
function randInt(min, max) {
	return Math.floor(Math.random() * (max - min+1)) + min;
}