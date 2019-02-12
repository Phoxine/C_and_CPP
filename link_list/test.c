#include<stdio.h>
#include<stdlib.h>
#include"test.h"

/*
 *	This program is a link list example and implements some function
 *	
 *	like create list, search node, insert node, free list etc.
 *
 *	author : peterchao
 */


/*
 *	function for creating a list
 */
Stu *createList(int *arr, int len){

	Stu *current, *first, *previous;

	for(int i=0; i<len; i++){
		// create new node and current point to this node
		current = (Stu*) malloc(sizeof(Stu)); 
		current-> data = arr[i];
		if(i == 0){	
			//pointer first to current node if the node is first node for link list
			first = current; 
		}else{
			// for example i = 1 previous will point to the node when i = 0
			previous->next = current;
		}
		current->next=NULL;
		previous = current;
	}
	printf("Create List Done\n");
	return first; //return address of first node
}	

/*
 *	function for User to input data numbers
 */
int init(){
	int count;
	printf("Input how many nodes that you want to create\n");
	scanf("%d",&count);// decide how many nodes will be created
	return count;
}

/*
 *	function for User to input node data
 */
int* list_data(int length){
	printf("Input date fo those %d nodes\n",length);
	int *arr = (int*)malloc(length);
	for (int i = 0 ; i < length ; i++){
		int value;
		printf("Node %d:\n",i+1);
		scanf("%d",&value);
		arr[i] = value;
	}
	return arr;
}
/*
 *	function for printing whole list
 */
void printList(Stu *node){
	while(node!=NULL){
		printf("address = %p\t",node);
		printf("data = %d\t",node->data);
		printf("next = %p\n",node->next);
		node = node->next;
	}
	printf("----------------------------\n");
}
/*
 *	fucntion for free memory
 */
void freeList(Stu * node){
	Stu * current, *tmp;
	current = node;
	while(current !=  NULL){
		tmp = current;
		current = current->next;
		free(tmp);
	}
	printf("Free List Done\n");
}

/*
 *	function for searching node
 */
Stu *searchNode(Stu *node, int data){
	Stu *search;
	search = node;
	while(search != NULL){
		if(search->data == data){
			return search;
		}else{
			search = search->next;
		}
	}
	return NULL;
}
/*
 *	fucntion for inserting node
 */
Stu* insertNode(Stu *node,int data_insert,int push){
	
	
	Stu *insert,*first = node;
	int data;
	insert = (Stu*) malloc(sizeof(Stu));
	printf("Input new node data\n");
	scanf("%d",&data);


	if(push == 1){
		node = searchNode(node,data_insert);
		if(node == NULL){
			printf("NULL node\n");
			return first;
		}
		insert->data = data;
		insert->next = node->next;
		node->next = insert;
		return first;
	}else if(push == 2){
		
		if(node->data == data_insert){
			insert->data = data;
			insert->next = node;
			return insert;
		}else{

			Stu *search;
			search = node;
			while(search->next != NULL){
				if(search->next->data == data_insert){
					node = search;
					insert->data = data;
					insert->next = node->next;
					node->next = insert;
					return first;
				}else{
					search = search->next;
				}
			}
			printf("NULL node\n");
			return first;
		}
	}
}
/*
 *	function for reversing list
 */
Stu *reverse(Stu *node){
	Stu *previous = NULL, *current = node, *preceding = node->next;

	while(preceding != NULL){
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = current->next;
	}
	current->next = previous;
	printf("reverse list done\n");
	return current;

}


/*
 *	main fucntion
 */
int main(){	
	Stu *test;
	
	//first user input
	int numbers = init();
	//second user input
	test = createList(list_data(numbers),numbers);
	printf("----------------------------\n");
	printList(test);
	
	int num=0,data_search,data_insert,push;
	while(num != -1)
	{
		printf("Input number to call function (1 : searchNode, 2 : insertNode, 3 : printList, 4 : reversedList, -1 : exit):\n");
		scanf("%d",&num);
		if(num == 1 || num == 2 || num == 3 || num == 4){
			switch(num){
				case 1:
					printf("Input Node data\n");
					scanf("%d",&data_search);
					printf("%p\n",searchNode(test,data_search));			
					break;
				case 2:
					printf("push back(1) or front(2)\n");
					scanf("%d", &push);
					if(push != 1 && push != 2){
						printf("Wrong option\n");
						break;
					}
					printf("Input Node data\n");
					scanf("%d" ,&data_insert);
					test = insertNode(test,data_insert,push);	
					break;
				case 3:
					printList(test);
					break;	
				case 4:
					test = reverse(test);
					break;
			}
		}else if(num!=-1){
			printf("Wrong option\n");
		}
	}	

	freeList(test);
	return 0;
}
