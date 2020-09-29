#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
struct Car //Acceleration Engine volume Year of manufacture Price strcpy 
{
	char stamp[50];
	char model[50];
	int acceleration;
	float engineVolume;
	int yearOfManufacture;
	int price;
};
Car * dopСharcteristics;
void init(int kol) 
{
	strcpy(dopСharcteristics[kol].stamp, "Hissan");
	strcpy(dopСharcteristics[kol].model, "GTX");
	dopСharcteristics[kol].acceleration = 360;
	dopСharcteristics[kol].engineVolume = 8;
	dopСharcteristics[kol].yearOfManufacture = 2021;
	dopСharcteristics[kol].price = 3650000;
}
int read(int kol)
{
	int i = kol; 
	do {
		system("cls");
		init(i);
		printf("Если хотите заполнение по умолчанию нажмите 1, если хотите заполнить, нажмите любую клавишу\n");
		if (_getch() != '1') 
		{
			system("cls");
			printf("Введите марку машины: ");
			scanf("%s", &dopСharcteristics[i].stamp);
			printf("\nВведите модель: ");
			scanf("%s", &dopСharcteristics[i].model);
			printf("\nВведите макс.скорость: ");
			scanf("%d", &dopСharcteristics[i].acceleration);
			printf("\nВведите объем двигателя: ");
			scanf("%f", &dopСharcteristics[i].engineVolume);
			printf("\nВведите год выпуска: ");
			scanf("%d", &dopСharcteristics[i].yearOfManufacture);
			printf("\nВведите цену: ");
			scanf("%d", &dopСharcteristics[i].price);
		}
		i++;
		printf("Нажмите Esc если хотите закончить или нажмите на любую кнопку\n");
	} while (_getch() != 27);
	return i;
}
void display( int kol) 
{
	for (int i = 0; i < kol; i++) 
	{
		printf("%d. %s %s %d %.1f %d %d\n", i + 1, dopСharcteristics[i].stamp, dopСharcteristics[i].model, dopСharcteristics[i].acceleration, dopСharcteristics[i].engineVolume, dopСharcteristics[i].yearOfManufacture, dopСharcteristics[i].price);
	}
}
void add( int kol) 
{
	printf("Выберите номера 2 машин сумму которых хотите сложить\nВведите номер перовой машины: ");
	int flag = 1, oneCar, twoCar, sumPayCar;
	do
	{
		scanf_s("%d", &oneCar);
		if (oneCar > 0 && oneCar < kol)
			flag = 0;
	} while (flag != 0);
	flag = 1;
	do
	{
		printf("Введите номер второй машину: ");
		scanf_s("%d", &twoCar);
		if (twoCar > 0 && twoCar < kol + 1)
			flag = 0;
	} while (flag != 0);
	sumPayCar = dopСharcteristics[oneCar - 1].price + dopСharcteristics[twoCar - 1].price;
	printf("За 2 машины вы заплатите: %d руб\n", sumPayCar);
}
void search( int kol) 
{
	printf("Введите название машины которую для поиска: ");
	char carSearch[50], cars[1];
	int flag = 1, flag2 = 1;
	gets_s(cars);
	gets_s(carSearch);
	for (int i = 0; i < kol; i++)
	{
		if (strcmp(dopСharcteristics[i].stamp, carSearch) == 0)
		{
			printf("%d. %s %s %d %.1f %d %d\n", i + 1, dopСharcteristics[i].stamp, dopСharcteristics[i].model, dopСharcteristics[i].acceleration, dopСharcteristics[i].engineVolume, dopСharcteristics[i].yearOfManufacture, dopСharcteristics[i].price);
			flag = 0;
		}
	}
	if (flag != 0)
		printf("Ни одной машины не найдено\n");
}
void comparison(int kol)
{
	printf("Введите номера машин которые хотите сравнить\nНомер первой машины: ");
	int flag = 1, oneCar, twoCar;
	do
	{
		scanf_s("%d", &oneCar);
		if (oneCar > 0 && oneCar < kol)
			flag = 0;
	} while (flag != 0);
	flag = 1;
	do
	{
		printf("Введите вторую машину: ");
		scanf_s("%d", &twoCar);
		if (twoCar > 0 && twoCar < kol + 1)
			flag = 0;
	} while (flag != 0);
	if (strcmp(dopСharcteristics[oneCar - 1].stamp, dopСharcteristics[twoCar - 1].stamp) == 0)
		printf("Марки машин одинакова\n");
	else
		printf("Марки машин отличаются\nМарка первой машины: %s\n Марка второй машины: %s\n", dopСharcteristics[oneCar - 1].stamp, dopСharcteristics[twoCar - 1].stamp);
	if (strcmp(dopСharcteristics[oneCar - 1].model, dopСharcteristics[twoCar - 1].model) == 0)
		printf("Модели машин одинакова\n");
	else
		printf("Модель машин отличаются\nМодель первой машины: %s\nМодель второй машины: %s\n", dopСharcteristics[oneCar - 1].model, dopСharcteristics[twoCar - 1].model);
	
	if (dopСharcteristics[oneCar - 1].acceleration == dopСharcteristics[twoCar - 1].acceleration)
		printf("Макс.скорость машин одинакова\n");
	if (dopСharcteristics[oneCar - 1].acceleration > dopСharcteristics[twoCar - 1].acceleration)
		printf("Макс.сокрость первой машины больше второй на: %d\n", dopСharcteristics[oneCar - 1].acceleration - dopСharcteristics[twoCar - 1].acceleration);
	if (dopСharcteristics[oneCar - 1].acceleration < dopСharcteristics[twoCar - 1].acceleration)
		printf("Макс.сокрость второй машины больше первой на: %d\n", dopСharcteristics[twoCar - 1].acceleration - dopСharcteristics[oneCar - 1].acceleration);

	if (dopСharcteristics[oneCar - 1].engineVolume == dopСharcteristics[twoCar - 1].engineVolume)
		printf("Объем машин одинакова\n");
	if (dopСharcteristics[oneCar - 1].engineVolume > dopСharcteristics[twoCar - 1].engineVolume)
		printf("Объем первой машины больше второй на: %.1f\n", dopСharcteristics[oneCar - 1].engineVolume - dopСharcteristics[twoCar - 1].engineVolume);
	if (dopСharcteristics[oneCar - 1].engineVolume < dopСharcteristics[twoCar - 1].engineVolume)
		printf("Объем второй машины больше первой на: %.1f\n", dopСharcteristics[twoCar - 1].engineVolume - dopСharcteristics[oneCar - 1].engineVolume);

	if (dopСharcteristics[oneCar - 1].yearOfManufacture == dopСharcteristics[twoCar - 1].yearOfManufacture)
		printf("Год машин одинакова\n");
	if (dopСharcteristics[oneCar - 1].yearOfManufacture > dopСharcteristics[twoCar - 1].yearOfManufacture)
		printf("Первая машина старше второй на: %d\n", dopСharcteristics[oneCar - 1].yearOfManufacture - dopСharcteristics[twoCar - 1].yearOfManufacture);
	if (dopСharcteristics[oneCar - 1].yearOfManufacture < dopСharcteristics[twoCar - 1].yearOfManufacture)
		printf("Вторая машина старше первой на: %d\n", dopСharcteristics[twoCar - 1].yearOfManufacture - dopСharcteristics[oneCar - 1].yearOfManufacture);

	if (dopСharcteristics[oneCar - 1].yearOfManufacture == dopСharcteristics[twoCar - 1].yearOfManufacture)
		printf("Стоимость машин одинакова\n");
	if (dopСharcteristics[oneCar - 1].yearOfManufacture > dopСharcteristics[twoCar - 1].yearOfManufacture)
		printf("Первая машина дороже второй на: %d\n", dopСharcteristics[oneCar - 1].yearOfManufacture - dopСharcteristics[twoCar - 1].yearOfManufacture);
	if (dopСharcteristics[oneCar - 1].yearOfManufacture < dopСharcteristics[twoCar - 1].yearOfManufacture)
		printf("Вторая машина дороже первой на: %d\n", dopСharcteristics[twoCar - 1].yearOfManufacture - dopСharcteristics[oneCar - 1].yearOfManufacture);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	int flag = 1, kol = 0;
	dopСharcteristics = (struct Car*)malloc(5 * sizeof(struct Car));
	printf("Добро пожаловать в магазин по закупке авто\n");
	do {
		kol = read( kol);
		system("cls");
		display(kol);
		add(kol);
		search(kol);
		comparison(kol);
		printf("Нажмите Esc если хотите закончить или нажмите на любую кнопку\n");
	} while (_getch() != 27);
	kol = 0;
	system("cls");
	free(dopСharcteristics);
	return 0;
}