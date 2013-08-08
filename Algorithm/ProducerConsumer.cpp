
typedef int Semaphore;

Semaphore empty = 10;
Semaphore full = 0;
Semaphore mutex = 1;



//pseudo code of prducer-consumer question by using semaphore 
// P  means  minus one if possible, or block current thread
// V means  increase one if possible, or block current thread

void produce(){
	while(true){
		produce_item();
		P(empty);
		P(mutex);  //P(mutex) here and V(mutex) below means that only one of the produce procedure and consume procedure can be excuted at the same time
		put_item();
		V(mutex);
		V(full);
	}
}



void consume(){
	while(true){
		P(full);
		P(mutex);
		consume_item();
		V(mutex);
		V(empty);
	}
}

void consume(){

}




int main(){






}







