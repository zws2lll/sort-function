//各种排序算法的实现
/*
交换函数
*/
void swap(int *list, int low, int high )
{    
	int temp = list[low];
	list[low] = list[high];
	list[high] = temp;
}

/*
小于函数
*/
bool lt(const int low, const int high )
{
	if(low < high)
		return true;
	else 
		return false;
}

/*
插入排序（稳定）
原理：插入排序逐个处理待排序的记录。每个新记录与前面已排序的子序列进行比较，
将它插入到子序列中正确的位置
代价是n2
*/
void inssort( int *list, int n )
{
	int i,j;
	for( i = 1; i < n; i++ )
	{
		for( j = i; ( j > 0 ) && ( lt( list[j], list[j-1] ) ); j-- )
			swap( list, j, j-1 );
	}
}

/*
冒泡排序（稳定）
原理：第一次的内部for循环从记录数组的底部比较到顶部，比较相邻的值。
如果低序号的值比高序号的值大，则二者交换顺序
代价是n2
*/
void bubsort( int *list, int n )
{
	int i,j;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = n-1; j > i; j-- )
		{    
			if( lt( list[j], list[j-1] ) )
				swap( list, j, j-1 );
		}
	}
}

/*
选择排序（不稳定）
原理：选择排序的第i次是“选择”数组中第i小的记录，并将该记录放到数组的第i个位置。
即首先从未排序的序列中找到最小的值，接着找到次小的，依次类推
代价是n2
*/
void selsort( int *list, int n )
{
	int i,j;
	for ( i = 0; i < n-1; i++ )
	{
		int low_index = i;
		for ( j = n-1; j > i; j-- )
		{    
			if( lt( list[j], list[low_index] ) )
				low_index = j;
		}
		swap( list, i, low_index );
	}
}

/*
插入排序函数（shell排序的辅助函数）
*/
void inssort( int *list, int n, int incr )
{
	int i,j;
	for ( i = incr; i < n; i += incr )
	{
		for ( j = i; (j >= incr) && (lt (list[j],list[j-incr]) ); j -= incr )
		{    
			swap( list, j, j-incr );
		}        
	}
}

/*
shell排序（不稳定）
原理：将序列分成子序列，然后分别对子序列用插入排序的方法进行排序，最后将子序列组合起来。
代价是n1.5
*/
void shellsort( int *list, int n )
{
	int i,j;
	for ( i = n/2; i > 2; i /= 2 )
	{
		for ( j = 0; j < i; j++ )
		{    
			inssort(&list[j], n-j, i);
		}
	}
	inssort(list, n, 1);
}

/*
快速排序(不稳定)
原理：首先选择一个轴值，小于轴值的结点被放到轴值的左边，大于轴值的结点被放到轴值的右边，这样轴值就被放在了正确的位置上。
然后对轴值左边和右边的子序列进行类似操作。
第一次调用的形式为quicksort(list,0,n-1)
代价是n*logn
*/
void quicksort(int *list, int low, int high)
{
	int pivot = list[ (low + high) / 2 ];
	int left = low - 1;
	int right = high;
	
	if(low >= high) 
		return 0;
	
	swap(list, (low + high) / 2, high);          
	do     
	{
		while(list[++left] < pivot);         
		while(right != 0 && list[--right] > pivot);         
		swap(list, left, right);     
	} while (left < right);          
	
	swap(list, left, right);     
	swap(list, left, high);          
	
	quicksort(list, low, left - 1);     
	quicksort(list, left + 1, high); 
}