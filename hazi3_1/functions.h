//
// Created by Administrator on 2023-03-04.
//

#ifndef HAZI3_1_FUNCTIONS_H
#define HAZI3_1_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <string.h>
enum Category{FRUIT, VEGETABLE, DIARY};
typedef struct{
    int year;
    int month;
    int day;
}Date_t;
typedef struct{
    char name[30];
    char barcode[10];
    char supplier[50];
    Date_t dateOfManufacture;
    enum Category category;
    double price;
}Product_t;
void readProductDetails(Product_t *pProduct);
void printProduct(Product_t product);
void allocateMemoryForProducts(Product_t **dpProducts, int numberOfProducts);
void readAllProductsDetails(Product_t **dpProducts, int *numberOfProducts, const char *input);
void printAllProducts(Product_t *pProducts, int numberOfProducts, const char *destination);
int getNumberOfProductsByCategory(Product_t *pProducts, int numberOfProducts, enum Category category);
void printProductsFromSpecificSupplier(Product_t *pProducts, int numberOfProducts, const char *supplier);
int cmp(const void *a, const void *b);
Product_t findProductByBarcode(Product_t *pProducts, int numberOfProducts, const char *barcode);
void sortProductsByName(Product_t *pProducts, int numberOfProducts);
void sortProductsByManufactureDateAndPrice(Product_t *pProducts, int numberOfProducts);

#endif //HAZI3_1_FUNCTIONS_H
