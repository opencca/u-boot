// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2023 Collabora Ltd.
 */

#include <fdtdec.h>
#include <fdt_support.h>

#ifdef CONFIG_OF_BOARD_SETUP
int rock5b_add_reserved_memory_fdt_nodes(void *new_blob)
{
	struct fdt_memory gap1 = {
		.start = 0x3fc000000,
		.end = 0x3fc4fffff,
	};
	struct fdt_memory gap2 = {
		.start = 0x3fff00000,
		.end = 0x3ffffffff,
	};

	// OpenCCA RME reserve: ARM_DRAM_RME_RESERVE_BASE
	struct fdt_memory opencca_rme_reserve = {
		.start = 0,
		.end = 0x1fffffff,
	};

	// The RMM must allocate granules for all RMM-managable memory.
	// For easier board compatibility, limit addressable memory to 16 GB,
	// even if 32 GB variant supports more RAM.
	struct fdt_memory opencca_rmm_not_managed = {
		.start = 0x3fc000000,
		.end = 0x7ffffffff,
	};

	unsigned long flags = FDTDEC_RESERVED_MEMORY_NO_MAP;
	unsigned int ret;

	/*
	 * Inject the reserved-memory nodes into the DTS
	 */
	ret = fdtdec_add_reserved_memory(new_blob, "gap1", &gap1,  NULL, 0,
					 NULL, flags);
	if (ret)
		return ret;

	ret = fdtdec_add_reserved_memory(new_blob, "gap2", &gap2,  NULL, 0,
					  NULL, flags);
	if (ret)
		return ret;

	ret = fdtdec_add_reserved_memory(new_blob, 
			"opencca_rme_reserve", &opencca_rme_reserve,  NULL, 0,
			NULL, flags);
	if (ret)
		return ret;

	ret = fdtdec_add_reserved_memory(new_blob, 
			"opencca_rmm_not_managed", &opencca_rmm_not_managed,  NULL, 0,
			NULL, flags);

	return ret;
		
}

int ft_board_setup(void *blob, struct bd_info *bd)
{
	return rock5b_add_reserved_memory_fdt_nodes(blob);
}
#endif
