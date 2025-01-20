#include <stdio.h>

struct abc {
	int data;
	struct abc* next;
}; //자기참조 구조체 정의
int main() {
	struct abc x;
	struct abc y;
	struct abc z;//3개의 구조체 선언

	x.data = 10;
	y.data = 20;
	z.data = 30;//구조체 데이터값 저장

	x.next = &y;
	y.next = &z;
	z.next = NULL;//x와 y의 구조체 변수는 다른 구조체를 가리키지만
	//z는 가리키지 않고 있다

	struct abc* p;//구조체 포인터 변수 p선언

	for (p = &x; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}// 각 구조체 내의 데이터 값 출력, 조건문은 주소를 이용하여서 

	printf("구조체 y 삭제후 \n");
	x.next = &z;
	y.next = NULL;// y구조체 삭제로 인해 x구조체의 포인터변수는 z를 가리킨다.

	for (p = &x; p != NULL; p=p->next) {
		printf("%d\n", p->data);
	}
		return 0;
	}//y가 삭제된이후 데이터 값 출력