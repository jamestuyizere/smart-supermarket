#include <stdio.h>
int main(){
//inventory data
char* product_name[]={"Bread", "Milk", "Eggs", "Rice", "Coffee"};
int product_prices[] = {30, 45, 80, 120, 150};
//data storage variable
int cart_item_ids[100];
int cart_quantities[100];

int total_items=0;
int choice;
// the engine

do{
    printf("\n =========================\n");
    printf("\n Smart SuperMarket\n");
    printf("\n =========================\n");
    printf("1. Add product\n");
    printf("2. View current bill\n");
    printf("3. Remove last product\n");
    printf("4. Apply discount\n");
    printf("5. Checkout and pay\n");
    printf("6. Exit\n");
    printf("\n===========================\n");
    printf("chose an option: \n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("\n--- Add a product ---\n");
        break;

    case 2:
        printf("\n--- View Bill ---\n");
        break;

    case 3:
        printf("\n--- Remove last product ---\n");
        break;

    default:
        printf("\nInvalid option!\n");
        break;
    }
}while(choice != 6);

    return 0;
}