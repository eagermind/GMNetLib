# GMNetLib

## 简介

GMNetLib 是一个添加国密算法的网络请求框架，让你的网络传输过程安全可靠。

使用 GMNetLib 你可以进行 GET，POST，DELETE，UPDATE 等网络请求，也可以上传、下载文件（包含断点续传）。

## 导入流程

### 手动导入

#### 步骤1：
 
启动IDE（如Xcode），把iOS包中的压缩文件中以下文件拷贝到项目文件夹下，并导入到项目工程中。

* GMNetLib.framework

#### 步骤2：

在 Build Phases 选项卡的 Link Binary With Libraries 中，增加以下依赖：

* libc++.tbd
* libz.tbd

### cocoapods 导入

1. 在 podfile 文件中添加

```
pod 'GMNetLib'
```
2. 运行 pod install

## 使用

在需要调用 GMNetLib 的文件中，增加头文件引用。

```
#import <GMNetLib/GMNetLib.h>
```

## Object-C 示例

```
// 传参
NSDictionary *parame = @{···};
    
// 设置requestHeader    
NSDictionary *headerDic = @{@"Content-Type":@"application/x-www-form-urlencoded",@"Accept":@"application/json"};
    
[[GMNetLib sharedNetLib] setRequestHeaderWithDic:headerDic];
    
// 发送请求
[[GMNetLib sharedNetLib] Post:PostUrl parameters:parame finishedBlock:^(NSDictionary * _Nullable resultDic, bool isSuccess) {
        
}];
```
## API文档

### 创建单例：

```
+ (instancetype _Nonnull)sharedNetLib;
```

### 设置 requestHeader：

```
- (void)setRequestHeaderWithDic:(NSDictionary *_Nullable)dic;
```

|参数|说明|
|:---:|:---:|
|dic|存放requestHeader的键值对|

### GET 请求

```
- (void)get:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nonnull)(NSDictionary * _Nonnull resultDic, bool isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|parameters|参数|
|finished|返回数据回调|

### POST 请求

```
- (void)post:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nonnull)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|parameters|参数|
|finished|返回数据回调|

### PUT 请求

```
- (void)put:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nullable)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|parameters|参数|
|finished|返回数据回调|

### DELETE 请求

```
- (void)delete:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nullable)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|parameters|参数|
|finished|返回数据回调|

### 上传文件

```
- (void)uploadFileWithUrl:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters fileName:(NSString *)fileName filePath:(NSString *_Nonnull)filePath progress:(void(^_Nonnull)(float progress))progressBlock finishedBlock:(void(^_Nullable)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|parameters|参数|
|filePath|本地存放文件路径|
|progressBlock|上传进度回调|
|finished|返回数据回调|

### 文件下载

```
- (void)downloadFileWithUrl:(NSString *_Nonnull)urlString filePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress))progressBlock finishedBlock:(void(^_Nonnull)(NSDictionary * _Nullable resultDic, BOOL isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|filePath|本地存放文件路径|
|progressBlock|上传进度回调|
|finished|返回数据回调|

### 文件下载（断点续传）

```
- (void)downloadFileWithUrl:(NSString *_Nonnull)urlString filePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress))progressBlock finishedBlock:(void(^_Nonnull)(NSDictionary * _Nullable resultDic, BOOL isSuccess))finished;
```

|参数|说明|
|:---:|:---:|
|urlString|网络地址|
|filePath|本地存放文件路径|
|progressBlock|上传进度回调|
|finished|返回数据回调|


