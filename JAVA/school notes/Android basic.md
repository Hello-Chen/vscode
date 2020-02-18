# Android basic knowledge

_2020 年 2 月 18 日 星期二_

## 学习路线

![Android学习路线](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218101721-2020-2-18-10-17-21.png)

## 安卓发展史

> 2003 年 10 月, Andy Rubin 等人一起创办了 Android 公司 2005 年 8 月谷歌收购了这家仅仅成立了 22 个月的公司,并让 Andy Rubin 继续负 Android 责项目。
> 在经过了数年的研发之后,谷歌终于在 2008 年推出了 Android 系统的第一个版本。
> 但自那之后, Android 的发展就一直受到重重阻挠。
> 乔布斯自始至终认为 Android 是一个抄袭 iPhone 的产品,里面剽窃了诸多 iPhone 的创意,并声称一定要毁掉 Android 而本身就是基于 Linux 开发的 Android 操作系统,在 2010 年被 Linux 团队从 Linux 内核主线中除名。
> 又由于 Android 中的应用程序都是使用 Java 开发的,甲骨文则针对 Android 侵犯 Java 知识产权一事对谷歌提起了诉讼
>
> > ==Android 第一行代码==

![Android 发展史](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218101827-2020-2-18-10-18-28.png)

![SDK和NDK](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218101910-2020-2-18-10-19-10.png)

## Android 体系结构

**安卓体系结构分为 4 层，基于 java，采用 Linux 内核驱动。
Dalvik 是谷歌设计用于安卓平台的虚拟机，可以简单完成进程隔离和线程管理并提高内存使用效率**

![Android 体系结构](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218095849-2020-2-18-9-58-49.png)

Android 系统采用分层构架，由高到低分为 4 层，依次是
应用程序层、应用程序构架层、核心库和 Linux 内核

### 1. 应用程序层（Applications）

    应用程序层是一个核心应用程序的集合，
    所有安装在手机上的应用程序都属于这一层，
    例如 系统自带的联系人程序、短信程序、
    或者从Google Play上下载的小游戏等都属于应用程序层。

### 2.应用程序框架层（Application Framework）

    应用程序框架层主要提供了构建应用程序是用到的各种 API。Android 自带的一些核心应用就是使用这些 API 完成的，
    例如视图（View）、活动管理器（Activity Manager）、
    通知管理器（Notification Manger）等，
    开发者也可以通过这些 API 来开发自己的程序。

### 3.核心类库（Libraries）

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

### 4.Linux 内核（Linux Kernel）

    Linux内核层为Android设备的各种硬件提供了底层的驱动，
    如显示驱动、音频驱动、照相机驱动、蓝牙驱动、电源管理驱动等。

![Android和ios区别](https://hello-chen-1300561671.cos.ap-chengdu.myqcloud.com/github_vscode/20200218102400-2020-2-18-10-24-0.png)
