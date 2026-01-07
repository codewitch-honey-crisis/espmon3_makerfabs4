#ifdef PANEL_DEPENDENCIES
// lib_deps = codewitch-honey-crisis/htcw_esp_lcd_st7701
#include "esp_lcd_st7701.h"
// lib_deps = codewitch-honey-crisis/htcw_esp_lcd_touch_gt911
#include "esp_lcd_touch_gt911.h"
// lib_deps = codewitch-honey-crisis/htcw_esp_lcd_panel_io_additions
#include "esp_lcd_panel_io_additions.h"
#endif
#define LCD_PIN_NUM_CS 1
#define LCD_PIN_NUM_SCL 12
#define LCD_PIN_NUM_SDA 11 
#define LCD_IO_INIT spi_line_config_t st7701_line_config = { \
        .cs_io_type = IO_TYPE_GPIO, \
        .cs_gpio_num = LCD_PIN_NUM_CS, \
        .scl_io_type = IO_TYPE_GPIO, \
        .scl_gpio_num = LCD_PIN_NUM_SCL, \
        .sda_io_type = IO_TYPE_GPIO, \
        .sda_gpio_num = LCD_PIN_NUM_SDA, \
        .io_expander = NULL, \
    }; \
    esp_lcd_panel_io_3wire_spi_config_t st7701_io_config = ST7701_PANEL_IO_3WIRE_SPI_CONFIG(st7701_line_config, 0); \
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_3wire_spi(&st7701_io_config, &lcd_io_handle)); 
#define LCD_VENDOR_CONFIG st7701_vendor_config_t vendor_config = { \
        .rgb_config = &rgb_panel_cfg, \
        .flags.enable_io_multiplex = 0, \
    }; \
    static uint8_t st7701_init_data_1[] = {0x77,0x01,0x00,0x00,0x10};\
    static uint8_t st7701_init_data_2[] = {((LCD_VRES >> 3) + 1)+(((LCD_VRES >> 1) & 3)?0x80:0x00),((LCD_VRES >> 1) & 3)};\
    static uint8_t st7701_init_data_3[] = {0x00,0x10,0x08};\
    static uint8_t st7701_init_data_4[] = {0x77,0x01,0x00,0x00,0x11};\
    static uint8_t st7701_init_data_5[] = {0x0D,0x02};\
    static uint8_t st7701_init_data_6[] = {0x31,0x05};\
    static uint8_t st7701_init_data_7[] = {0x08};\
    static uint8_t st7701_init_data_8[] = {0x00,0x11,0x18,0x0E,0x11,0x06,0x07,0x08,0x07,0x22,0x04,0x12,0x0F,0xAA,0x31,0x18};\
    static uint8_t st7701_init_data_9[] = {0x00,0x11,0x19,0x0E,0x12,0x07,0x08,0x08,0x08,0x22,0x04,0x11,0x11,0xA9,0x32,0x18};\
    static uint8_t st7701_init_data_10[] = {0x77,0x01,0x00,0x00,0x11};\
    static uint8_t st7701_init_data_11[] = {0x60};\
    static uint8_t st7701_init_data_12[] = {0x32};\
    static uint8_t st7701_init_data_13[] = {0x07};\
    static uint8_t st7701_init_data_14[] = {0x80};\
    static uint8_t st7701_init_data_15[] = {0x49};\
    static uint8_t st7701_init_data_16[] = {0x85};\
    static uint8_t st7701_init_data_17[] = {0x21};\
    static uint8_t st7701_init_data_18[] = {0x78};\
    static uint8_t st7701_init_data_19[] = {0x00,0x1B,0x02};\
    static uint8_t st7701_init_data_20[] = {0x08,0xA0,0x00,0x00,0x07,0xA0,0x00,0x00,0x00,0x44,0x44};\
    static uint8_t st7701_init_data_21[] = {0x11,0x11,0x44,0x44,0xED,0xA0,0x00,0x00,0xEC,0xA0,0x00,0x00};\
    static uint8_t st7701_init_data_22[] = {0x00,0x00,0x11,0x11};\
    static uint8_t st7701_init_data_23[] = {0x44,0x44};\
    static uint8_t st7701_init_data_24[] = {0x0A,0xE9,0xD8,0xA0,0x0C,0xEB,0xD8,0xA0,0x0E,0xED,0xD8,0xA0,0x10,0xEF,0xD8,0xA0};\
    static uint8_t st7701_init_data_25[] = {0x09,0xE8,0xD8,0xA0,0x0B,0xEA,0xD8,0xA0,0x0D,0xEC,0xD8,0xA0,0x0F,0xEE,0xD8,0xA0};\
    static uint8_t st7701_init_data_26[] = {0x02,0x00,0xE4,0xE4,0x88,0x00,0x40};\
    static uint8_t st7701_init_data_27[] = {0x3C,00};\
    static uint8_t st7701_init_data_28[] = {0xAB,0x89,0x76,0x54,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x20,0x45,0x67,0x98,0xBA};\
    static uint8_t st7701_init_data_29[] = {0x77,0x01,0x00,0x00,0x13};\
    static uint8_t st7701_init_data_30[] = {0xE4};\
    static uint8_t st7701_init_data_31[] = {0x77,0x01,0x00,0x00,0x00};\
    static st7701_lcd_init_cmd_t st7701_lcd_init_cmds[] = {\
        {0xFF, st7701_init_data_1, sizeof(st7701_init_data_1), 0},\
        {0xC0, st7701_init_data_2, sizeof(st7701_init_data_2), 0},\
        {0xC3, st7701_init_data_3, sizeof(st7701_init_data_3), 0},\
        {0xFF, st7701_init_data_4, sizeof(st7701_init_data_4), 0},\
        {0xC1, st7701_init_data_5, sizeof(st7701_init_data_5), 0},\
        {0xC2, st7701_init_data_6, sizeof(st7701_init_data_6), 0},\
        {0xCD, st7701_init_data_7, sizeof(st7701_init_data_7), 0},\
        {0xB0, st7701_init_data_8, sizeof(st7701_init_data_8), 0},\
        {0xB1, st7701_init_data_9, sizeof(st7701_init_data_9), 0},\
        {0xFF, st7701_init_data_10, sizeof(st7701_init_data_10), 0},\
        {0xB0, st7701_init_data_11, sizeof(st7701_init_data_11), 0},\
        {0xB1, st7701_init_data_12, sizeof(st7701_init_data_12), 0},\
        {0xB2, st7701_init_data_13, sizeof(st7701_init_data_13), 0},\
        {0xB3, st7701_init_data_14, sizeof(st7701_init_data_14), 0},\
        {0xB5, st7701_init_data_15, sizeof(st7701_init_data_15), 0},\
        {0xB7, st7701_init_data_16, sizeof(st7701_init_data_16), 0},\
        {0xB8, st7701_init_data_17, sizeof(st7701_init_data_17), 0},\
        {0xC1, st7701_init_data_18, sizeof(st7701_init_data_18), 0},\
        {0xC2, st7701_init_data_18, sizeof(st7701_init_data_18), 0},\
        {0xE0, st7701_init_data_19, sizeof(st7701_init_data_19), 0},\
        {0xE1, st7701_init_data_20, sizeof(st7701_init_data_20), 0},\
        {0xE2, st7701_init_data_21, sizeof(st7701_init_data_21), 0},\
        {0xE3, st7701_init_data_22, sizeof(st7701_init_data_22), 0},\
        {0xE4, st7701_init_data_23, sizeof(st7701_init_data_23), 0},\
        {0xE5, st7701_init_data_24, sizeof(st7701_init_data_24), 0},\
        {0xE6, st7701_init_data_22, sizeof(st7701_init_data_22), 0},\
        {0xE7, st7701_init_data_23, sizeof(st7701_init_data_23), 0},\
        {0xE8, st7701_init_data_25, sizeof(st7701_init_data_25), 0},\
        {0xEB, st7701_init_data_26, sizeof(st7701_init_data_26), 0},\
        {0xEC, st7701_init_data_27, sizeof(st7701_init_data_27), 0},\
        {0xED, st7701_init_data_28, sizeof(st7701_init_data_28), 0},\
        {0xFF, st7701_init_data_29, sizeof(st7701_init_data_29), 0},\
        {0xE5, st7701_init_data_30, sizeof(st7701_init_data_30), 0},\
        {0xFF, st7701_init_data_31, sizeof(st7701_init_data_31), 0},\
        {0x21, 0, 0, 0},\
        {0x11, NULL, 0, 120},\
    };\
    vendor_config.init_cmds = st7701_lcd_init_cmds;\
    vendor_config.init_cmds_size = 36;\
    vendor_config.flags.enable_io_multiplex = 0;\
    vendor_config.flags.use_mipi_interface = 0;\
    vendor_config.rgb_config = &rgb_panel_cfg;\
    vendor_config.flags.auto_del_panel_io = 0;\
    vendor_config.flags.mirror_by_cmd = 0;
