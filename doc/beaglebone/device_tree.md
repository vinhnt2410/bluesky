## Device tree (beaglebone black)

### Memory node

Memory node cung cấp một thông tin cơ bản về địa chỉ và kích thước vùng nhớ vật lý. Node này thường được filled hoặc updated bởi bootloader.

Memory layout được mô tả bởi node như sau:

```
memory {
	reg =  <(baseaddr1) (size1)
		(baseaddr2) (size2)
		...
		(baseaddrN) (sizeN)>;
};
```
baseaddrX:	base address của memory bank được định nghĩa.
sizeX:		kích thước của memory bank.

Có thể có nhiều hơn một memory bank được định nghĩa.

### Ví dụ beaglebone black

trong file device tree [..]linux/arch/arm/boot/dts/am335x-boneblack-common.dtsi memory node được thể hiện như sau:

```
/ {
	/* Memory block bắt đầu với địa chỉ 0x80000000 và 
	 * có kích thước là 0x20000000 bytes (512MB).
	 * Địa chỉ cuối của memory block là 0xA0000000
	 */
	memory@80000000 {
		device_type = "memory";
		reg = <0x80000000 0x20000000>; /* 512 MB */
	};

	clk_mcasp0_fixed: clk_mcasp0_fixed {
		#clock-cells = <0>;
		compatible = "fixed-clock";
		clock-frequency = <24576000>;
	};

	clk_mcasp0: clk_mcasp0 {
		#clock-cells = <0>;
		compatible = "gpio-gate-clock";
		clocks = <&clk_mcasp0_fixed>;
		enable-gpios = <&gpio1 27 0>; /* BeagleBone Black Clk enable on GPIO1_27 */
	};
	...
};

```

### Reserved memory

Reserved memory nhằm tạo ra một vùng nhớ RAM nằm ngoài quyền kiểm soát của hệ điều hành để phục vụ cho các mục đính riêng.

### Ví dụ

Reserve một vùng nhớ có kích thước 256KB cho beaglebone như sau:
Thông thường khi reserve memory chúng ta sẽ reserve ở vùng cuối của memory block.
Bassed address của reserved node được tính bằng cách lấy địa chỉ cuối cùng của memory block và trừ đi kích thước muốn reserve

```
BaseAddrReservedNode = 0xA0000000 - 0x00040000 (256KB) = 0x9ffc0000
```

```
/{	
	reserved-memory {
		#address-cells = <1>;
		#size-cells = <1>;
		ranges;
		
		memory_reserved: memory_reserved@0x9ffc0000 {
			reg = <0x9ffc0000 0x00040000>;
			no-map;
			status = "okay";
		};
	};

  ...
};
```
Trường #address-cells và #size-cells trong parent node là được dùng để chỉ ra kích thước địa chỉ của cells và kích thước cells trong các trường con. 
	#address-cells = <1> base address của memory block trong trường con chỉ có 32 bits
	#address-cells = <2> base address của memory block trong trường con chỉ có 64 bits

Nếu không gian địa chỉ của node cha và con là được xác định thì một node có thể thêm một thuộc tính ranges rỗng. Điều này nói lên là không gian địa chỉ node con được mapped 1:1 vào trong không gian địa chỉ node cha.


[https://elinux.org/Device_Tree_Usage]


## BUILD kernel cross compiler for beaglebone

### Get source code

### Setup enviroment

```
sudo apt-get install -y build-essential
sudo apt-get install -y libncurses5 libncurses5-dev
sudo apt-get install -y bison flex libssl-dev
sudo apt-get install lzop
sudo apt-get install u-boot-tools

```



### Build

```
dtc -I dtb -O dts -o am335x-boneblack.dts am335x-boneblack.dtb
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- LOADADDR=0x80000000 uImage dtbs
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules
```
