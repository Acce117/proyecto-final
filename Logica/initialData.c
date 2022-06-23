#include "estructura.h"

void initial_data(address addresses[]){
	address address1 = {2.3, 4.67, "calle1", "entrecalle1", "entrecalle2", 3, 231, true};
	address address2 = {8.2, 5.6, "calle2", "entrecalle2", "entrecalle3", 3, 344, true};
	address address3 = {34.23, 15.37, "calle3", "entrecalle3", "entrecalle4", 3, 0, false};
	address address4 = {22.12, 15.67, "calle4", "entrecalle4", "entrecalle5", 3, 42, true};
	address address5 = {27.31, 6, "calle5", "\0", "entrecalle6", 3, 892, true};
	address address6 = {28.52, 0.0, "calle6", "entrecalle6", "entrecalle7", 3, 0, false};
	address address7 = {31.32, 5.07, "calle7", "entrecalle7", "entrecalle8", 3, 412, true};
	address address8 = {21.92, 0.66, "calle8", "\0", "\0", 3, 53, true};
	address address9 = {38.32, 1.9, "calle9", "entrecalle9", "entrecalle10", 3, 0, false};
	address address10 = {2.32, 12.8, "calle10", "entrecalle10", "entrecalle11", 3, 783, true};
	address address11 = {5.62, 3.7, "calle11", "entrecalle11", "\0", 3, 0, false};
	address address12 = {6.32, 9.67, "calle12", "entrecalle12", "entrecalle13", 3, 125, true};
	address address13 = {27.2, 8.7, "calle13", "entrecalle13", "entrecalle14", 3, 327, true};
	address address14 = {8.3, 5.6, "calle14", "\0", "entrecalle15", 3, 372, true};
	address address15 = {28.32, 45.67, "calle15", "entrecalle15", "entrecalle16", 3, 15, true};

	addresses[0] = address1;
	addresses[1] = address2;
	addresses[2] = address3;
	addresses[3] = address4;
	addresses[4] = address5;
	addresses[5] = address6;
	addresses[6] = address7;
	addresses[7] = address8;
	addresses[8] = address9;
	addresses[9] = address10;
	addresses[10] = address11;
	addresses[11] = address12;
	addresses[12] = address13;
	addresses[13] = address14;
	addresses[14] = address15;
}
