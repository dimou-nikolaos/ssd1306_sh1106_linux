#ifndef __SH1106_H__
#define __SH1106_H__

#define SH1106_I2C_ADDR            0x3c

#define SH1106_COMM_CONTROL_BYTE   0x00
#define SH1106_DATA_CONTROL_BYTE   0x40

#define SH1106_COMM_DISPLAY_OFF    0xae
#define SH1106_COMM_DISPLAY_ON     0xaf
#define SH1106_COMM_HORIZ_NORM     0xa0
#define SH1106_COMM_HORIZ_FLIP     0xa1
#define SH1106_COMM_RESUME_RAM     0xa4
#define SH1106_COMM_IGNORE_RAM     0xa5
#define SH1106_COMM_DISP_NORM      0xa6
#define SH1106_COMM_DISP_INVERSE   0xa7
#define SH1106_COMM_MULTIPLEX      0xa8
#define SH1106_COMM_VERT_OFFSET    0xd3
#define SH1106_COMM_CLK_SET        0xd5
#define SH1106_COMM_PRECHARGE      0xd9
#define SH1106_COMM_COM_PIN        0xda
#define SH1106_COMM_DESELECT_LV    0xdb
#define SH1106_COMM_CONTRAST       0x81
#define SH1106_COMM_DISABLE_SCROLL 0x2e
#define SH1106_COMM_ENABLE_SCROLL  0x2f
#define SH1106_COMM_PAGE_NUMBER    0xb0
#define SH1106_COMM_LOW_COLUMN     0x00
#define SH1106_COMM_HIGH_COLUMN    0x10

#define SH1106_COMM_START_LINE     0x40

#define SH1106_COMM_CHARGE_PUMP    0x8d

#define SH1106_COMM_SCAN_NORM      0xc0
#define SH1106_COMM_SCAN_REVS      0xc8

// Note: SH1106 doesn't use these memory mode commands
// Kept for compatibility but they won't be used
#define SH1106_COMM_MEMORY_MODE    0x20
#define SH1106_COMM_SET_COL_ADDR   0x21
#define SH1106_COMM_SET_PAGE_ADDR  0x22

#define SH1106_HORI_MODE           0x00
#define SH1106_VERT_MODE           0x01
#define SH1106_PAGE_MODE           0x02

#define SH1106_FONT_SMALL          0x00
#define SH1106_FONT_NORMAL         0x01

#define SH1106_128_64_LINES        64
#define SH1106_128_32_LINES        32
#define SH1106_64_48_LINES         48

#define SH1106_128_64_COLUMNS      128
#define SH1106_128_32_COLUMNS      128
#define SH1106_64_48_COLUMNS       64

// Column offset for SH1106
#define SH1106_COLUMN_OFFSET       2

uint8_t sh1106_init(uint8_t i2c_dev);
uint8_t sh1106_end();
uint8_t sh1106_oled_onoff(uint8_t onoff);
uint8_t sh1106_oled_horizontal_flip(uint8_t flip);
uint8_t sh1106_oled_display_flip(uint8_t flip);
uint8_t sh1106_oled_multiplex(uint8_t row);
uint8_t sh1106_oled_vert_shift(uint8_t offset);
uint8_t sh1106_oled_set_clock(uint8_t clk);
uint8_t sh1106_oled_set_precharge(uint8_t precharge);
uint8_t sh1106_oled_set_deselect(uint8_t voltage);
uint8_t sh1106_oled_set_com_pin(uint8_t value);
uint8_t sh1106_oled_set_mem_mode(uint8_t mode);
uint8_t sh1106_oled_set_col(uint8_t start, uint8_t end);
uint8_t sh1106_oled_set_page(uint8_t start, uint8_t end);
uint8_t sh1106_oled_set_constrast(uint8_t value);
uint8_t sh1106_oled_scroll_onoff(uint8_t onoff);
uint8_t sh1106_oled_set_X(uint8_t x);
uint8_t sh1106_oled_set_Y(uint8_t y);
uint8_t sh1106_oled_set_XY(uint8_t x, uint8_t y);
uint8_t sh1106_oled_set_rotate(uint8_t degree);
uint8_t sh1106_oled_default_config(uint8_t oled_lines, uint8_t oled_columns);
uint8_t sh1106_oled_write_line(uint8_t size, char* ptr);
uint8_t sh1106_oled_write_string(uint8_t size, char* ptr);
uint8_t sh1106_oled_clear_line(uint8_t row);
uint8_t sh1106_oled_clear_screen();
uint8_t sh1106_oled_save_resolution(uint8_t column, uint8_t row);
uint8_t sh1106_oled_load_resolution();

#endif
