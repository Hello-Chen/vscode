# <p align="center">C_C++代码块自定义</p>

## 1.代码块是什么？

    代码块可以让代码实现自动填充

![代码块演示-2020-2-2-15-53-23.png](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/代码块演示-2020-2-2-15-53-23.png)

## 2.设置代码块

    代码块设置可分为：用户代码块片段和全局代码块片段，作用的工作区域不同，用户可自行选着。

![设置代码块-2020-2-2-18-12-49.png](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/设置代码块-2020-2-2-18-12-49.png)
![设置代码块2-2020-2-2-18-12-49.png](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/设置代码块2-2020-2-2-18-12-49.png)
![代码块说明-2020-2-2-18-12-56.png](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/代码块说明-2020-2-2-18-12-56.png)

## 自用代码块

```
{
    "Print to Scanf": {
        "scope": "c,cpp",        //定义语言范围,可多选，如"c,cpp,javascript,typescript"
        "prefix": "sca",         //触发条件，输入"sca"触发代码块
        "body": [                //需要填充的代码内容
            "scanf(\"%$0\")"     //光标返回位置 $1,${1:defaulttext}
        ],
        "description": "Scanf"   //代码块名称
    },

    "Print to For": {
        "scope": "c,cpp",
        "prefix": "fo",
        "body": [
            "for(int ${2:i} = 0; ${2:i} < ${1:n}; ${2:i}++)",
            "{",
            "    $3",
            "}",
        ],
        "description": "For循环"
    },

    "Print to Printf": {
        "scope": "c,cpp",
        "prefix": "pri",
        "body": [
            "printf(\"%$0\");"
        ],
        "description": "Printf"
    },

    "Print to #include <stdio.h>":{
    "scope": "c,cpp",
    "prefix": "std",
    "body": [
            "#include <stdio.h>\n",
            "int main(void)",
            "{",
            "    ${0:printf(\"Hello Chen\");}",
            "    getchar();",
            "}",
    ],
    "description": "stdio.h"
    },

    "Print to #include <iostream>":{
        "scope": "c,cpp",
        "prefix": "ios",
        "body": [
        "#include <iostream>\n",
        "using namespace std;",
         "int main(void)",
        "{",
        "    ${0:cout << \"Hello Chen\" << endl;}",
        "    system(\"pause\");",
        "}",
        ],
        "description": "iostream"
    }
}
```
