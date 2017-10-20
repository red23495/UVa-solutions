import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			String s = cin.next();
			int b1 = cin.nextInt();
			int b2 = cin.nextInt();
			BigInteger n = new BigInteger(s,b1);
			int a = Integer.parseInt(n.toString());
			String ans = Integer.toString(a,b2);
			ans = ans.toUpperCase();
			if(ans.length() > 7) {
				System.out.println("  ERROR");
				continue;
			}
			System.out.printf("%7s\n",ans);
		}
	}
}
