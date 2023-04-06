#include <stdio.h>
typedef unsigned int u_int;
double frexp(double value, int* eptr) 
{
	union { //해당 공동체는 8바이트 공간을 공유하므로, v와 double_stuct는 8바이트의 공간을 공유하고 double_struct를 통해 v의 데이터를 세부적으로 조작 가능
		double v;
		struct double_struct{
			u_int u_mant2 : 32; 
			u_int u_man1 : 20;
			u_int u_exp : 11; //지수부
			u_int u_sign : 1;
		} s;
	} u;
	if (value) {
		u.v = value;
		*eptr = u.s.u_exp - 1022; 
		u.s.u_exp = 1022; //지수값 날리기
		return(u.v);
	}
	else {
		*eptr = 0;
		return(u.v);
	}
}
int main() {

}