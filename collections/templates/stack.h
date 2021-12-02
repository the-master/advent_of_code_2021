#include <stdlib.h>

#ifndef type_
#error define type_ 
#endif



#define pop__ pop_
#define push__ push_
#define new_stack__ new_stack_
#define stack__ _stack
#define delete__ delete_
#define ccat(a,b) ccat2(a,b)
#define ccat2(a,b) a##b

#ifdef type_name_
#define pop_ ccat(pop__,type_name_)
#define push_ ccat(push__,type_name_)
#define new_stack_ ccat(new_stack__,type_name_)
#define stack_ ccat(type_name_,stack__)
#define delete_ ccat(delete__,ccat(type_name_,stack__))
#else
#define pop_ ccat(pop__,type_)
#define push_ ccat(push__,type_)
#define new_stack_ ccat(new_stack__,type_)
#define stack_ ccat(type_,stack__)
#define delete_ ccat(delete__,ccat(type_,stack__))

#endif // !1






typedef struct stack_ {
	int n;
	int allocated_;
	type_* content;
	const void (*push)(struct stack_*, type_);
	const type_(*pop)(struct stack_*);

}stack_;

type_ pop_(stack_* stack);
int push_(stack_* s, type_  e);

stack_ new_stack_() {
	return (stack_) { .n = 0, .allocated_ = 0, .content = malloc(0), .pop = pop_, .push = push_ };
}

type_ pop_(stack_* stack) {
	return stack->content[--stack->n];
}
// return value:error code malloc
// 1 succesful push
// 0 failed push 
int push_(stack_* s, type_  e) {
	if (s->n + 1 >= s->allocated_) {
		s->allocated_++;
		type_* temp = realloc(s->content, sizeof(type_) * s->allocated_);
		if (temp) {
			s->content = temp;
		}
		else {
			s->allocated_--;
			return 0;
		}
	}
	s->content[s->n++] = e;
	return 1;
}
void delete_(stack_* list) {
	list->n = -1;
	list->allocated_ = -1;
	free(list->content);
	list->content = 0;
}



#undef type_
#undef pop__
#undef push__
#undef new_stack__
#undef stack__
#undef delete__
#undef ccat
#undef ccat2

#undef pop_
#undef push_
#undef new_stack_
#undef stack_
#undef delete_