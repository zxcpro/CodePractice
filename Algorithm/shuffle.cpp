#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

//shuffle     algorithm

//Solution 1
//fisher_yates  shuffle
//which  can  ensure  the  possibility that a num  occurs in a position  equal
void shuffle_fisher_yates(int* array,int size){
	for(    int i = size - 1;   i > 0;      --i){
		int j = rand()%(i+1);      //caution:    % (i+1)       which  means   swap  is likely  not to happen     (  when  j == i   ) 
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}


int main(){

int pokers[] = {1,2,3,4,5,6,7,8,9};
int size = sizeof(pokers)/sizeof(int);

shuffle_fisher_yates(pokers,size);

for (int i = 0; i < size; ++i){
	cout<<pokers[i]<<" ";
}

}