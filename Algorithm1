void seqsearch(int n, const int S[], int x, int &location) {
	location = 0;
	while ((location < n) && (S[location] != x))
		location++;

	if (location >= n)
		location = -1;
}

void binsearch(int n, const int s[], int x, int& location) {

	int low = 0, high = n - 1, mid;
	location = -1;
	while ((low <= high) && (location == (-1))) {
		mid = (low + high) / 2;
		if (x == s[mid])
			location = mid;
		else if (x<s[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
}

int fib(int n) {
	int f[n];

	f[0] = 0;
	if (n>0) {
		f[1] = 1;
		for (int i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int fib(int n) {
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

void merge(int h, int m, int u[], int v[], int s[]) {
	int i = 0, j = 0, k = 0;

	while ((i<h) && (j<m)) {
		if (u[i]<v[j]) {
			s[k] = u[i];
			i++;
		}
		else {
			s[k] = v[j];
			j++;
		}
		k++;
	}
	if (i >= h)
		copy(v + j, v + m, s + k);
	else
		copy(u + i, u + h, s + k);

}


void mergesort(int n, int s[]) {
	if (n>1) {
		int h = (n / 2);
		int m = n - h;
		int *u = new int[h];
		int *v = new int[m];
		copy(s, s + h, u);
		copy(s + h, s + n, v);
		mergesort(h, u);
		mergesort(m, v);
		merge(h, m, u, v, s);
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void partition(int low, int high, int& pivot) {
	int i, j = low;
	int pivotitem = s[low];
	for (i = low + 1; i <= high; i++)
		if (s[i]<pivotitem) {
			j++;
			swap(s[i], s[j]);
		}
	pivot = j;
	swap(s[low], s[pivot]);
}

void quicksort(int low, int high) {
	int pivot;
	if (high>low) {
		partition(low, high, pivot);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}
