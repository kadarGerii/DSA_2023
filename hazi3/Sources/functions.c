//
// Created by Administrator on 2023-03-01.
//

#include "../Headers/functions.h"
void readProductDetails(Product_t *pProduct){
    scanf("\n%[^\n]", pProduct ->name);
    scanf("\n%[^\n]", pProduct ->barcode);
    scanf("\n%[^\n]", pProduct ->supplier);
    scanf("%d%d%d", &pProduct ->dateOfManufacture.year, &pProduct -> dateOfManufacture.month, &pProduct -> dateOfManufacture.day);
    scanf("%d", &pProduct ->category);
    scanf("%lf", &pProduct ->price);
}
void printProduct(Product_t product){
    printf("%s", product.name);
    printf("%s", product.barcode);
    printf("%s", product.supplier);
    printf("%d / %d / %d", product.dateOfManufacture.year, product.dateOfManufacture.month, product.dateOfManufacture.day);
    printf("%d", product.category);
    printf("%0.2f", product.price);
}
void allocateMemoryForProducts(Product_t **dpProducts, int numberOfProducts){
    *dpProducts = (Product_t*)malloc(numberOfProducts*sizeof (Product_t));
    if(*dpProducts == NULL){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void readAllProductsDetails(Product_t **dpProducts, int *numberOfProducts, const char *input){
    if(!freopen(input, "r", stdin)){
        printf("%s", FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%d", numberOfProducts);
    allocateMemoryForProducts(&*dpProducts, *numberOfProducts);
    for (int i = 0; i < *numberOfProducts; ++i) {
        readProductDetails(&(*dpProducts)[i]);
    }
    freopen("CON", "r", stdin);
}
void printAllProducts(Product_t *pProducts, int numberOfProducts, const char *destination){
    if(!freopen(destination, "w", stdout)){
        printf("%s", FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    for (int i = 0; i < numberOfProducts; ++i) {
        printProduct(pProducts[i]);
    }
}
