#ifndef OBJECT_H
#define OBJECT_H 

#define STRING  1 
#define INT     2 

typedef struct object
{
	void * ob;
	int type;      // 1 STRING 2 INT 
	unsigned int used ;   //the factual of sizeof  ob 
	unsigned int size ;  // allocate to the size of ob;
}ssth;

static int ob_init(ssth * ,int flags);//if flags is STRING(18bytes)   or INT (sizeof(int))

int ob_create(ssth * , void * , int flags); 

int ob_free(ssth * );



#endif
