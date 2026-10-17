#include <stdio.h>

int main() {
    // --- INVENTORY DATA ---
    char* product_name[] = {"Bread", "Milk", "Eggs", "Rice", "Coffee"};
    int product_prices[] = {30, 45, 80, 120, 150};
    
    // --- DATA STORAGE (CART) ---
    int cart_item_ids[100];
    int cart_quantities[100];
    int total_items = 0;
    
    int choice;
    
    // --- THE ENGINE ---
    do {
        printf("\n================================\n");
        printf("      SMART SUPERMARKET\n");
        printf("================================\n");
        printf("1. Add product\n");
        printf("2. View current bill\n");
        printf("3. Remove last product\n");
        printf("4. Apply discount\n");
        printf("5. Checkout and pay\n");
        printf("6. Exit\n");
        printf("================================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
                printf("\n--- Add a product ---\n");
                int selected_id, quantity;
                
                printf("Available products:\n");
                printf("1. Bread - 30\n2. Milk - 45\n3. Eggs - 80\n4. Rice - 120\n5. Coffee - 150\n");
                
                printf("Enter product ID(1-5): ");
                scanf("%d", &selected_id);
                
                if (selected_id < 1 || selected_id > 5) {
                    printf("Error: Invalid product ID!\n");
                    break; 
                }

                printf("Enter quantity: ");
                scanf("%d", &quantity);

                if (quantity <= 0) {
                    printf("Error: Invalid quantity!\n");
                    break;
                }

                cart_item_ids[total_items] = selected_id - 1; 
                cart_quantities[total_items] = quantity;
                total_items++;
                printf("Product added to cart!\n");
                
                break;
            } 
            
            case 2: { 
                printf("\n========== CURRENT BILL ==========\n");
                printf("Product\t\tQty\tPrice\tTotal\n");
                printf("------------------------------------------\n");
                
                int subtotal = 0;
                
                for (int i = 0; i < total_items; i++) {
                    int stored_id = cart_item_ids[i];
                    int qty = cart_quantities[i];
                    int price = product_prices[stored_id];
                    
                    int line_total = price * qty;
                    subtotal = subtotal + line_total;
                    
                    printf("%s\t\t%d\t%d\t%d\n", product_name[stored_id], qty, price, line_total);
                }
                
                printf("------------------------------------------\n");
                printf("Subtotal:\t\t\t%d\n", subtotal);
                printf("==========================================\n");
                break;
            } 
            
            case 3: { 
                printf("\n--- Remove last product ---\n");
                if (total_items > 0) {
                    total_items--; 
                    printf("Last purchase removed successfully!\n");
                } else {
                    printf("Error: The cart is already empty!\n");
                }
                break;
            } 
            
            case 4: { 
                printf("\n--- Apply discount ---\n");
                int subtotal = 0;
                
                // Calculate subtotal
                for (int i = 0; i < total_items; i++) {
                    int stored_id = cart_item_ids[i];
                    int qty = cart_quantities[i];
                    int price = product_prices[stored_id];
                    subtotal += price * qty;
                }
                
                // Apply discount logic
                if (subtotal > 500) {
                    subtotal *= 0.9; // 10% discount
                    printf("A 10%% discount has been applied!\n");
                } else {
                    printf("No discount applicable.\n");
                }
                
                printf("New Subtotal: %d\n", subtotal);
                break;
            } 
            
            case 5: { 
                printf("\n--- Checkout and pay ---\n");
                int subtotal = 0;       
                break; 
            } 
            
            case 6: {
                printf("\nExiting...\n");
                break;
            }

            default: {
                printf("\nInvalid option!\n");
                break;
            }
        } // <-- THIS WAS THE MISSING BRACE TO CLOSE THE SWITCH!
        
    } while(choice != 6);

    return 0;
}