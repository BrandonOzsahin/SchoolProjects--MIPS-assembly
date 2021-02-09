#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "students.h"

// Creates the entire linked list from the file.
// Should call readNext and push
// Returns head of the linked list
Student *buildStudentList()
{
  Student *head;

  head=(Student*) malloc (sizeof(struct Student));
  head->next=NULL;

  Glist=head;

  Student *tempNode;
  myfile = fopen("test.data","r");

  int i=0;
  while (i<9){
    tempNode=readNext();
    push(tempNode);
    i=i+1;
  }

  return (Glist);
}

//Read a single line from standard input and return a student structure located on the heap
Student *readNext()
{
  char Tname[16];
  int Tage;
  float Tgpa;
    fscanf(myfile,"%s",&Tname);
    fscanf(myfile,"%d",&Tage);
    fscanf(myfile,"%f",&Tgpa);
  Student *node= (Student *) malloc( sizeof(Student) );
  int p=0;
  while (p<16){
  node->name[p] = Tname[p];
  p=p+1;}
  node->gpa = Tgpa;
  node->age=Tage;
  return (node);
}


//insert a new student node at the head of the linked list
void push(Student *student)
{
  student->next=Glist;
  Glist=student;
  return;
}

//Return a student structure stored on the heap
Student *makeStudent(char name[16], int age, float gpa)
{
  Student *s = (Student *) malloc( sizeof(Student) );
  int p=0;
  while (p<16){
  s->name[p] = name[p];
  p=p+1;}
  s->gpa = gpa;
  s->age=age;
  s->next=NULL;
  return s;
}

void insert(Student *list, Student *s, int position)
{
  int i=2;
  Student *Aux;
  Student *Aux2;
  Aux=list;
  while(i<position) {Aux=Aux->next; i=i+1;}
  Aux2=Aux->next;
  Aux->next=s;
  s->next=Aux2;
}



//Displays contents of a single student structure
void display(Student *s)
{
  printf("Name %s\n",s->name);
  printf("Students GPA: %f\n",s->gpa);
  printf("Age: %d\n", s->age);
  printf("\n");
  return;
}

//Displays contents of the entire linked list
void displayAll(Student *ss)
{
  int k=0;
while( ss != NULL)
  {
  printf("Name: %s\n",ss->name);
  printf("Students GPA: %f\n",ss->gpa);
  printf("Age: %d\n", ss->age);
  ss = ss->next;
  }
  return;
}


//Main function tests your functions.
int main()
{
  printf("Program Started\n");

  Glist = buildStudentList();
  displayAll(Glist);//para probar

  //Insert a new student in desired position
    printf("\n Insert New Student \n");
  Student *s = makeStudent("Max",6, 4.0);
  insert(Glist, s, 3);

  //Display entire linked list
  displayAll(Glist);

  printf("Program Successful Exit\n");
  return(0);
}
