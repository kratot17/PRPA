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
    return arr;
}

void srt(int *arr, int el_in_total)
{
    int dup = 0, dup_cnt = 1, dup_grps = 0, sub_len = 1, sub_cnt = 0, min = 0, counter = 0, local_min = 0, local_max = 0;

    // zjistit sub_len a dup
    for (sub_len; dup_grps < 2; sub_len++)
    {
        for (int i = 0; i < sub_len; i++)
        {
            if ((*(arr + i) == *(arr + sub_len)) && *(arr + i) != dup)
            {
                if (counter == 0)
                {
                    dup = *(arr + sub_len);
                    counter++;
                }
                dup_grps++;
                break;
            }
        }
        if (*(arr + sub_len) == dup)
            dup_cnt++;
    }
    sub_len--;
    printf("dup: %i dup_cnt: %i\n", dup, dup_cnt);

    int *tmp = (int *)calloc(sub_len, sizeof(int));
    for (int i = 0; i < sub_len; i++) // rewrite tmp
        *(tmp + i) = *(arr + i);
    prnt_arr(tmp, sub_len);

    // sort prvni casti
    local_min = *tmp;
    for (int i = 0; i < sub_len; i++) // gets minimum from tmp
    {
        if (*(tmp + i) < local_min)
            local_min = *(tmp + i);
    }
    local_max = *tmp;
    for (int i = 0; i < sub_len; i++) // gets maximum from tmp
    {
        if (*(tmp + i) > local_max)
            local_max = *(tmp + i);
    }
    int *tmp2 = (int *)calloc(sub_len, sizeof(int)); // sorted array

    for (int i = 0; i < sub_len; i++)
    {
        for (int j = 0; j < sub_len; j++)
        {
            if (*(tmp + j) == local_min)
            {
                *(tmp2 + i) = *(tmp + j);
                local_min++;
                break;
            }
            else if (*(tmp + j) != local_min)
            {
                local_min++;
                break;
            }
        }
    }

    prnt_arr(tmp2, sub_len);

    int *rst = (int *)calloc(el_in_total - sub_len, sizeof(int));
    for (int i = 0; i < el_in_total - sub_len; i++) // rewrite rst
    {
        *(rst + i) = *(arr + i + sub_len);
    }
    prnt_arr(rst, el_in_total - sub_len);

    // opsat zpet

    free(tmp);
    free(rst);
    free(tmp2);

    // while (sub_len != el_in_total)
    // {

    // }
}

int main()
{
    int el_in_frst_blck = 10, el_in_total = 0, ret_val = 0, frst_el = 0, min = 0, max = 0;
    float med = 0;

    int *arr = scan_arr(el_in_frst_blck, &el_in_total, &frst_el, &min, &max);
    printf("before sort:\n");
    prnt_arr(arr, el_in_total);

    // printf("Median %.2f\n", med);
    // printf("Pocet cisel: %i\n", el_in_total);
    // printf("Min. hodnota: %i\n", min);
    // printf("Max. hodnota: %i\n", max);

    srt(arr, el_in_total);
    printf("after sort:\n");
    prnt_arr(arr, el_in_total);

    free(arr);
    return ret_val;
}
