import java.util.*;
import java.io.StringReader;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main {
	
	public BigInteger[][] memo;
	
	public BigInteger nCk(int n, int k){
		if(n == k || k == 0) return memo[n][k] = new BigInteger("1");
		if(memo[n][k] != null) return memo[n][k];
		return memo[n][k] = nCk(n-1,k-1).add(nCk(n-1,k));
	}
	
	public static void main(String args[]){
		Main obj = new Main();
		obj.memo = new BigInteger[210][110];
		Scanner cin = new Scanner(System.in);
		int test = cin.nextInt();
		while(test-- != 0){
			int total = cin.nextInt();
			int num = cin.nextInt();
			int black = 0;
			int k = num;
			while(num-- != 0){
				black += cin.nextInt();
			}
			int white = total - black + 1;
			if(white < k){
				System.out.println("0");
				continue;
			}
			System.out.println(obj.nCk(white,k));
		}
	}
}
