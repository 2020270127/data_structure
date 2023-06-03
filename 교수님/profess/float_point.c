#include <stdio.h>
typedef unsigned int u_int;
double frexp(double value, int* eptr) 
{
	union { //�ش� ����ü�� 8����Ʈ ������ �����ϹǷ�, v�� double_stuct�� 8����Ʈ�� ������ �����ϰ� double_struct�� ���� v�� �����͸� ���������� ���� ����
		double v;
		struct double_struct{
			u_int u_mant2 : 32; 
			u_int u_man1 : 20;
			u_int u_exp : 11; //������
			u_int u_sign : 1;
		} s;
	} u;
	if (value) {
		u.v = value;
		*eptr = u.s.u_exp - 1022; 
		u.s.u_exp = 1022; //������ ������
		return(u.v);
	}
	else {
		*eptr = 0;
		return(u.v);
	}
}
int main() {

}