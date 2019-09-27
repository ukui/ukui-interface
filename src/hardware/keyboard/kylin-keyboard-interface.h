/*
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
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


#ifndef __KYLINKEYBOARDINTERFACE_H__
#define __KYLINKEYBOARDINTERFACE_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize the DBus Communication
 */
bool InitDBusKeyboard(void);

/**
 * Delete the DBus Communication.
 */
bool DeInitDBusKeyboard(void);

/**
 * Repeat the key when holding down a key.
 * @param in_arg is the value you want to set.
 * @return true if setting successfully.
 */
bool kylin_hardware_keyboard_set_repeat(const bool in_arg);

/**
 * Get the value of key.
 * @return the value of key.
 */
bool kylin_hardware_keyboard_get_repeat();

/**
 * Set key speed.
 * @param in_arg is the value you want to set.
 * @return true if setting successfully.
 */
bool kylin_hardware_keyboard_set_rate(const int in_arg);

/**
 * Get the value of key.
 * @return the value of key.
 */
int kylin_hardware_keyboard_get_rate();

/**
 * Set time delay.
 * @param in_arg is the value you want to set.
 * @return true if setting successfully.
 */
bool kylin_hardware_keyboard_set_delay(const int in_arg);

/**
 * Get the value of key.
 * @return the value of key.
 */
int kylin_hardware_keyboard_get_delay();

#ifdef __cplusplus
}
#endif

#endif













