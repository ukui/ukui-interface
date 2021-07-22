/*
 * Copyright (C) 2021 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
 *
 */

#ifndef __KYLINCOMMON_H__
#define __KYLINCOMMON_H__

#include<stdio.h>

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * 函数名称：common_get_xdgsessiontype
 * 功能： 获取区分x11与wayland的环境变量值
 * 参数1：xdgSessionType xdg会话类型字符串指针(out)
 * 参数2：max_len xdg会话类型字符串缓存大小(in)
 * 返回值：> 0 成功 否则失败
 **/
int common_get_xdgsessiontype(char *xdgSessionType, int max_len);

/**
 * 函数名称：common_get_lsbrelease
 * 功能：根据lsbrelease信息的键获取值
 * 参数1：key lsbrelease信息的键(in)
 * 参数2：value lsbrelease信息的值(out)
 * 参数3：value_max_len 值缓存区的大小(in)
 * 返回值：> 0 成功 否则失败
 **/
int common_get_lsbrelease(const char *key, char *value, int value_max_len);

/**
 * 函数名称：common_get_osrelease
 * 功能：根据osrelease信息的键获取值
 * 参数1：key osrelease信息的键(in)
 * 参数2：value osrelease信息的值(out)
 * 参数3：value_max_len 值缓存区的大小(in)
 * 返回值：> 0 成功 否则失败
 **/
int common_get_osrelease(const char *key, char *value, int value_max_len);

/**
 * 函数名称：common_get_kyinfo
 * 功能：根据kyinfo的键获取值
 * 参数1：session kyinfo的session值(in)
 * 参数2：key kyinfo的键(in)
 * 参数3：value kyinfo的值(out)
 * 参数4：value_max_len 值缓存区的大小(in)
 * 返回值：>= 0 成功 否则失败
 **/
int common_get_kyinfo(const char *session, const char *key, char *value, int value_max_len);

/**
 * 函数名称：common_get_prjcodename
 * 功能：根据PROJECT_CODENAME字段的值
 * 参数1：value PROJECT_CODENAME字段的值(out)
 * 参数2：value_max_len 值缓存区的大小(in)
 * 返回值：> 0 成功 否则失败
 **/
int common_get_prjcodename(char *value, int value_max_len);

/**
 * 函数名称：common_get_cpumodelname
 * 功能：获取CPU型号
 * 参数1：modelName CPU型号信息(out)
 * 参数2：max_len CPU型号缓存区的大小(in)
 * 返回值：> 0 成功 否则失败
 **/
int common_get_cpumodelname(char *modelName, int max_len);

/**
 * 函数名称：common_get_spechdplatform
 * 功能：获取特定硬件平台信息
 * 参数1：platformName 特定硬件平台信息(out)
 * 参数2：max_len 特定硬件平台缓存区的大小(in)
 * 返回值：> 0 成功 否则失败
 **/
int common_get_spechdplatform(char *platformName, int max_len);

#ifdef  __cplusplus
}
#endif

#endif // __KYLINCOMMON_H__