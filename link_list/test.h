/*
 *	link list structure
 */

typedef struct Student{
	int data;
	struct Student *next;
}Stu;


/*
 *	initailize list
 */

int init();			//decide how many nodes in list
int* list_data(int);		//input node data
Stu *createList(int*,int);	//create list

/*
 *	some function interact with list
 */

Stu *searchNode(Stu*,int);	//input data and print address of the node
Stu *reverse(Stu*);		//reverse list
Stu *insertNode(Stu*,int,int);	//push back or front
void printNode(Stu*);		//print list

/*
 *	clear
 */
void freeList(Stu*);
