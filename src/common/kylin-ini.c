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

#include "kylin-ini.h"

#include <stdio.h>  
#include <string.h>

// getIniKeyString 读取ini键值
int getIniKeyString(const char *filename, const char *session, const char *key, char *value, int value_max_len)
{
    if (filename == NULL || session == NULL || key == NULL || value == NULL || value_max_len <= 0) 
        return -1; // 参数错误
    FILE *fp = NULL;
    int  flag = 0;
    char sSession[64], *wTmp;
    char sLine[1024];
    snprintf(sSession, 64, "[%s]", session);
    if(NULL == (fp = fopen(filename, "r"))) {  
        perror("fopen");  
        return -1;
    }
    while (NULL != fgets(sLine, 1024, fp)) {
        // 这是注释行
        if (0 == strncmp("//", sLine, 2)) continue;
        if ('#' == sLine[0])              continue;
        wTmp = strchr(sLine, '=');
        if ((NULL != wTmp) && (1 == flag)) {
            if (0 == strncmp(key, sLine, strlen(key))) { // 长度依文件读取的为准  
                sLine[strlen(sLine) - 1] = '\0';  
                fclose(fp);
                while(*(wTmp + 1) == ' '){
                    wTmp++;
                }
                int nValidLen = strlen(wTmp + 1);
                nValidLen = nValidLen < value_max_len ? nValidLen : value_max_len;
                strncpy(value, wTmp + 1, nValidLen);
                return 0;
            }  
        } else {
            if (0 == strncmp(sSession, sLine, strlen(sSession))) { // 长度依文件读取的为准  
                flag = 1; // 找到标题位置  
            }
        }
    }
    fclose(fp);
    return -1;
}

// 设置ini键值
int setIniKeyString(const char *filename, const char *session, const char *key, char *value)
{
    if (filename == NULL || session == NULL || key == NULL || value == NULL) 
        return -1; // 参数错误
    FILE *fpr = NULL, *fpw = NULL;  
    int  flag = 0;  
    char sLine[1024] = {0}, sSession[64] = {0}, *wTmp = NULL;        
    snprintf(sSession, 64, "[%s]", session);
    if (NULL == (fpr = fopen(filename, "r")))
        return -1;// 读取原文件
    
    snprintf(sLine, 256, "%s.tmp", filename);
    if (NULL == (fpw = fopen(sLine, "w"))) {
        fclose(fpr);
        fpr = NULL;
        return -1;// 写入临时文件
    }

    while (NULL != fgets(sLine, 1024, fpr)) {
        if (2 != flag) { // 如果找到要修改的那一行，则不会执行内部的操作
            wTmp = strchr(sLine, '=');
            if ((NULL != wTmp) && (1 == flag)) {
                if (0 == strncmp(key, sLine, strlen(key))) { // 长度依文件读取的为准
                    flag = 2;// 更改值，方便写入文件
                    snprintf(wTmp + 1, 256, " %s\n", value);
                    break;
                }
            } else {
                if (0 == strncmp(sSession, sLine, strlen(sSession))) { // 长度依文件读取的为准
                    flag = 1; // 找到标题位置
                }
            }
        }
        fputs(sLine, fpw); // 写入临时文件 
    }
    if (flag == 0) { // 未找到session
        char wBuffer[1024] = {0};
        snprintf(wBuffer, 1024, "%s\n", sSession);
        fputs(wBuffer, fpw); // 写入会话
        snprintf(wBuffer, 1024, "%s = %s\n", key, value);
        fputs(wBuffer, fpw); // 写入键值
    } else if (flag == 1) { // 待完善
        char wBuffer[1024] = {0};
        snprintf(wBuffer, 1024, "%s = %s\n", key, value);
        fputs(wBuffer, fpw); // 写入键值
    }
    fclose(fpr);
    fclose(fpw);
    snprintf(sLine, 256, "%s.tmp", filename);
    return rename(sLine, filename);// 将临时文件更新到原文件
}
