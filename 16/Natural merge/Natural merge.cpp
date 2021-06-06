#include <iostream>
using namespace std;

int arr[10];
int num;


void mergeSortRec(int* v, int r) {
	int p = 1;
	int k = 1;
	int i = 0;
	bool flag = false;

	while (v[i] <= v[i + 1] && i < r - 1) {
		p++;
		i++;
	}
	if (v[i] > v[i + 1] && i < r - 1) {
		i++;
		flag = true;
		while (v[i] <= v[i + 1] && i < r - 1) {
			k++;
			i++;
		}
	}
	num = i + 1;
	int* a = new int[p];
	int* b = new int[k];

	for (i = 0; i < p; i++) {
		a[i] = v[i];
	}

	int g = 0;
	if (flag == true) {
		for (i = p; i < p + k; i++) {
			b[g] = v[i];
			g++;
		}
	}
	int j = 0;
	int l = 0;
	if (flag == true) {
		for (i = 0; i < num; i++) {
			if ((a[l] < b[j] || j >= k) && l < p) {
				v[i] = a[l];
				l++;
			}
			else
				if ((a[l] > b[j] || l >= p) && j < k) {
					v[i] = b[j];
					j++;
				}
				else
					if (a[l] == b[j] && j < k && l < p) {
						v[i] = a[l];
						v[i + 1] = b[j];
						l++;
						j++;
						i++;
					}
		}
	}
	delete[] a;
	delete[] b;
}

void mergeSort1(int* v, int r, int i) {
	if (i < r) {
		mergeSortRec(v, r);
		mergeSort1(v, r, i + 1);
	}
}



int main()
{
	setlocale(LC_ALL, "rus");

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	mergeSort1(arr, 10, 0);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}