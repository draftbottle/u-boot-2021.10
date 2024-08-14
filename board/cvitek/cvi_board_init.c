static void set_rtc_register_for_power(void)
{
	printf("set_rtc_register_for_power\n");

    mmio_write_32(0x050250AC, 0x2);
 	mmio_write_32(0x03001098, 0x0);
 	mmio_write_32(0x0300109C, 0x0);
 	mmio_write_32(0x03001090, 0x0);
 	mmio_write_32(0x03001094, 0x0);
 	mmio_write_32(0x05027084, 0x0);
	mmio_write_32(0x05027088, 0x0);
 	mmio_write_32(0x0502708C, 0x0);
	mmio_write_32(0x05027090, 0x0);
 	mmio_write_32(0x050260BC, 0x1700);
 	mmio_write_32(0x05026128, 0x0);
	// Reset Key
	mmio_write_32(0x050260D0, 0x7);
}

int cvi_board_init(void)
{
	// LED
	PINMUX_CONFIG(IIC0_SDA, XGPIOA_29);

	// USB
	PINMUX_CONFIG(USB_VBUS_EN, XGPIOB_5);

	// I2C4 for TP
	PINMUX_CONFIG(VIVO_D1, IIC4_SCL);
	PINMUX_CONFIG(VIVO_D0, IIC4_SDA);

	// TP INT
	PINMUX_CONFIG(JTAG_CPU_TCK, XGPIOA_18);
	// TP Reset
	PINMUX_CONFIG(JTAG_CPU_TMS, XGPIOA_19);

	// Camera0
	PINMUX_CONFIG(IIC3_SCL, IIC3_SCL);
	PINMUX_CONFIG(IIC3_SDA, IIC3_SDA);
	PINMUX_CONFIG(CAM_MCLK0, CAM_MCLK0); // Sensor0 MCLK
	PINMUX_CONFIG(CAM_RST0, XGPIOA_2);   // Sensor0 RESET

	// Camera1
	PINMUX_CONFIG(IIC2_SDA, IIC2_SDA);
	PINMUX_CONFIG(IIC2_SCL, IIC2_SCL);
	PINMUX_CONFIG(CAM_MCLK1, CAM_MCLK1); // Sensor1 MCLK
	PINMUX_CONFIG(CAM_PD1, XGPIOA_4);    // Sensor1 RESET

	// WIFI/BT
	PINMUX_CONFIG(CLK32K, PWR_GPIO_10);

	set_rtc_register_for_power();

	return 0;
}
