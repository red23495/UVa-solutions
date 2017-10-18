import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int test;
		test = sc.nextInt();
		sc.nextLine();
		for(int t = 1; t <= test; t++){
			String s1,s2;
			s1 = sc.next();
			s2 = sc.next();
			BigInteger num1, num2;
			StringBuilder s = new StringBuilder(s1);
			s.reverse();
			num1 = new BigInteger(s.toString());
			s = new StringBuilder(s2);
			s.reverse();
			num2 = new BigInteger(s.toString());
			num1 = num1.add(num2);
			s = new StringBuilder(num1.toString());
			num1 = new BigInteger(s.reverse().toString());
			System.out.println(num1.toString());
			//System.out.println(s.toString());
		}
	}
}
