#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <windows.h>


int DeletePovtori(int* mass, int n) {
	for (int j = 0; j < n; j += 1) {
		for (int i = j + 1; i < n; i += 1) {
			if (mass[j] == mass[i]) {
				mass[i] = '\0';
			}
		}
	}
	int s=0;
	for (int i = 0; i < n; i++) {
		if (mass[i] != '\0') {
			printf("%d", mass[i]);
			s++;
		}
	}
	return(s);
}

void bubble(int* num, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) 
		{
			if (num[j - 1] > num[j]) 
			{
				int temp = num[j - 1]; 
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}

int main()
{
	setlocale( LC_ALL,"rus");
	
	printf("введите размер\n пожалуйста\n ");
	int a;
	scanf_s("%d", &a);
	

	int* mass = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++)
	{
		scanf_s("%d", &mass[i]);
	}
	int k;
	k =DeletePovtori(mass, a);
	bubble(mass, k);
}