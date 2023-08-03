/*linker script by mohamed waleed*/

MEMORY
{
	flash(RX)	:ORIGIN	 = 0X00000000, LENGTH = 512M
	sram(RWX)	:ORIGIN	 = 0X20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_TEXT = .;
	}> flash

	.data : {
	_S_DATA = .;
	*(.data*)
	. = ALIGN(4);
	_E_DATA = .;
	}> sram AT> flash
	
	.bss : {
	_S_BSS = .;
	*(.bss*)
	_E_BSS = .;
	} > sram
}