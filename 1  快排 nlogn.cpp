//-----1  快排 nlogn
#include<iostream>
using namespace std;
const int N=1e6+10;
int n;
int q[N];

void quick_sort(int q[],int l,int r)
{
	if(l>=r) return;
	int x=q[l + r >> 1],i=l-1,j=r+1;
	while(i<j)
	{
		do i++; while(q[i]<x);
		do j--; while(q[j]>x);
	/*  降序快排 
		do i++;while(q[i]>x);
		do j--;while(q[j]<x);
	*/
		if(i<j)
		{
			int t=q[i];
			q[i]=q[j];
			q[j]=t;
		}
	}
	//循环结束的结果  l >= j  所以划分区间[l,j] <=x , [j+1,r] >=x 
	quick_sort(q,l,j);    
	quick_sort(q,j+1,r);  //右边一定大于等于x
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&q[i]);
	quick_sort(q,0,n-1);
	for(int i=0;i<n;i++) printf("%d ",q[i]);
	return 0;	
} 


/*当以 i 划分区间时：
 
void quick_sort(int q[],int l,int r)
{
	if(l>=r) return;
	int x=q[l + r + 1>> 1],i=l-1,j=r+1;
	while(i<j)
	{
		do i++; while(q[i]<x);
		do j--; while(q[j]>x);
		if(i<j)
		{
			int t=q[i];
			q[i]=q[j];
			q[j]=t;
		}
	}
	//结束循环情况：i与j重合 指向x 
	quick_sort(q,l,i-1);  //只有2个数的序列如0、1；若(l,i),(i+1,r)则导致死循环 超时 
	quick_sort(q,i,r);
}

*/ 

/*
快速排序和归并排序一样，每一层的总时间复杂度都是 O（n） ，因为需要对每一个元素遍历一次。 
而且在最好的情况下，同样也是有 logn 层，所以快速排序最好的时间复杂度为 O（nlogn） 。
*/

//当以i划分区间时： 
		 //特殊情况一： 
//当给定的序列有序时，如果每次选择区间右端点进行划分，每次会将区间[L, R]
//划分成[L, L]和[L , R-1]，那么相当于每次递归右半部分的区间长度只会减少1，
//所以就需要递归 n-1次了，时间复杂度会达到 n2。但每次选择区间中点或者随机
//值时，划分的两个子区间长度会比较均匀，那么期望只会递归 logn层。
      
	    //特殊情况二： 
//只有两个数时，若序列为0，1； 选x=q[r]或x=q[l+r>>1]
//每次将区间划分为[L,L-1]和[L,R], 会发生死循环




//-----1  快排延伸  快速选择 O（n）
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

int quick_sort(int q[], int l, int r, int k)
{
    if (l == r) return q[l];              //可以写l>=r  因为在快选中，保证了所选区间一定有数，因为要从这个区间里边找结果， 但快排的区间不一定有数即l>r 
										  //最后的输出是通过这一步的 
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    //循环结束的结果  l >= j  所以划分区间[l,j] <=x , [j+1,r] >=x 
    if (j - l + 1 >= k) return quick_sort(q, l, j, k);  //左半边总数：sl=j-l+1,  ==的时候也没办法直接输出结果，因为不知道下标是多少 
    else return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    cout << quick_sort(q, 0, n - 1, k) << endl;

    return 0;
}

/* 时间复杂度分析：
因为，处理数据总量为 n+n/2+n/4+....+1，一共log n项（log n层排序，第i层数据量为n/(2^(i-1)） 
所以， O=n+n/2+n/4+....+1= ( 1*(1-2^log n) )/(1-2) = n
*/

//-----2  归并排序
#include<iostream>
using namespace std;
const int N=1e6+10;
int n;
int q[N],tmp[N];

void merge_sort(int q[],int l,int r)
{
	if(l>=r) return;
	int mid=l+r>>1;
	merge_sort(q,l,mid);
	merge_sort(q,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
		if(q[i]<=q[j]) tmp[k++]=q[i++];
		else	tmp[k++]=q[j++];
	while(i<=mid) tmp[k++]=q[i++];
	while(j<=r) tmp[k++]=q[j++];
	for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&q[i]);
	merge_sort(q,0,n-1);
	for(int i=0;i<n;i++) printf("%d ",q[i]);
	return 0;
}





