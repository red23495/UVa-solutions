import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int base;
		while(true){
			base=cin.nextInt();
			if(base == 0) break;
			BigInteger b = new BigInteger(cin.next(),base);
			BigInteger m = new BigInteger(cin.next(),base);
			b = b.mod(m);
			System.out.println(Integer.toString(Integer.parseInt(b.toString()), base));
		}
	}
}
