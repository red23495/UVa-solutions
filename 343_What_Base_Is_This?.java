import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			String s1 = cin.next();
			String s2 = cin.next();
			char min1='0',min2='0';
			for(int i = 0; i < s1.length(); i++){
				if(s1.charAt(i) > min1) min1 = s1.charAt(i);
			}
			for(int i = 0; i < s2.length(); i++){
				if(s2.charAt(i) > min2) min2 = s2.charAt(i);
			}
			if(min1 == '0' && min2 == '0') {
				System.out.println("0 (base 2) = 0 (base 2)");
				continue;
			}
			else if(min1 == '0' || min2 == '0'){
				System.out.println(s1 + " is not equal to " + s2 + " in any base 2..36");
				continue;
			}
			int ansbase1  = 0, ansbase2 = 0;
			int base1,base2;
			if(min1 > '9') base1 = (min1-'A')+11;
			else base1 = (min1-'0')+1;
			if(min2 > '9') base2 = (min2-'A')+11;
			else base2 = (min2-'0')+1;
			for(int i = base1; i <= 36 && ansbase1 == 0; i++){
				BigInteger n1 = new BigInteger(s1,i);
				for(int j = base2; j <= 36; j++){
					BigInteger n2 = new BigInteger(s2,j);
					if(n1.toString().compareTo(n2.toString()) == 0){
						ansbase1 = i; ansbase2 = j;
						break;
					}
				}
			}
			if(ansbase1 != 0)System.out.println(s1 + " (base "+ ansbase1 +") = "+ s2 +" (base "+ ansbase2 +")");
			else System.out.println(s1 + " is not equal to "+ s2 +" in any base 2..36");
		}
	}
}
