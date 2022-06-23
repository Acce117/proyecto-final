#include <stdbool.h>

#ifndef ADDRESS
#define ADDRESS

typedef struct{

	float coord_X;
	float coord_Y;
    char main_street[20];
    char between_1[20];
    char between_2[20];
	int inhabitants;
	int number;
	bool has_number;

} address;

#endif
