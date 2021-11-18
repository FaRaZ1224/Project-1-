/*faraz h
 * tuesday 5-8
 * lab 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
#define LENGTH 20




int insert (char *name, int size);                                     //global variables
int delete (void);
int list (void);
int size2(void);
int duplicate(char *name2);
void read (char *);
void save (char *);





typedef struct ENTRY
{                                   //structure template
        char names[LENGTH];
        int sizes;
	struct ENTRY *next;
	
}ENTRY;


typedef struct LIST
{
	ENTRY *head;
	ENTRY *tail;                                     //declaring head and tail
}LIST;

LIST array[4] = {{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL}};



int main(int argc, char *argv[])
{


	int size;
	char name[LENGTH]; 

	if (argc == 1)
	{
		printf("the file name is falling.\n");
		return 1;
	}

	read (argv[1]);

                                                    //start of main function
        int i;
        int input;


while(1)
{                                               
printf("1 - schedule appointment\n");
printf("2 - Remove appointment\n");
printf("3 - List schedule\n");
printf("4 - Search\n");
printf("0 - Quit\n");
scanf("%d", &input);

switch(input)
{                                  //switch with case functions
case 1: 
	printf("what is your name\n");
	scanf("%s", name);

	if(duplicate(name) == 1)
	{
	printf("this name is already used.\n");
	return 1;
	}

	printf("what is your group size\n");
	scanf("%d", &size);
	               
	insert(name,size);                         
	break;               
case 2:                       
	delete();                       
	break;                 
case 3:                        
	list();                        
	break;            
case 4:                       
	size2();                        
	break;                
case 0: 
	save(argv[1]);                       
	return 5;
	break;
          
default:                        
	printf("not valid.\n");                        
	break;
                
}       
}
}


int insert(char *name, int groupsize)
{	



				//insert function                                    
       

 	
	ENTRY *p;
        p = (ENTRY*)malloc(sizeof(ENTRY));



	if (groupsize == 1 || groupsize == 2)

	{ 					//depending on the group size, p is put in a certain linked list
	
	if (array[0].head == NULL)
	{
	    array[0].head = p;
	    array[0].tail = p;
	}
	
	else
	{
	    array[0].tail->next = p;
	    array[0].tail = p;
	}
        }

 	
    if (groupsize == 3 || groupsize == 4)
	
	{
	if (array[1].head == NULL)
	{
	    array[1].head = p;
	    array[1].tail = p;
	}
	
	else
	{
	    array[1].tail->next = p;
	    array[1].tail = p;
	}
    	}

    if (groupsize == 5 || groupsize == 6)
	{
	if (array[2].head == NULL)
	{
	    array[2].head = p;
	    array[2].tail = p;
	}
	else
	{
	    array[2].tail->next = p;
	    array[2].tail = p;
	}
    	}

    if (groupsize > 6)
	{
	if (array[3].head == NULL)
	{
	    array[3].head = p;
	    array[3].tail = p;
	}
	else
	{
	    array[3].tail->next = p;
	    array[3].tail = p;
	}
    }


 p->sizes=groupsize;
 strcpy(p->names, name);
 p->next = NULL;

return;

}

int delete(void)
	{                                                 //delete function


        int groupsize;                                                                    

	ENTRY *p = NULL;
	ENTRY *q = NULL;
	int i; 
	

	printf("enter the number of available appointments\n");
	scanf("%d", &groupsize);
	
	int sum = groupsize;
		
	for(i=0; i<4; i++)
	{
	p = array[i].head;
		while(p != NULL && p->sizes <= groupsize)
		{
		groupsize -= p->sizes;
			if(p == array[i].head)
			{  
			array[i].head = p->next;
        		printf("Removed %s party of %d from waiting list.\n", p->names, p->sizes);        //print removal
                     	p = p->next;                                           //set p to next nod
 		    	}	


        	

       			else if (p == array[i].tail)
			{
			array[i].head = array[i].tail = NULL;
			printf("removed %s party of %d from waiting list\n", p->names, p->sizes);
			free(p);
			break;
			}
	}
	}
	}



int list(void)
{
int i;
ENTRY *temp;

 for (i = 0; i < 4; i++)
{
	if (i == 0)						//list function
	{
	    printf("Group size from 1-2\n");
	}
	
	else if (i == 1)
	{
	    printf("Group size from 3-4\n");
	}
	
	else if (i == 2)
	{
	    printf("Group size from 5-6\n");
	}
	
	else
	{
	    printf("Group size greater than 7\n");
	}
	
	if (array[i].head == NULL)
	{
	    printf("The group size is empty\n");    
	}
	
	else
	{
	   temp = array[i].head;
	
        while(temp != NULL)                                       //lists out appointments
		{
                printf("Appointment for %d under %s\n",temp->sizes, temp->names);

		temp = temp->next;
		}
	}
}		
return;

}


int duplicate (char *name2)

{
int i;
ENTRY *q;

	for(i=0; i < 4; i++)
	q = array[i].head;
        while(q != NULL)
		{
                if(strcmp(q->names,name2) == 0)
		{                         //checks if the name is the same as another stored name
                        return 1;
                }
		
		q = q->next;

        }
        return 0;
}




int size2(void)
{

ENTRY *temp;

int i;

printf("Enter a group Size:\n");
int groupsize = 0;
scanf("%d", &groupsize);			//checks the size of the group

for(i=0; i < 4; i++)
{
	temp = array[i].head;

	while(temp != NULL)
	{
		if(temp->sizes <=groupsize)
			{          
				printf("%d, %s\n",temp->sizes, temp->names);
                 
			}

 	temp = temp->next;
	}
	}
        return;
}




void read(char *fname)
{

char name[LENGTH];
 int size;

FILE *fp;
								//reads the input and puts names and numbers into list
fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("cant open %s", name);
		return;
	}	

//fseek(fp, 16, SEEK_SET);

while (fscanf(fp, "%s %d", name, &size)==2) 

	{
	printf("%s", name);
	insert(name, size);
	}
							
fclose(fp);
return;

}



void save(char *fname)
{

int i;
char name[LENGTH];
int size1;
ENTRY *p;
							 
FILE *fp;
fp = fopen(fname, "w");
	if (fp == NULL)
	{
	printf("error");
	return;
	}

for(i=0; i<4; i++)
{
								//prints names and number into list into text file
p = array[i].head;
while (p!=NULL)
{
	fprintf(fp, "%s  %d\n", p->names, p->sizes);
	p=p->next;

}

}

fclose(fp);
return;
}














































































































	



































