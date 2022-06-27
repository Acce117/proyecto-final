#include "Logica/estructura.h"
#include "lib/fort.h"

int selection();

int choice(char *);

void validate_point_value(float *, char *);

void add_street(char *, char *);

void validate_integer(int *, char *);

bool validate_repeted_street(char *, char *);

bool validate_repeted_data(address [], int, int *);

void update_inhabitants(int *);

void write_in_table(address, ft_table_t);

void print_addresses(address addresses[], int);

int add_address(address addresses[], int);

void add_point(float *x, float *y);

void show_if_has_number(address addresses[], int);

void show_farthest_address(address addresses[], int, float, float);

void print_empty_secondary_address_count(address addresses[], int);

void atleast_5addresses(address [], int);
