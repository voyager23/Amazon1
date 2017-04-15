#include <stdio.h>
#include <stdlib.h>

//-----declarations------
typedef int triple[3];
typedef triple triple_list[20];

triple_list triples = {{ 7,25,26},{29,31,32},
			{ 0, 5,20},{23,24,28},
			{ 7,19,30},{33,42,43},
			{ 0, 5,14},{28,38,39},
			{ 4,10,19},{25,26,37},
			{15,20,33},{ 3, 0,40},
			{ 8,23,36},{ 0,25,41},
			{33, 9,15},{14,37,22},
			{21,26,32},{ 2,35,13},
			{14,27,16},{30, 5,38}};

void prt_triple_list(triple *t);
int compar_funct_1(const void *, const void *);
int search_funct_1(const void *, const void *);

//-----definitions-----
void prt_triple_list(triple *t)
{
	const int lines = sizeof(triple_list)/(sizeof(int)*3);
	for(int l = 0; l < lines; ++l){
		triple *tl = t + l;
		printf("%02d,%02d,%02d\n", (*tl)[0], (*tl)[1], (*tl)[2]);
	}
}

int compar_funct_1(const void *pkey, const void *pelem)
{
	const triple *key = (const triple*)pkey;
	const triple *elem = (const triple*) pelem;

	if((*key)[0] > (*elem)[0]) return 1;
        if((*key)[0] < (*elem)[0]) return -1;

        if((*key)[2] > (*elem)[2]) return 1;
        if((*key)[2] < (*elem)[2]) return -1;

        if((*key)[1] > (*elem)[1]) return 1;
        if((*key)[1] < (*elem)[1]) return -1;

	return 0;
}

int search_funct_1(const void *pkey, const void *pelem)
{
        const triple *key = (const triple*)pkey;
        const triple *elem =  (const triple*)pelem;

        if((*key)[0] > (*elem)[0]) return 1;
        if((*key)[0] < (*elem)[0]) return -1;

        if((*key)[2] > (*elem)[2]) return 1;
        if((*key)[2] < (*elem)[2]) return -1;

        if((*key)[1] > (*elem)[1]) return 1;
        if((*key)[1] < (*elem)[1]) return -1;

        return 0;
}

//=======================================================================

int main(int argc, char **argv)
{


	prt_triple_list(triples);
	qsort(triples, 20, sizeof(triple), compar_funct_1);
	printf("===========\n");
	prt_triple_list(triples);
	return 0;
}
