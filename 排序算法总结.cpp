/*
常见排序算法主要有：冒泡排序，选择排序，插入排序，归并排序，希尔排序，堆排序，快速排序，计数排序，基数排序，桶排序。
1. 冒泡排序(Bubble sort)
    依次比较相邻的两个数，将小数放在前面，大数放在后面。

2. 选择排序(Selection sort)
    每一趟从待排序的数据元素中选出最小（或最大）的一个元素，顺序放在已排好序的数列的最后，直到全部待排序的数据元素排完。

3. 插入排序(Insertion sort)
    将n个元素的数列分为已有序和无序两个部分，每次处理就是将无序数列的第一个元素与有序数列的元素从后往前逐个进行比较，
    找出插入位置，将该元素插入到有序数列的合适位置中。

4. 归并排序(Merge sort)
    将两个（或两个以上）有序表合并成一个新的有序表，即把待排序序列分为若干个子序列，每个子序列是有序的。然后再把有序子序列合并为整体有序序列。
    排序过程如下：
        1) 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
        2) 设定两个指针，最初位置分别为两个已经排序序列的起始位置
        3) 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
        4) 重复步骤3直到某一指针达到序列尾
        5) 将另一序列剩下的所有元素直接复制到合并序列尾

5. 希尔排序(Shell sort)
    希尔排序插入排序的一种，是针对直接插入排序算法的改进，该方法又称缩小增量排序。
    排序过程如下：
        1) 先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。所有距离为d1的倍数的记录放在同一个组中。
        2) 在各组内进行直接插入排序；
        3) 取第二个增量d2<d1重复上述的分组和排序，直至所取的增量dt=1(dt<dt-l<…<d2<d1)，即所有记录放在同一组中进行直接插入排序为止。

6. 堆排序(Heap sort)
    堆积排序是指利用堆积树（堆）这种资料结构所设计的一种排序算法，可以利用数组的特点快速定位指定索引的元素。
    排序过程如下：
        1) 建立一个堆H[0..n-1]
        2) 把堆首（最大值）和堆尾互换
        3) 把堆的尺寸缩小1，并调用shift_down(0),目的是把新的数组顶端数据调整到相应位置
        4) 重复步骤2，直到堆的尺寸为1

7. 快速排序(Quick sort)
    通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据
    分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
    排序过程如下：
    　　1) 设置两个变量i、j，排序开始的时候：i=0，j=n-1
    　　2) 以第一个数组元素作为关键数据，赋值给key，即 key=A[0]
    　　3) 从J开始向前搜索，即由后开始向前搜索（j=j-1），找到第一个小于key的值A[j]，并与A[i]交换
    　　4) 从i开始向后搜索，即由前开始向后搜索（i=i+1），找到第一个大于key的A[i]，与A[j]交换
    　　5) 重复第3、4、5步，直到 i=j；(3,4步是在程序中没找到时候j=j-1，i=i+1，直至找到为止。找到并交换的时候i，j指针位置不变。另外当i=j这过程一定正好是i+或j-完成的最后另循环结束。) 


8. 计数排序(Counting sort)
    计数排序使用一个额外的数组C，其中第i个元素是待排序数组A中值等于i的元素的个数。然后根据数组C来将A中的元素排到正确的位置。
    当输入的元素是 n 个 0 到 k 之间的整数时，它的运行时间是 O(n + k)。计数排序不是比较排序，排序的速度快于任何比较排序算法。
    排序过程如下：
        1) 找出待排序的数组中最大和最小的元素
        2) 统计数组中每个值为i的元素出现的次数，存入数组C的第i项
        3) 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
        4) 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1

9. 基数排序(Radix sort)
    一种整数排序算法，原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。
    基数排序的方式可以采用LSD（Least significant digital）或MSD（Most significant digital），LSD的排序方式由键值的最右边开始，
    而MSD则相反，由键值的最左边开始。
    排序过程：
        1) 先按k1(某位上的数字)排序分组，同一组中记录，关键码k1相等，
        2) 对各组按k2排序分成子组，
        3) 对后面的关键码继续这样的排序分组，直到按最次位关键码kd对各子组排序后。再将各组连接起来，便得到一个有序序列。
     
10. 桶排序(Bucket sort)
    桶排序或所谓的箱排序，工作的原理是元素分到有限数量的桶子里。箱排序只适用于关键字取值范围较小的情况，否则所需箱子的数目m太多导致浪费存储空间和计算时间。
    每個桶子再个别排序（有可能再使用別的排序算法或是以递归方式继续使用桶排序进行排序）。
    排序过程如下：
        1) 设置一定量的阵列作为‘空桶子’
        2) 遍历序列，并把元素一个个放到对应的桶子中
        3) 对每一个不是空的桶子进行排序
        4) 从非空桶子中把元素再放回到原来的序列中
*/

#include <iostream>
#include <ctime>
const int SIZE = 100;
const int MAX = 1000;
using namespace std;

//交换数据
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//冒泡排序
void BubbleSort(int *arr, int size)
{
	int i, j;
	for(i=0;i<size-1;i++)
		for(j=size-1;j>i;j--)
			if(arr[j] < arr[j-1])
				Swap(arr[j], arr[j-1]);
}

