import java.util.*;
import java.io.StringReader;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger[] cat = new BigInteger[301];
		BigInteger[] fact = new BigInteger[301];
		fact[0] = BigInteger.ONE;
		cat[0] = BigInteger.ONE;
		for(int i = 1; i <= 300; i++){			
			cat[i] = cat[i-1].multiply(new BigInteger(Integer.toString(4*i*i - 2*i)));
			cat[i] = cat[i].divide(new BigInteger(Integer.toString(i*i+i)));
			fact[i] = fact[i-1].multiply(new BigInteger(Integer.toString(i)));
		}
		while(true){
			int n = cin.nextInt();
			if(n == 0) return;
			System.out.println(cat[n].multiply(fact[n]));
		}
	}
}
