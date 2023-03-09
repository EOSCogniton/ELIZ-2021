/* Flash memory and RAM memory maps
		                      // Start       End         Size(KB)
		NVM_Utest=0,          //0x00400000   0x00403FFF     16
		
		DF_Low0  =1,          //0x00800000   0x00803FFF     16
		DF_Low1  =2,          //0x00804000   0x00807FFF     16
		DF_Mid0  =3,          //0x00808000   0x0080FFFF     32
		DF_Mid1  =4,          //0x00810000   0x00817FFF     32
		
		PF_Low2  =5,          //0x00F98000   0x00F9BFFF     16
		PF_Low3  =6,          //0x00F9C000   0x00F9FFFF     16
		PF_High0  =7,         //0x00FA0000   0x00FAFFFF     64
		PF_High1  =8,         //0x00FB0000   0x00FBFFFF     64
		PF_High2  =9,         //0x00FC0000   0x00FCFFFF     64
		PF_High3  =10,        //0x00FD0000   0x00FDFFFF     64
		PF_High4  =11,        //0x00FE0000   0x00FEFFFF     64
		PF_High5  =12,        //0x00FF0000   0x00FFFFFF     64
		PF_Large0  =13,       //0x01000000   0x0103FFFF     256
		PF_Large1  =14,       //0x01040000   0x0107FFFF     256
		PF_Large2  =15,       //0x01080000   0x010BFFFF     256
		PF_Large3  =16,       //0x010C0000   0x010FFFFF     256
		PF_Large4  =17,       //0x01100000   0x0113FFFF     256
		PF_Large5  =18,       //0x01140000   0x0117FFFF     256
		PF_Large6  =19,       //0x01180000   0x011BFFFF     256
		PF_Large7  =20,       //0x011C0000   0x011FFFFF     256
		
		RAM memory map
		0x40000000 0x4001FFFF 128 KB  System RAM on MPC5744P, MPC5743P, MPC5742P, andMPC5741P
		0x40020000 0x4002FFFF 64 KB   System RAM on MPC5744P, MPC5743P, and MPC5742P.Reserved on MPC5741P
		0x40030000 0x4003FFFF 64 KB   System RAM on MPC5744P and MPC5743P.Reserved on MPC5742P and MPC5741P
		0x40040000 0x4005FFFF 128 KB  System RAM on MPC5744P.Reserved on MPC5743P, MPC5742P, and MPC5741P
		0x40060000 0x4FFFFFFF - - Reserved
		
		Local memory
		0x50000000 0x507FFFFF - - Reserved
		0x50800000 0x5080FFFF 64 KB 64 KB D-MEM CPU0
		0x50810000 0x5FFFFFFF - - Reserved

		cal_off:	
		cal_on:	128K
		measure: 64K
*/     

/* Entry Point */
ENTRY(_start)

/* define heap and stack size */
NVM_FLASH_ADDR = 0x00800000 ;

/* define heap and stack size */
__HEAP_SIZE            = 0 ;
__STACK_SIZE           = 60K ;

SRAM_SIZE =  384K;    
/* Define SRAM Base Address */
SRAM_BASE_ADDR = 0x40000000;

/* Define CPU0 Local Data SRAM Allocation */
LOCALDMEM_SIZE = 64K;
/* Define CPU0 Local Data SRAM Base Address */
LOCALDMEM_BASE_ADDR = 0x50800000;
    
  
MEMORY
{   
	/* flash */
	main_nvm_rom :   org = 0x00800000, len = 96K-8
		
	boot_conf : 	 org = 0x00F98008, len = 16K-8	
	boot_reset_vec : org = 0x00FA0000, len = 8	
	boot_text : 	 org = 0x00FA0008, len = 192K-8
	
	flag :			 org = 0x00F9C008, len = 16K-8
	
    main_cal_rom :   org = 0x00FD0000, len = 192K
    main_reset_vec : org = 0x01000000, len = 0x8
    main_text :		 org = 0x01000030, len = 2048K-0x30-0x400 
    ProgramDependenceFlg :  org = 0x011FFC00, len = 0x400
    /* ram */ 
    m_cal_on :	  	 org = 0x40000000, len = 0x8000
    m_data :	  	 org = 0x40000000+0x8000, len = 384K-0x8000
    local_dmem  : 	 org = 0x50800000, len = 64K   
}


