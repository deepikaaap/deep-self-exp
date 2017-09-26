// The following code is your starting point for PROG8130 Assignment #1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// structure/typedef used for holding data
typedef struct {
	char name[30];
	int index;
} inputData;
    int head_index, k, j=0;
	char repeat[30];
	inputData added[5];
// definition of linked list data nodes
typedef struct LinkedListNode {
	struct LinkedListNode		*ptrNextNode;		// pointer to next node in list (NULL if the end)
	char						NameData[30];		// the name to be stored (no need to store index)
} LinkedListNodeDef;

// prototypes
void AddToLinkedList(LinkedListNodeDef **ptrHead, char *NameData, int DataIndex);
void PrintLinkedList(LinkedListNodeDef *ptrHead);


// make the data positions the last 5 digits of student number
// for example if my student number ended in 94330 the data will be as supplied
inputData iData[5] = {
        { "fish", 2 },
        { "airplane", 1 },
        { "chocolate", 1 },
        { "orange", 3 },
        { "pickels", 2 }
};

// data used for test
// paste the data here that was created by Prog8130Assign1DataCreator.exe

int main(){
	int i;
	// define linked list head
	struct LinkedListNode		*ptrHead = NULL;
	
	// Print out the input data
	printf("Data before Linked List is:\n");
	for (i = 0; i < 5; i++)
		printf("%s , %d\n", iData[i].name, iData[i].index);

	// insert the data into Linked List
	for (i = 0; i < 5; i++)
		AddToLinkedList( &ptrHead, iData[i].name, iData[i].index);
	// now print out the list in order it is stored starting at head
	PrintLinkedList(ptrHead);
}

// fill in this function to add linked list nodes to provided index location
void AddToLinkedList(LinkedListNodeDef **ptrHead, char *NameData, int DataIndex){
	// you need to add the code to put the NameData string into the linked list at the DataIndex location here!
	// Note: DataIndex of 0 or 1 is the beginning of the list, any number greater than th number of nodes in the list will go at end!
	// Hint: You are going to have to use malloc or calloc to allocate memory for new node
	if (j>0){
	    strcpy(repeat,"\0");
	    for(k=0;k<=j;k++){
	        if (added[k].index == DataIndex){
	          strcpy(repeat,added[k].name);
	          break;
	        }
	    }
	}
	added[j].index = DataIndex;
	strcpy(added[j].name,NameData);
	struct LinkedListNode *link = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
	strcpy(link -> NameData, NameData);
	if (*ptrHead == NULL || (head_index > DataIndex)){
	  link -> ptrNextNode = *ptrHead;
	  *ptrHead = link;
	  head_index = DataIndex;  
	}
	else {
	  struct LinkedListNode *currentlast = *ptrHead;
	  while (currentlast -> ptrNextNode != NULL)
	  {   
	      currentlast = currentlast -> ptrNextNode;
	  }
	  if(repeat[0] == '\0'){
	    currentlast -> ptrNextNode = link;
	    link -> ptrNextNode = NULL;  
	  }
	  else{
	    struct LinkedListNode *temp = *ptrHead;
	    struct LinkedListNode *prev = NULL;
	    while(temp->ptrNextNode != NULL && strcmp(temp -> NameData,repeat) != 0){
	        prev = temp;
	        temp = temp->ptrNextNode;
	    }
	    if(prev == NULL){
	       *ptrHead = link; 
	    }
	    else{
	        prev->ptrNextNode = link;
	    }
	    if(temp -> ptrNextNode != NULL){
	    link->ptrNextNode = temp -> ptrNextNode;
	    currentlast -> ptrNextNode = temp;
	    }
	    else{
	      link ->ptrNextNode = temp;
	    }
	    temp -> ptrNextNode = NULL;
	  }  
	}
	j+=1;
}

// print out the linked list starting at the supplied linked list head
void PrintLinkedList(LinkedListNodeDef *ptrHead){
	// you need to add code to print out each node in list starting at the ptrHead until the ptrNextNode is NULL
   LinkedListNodeDef *ptr = ptrHead;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("%s ", ptr->NameData);
      ptr = ptr->ptrNextNode;
   }
	
   printf(" ]");

}
