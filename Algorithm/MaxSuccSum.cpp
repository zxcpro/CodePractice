#include <iostream>
using namespace std;

int MaxSuccSum(int* array,int len){
int maxSum = 0;
int curSum = 0;
//if you want to know where to start and end
int start = 0;
int end = 0;
	for (int i = 0; i < len; ++i){
		if (curSum < 0){
			curSum = 0;
			//reset start and end
			start = i;
			end = i;
		}
		curSum += array[i];
		if (curSum > maxSum){
			maxSum = curSum;
			end = i;
		}
	}
	//output the nums
	cout<<"the nums are:";
	for (int i = start; i <= end; ++i){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	//return the max sum
	return maxSum;
}




int main(){
int array[] = {1,5,-7,-3,2,1,-4,8,2,-6,7};
int len = sizeof(array)/sizeof(int);
cout<<MaxSuccSum(array,len)<<endl;

}