#include "init.h"
#include "parent.cpp"
#include "child.cpp"
#include "relation.cpp"
#include "sort.h"

int choice; char repeat;
infoParent angkutan; string daerah;

void addDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void showDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void updateDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void deleteDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void showMenu(string x, listParent &LP, listChild &LC, listRel &LR);