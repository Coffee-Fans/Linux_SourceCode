/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *                                        
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#include <drv_conf.h>
#include <osdep_service.h>
#include <drv_types.h>
#include <rtw_byteorder.h>

#include <hal_init.h>

#include "HalVerDef.h"


#define _HAL_INIT_C_
#ifdef CONFIG_CHIP_VER_INTEGRATION
void dump_chip_info(HAL_VERSION	ChipVersion)
{
	if(IS_81XXC(ChipVersion)){
		DBG_871X("Chip Version Info: %s_",IS_92C_SERIAL(ChipVersion)?"CHIP_8192C":"CHIP_8188C");
	}
	else if(IS_92D(ChipVersion)){
		DBG_871X("Chip Version Info: CHIP_8192D_");
	}
	else if(IS_8723_SERIES(ChipVersion)){
		DBG_871X("Chip Version Info: CHIP_8723A_");
	}
	else if(IS_8188E(ChipVersion)){
		DBG_871X("Chip Version Info: CHIP_8188E_");
	}

	DBG_871X("%s_",IS_NORMAL_CHIP(ChipVersion)?"Normal_Chip":"Test_Chip");	
	DBG_871X("%s_",IS_CHIP_VENDOR_TSMC(ChipVersion)?"TSMC":"UMC");
	if(IS_A_CUT(ChipVersion)) DBG_871X("A_CUT_");	
	else if(IS_B_CUT(ChipVersion)) DBG_871X("B_CUT_");	
	else if(IS_C_CUT(ChipVersion)) DBG_871X("C_CUT_");	
	else if(IS_D_CUT(ChipVersion)) DBG_871X("D_CUT_");	
	else if(IS_E_CUT(ChipVersion)) DBG_871X("E_CUT_");	
	else DBG_871X("UNKNOWN_CUT(%d)_",ChipVersion.CUTVersion);
	
	if(IS_1T1R(ChipVersion))	DBG_871X("1T1R_");	
	else if(IS_1T2R(ChipVersion))	DBG_871X("1T2R_");	
	else if(IS_2T2R(ChipVersion))	DBG_871X("2T2R_");
	else DBG_871X("UNKNOWN_RFTYPE(%d)_",ChipVersion.RFType);

	
	DBG_871X("RomVer(%d)\n",ChipVersion.ROMVer);	
}

#endif

