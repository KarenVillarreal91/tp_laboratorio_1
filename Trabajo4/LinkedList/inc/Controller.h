#include "../testing/inc/Employee.h"


int controller_mainMenu(int flagCargado);
int controller_editMenu();
char confirmar();

int controller_loadFile(char* path, LinkedList* pArrayListEmployee);
int controller_requestFile(LinkedList* pArrayListEmployee);
void controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
void controller_ListEmployee(LinkedList* pArrayListEmployee);
void controller_removeEmployee(LinkedList* pArrayListEmployee);
void controller_saveCopyList(LinkedList* pArrayListEmployee);
void controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_removeAllEmployee(LinkedList* pArrayListEmployee);
void controller_saveList(LinkedList* pArrayListEmployee);
void controller_replace(LinkedList* pArrayListEmployee);


void employee_print(Employee* this);
