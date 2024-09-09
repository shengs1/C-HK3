#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
struct LinkedList
{
	Node* head;
	Node* tail;
};
Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}
void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}   
void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}
void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}
int RemoveAfterQ(LinkedList& l, Node* q, int& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next;
		}
	}
    cout <<endl;
}
Node* GetNode(LinkedList& l, int index)
{
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}
Node* Search(LinkedList l, int x)
{
	Node* node = l.head;
	while (node != NULL && node->data != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

int main() {
    cout<<"Task 1"<<endl;
    LinkedList list;
    CreateList(list);
    Node* node;
    int n[7] ={13,11,9,7,5,3,1} ;
    for (int i = 0; i < 7; i++)
	{
		node = CreateNode(n[i]);
	
		AddTail(list, node);
	}
	cout <<"Danh sach node ban dau"<<endl;
    PrintList(list);
    cout<<endl;
    
    cout<<"Task 2"<<endl;
    cout <<"Danh sach node them 2 vao dau"<<endl;
    Node* Node2 = CreateNode(2);
    AddHead(list, Node2);
    PrintList(list);
    cout<<endl;

    cout<<"Task 3"<<endl;
    cout <<"Danh sach node them 8 vao cuoi"<<endl;
    Node* Node8 = CreateNode(8);
    AddTail(list, Node8);
    PrintList(list);
    cout<<endl;

    cout<<"Task 4"<<endl;
    Node* NodeMid = GetNode(list,4);
    if (NodeMid != NULL)
		cout << "Node o giua la: " << NodeMid->data << endl;
    cout<<endl;


    int x = 11;
    Node* searchNode = Search(list,x);
	//if (searchNode != NULL)
		//cout <<"So "<<x<<" Co trong danh sach" << endl;
	//else    
		//cout << "Not Found" << endl;
    cout<<"Task 5"<<endl;
    int RemoveNode;
	int result = RemoveAfterQ(list, searchNode, RemoveNode);
	if (result)
	{
		cout << "So node bi xoa: " << RemoveNode << endl;
		cout << "List sau khi xoa: ";
		PrintList(list);
		cout << endl;
	}
	else
		cout << "Nothing is removed" << endl;
    cout<<endl;


    return 0;
}