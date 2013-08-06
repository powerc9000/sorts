function mergesort(array){
	if(array.length <=1) return array;
	var left =[],
		right = [];
	var middle = (array.length/2) | 0;
	var i;

	for(i=0; i<array.length; i++){
		if(i<middle){
			left.push(array[i]);
		}
		else{
			right.push(array[i]);
		}
	}

	left = mergesort(left);
	right = mergesort(right);

	return merge(left, right);
}

function merge(left, right){
	var result = [];
	while( left.length > 0 || right.length > 0){
		if(left.length >0 && right.length >0){
			if(left[0] <= right[0]){
				result.push(left[0]);
				left = left.slice(1);
			}
			else{
				result.push(right[0]);
				right = right.slice(1);
			}
		}
		else if(left.length > 0){
			result.push(left[0]);
			left = left.slice(1);
		}
		else if(right.length > 0){
			result.push(right[0]);
			right = right.slice(1);
		}
	}
	return result;
}