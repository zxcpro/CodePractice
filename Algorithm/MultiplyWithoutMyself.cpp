#include <cstdlib>
#include <iostream>

using namespace std;

//there is an array  A[n] here
//your task is to generate another array B[] its lement B[i] is   A[0]*A[1]* ....*A[i-1]*A[i+1]*....  A[n] ,but you can't use divide
//the time complexity  if limited to O(n)


//since  the  new    num[i]     is      a[0] * a[1] *...*a[i-1]       *        a[i+1]  * a[i+2] * ....* a[n]
//so first round  we  calculate the left part from left to right
//then second round we caculate the right part from right to left
void mutiWithoutMe(int* array,int size){
	int newArray[size] ;
	newArray[0] = 1;
	for (int i = 1; i < size; ++i){
		newArray[i] = newArray[i-1] * array[i-1];
	}
	int tmp = array[size - 1];
	for (int i = size - 2; i >= 0; --i){
		newArray[i] *= tmp;
		tmp *= array[i];
	}
	for (int i = 0; i < size; ++i)	{
		cout<<newArray[i]<<" ";
	}
}

int main(){

int a[] = {2,3,4,5,6};
int size = sizeof(a)/sizeof(int);
mutiWithoutMe(a,size);


}