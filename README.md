# GMNetLib

## 简介

GMNetLib 是一个基于 libcurl 封装的网络请求框架，添加国密算法，安全可靠。

## 导入流程

### 手动导入

#### 步骤1：
 
启动IDE（如Xcode），把iOS包中的压缩文件中以下文件拷贝到项目文件夹下，并导入到项目工程中。

* GMNetLib.framework

#### 步骤2：

在 Build Phases 选项卡的 Link Binary With Libraries 中，增加以下依赖：

* libc++.tbd
* libz.tbd

#### 步骤3：

在需要调用 GMNetLib 的文件中，增加头文件引用。

```
#import <GMNetLib/GMNetLib.h>
```

### 使用 cocoapods 导入

```
pod 'GMNetLib'
```
