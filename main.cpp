#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *previous;
};
class doublyLinkedList
{
    private:
        node* first;
        node* last;
        int counter;
    public:
	doublyLinkedList()
	{
		first = NULL;
		last = NULL;
		counter = 0;
	}
	bool isEmpty()
	{
		return (first == NULL);
	}
	int getActualSize()
	{ return counter; }
	void destroyList()
	{
		node *temp;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
		last = NULL;
		counter = 0;
	}
	void addLast(int dd)
	{
		node *temp = new node;
		temp->data = dd;
		if (counter == 0)
        {
			first = last = temp;
            temp->next = temp->previous = NULL;
        }
		else
        {
			temp->next = NULL;
			temp->previous = last;
			last->next = temp;
			last = temp;
		}
		counter++;
	}
	void addFirst(int dd)
	{
		node*temp = new node;
		temp->data = dd;
		if (counter == 0)
        {
			first = last = temp;
			temp->next = temp->previous = NULL;
		}
		else
        {
			temp->next = first;
			temp->previous = NULL;
			first->previous = temp;
			first = temp;
		}
		counter++;
	}
	void addIndex(int pos, int dd)
	{
		if (pos < 0 || pos > counter)
			cout << "Error, you are inserting out of the range" << endl;
		else
		{
			node *temp = new node;
			temp->data = dd;
			if (pos == 0)
				addFirst(dd);
			else if (pos == counter)
				addLast(dd);
			else
			{
				node *current = first;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
				temp->next = current->next;
				temp->previous = current;
				current->next->previous = temp;
				current->next = temp;
				counter++;
			}
		}
	}
	void deleteFirst()
	{
		if (counter == 0)
			cout << "Error, you want to delete from empty list" << endl;
		else if (counter == 1)//first == last
		{
			delete first;
			last = first = NULL;
		}
		else
		{
			node *current = first;
			first = first->next;
			first->previous = NULL;
			delete current;
		}
		counter--;
	}
	void deleteIndex(int pos)
	{
		if (pos < 0 || pos >= counter)
        {
			cout << "Error, you are deleting out of the range" << endl;
			return;
		}
		else if (pos == 0)
		{
			deleteFirst();
		}
		else if (pos == counter - 1)
		{
			deleteLast();
		}
		else
		{
			node *current = first->next;
			for (int i = 1; i < pos; i++)
			{
				current = current->next;
			}
			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
		}
		counter--;
	}
	void deleteLast()
	{
		if (counter == 0)
			cout << "Error, you want to delete from empty list" << endl;
		else if (counter == 1)
		{
			delete first;  //delete last;
			last = first = NULL;
			counter--;
		}
		else
		{
			node *current = last;
			last = last->previous;
			last->next = NULL;
			delete current;
			counter--;
		}
	}
	void printDoublyLinkedList()
	{
		if (isEmpty())
		{
			cout << "Error, you cannot print an empty list";
		}
		else
        {
			node *temp = first;
			while (temp != nullptr)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
		}
		cout << endl;
	}
	void reverse_printDoublyLinkedList()
	{
		if (isEmpty())
		{
			cout << "Error, you cannot print an empty list";
		}
		else
		{

			node *temp = last;
			while (temp != NULL) {
				cout << temp->data << "\t";
				temp = temp->previous;
			}
		}
		cout << endl;
	}
	void searchList(int dd)
	{
	    if (isEmpty())
		{
			cout << "Error, you are searching in an empty list";
		}
		else
        {
            bool exists = false;
			node *temp = first;
			while (temp != nullptr)
			{
				if (temp->data == dd)
                    {
                        exists = true;
                        break;
                    }
                    temp = temp->next;
			}
			if (exists == true)
                cout<<dd<<" exists in the doubly linked list";
            else
                cout<<dd<<" does not exist in the doubly linked list";
		}

		cout << endl;
	}
	void insertSorted(int dd)
	{
	    int pos=0;
	    node *current;
	    current = first;
        node *temp = new node;
        temp->data = dd;
        if (counter == 0)
        {
			first = last = temp;
			temp->next = temp->previous = NULL;
		}
		else
        {
            sortList();
			while(temp->data > current->data)
            {
                pos++;
                current = current->next;
            }
            addIndex(pos,dd);
		}
		cout<<"The sorted doubly linked list after inserting an element is:\n";
            printDoublyLinkedList();
	}
	void sortList()
	{
	    if (isEmpty())
		{
			cout << "Error, you you want to sort an empty list";
		}
		else
        {
            node *i , *j ;
			int dd;
			for( i=first ; i->next != NULL ; i=i->next )
            {
                for( j=i->next ; j != NULL ; j=j->next )
                {
                    if( i->data > j->data )
                    {
                        dd = j->data;
                        j->data = i->data;
                        i->data = dd;
                    }
                }
            }
        }
	}
};

int main()
{
	doublyLinkedList dl;
	dl.addIndex(0,10);
	dl.addIndex(1,20);
	dl.addIndex(2,100);
	dl.addFirst(50);
	dl.addLast(85);
	cout<<"The doubly linked list is:\n";
	dl.printDoublyLinkedList();
	cout<<"The reverse doubly linked list is:\n";
	dl.reverse_printDoublyLinkedList();
	dl.insertSorted(60);
	cout<<"The size of this doubly linked list: "<<dl.getActualSize()<<"\n";
	dl.searchList(100);
	dl.searchList(150);
}
