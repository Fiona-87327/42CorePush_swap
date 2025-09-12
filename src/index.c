#include "push_swap.h"

static void swap_int(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}

static int partition(int *arr, int lo, int hi)
{
    int pivot = arr[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i+1], &arr[hi]);
    return i + 1;
}

static void quicksort(int *arr, int lo, int hi)
{
    if (lo >= hi) return;
    int p = partition(arr, lo, hi);
    quicksort(arr, lo, p - 1);
    quicksort(arr, p + 1, hi);
}

void assign_indices(t_node *a)
{
    int n = stack_size(a);
    if (n <= 0) return;
    int *vals = (int *)xmalloc(sizeof(int) * n);
    int i = 0;
    for (t_node *p = a; p; p = p->next)
        vals[i++] = p->value;
    quicksort(vals, 0, n - 1);
    /* map value -> rank via binary search */
    for (t_node *p = a; p; p = p->next)
    {
        int lo = 0, hi = n - 1, rank = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (vals[mid] == p->value)
            {
                rank = mid;
                break;
            }
            else if (vals[mid] < p->value) lo = mid + 1;
            else hi = mid - 1;
        }
        p->index = rank;
    }
    free(vals);
}