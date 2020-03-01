## 循环嵌套在控制台输出9*9乘法口诀表

```java
/*九九乘法表
* 分析: 一个for控制行，一个for控制列
* 变量: 列：int column, 行：int row
*/
package Exercise_while.work;

public class Multiplication_Ninety_nine_table {
    public static void main(String[] args) {
        for (int row = 1; row <= 9; row++) {
            for (int column = 1; column <= row; column++) {
                System.out.print(column + "*" + row + "=" + (row * column) + " ");
            }
            System.out.println();
        }
    }
}

```

## 公鸡5文钱一只，母鸡3文钱一只，小鸡3只一文钱，用100文钱买一百只鸡,其中公鸡，母鸡，小鸡都必须要有，问公鸡，母鸡，小鸡要买多少只刚好凑足100文钱


```java
/*百鸡问题
* 分析: 1.要满足问题条件需用三重嵌套for循环来做遍历判断
*      2.要满足三种种类的鸡都有则：for循环初始值为1且所有鸡总数不得超过100
*      3.要满足总金额等于100
*      4.小鸡必需为整数
* 变量: 母鸡:hen, 公鸡:cock, 小鸡:chick
*/
package Exercise_while.work;

public class Hundred_chicken {
    public static void main(String[] args) {
        for (int hen = 1; hen <= 100; hen++) {
            for (int cock = 1; cock <= 100; cock++) {
                for (int chick = 1; chick <= 100; chick++) {
                    if ((5 * hen + 3 * cock + chick / 3 == 100) && (hen + cock + chick == 100)
                           && (chick % 3 == 0)) {
                        System.out.println(" hen:" + hen + " cock:"
                                + cock+ " chick:" + chick);
                    }
                }
            }
        }
    }
}

```

## 控制台输入一个正整数，判断它是否为质数

```java
/*输入一个正整数判断是否为质数
* 分析: 质数判断条件1：大于1的自然数，2：除了1和它本身以外不再有其他因数的自然数。
* 变量: 质数个数：int a, 输入正整数：int num
*/
package Exercise_while.work;

import java.util.Scanner;

public class Prime_number {
    public static void main(String[] args) {
        int a = 0;  // 质数的个数
        Scanner input = new Scanner(System.in);
        System.out.println("输入一个正整数：");
        int num = input.nextInt();

        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                a++;       // 质数个数加1
            }
        }

        if (a == 0) {
            System.out.println(num + "是质数");
        } else {
            System.out.println(num + "不是质数");
        }
    }
}

```
