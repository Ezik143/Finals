#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

const char *choices[10] = {"1. Bubble sort", "2. find the smallest missing number", "3. find the maximum and minimum numbers", "4. reverse an array", "5. Count odd and even numbers", "6. sum and average", "7. search an element in an array", "8. merge 2 arrays", "9. Calculate the mean, median, mode", "10. Exit"};

void clear_stdin()
{
    long long c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void swap(long long *arr, long long left, long long right)
{
    long long temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void print_arr(long long *arr, long long arr_len, char *name)
{
    printf("%s\n", name);
    for (long long i = 0; i < arr_len; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

void input_y_n(char *var_to_store, char *question)
{
    char inputed_var;
    do
    {
        printf("%s(y or n)?\n", question);
        (*var_to_store) = getch();
        inputed_var = *var_to_store;
    } while (inputed_var != 'y' && inputed_var != 'Y' && inputed_var != 'n' && inputed_var != 'N');
}

void ask_questions(long long *arr[], long long *arr_len)
{
    system("cls");
    long long arr_len_val;
    long long res;
    do
    {
        printf("input array length: ");
        res = scanf("%lld", arr_len);
        clear_stdin();
        arr_len_val = *arr_len;
    } while (arr_len_val < 1 || res == 0);
    (*arr) = malloc(arr_len_val * sizeof(long long));
    char ch;
    for (long long i = 0; i < arr_len_val; i++)
    {
        printf("input val %lld: ", i + 1);
        res = scanf("%lld", &((*arr)[i]));
        if (res != 1 || (ch = getchar()) != '\n')
        {
            i--;
        }
        if (ch != '\n')
        {
            clear_stdin();
        }
    }
}

// 1. bubble sort
void bubble_sort(long long *arr, long long arr_len)
{
    for (long long i = 0; i < arr_len; i++)
    {
        for (long long j = 0; j < arr_len - i - 1 ; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
    print_arr(arr, arr_len, "sorted array");
}

// 2. find the smallest missing number
void smallest_missing_number(long long *arr, long long arr_len)
{
    long long unique_elem;
    long long unique_elem_arr_len = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        if (i == 0)
        {
            unique_elem = arr[i];
            unique_elem_arr_len++;
            continue;
        }
        if (arr[i] != unique_elem)
        {
            unique_elem = arr[i];
            unique_elem_arr_len++;
        }
    }
    long long *unique_elem_arr = malloc(unique_elem_arr_len * sizeof(long long));
    unique_elem = 0;
    long long unique_elem_cnt = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        if (arr[i] != unique_elem)
        {
            unique_elem_arr[unique_elem_cnt] = arr[i];
            unique_elem = arr[i];
            unique_elem_cnt++;
        }
    }
    bubble_sort(unique_elem_arr, unique_elem_arr_len);
    long long smallest_num = 0;
    long long first_pos = 1;
    for (long long i = 0; i < unique_elem_arr_len; i++)
    {

        if (first_pos)
        {
            if (unique_elem_arr[i] != smallest_num && i != 0)
            {
                printf("smallest missing num: %lld\n", smallest_num);
                free(unique_elem_arr);
                return;
            }
            first_pos = 0;
            smallest_num = unique_elem_arr[i];
            smallest_num++;
            continue;
        }
        if (unique_elem_arr[i] != smallest_num)
        {
            printf("smallest missing num: %lld\n", smallest_num);
            free(unique_elem_arr);
            return;
        }
        smallest_num++;
    }
    printf("no smallest missing number\n");
    free(unique_elem_arr);
}

// 3. find the maximum and minimum numbers
void find_min_max(long long *arr, long long arr_len)
{
    long long smallest = arr[0];
    long long biggest = smallest;
    for (long long i = 0; i < arr_len; i++)
    {
        long long cur_num = arr[i];
        if (cur_num < smallest)
            smallest = cur_num;
        if (cur_num > biggest)
            biggest = cur_num;
    }
    printf("smallest: %lld\n", smallest);
    printf("biggest: %lld\n", biggest);
}

// 4. reverse an array
void rev_arr(long long *arr, long long arr_len)
{
    long long right_i = arr_len - 1;
    for (long long i = 0; i < arr_len / 2; i++)
    {
        swap(arr, right_i, i);
        right_i--;
    }
    print_arr(arr, arr_len, "reverse array");
}

// 5. Count odd and even numbers
void odd_even(long long *arr, long long arr_len)
{
    long long odd_cnt = 0, even_cnt = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        if ((long long)arr[i] % 2 == 0)
        {
            even_cnt++;
        }
        else
        {
            odd_cnt++;
        }
    }
    printf("odd count: %lld\n", odd_cnt);
    printf("even count: %lld\n", even_cnt);
}

// 6. sum and average
void sum_average(long long *arr, long long arr_len)
{
    long long sum = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        sum += arr[i];
    }
    float average = (float)sum / (float)arr_len;
    printf("sum: %lld\n", sum);
    printf("average: %f\n", average);
}

// 7. search an element in an array
void get_elem(long long *arr, long long arr_len, long long elem_to_find)
{
    int count = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        if (arr[i] == elem_to_find)
        {
            printf("found elem at index {%lld}\n", i);
            count++;
        }
    }
    if (count == 0)
    {
        printf("Could't find element\n");
        return;
    }
}

// 8. merge 2 arrays
void merge_arr(long long *first_arr, long long *second_arr, long long first_arr_len, long long second_arr_len)
{
    print_arr(first_arr, first_arr_len, "1st array");
    print_arr(second_arr, second_arr_len, "2nd array");
    long long merged_arr_len = first_arr_len + second_arr_len;
    long long *merged_arr = malloc((merged_arr_len) * sizeof(long long));
    for (long long i = 0; i < first_arr_len; i++)
    {
        merged_arr[i] = first_arr[i];
    }
    for (long long i = 0; i < second_arr_len; i++)
    {
        merged_arr[first_arr_len + i] = second_arr[i];
    }
    print_arr(merged_arr, merged_arr_len, "merged array");
    free(merged_arr);
}

// 9. Calculate the mean, median, mode
void get_stats(long long *arr, long long arr_len)
{
    float median, mean = 0.0f;
    long long mode = 0;
    bubble_sort(arr, arr_len);
    if (arr_len % 2 == 0)
        median = (float)(arr[arr_len / 2] + arr[(arr_len / 2) - 1]) / 2.0f;
    else
        median = (float)arr[arr_len / 2];
    for (long long i = 0; i < arr_len; i++)
    {
        mean += arr[i];
    }
    mean /= (float)arr_len;
    long long unique_elem = 0;
    long long unique_elem_arr_len = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        if (arr[i] != unique_elem)
        {
            unique_elem = arr[i];
            unique_elem_arr_len++;
        }
    }
    long long *unique_elem_arr = malloc(unique_elem_arr_len * sizeof(long long));
    unique_elem = 0;
    long long unique_elem_cnt = 0;
    for (long long i = 0; i < arr_len; i++)
    {
        if (arr[i] != unique_elem)
        {
            unique_elem_arr[unique_elem_cnt] = arr[i];
            unique_elem = arr[i];
            unique_elem_cnt++;
        }
    }
    long long *unique_elem_freq_arr = malloc(unique_elem_arr_len * sizeof(long long));
    for (long long i = 0; i < unique_elem_arr_len; i++)
    {
        unique_elem_freq_arr[i] = 0;
    }
    for (long long i = 0; i < unique_elem_arr_len; i++)
        for (long long j = 0; j < arr_len; j++)
            if (unique_elem_arr[i] == arr[j])
                unique_elem_freq_arr[i]++;
    long long largest_freq = 0;
    bool same_freq = false;
    for (long long i = 0; i < unique_elem_arr_len; i++)
    {
        if (unique_elem_freq_arr[i] > largest_freq)
        {
            largest_freq = unique_elem_freq_arr[i];
            mode = unique_elem_arr[i];
            same_freq = false;
        }
        else if (unique_elem_freq_arr[i] == largest_freq)
        {
            same_freq = true;
        }
    }
    printf("mean: %.2f\n", mean);
    printf("median: %.2f\n", median);
    if (same_freq)
    {
        printf("no mode\n");
    }
    else
    {
        printf("mode: %lld\n", mode);
    }
    free(unique_elem_arr);
    free(unique_elem_freq_arr);
}

