#ifndef CREARDLL_H_
#define CREARDLL_H_

_declspec(dllexport) int add2(int x, int y);/*_declspec(dllexport)����һ��������������˵�������Ҫ�ӱ�DLL����,��Ҫ�������á�*/
int add2(int x, int y);  //��ͺ���

#endif