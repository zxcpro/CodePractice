import java.util.*;


public class Consumer implements Runnable{
	private Pool pool;
	Random ran = new Random();
	public Consumer(Pool otherPool){
		pool = otherPool;
	}

	public void run(){
		while(true){
			int randConsume = 3;
			pool.consume(randConsume);

			//wait for a while to reconsume
			try{
				Thread.sleep(200);
			}catch(Exception e){

			}
		}
		
	}

}