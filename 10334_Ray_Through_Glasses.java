import java.util.*;
import java.io.StringReader;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main {
	
	public BigInteger[] fibos;
	
	private BigInteger fibo(int n){
		if(fibos[n] != null) return fibos[n];
		return fibos[n] = fibo(n-1).add(fibo(n-2));
	}
	
	public Main(){
		fibos = new BigInteger[1001];
		fibos[0] = new BigInteger("1");
		fibos[1] = new BigInteger("2");
		fibo(1000);
	}
	public static void main(String args[]){
		Main obj = new Main();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n = cin.nextInt();
			System.out.println(obj.fibos[n]);
		}
	}
}
