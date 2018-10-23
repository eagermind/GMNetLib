//
//  GMNetLib.h
//  GMNetLib
//
//  Created by 鲲鹏刘 on 2018/10/16.
//  Copyright © 2018年 鲲鹏刘. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define BASE_URL @"http://om.win-trust.cn/api"

@interface GMNetLib : NSObject

/** 创建单例 */
+ (instancetype _Nonnull)sharedNetLib;

/** 设置requestheader
 *
 *  dic :  存放requestheader的键值对
 */
- (void)setRequestHeaderWithDic:(NSDictionary *_Nullable)dic;


/**
 * GET请求
 *
 * urlString  : 网络地址
 * parameters : 参数
 * finished   : 返回数据回调
 */
- (void)Get_Curl:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nonnull)(NSDictionary * _Nonnull resultDic, bool isSuccess))finished;

/**
 * POST请求
 *
 * urlString  : 网络地址
 * parameters : 参数
 * finished   : 返回数据回调
 */
- (void)Post_Curl:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nonnull)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;

/**
 * PUT请求
 *
 * urlString  : 网络地址
 * parameters : 参数
 * finished   : 返回数据回调
 */
- (void)Put_Curl:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nullable)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;

/**
 * DELETE请求
 *
 * urlString  : 网络地址
 * parameters : 参数
 * finished   : 返回数据回调
 */
- (void)Delete_Curl:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters finishedBlock:(void(^_Nullable)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;

/**
 * 上传文件
 *
 * urlString      : 网络地址
 * parameters     : 参数
 * filePath       : 本地存放文件路径
 * progressBlock  : 上传进度回调
 * finished       : 返回数据回调
 */
- (void)uploadFileWithUrl:(NSString *_Nonnull)urlString parameters:(NSDictionary *_Nullable)parameters fileName:(NSString *)fileName filePath:(NSString *_Nonnull)filePath progress:(void(^_Nonnull)(float progress))progressBlock finishedBlock:(void(^_Nullable)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;

/**
 * 文件下载
 *
 * urlString      : 网络路径
 * filePath       : 本地存放文件路径
 * progressBlock  : 下载进度回调
 * finished       : 返回数据回调
 */
- (void)downloadFileWithUrl:(NSString *_Nonnull)urlString filePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress))progressBlock finishedBlock:(void(^_Nonnull)(NSDictionary * _Nullable resultDic, BOOL isSuccess))finished;

/**
 * 文件下载（断点续传）
 *
 * urlString      : 网络路径
 * filePath       : 本地存放文件路径
 * progressBlock  : 下载进度回调
 * finished       : 返回数据回调
 */
- (void)downloadBreakpointResumeWithUrl:(NSString *_Nonnull)urlString filePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress))progressBlock finishedBlock:(void(^_Nonnull)(NSDictionary * _Nullable resultDic, bool isSuccess))finished;


@end


