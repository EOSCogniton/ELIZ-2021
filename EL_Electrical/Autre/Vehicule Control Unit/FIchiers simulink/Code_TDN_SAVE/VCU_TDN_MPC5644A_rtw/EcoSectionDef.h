#ifndef EcoSectionDef_H
#define EcoSectionDef_H
#include "ser_mem.h"
#define __RP                           _CAL_DATA_OFF
#define __RWP                          _CAL_DATA_ON
#define __MP                           _MEASURE_DATA_
#define __FNVMP                        _FNVM_DATA_
#define __FNVMF                        _FNVM_FLAG_
#define __UFNVMP                       _UFNVM_DATA_
#define __UFNVMF                       _UFNVM_FLAG_
#define __BOOTP                        _BOOT_CONF_
#define __BOOT_SEEDKEY_CODE            _BOOT_SEEDKEY_CODE_
#define __ADDR_EPK                     _ADDR_EPK_
#endif

/******************************************************************************/
#ifdef PUSH__RP
#undef PUSH__RP
#endif

#ifdef POP__RP
#undef POP__RP
#endif

/******************************************************************************/
#ifdef PUSH__RWP
#undef PUSH__RWP
#endif

#ifdef POP__RWP
#undef POP__RWP
#endif

/******************************************************************************/
#ifdef PUSH__MP
#undef PUSH__MP
#endif

#ifdef POP__MP
#undef POP__MP
#endif

/******************************************************************************/
#ifdef PUSH__FNVMP
#undef PUSH__FNVMP
#endif

#ifdef POP__FNVMP
#undef POP__FNVMP
#endif

/******************************************************************************/
#ifdef PUSH__FNVMF
#undef PUSH__FNVMF
#endif

#ifdef POP__FNVMF
#undef POP__FNVMF
#endif

/******************************PUSH__UFNVMP************************************************/
#ifdef PUSH__UFNVMP
#undef PUSH__UFNVMP
#endif

#ifdef POP__UFNVMP
#undef POP__UFNVMP
#endif

/********************************POP__UFNVMP**********************************************/
#ifdef PUSH__UFNVMF
#undef PUSH__UFNVMF
#endif

#ifdef POP__UFNVMF
#undef POP__UFNVMF
#endif

/******************************************************************************/
#ifdef PUSH__BOOTP
#undef PUSH__BOOTP
#endif

#ifdef POP__BOOTP
#undef POP__BOOTP
#endif

#ifdef PUSH__BOOT_SEEDKEY_CODE
#undef PUSH__BOOT_SEEDKEY_CODE
#endif

#ifdef POP__BOOT_SEEDKEY_CODE
#undef POP__BOOT_SEEDKEY_CODE
#endif

#ifdef PUSH__ADDR_EPK
#undef PUSH__ADDR_EPK
#endif

#ifdef POP__ADDR_EPK
#undef POP__ADDR_EPK
#endif

/******************************************************************************/
