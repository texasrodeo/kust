// kustList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <cstddef>
#include <iostream>
using namespace std;

struct list
{
	int value;
	struct list* next;
};
list* init(int a)
{
	list* lst;
	

	lst = new list;
	lst->value = a;
	lst->next = NULL;
	return(lst);
};

list* add(list* lst, int a)
{
	list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;
	list* newlst;
	newlst = new list;
	newlst->value = a;
	newlst->next = NULL;
	p->next = newlst;
	return(lst);
};

void print(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->value); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != NULL);
}



list* swap(list* lst1, list* lst2, list* head)
{
	// Возвращает новый корень списка
	struct list* prev1, * prev2, * next1, * next2;
	prev1 = head;
	prev2 = head;
	if (prev1 == lst1)
		prev1 = NULL;
	else
		while (prev1->next != lst1) // поиск узла предшествующего lst1
			prev1 = prev1->next;
	if (prev2 == lst2)
		prev2 = NULL;
	else
		while (prev2->next != lst2) // поиск узла предшествующего lst2
			prev2 = prev2->next;
	next1 = lst1->next;  // узел следующий за lst1
	next2 = lst2->next;  // узел следующий за lst2
	if (lst2 == next1)
	{                       // обмениваются соседние узлы
		lst2->next = lst1;
		lst1->next = next2;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else
		if (lst1 == next2)
		{
			// обмениваются соседние узлы
			lst1->next = lst2;
			lst2->next = next1;
			if (lst2 != head)
				prev2->next = lst2;
		}
		else
		{
			// обмениваются отстоящие узлы
			if (lst1 != head)
				prev1->next = lst2;
			lst2->next = next1;
			if (lst2 != head)
				prev2->next = lst1;
			lst1->next = next2;
		}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}


list* getMax(list* head) { //ищем узел с макс значением
	list* max = head;
	list* tmp = head;
	do {
		if (tmp->value > max->value) {
			max = tmp;
		}
		tmp = tmp->next; // переход к следующему узлу
	} while (tmp != NULL);
	return max;
}

list* getFirstNegativeNumber(list* head) { //получаем первый отрицательный
	
	list* tmp = head;
	while (tmp->value >= 0)
		tmp = tmp->next;
	return tmp;
}

int getRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

list* generateRandomList(int count, int min, int max) //count -кол-во элементов, min и max - нижняя и верхняя границы рандома
{
	list* list = init(getRandomNumber(min, max));
	for (int i = 1; i < count; i++) {
		add(list, getRandomNumber(min, max));
	}
	return list;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int len, min, max;
	cout << "Введите количество элементов списка, нижнюю и верхнюю границы случайных чисел для элементов списка. Список будет сгенерирован автоматически" << endl;
	cout << "Кол-во элементов" << endl;
	cin >> len;
	cout << "Нижняя граница" << endl;
	cin >> min;
	cout << "Верхняя граница" << endl;
	cin >> max;	
	list* myList = generateRandomList( len, min, max);
	print(myList);
	cout << endl;
	list* maxElement = getMax(myList);
	list* firstNegative = getFirstNegativeNumber(myList);
	myList = swap(maxElement, firstNegative, myList);
	print(myList);

	cin.get();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