SECTIONS
{
    .main_reset_vec  : 
    {
    	KEEP(*(.rchw))
        KEEP(*(.cpu0_reset_vector))
    } > main_reset_vec
    
    .version_info : ALIGN(0x10)
    {
    	KEEP(*(.version))
    } > main_text
    
    identifier_info : ALIGN(0x100)
    {
    	KEEP(*(.identifier))
    } > main_text

    .startup : ALIGN(0x400)
    {
    __start = . ;
    	*(.startup)
    } > main_text
    
    .core_exceptions_table   : ALIGN(4096)
    {
      __IVPR_VALUE = . ;
      KEEP(*(.core_exceptions_table))
    } > main_text

    .intc_vector_table   : ALIGN(4096)
    {
      KEEP(*(.intc_vector_table))
    } > main_text
      
    .text : 
    {
      *(.text.startup)
      *(.text)      
      *(.text.*)
      KEEP (*(.init))
      KEEP (*(.fini))            
      . = ALIGN(16);
    } > main_text
    
    .ctors :
    {
      __CTOR_LIST__ = .;
      /* gcc uses crtbegin.o to find the start of
         the constructors, so we make sure it is
         first.  Because this is a wildcard, it
         doesn't matter if the user does not
         actually link against crtbegin.o; the
         linker won't look for a file to match a
         wildcard.  The wildcard also means that it
         doesn't matter which directory crtbegin.o
         is in.  */
      KEEP (*crtbegin.o(.ctors))
      KEEP (*crtbegin?.o(.ctors))
      /* We don't want to include the .ctor section from
         from the crtend.o file until after the sorted ctors.
         The .ctor section from the crtend file contains the
         end of ctors marker and it must be last */
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
      KEEP (*(SORT(.ctors.*)))
      KEEP (*(.ctors))
      __CTOR_END__ = .;
    } > main_text

    .dtors :
    {
      __DTOR_LIST__ = .;
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
      __DTOR_END__ = .;
    } > main_text
        
    .preinit_array :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } > main_text

    .init_array :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);
    } > main_text

    .fini_array :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } > main_text
          
    .rodata :
    {
      *(.rodata)
      *(.rodata.*)
    } > main_text
    
    .eh_frame_hdr : { *(.eh_frame_hdr) } > main_text
    .eh_frame     : { KEEP (*(.eh_frame)) } > main_text

/**section for bootloader configure 
*/
	.boot_conf : ALIGN(8)
	{
    	KEEP (*(.boot_conf)) 
    	. =  ALIGN(8);
	} >boot_conf
	
    .boot_alg : ALIGN(0x400)
	{
    	KEEP (*(.boot_alg)) 
     	. =  ALIGN(8);   		
	} >boot_conf
    
	.flag : ALIGN(8)
	{
	    __FIRST_FLAG_START = .;
	    KEEP (*(.first_flag))
	    . = ALIGN(8);
	    __FIRST_FLAG_END = .; 	
	} >flag

/**section for the flags of nvm data
*/
	.nvm_flag : ALIGN(8)
	{
	    __FNVM_FLAG_START = .;
    	KEEP (*(.fnvm_flag))  
    	__FNVM_FLAG_END = .;

    	__UFNVM_FLAG_START = .;
    	KEEP (*(.ufnvm_flag))
    	__UFNVM_FLAG_END = .;
	} >main_text

/**section for offline calibration data 
*/
    .cal_data_off :ALIGN(0x100)
    {
    	KEEP (*(.cal_data_off))  
    	
    } >main_cal_rom
 		
 		
/**section for online calibration data 
*/    
    .cal_data_on : ALIGN(0x100)
    {
    	KEEP (*(.cal_data_on)) 
    	
    } >m_cal_on AT>main_cal_rom
 
/**section for online nvm data 
* save the default value in main_text for data lost
* main_nvm_rom is used for write/read nvm data
*/ 
	.nvm_data   : ALIGN(0x10000)
	{
	  __FNVM_RAM_START = .;
      KEEP (*(.fnvm_data)) 
      . = ALIGN(8) ;
      __FNVM_RAM_END = .;	
    	
      __UFNVM_RAM_START = .;
      KEEP (*(.ufnvm_data))
      . = ALIGN(8)  ;
      __UFNVM_RAM_END = .;
    } >m_data AT>main_text
    
