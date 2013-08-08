
import java.util.*;


public class Producer implements Runnable{
	private Pool pool;
	Random ran = new Random();

	Producer(Pool somePool){
		pool = somePool;
	}

	public void run(){
		while(true){
			int randProduce = 1;// set to one at first
			pool.produce(randProduce);

			//wait for a while to reproduce
			try{
				Thread.sleep(200);
			}catch(Exception e){

			}		
		}

	}


}