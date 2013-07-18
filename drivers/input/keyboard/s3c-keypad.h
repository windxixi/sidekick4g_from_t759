/* linux/drivers/input/keyboard/s3c-keypad.h 
 *
 * Driver header for Samsung SoC keypad.
 *
 * Kim Kyoungil, Copyright (c) 2006-2009 Samsung Electronics
 *      http://www.samsungsemi.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */


#ifndef _S3C_KEYPAD_H_
#define _S3C_KEYPAD_H_

static void __iomem *key_base;


#define KEYPAD_COLUMNS	9	// SIDEKICK_KEYPAD
#define KEYPAD_ROWS	7
#define MAX_KEYPAD_NR  63





int keypad_keycode[] = {


			8,2,3,4,5,6,7,16,		// 7
			10,11,40,13,14,15,17,18,	// 15
			19,20,21,22,23,25,67,27,	// 23
			28,29,30,31,33,34,35,36,	// 31
			48,38,39,41,66,43,44,45,	// 39
			46,56,49,68,51,52,53,54,	// 47
			64,32,65,59,60,61,0,63,		// 55
			42, 50, 58, 0, 0, 0, 0, 0,

};






#define KEYPAD_ROW_GPIOCON      (S5PV210_GPH3_BASE + 0x00)
#define KEYPAD_ROW_GPIOPUD      (S5PV210_GPH3_BASE + 0x08)
#define KEYPAD_COL_GPIOCON      (S5PV210_GPH2_BASE + 0x00)
#define KEYPAD_COL_GPIOPUD      (S5PV210_GPH2_BASE + 0x08)




#define KEYPAD_DELAY		(300)  //600


#define	KEYIFCOL_CLEAR		(readl(key_base+S3C_KEYIFCOL) & ~0xffff)
#define	KEYIFCON_CLEAR		(readl(key_base+S3C_KEYIFCON) & ~0x1f)
#define KEYIFFC_DIV		(readl(key_base+S3C_KEYIFFC) | 0x1)

#define KEYCODE_UNKNOWN 10 

struct s3c_keypad {
	struct input_dev *dev;
	int nr_rows;	
	int no_cols;
	int total_keys; 
	int keycodes[MAX_KEYPAD_NR];
};

extern void s3c_setup_keypad_cfg_gpio(int rows, int columns);

#endif				/* _S3C_KEYIF_H_ */
