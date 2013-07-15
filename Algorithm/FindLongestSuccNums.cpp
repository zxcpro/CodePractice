#include <iostream>
#include <map>
#include <bitset>


#define INT_BITS sizeof(int)
#define MASK 0x1f
#define SHIFT 5

using namespace std;

//15,7,9,14,11,8,13,12

//Solution One: Using  Disjoint Sets
struct DisjointSets
{
	int* father;
	int* source;
	int size;
	DisjointSets(int* array,int length){
		source = array;
		size = length;
		father = new int[size];
		make_set();
	}
	void make_set();
	int find_set(int index);
	void union_set(int index1,int index2);
};

void DisjointSets::make_set(){
	for (int i = 0; i < size; ++i){
		father[i] = i;
	}
}



int DisjointSets::find_set(int index){     //get its ancester's index  and compress the path
	/* Nomal Edition
	int fatherIndex = index;
	while (fatherIndex != father[fatherIndex]){
		fatherIndex = father[index];
		index = fatherIndex;
	}
	return fatherIndex;
	*/

	//using the recursion version
	//compress the path while recalling back
	if (index == father[index])	{
		return index;
	}
	father[index] = find_set(father[index]);//it assigns their father index to their ancestor to compress the path when next finding ancestor
	return father[index];
}



void DisjointSets::union_set(int index1,int index2){
	int fatherOfIndex1 = find_set(index1);
	int fatherOfIndex2 = find_set(index2);
	if (fatherOfIndex1 != fatherOfIndex2){ // if they are not in the same set,union them
		if (source[fatherOfIndex1] > source[fatherOfIndex2]){
			father[fatherOfIndex2] = fatherOfIndex1;
		}else{
			father[fatherOfIndex1] = fatherOfIndex2;
		}
	}
}


void FindLogestSuccNumSolution1(int* array,int size){
	DisjointSets* dij = new DisjointSets(array,size);
	 //using a map to store the value-index relationship
	map<int, int> valueIndex; 
	for (int i = 0; i < size; ++i)
		valueIndex.insert(make_pair(array[i],i));
	for (int i = 0; i < size; ++i){     //iterate the array,union value+1,value-1 if exists
		if (valueIndex.count(array[i]-1)){
			int preIndex = preIndex = valueIndex.find(array[i]-1)->second; //combine the value-1  location if exists
			dij->union_set(i,preIndex);
		}
		if (valueIndex.count(array[i]+1)){
			int postIndex = postIndex = valueIndex.find(array[i]+1)->second; //combine the value+1 location if exists
			dij->union_set(i,postIndex);
		}
	}
	//father array now  :   [0,2,2,0,0,2,0,0]
	//you have to find which root has most children  then sort them and ouput
	//complex answer
}



//Solution 2:
//if the nums are whthin a range
//use a bitmap , each bit represents if the num  that equals to the bit index    exists in the array

//since bitset in stl doesn't support dynamic allocation, I'll implement a simple bitset myself
struct Bitset
{
	//#define INT_BITS sizeof(int)
	//#define MASK 0x1f              31       an integer occupy 4 bytes  = 32 bit   so the bit index ranges from 0 to 31
	//#define SHIFT 5        2^5 = 32
	int* bits;
	int len;
	Bitset(int length){
		len = length;
		int intNums = length/INT_BITS + 1;
		bits = new int[intNums]();
	}
	void set(int index);
	bool test(int index);
};
void Bitset::set(int index){
	//index >> SHIFT     means   the index  of the integer which includes the bit you want to set
	// index & MASK     equals  to         index % MASK             find out which bit in this integer you want to set
	bits[index >> SHIFT]  |= 1 << (index & MASK); 
}

bool Bitset::test(int index){
	return  bits[index >> SHIFT] & 1 << (index & MASK);
}

void FindLogestSuccNumSolution2(int* array,int size){
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < size; ++i){
		if (array[i] > max){
			max = array[i];
		}
		if (array[i] < min){
			min = array[i];
		}
	}
	int length = max - min + 1;
	Bitset* existsSet = new Bitset(length);
	for (int i = 0; i < size; ++i){
		existsSet->set(array[i] - min);
	}
	int startIndex = 0;
	int succ = 0;
	int finalSucStartIndex = 0;
	int maxSucc = 0;
	for (int i = 0; i < length; ++i){
		if (existsSet->test(i))	{
			succ++;
			if (succ > maxSucc){
				maxSucc = succ;
				finalSucStartIndex = startIndex;
			}
		}else{
			startIndex = i+1;
			succ = 0;
		}
	}
	for (int i = 0; i < maxSucc; ++i){
		int res = min + finalSucStartIndex + i;
		cout<<res<<" ";
	}

}






//Solution 3:
//if the range of nums is wide, solution2 may take too much room
//however,we can use a map<int,int> to achrive the same goal
//the key of map stores the start num
//the value of map stores how many nums below is still successive
void FindLogestSuccNumSolution3(int* array,int size){
	map<int,int> valueSuccMap;
	map<int,int>::iterator it;
	for (int i = 0; i < size; ++i){
		int curVal = array[i];
		it = valueSuccMap.find(curVal + 1);
		int succNum = 0;
		if (  it != valueSuccMap.end() ){           //when iterating a num, first check if its value+1 element exists,  if exists ,  one more successive num, the counter add one 
			succNum = it->second + 1;
		}else{
			succNum = 1;
		}
		valueSuccMap.insert(make_pair(curVal,succNum));

		//keep looking for the nums smaller then current val, change their succ num until it breaks
		int tmpVal = curVal;
		int tmpSucc = succNum;
		while(       (it = valueSuccMap.find(tmpVal - 1))  != valueSuccMap.end()       ){
			it->second = tmpSucc + 1;
			tmpSucc = it->second;
			tmpVal -= 1;
		}
	}
	//find out whose value in the map is the biggest
	int startNum ;
	int succNum = 0;
	for(it = valueSuccMap.begin();it != valueSuccMap.end();it++){
		if(it->second > succNum){
			succNum = it->second;
			startNum = it->first;
		}
	}
	for (int i = 0; i < succNum; ++i){
		cout<<startNum+i<<" ";
	}

}



int main(){
int source[] = {15,7,9,14,11,8,13,12};
int size = sizeof(source)/sizeof(int);
//Solution One
//FindLogestSuccNumSolution1(source,size);
//Solution Two
//FindLogestSuccNumSolution2(source,size);
//Solution Thress
FindLogestSuccNumSolution3(source,size);
}