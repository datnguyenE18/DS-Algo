#include<iostream>
#include<fstream>
using namespace std;
void doctep(float a[], int &n){
	fstream fd("input.txt",ios::in);
	fd>>n;
	for(int i=0;i<n;i++){
		fd>>a[i];
	}
	fd.close();
}
void swap(float *a, float *b)
{
	float temp = *a;
	*a = *b;
	*b= temp;
}

void merge(float a[], int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	
	float L[n1], R[n2];
	int i=0;
	while(i<n1){
		L[i] = a[l+i];
		i++;
	}
	int j=0;
	while(j<n2){
		R[j] = a[m+1+j];
		j++;
	}	
	i=0;
	j=0;
	int k=l;
	
	while(i < n1 && j < n2 ){
		int chon=1;
		while(L[i] <= R[j]&&chon==1)
		{
			a[k] = L[i];
			i++;
			chon=0;
			break;
		}
		while(L[i]>R[j]&&chon==1)
		{
			a[k] = R[j];
			j++;
			chon=0;
			break;
		}
		k++;
	}
	
	while(i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(float a[], int l , int r)
{
	while(l < r)
	{
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		
		merge(a, l, m ,r);
		break;
	}
}
void mergesort(float a[], int n){
	mergeSort(a,0,n-1);
}
void ghitep(float a[], int n){
	fstream fg("output.txt",ios::out);
	fg<<n<<endl;
	for(int i=0;i<n;i++){
		fg<<a[i]<<" ";
	}
	fg.close();
}
int main(){
	float a[100]; int n;
	doctep(a,n);
	mergesort(a,n);
	ghitep(a,n);
	return 0;
}

