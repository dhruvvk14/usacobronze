import java.util.*; import java.io.*;
public class p3 {
	static class block{
		boolean charCount[] =  new boolean[26];
		String block ;
	}
	
	public static void main(String [] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		block b[] = new block[4];
		for(int i = 0; i < 4; i++) {
			b[i] = new block();
			b[i].block = scan.next();
			for(int l = 0; l < b[i].block.length(); l++) {
				char c = b[i].block.charAt(l);
				int a = c;
				b[i].charCount[a - 65] = true;
			}
		}
		while(t > 0) {
			t--;
			String word = scan.next();
			int n = word.length();
			boolean visited[] = new boolean[word.length()];
			for(block block: b) {
				boolean nextBlock = false;
				for(int i = 0; i < n; i++) {
					char c = word.charAt(i);
					int a = c;
					if(block.charCount[a - 65] && !visited[i]){
						// now we make it visited
						//System.out.println(i + " " + block.block);
						visited[i] = true;
						nextBlock = true;
						break;
					}
					if(nextBlock) {
						break;
					}
				}
				if(nextBlock) {
					continue;
				}
			}
			boolean yes = true;
			for(int i = 0; i < n; i++) {
				if(!visited[i]) {
					yes = false;
					break;
				}
			}
			if(yes) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}
	static boolean solve(block b[], String word){
		int n = word.length();
		boolean visited[] = new boolean[word.length()];
		for(block block: b) {
			boolean nextBlock = false;
			for(int i = 0; i < n; i++) {
				char c = word.charAt(i);
				int a = c;
				if(block.charCount[a - 65] && !visited[i]){
					// now we make it visited
					//System.out.println(i + " " + block.block);
					visited[i] = true;
					nextBlock = true;
					break;
				}
				if(nextBlock) {
					break;
				}
			}
			if(nextBlock) {
				continue;
			}
		}
		boolean yes = true;
		for(int i = 0; i < n; i++) {
			if(!visited[i]) {
				yes = false;
				break;
			}
		}
		return yes;
	}
}
