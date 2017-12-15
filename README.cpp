# Dynamic_array
Creation of dynamic array using pointers

#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

struct NewMass
{
	int * k, * v;
};
 
 

int main()
{
	int len = 0; //Начальная длина
	cout << " Write number of keys $ values " << endl;
	cin >> len;
	cout << " Your array is: " << endl;

	int * keys = (int*)malloc(len*sizeof(int)); 
	int * values = (int*)malloc(len*sizeof(int));
	struct NewMass * third = (NewMass*)malloc(len*sizeof(NewMass));
	if (keys == NULL) return (1);
	if (values == NULL) return (1);

	for (int i = 0; i < len; i++) //заполнение массива
	{
		keys[i] = rand() % 50;
		values[i] = rand() % 50;
		third[i].k = &keys[i];
		third[i].v = &values[i];
	}
	for (int i = 0; i < len; i++) //вывод массива
		cout<<*third[i].k<<" "<<*third[i].v<<endl;

	cout<<" Lets add an element "<<endl;
	int input;
	len++;
	cout<<" Enter key: ";
	cin>>input;
	keys = (int*)realloc(keys, len * sizeof(int));
	keys[len - 1] = input;
	cout<<" Enter value: ";
	cin>>input;
	values = (int*)realloc(values, len * sizeof(int));
	values[len - 1] = input;

	third = (NewMass*)realloc(third, len * sizeof(NewMass));
	for (int i = 0; i < len; i++) //заполнение массива с новым элементом
	{
		third[i].k = &keys[i];
		third[i].v = &values[i];
	}

	for (int i = 0; i < len; i++) //вывод
		cout<<*third[i].k<<" "<<*third[i].v<<endl;

	cout << " Lets sort this array : " << endl ; //Сортировка
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (*third[j + 1].k < *third[j].k)
			{
				struct NewMass tmp = third[j + 1];
				third[j + 1] = third[j];
				third[j] = tmp;
			}
		}
	}

	for (int i = 0; i < len; i++) //вывод
		cout<<*third[i].k<<" "<<*third[i].v<<endl;


	free(keys); free(values); free(third); 
	system("pause");
	return 0;
}
