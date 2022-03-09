import java.util.*; import java.io.*;
public class p3_Feb_2022 {
	static class block{
		boolean charCount[] =  new boolean[26];
		String block ;
	}
	static void swap(block b[], int i, int j){
		block temp = b[i];
		b[i] = b[j];
		b[j] = temp;
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
			boolean works = false;
			block b1[] = new block[4];
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					for(int a = 0; a < 4; a++) {
						for(int c = 0; c < 4; c++) {
							if(a == j || a == i || a== c || j == i || j == c || i == c) {
								continue;
							}
							for(int l = 0; l < 4; l++) {
								b1[l] = new block();
							}
							b1[i] = b[0];b1[j] = b[1];b1[a] = b[2]; b1[c] = b[3];
							works = solve(b1, word);
							if(works) {
								break;
							}
						}
						if(works) break;
					}
					if(works) break;
				}
				if(works) break;
			}
			if(works) System.out.println("YES");
			else System.out.println("NO");
			
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
