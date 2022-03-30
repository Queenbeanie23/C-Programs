#include "pch.h"
#include <iostream>
#include <string>
#include <fstream> //header file for file handling system
using namespace std;

template <typename K, typename V>

class HashNode{
public:
	V value;
	K key;

	HashNode(K key, V value) {
		this->value = value;
		this->key = key;

	}

};
template <typename K, typename V>
class Hashtable {
	HashNode<K, V>** arr;
	int size;
	int count;

public:
	Hashtable(int s) {
		count = 0;
		size = s;
		arr = new HashNode<K, V>*[size];

		for (int i = 0; i < size; i++)
			arr[i] = NULL;

	}

	int hashIn(int n) {
		return n % size;


	}
	int insertItem(K key, V value) {
		if (count == size) {
			cout<< "table is full";
			return 0;
		}
		

		int hashindex = hashIn(key);
		int pcounter = 0;
		while (arr[hashindex] != NULL) {
			hashindex = (hashindex+1) % size;
			pcounter++;
		}
		arr[hashindex] = new HashNode<K, V>(key, value);
		arr[hashindex] ->key = key;
		arr[hashindex]->value = value;
		count++;
		cout << pcounter << endl;
		return pcounter;


}
	bool isEmpty() {
		return size == 0;
	}
	int sizeofMap()
	{
		return size;
	}
	V deleteItem(int key) {

		int hashindex = hashIn(key);
		int temp = hashindex;

		while (true) {
			if (arr[hashindex] == NULL)
				hashindex =( hashindex +1) % size;
			else if (arr[hashindex]->key != key)
				hashindex = (hashindex +1) % size;
			else

				break;

			if (hashindex == temp) {
				temp = -1;
				break;
			}

		}

		V save;
		if (temp == -1)
			cout << "Not found";
		else {

			save = arr[hashindex]->value;
			delete arr[hashindex];
			arr[hashindex] = NULL;
			count--;

		}
		return save;



	}
	V getItem(int key) {
	
		int hashindex = hashIn(key);
		int temp = hashindex;

		while (true) {
			if (arr[hashindex] == NULL)
				hashindex = (hashindex +1) % size;
			else if (arr[hashindex]->key != key)
				hashindex =  (hashindex +1 ) % size;
			else

				break;

			if (hashindex == temp) {
				temp = -1;
				break;
			}

		}
		if (temp == -1)
			cout << "Not found";
		else {
			return arr[hashindex]-> value;

		}

	}
	void display()
	{
		for (int i = 0; i < size; i++) {
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key
				<< "  value = "
				<< arr[i]->value << endl;
		}
	}

		

};


TEST(Hash, LinearProbing1)
{
	Hashtable <int,  string >* h = new Hashtable<int, string>(12);

	h->insertItem(6, "James");
	h->insertItem(12,"Alex");
	h->insertItem(12, "Clifford");

	h->display();

	EXPECT_EQ(0, h->isEmpty());
	EXPECT_EQ(12, h->sizeofMap());
	EXPECT_EQ("James", h->getItem(6));
	EXPECT_EQ("Alex", h->getItem(12));
	EXPECT_EQ("James", h->deleteItem(6));


}
TEST(Hash, LinearProbing2) {

	Hashtable <int, string >* h = new Hashtable<int, string>(11);


	h->insertItem(52, "Alex");
	h->insertItem(34, "Clifford");
	h->insertItem(90, "Carr");
	h->insertItem(14, "Jason");
	h->insertItem(87, "Chris");
	h->insertItem(62, "luke");
	h->insertItem(42, "Eric");
	h->insertItem(2, "Nader");
	h->insertItem(100, " Jessica");
	h->insertItem(3, "Purple");


	EXPECT_EQ(0, h->isEmpty());
	EXPECT_EQ(11, h->sizeofMap());
	EXPECT_EQ("Purple", h->getItem(3));
	EXPECT_EQ("Clifford", h->deleteItem(34));
	EXPECT_EQ(5, h->insertItem(72, "Sam"));


}
