#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StaticArray.h"
#include "LinkedDeque.h"
#include <ctime>
#include <string>
using namespace std;

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	Stack<double> stack(15.4);

	stack.Push(15.15);
	stack.Push(15.7);
	stack.Push(15.3);
	stack.Push(15.9);
	stack.Push(15.14);
	cout << stack << endl;
	Stack<double> a;
	a = stack;
	cout << a << endl;
	stack.SelectionSort();
	cout << stack << endl;
	LinkedDeque<double> linked_d(1.5);
	linked_d.PushFront(1.7);
	linked_d.PushBack(1.4);
	linked_d.PushFront(1.3);
	linked_d.PushBack(1.8);
	linked_d.PushFront(1.1);
	LinkedDeque<double> s1(linked_d);
	cout << linked_d << endl;
	cout << s1 << endl;

	StaticArray<string>stat(10,"a");
	stat.Set(6, "b");
	cout<<stat.Get(6);
	cout << stat;

	LinkedList<int> lst;
	lst.Push(6);
	cout << lst;

	Queue<int> que;
	for (int i = 0; i < 10; i++)
		que.Push(rand() % 101);
	que.SelectionSort();
	cout << endl << que << endl;

	LinkedList<string>linklist;

	linklist.Push("dd");
	linklist.Push("a");
	linklist.Push("s");
	linklist.Push("you");
	//linklist.Remove(1);
	cout << linklist << endl;
	linklist.SelectionSort();
	
	cout << linklist;





	system("pause");
}
