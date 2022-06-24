#include "estructura.h"
#include <math.h>

float euclidean_ecuation(float point_x_1, float point_x_2, float point_y_1, float point_y_2){
    return sqrt(pow((point_x_1 - point_x_2), 2) + pow((point_y_1 - point_y_2), 2));
}

int euclidean_distance(address addresses[], int cant, float x, float y){
	int i, pos = 0;
    float distance1 = euclidean_ecuation(x, addresses[0].coord_X, y, addresses[0].coord_Y);
    float distance2;
    for (i = 1; i < cant; i++){
        distance2 = euclidean_ecuation(x, addresses[i].coord_X, y, addresses[i].coord_Y);
        if (distance2 > distance1){
            distance1 = distance2;
			pos = i;
		}
	}

	return pos;
}
