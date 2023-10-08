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

