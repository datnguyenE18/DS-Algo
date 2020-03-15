#include <stdio.h>

void doctep(float a[], int &n) {
	FILE *fdoc = fopen("input.txt", "r");
	fscanf(fdoc, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fdoc, "%f", &a[i]);
	}
	fclose(fdoc);
}

void ghitep(float a[], int n) {
	FILE *fghi = fopen("output.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(fghi, "%.2f ", a[i]);
	}
	fclose(fghi);
}

void swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

void quicksort(float a[], int left, int right) {
	int i = left, j = right;
	float pivot = a[left + (right-left)/2];
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		while (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
			break;
		}
	}
	while (left < j) {
		quicksort(a, left, j);
		break;
	}
	while (i < right) {
		quicksort(a, i, right);
		break;
	}
}

int main() {
	int n;
	float a[100000];
	doctep(a, n);
	quicksort(a, 0, n - 1);
	ghitep(a, n);
	return 0;
}

