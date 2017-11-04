import java.util.Random;

public class Quick
{
	private static int cnt=0;
	public static void sort(int[] a){
		Random rand = new Random();
		System.out.println("快排之前:");
		for(int i=0;i<20;++i){
			a[i]=rand.nextInt(100);
			System.out.print(a[i]+" ");
		}
		sort(a,0,a.length - 1);
	}
	public static void sort(int[] a,int lo,int hi){
		if(hi <= lo) return;
		int j = partition(a,lo,hi);//切分
		sort(a,lo,j-1);
		sort(a,j+1,hi);
	}
	public static int partition(int[] a,int lo,int hi){
		//将数组切分为a[lo..i-1],a[i],a[i+1..hi]
		int i=lo,j=hi+1;//左右扫描指针
		int pt=a[lo];//切分元素
		while(true){
			//扫描左右,检查扫描是否结束并交换元素
			while(a[++i]<pt)if(i==hi) break;//扫描到最左边都没找到大于等于pt的
			while(a[--j]>pt)if(j==lo) break;
			if(i>=j) break;//指针重合
			swap(a,i,j);//没有问题,交换两值
		}
		swap(a,lo,j);//将作为基准的数放回正确的位置,切分为两部分,大于基准,小于基准
		return j;
	}
	public static void swap(int[] a,int x,int y){
		if(x == y) return;
		a[x]=a[x]^a[y];
		a[y]=a[y]^a[x];
		a[x]=a[x]^a[y];
		cnt++;
		System.out.println("\n第"+cnt+"次变化 "+x+" to "+y+" : ");
		for(int item: a){
			System.out.print(item+" ");
		}
	}
	public static void main(String[] args){
		int[] a=new int[20];
		sort(a);
		System.out.println("\n快排之后:");
		for(int item: a){
			System.out.print(item+" ");
		}
	}
}