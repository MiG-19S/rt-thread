/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-08-21     MurphyZhao   the first version
 */
#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtthread.h>
#include <board.h>

/* enable stm32l4 onchip flash driver sample */
#define FAL_FLASH_PORT_DRIVER_STM32L4
/* enable SFUD flash driver sample */
#define FAL_FLASH_PORT_DRIVER_SFUD

extern const struct fal_flash_dev _onchip_flash_8k;
extern const struct fal_flash_dev _onchip_flash_128k;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &_onchip_flash_8k,                                               \
    &_onchip_flash_128k,                                             \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define FAL_PART_TABLE                                                                                                   \
{                                                                                                                        \
    {FAL_PART_MAGIC_WROD,        "app", "onchip_flash_8k",                                    0,       64 * 1024, 0},    \
    {FAL_PART_MAGIC_WROD,      "param", "onchip_flash_128k",                                  0,     3 * 128 * 1024, 0}, \
}
#endif /* FAL_PART_HAS_TABLE_CFG */
#endif /* _FAL_CFG_H_ */
