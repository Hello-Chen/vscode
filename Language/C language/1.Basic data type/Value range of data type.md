# <center> 1.Basic data type </center>

- [<center> 1.Basic data type </center>](#center-1basic-data-type-center)
    - [1.进制转换 1Byte == 8 bit](#1进制转换-1byte--8-bit)
    - [2. 打印显示进制和进制前缀](#2-打印显示进制和进制前缀)
    - [3. 数据类型](#3-数据类型)
    - [4. 在当前系统下查看](#4-在当前系统下查看)

### 1.进制转换 1Byte == 8 bit

![进制转换](https://gitee.com/Hello-Chen/Hello-Chen_Pictures/raw/master/res/20200212140102.png)

### 2. 打印显示进制和进制前缀

在计算机中以十进制显示数字，使用%d；以八进制显示数字，使用%o；以十六进制显示数字，使用%x。要显示各进制数的前缀 0、0x、0X，必须分别使用%#o、%#x、%#X。
>[data type.c](https://gitee.com/Hello-Chen/vscode/blob/master/C%20language/1.Value%20range/data%20type.c)

### 3. 数据类型

1. 整型： short long int
2. 浮点型：float double
3. 字符型：char
4. 布尔型\_Bool：true false 无符号int型
5. 有无符号型：signed unsigned 有无负数的区别 %u

> [sizeof.c](https://gitee.com/Hello-Chen/vscode/blob/master/C%20language/1.Value%20range/sizeof.c)

- **有符号整数类型**

  |         类型名称          | 字节数 |                         取值范围[^1]                         |
  | :-----------------------: | :----: | :----------------------------------------------------------: |
  |        signed char        |   1    |                  -2^7 > 2^7-1 (-128 > 127)                   |
  |     short int (short)     |   2    |               -2^15 > 2^15-1 (-32768 > 32767)                |
  |            int            |   4    |          -2^31 > 2^31-1 (-2147483648 > 2147483647)           |
  |      long int (long)      |   4    |          -2^31 > 2^31-1 (-2147483648 > 2147483647)           |
  | long long int (long long) |   8    | -2^63 > 2^63-1 (-9. 2233720368548e+18 > 9.2233720368548e+18) |

[^1]: n 为数据类型所占位数,如在 64 位系统中 int 通常为 4 字节，也就是 4\*8=32 位。（每个字节为 8 位）
有符号整型取值范围计算公式（2^(n-1), 2^(n-1) - 1）
无符号整型（0, 2^n）

- **无符号整数类型**
  | 类型名称 | 字节数 | 取值范围[^1] |
  | :----------------------------------------: | :----: | :--------------------------: |
  | unsigned char | 1 | 0 ~ 2^8(256) |
  | unsigned short int (short) | 2 | 0 ~ 2^16(65 536) |
  | unsigned int | 4 | 0 ~ 2^32(4 294 967 296) |
  | unsigned long int (unsignedlong) | 8 | 0 ~ 2^32(4 294 967 296) |
  | unsigned long long int (unsignedlong long) | 8 | 0 ~ 2^64(1.844674407371e+19) |

- **浮点类型**

  |  类型名称   | 字节数 |             取值范围             |
  | :---------: | :----: | :------------------------------: |
  |    float    |   4    |   -/+3.4e38（精确到 6 位小数）   |
  |   double    |   8    |  -/+1.7e308（精确到 15 位小数）  |
  | long double |   12   | -/+1.19e4932（精确到 18 位小数） |

### 4. 在当前系统下查看

```c
/*获取char数据类型的取值范围*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(void)
{
  printf("char:MIN %d;MAX %d\n", CHAR_MIN, CHAR_MAX);

    system("pause");
}
```

> 很多程序员和组织都有系统化的变量命名规则,其中变量的名字可以表示它的类型。
    例如:使用前缀表示int变量,使用us_表示 unsigned short变量。
    这样通过名字就可以确定变量smart为int类型,变量us_ verysmart为 unsigned short类型
> > _C Primer Plus 第六版_
