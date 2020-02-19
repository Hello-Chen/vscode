|      Android 版本       |       版本名        | API |       发布时间       |
| :---------------------: | :-----------------: | :-: | :------------------: |
|           10            |          Q          | 29  |      2019\-9\-3      |
|            9            |   Pie（AndroidP\)   | 28  |      2018\-8\-7      |
|          8\.1           |  Oreo（Android O）  | 27  |     2017\-12\-05     |
|            8            |  Oreo（Android O）  | 26  |       2017\-03       |
|      7\.1/7\.1\.1       |       Nought        | 25  |       2016\-10       |
|            7            |       Nought        | 24  |       2016\-08       |
|         6\.0\.1         |     Marshmallow     | 23  |       2015\-12       |
|            6            |     Marshmallow     | 23  |       2015\-10       |
|      5\.1/5\.1\.1       |      Lollipop       | 22  |     2015\-03/04      |
|  5\.0/5\.0\.1/5\.0\.2   |      Lollipop       | 21  |     2014\-11/12      |
| 4\.4w/4\.4w\.1/4\.4w\.2 |       Kitkat        | 20  |    2014\-06/09/10    |
|  4\.4/4\.4\.1~4\.4\.4   |       Kitkat        | 19  |  2013\-10/2014\-06   |
|      4\.3/4\.3\.1       |    JellyBeanmr2     | 18  |        41465         |
|      :-----------:      |       :-----:       |
|  4\.2/4\.2\.1/4\.2\.2   |    JellyBeanmr1     | 17  | 2012\-11-11/2013\-02 |
|  4\.1/4\.1\.1/4\.1\.2   |      JellyBean      | 16  |    2012\-07/07/10    |
|     4\.0\.3/4\.0\.4     | IceCreamSandwishmr1 | 15  |  2011\-12/2012\-03   |
|  4\.0/4\.0\.1/4\.0\.2   |  IceCreamSandwish   | 14  |    2011\-10/10/11    |
|  3\.2/3\.2\.1~3\.2\.6   |    Honeycombmr2     | 13  |    2011\-07/2012     |
|         3\.1\.x         |    Honeycombmr1     | 12  |       2011\-05       |
|         3\.0\.x         |      Honeycomb      | 11  |       2011\-02       |
|     2\.3\.3~2\.3\.7     |   Gingerbreadmr1    | 10  | 2010-11\-02/2011\-09 |
|  2\.3/2\.3\.1/2\.3\.2   |     Gingerbread     |  9  | 2010\-12-12/2011\-01 |
|  2\.2/2\.2\.1~2\.2\.3   |        Froyo        |  8  | 2010\-05/2011\-01-11 |
|         2\.1\.x         |      Eclairmr1      |  7  |       2010\-01       |
|         2\.0\.1         |     Eclair_0_1      |  6  |       2009\-12       |
|            2            |       Éclair        |  5  |       2009\-10       |
|          1\.6           |        Donut        |  4  |       2009\-09       |
|          1\.5           |       Cupcake       |  3  |       2009\-04       |
|          1\.1           |      Base_1_1       |  2  |       2009\-02       |
|            1            |        Base         |  1  |       2008\-09       |

@import "E:\ZM\v scode\README.md"
@import "https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/Resource%20directory/README.md"

```mermaid
graph
    id1{{This is the text in the box}}
```

```mermaid
graph TB
A[平行形] -- 链接 --> B((圆))
A --> C(圆角长方形)
B --> D{菱形}
C --> D
```

```mermaid
graph TB
	c1-->a2
    subgraph one
    a1-->a2
    end
    subgraph two
    b1-->b2
    end
    subgraph three
    c1-->c2
    end
```

```mermaid
sequenceDiagram
张三 ->> 李四: 你好！李四, 最近怎么样?
李四-->>王五: 你最近怎么样，王五？
李四--x 张三: 我很好，谢谢!
李四-x 王五: 我很好，谢谢!
Note right of 王五: 李四想了很长时间, 文字太长了<br/>不适合放在一行.

李四-->>张三: 打量着王五...
张三->>王五: 很好... 王五, 你怎么样?
```

```mermaid
graph TB
    id1(圆角矩形)--普通线-->id2[矩形]
    subgraph 子图表
        id2==粗线==>id3{菱形}
        id3-.虚线.->id4>右向旗帜]
        id3--无箭头---id5((圆形))
    end
```

```mermaid
graph LR
    id1(Android 学习路线) --> id2(1.环境搭建开发相关)
    id1 --> id3("2.Android UI(User Interface)详解")
    id1 --> id4(3.事件处理机制)
    id1 --> id5(3.AndroidIntent)
    id1 --> id6(4.Fragment)
    id1 --> id7(5.数据存储四大组件和组件)
    id1 --> id8(6.网络编程)
    id1 --> id9(7.绘图与动画)
    id1 --> id10(8.多媒体开发)
    id1 --> id11(9.其他东西)
```
8多媒体开发7绘图与动画6网络编程Android学习路线9其他一些东西
```mermaid
stateDiagram
    [*] --> Still
    Still --> [*]

    Still --> Moving
    Moving --> Still
    Moving --> Crash
    Crash --> [*]
```
