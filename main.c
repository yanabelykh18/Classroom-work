#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
typedef struct //�������� ���������
{
	int a;
	int b;
	double mod;
} Chislo;

void inputChilso(Chislo* x, FILE* f) //���������� ����� �� �����
{
	fscanf_s(f, "%d", &(x->a));
	fscanf_s(f, "%d", &(x->b));
	x->mod = sqrt(pow(x->a, 2) + pow(x->b, 2));
}
Chislo* inputMassChislo(int* size, char* f) //���������� �������
{
	FILE* input;
	fopen_s(&input, f, "r");
	fscanf_s(input, "%d", size);
	char tmp;
	fscanf_s(input, "%c", &tmp, 1);
	Chislo* result = (Chislo*)malloc((*size) * sizeof(Chislo));
	for (int i = 0; i < *size; ++i)
	{
		inputChilso(&result[i], input);
	}
	fclose(input);
	return result;
}
void outputChislo(Chislo* c) //����� ������������ �����
{
	printf("%d+%di\n \t ������ =%f\n", c->a, c->b, c->mod);
}
void outputMassChislo(Chislo* mass, int size) //����� � �������
{
	for (int i = 0; i < size; ++i)
	{
		outputChislo(&mass[i]);
	}
}
void outputBiggestChislo(Chislo* m, int size)
{
	double biggestmod = 0;
	for (int i = 0; i < size; i++)
	{
		if (m[i].mod > biggestmod)
		{
			biggestmod = m[i].mod;
		}

	}
	printf(" ������� ������ %f\n", biggestmod);
	for (int i = 0; i < size; i++)
	{
		if (sqrt(pow(m[i].a, 2) + pow(m[i].b, 2)) == biggestmod)
		{
			printf("������� �� ������ %d+%di\n", m[i].a, m[i].b);
		}
	}

}
int main()
{
	/*������� 1. ������� ����������� ����� �� �����, ������� � ������� � ���� a+bi
	setlocale(LC_ALL, "Rus");
    int size;
    Chislo* input = 0;
    input = inputMassChislo(&size, "A.txt");
    outputMassChislo(input, size);
    outputBiggestChislo(input, size);
    free(input);
    system("pause");
	*/
	/* ������� 2. ����������� ���������� ���� ������ � ������� (����������� �������� ������ ���������� ��������).
	setlocale(LC_ALL, "rus");
	printf("������� ���������� �������� � ������ :\n");
	int n, i;
	scanf_s("%d", &n);
	char* password = (char*)malloc(n * sizeof(char));
	printf("������� ������:\n");
	for (i = 0; (password[i] = getch()) != '\r';)
	{
		if (password[i] == '\b' && i != 0) {
			printf("%s", "\b \b");
			i--;
		}
		else if (password[i] != '\b') {
			printf("%c", '*');
			i++;
		}
	}
	password[i] = '\0';
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%c", password[i]);
	}*/

}