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
void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (l.tail == q)
			l.tail = p;
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
Node* Search(LinkedList l, int x)
{
	Node* node = l.head;
	while (node != NULL && node->data != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}
void DeleteAllNodes(LinkedList& l)
{
    Node* current = l.head;
    Node* next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    l.head = l.tail = NULL;
}

int main() {
    LinkedList list;
    CreateList(list); 
    int array[8] = {8, 7, 9, 1, 2, 12, 10, 4};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        {
            Node* node = CreateNode(array[i]);
            AddTail(list, node);
        }
    cout << "Da tao thanh cong day tren" << endl;
    PrintList(list);
    cout <<"*************************"<<endl;

    
    cout << "Xin moi lua chon sau: " << endl;
    cout << "1. Tim phan tu trong day" << endl;
    cout << "2. Them phan tu vao trong day." << endl;
    cout << "3. Xoa phan tu trong day" << endl;
    cout << "4. Xoa tat ca phan tu." << endl;

    int option;
    cout << "Xin moi nhap option: ";
    cin >> option;

    switch (option)
    {
        case 1: 
        {
            cout << "Xin moi nhap phan tu can tim kiem: ";
            int x;
            cin >> x;
            Node* searchNode = Search(list, x);
            if (searchNode != NULL)
            {
                    cout << "Phan tu " << x << " DUOC tim thay trong danh sach." << endl;
            }
            else
            {
                    cout << "Phan tu " << x << " KHONG co trong danh sach." << endl;
            }
            break;
        }
        case 2:
        {
            int z,x;
            cout << "Xin moi nhap vi tri can them vao: "<<endl;
            cin >> x;
            Node* searchNode = Search(list, x);
            cout << "Xin moi nhap phan tu can them vao: "<<endl;
            cin >> z;
            Node* nodez = CreateNode(z);
            InsertAfterQ(list,nodez,searchNode);
            cout << "List sau khi them "<< z << " sau "<< x << endl;
            PrintList(list);
            break;
        }
        case 3:
        {
            int x;
            cout << "xin moi nhap vi tri can xoa: "<<endl;
            cin >> x;
            Node* searchNode = Search(list, x);
            int RemoveNode;
            RemoveAfterQ(list,searchNode,RemoveNode);
            cout <<"So node bi xoa "<< RemoveNode <<endl;
            cout << "List sau khi xoa "<<endl;
            PrintList(list);
            break;
        }
        case 4:
        {
            DeleteAllNodes(list);
            cout << "Da xoa tat ca phan tu cua danh sach." << endl;
            break;
        }
        default:
            cout << "Lua chon khong hop le, vui long chon lai." << endl;
            break;
    }
    return 0;
}
