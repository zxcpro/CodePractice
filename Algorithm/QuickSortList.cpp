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






Node* partition(Node* head,Node* end,Node** newHead,Node** newTail){
	Node* privot = end;
	Node* tail = privot;
	Node* pre = NULL;
	Node* tmp = head;
	while(tmp != privot){
		if ( tmp->value < privot->value ){
			if ( pre == NULL){//the current first node of the list is not needed to swap ,  e.g   2  6  3  4      or    8 1 6 4(after one swap it becomes 1 6 4 8)
				*newHead = tmp;
			}
			pre = tmp;
			tmp = tmp->pNext;
		}else{
			Node* nextTmp = tmp->pNext;
			tmp->pNext = NULL;
			tail->pNext = tmp;
			tail = tmp;
			if ( pre == NULL ){
				*newHead = nextTmp;
			}else{
				pre->pNext = nextTmp;
			}
			tmp = nextTmp;
		}
	}
	*newTail = tail;
	return privot;
}





Node* quickSortListRecur(Node* head,Node* tail){
	if (head == tail){
		return head;
	}
	Node* newHead = NULL;
	Node* newTail = NULL;
	Node* privot = partition(head,tail,&newHead,&newTail);
	if (newHead != privot){
		Node* prePrivot = newHead;
		while(prePrivot->pNext != privot){
			prePrivot = prePrivot->pNext;
		}
		prePrivot->pNext = NULL; //set the end of the first part to NULL,so that we can deal with it like a isolate list
		newHead = quickSortListRecur(newHead,prePrivot);
		Node* lastNode = newHead;
		while(lastNode->pNext != NULL){
			lastNode = lastNode->pNext;
		}
		lastNode->pNext = privot; //link it to privot after sort the first part
	}
	if (newTail != privot){
		privot->pNext = quickSortListRecur(privot->pNext,newTail);
	}
	return newHead;
}






Node* quickSortList(Node* head){
	Node* tail = head;
	while(tail->pNext){
		tail = tail->pNext;
	}
	Node* newHead = quickSortListRecur(head,tail);
	return newHead;
}











int main(){
Node* a = new Node(8);
Node* b = new Node(3);
Node* c = new Node(6);
Node* d = new Node(4);
Node* e = new Node(1);
a->pNext = b;
b->pNext = c;
c->pNext = d;
d->pNext = e;


Node* newHead = quickSortList(a);
while(newHead){
	cout<<newHead->value<<" ";
	newHead = newHead->pNext;
}

}