import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int test = cin.nextInt();
		cin.useDelimiter("(\\s*/\\s*|\\s*\n)");
		while((test--) != 0){
			cin.skip("\\s*");
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			BigInteger gcd = a.gcd(b);
			//System.out.println(a.toString() + " " + b.toString() + " " + gcd.toString());
			System.out.println(a.divide(gcd).toString() + " / " + b.divide(gcd).toString());
		}
	}
}
