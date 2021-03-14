#include <iostream>
using namespace std;

class Objects {
public:
	Objects() {
		cout << "Objects()" << endl;
	}
	virtual ~Objects() {
		cout << "~Objects()" << endl;
	}
	virtual void AB() {}
};

class A: public Objects {
protected:
	int a;
public:
	A() {
		cout << "A()" << endl;
		a = 1;
	}
	A(int _a) {
		cout << "A(int _a)" << endl;
		a = _a;
	}
	A(const A& s) {
		cout << "A(const A& s)" << endl;
		a = s.a;
	}
	~A() {
		cout << "~A()" << endl;
	}
	void AB() {
		cout << "a= " << a << endl;
	}
};

class B: public Objects {
protected:
	int b;
public:
	B() {
		cout << "B()" << endl;
		b = 2;
	}
	B(int _b) {
		cout << "B(int _b)" << endl;
		b = _b;
	}
	B(const B& s) {
		cout << "B(const B& s)" << endl;
		b = s.b;
	}
	~B() {
		cout << "~B()" << endl;
	}
	void AB() {
		cout << "b= " << b << endl;
	}
};

class MyStorage {
protected:
	Objects** objs;
	int size;
	int c; 
public:
	MyStorage(int size) {
		objs = new Objects * [size];
		for (int i = 0; i < size; i++) {
			objs[i] = NULL;
		}
		this->size = size;
		c = 0;
	}
	void setObject(int i, Objects* SomeObject) {
		if (i < size && objs[i] == NULL)
			objs[i] = SomeObject;
		    c++;
	}
	Objects* getObject(int i) {
		if (i < size && objs[i] != NULL)
			return objs[i];
	}
	void delOblect(int i) {
		if (i < size && objs[i] != NULL)
			objs[i] = NULL;
		    c--;
	}
	int getSize() {
		return size;
	}
	void resize(int newSize) {
		Objects** new_objs = new Objects * [newSize];
		for (int i = 0; i < size; i++) {
			new_objs[i] = objs[i];
		}
		for (int i = size; i < newSize; i++) {
			new_objs[i] = NULL;
		}
		size = newSize;
	}
};

int main(){

	MyStorage storage(10);

	for (int i = 0; i < storage.getSize(); i++)
		if (rand() % 2 == 0)
			storage.setObject(i, new A());
		else
			storage.setObject(i, new B());

	for (int i = 0; i < storage.getSize(); i++)
		storage.getObject(i)->AB();
}