function quicksort(array){
	
	if(array.length <= 1) return array;

	var pivot, greater, lesser, pVal;
	greater = [];
    lesser = [];
	pivot = randInt(0, array.length-1);
	pVal = array[pivot];
	array = array.slice(0, pivot).concat(array.slice(pivot+1))
	for(var i=0; i<array.length; i++){
		if(array[i] < pVal){
			lesser.push(array[i]);
		}
		else{
			greater.push(array[i])
		}
	}
	return (quicksort(lesser)).concat([pVal], quicksort(greater));
}

function randInt(min, max) {
	return Math.floor(Math.random() * (max - min+1)) + min;
}