long long main()
{
    long long *arr = NULL, arr_len = 0, choice = 0;
    bool exited = false;
    while (!exited)
    {
        system("cls");
        printf("%c", 201);
        for (long long i = 0; i < 42; i++)
            printf("%c", 205);
        printf("%c\n", 187);
        printf("%c                                          %c\n", 186, 186);
        printf("%c            Up key to move up             %c\n", 186, 186);
        printf("%c          Down key to move down           %c\n", 186, 186);
        printf("%c             Enter to select              %c\n", 186, 186);
        printf("%c                Main Menu                 %c\n", 186, 186);
        printf("%c                                          %c\n", 186, 186);
        printf("%c", 204);
        for (long long i = 0; i < 42; i++)
            printf("%c", 205);
        printf("%c\n", 185);
        printf("%c                                          %c\n", 186, 186);
        for (long long i = 0; i < 10; i++)
        {
            if (choice == i)
            {
                printf("%c \x1b[36m> %s\x1b[0m", 186, choices[i]);
            }
            else
            {
                printf("%c   %s", 186, choices[i]);
            }
            long long spaces = (42 - strlen(choices[i])) - 3;
            for (long long i = 0; i < spaces; i++)
            {
                printf(" ");
            }
            printf("%c\n", 186);
        }
        printf("%c                                          %c\n", 186, 186);
        printf("%c", 200);
        for (long long i = 0; i < 42; i++)
            printf("%c", 205);
        printf("%c\n", 188);
        char input;
        if (kbhit())
        {
            input = getch();
            if (input == 72 && choice != 0)
                // up key pressed
                choice--;
            else if (input == 80 && choice != 9)
                // down key pressed
                choice++;
        }
        else
            input = getch();
        if (input == '\x0D')
        {
            char try_again = 'y';
            while (try_again == 'y' || try_again == 'Y')
            {
                if (choice == 9)
                {
                    exited = true;
                    break;
                }
                ask_questions(&arr, &arr_len);
                system("cls");
                print_arr(arr, arr_len, "given array");
                switch (choice)
                {
                case 0:
                    bubble_sort(arr, arr_len);
                    break;
                case 1:
                    smallest_missing_number(arr, arr_len);
                    break;
                case 2:
                    find_min_max(arr, arr_len);
                    break;
                case 3:
                    rev_arr(arr, arr_len);
                    break;
                case 4:
                    odd_even(arr, arr_len);
                    break;
                case 5:
                    sum_average(arr, arr_len);
                    break;
                case 6:
                {
                    long long elem_to_get = 0;
                    printf("element to get: ");
                    long long res = 0;
                    while (res == 0)
                    {
                        res = scanf("%lld", &elem_to_get);
                        clear_stdin();
                    }
                    get_elem(arr, arr_len, elem_to_get);
                    break;
                }
                case 7:
                {
                    long long second_arr_len;
                    long long *second_arr;
                    ask_questions(&second_arr, &second_arr_len);
                    merge_arr(arr, second_arr, arr_len, second_arr_len);
                    free(second_arr);
                    break;
                }
                case 8:
                    get_stats(arr, arr_len);
                    break;
                }
                input_y_n(&try_again, "try again");
            }
        }
    }
    system("cls");
    printf("Goodbye!\n");
    if (arr != NULL)
    {
        free(arr);
    }
    return 0;
}

// Reminder replace eve i and j in a for loop with index and inner index
