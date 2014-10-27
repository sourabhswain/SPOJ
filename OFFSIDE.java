import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Offisde..Just need to check with the second player in the array..
 * @author Sunny
 *
 */
public class OFFSIDE {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		while(true){
			StringTokenizer tokenizer = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(tokenizer.nextToken());
			int d = Integer.parseInt(tokenizer.nextToken());
			
			if(a==0 && d==0) break;
			int i=0;
			int attack[] = new int[a];
			int defend[] = new int[d];
			
			tokenizer = new StringTokenizer(in.readLine());
			for(i=0; i<a; i++){
				attack[i] = Integer.parseInt(tokenizer.nextToken());
			}
		
			tokenizer = new StringTokenizer(in.readLine());
			for(i=0;i<d;i++){
				defend[i] = Integer.parseInt(tokenizer.nextToken());
			}
		
			Arrays.sort(attack);
			Arrays.sort(defend);
			
			if(attack[0] >= defend[1]){
				System.out.println("N\n");
			}else{
				System.out.println("Y\n");
			}
		}
		System.out.flush();
	}

}
