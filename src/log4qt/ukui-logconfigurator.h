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

#ifndef __UKUI_LOGCONFIGURATOR_H__
#define __UKUI_LOGCONFIGURATOR_H__

#include "ukui-logmacros.h"

#include <QObject>
#include <QMutex>
#include <qgsettings.h>
#include "log4qt/helpers/properties.h"
#include "ukui-logrolling.h"

// 日志sdk对外衔接类
class LIBUKUILOG4QT_EXPORT UkuiLog4qtConfig : public QObject
{
    Q_OBJECT

private:
    virtual ~UkuiLog4qtConfig();
    UkuiLog4qtConfig(QObject *parent = nullptr);

public:
    // 返回日志配置器实例
    static UkuiLog4qtConfig *instance();
    // 初始化日志sdk属性
    int init(QString strAppName);
    // 释放自身资源
    static void shutdown();

private:
    // 初始化gsettings并监听
    void initSettings(QString strAppName, Log4Qt::Properties &properties);

public:
    // 检查日志文件线程对象
    UkuiLog4qtRolling            *m_threadCheckFile;

private:
    // 自身实例
    static UkuiLog4qtConfig     *mInstance;
    // 是否已初始化
    bool                        m_isInited;
    // 全局gsettings
    QGSettings                  *m_gsLog4qtGlobal;
    // 当前程序特例gsettings
    QGSettings                  *m_gsLog4qtSpecial;
    // 当前属性列表
    Log4Qt::Properties           m_log4qtProperties;
    // 最多允许文件数
    unsigned                     m_uMaxFileCount;
    // 最大允许文件容量
    quint64                      m_uMaxFileSize;
    // 文件检查时间间隔 s
    quint64                      m_timeCheckFile;
};

#endif // __UKUI_LOGCONFIGURATOR_H__