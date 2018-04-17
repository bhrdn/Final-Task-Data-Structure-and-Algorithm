#include "init.h"
#include "parent.cpp"
#include "child.cpp"

int choice; char repeat;
listParent LP;
listChild LC;

void addDatas(string x);
void showDatas(string x);
void updateDatas(string x);
void deleteDatas(string x);
void showMenu(string x, listParent &LP, listChild &LC);