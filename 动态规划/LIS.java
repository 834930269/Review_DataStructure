//O(n^2)
import java.util.*;
public class LIS {
	private static int[] c=new int[100000+1];
	private static int[] dp=new int[100000+1];
	public static void main(String[] args){
		int n;
		Scanner cin=new Scanner(System.in);
		n=cin.nextInt();
		for(int i=0;i<n;++i){
			c[i]=cin.nextInt();
		}
		/*
		 * dp[j]: 以c[j]为结尾从0...i的LIS 
		 */
		for(int i=1;i<n;++i){
			for(int j=0;j<i;++j){
				if(c[i]>=c[j]){
					dp[i]=Math.max(dp[i],dp[j]+1);
				}
			}
		}
		System.out.println(dp[n-1]+1);
	}
}
