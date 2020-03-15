#include<stdio.h>
#include<conio.h>

void bubblesort(float a[],int n)
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = n;j > i;j--)
		{
			if (a[j] > a[j - 1])
			{
				float tmp;
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void doctep(float a[],int &n)
{
	FILE *f = fopen("input.txt","r");
	fscanf(f,"%d",&n);
	for(int i = 1;i <= n;i++)
		fscanf(f,"%f",&a[i]);
	fclose(f);
}

void ghitep(float a[],int n)
{
	FILE *f = fopen("output.txt","w");
	fprintf(f,"%d\n",n);
	for(int i = 1;i <= n;i++)
		fprintf(f,"%f ",a[i]);
}

main(){
	float a[100];
	int n;
	doctep(a,n);
	bubblesort(a,n);
	ghitep(a,n);
}
