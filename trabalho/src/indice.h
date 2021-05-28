#ifndef INDICE_H_
#define INDICE_H_


/* defines  */
#define MAXKEYS 5 // testing , 204 is the real one 
#define PAGESIZE 4096
#define FREE_SPACE_ON_PAGE (PAGESIZE - ((MAXKEYS * 4) + (MAXKEYS * 8) + ((MAXEYS + 1) * 8) + 3))
/************/

typedef struct index{
  int key;
  long file_position;
}INDEX;

/**********************************/
/*            B-TREE              */
/**********************************/

typedef enum{
  false, true
}BOOL;

typedef struct page{
  INDEX index[MAXKEYS]; // actual keys
  long *childs; // rrn of childs
  short key_num; //number of keys stored in page
  BOOL is_leaf;
}PAGE;

typedef struct promoted_key{
  INDEX *index;
  long *childs;

}P_KEY;

PAGE *_create();
int _search(PAGE *);
void _delete_b_tree(PAGE *);
BOOL _page_full(PAGE *);
int _insert_b_tree(PAGE *, int *, long *);
/*@Description: search elements in array*/
/*@Param: key, pointer to array, end of array and beginning of array*/
/*@Return: array position*/
int binary_search(long , INDEX *, int , int );
#endif
