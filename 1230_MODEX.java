import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int test = cin.nextInt();
		while((test--) != 0){
			BigInteger x = new BigInteger(cin.next());
			BigInteger y = new BigInteger(cin.next());
			BigInteger n = new BigInteger(cin.next());
			x = x.modPow(y, n);
			System.out.println(x.toString());
		}
	}
}
