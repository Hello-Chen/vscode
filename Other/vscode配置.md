# vscode

## 插件

[](https://marketplace.visualstudio.com/items?itemName=Spades.vs-picgo)

## 代码块

```C
{
    "Print to Scanf": {
        "scope": "c,cpp",        //定义语言范围,可多选，如"c,cpp,javascript,typescript"
        "prefix": "sca",//触发条件，输入"sca"触发代码块
        "body": [                //需要填充的代码内容
            "scanf(\"%$0\")"
        ],
        "description": "Scanf" //代码块名称
    },

    "Print to For": {
        "scope": "c,cpp",
        "prefix": "fo",
        "body": [
            "for(int ${2:i} = 0; ${2:i} < ${1:n}; ${2:i}++)",
            "{",
            "    ",
            "}"
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
            "#include <stdio.h>",
            "int main(void)",
            "{",
            "    printf(\"Hello Chen$0\");",
            "getchar();",
            "}",
    ],
    "description": "stdio.h"
    },

    "Print to #include <iostream>":{
        "scope": "c,cpp",
        "prefix": "ios",
        "body": [
        "#include <iostream>",
        "using namespace std;",
        "int main(void)",
        "{",
        "    cout << \"Hello Chen\" << endl;",
        "    system(\"pause\");",
        "}",
        ],
        "description": "iostream"
    }
}
```
