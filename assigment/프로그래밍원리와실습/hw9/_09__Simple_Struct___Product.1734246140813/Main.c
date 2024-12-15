#include <stdio.h>

typedef struct st_product{
	char     *name;
	int      price;
	int   quantity;
} Product;

void print_product(Product *prod) {
	
	printf("Product name: %s\n", prod->name);
	printf("Product price: %dwon\n", prod->price);
	printf("Product quantity: %d\n\n", prod->quantity);
}

void print_product_table(Product *p_prod){
	int total=0;	

  while ((p_prod->name) != "") {
		total += (p_prod->price)*(p_prod->quantity);
		print_product(p_prod);
		p_prod++;
	}
	printf("The total to buy all the products in the table : %d\n", total);
}


int main(void){
	Product table[]={ {"Tomato", 150,  5},
									  {"Apple",  100, 10},	
									  {"Banana", 200,  3},
									  {"Carrot",  50,  7},
									  {"Pear",   300,  2},
									  {"",  0,  0} }; 

	print_product_table(table);

	return 0;
}