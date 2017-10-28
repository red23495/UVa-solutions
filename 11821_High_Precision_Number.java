import java.util.*;
import java.io.StringReader;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int test = cin.nextInt();
		while((test--) != 0){
			BigDecimal sum = new BigDecimal("0");
			while(true){
				BigDecimal n = cin.nextBigDecimal();
				if(n.toString().equals("0")) break;
				sum = sum.add(n);
			}
			System.out.println(sum.stripTrailingZeros().toPlainString());
		}
	}
}
