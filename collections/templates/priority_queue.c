#include <stdlib.h>

#if defined(type_)

#define add__ add_
#define new_priority_queue__ new_priority_queue_
#define priority_queue__ _priority_queue
#define peek__ peek_
#define poll__ poll_
#define is_empty__ is_empty_
#define swim__ swim
#define delete__ delete_

#define ccat(a,b) ccat2(a,b)
#define ccat2(a,b) a##b
#define add_ ccat(add__,type_)
#define new_priority_queue_ ccat(new_priority_queue__,type_)
#define priority_queue_ ccat(type_,priority_queue__)
#define peek_ ccat(peek__,type_)
#define poll_ ccat(poll__,type_)
#define is_empty_ ccat(is_empty__,type_)
#define swim ccat(swim__,type_)
#define delete ccat(delete__,ccat(type_,priority_queue__))

#ifndef my_realloc
#define my_realloc
static void* reall(void* ptr, int size) {
	void* rv = realloc(ptr, size);
	if (rv) {
		return (void*)rv;
	}
	exit(EXIT_FAILURE);
}
#endif // !_mystack

typedef struct priority_queue_ {
	int (*compare)(type_ left, type_ right);
	int n;
	type_* content;
	int allocated_;
	int (*is_empty)(struct priority_queue_* list);
	int (*push)(struct priority_queue_* queue, type_  val);
	type_(*peek)(struct priority_queue_* queue);
	type_(*pop)(struct priority_queue_* queue);

}priority_queue_;
int (*is_empty)(priority_queue_* list);

int (add_)(priority_queue_* queue, type_  val);
type_(peek_)(priority_queue_* queue);
type_(poll_)(priority_queue_* queue);
int is_empty_(priority_queue_* list);

priority_queue_ new_priority_queue_(int (*compare)(type_ left, type_ right)) {
	return (priority_queue_) { 
		.compare = compare,
		.n = 0, 
		.content = malloc(0),
		.allocated_ = 0,
		.is_empty = is_empty_,
		.push = add_,
		.peek = peek_,
		.pop = poll_
	};
}

int is_empty_(priority_queue_* list) {
	return list->n == 0;
}

static void swim(priority_queue_* queue, int index) {
	if (index == 0)
		return;
	int parent_index = (index - 1) / 2;
	while (index > 0 && queue->compare(queue->content[parent_index], queue->content[index]) > 0) {
		type_ temp = queue->content[index];
		queue->content[index] = queue->content[parent_index];
		queue->content[parent_index] = temp;

		index = parent_index;
		parent_index = (index - 1) / 2;
	}

}

int add_(priority_queue_* queue, type_  val) {
	queue->n++;
	if (queue->n > queue->allocated_) {
		type_* temp = realloc(queue->content, sizeof(type_) * queue->n);
		if (temp == 0) {
			queue->n--;
			return 0;
		}
		queue->content = temp;
		queue->allocated_ = queue->n;
	}
	queue->content[queue->n - 1] = val;
	swim(queue, queue->n - 1);
	return 1;
}
type_ peek_(priority_queue_* queue) {
	return queue->content[0];
}


type_ poll_(priority_queue_* queue) {
	if (queue->n <= 0)
		return (type_) { 0 };
	type_ rv = queue->content[0];
	queue->content[0]=queue->content[queue->n-1];
	queue->n--;
	int index = 0;
	int child;
	while ((child=index * 2 + 1) < queue->n ) {
		if (child + 1 < queue->n && queue->compare(queue->content[child], queue->content[child + 1]) > 0) 
			child++;
		
		if (queue->compare(queue->content[index], queue->content[child])>0) {
			type_ temp = queue->content[index];
			queue->content[index] = queue->content[child];
			queue->content[child] = temp;
			index = child;
		}
		else {
			break;
		}
	}
	return rv;
}

#else
#error define type_
#endif // type
#undef type_

#undef add__
#undef new_priority_queue__
#undef priority_queue__
#undef peek__
#undef poll__
#undef is_empty__
#undef swim__
#undef delete__

#undef ccat
#undef ccat2
#undef add_
#undef new_priority_queue_
#undef priority_queue_
#undef peek_
#undef poll_
#undef is_empty_
#undef swim
#undef delete
