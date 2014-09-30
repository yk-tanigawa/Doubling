#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST_DATA_SIZE 16


typedef enum basechar_{
  /* 塩基をtypedef enumでコードする
   * 入力データはchar型だが，プログラム内部ではbasechar型
   * として取り扱う。 */
  $,
  A,
  C,
  G,
  T,
  N,
} basechar;

basechar *debug_test_rand_data(int);
basechar *debug_test_data(void);
inline basechar data_i_to_basechar(int);
inline basechar data_c_to_basechar(char);
basechar *data_ary_c_to_basechar(char *, int);
inline char data_basechar_to_c(basechar);

#if 0
basechar *debug_test_rand_data(int num)
{
  int i;
  for(i = 0; i < num; i++){
    ary[i] = data_n_to_i(genrand_int32());
  }
  return ary;
}
#endif

basechar *debug_test_data(void)
{
  char test[TEST_DATA_SIZE] = "ATAATACGATAATAA$";
  basechar *ary = calloc(TEST_DATA_SIZE, sizeof(basechar));
  ary = data_ary_c_to_basechar(test, strlen(test));
  return ary;
}

inline basechar data_i_to_basechar(int i)
{ /* 数値iをbasechar (enumで実装)に変換する */
  basechar n;
  if      (i == 0){ n = $;}
  else if (i == 1){ n = A;}
  else if (i == 2){ n = C;}
  else if (i == 3){ n = G;}
  else if (i == 4){ n = T;}
  else {n = N;}
  return n;
}


inline basechar data_c_to_basechar(char c)
{ /* 文字cをbasechar (enumで実装)に変換する */
  basechar n;
  if      (c == '$'){ n = $;}
  else if (c == 'A'){ n = A;}
  else if (c == 'C'){ n = C;}
  else if (c == 'G'){ n = G;}
  else if (c == 'T'){ n = T;}
  else              {n = N;}
  /* よくわからないデータはNとする */
  return n;
}

basechar *data_ary_c_to_basechar(char *c, int num)
{ /* charの配列として与えられたデータを
   * basecharの配列に変換する */
  int i;
  basechar *ary = calloc(num, sizeof(int));
  for(i = 0; i < num; i++){
    ary[i] = data_c_to_basechar(c[i]);
  };
  return ary;
}

inline char data_basechar_to_c(basechar n)
{/* basechar型の文字nを受け取って
  * char型の文字として返す */
  char c;
  if     (n == $){c = '$';}
  else if(n == A){c = 'A';}
  else if(n == C){c = 'C';}
  else if(n == G){c = 'G';}
  else if(n == T){c = 'T';}
  else           {c = 'N';}
  /* よくわからないデータはNとする */
  return c;
}

void data_show(basechar *ary, int length)
{/* 長さlengthのbasecharの配列aryの中身を出力する */
  int i;
  for(i = 0; i < length; i++){
    printf("%c", data_basechar_to_c(ary[i]));
    if( (i + 1) % 30 == 0 || i == (length - 1) ){
      printf("\n");
    }
  }
  return;
} 
    

int main(void)
{
  basechar *data = debug_test_data();
  data_show(data, 16);
  free(data);  
  return 0;
}
