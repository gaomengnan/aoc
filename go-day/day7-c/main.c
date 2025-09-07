#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 实现类似 Python 的 array[:-1] 功能
int *slice_array(const int *array, size_t length, size_t *new_length) {
  if (length == 0) {
    *new_length = 0;
    return NULL; // 空数组
  }

  // 新数组的长度是原数组长度减 1
  *new_length = length - 1;

  // 分配内存给新数组
  int *new_array = (int *)malloc(*new_length * sizeof(int));
  if (new_array == NULL) {
    fprintf(stderr, "内存分配失败\n");
    exit(1);
  }

  // 复制原数组中除最后一个元素之外的所有元素
  for (size_t i = 0; i < *new_length; i++) {
    new_array[i] = array[i];
  }

  return new_array;
}

// 递归函数，查找表达式
bool can_obtain(int *nums, int target, int size) {
  if (size == 1) {
    return target == nums[0];
  }

  size_t new_length;
  int *new_s = slice_array(nums, size, &new_length);

  if (target % nums[size - 1] == 0 &&
      can_obtain(new_s, target / nums[size - 1], new_length)) {
    return true;
  }

  size_t new_length1;
  int *new_s1 = slice_array(nums, size, &new_length1);

  if (target > nums[size - 1] &&
      can_obtain(new_s1, target - nums[size - 1], new_length1)) {
    return true;
  }

  return false;
}

// READ FILE
void *readFile(char *filePath) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int ans = 0;

  fp = fopen(filePath, "r");
  if (fp == NULL) {
    printf("Failed To Read filePath:%s \n", filePath);
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    char *target_val = strtok(line, ":");
    char *after_token = strtok(NULL, ":");
    int capacity = 20;
    int count = 0;
    char **nums = (char **)malloc(capacity * sizeof(char *));

    char *token = strtok(after_token, " ");
    while (token != NULL) {
      if (count >= capacity) {
        capacity *= 2;
        nums = (char **)realloc(nums, capacity * sizeof(char *));
        if (nums == NULL) {
          printf("Failed to reallocate memory");
          exit(EXIT_FAILURE);
        }
      }
      nums[count] = strdup(token); // 复制 token 到新分配的内存
      if (nums[count] == NULL) {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
      }
      count++;
      token = strtok(NULL, " ");
    }

    int *arr = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
      arr[i] = atoi(nums[i]);
    }

    char current_expr[100] = "";

    if (can_obtain(arr, atoi(target_val), count)) {
      ans += atoi(target_val);
    }
    /* if (canAchieve) { */
    /*   ans += atoi(target_val); */

    /* } */

    for (int i = 0; i < count; i++) {
      free(nums[i]); // 释放 strdup 分配的内存
    }
    free(nums); // 释放 nums 数组
    free(arr);  // 释放 arr 数组
  }

  fclose(fp);
  if (line) {
    free(line);
  }

  printf("Part-1 ans is %d \n", ans);
  return 0;
}

int main() {
  readFile("./example.txt");
  readFile("./input.txt");
  return 0;
}
