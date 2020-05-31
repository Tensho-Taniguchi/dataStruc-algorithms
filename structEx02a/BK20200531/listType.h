#ifndef A_CLASS
#define A_CLASS


const int MAX = 100;

class listObj {
private:
	int aList[MAX];
	int lastIndex;
public:
	void initL();
	bool addL(int x);
	void displayL();
	bool emptyL();
	bool deleteL(int itemToDelete);
	int searchL(int key);
	bool isFull();
	void clearL();
};

#endif