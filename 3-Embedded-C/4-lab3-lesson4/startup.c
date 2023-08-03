//startup.c
//mohamed waleed

#include<stdint.h>
extern int main(void);

//we can replicate stack_top effect using a n array of 1024B located by .bss and uninitilaized 
static unsigned long  Stack_top[256];
void reset_handler ();

void defualt_handler ()
{
	reset_handler();
}
void nmi_handler () __attribute__((weak,alias("defualt_handler")));;
void h_fault_handler () __attribute__((weak,alias("defualt_handler"))) ;;
void mm_fault_handler () __attribute__((weak,alias("defualt_handler")));;
void bus_fault_handler () __attribute__((weak,alias("defualt_handler")));;
void usage_fault_handler () __attribute__((weak,alias("defualt_handler")));;


void (* const g_p_fn_Vectors [])() __attribute__((section(".vectors"))) =
{
	( void (*)() ) ((unsigned long)Stack_top + sizeof(Stack_top)),
	( void (*)() ) &reset_handler,
	( void (*)() ) &nmi_handler,
	( void (*)() ) &h_fault_handler,
	( void (*)() ) &mm_fault_handler,
	( void (*)() ) &bus_fault_handler,
	( void (*)() ) &usage_fault_handler
};

extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void reset_handler (void) 
{
	//copy .data from flash to rom
	unsigned int data_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char *d_src = (unsigned char*)&_E_TEXT;
	unsigned char *d_dst = (unsigned char*)&_S_DATA;
	for(int i =0; i<data_size; i++){
		*((unsigned char*)d_dst++) = *((unsigned char*)d_src++); 
	}

	//initialize bss values with zero in sram
	unsigned int bss_size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	unsigned char *b_dst = (unsigned char*)&_S_BSS;
	for(int i =0; i<bss_size; i++){
		*((unsigned char*)b_dst++) = (unsigned char) 0; 
	}

	// branch/jump to main after initilalizing memory segments
	main();
}