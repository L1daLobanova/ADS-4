// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if ((arr[i] + arr[j]) == value)
        k += 1;
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > value)
      continue;
    for (int j = len - 1; j > i; j--) {
      if (arr[j] > value)
        continue;
      if ((arr[i] + arr[j]) == value)
        k += 1;
    }
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
      int start = i, end = len, nado = value - arr[i];
      while ((end - start) > 1) {
          int mid = (start + end) / 2;
          if (arr[mid] == nado) {
              k++;
              int top = mid + 1;
              while (arr[top] == nado && top < end) {
                  k++;
                  top++;
              }
              top = mid - 1;
              while (arr[top] == nado && top > start) {
                  k++;
                  top--;
              }
              break;
          }
          if (arr[mid] > nado)
              end = mid;
          if (arr[mid] < nado)
              start = mid;
      }
  }
  return k;
}
