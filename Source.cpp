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
	/*LinkedList *my_lst = new LinkedList();*/
	/*cout << "Is Empty: " << my_lst->IsEmpty() << "\n";
	for (int i = 0; i < 10; i++)
	my_lst->Insert(i, i);
	cout << my_lst->ToString() << "\nSize: " << my_lst->Size() << "\nIs Empty: " << my_lst->IsEmpty() << "\n";
	my_lst->Insert(5, 21);
	cout << my_lst->ToString()<< "\nSize: " << my_lst->Size() << "\nIs Empty: " << my_lst->IsEmpty() << "\n";
	my_lst->Remove(5);
	cout << my_lst->ToString() << "\nSize: " << my_lst->Size() << "\nIs Empty: " << my_lst->IsEmpty() << "\n";
	for (int i = 0; i < 10; i++)
	cout << my_lst->Get(i) << " ";
	cout << "\n";
	for (int i = 0; i < 10; i++) {
	my_lst->Set(i, 7);
	cout << my_lst->ToString() << "\n";
	}
	for (int i = 0; i < 10; i++)
	cout << my_lst->Pop() << "\n";
	cout << my_lst->ToString()<< "\nSize: " << my_lst->Size() << "\n";*/

	/*Queue*my_que = new Queue();
	cout << "Is Empty: " << my_que->IsEmpty() << "\n";
	for (int i = 0; i < 10; i++)
	my_que->Push(i);
	cout << my_que->Pop() << "\n";
	cout << my_que->Peek()<< "\n";
	cout << my_que->ToString().c_str() << "\nSize: " << my_que->Size() << "\n";
	StaticArray* my_Arr = new StaticArray (10,6);
	cout << my_Arr->ToString() << "\nSize: " << my_Arr->Size() << "\nIs Empty: " << my_Arr->IsEmpty() << "\n";
	for (int i = 0; i < 10; i++)
	cout << my_Arr->Get(i) << " ";
	cout << "\n";
	my_Arr->Set(6, 7);
	cout << my_Arr->ToString() << "\nSize: " << my_Arr->Size() << "\n";*/
	/*PushPopContainer *elem[3];
	elem[0] = new Stack();
	elem[1] = new Queue();
	elem[2] = new LinkedList ();

	for (int i = 0; i < 3; i++)
	{
	elem[i]->Push(1);
	cout << elem[i]->ToString() << "\n";

	elem[i]->Push(2);
	cout << elem[i]->ToString() << "\n";
	elem[i]->Push(3);
	cout << elem[i]->ToString() << "\n";


	}*/
	/*for (int i = 0; i < 3; i++)
	{
	elem[i]->Pop();
	cout<< elem[i]->ToString() <<"\n";
	}*/
	/*Container<int> *elem[3];
	elem[0] = new Stack<int>();
	elem[1] = new StaticArray<int>(5, 0);
	elem[2] = new LinkedList<int>();
	for (int i = 0; i < 3; i++)
	{
		InsertableContainer<int> *Insertable = dynamic_cast <InsertableContainer<int>*>(elem[i]);
		if (Insertable != NULL)
		{
			if (Insertable->Insert(1, 10))
				cout << "Inserted!" << endl;
			else
				cout << "Error" << endl;
			cout << Insertable->ToString().c_str() << endl;
			Insertable->Insert(1, 10);
			cout << "!" << Insertable->ToString() << endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		IndexedContainer<int> *Indexed = dynamic_cast <IndexedContainer<int>*>(elem[i]);
		if (elem[i]->Size() < 4)
		{
			continue;
		}
		if (Indexed != NULL)
		{
			cout << Indexed->Get(3) << endl;
			Indexed->Set(3, 20);
			cout << Indexed->Get(3) << endl;
		}
	}
	Deque<int> *deque = new LinkedDeque<int>();
	for (int i = 0; i < 5; i++)
	{
		deque->PushBack(i);
		deque->PushFront(i);
		cout << "*" << deque->ToString() << endl;
	}
	while (!deque->IsEmpty())
	{
		cout << deque->PopBack() << endl;
	}
*/
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