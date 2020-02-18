# <cent>Android basic knowledge</cent>

_2020 年 2 月 18 日 星期二_

- [Android basic knowledge](#centandroid-basic-knowledgecent)
  - [一、学习路线](#一学习路线)
  - [二、安卓发展史](#二安卓发展史)
    - [Android 历代版本和API代号](#android-历代版本和api代号)
  - [三、Android 体系结构](#三android-体系结构)
    - [3.1. 应用程序层（Applications）](#31-应用程序层applications)
    - [3.2.应用程序框架层（Application Framework）](#32应用程序框架层application-framework)
    - [3.3.核心类库（Libraries）](#33核心类库libraries)
    - [3.4.Linux 内核（Linux Kernel）](#34linux-内核linux-kernel)
  - [四、Android 环境搭建](#四android-环境搭建)
    - [4.1.Gradle](#41gradle)
    - [4.2.Android studio 汉化](#42android-studio-汉化)
  - [五、Android 学习参考书](#五android-学习参考书)
  - [六、解决 Android Studio 环境中的问题](#六解决-android-studio-环境中的问题)

## 一、学习路线

<center><img src="https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218101721-2020-2-18-10-17-21.png" height="100%" width="100%"></center>

## 二、安卓发展史

> 2003 年 10 月, Andy Rubin 等人一起创办了 Android 公司 2005 年 8 月谷歌收购了这家仅仅成立了 22 个月的公司,并让 Andy Rubin 继续负 Android 责项目。
> 在经过了数年的研发之后,谷歌终于在 2008 年推出了 Android 系统的第一个版本。
> 但自那之后, Android 的发展就一直受到重重阻挠。
> 乔布斯自始至终认为 Android 是一个抄袭 iPhone 的产品,里面剽窃了诸多 iPhone 的创意,并声称一定要毁掉 Android 而本身就是基于 Linux 开发的 Android 操作系统,在 2010 年被 Linux 团队从 Linux 内核主线中除名。
> 又由于 Android 中的应用程序都是使用 Java 开发的,甲骨文则针对 Android 侵犯 Java 知识产权一事对谷歌提起了诉讼
>
> > ==Android 第一行代码==

![Android 发展史](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218101827-2020-2-18-10-18-28.png)

### Android 历代版本和API代号

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


![SDK和NDK](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218101910-2020-2-18-10-19-10.png)

## 三、Android 体系结构

**安卓体系结构分为 4 层，基于 java，采用 Linux 内核驱动。
Dalvik 是谷歌设计用于安卓平台的虚拟机，可以简单完成进程隔离和线程管理并提高内存使用效率**

![Android 体系结构](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218095849-2020-2-18-9-58-49.png)

Android 系统采用分层构架，由高到低分为 4 层，依次是
应用程序层、应用程序构架层、核心库和 Linux 内核

### 3.1. 应用程序层（Applications）

    应用程序层是一个核心应用程序的集合，
    所有安装在手机上的应用程序都属于这一层，
    例如 系统自带的联系人程序、短信程序、
    或者从Google Play上下载的小游戏等都属于应用程序层。

### 3.2.应用程序框架层（Application Framework）

    应用程序框架层主要提供了构建应用程序是用到的各种 API。Android 自带的一些核心应用就是使用这些 API 完成的，
    例如视图（View）、活动管理器（Activity Manager）、
    通知管理器（Notification Manger）等，
    开发者也可以通过这些 API 来开发自己的程序。

### 3.3.核心类库（Libraries）

    核心类库中包含了系统库挤Android运行时库。
    系统库这一层主要是通过C/C++库来为Android系统提供主要的特性支持，
    如OpenGL/ES库提供了3D绘图的支持，Webkit库提供了浏览器内核的支持。
    Android运行时库（Android Runtime）主要提供了一些核心库，
    能够允许开发者使用java语言来编写Android应用程序。
    另外，Android运行时库中还包括了Dalvik虚拟机，
    它使得灭一个Android应用都能运行在独立的过程当中，
    并且拥有一个自己的Dalvik虚拟机实例。
    相当于java虚拟机，Dalvik虚拟机是专门为移动设备定制的，
    它只对手机内存、CPU性能等做了优化处理。

### 3.4.Linux 内核（Linux Kernel）

    Linux内核层为Android设备的各种硬件提供了底层的驱动，
    如显示驱动、音频驱动、照相机驱动、蓝牙驱动、电源管理驱动等。

![Android和ios区别](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218102400-2020-2-18-10-24-0.png)

## 四、Android 环境搭建

- [Jetbrains Toolbox](https://www.jetbrains.com/toolbox-app)

![Jetbrains Toolbox](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218105030-2020-2-18-10-50-30.png)

### 4.1.Gradle

因为 Gradle 是 Android studio 环境配置中最耗时间的一部分，
所以我们可以离线下载复制到相应目录下即可。

- [Gradle 官网下载地址](https://services.gradle.org/distributions/)

![Gradle](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218105303-2020-2-18-10-53-4.png)

- Gradle 配置
  下载后的 Gradle 包解压放在自己的用户目录下，如下：

![Gradle配置](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218113231-2020-2-18-11-32-31.png)

### 4.2.Android studio 汉化

- 感谢 github ==pingfangx==
- [汉化包](https://github.com/pingfangx/TranslatorX)

- [使用教程](https://github.com/pingfangx/TranslatorX/wiki/Usage#%E5%9B%BE%E6%96%87%E6%95%99%E7%A8%8B)

## 五、Android 学习参考书

- [安卓第一行代码](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/Resource%20directory/%E7%AC%AC%E4%B8%80%E8%A1%8C%E4%BB%A3%E7%A0%81%20Android%20%E7%AC%AC2%E7%89%88-%E9%83%AD%E9%9C%96-%E4%BA%BA%E9%82%AE-2016.12-P580.pdf)

- [ANDROID 移动开发基础案例教程](https://cs-ans.chaoxing.com/download/5ad7ade1867b1fb4f93732f13521a938)

- [TheBusyCoder'sGuidetoAndroidDevelopment(2016)](https://cs-ans.chaoxing.com/download/2f1a9ff491e5b3a9986b35308c27c3d5)

- [50 个安卓开发者应该熟悉的 Android-Studio 技巧和资源](https://cs-ans.chaoxing.com/download/7172350861bab7b51c976fbd5c083860)

- [Android-Studio 快捷键和使用技巧](https://cs-ans.chaoxing.com/download/b7edc3879ee0eee97194dc23de0f1477)

- [史上最详细的 Android-Studio 系列教程](https://cs-ans.chaoxing.com/download/8ee83ec63828a743a18b34da4b34616a)

## 六、解决 Android Studio 环境中的问题

- [AndroidStudio 中集成 Genymotion](https://cs-ans.chaoxing.com/download/8906f50f313b292474605eeb2c51a239)

- [AndroidStudio 中显示行号](https://cs-ans.chaoxing.com/download/d98ff71e4d9dd9add6cb513016e30909)

- [Android 设备 arm 架构和 X86 架构的区别](https://cs-ans.chaoxing.com/download/c90bcfcc6a6462b4783e3ab2e508518c)

- [AndroidStudio 快捷键及常用技巧](https://cs-ans.chaoxing.com/download/8b630a545b37479da7abb5a463fb62eb)

- [androidstudio](https://cs-ans.chaoxing.com/download/9570084cac8e666e80c32e8fc0718feb)

- [Gradle 问题集锦](https://cs-ans.chaoxing.com/download/d626424028439f01a195320c48c9315f)

- [AndroidStudio 导入问题汇总](https://cs-ans.chaoxing.com/download/3e78101afd08c5e3456ccb3b0c549252)
