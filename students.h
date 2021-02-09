#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct Student Student;

Student *Glist;
FILE *myfile;

struct Student
{
  char name[16];
  int age;
  float gpa;

  Student *next;
};

Student *makeStudent(char *name, int age, float gpa);
void insert(Student *list, Student *s, int position);
Student *readNext();
Student *buildStudentList();
void display(Student *s);
void displayAll(Student *list);
void push(Student *student);
void cleanUp(Student *list);


#endif
