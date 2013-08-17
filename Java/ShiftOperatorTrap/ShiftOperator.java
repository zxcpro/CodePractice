public class ShiftOperator{
	public static void main(String[] args){
		//shift operator on char/short/byte may cause some error
		//at first,shift operator convert char/short/byte to int 
		short a = -1;
		System.out.println(a);           //short 16bit  1111 1111 1111 1111
		//before shift a is converted to int 32bit 1111 1111 1111 1111 1111 1111 1111 1111
		System.out.println(a>>>10);    //a>>>10 int 32bit 0000 0000 0011 1111 1111 1111 1111 1111 
		a >>>= 10;                     //assign to short,there will be trancated short 16bit
                //short 16bit 1111 1111 1111 1111
		System.out.println(a);        //still -1
	}
}
		
