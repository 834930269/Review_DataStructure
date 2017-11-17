import java.util.*;
public class stlin {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int n,m,M;
        n=in.nextInt();
        m=in.nextInt();
        M=in.nextInt();
        solve(n,m,M);
    }
    public static void solve(int n,int m,int M){
        int[][] dp=new int[m+1][n+1]; 
        //递推式=>dp[i][j]=dp[i-1][j](ai=0时对应的是i-1划分)+dp[i][j-i]()
        dp[0][0]=1;
        for(int i=1;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-i])%M;
                }
            }
        }
        System.out.println(dp[m][n]);
    }
}