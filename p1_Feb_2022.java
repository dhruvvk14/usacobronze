//by Dhruv Kothari
import java.util.*; import java.io.*;
public class p1_Feb_2022 {
	static void solve(int array[], int sum) {
		int n = array.length;
		//the logic here is to check if the entire sum % numbers == 0
		for(int p = n; p >= 1; p--) {
			if(sum % p != 0) {
				// impossible to part it into that many partitions as it won't be integer
				continue;
			}
			boolean possible = true;
			// how can we check if it works?
			/* We must check a few of the following
			 * 
			 * 
			 */
			int curSum = 0;
			for(int i = 0; i < n; i++) {
				curSum += array[i];
				if(curSum > sum / p) {
					possible = false;
					break;
				}
				else if(curSum == sum/p) {
					// now we have to make cur sum == 0, as we need to check for another valid group
					curSum = 0;
				}
			}
			if(possible) {
				System.out.println(p);
				return;
			}
		}
	}
	public static void main(String [] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t > 0) {
			t--;
			int n = scan.nextInt();
			int array[] = new int[n];
			int sum = 0;
			for(int i = 0; i < n; i++) {
				array[i] = scan.nextInt();
				sum += array[i];
			}
			//solve in method
			solve(array, sum);
		}
	}
}