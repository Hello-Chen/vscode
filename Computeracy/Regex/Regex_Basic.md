# Regex

## 元字符

<style type="text/css">
    table.tftable {
      font-size: 12px;
      color: #333333;
      width: 100%;
      border-width: 1px;
      border-color: #bcaf91;
      border-collapse: collapse;
    }

    table.tftable th {
      font-size: 16px;
      background-color: #ded0b0;
      border-width: 2px;
      padding: 10px;
      border-style: dashed;
      border-color: #bcaf91;
      text-align: center;
    }

    table.tftable tr {
      background-color: #e9dbbb;
    }

    table.tftable td {
      font-size: 16px;
      border-width: 2px;
      padding: 10px;
      border-style: solid;
      border-color: #bcaf91;
    }
  </style>
  <table id="tfhover" class="tftable" border="1">
    <tr>
      <th colspan="2">常用元字符</th>
      <th colspan="2">常用限定符</th>
      <th colspan="2">常用反义词</th>
    </tr>
    <tr>
      <th>语法</th>
      <th>说明</th>
      <th>语法</th>
      <th>说明</th>
      <th>语法</th>
      <th>说明</th>
    </tr>
    <tr>
      <td align="center">.</td>
      <td>匹配除换行符以外的任意字符</td>
      <td align="center">*</td>
      <td>重复零次或更多次</td>
      <td align="center">\W</td>
      <td>匹配任意不是字母，数字，下划线，汉字的字符</td>
    </tr>
    <tr>
      <td align="center">\w</td>
      <td>匹配字母或数字或下划线</td>
      <td align="center">+</td>
      <td>重复一次或更多次</td>
      <td align="center">\S</td>
      <td>匹配任意不是空白符的字符</td>
    </tr>
    <tr>
      <td align="center">\s</td>
      <td>匹配任意的空白符</td>
      <td align="center">?</td>
      <td>重复零次或一次</td>
      <td align="center">\D</td>
      <td>匹配任意非数字的字符</td>
    </tr>
    <tr>
      <td align="center">\d</td>
      <td>匹配数字</td>
      <td align="center">{n}</td>
      <td>重复n次</td>
      <td align="center">\B</td>
      <td>匹配不是单词开头或结束的位置</td>
    </tr>
    <tr>
      <td align="center">\b</td>
      <td>匹配单词的开始或结束</td>
      <td align="center">{n,}</td>
      <td>重复n次或更多次</td>
      <td align="center">[^x]</td>
      <td>匹配除了x以外的任意字符</td>
    </tr>
    <tr>
      <td align="center">^</td>
      <td>匹配字符串的开始</td>
      <td align="center">{n,m}</td>
      <td>重复n到m次</td>
      <td align="center">[^aeiou]</td>
      <td>匹配除了aeiou这几个字母以外的任意字符</td>
    </tr>
    <tr>
      <td align="center">$</td>
      <td>匹配字符串的结束</td>
      <td align="center" colspan="4"><a href="http://tool.chinaz.com/tools/regexgenerate">数据来源：http://tool.chinaz.com/tools/regexgenerate</a></td>
    </tr>
</table>
