import java.math.BigInteger;
import java.util.Scanner;

/**
 * 
 * SPOJ ...Canton series implementation
 * @author Sunny
 *
 */

public class CANTON {

	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		
		try{
			int t = sc.nextInt();
			while(t>0){
				BigInteger n = new BigInteger(sc.next());
				findElement(n);
				t--;
			}
		}catch(Exception e){
			System.err.println(e.getMessage());
			return;
		}
	}

	private static void findElement(BigInteger n) {
		// TODO Auto-generated method stub
		BigInteger sum = new BigInteger("0");
		int row=0;
		while(n.intValue() > sum.intValue()) {
			sum = sum.add(new BigInteger(""+(row+1)));
			row++;
		}
		
		int den=0,num=0;
		int element_id = sum.intValue()-n.intValue()+1;
		if(row%2 == 0){
			den = element_id;
			num = row-element_id+1;
		}else{
			num = element_id;
			den = row-element_id+1;
		}
	
		System.out.println("TERM " + n.intValue() + " IS " + num + "/" + den);
	}
}
