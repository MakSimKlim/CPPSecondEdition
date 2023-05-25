template <typename T> //
void insert_ascending(T a[], int size)
{
	T x;
	int i, j;

	for (i = 0; i < size; i++)
	{
		x = a[i];
		for (j = i - 1; j >= 0 && a[j] < x; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
}
template <typename T>
void insert_descending(T a[], int size)
{
	T x;
	int i, j;

	for (i = 0; i < size; i++)
	{
		x = a[i];
		for (j = i - 1; a[j] > x; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
}