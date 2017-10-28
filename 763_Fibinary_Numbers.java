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
	
	private BigInteger toFibBinary(String s){
		BigInteger ret = new BigInteger("0");
		for(int i = 0, j = s.length()-1; i < s.length(); i++,j-- ){
			if(s.charAt(j) == '1') ret = ret.add(fibos[i]);
		}
		return ret;
	}
	
	private BigInteger BigIntToFibBinary(BigInteger b){
		BigInteger ret = new BigInteger(b.toString());
		StringBuilder build = new StringBuilder();
		int len = 201;
		while(len >= 0){
			if(fibos[len].compareTo(ret) <= 0){
				build.append('1');
				ret = ret.subtract(fibos[len]);
			}else{
				build.append('0');
			}
			len--;
		}
		return new BigInteger(build.toString());
	}
	
	public static void main(String args[]){
		Main obj = new Main();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			BigInteger n1 = obj.toFibBinary(cin.next());
			BigInteger n2 = obj.toFibBinary(cin.next());
			System.out.println(obj.BigIntToFibBinary(n1.add(n2)).toString());
			if(cin.hasNext()) System.out.print('\n');
		}
	}
}
