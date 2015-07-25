#include "object.h"
#include<stdio.h>
#include<stdlib.h>  // for malloc realloc 
#include<string.h>

int  ob_init(ssth * ob  ,int flags)
{
	int opt = flags;

	switch(opt){
		case STRING:
			ob->type = STRING;
			ob->ob = malloc(18);
			ob->size = 18;
			ob->used = 0;
			break;
		case INT   :
			ob->type = INT;
			ob->ob = malloc(sizeof(int));
			ob->size = 4;
			ob->used = 0;
			break;
		default:
			 printf( " ob_init param error in %s on line %d\n " , __FILE__, __LINE__);
			 return -1;
	}
	return 0;
}


int ob_free(ssth * ob)
{
	if (NULL != ob){
		free(ob->ob);
		return 0;
	}else
		return -1;		
}

int ob_create(ssth * ob , void * sui ,int flags)
{
	int opt = flags;
	char * str;
	int size =0;

	ob_init(ob,opt);

	switch(flags){
		case STRING:
			str = (char *)sui;
			size = strlen(str) + 1;
			if (size > ob->size){
				ob->ob = realloc(ob->ob,(size/ob->size + 1)*ob->size);
				strncpy(ob->ob,str,size);
				ob->size = (size/ob->size +1)*(ob->size);
				ob->used = size ; 
			} else if (size <= ob->size){
				ob->used = size;
				strncpy(ob->ob,str,size);
			} else {
				printf("create string error %s",str);
				return -1;
			}
			break;
		case INT :
			strncpy(ob->ob ,(char *)sui,4);
			ob->used =4 ;
			break;
		}
	return 0;
}


int main()
{
	ssth string;
	ssth num;
	int rc;
	/*string*/
	/*rc = ob_create(&string,"12345",STRING);
	printf("string:%s,size:%d,used:%d\n",(char *)string.ob,string.size,string.used);
	if(rc < 0) 
		printf("create %s fail\n","12345");
	else{
		rc = ob_create(&string,"0123456789012345678",STRING);
		printf("after add length of string \n");
		printf("string:%s,size:%d,used:%d\n",(char *)string.ob,string.size,string.used);
	}
	ob_free(&string);
	*/
	/*int*/
	int p =2222;
	rc = ob_create(&num,&p,INT);
	printf("int:%d,size:%d,used:%d\n",*(int *)num.ob,num.size,num.used);
	ob_free(&num);


	return 0;

}
