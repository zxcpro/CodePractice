#include <cstdlib>
#include <time.h>
#include <iostream>


using namespace std;




//get   k  items   in    N    items ,  however   N  is  not  known  till the end
//whcih is a classic question called  Reservior Smpling


//a common sample based on this    is    asking you to get    k    nodes     in      a   list     while    you don't know how many nodes the list have


struct Node
{
	int value;
	Node* pNext;
	Node(int val):value(val),pNext(NULL){}
};

typedef Node* List;

int random(int start, int end){      //random   a  num   from     start(included)     to    end(not included)
	sleep(1);       //in order to set different seed
	srand(time(NULL));
	return   start + rand()%(end - start) ;
}


void pickKNodesInList( List   list ,int k ){
	int res[k];
	int i = 1;
	while(list != NULL){
		//at first  we    store   the  first   k  elements
		if (i <= k)	{
			res[i-1] = list->value;
		}else{
		//for each of the left elements,   there    is    k/i+1  possibility  to  select  this element  e.g.     10/100
		//if  it's  chosen ,  swap  it  with  one random element  that has been already picked
			int randNum = random(1,i+1);   //ranNum  ranges  from    1  to    i(included)        e.g.     1-100
			if (randNum <= k)	{        //e.g.      5 <= 10
				//swap  this num  with  random  one of  selected   ones 
				res[randNum-1] = list->value;
			}
		}
	i++;
	list = list->pNext;
	}
	for (int i = 0; i < k; ++i)	{
		cout<<res[i]<<" ";
	}
}


int main(){
Node* head = NULL;
Node* lastNode = NULL;
Node* curNode = NULL;
//generate and combile a list
for (int i = 0; i < 20; ++i){
	curNode = new Node(i);
	if (head == NULL){
		head = curNode;
	}

	if (lastNode != NULL){
	lastNode->pNext = curNode;
	}
	lastNode = curNode;
}

pickKNodesInList(head,10); 
}