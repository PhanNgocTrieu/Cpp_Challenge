#ifndef __SORT_H__
#define __SORT_H__

void enterArray(int arr[], int _size)
{
	int _idex = 0;
	for (_idex; _idex < _size; _idex++)
	{
		printf("Enter arr[%d]:",_idex);
		scanf("%d", &arr[_idex]);
	}
}

void outputArray(int arr[], int _size)
{
	int _idex = 0;
	for (_idex; _idex < _size; _idex++)
	{
		printf("%d ",arr[_idex]);
	}
}

int Compare(const void* a, const void* b)
{
	return (*(int*)a - *(int *)b);
}

void quickSortForArray_Solving()
{
	int arr[100];
	int _size;
	printf("Enter n: ");
	scanf("%d", &_size);
	enterArray(arr,_size);
	qsort(arr,_size,sizeof(int),Compare);
	outputArray(arr,_size);	
}


/**
 *	Built - Sorting
 */
 
void Swap(int *a,int *b){
	int tmp = *a;
	*a=*b;
	*b=tmp;
}

 
void SelectionSort(int a[],int n )
{ 
	int min; // chi so phan tu nho nhat trong day 
	int i,j;
	for ( i=0; i<n-1 ; i++)
	{ 
		min = i;
		for( j = i+1; j <n ; j++)
		{
			if (a[j] < a[min])
				min = j; // ghi nhan vi tri phan tu nho nhat
		}
		Swap(&a[min], &a[i]); 
	}
}

#endif // _SORT_H_
