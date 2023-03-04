//
// Created by Administrator on 2023-03-04.
//

#include "functions.h"

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
int getNumberOfProductsByCategory(Product_t *pProducts, int numberOfProducts, enum Category category){
    int sum = 0;
    for (int i = 0; i < numberOfProducts; ++i){
        if (pProducts[i].category == category)
            sum++;
    }
    return sum;
}
void printProductsFromSpecificSupplier(Product_t *pProducts, int numberOfProducts, const char *supplier){
    for (int i = 0; i < numberOfProducts; ++i){
        if (strcmp(pProducts[i].supplier, supplier) == 0) {
            printProduct(pProducts[i]);
        }
    }
}
int cmp(const void *a, const void *b){
    Product_t *p = (Product_t*)a;
    Product_t *q = (Product_t*)b;
    return strcmp(p->barcode, q ->barcode);
}
Product_t findProductByBarcode(Product_t *pProducts, int numberOfProducts, const char *barcode){
    qsort(pProducts, numberOfProducts,sizeof(Product_t), cmp);
    Product_t search;
    strncpy(search.barcode, barcode,sizeof(search.barcode));
    Product_t *searchResult = (Product_t*)bsearch(search.barcode, pProducts, numberOfProducts, sizeof(Product_t), cmp);
    return *searchResult;
}
int cmpName(const void *a, const void *b){
    Product_t *p = (Product_t*)a;
    Product_t *q = (Product_t*)b;
    return strcmp(p->name, q ->name);
}
void sortProductsByName(Product_t *pProducts, int numberOfProducts){
    qsort(pProducts, numberOfProducts,sizeof(Product_t), cmpName);
    printAllProducts(pProducts, numberOfProducts, "CON");

}
int cmpDate(const void *a, const void *b){
    Product_t *p = (Product_t*)a;
    Product_t *q = (Product_t*)b;
    if (p->dateOfManufacture.year > q -> dateOfManufacture.year){
        return 1;
    }
    else if (p -> dateOfManufacture.year < q -> dateOfManufacture.year) {
        return 0;
    }
    else{
        if (p -> dateOfManufacture.month > q -> dateOfManufacture.month)
            return 0;
        else if (p -> dateOfManufacture.month < q -> dateOfManufacture.month)
            return 1;
        else {
            if (p->dateOfManufacture.day > q->dateOfManufacture.day)
                return 1;
            else if (p->dateOfManufacture.day < q->dateOfManufacture.day)
                return 0;
            else{
                if(p->price > q->price)
                    return 0;
                else if(p->price < q -> price)
                    return 1;
                else return -1;
            }
        }
    }
}
void sortProductsByManufactureDateAndPrice(Product_t *pProducts, int numberOfProducts){
    qsort(pProducts, numberOfProducts,sizeof(Product_t), cmpDate);
    printAllProducts(pProducts, numberOfProducts, "CON");
}