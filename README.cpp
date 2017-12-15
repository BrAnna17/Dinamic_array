/*Dynamic_array
Creation of dynamic array using pointers*
 Брагина Анна, семинар 6, задача 10.
 Есть два массива, массив ключей и массив значений. Также есть третий массив в котором попарно
 хранятся указатели на соответствующие эллементы этих двух массивов. Необходимо организовать функцию  сортировки пар
 в третьем массиве по возрастанию ключей, а также добавление новой пары ключ-значение ко всей коллекции*/
 
#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

struct NewMass // Объявляем структуру. Поле  k -  ключи,  v - значения
{
	int * k, * v;
};
 
NewMass* sort(int* keys, int* values, NewMass* third, int len) //Функция, реализурующая сортировку нового массива, возвращает
{						              // указатель на измененную структуру
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (*third[j + 1].k <*third[j].k)
			{
				NewMass tmp = third[j + 1];
				third[j + 1] = third[j];
				third[j] = tmp;
			}
		}
	}

	return (third);
}

 

int main()
{
	int len = 0; //Начальная длина
	cout << " Write number of keys $ values " << endl;
	cin >> len;
	int * keys = (int*)malloc(len*sizeof(int)); //Выделяем динамическую память для ключей и значений
	int * values = (int*)malloc(len*sizeof(int));
	struct NewMass * third = (NewMass*)malloc(len*sizeof(NewMass));
	if (keys == NULL) return (1); 
	if (values == NULL) return (1);

	for (int i = 0; i < len; i++) //Заполнение массива
	{
		keys[i] = rand() % 50;
		values[i] = rand() % 50;
		third[i].k = &keys[i];
		third[i].v = &values[i];
	}
	cout << " Your array is: " << endl; 
	for (int i = 0; i < len; i++) // Печатаем  массив
		cout<<*third[i].k<<" "<<*third[i].v<<endl;

	cout<<" Lets add an element "<<endl;
	int input;
	len++;
	cout<<" Enter key: ";
	cin>>input;
	keys = (int*)realloc(keys, len * sizeof(int)); //Изменяем размер динамического массива ключей
	keys[len - 1] = input; // Добавляем ключ
	cout<<" Enter value: ";
	cin>>input;
	values = (int*)realloc(values, len * sizeof(int)); //Изменяем размер динамического массива значений
	values[len - 1] = input; // Добавляем значение

	third = (NewMass*)realloc(third, len * sizeof(NewMass));
	for (int i = 0; i < len; i++) //заполнение массива с новым элементом
	{
		third[i].k = &keys[i];
		third[i].v = &values[i];
	}

	for (int i = 0; i < len; i++) //вывод массива с новым элементом в конце (просто добавили )
		cout<<*third[i].k<<" "<<*third[i].v<<endl;

	cout << " Lets sort this array : " << endl ;
	
	third = sort(keys, values, third, len);// Возвращаем указатель на измененную структуру с уже отсортированными элементами
	for (int i = 0; i < len; i++) //выводим итог
		cout<<*third[i].k<<" "<<*third[i].v<<endl;


	free(keys); free(values); free(third); // Освобождаем память
	system("pause");
	return 0;
}
