import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(true){
			String s = cin.next();
			if(s.equals("0")) break;
			BigInteger n = new BigInteger(s);
			n = n.mod(new BigInteger("17"));
			if(n.toString() == "0") System.out.println("1");
			else System.out.println("0");
		}
	}
}
