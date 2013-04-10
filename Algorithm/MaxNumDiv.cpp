#include <iostream>
using namespace std;

void findMax(int* array,int left,int right,int& max){
if (left == right){
	max = array[left];
	return;
}else if (right - left == 1){
	max = array[left] > array[right] ? array[left] : array[right];
	return;
}


int leftMax = 0;
int rightMax = 0;
findMax(array,left,(left+right)/2,leftMax);
findMax(array,(left+right)/2+1,right,rightMax);
max = leftMax > rightMax?leftMax : rightMax;
}




int main(){
int nums[] = {4,8,2,7,1,3,9,6,1,13,0,18,1,3,5};
int nums1[] = {4,8,2,7,21,1,3,9,6,1,13,0,18,1,3,5};

int max = 0;
int len = sizeof(nums)/sizeof(int);
findMax(nums,0,len-1,max);
cout<<max<<endl;
findMax(nums1,0,len-1,max);
cout<<max<<endl;

}