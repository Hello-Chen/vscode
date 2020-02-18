# <center> 2.String & standrad IO </center>

### 函数：strlen()

strlen()函数给出字符串中的字符长度。
string.h提供strlen函数原型

### 关键字：const

C90标准新增了const关键字，用于限定一个变量为只读

**C头文件limits.h和float.h分别提供了与整数类型和浮点类型大小限制相
关的详细信息。**

![limits.h](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/HelloChen_2020-02-17_14-19-25-2020-2-17-14-20-54.png)

![float.h](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200217142350-2020-2-17-14-23-51.png)

### 字符串

C语言没有专门用于储存字符串的变量类型，字符串都被储存在char类
型的数组中。数组由连续的存储单元组成，字符串中的字符被储存在相邻的
存储单元中，每个单元储存一个字符

![储存字符串](https://gitee.com/Hello-Chen/Hello-Chen_Pictures/raw/master/res/20200215111911.png)

数组末尾位置的字符\0。这是空字符（null character），C
语言用它标记字符串的结束。空字符不是数字0，它是非打印字符，其ASCII
码值是（或等价于）0。C中的字符串一定以空字符结束，这意味着数组的
容量必须至少比待存储字符串中的字符数多1。因此，程序清单4.1中有40个
存储单元的字符串，只能储存39个字符，剩下一个字节留给空字符。

### 如何创建、存储字符串

char (name) [字符长度，不填默认/0结束] = {可赋值 "String"'String'}；

### Printf

![Printf转换](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200217143030-2020-2-17-14-30-30.png)

![Printf转换修饰符](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200217143633-2020-2-17-14-36-33.png)

###　Scanf

![Scanf转换](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200217150159-2020-2-17-15-2-0.png)

![Scanf转换修饰符](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200217150814-2020-2-17-15-8-14.png)

### *转换修饰符

==skiptwo.c==
