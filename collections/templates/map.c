#include <string.h>
#include <stdlib.h>

#ifndef value_type_
#error define value_type_  as the type of the values in this map
#endif

#ifndef key_type_
#error define key_type_  as the type of the keys in this map
#endif

#if defined(value_type_) && defined(key_type_)


#define put__ put_
#define new_map__ new_map_
#define map__ _map
#define contains_key__ contains_key_
#define remove__ remove_
#define get__ get_
#define remove_all__ remove_all_
#define entry__ entry_
#define del__
#define underscore_ _
#define TREE _tree
#define ccat(a,b) ccat2(a,b)
#define ccat2(a,b) a##b

#define type_ ccat(key_type_,ccat(underscore_,value_type_))

#define put_ ccat(put__,type_)
#define new_map_ ccat(new_map__,type_)
#define map_ ccat(type_,map__)
#define contains_key_ ccat(contains_key__,type_)
#define remove_ ccat(remove__,type_)
#define get_ ccat(get__,type_)
#define remove_all_ ccat(remove_all__,type_)
#define entry_ ccat(entry__,type_)
#define tree_ ccat(type_,TREE)
#define del_ ccat(del__,type_)
#ifndef my_malloc
#define my_malloc
static void* mall(int size) {
	void* rv = malloc(size);
	if (rv) {
		return (void*)rv;
	}
	exit(EXIT_FAILURE);
}
#endif // !_mystack
typedef struct {
	key_type_ key;
	value_type_ value;
}entry_;
typedef struct tree_ {
	entry_ value;
	struct tree_* left;
	struct tree_* right;
}tree_;
typedef struct map_{
	int (*compare)(key_type_, value_type_);
	int err;
	tree_* content;
	void(*put)(struct map_*, key_type_, value_type_);
	value_type_(*get)(struct map_*, key_type_);
	value_type_(*contains_key)(struct map_*, key_type_);
	value_type_(*remove)(struct map_*, key_type_);
	void (*del)(struct map_*);
}map_;
void put_(map_* , key_type_  , value_type_ );
value_type_ get_(map_* map, key_type_ key);
int contains_key_(map_* map, key_type_ key);
value_type_  remove_(map_* map, key_type_ key);
void del_(map_*);
map_ new_map_(int (*compare)(key_type_, value_type_)) {
	return (map_) { 
		.compare = compare,
		.content = 0,
		.err = 0,
		.put=put_,
		.get=get_,
		.contains_key=contains_key_,
		.remove=remove_,
		.del = del_
	};
}
void del_(map_* map) {
	if(map->content){
		map_ left = (map_){ .content = map->content->left };
		map_ right = (map_){ .content = map->content->left };
		del_(&left);
		del_(&right);
		free(map->content);
	}
	*map = (map_){0};
}
int contains_key_(map_* map, key_type_ key) {
	get_(map, key);
	return map->err==0;
}

void put_(map_* map, key_type_  key, value_type_ value) {
	map->err = 0;
	entry_ e = (entry_){ key,value };
	tree_** tree = &map->content;
	while (1) {
		if (*tree == 0)
		{
			*tree = mall(sizeof(tree_));
			**tree = (tree_){ .value = e };
			return;
		}
		int compare_result = map->compare(key,(*tree)->value.key);

		if (compare_result == 0)
			return;//no duplicate  allowed
		if (compare_result < 0) {
			tree = &((*tree)->left);
		}
		else {
			tree = &((*tree)->right);
		}
	}
}

value_type_ get_(map_* map, key_type_ key) {
	map->err = 0;
	tree_* tree = map->content;
	while (tree != 0) {
  		int compare_result = map->compare(key,tree->value.key);
		
		if (compare_result == 0)
			return tree->value.value;//no duplicate entries
		
		if (compare_result < 0) {
			tree = tree->left;
		}
		else {
			tree = tree->right;
		}
	}
	map->err = 1;
	return (value_type_) { 0 };
}

value_type_ remove_(map_* map, key_type_ key) {
	tree_** tree = &(map->content);
	while (1) {
		if (*tree == 0)
			return 0;

		int compare_result = map->compare(key,(*tree)->value.key);

		if (compare_result == 0) {
			tree_* left = (*tree)->left;
			tree_* right = (*tree)->right;
			if (left == 0 && right == 0) {
				value_type_ e = (*tree)->value.value;
				free(*tree);
				*tree = 0;
				return e;
			}
			if (left == 0) {
				value_type_ e = (*tree)->value.value;
				//tree_** temp = tree;
				free(*tree);
				*tree = right;
				return e;
			}
			if (right == 0) {
				value_type_ e = (*tree)->value.value;
				free(*tree);
				*tree = left;
				return e;
			}

			tree_** parent_of_min = 0;
			tree_* seek_min = right;
			while (seek_min->left!=0) {
				*parent_of_min = seek_min;
				seek_min = seek_min->left;
			}
			(*tree)->value = seek_min->value;
			*parent_of_min = seek_min->right;
			free(seek_min);
			seek_min = 0;
			return 1;
		}
		if (compare_result < 0) {
			tree = &((*tree)->left);
		}
		else {
			tree = &((*tree)->right);
		}
	}
	return 0;
}


#undef key_type_
#undef value_type_

#undef put__
#undef new_map__
#undef map__
#undef contains_key__
#undef remove__
#undef get__
#undef remove_all__
#undef entry__

#undef underscore_
#undef TREE
#undef ccat
#undef ccat2

#undef type_

#undef put_
#undef new_map_
#undef map_
#undef contains_key_
#undef remove_
#undef get_
#undef remove_all_
#undef entry_
#undef tree_

#endif //#if defined(value_type_) && defined(key_type_)