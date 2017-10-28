import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			BigInteger p = new BigInteger(cin.next());
			if(p.toString() == "0") break;
			BigInteger a = new BigInteger(cin.next());
			if(p.isProbablePrime(10)){
				System.out.println("no");
				continue;
			}
			BigInteger lhs = a.modPow(p, p);
			BigInteger rhs = a.mod(p);
			if(lhs.toString().equals(rhs.toString())){
				System.out.println("yes");
			}
			else{
				System.out.println("no");
			}
		}
	}
}
