#include <cstdlib>
#include <iostream>
using namespace std;




struct Node
{
	int value;
	Node* pNext;
	Node(int val){
		value = val;
		pNext = NULL;
	}
};




Node* makeList(int* array,int size){
	Node* tmp = NULL;
	Node* next = NULL;
	Node* head = NULL;
     for (int i = 0; i < size; ++i){
     	if (head == NULL){
     		tmp = new Node(array[i]);
     		head = tmp;
     	}else{
     		next = new Node(array[i]);
     		tmp->pNext = next;
     		tmp = next;
     	}
     	
     }
     return head;

}


//two lists, every node has a value of 0~9 , so one list represents a num
//add two lists,and return a list represents their sum
//the list   1->4->9->5->6->3->2  represents for 1495632
//           7->2->3->8->9->1->5
//           8->7->3->4->5->4->7 


Node* addListsRecurReal(Node* head1,Node* head2,bool& carry){
	if (head1->pNext == NULL || head2->pNext == NULL){
		int sum = head1->value + head2->value;
		if (sum < 10){
			carry = false;
			return new Node(sum);
		}else{
			carry = true;
			return new Node(sum%10);
		}
	}

	int sum = head1->value + head2->value; 
	Node* next = addListsRecurReal(head1->pNext,head2->pNext,carry);
	Node* newNode;
	if (carry){
		sum += 1;
	}
	if (sum < 10){
		newNode = new Node(sum);
		carry = false;
	}else{
		newNode = new Node(sum%10);
		carry = true;
	}
	newNode->pNext = next;
	return newNode;
}

Node* addListsRecur(Node* head1,Node* head2){
	bool carry = false;
	Node* head = addListsRecurReal(head1,head2,carry);
	if (carry){
		Node* realHead = new Node(1);
		realHead->pNext = head;
		return realHead;
	}
	return head;

}








//8  3  5  8  2  1
//1  6  4  1  9  2

Node* addListsNonRecur(Node* head1,Node* head2){
	Node* head = NULL;
	Node* cur = NULL;
	Node* last = NULL;
	//if carry happens,iterate from pre to cur
	Node* pre = NULL;

	//process the first nodes of two lists alone
	int sum = head1->value + head2->value;
	if (sum < 9){
		cur = new Node(sum);
		head = cur;
		pre = cur;
		last = cur;
	}else{
		int num = sum%10;
		cur = new Node(num);
		Node* headNode;
		//build a new node as the head node
		if (num != 9){
			headNode = new Node(1);
			pre = cur;
		}else{
			//the zero node is fit for being the first pre node,so when the first bit is 9 and carry happens,it will be convinient to add 1
			//remember if no carry happens,the zero head node should be eliminated.
			headNode = new Node(0);
			pre = headNode;
		}
		headNode->pNext = cur;
		head = headNode;
		last = cur;
	}


	//loop the other nodes
	Node* tmp1 = head1->pNext;
	Node* tmp2 = head2->pNext;
	while(tmp1 != NULL && tmp2 != NULL){
		sum = tmp1->value + tmp2->value;
		//if sum < 10, build a new node and connect it
		if (sum < 10){
			cur = new Node(sum);
			last->pNext = cur;
			last = cur;
			//if sum == 9, the pre node shouldn't be changed
			if (sum != 9){
				pre = cur;
			}
		}
		else{
			//if the sum of two nodes bigger than 10
			//build a new node with remainder and connect it
			cur = new Node(sum%10);
			last->pNext = cur;
			last = cur;
			//  1 9 9 9 9 3
			//for example 3 is the remainder,and now needs carry
			//  add pre node num: 1 to 2, then the num between pre and cur are assigned to 0
			pre->value += 1;
			Node* tmp = pre->pNext;
			while(tmp != cur){
				tmp->value = 0;
				tmp = tmp ->pNext;
			}
			//after the assign zero loop, the pre node should be cur node
			pre = cur;
		}
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}



	return head->value == 0 ? head->pNext : head;

}








int main(){
int arr1[] = {3,4,9,5,6,3,2};	
int arr2[] = {7,2,3,8,9,1,5};
int size = sizeof(arr1)/sizeof(int);
Node* head1 = makeList(arr1,size);
Node* head2 = makeList(arr2,size);


Node* newList = addListsNonRecur(head1,head2);
//Node* newList = addListsRecur(head1,head2);

while(newList != NULL){
	cout<<newList->value<<" ";
	newList = newList->pNext;
}



}