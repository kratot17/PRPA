#include <stdio.h>
#include <stdlib.h>

void prnt_arr(int *arr, int el_in_total)
{
    for (int i = 0; i < el_in_total; i++)
    {
        printf("%i ", *(arr + i));
    }
    printf("\n");
}

int *scan_arr(int el_in_frst_blck, int *el_in_total, int *frst_el, int *min, int *max)
{
    int el_in_blck = el_in_frst_blck, el_counter = 0, scan_out = 0, input = 0;
    int *arr = (int *)calloc(el_in_blck, sizeof(int));
    int *tmp;

    while (1)
    {
        scan_out = scanf("%i", &input);
        if (scan_out == 1) // if scan was successful
        {
            if (*el_in_total == 0)
            {
                *min = input;
                *max = input;
                *frst_el = input;
            }
            *(arr + *el_in_total) = input;
            if (input > *max)
                *max = input;
            if (input < *min)
                *min = input;
            el_counter++;
            (*el_in_total)++;
        }
        // printf("scan_out: %i el_in_blck: %i el_counter: %i el_in_total: %i input: %i\n", scan_out, el_in_blck, el_counter, *el_in_total, input);
        if ((scan_out != 1) || (el_counter >= el_in_blck))
        {
            el_in_blck *= 2;
            tmp = realloc(arr, (*el_in_total + el_in_blck) * sizeof(int)); // add tmp block to arr
            arr = tmp;
            if (tmp != arr) // free if new array is at different address
                free(tmp);
            el_counter = 0;
        }
        if (scan_out != 1)
        {
            tmp = realloc(arr, *el_in_total * sizeof(int)); // clean array from unscaned elements
            arr = tmp;
            if (tmp != arr) // free if new array is at different address
                free(tmp);
            break;
        }
    }
    *el_in_total -= 1;
    return arr;
}

int cmp_func(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int el_in_frst_blck = 10, el_in_total = 0, ret_val = 0, frst_el = 0, min = 0, max = 0;
    float med = 0;

    int *arr = scan_arr(el_in_frst_blck, &el_in_total, &frst_el, &min, &max);
    // printf("before sort:\n");
    // prnt_arr(arr, el_in_total);

    qsort(arr, el_in_total, sizeof(int), cmp_func);
    // printf("after sort:\n");
    // prnt_arr(arr, el_in_total);

    if (el_in_total % 2 == 0)
        med = (float)(*(arr + (el_in_total - 1) / 2) + *(arr + (el_in_total - 1) / 2 + 1)) / 2;
    else
        med = *(arr + (int)(el_in_total / 2 + 0.5));

    printf("Median %.2f\n", med);
    printf("Pocet cisel: %i\n", el_in_total);
    printf("Min. hodnota: %i\n", min);
    printf("Max. hodnota: %i\n", max);

    free(arr);
    return ret_val;
}
