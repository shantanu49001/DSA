//hash find krne k liye O(l)-->lemgth of string
//always each box me n/b entries hoti hai 
//practically ek hi box me saare nhi jate
//seaching me max-> O(n/b)   =Load factor boxes me n ebtry daal di
//we ensure n/b<0.7
//120 values aa rhi hai to we ensure 127 boxes 
//so we assume O(1)->very less list element ina box
//whenevr boxes kam pagenge we will double the array size
//load factor wapas se 0.7 se less ho ayegi
//Rehsing
//<--- previous code me jao

