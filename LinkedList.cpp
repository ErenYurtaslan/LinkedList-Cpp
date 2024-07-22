#include <iostream>
using namespace std;




class Node {
public:
	int deger;
	Node* ptrNext;

	Node(int deger) {
		this->deger = deger;
		ptrNext = NULL; 
	}
};


class LinkedList {
private:
	Node* ptrHead;
	Node* ptrTail;
	int lengthLL;
public:
	LinkedList(int deger) {
		Node* node = new Node(deger);
		ptrHead = node;
		ptrTail = node;
		lengthLL = 1;
	}

	~LinkedList() {
		cout << "destructor çaðrýldý" << endl;
		Node* ptrTmp = ptrHead;
		while (ptrHead) {
			ptrHead = ptrHead->ptrNext;
			delete ptrTmp;
			ptrTmp = ptrHead;
		 }
	}


	void printHead() {
		if (ptrHead != NULL) cout <<"Head: " << ptrHead->deger << endl;
	}
	void printTail() {
		if (ptrTail != NULL) cout <<"Tail: " << ptrTail->deger << endl;
	}
	void getlengthLL() {
		cout << "Length of LinkedList: " << this->lengthLL << endl;
	}

	void appendList(int deger) {
		Node* node = new Node(deger);

		if (lengthLL==0) {
			ptrHead = node;
			ptrTail = node;
		}
		else {
			ptrTail->ptrNext = node;
			ptrTail = node;
		}
		lengthLL++; 
	}

	void printAll() {
		Node* ptrTmp = ptrHead;
		cout << "LinkedList düðümleri: ";
		while (ptrTmp != NULL) {
			if(ptrTmp->ptrNext != NULL){
				cout << ptrTmp->deger << ", ";
			}
			else {
				cout << ptrTmp->deger;
			}
			
			ptrTmp = ptrTmp->ptrNext; 
		}
		cout << endl;
	}

	void deleteLast() {

		if (lengthLL == 0) return;

		Node* temp1 = ptrHead;
		Node* temp2 = ptrHead;

		while (temp1->ptrNext) {
			temp2 = temp1;
			temp1 = temp1->ptrNext;
		}

		ptrTail = temp2;
		ptrTail->ptrNext = NULL;
		lengthLL--;
		if (lengthLL==0)
		{
			ptrHead = NULL;
			ptrTail = NULL;
		}//eðer silme iþleminden sonra liste tamamen boþalýrsa pointerlarý boþa çýkarýyoruz.
		delete temp1; 
	}

	void addFirst(int deger) {
		Node* node = new Node(deger);

		if (lengthLL == 0) {
			ptrHead = node;
			ptrTail = node;
		}
		else {
			node->ptrNext = ptrHead;
			ptrHead = node;
		}
		lengthLL++;
	}


	void deleteFirst() {
		if (lengthLL == 0) return;

		Node* temp = ptrHead;
		if (lengthLL == 1) {
			ptrHead = NULL;
			ptrTail = NULL;
		}
		else {
			ptrHead = ptrHead->ptrNext;
		}
		delete temp;
		lengthLL--;
	}

	Node* getNode(int index) {
		if (index < 0 || index >= lengthLL) return NULL;//index yoksa null atar.

		Node* temp = ptrHead;
		for (int i = 0; i < index; i++) {
			temp = temp->ptrNext;//düðüme index verdik. index deðerini girince o düðümün deðeri bize dönecek.
		}
		return temp;
	}

	bool setValue(int index, int newValue) {
		Node* temp = getNode(index);
		if (temp != NULL) { temp->deger = newValue; return true; }

		return false;

	}

	bool insertNode(int index, int value) {
		if (index<0 || index>lengthLL) {
			return false;
		}else if(index==0){
			addFirst(value);
			return true;
		}else if (index==lengthLL) {
			appendList(value);
			return true;
		}else {
			Node* newNode = new Node(value);
			Node* temp = getNode(index - 1);
			newNode->ptrNext = temp->ptrNext;
			temp->ptrNext = newNode; 
			lengthLL++;
			return true;
		}
	}


	void deleteAnyNode(int index) {
		if (index >= 0 && index < lengthLL) {
			if (index == 0) {
				deleteFirst();
			}
			else if (index==lengthLL-1) {
				deleteLast();
			}
			else {
				Node* ptrDel = getNode(index); 
				Node* temp = getNode(index-1);

				temp->ptrNext = ptrDel->ptrNext;
				delete ptrDel;

				lengthLL--;

			}
		}
		else {
			cout << "Index deðeri kapasite dýþý." << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Turkish");
	LinkedList* list1 = new LinkedList(12);
	list1->appendList(5);
	list1->appendList(78);
	list1->appendList(31);
	list1->appendList(66);

	list1->getlengthLL();
	list1->printHead();
	list1->printTail();

	list1->printAll(); 
	list1->deleteLast();
	list1->printAll();  

	list1->addFirst(43);
	list1->printAll();

	list1->deleteFirst();
	list1->printAll();

	Node* sonuc = list1->getNode(0);
	if (sonuc != NULL) cout << sonuc->deger << endl<<endl; 
	else cout << "Boundary condition error!" << endl<<endl; 

     
	if (list1->setValue(1 , 34)) {
		cout << "Eleman deðiþtirme baþarýlý" << endl;
	}
	else {
		cout << "Index'i kontrol ediniz!" << endl;
	}
	
	list1->printAll(); 
	
	cout << endl; 
	

	if (list1->insertNode(4, 858)) {
		cout << "Eleman ekleme baþarýlý" << endl;
	}
	else {
		cout << "Index'i kontrol ediniz!" << endl;
	}

	list1->printAll(); 
	cout << endl; 

	list1->deleteAnyNode(28);

	list1->printAll(); 


	
	cout << endl;
	delete list1;
}
