class Item{
	public Item(String s){
		System.out.println(s+" item constructed");
	}
}


class A{
	Item aItem = new Item("A");
	static{
		System.out.println("Class A static part loaded!");
	}
	public A(){
		System.out.println("A constructed!");
	}

}



class B extends A{
	Item bItem = new Item("B");
	static{
		System.out.println("Class B static part loaded!");
	}
	public B(){
		System.out.println("B constructed!");
	}

}

class C extends B{
	Item cItem = new Item("C");
	static{
		System.out.println("Class C static part loaded!");
	}
	public C(){
		System.out.println("C constructed!");
	}
}

public class LoadSequence{
	
	public static void main(String[] args){
		C c1 = new C();
		C c2 = new C();
		/*
		result is:
		Class A static part loaded!
		Class B static part loaded!
		Class C static part loaded!
		A item constructed
		A constructed!
		B item constructed
		B constructed!
		C item constructed
		C constructed!
		A item constructed
		A constructed!
		B item constructed
		B constructed!
		C item constructed
		C constructed!
		*/
	}

}

