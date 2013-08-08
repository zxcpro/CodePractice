
import java.util.*;


public class Pool{
	public static final int MAX_NUM = 10;
	public final int INIT_NUM = 3;
	private ArrayList<Item> list = new ArrayList<Item>();
	public Pool(){
			for(int i = 0;i < INIT_NUM;i++){
			list.add(new Item());
			}
	}


	public void produce(int num){
		try{
			synchronized(list){
				while(list.size() + num > MAX_NUM ){
					wait();
				}
				//produce items here
				for(int i=0;i<num;i++){
					Item item = new Item();
					list.add(item);
					System.out.println("producing "+item.toString());
				}
				System.out.println(num+" items produced");
				list.notifyAll();
			}			
		}catch(Exception e){
				
		}
	}


	public void consume(int num){
		try{
			synchronized(list){
				while(list.size() < num){
					wait();
				}
				//consume the items here
				for(int i=0;i<num;i++){
					System.out.println("consuming "+list.get(0).toString());
					list.remove(0);					
				}
				System.out.println(num+" items consumed");
				list.notifyAll();
			}

		}catch(Exception e){

		}
	}


	public ArrayList<Item> getList(){
		return list;
	}

}