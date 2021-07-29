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
#include <stdlib.h>
#include <ctype.h>

//去除尾部空白字符 包括\t \n \r  
/*
标准的空白字符包括：
' '     (0x20)    space (SPC) 空格符
'\t'    (0x09)    horizontal tab (TAB) 水平制表符    
'\n'    (0x0a)    newline (LF) 换行符
'\v'    (0x0b)    vertical tab (VT) 垂直制表符
'\f'    (0x0c)    feed (FF) 换页符
'\r'    (0x0d)    carriage return (CR) 回车符
//windows \r\n linux \n mac \r
*/ 
char *rtrim(char *str, int containQuot)
{
    if(str == NULL || *str == '\0') {
        return str;
    }
    int len = strlen(str);
    char *p = str + len - 1;
    if (containQuot) {
        while(p >= str && (isspace(*p) || *p == '\"')) {
            *p = '\0'; --p;
        }
    } else {
        while(p >= str && isspace(*p)) {
            *p = '\0'; --p;
        }
    }
    return str;
}

//去除首部空格 
char *ltrim(char *str, int containQuot)
{
    if(str == NULL || *str == '\0') {
        return str;
    }
    int len = 0;
    char *p = str;
    if (containQuot) {
        while(*p != '\0' && (isspace(*p) || *p == '\"')) { 
            ++p; ++len;
        }
    } else {
        while(*p != '\0' && isspace(*p)) { 
            ++p; ++len;
        }
    }
    memmove(str, p, strlen(str) - len + 1);
    return str;
}

//去除首尾空格
char *trim(char *str, int containQuot)
{
    str = rtrim(str, containQuot);
    str = ltrim(str, containQuot);
    return str;
}

// getIniKeyString 读取ini键值
int getIniKeyString(const char *filename, const char *session, const char *key, char *value, int value_max_len)
{
    if (filename == NULL || session == NULL || key == NULL || value == NULL || value_max_len <= 0) 
        return -1; // 参数错误
    // 清空目标缓存
    FILE *fp = NULL;
    int  flag = 0;
    char sSession[64], *wTmp = NULL;
    char sLine[1024];
    snprintf(sSession, 64, "[%s]", session);
    if(NULL == (fp = fopen(filename, "r"))) {  
        perror("fopen");  
        return -1;
    }
    while (NULL != fgets(sLine, 1024, fp)) {
        // 这是注释行
        trim(sLine, 0);
        if (0 == strncmp("//", sLine, 2)) continue;
        if ('#' == sLine[0])              continue;
        wTmp = strchr(sLine, '=');
        if ((NULL != wTmp) && (1 == flag)) {
            int keyLen = wTmp - sLine;
            char keyName[256] = {0};
            strncpy(keyName, sLine, keyLen);
            rtrim(keyName, 0);
            keyLen = strlen(keyName) > strlen(key) ? strlen(keyName) : strlen(key);
            if (0 == strncmp(key, keyName, keyLen)) { // 长度依文件读取的为准
                fclose(fp);
                int nValidLen = strlen(wTmp + 1);
                nValidLen = nValidLen < value_max_len ? nValidLen : value_max_len;
                strncpy(value, wTmp + 1, nValidLen);
                trim(value, 1);
                return 0;
            }  
        } else {
            if (0 == strncmp(sSession, sLine, strlen(sSession))) { // 长度依文件读取的为准  
                flag = 1; // 找到目标session位置  
            } else if (flag == 1) { // 找到其他空行或session
                wTmp = strchr(sLine, '[');
                if (NULL != wTmp) {
                    flag = 0;
                }
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
