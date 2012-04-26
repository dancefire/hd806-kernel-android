/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from AMLOGIC, INC.
 * (C) COPYRIGHT 2011 AMLOGIC, INC.
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from AMLOGIC, INC.
 */

/**
 * @file mali_platform.c
 * Platform specific Mali driver functions for meson platform
 */
#include "mali_kernel_common.h"
#include "mali_osk.h"
#include "mali_platform.h"

#include <mach/am_regs.h>

_mali_osk_errcode_t mali_platform_init(_mali_osk_resource_t *resource)
{
    MALI_SUCCESS;
}

_mali_osk_errcode_t mali_platform_deinit(_mali_osk_resource_type_t *type)
{
    MALI_SUCCESS;
}

_mali_osk_errcode_t mali_platform_powerdown(u32 cores)
{
    /* turn on MALI clock gating */
    CLEAR_CBUS_REG_MASK(HHI_MALI_CLK_CNTL, 1 << 8);

    MALI_SUCCESS;
}

_mali_osk_errcode_t mali_platform_powerup(u32 cores)
{
    /* turn off MALI clock gating */
    SET_CBUS_REG_MASK(HHI_MALI_CLK_CNTL, 1 << 8);

    MALI_SUCCESS;
}

void mali_gpu_utilization_handler(u32 utilization)
{
}

#if MALI_POWER_MGMT_TEST_SUITE
u32 pmu_get_power_up_down_info(void)
{
	return 4095;

}
#endif
