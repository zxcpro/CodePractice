


import java.util.*;

public class ThreadTest{



	public static void main(String[] args){
		System.out.print("123");
		Pool pool = new Pool();
		Producer producer1 = new Producer(pool);
		Producer producer2 = new Producer(pool);
		Consumer consumer = new Consumer(pool);
		new Thread(producer1).start();
		new Thread(producer2).start();
		new Thread(consumer).start();
	}




}



