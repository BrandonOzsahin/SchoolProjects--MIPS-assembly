#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "students.h"


// Creates the entire linked list from the file.
// Should call readNext and push
// Returns head of the linked list
Student *buildStudentList()
{
  Student *head; // creates head of the students in linked list

  head=(Student*) malloc (sizeof(struct Student)); // gives head size of student
  head->next=NULL; // next should be empty (address)

  Student *tempNode; // student *tempNode to hold the added student
   //FILE *myfile;
  //myfile = fopen("test.data","r"); // opens file test.data

  int i=0;
  while (i<9)
  {
    tempNode=readNext();
    push(&head,tempNode);
    i=i+1;
  }

	
	return head;  //FINISHED BUILD with teturn
}

//Read a single line from standard input and return a student structure located on the heap
Student *readNext()
{
	
  char Tempname[16]; // arrays hold 16 chars temp
  char Tempyear[16];
  float Tempgpa;
  FILE *myfile; // calls to myfile to read test.data
  myfile=fopen("test.data","r");

  int i = 0;
  while (i < 16) {
    char temp_char = (char) fgetc (myfile);
    if (temp_char == ' ') {
      break;
    }
    
    Tempname[i++] = temp_char;
  }
  
  fscanf(myfile,"%f",&Tempgpa); // puts the data inside the values

  int j = 0;
  while (j < 16) {
    char temp_char = (char) fgetc(myfile);
    if (temp_char == ' ') {
      continue;
    }
    else if (temp_char == '\n'){
      break;
    }
    else {
      Tempyear[j++] = temp_char;
    }
  }

  Student *node= (Student *) malloc( sizeof(struct Student) );
  node -> name = malloc (sizeof(char));
  node -> year = malloc(sizeof(char));

  int p=0;
  while (p<i)
  {
    node->name[p] = Tempname[p];
    p=p+1;
  }
  node->gpa = Tempgpa;
	p=0;
while (p<j)
{
  node->year[p] = Tempyear[p];
  p=p+1;
  
  }
	fclose(myfile);
	return node;
}


//Return a student structure stored on the heap **********fin***
Student *makeStudent(char *name, float gpa, char *year)
{
	Student *s = (Student *) malloc( sizeof(Student) );
	char *n = (char *) malloc ( (strlen(name) + 1) * sizeof(char) ); // array of name plus /0 for null value
	strcpy(n, name); // copies string name to n
	s->name = n; 
	s->gpa = gpa;
	char *y = (char *) malloc((strlen(year) +1) * sizeof(char) );
	strcpy(y, year);
	s->year = y;
	return s;  //*****finished returns thr make student
}

//insert a new student node at the head of the linked list
void push(Student **list, Student *student)
{   
	student->next=*list; 
       *list=student;
}

//Insert a student node in the desired position on the linked list
void insert(Student *list, Student *s, int position)
{
	Student* tempStudent = NULL;
	Student* ptr = NULL;
	tempStudent = list;
	if(position == 1)
	{
		list=s;
		s->next = tempStudent;
	}
	else
	{
		int i=2;
		while(i<position)
		{
			tempStudent=tempStudent->next;
			++i;
		}
		ptr=tempStudent->next;
		tempStudent->next = s;
		s->next = ptr;
	}
}


//Displays contents of a single student structure
void display(Student *s)
{
	printf("Name %s\n",s->name);
	printf("Students GPA: %.lf\n",s->gpa);
	printf("Year: %s\n", s->year);
}

//Displays contents of the entire linked list
void displayAll(Student *list)
{
	while( list != NULL)
	{
		display(list);
		list = list->next;
	}
}

//Delete all data allocated on the heap before terminating program
void cleanUp(Student *list)
{
	Student *curr = list;
	while ( curr != NULL)
	{
		Student *temp = curr->next;
		free(curr);
		curr = temp;
	}
}

//Main function tests your functions. 
int main()
{
	printf("Program Started\n");

	//Construct Linked List from Standard Input
	Student *list = buildStudentList();
	
	//Insert a new student in desired position
	 Student *s = makeStudent("Max",3.0, "senior");
	insert(list, s, 3);
	
	//Display entire linked list
	displayAll(list);

	//Free all heap memory
  cleanUp(list);
	
    //printf("Program Successful Exit\n");
    //exit(EXIT_SUCCESS);
		return 0;
}