//选择排序
void SelectionSort(int *arr, int size)
{
	int i, j, min;
	//找出从a[i]到a[size-1]的最小元素的位置
	for(i=0;i<size-1;i++)
	{
		min = i;
		for(j=i+1;j<size;j++)
			if(arr[min] > arr[j])
				min = j;
		//将a[i]与a[min]的数据交换
		Swap(arr[i], arr[min]);
	}
}

//插入排序
void InsertSort(int *arr, int size)
{
	int fOut, loc, temp;
	for(fOut=1;fOut<size;fOut++)
		if(arr[fOut] < arr[fOut-1])
		{
			temp = arr[fOut];
			loc = fOut;
			do
			{
				arr[loc] = arr[loc-1];
				loc--;
			}while(loc>0 && arr[loc-1]>temp);
			arr[loc] = temp;
		}
}

//快速排序
int Partition(int *arr, int first, int last)
{
	int i, small, x;
	//为了减少最差情况的出现频率而作的一种优化
	swap(arr[first], arr[ (first+last)/2 ]);
	x = arr[first];
	small = first;
	for(i=first+1;i<=last;i++)
		if(arr[i] < x)
		{
			small++;
			swap(arr[small], arr[i]);
		}
		swap(arr[first], arr[small]); 
		return small;
}

void RecQuick(int *arr, int first, int last)
{
	int pivotLoc;
	if(first < last)
	{
		pivotLoc = Partition(arr, first, last);
		RecQuick(arr, first, pivotLoc-1);
		RecQuick(arr, pivotLoc+1, last);
	}
}

void QuickSort(int *arr, int size)
{
	RecQuick(arr, 0, size-1);
}

//计数排序
void CountSort(int *arr, int size)
{
	int temp[MAX] = {0};
	int i, j;
	for(i=0;i<size;i++)
		temp[arr[i]]++;
	j = 0;
	for(i=0;i<MAX;i++)
	{
		while(0 != temp[i])
		{
			arr[j] = i;
			temp[i]--;
			j++;
		}
	}
}

//归并排序
void Merge(int *arr, int start, int mid, int end)
{
	int temp1[SIZE], temp2[SIZE];
	int n1, n2;
	int i, j, k;
	n1 = mid - start + 1;
	n2 = end - mid;
	//拷贝前半部分数组
	for(i=0;i<n1;i++)
		temp1[i] = arr[start + i];
	//拷贝后半部分数组
	for(i=0;i<n2;i++)
		temp2[i] = arr[mid + i + 1];
	//把后面的元素设置的很大
	temp1[n1] = temp2[n2] = INT_MAX;
	i = j = 0;
	// 逐个扫描两部分数组然后放到相应的位置去
	for(k=start;k<=end;k++)
	{
		if(temp1[i] <= temp2[j])
		{
			arr[k] = temp1[i];
			i++;
		}
		else
		{
			arr[k] = temp2[j];
			j++;
		}
	}
}

void RecMerge(int *arr, int start, int end)
{
	int i;
	if(start < end)
	{
		i = (start + end) / 2;
		RecMerge(arr, start, i);
		RecMerge(arr, i+1, end);
		Merge(arr, start, i, end);
	}
}

void MergeSort(int *arr, int size)
{
	RecMerge(arr, 0, size-1);
}

//堆排序
void Heapify(int *arr, int low, int high)
{
	int large;
	int temp = arr[low];
	large = 2 * low + 1;
	while(large <= high)
	{
		if(large<high && arr[large]<arr[large+1])
			large = large + 1;
		if(temp > arr[large])
			break;
		else
		{
			arr[low] = arr[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	arr[low] = temp;
}

void BuildHeap(int *arr, int size)
{
	int i;
	for(i=size/2-1;i>=0;i--)
		Heapify(arr, i, size-1);
}

void HeapSort(int *arr, int size)
{
	int i;		//lastOfOrder
	BuildHeap(arr, size);
	for(i=size-1;i>=0;i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, 0, i-1);
	}
}

//希尔排序
void ShellSort(int *arr, int size)
{
	int i, j, k, temp;
	//i为增量
	for(i=size/2;i>0;i/=2)
	{
		for(j=i;j<size;j+=i)
		{
			temp = arr[j];
			k = j;
			while(k-i>=0 && temp<arr[k-i])
			{
				arr[k] = arr[k-i];
				k -= i;
			}
			arr[k] = temp;
		}
	}
}

//输出数组里的数据
void Print(int *arr, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%6d ", arr[i]); 
		if(0 == (i+1) % 10)
			cout << endl;
	}
	cout << endl;
}

//主函数
//先随机选择100个整型数据放入数组中，并输出
//然后将其从小到大排序，并输出
int main()
{
	int arr[SIZE], i;
	cout << "The array is: " << endl;
	srand((unsigned)time(0));
	for(i=0;i<SIZE;i++)
		arr[i] = rand() % MAX;
	Print(arr, SIZE);

	//请选择其中一个排序算法，以运行该程序
	//BubbleSort(arr, SIZE);
	//SelectionSort(arr, SIZE);
	//CountSort(arr, SIZE);
	//InsertSort(arr, SIZE);
	//SelectionSort(arr, SIZE);
	//QuickSort(arr, SIZE);
	//MergeSort(arr, SIZE);
	//HeapSort(arr, SIZE);
	ShellSort(arr, SIZE);

	cout << "After sorting, the array is:" << endl;
	Print(arr, SIZE);
	return 0;
}
