//
//  SYMusicPalyManager.h
//  AudioPlayer
//
//  Created by macmini on 2017/12/7.
//  Copyright © 2017年 macmini. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <AVFoundation/AVFoundation.h>

@class SYMusicModel,SYMusicMessageModel;

@protocol SYMusicPalyManagerDelegate


/**
 获取播放总时间回调
 */
- (void)startGetMusicTotleTime;


/**
 每秒更新UI回调
 */
- (void)updateMusicByOneSecend;


/**
 正在播放回调
 */
- (void)statusPlayingMusic;


/**
 暂停播放回调
 */
- (void)statusPausedMusic;


/**
 播放结束回调
 */
- (void)playMusicFinsh;

@optional

/**
 播放缓冲进度回调

 @param progress 缓冲进度
 */
- (void)bufferProgress:(CGFloat)progress;

/**
 初始化歌词回调
 */
- (void)readyLrc;

/**
 每帧更新歌词回调
 */
- (void)updateLrcByOneFrame;
@end

@interface SYMusicPalyManager : NSObject
/** 存放的播放列表 */
@property(nonatomic,readonly)NSArray<SYMusicModel *>*musicModels;

/** 歌曲信息数据模型 */
@property (nonatomic, readonly) SYMusicMessageModel *messageModel;

+ (instancetype)shareSYMusicPalyManager;

#pragma mark 创建avplayer

/**
 播放网络单个音频

 @param song 歌曲模型
 @param delegate 播放类回调
 @param autoPlay 是否自动播放
 */
- (void)prepareToPlayMusicWithSong:(SYMusicModel *)song delegate:(id)delegate autoPlay:(BOOL)autoPlay;


/**
 播放音频列表

 @param songs 歌曲模型数组
 @param delegate 播放类回调
 @param autoPlay 是否自动播放
 */
- (void)prepareToPlayMusicWithSongs:(NSArray<SYMusicModel *> *)songs delegate:(id)delegate autoPlay:(BOOL)autoPlay;

#pragma mark 播放控制

/**
 播放
 */
- (void)play;

/**
 暂停
 */
- (void)pause;

/**
 跳转指定进度

 @param progress 进度 0-1
 */
- (void)playAtProgress:(CGFloat)progress;

/**
 播放上一首 播放单个音频时就是从头开始播放该音频
 */
- (void)playerPreviouse;

/**
 播放下一首 播放单个音频时就是从头开始播放该音频
 */
- (void)playerNext;


/**
 停止播放
 */
- (void)stopPlay;
@end
