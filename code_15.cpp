long long int Merge(long long int arr[], int i, int mid, int j)
{
	int k = mid;
	long long int count =0;
	long long int temp[j-i+1];
	int idx = 0;
	int ii = i;
	
	while(i<=mid-1 && k<=j)
	{
		if(arr[i] > arr[k])
		{
			count += mid - i;
			temp[idx++] = arr[k++]; 
		}
		else 
		{
			temp[idx++] = arr[i++];
		}
	}
	
	while(i<=mid-1)
	{
		temp[idx++] = arr[i++];
	}
	
	while(k<= j)
	{
		temp[idx++] = arr[k++];
	}
	
	for(i=0; i<idx; i++)
	{
		arr[i+ ii] = temp[i];
	}
	
	return count;
}


long long int _MergeSort(long long arr[], int i, int j)
{
	if(i>=j) return 0;
	
	int mid = (i+j)/2;
	long long int count = 0;
	
	count += _MergeSort(arr, i, mid);
	count += _MergeSort(arr, mid+1, j);
	count += Merge(arr, i, mid+1, j);
	
	return count;
	
}



long long int inversionCount(long long arr[], int n)
{
	long long int count =0;
	count = _MergeSort(arr, 0, n-1);
	return count;
}

