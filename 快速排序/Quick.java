import java.util.Random;

public class Quick
{
	private static int cnt=0;
	public static void sort(int[] a){
		Random rand = new Random();
		System.out.println("����֮ǰ:");
		for(int i=0;i<20;++i){
			a[i]=rand.nextInt(100);
			System.out.print(a[i]+" ");
		}
		sort(a,0,a.length - 1);
	}
	public static void sort(int[] a,int lo,int hi){
		if(hi <= lo) return;
		int j = partition(a,lo,hi);//�з�
		sort(a,lo,j-1);
		sort(a,j+1,hi);
	}
	public static int partition(int[] a,int lo,int hi){
		//�������з�Ϊa[lo..i-1],a[i],a[i+1..hi]
		int i=lo,j=hi+1;//����ɨ��ָ��
		int pt=a[lo];//�з�Ԫ��
		while(true){
			//ɨ������,���ɨ���Ƿ����������Ԫ��
			while(a[++i]<pt)if(i==hi) break;//ɨ�赽����߶�û�ҵ����ڵ���pt��
			while(a[--j]>pt)if(j==lo) break;
			if(i>=j) break;//ָ���غ�
			swap(a,i,j);//û������,������ֵ
		}
		swap(a,lo,j);//����Ϊ��׼�����Ż���ȷ��λ��,�з�Ϊ������,���ڻ�׼,С�ڻ�׼
		return j;
	}
	public static void swap(int[] a,int x,int y){
		if(x == y) return;
		a[x]=a[x]^a[y];
		a[y]=a[y]^a[x];
		a[x]=a[x]^a[y];
		cnt++;
		System.out.println("\n��"+cnt+"�α仯 "+x+" to "+y+" : ");
		for(int item: a){
			System.out.print(item+" ");
		}
	}
	public static void main(String[] args){
		int[] a=new int[20];
		sort(a);
		System.out.println("\n����֮��:");
		for(int item: a){
			System.out.print(item+" ");
		}
	}
}