/* SPDX-License-Identifier:     GPL-2.0+ */
/*
 * (C) Copyright 2021 Rockchip Electronics Co., Ltd
 * Copyright (c) 2023 Edgeble AI Technologies Pvt. Ltd.
 */

#ifndef __CONFIG_RK3588_COMMON_H
#define __CONFIG_RK3588_COMMON_H

#include <linux/stringify.h>
#include "rockchip-common.h"

#define CFG_IRAM_BASE			0xff000000

#define CFG_SYS_SDRAM_BASE		0
#define SDRAM_MAX_SIZE			0xf0000000

#define ENV_MEM_LAYOUT_SETTINGS		\
	"scriptaddr=0x10E00000\0"	\
	"script_offset_f=0x111FE000\0"	\
	"script_size_f=0x10202000\0"	\
	"pxefile_addr_r=0x11000000\0"	\
	"fdt_addr_r=0x1A300000\0"	\
	"fdtoverlay_addr_r=0x12200000\0"	\
	"kernel_addr_r=0x12280000\0"	\
	"ramdisk_addr_r=0x1A400000\0"	\
	"kernel_comp_addr_r=0x18200000\0"	\
	"kernel_comp_size=0x12200000\0"

#define CFG_EXTRA_ENV_SETTINGS \
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
	"partitions=" PARTS_DEFAULT		\
	ENV_MEM_LAYOUT_SETTINGS			\
	ROCKCHIP_DEVICE_SETTINGS \
	"boot_targets=" BOOT_TARGETS "\0" \
	"dfu_alt_info=ram ram0=ram ram " \
		__stringify(CONFIG_SPL_LOAD_FIT_ADDRESS) " " \
		__stringify(CONFIG_SYS_DFU_DATA_BUF_SIZE) "\0"	\
	"dfu_alt_info_ram=u-boot.itb ram " \
		__stringify(CONFIG_SPL_LOAD_FIT_ADDRESS) " " \
		__stringify(CONFIG_SYS_DFU_DATA_BUF_SIZE)

#endif /* __CONFIG_RK3588_COMMON_H */
