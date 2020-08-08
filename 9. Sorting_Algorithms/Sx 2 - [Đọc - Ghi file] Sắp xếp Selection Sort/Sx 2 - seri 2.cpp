#include<stdio.h>
#include<conio.h>

void doctep(float a[], int &n)
{
	FILE *f = fopen("input.txt","r");
	fscanf(f,"%d", &n);
	for (int i = 1; i <= n; i++)
		{
			fscanf(f,"%f", &a[i]);
		}
	fclose(f);
}

void ghitep(float a[], int n)
{
	FILE *f = fopen("output.txt","w");
	fprintf(f,"%d\n", n);
	for (int i = 1; i <= n; i++)
		{
			fprintf(f,"%f\t", a[i]);
		}
	fclose(f);
}

void selectsort(float a[], int n)
{
	for (int i = 1; i <= n; i++)
		{
			int vt = i, j;
			float temp;
			for (int j = i + 1; j <= n; j++ )
				{
					if(a[j] <= a[vt])
						{
							temp = a[vt];
							a[vt] = a[j];
							a[j] = temp;							
						}
				}
		}
}

int main()
{
	int n;
	float a[100];
	doctep(a,n);
	selectsort(a,n);
	ghitep(a,n);
	return 0;
}
