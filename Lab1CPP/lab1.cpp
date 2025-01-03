#include <cstdio>
#include <stdexcept>
#include "array.h"

Array* array_create_and_read(FILE* input)
{
    int n;
    if (fscanf(input, "%d", &n) < 1) throw std::invalid_argument("Failed to read size");
    /* Create array */
    Array* arr = array_create(n);
    /* Read array data */
    for (int i = 0; i < n; ++i)
    {
        int x;
        if (fscanf(input, "%d", &x) < 1) throw std::invalid_argument("Failed to read number");
        array_set(arr, i, x);
    }

    return arr;
}

void task1(Array* arr)
{
    int sum1 = 0;
    int sum2 = 0;
    size_t size = array_size(arr);

    for (size_t index{ 0 }; index < size; ++index) {
        if (array_get(arr, index) > 20) {
            sum1 += (int)array_get(arr, index);
        }
        if (array_get(arr, index) < 50) {
            sum2 += (int)array_get(arr, index);
        }
    }
    if (sum1 > 100) {
        printf("A: True\n");
    }
    else {
        printf("A: False\n");
    }
    if (sum2 % 2 == 0) {
        printf("B: True\n");
    }
    else {
        printf("B: False\n");
    }
}

void task2(Array* arr)
{
    size_t size = array_size(arr);
    Array* printed = array_create(size);
    size_t printed_count = 0;

    for (size_t index{ 0 }; index < size; ++index) {
        int currentValue = (int)array_get(arr, index);
        int count = 0;


        for (size_t index1{ 0 }; index1 < size; ++index1) {
            if (array_get(arr, index1) == currentValue) {
                count++;
            }
        }


        if (count == 2) {

            bool already_printed = false;
            for (size_t j = 0; j < printed_count; ++j) {
                if (array_get(printed, j) == currentValue) {
                    already_printed = true;
                    break;
                }
            }


            if (!already_printed) {
                printf("%d\n", currentValue);
                array_set(printed, printed_count++, currentValue);
            }
        }
    }

    array_delete(printed);
}

int main(__attribute__((unused)) int argc, char** argv)
{
    Array* arr = NULL;
    FILE* input = fopen(argv[1], "r");
    arr = array_create_and_read(input);
    task1(arr);
    array_delete(arr);
    /* Create another array here */
    arr = array_create_and_read(input);
    task2(arr);
    array_delete(arr);

    fclose(input);
    return 0;
}
