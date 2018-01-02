#ifndef CREARDLL_H_
#define CREARDLL_H_

_declspec(dllexport) int add2(int x, int y);/*_declspec(dllexport)声明一个导出函数，是说这个函数要从本DLL导出,我要给别人用。*/
int add2(int x, int y);  //求和函数

#endif