#include<stdio.h>
#include<conio.h>
void insertionsort(float a[],int n)
{
		for(int i = 2;i <= n;i++)
	{
			int j = i - 1;
			float t = a[i];
		while (t > a[j] && j >= 1)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}
void doctep(float a[],int &n){
	FILE *f = fopen("input.txt","r");
	fscanf(f,"%d",&n);
	for(int i = 1;i <= n;i++)
		fscanf(f,"%f",&a[i]);
	fclose(f);
}
void ghitep(float a[],int n){
	FILE *f = fopen("output.txt","w");
	fprintf(f,"%d\n",n);
	for(int i = 1;i <= n;i++)
		fprintf(f,"%f ",a[i]);
	fclose(f);
}
main(){
	float a[100];
	int n;
	doctep(a,n);
	insertionsort(a,n);
	ghitep(a,n);
}
