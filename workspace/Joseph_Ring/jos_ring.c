#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct TestList {
	struct list_head p; //链表关系位于链表节点结构体成员变量的第一个位置，那么实际上这个链表关系的指针的地址和链表节点的指针的地址是一样的
	int num;

};

int main() {
	int N = 41;
	int K = 0;
	int M = 3;
	int i = 0;
	int m_tem = 1;
	struct list_head *pos;
	struct TestList* p_list;
	p_list = (struct TestList*) malloc(N * sizeof(struct TestList));
	LIST_HEAD(head);
	INIT_LIST_HEAD(&head);
	for (i = 0; i < N; i++) {
		p_list[i].num = i + 1;
		//(struct TestList*)((char*)p_list + (i* sizeof(struct TestList)))->num = i;
		list_add_tail(&(p_list[i].p), &head);
	}
	for (pos = &p_list[K].p; 1; pos = pos->next) {

		if (list_empty(&head)) {
			break;
		}
		if (pos == &head) {
			continue;
		}
		if (m_tem == M) {
			printf("OUT is %d\n", ((struct TestList*) pos)->num);
			//printf("OUT is %d\n", ((struct TestList*) (list_entry(pos,typeof(struct TestList),p)))->num);
			list_del(pos);
			m_tem = 1;
		} else {
			m_tem++;
		}
	}
	free(p_list);
	return 1;
}
