/***************************************************************************
 *            nge_main.h
 *
 *  2011/03/26 01:50:11
 *  Copyright  2011  Kun Wang <ifreedom.cn@gmail.com>
 ****************************************************************************/
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _NGE_MAIN_H
#define _NGE_MAIN_H

#include "nge_common.h"

#define INIT_VIDEO 1
#define INIT_AUDIO 2
#define INIT_ALL   INIT_VIDEO|INIT_AUDIO

#define main NGE_main

enum NotifyType
{
	NGE_NOTIFY_PAUSE = 0,
	NGE_NOTIFY_RESUME,
	NGE_NOTIFY_STOP,
};

/**
 *回调函数
 *@param int type, 通知类型
 *@param void* data, 通知数据
 *@param void* pCookie, 用户数据
 */
typedef void (*NotifyCallback)(int type, void* data, void* pCookie);

#ifdef __cplusplus
extern "C"{
#endif

/**
 *NGE初始化函数
 *@param int flags,初始化标志位,INIT_VIDEO(视频),INIT_AUDIO(音频)或者INIT_ALL
 *@return 无
 */
void NGE_Init(int flags);

/**
 *NGE退出函数
 *@return 无
 */
void NGE_Quit();

/**
 *设置屏幕窗口
 *@param const char* winname,窗口名字
 *@param int screen_width,窗口宽
 *@param int screen_height,窗口高
 *@param int screen_bpp,窗口bpp,通常填32
 *@param int screen_full,是否全屏0-窗口,1-全屏
 *@return
 */
void NGE_SetScreenContext(const char* winname,int screen_width,int screen_height,int screen_bpp,int screen_full);

/**
 *设置系统原生屏幕分辨率
 *@param int width,宽度
 *@param int height,高度
 */
void NGE_SetNativeResolution(int width,int height);

/**
 *设置片头动画地址
 *@param const char* path,地址
 */
void NGE_SetOPMoviePath(const char* path);

/**
 *注册通知回调函数
 *@param NotifyCallback cb, 回调函数
 */
void NGE_RegisterNotifyCallback(NotifyCallback cb, void* pCookie);
#ifdef __cplusplus
}
#endif

#endif /* _NGE_MAIN_H */
