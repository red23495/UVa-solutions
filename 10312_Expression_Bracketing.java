import java.util.*;
import java.io.StringReader;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger[] cat = new BigInteger[27];
		BigInteger[] sup_cat = new BigInteger[27];
		cat[0] = BigInteger.ONE;
		for(int i = 1; i <= 26; i++){			
			cat[i] = cat[i-1].multiply(new BigInteger(Integer.toString(4*i*i - 2*i)));
			cat[i] = cat[i].divide(new BigInteger(Integer.toString(i*i+i)));
		}
		sup_cat[1] = BigInteger.ONE;
		sup_cat[2] = BigInteger.ONE;
		for(int i = 3; i <= 26; i++){
			int a1 = 3*(2*i - 3);
			int a2 = (i - 3);
			sup_cat[i] = sup_cat[i-1].multiply(new BigInteger(Integer.toString(a1))).subtract(new BigInteger(Integer.toString(a2)).multiply(sup_cat[i-2])).divide(new BigInteger(Integer.toString(i)));			
		}
		while(cin.hasNextInt()){
			int n = cin.nextInt();
			//System.out.println(sup_cat[n]);
			System.out.println(sup_cat[n].subtract(cat[n-1]));
		}
	}
}
