import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Vector;
import java.lang.StringBuilder;
class Main{
	public static void main(String[] args){
		try{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder t = new StringBuilder();
		String s;
		while((s = br.readLine()) != null) {t.append(s);t.append(" ");}
		s = t.toString();
		StringTokenizer st = new StringTokenizer(s);
		while(st.hasMoreTokens()){
			String temp;
			Vector<BigInteger> v = new Vector<BigInteger>();
			Vector<Integer> zero = new Vector<Integer>();
			BigInteger last = new BigInteger("1");
			int le = -1;
			while(true){
				temp = st.nextToken();
				//System.out.println(temp);
				if(Integer.parseInt(temp) == -999999) break;
				if(Integer.parseInt(temp) == 0){
					v.addElement(new BigInteger("0"));
					le = zero.size();
					zero.addElement(le);
				}
				else{
					last = last.multiply(new BigInteger(temp));
					v.addElement(last);
					zero.addElement(le);
				}
			}
			//for(int i = 0; i < zero.size(); i++) System.out.println(v.elementAt(i));
			BigInteger ans = new BigInteger("-99999");
			for(int i = 0; i < v.size(); i++){
				for(int j = i; j < v.size(); j++){
					BigInteger x = v.elementAt(j);
					if(zero.elementAt(j)>=i) x = BigInteger.valueOf(0);
					else if(i > 0){
						int a;
						for(a = i - 1;a >= 0 && v.elementAt(a).compareTo(BigInteger.valueOf(0)) == 0 ; a--);
						//System.out.println(a);
						if(a >= 0)x = v.elementAt(j).divide(v.elementAt(a));
					}
					//System.out.println(i+" "+j+" "+x);
					if(ans.compareTo(x) < 0) ans = x;
				}
			}
			System.out.println(ans);
		}
		}catch(Exception e){}	
	}
}
