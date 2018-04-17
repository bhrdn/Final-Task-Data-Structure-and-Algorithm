#include "init.h"
#include "parent.cpp"
#include "child.cpp"

int choice; char repeat;

void addDatas(string x, listParent &LP, listChild &LC);
void showDatas(string x, listParent &LP, listChild &LC);
void updateDatas(string x, listParent &LP, listChild &LC);
void deleteDatas(string x, listParent &LP, listChild &LC);
void showMenu(string x, listParent &LP, listChild &LC);