/**section for measurement data 
*/  
    .measure_data (NOLOAD) : ALIGN(0x8000)
    {
    	KEEP (*(.measure_data))  	
    } >m_data
  
	.data   : 
	{
	  *(.data)
	  *(.data.*)
	}  > m_data AT>main_text
    
    .sdata2  :
	{  
	  *(.sdata2)
	  *(.sdata2.*)
	} > m_data AT>main_text

	.sbss2    (NOLOAD)   :
	{
      /* _SDA2_BASE_ = .; */ 
	  *(.sbss2)
	  *(.sbss2.*)
	} > m_data
    
    .sdata  :
	{
	  *(.sdata)
	  *(.sdata.*)
	} > m_data AT>main_text
    
	.bss   (NOLOAD)  :
	{
	  __BSS_START = .;
	  *(.sbss)
	  *(.sbss.*)	
      *(.bss)
      *(.bss.*)
      *(COMMON)
      __BSS_END = .;
    } > m_data
    
    .stack (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;
      PROVIDE (_end = . );
      PROVIDE (end = . );      
      . += __HEAP_SIZE ;
      __HEAP_END = . ;
      _stack_end = . ;
      . +=  __STACK_SIZE ;
      _stack_addr = . ;
      __SP_INIT = . ;
      . += 4;
    } > local_dmem
    
    .ProgramDependenceFlg :
    {
      KEEP (*(.ProgramDependenceFlg))
    } >ProgramDependenceFlg
 
/*-------- LABELS USED IN CODE -------------------------------*/

__USD_ONLINE_FLAG = 		0x00F9C200;
__NVM_FLASH_END = 			0x00817ff8;

/*	Labels for bootloader configure		*/
__BOOT_CONF_START = ADDR(.boot_conf);
__BOOT_CONF_SIZE = SIZEOF(.boot_conf); 

/*	Labels for bootloader alg		*/
__BOOT_ALG_FLASH_START = LOADADDR(.boot_alg);
__BOOT_ALG_START = ADDR(.boot_alg);    
 
/*	Labels for offline calibration data		*/
__CAL_OFF_FLASH_START = ADDR(.cal_data_off);
__CAL_OFF_SIZE = SIZEOF(.cal_data_off);   
   
/*	Labels for online calibration data		*/
__CAL_ON_RAM_START = ADDR(.cal_data_on);
__CAL_ON_FLASH_START = LOADADDR(.cal_data_on);
__CAL_ON_SIZE = SIZEOF(.cal_data_on);  

/*	Labels for  NVM data		*/
__NVM_SRAM_ADDR = ADDR(.nvm_data);
__NVM_SIZE   = SIZEOF(.nvm_data);
__NVM_ROM_ADDR  = LOADADDR(.nvm_data);	 /*default value */ 	
__NVM_FLASH_START = __FNVM_FLASH_START ; /* write /read area */

/*	Labels for fixed NVM data		*/
__FNVM_FLASH_START = NVM_FLASH_ADDR;
__FNVM_SIZE = __FNVM_RAM_END - __FNVM_RAM_START;

/*	Labels for un-fixed NVM data		*/
__UFNVM_FLASH_START = __FNVM_FLASH_START + __FNVM_SIZE;
__UFNVM_SIZE = __UFNVM_RAM_END - __UFNVM_RAM_START;


/*	Labels for measurement data		*/   
__MEASURE_RAM_ADDR = ADDR(.measure_data);
__MEASURE_SIZE = SIZEOF(.measure_data);
        
/* Labels for Copying Initialised Data from Flash to RAM */
__DATA_SRAM_ADDR  = ADDR(.data);
__SDATA_SRAM_ADDR = ADDR(.sdata);

__DATA_SIZE   = SIZEOF(.data);
__SDATA_SIZE  = SIZEOF(.sdata);

__DATA_ROM_ADDR  = LOADADDR(.data);
__SDATA_ROM_ADDR = LOADADDR(.sdata);
   
/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = SRAM_SIZE;
__SRAM_BASE_ADDR = SRAM_BASE_ADDR;

__LOCAL_DMEM_SIZE = LOCALDMEM_SIZE;
__LOCAL_DMEM_BASE_ADDR = LOCALDMEM_BASE_ADDR;

__BSS_SIZE    = __BSS_END - __BSS_START;    
      
}

