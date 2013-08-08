public class Item{
	private static int itemCount = 0;
	private final int id = itemCount++;
	public String toString(){
		return "the "+id+" item";
	}
}