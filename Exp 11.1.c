#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
    struct Term *next;
};

struct Term *createTerm(int coeff, int exp)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term **poly, int coeff, int exp)
{
    if (coeff == 0)
        return;
    struct Term *newTerm = createTerm(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp)
    {
        newTerm->next = *poly;
        *poly = newTerm;
    }
    else
    {
        struct Term *current = *poly;
        while (current->next != NULL && current->next->exp > exp)
        {
            current = current->next;
        }
        if (current->exp == exp)
        {
            current->coeff += coeff;
            free(newTerm);
            if (current->coeff == 0)
            { // Remove term if coeff becomes 0
                struct Term *temp = *poly;
                if (temp == current)
                {
                    *poly = current->next;
                }
                else
                {
                    struct Term *prev = *poly;
                    while (prev->next != current)
                        prev = prev->next;
                    prev->next = current->next;
                }
                free(current);
            }
        }
        else
        {
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    struct Term *current1 = poly1;
    struct Term *current2 = poly2;

    while (current1 != NULL)
    {
        insertTerm(&result, current1->coeff, current1->exp);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        insertTerm(&result, current2->coeff, current2->exp);
        current2 = current2->next;
    }

    return result;
}

void printPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }
    struct Term *current = poly;
    while (current != NULL)
    {
        if (current->coeff > 0 && current != poly)
        {
            printf("+");
        }
        printf("%dx^%d ", current->coeff, current->exp);
        current = current->next;
    }
    printf("\n");
}

void freePolynomial(struct Term *poly)
{
    struct Term *current = poly;
    while (current != NULL)
    {
        struct Term *temp = current;
        current = current->next;
        free(temp);
    }
}

void inputPolynomial(struct Term **poly)
{
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

int main()
{
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;

    printf("Enter first polynomial:\n");
    inputPolynomial(&poly1);

    printf("Enter second polynomial:\n");
    inputPolynomial(&poly2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Term *result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}