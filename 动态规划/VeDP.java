import java.util.*;
//矩阵链乘
//11-17
public class VeDP {
    public static final int MAXN=100;
    public static final int INF=0x3f3f3f3f;
    static int[] p=new int[MAXN+1];
    static int[][] m=new int[MAXN+1][MAXN+1];
    public static void main(String args[]){
        Scanner cin=new Scanner(System.in);
        int n;
        n=cin.nextInt();
        for(int i=1;i<=n;++i){//因为中间肯定相同
            p[i-1]=cin.nextInt();
            p[i]=cin.nextInt();
        }
        for(int l=2;l<=n;++l){
            for(int i=1;i<=n-l+1;++i){
                int j=i+l-1;
                m[i][j]=INF;
                for(int k=i;k<=j-1;++k){
                    m[i][j]=Math.min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
                }
            }
        }
        System.out.println(m[1][n]);
    }
}