#define LCD_PIN_NUM_DE 45
#define LCD_PIN_NUM_VSYNC 4
#define LCD_PIN_NUM_HSYNC 5
#define LCD_PIN_NUM_CLK 21
#define LCD_PIN_NUM_D00 39
#define LCD_PIN_NUM_D01 40
#define LCD_PIN_NUM_D02 41
#define LCD_PIN_NUM_D03 42
#define LCD_PIN_NUM_D04 2
#define LCD_PIN_NUM_D05 0
#define LCD_PIN_NUM_D06 9
#define LCD_PIN_NUM_D07 14
#define LCD_PIN_NUM_D08 47
#define LCD_PIN_NUM_D09 48
#define LCD_PIN_NUM_D10 3
#define LCD_PIN_NUM_D11 6
#define LCD_PIN_NUM_D12 7
#define LCD_PIN_NUM_D13 15
#define LCD_PIN_NUM_D14 16
#define LCD_PIN_NUM_D15 8
#define LCD_PIN_NUM_BCKL -1
#define LCD_DATA_ENDIAN_LITTLE 0
#define LCD_HSYNC_FRONT_PORCH 10
#define LCD_HSYNC_PULSE_WIDTH 8
#define LCD_HSYNC_BACK_PORCH 50
#define LCD_VSYNC_FRONT_PORCH 40
#define LCD_VSYNC_PULSE_WIDTH 8
#define LCD_VSYNC_BACK_PORCH 20
#define LCD_CLK_ACTIVE_NEG 1
#define LCD_CLK_ON_LEVEL 1
#define LCD_DE_ON_LEVEL 1
#define LCD_BIT_DEPTH 16
#define LCD_INIT esp_lcd_new_panel_st7701
#define LCD_HRES 480
#define LCD_VRES 480
#define LCD_INVERT_COLOR 0
#define LCD_COLOR_SPACE LCD_COLOR_RGB
#define LCD_SWAP_COLOR_BYTES 0
#define LCD_TRANSFER_IN_SPIRAM
#define LCD_CLOCK_HZ (16 * 1000 * 1000)

#define TOUCH_I2C_HOST I2C_1
#define TOUCH_PIN_NUM_SDA 17
#define TOUCH_PIN_NUM_SCL 18
#define TOUCH_PIN_NUM_INT -1
#define TOUCH_PIN_NUM_RST 38
#define TOUCH_INIT esp_lcd_touch_new_i2c_gt911
#define TOUCH_I2C_ADDRESS ESP_LCD_TOUCH_IO_I2C_GT911_ADDRESS
#define TOUCH_CLOCK_HZ (400*1000)
#define TOUCH_RST_ON_LEVEL 0
#define TOUCH_INT_ON_LEVEL 0
#define TOUCH_DC_BIT_OFFSET 0
#define TOUCH_CMD_BITS 16
#define TOUCH_PARAM_BITS 0
#define TOUCH_DISABLE_CONTROL_PHASE 1
#define SD_PIN_NUM_CLK 12
#define SD_PIN_NUM_MISO 13
#define SD_PIN_NUM_MOSI 11
#define SD_PIN_NUM_CS 10

