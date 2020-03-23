#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
typedef struct //Создание структуры
{
	int a;
	int b;
	double mod;
} Chislo;

void inputChilso(Chislo* x, FILE* f) //Считывание числа из файла
{
	fscanf_s(f, "%d", &(x->a));
	fscanf_s(f, "%d", &(x->b));
	x->mod = sqrt(pow(x->a, 2) + pow(x->b, 2));
}
Chislo* inputMassChislo(int* size, char* f) //Считывание массива
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
void outputChislo(Chislo* c) //Вывод комплексного числа
{
	printf("%d+%di\n \t модуль =%f\n", c->a, c->b, c->mod);
}
void outputMassChislo(Chislo* mass, int size) //Вывод в консоль
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
	printf("Больший модуль %f\n", biggestmod);
	for (int i = 0; i < size; i++)
	{
		if (sqrt(pow(m[i].a, 2) + pow(m[i].b, 2)) == biggestmod)
		{
			printf("Большее по модулю %d+%di\n", m[i].a, m[i].b);
		}
	}

}
int main()
{
	/*Задание 1. Считать комплексные числа из файла, вывести в консоль в виде a+bi
	setlocale(LC_ALL, "Rus");
    int size;
    Chislo* input = 0;
    input = inputMassChislo(&size, "A.txt");
    outputMassChislo(input, size);
    outputBiggestChislo(input, size);
    free(input);
    system("pause");
	*/
	/* Задание 2. Реализовать безопасный ввод пароля в консоль (отображение звёздочек вместо печатаемых символов).
	setlocale(LC_ALL, "rus");
	printf("Введите количество символов в пароле :\n");
	int n, i;
	scanf_s("%d", &n);
	char* password = (char*)malloc(n * sizeof(char));
	printf("Введите пароль:\n");
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
