import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextInt()){
			int N,A;
			N = cin.nextInt();
			A = cin.nextInt();
			BigInteger expo = new BigInteger("1");
			BigInteger res = new BigInteger("0");
			BigInteger bigA = new BigInteger(new Integer(A).toString());
			for(int i = 1; i <= N; i++){
				expo = expo.multiply(bigA);
				BigInteger bigI = new BigInteger(new Integer(i).toString());
				bigI = bigI.multiply(expo);
				res = res.add(bigI);
			}
			System.out.println(res.toString());
		}
	}
}
