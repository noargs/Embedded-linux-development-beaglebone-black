## Embedded linux development with Beaglebone black    
   
Official website for [Beaglebone black](https://www.beagleboard.org/boards/beaglebone-black).  
    
[Design](https://git.beagleboard.org/beagleboard/beaglebone-black) contain Beaglebone black **Schematic** and **Reference Manual** in Docs folder of this repository.  

Go to [wiki](https://elinux.org/Main_Page) and find your board BeagleBone Black for ton of information)  
    

## Introduction (just enough to get started):

It is actually redundant to explain about Beaglebone hardware, when you can get all the info regarding this board from its official site here     
   
The community describes this board as follows

“Beaglebone Black is a low-cost, community-supported development platform for developers and hobbyists. Boot Linux in under 10 seconds and get started on development in less than 5 minutes with just a single USB cable.”

So, you should pay attention to these points     
    
## 1. It’s an open source h/w, s/w platform.
That means, if you are planning to design your own single board computer (a SBC), then you can reuse the Beaglebone black’s design, schematics, software, etc. So, the beaglebone hardware enables you to quickly come up with your own customized board. Most of the companies ,what they do is , they take the BBB hardware design, like part numbers, schematics , BOM etc and they add customer specific add-ons or features then release the product to the market.   
   
When the hardware team is working on the new hardware, the software team will not sit idle, they test their software, drivers, and applications on reference ( such as Beaglebone ) board, which greatly reduces the time to market effort.  
   
## 2. A low cost Single Board Computer (SBC)   
   
The BBB hardware is powerful yet low cost SBC currently available.   
   
So, what’s a SBC?   
   
When a single piece of circuit board, comprises most of the personal Computer hardware/software components, then it is called as a SBC. Of course you cannot have terra bytes of hard disk mounted on a circuit board, but it has significant amount of on board memory, it has wireless/wired connectivity, it has USB interfaces, it can run operating systems, you can connect to monitor or projector. Yes! You can compare this with the motherboard of your PC.  
   
Hence it is called as single board computer. Another most famous SBC is Raspberry PI but it is partially an “open hardware” because the SOC manufacturer hides the details.    
   
<img src="images/bbb_intro.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">   
<img src="images/bbb_intro2.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">   
<img src="images/bbb_intro3.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro4.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro5.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro6.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro7.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro8.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro9.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">     
<img src="images/bbb_intro10.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">  
<img src="images/bbb_intro11.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">    
<img src="images/bbb_intro12.png" alt="Non ReatTime Vs RealTime" title="BBB Introduction">   
   
    
## Connecting BBB and USB to serial TTL convertor hardware or cable    
   
 As I mentioned in the previous document, you can use either a standalone USB to serial TTL convertor hardware like shown below (you should arrange for the connecting jumper wires though)   
<img src="images/usb_ttl.png" alt="Non ReatTime Vs RealTime" title="BBB and USB-TTL converter">   
   
Or, you may use the USB to serial TTL converter with cable like below. This is more convenient because it has good length and you need not to bother about connecting to BBB using jumper wires.

This cable has embedded “USB to serial “converter chip inside.  
   
<img src="images/usb_ttl2.png" alt="Non ReatTime Vs RealTime" title="BBB and USB-TTL converter">   
   
And always remember when you connect  “USB to Serial Convertor” to any hardware like BBB, the TX pin of this module should go to the RX pin of the another board, in this case BBB. Take look in to the table below for connection details. It’s very simple.   
   
<img src="images/usb_ttl3.png" alt="Non ReatTime Vs RealTime" title="BBB and USB-TTL converter">   
   
Here is a BBB schematic details of J1 UART0 pins   
    
<img src="images/usb_ttl4.png" alt="Non ReatTime Vs RealTime" title="BBB and USB-TTL converter">   
   
## Serial port monitoring software   
    
<img src="images/serial_port_monitoring.png" alt="Serial port monitoring">   
   
**Using Minicom**   
   
Confirm by running `sudo minicom` command in terminal to see if `Minicom` already installed  
    
OR   
   
Install on Ubuntu by first running `sudo apt-get update` and then `sudo apt-get install minicom`   
   

## Configure minicom on first time install    
   
Just connect your USB to UART convertor hardware to the PC (not beaglebone hardware.)  
   
Run the `dmesg` on terminal   
     
<img src="images/dmesg.png" alt="dmesg to check chipset info">   
      
> Chipset converter `pl2303` is detected and attached to ttyUSB0. Alternatively, if you are using FTDI, then following output will be shown in terminal as shown below    
   
<img src="images/ftdi.png" alt="FTDI FT232R">    
   
Type `sudo minicom -s` to configure the minicom and configure `Serial port setup` by choosing  
    
<img src="images/minicom_output.png" alt="Minicom output">   
   
Keep the **Hardware Flow Control** and **Software Flow Control** as **No** as according to BBB Schematic, it doesn't have this feature available on the board   
    
<img src="images/usb-ttl_no_hw.png" alt="Hardware flow control">   
   
Finally `Save setup as dfl` so we don't have to setup the configuration again and again.  


## BBB getting started   
   
Let us do some experiment with our new Beaglebone black Revision C hardware. Remember, the Beaglebone hardware comes with the Debian flavor of the Linux operating system which is stored in the EMMC memory of your Beaglebone hardware. when you give power (USB mini B connector over P4) to the Beaglebone hardware, it boots the pre-built or pre-loaded Debian Linux distribution from this board. A drive FAT based file system `BeagleBone Getting Started` will appear upon successful booting of a board, They have divided the EMMC memeory to different partitions like FAT and ext3 etc. and they have stored the images over there. You will find a page `START.htm` inside the Drive which contains Getting started documentation with Beaglebone hardware. Inside `Drivers/Windows/` you will see driver `BONE_D64.exe` which enables the Beaglebone's internet over USB capability. Hence you need not to connect the Ethernet cable as Beaglebone supports the Ethernet over the USB interface.   
    
> [!NOTE]   
> If some reason you failed to install the driver then you have to disable `Driver signature enforcement` on windows pc.  
    
The installation of the driver resulted in creation of the interface in the `Network connections > Uidentified network | Remote NDIS compatible Device` , which allows BBB to communicate with PC over USB cable (Ethernet over USB)    
    
## BBB Web Interface    
    
The BBB Debian OS running on the board already running a web server which you can connect to by typing the IP address `http://192.168.7.2` for Windows (You can look for the right IP address on `START.htm` according to your OS as shown below)  

 <img src="images/ip_address.png" alt="Table of your IP Address for your OS">     


 ## Communicating with BBB    

We will use **minicom** to talk to FTDI USART-TTL and **SSH** to connect to BBB (over internet to USB). We will accomplish both `minicom` and `ssh` from two different terminals inside Ubuntu. 

Initially FTDI may not show up on Ubuntu (when we run `dmesg`) as it is owned by Windows OS however we will go to Virtualbox and select `Devices > USB > FTDI` to change its ownership to Ubuntu. Now, it will appear (i.e. ttyUSB0) inside Ubuntu. There we will go to `Serial port setup` and rest follow the section `Configure minicom on first time install` as explained previously. Now reset your board and you will get the logs on Ubuntu's minicom.   

Let's login now in the Serial window of minicom with debain username `debian` and default password as `temppwd`. Now, check the `ifconfig`. You will find two interfaces `usb0` **192.168.7.2** (internet over usb, as beaglebone is connected with laptop over P4 through USB mini B, we will also use it to connect over ssh on seperate terminal) and `usb1` **192.168.6.2**  communicating over USB-TTL FTDI with minicom.     

On second terminal run `ping 192.168.7.2` to confirm that communication with beaglebone hardware is working over USB mini B at P4 (Internet over USB). You can now ssh beaglebone with `ssh -l debian 192.168.7.2` 
    
> [!NOTE]    
> Use the Virtual machine only when you want to compile the kernel, bootloader, or use the build root software i.e. busy box. However if you only want to write application for the beaglebone then just use the **eclipse** which is installed on your primary operating system such Windows, Mac etc. **You don't need to install Eclipse on the virtual machine for application development purpose**    
    

# BBB Linux booting process                    

Let's explore, How to boot the Linux kernel on the ARM based hardware such as Beaglebone Black target hardware which is powered by the SOC AM335x (ARM cortex A8 processor) from Texas Instruments.    
      
To run Linux on this embedded board, we need minimum of 4 software components as shown below.     
      
<img src="images/linux_boot_req.png" alt="Linux Boot Requirement">   
    
## RBL (ROM Boot Loader)     
    
A very tiny boot loader with limited functionalities runs out of the ROM memory (176 Kb, another SOC internal RAM memory of 128 Kb) of the SOC when you power up the board. This boot loader is written by the vendor, in our case, written by the Texas Instruments, and stored in the ROM of the SOC during taping out of the chip. You cannot change this boot loader (cannot overwrite). You may also not get the source code of this boot loader. The job of the ROM is to set up the, Stack setup, calling `main()`, initialising watch dog timer (Initialised for 3 mins), and SOC PLLs clock 500 MHz to A8 by MPU_ADPLLS etc. Based on the value of 15:14 bits of the SYSBOOT register, the RBL comes to know about the value of the external crystal connected to the SOC (in our case 24MHz Crystal at the bottom of BBB with part name Y2. 14th bit SYS_BOOT14(LCD_DATA14) tied to high voltage and 15th pin SYS_BOOT15(LCD_DATA15) tied to low voltage as shown below). Finally to load and execute the second stage boot loader **SPL/MLO** from the internal memory (_SRAM_) of the SOC.   
    
<img src="images/rbl.png" alt="ROM Boot Loader">    
     
<img src="images/startup_procedure.png" alt="Startup procedure">      
     
<img src="images/pll.png" alt="DPLLs and clocks configurations">      
     
<img src="images/clock_config.png" alt="Clock configuration">        
     
<img src="images/rbl_summary.png" alt="RBL Summary">    
     
     
## SPL/MLO (Secondary Program Loader / Memory Loader)   
     
The job of the Secondary stage boot loader is to initialise the SOC to a point that the Third stage boot loader **U-boot** can be loaded into external RAM (DDR memory) of the board.       
     
<img src="images/spl_summary.png" alt="SPL Summary">    
     
Suppose, if you want to clock your MPU at 300MHz instead of say 500MHz, you can only do that in the second stage boot loader (by reconfiguring the PLL) where you can bring down the clock frequency to 300MHz and vice versa   
    
RBL must load and execute the second stage boot loader within 3 minutes (Watchdog expiry)  Let's say, it finds the second stage boot loader on the e-MMC memory of the board. Then the ROM code copies the MLO/SPL to the internal RAM of the SOC.       
     
<img src="images/spl.png" alt="SPL copied into Internal RAM of the SOC">    
     
The MLO or SPL will have its own image header which is decided by TI itself. From the image header, it will get 2 important information. One is the load address and another one is the total size of the MLO.         
     
<img src="images/mlo_image_header.png" alt="MLO/SPL image header">    

> [!NOTE] 
> Remember that, MLO will not load the third stage boot loader like U-Boot to the internal RAM of the SOC. Why? Because, the internal RAM is only of 128KB. U-boot obviously will not fit there. So, it copies it to the DDR memory which is external to the SOC.    
     
<img src="images/rbl_to_uboot.png" alt="Can we avoid using MLO/SPL by making RBL load u-boot directly to SRAM">           
     
**Why AM335x RBL cannot load the Uboot directly to DDR?**   

ROM code won’t be having any idea about what kind of DDR RAM being used in the product to initialize it. DDR RAM is purely product/ board specific. Let’s say there are 3 board/product manufacturing companies X,Y,Z. X may design a product using AM335x SOC with DDR3. In which lets say DDR3 RAM is produced by microchip. Y may design its product using AM335x SOC with DDR2 produced by Transcend and Z may not use DDR memory at all for its product.

So, RBL has no idea in which product this chip will be used and what kind of DDR will be used, and what are DDR tuning parameters like speed, bandwidth, clock augments, size, etc. 

RBL just tries to fetch the SPL found in memory devices such as eMMC and SD card or peripherals like UART,EMAC,etc.

> [!NOTE] 
> And in the SPL/MLO, you should know, what kind of DDR is connected to your product and based on that you have to change the SPL code , rebuild it and generate the binary to use it as the second stage boot loader.

For example the Beaglebone black uses DDR3 from Kingston and if your product uses DDR3 from transcend, then if the turning parameters are different then you have to change the DDR related header files and the tuning parameter macros of the SPL , rebuild and generate the binary   
    

Now, let's see practically booting of the ROM bootloader and the MLO on the BeagleBone hardware. For that, first let's use the [pre-built binaries](prebuilt_images/Angstrom_Demo/) named MLO-beaglebone-2013.04.    
     
You need a micro SD card and partition (with Gparted, you can download GUI via Ubuntu Software center) card into two. One partition must be of type FAT filesystem (preferably with space of 1GB) and another partition should be of type EXT3. But, for the time being, we will not be using the

> [!NOTE] 
> Remember, never operate command line using root privileges. instead use `sudo` command   
    
<img src="images/partition.png" alt="Partitioning the SC card">           
     
Running `$ sudo dmesg` and check your SD card (which may identified by the PC as **sdb** device).   
   
Delete the /dev/sdb which will make it unalloacted. Keep first partition as **fat16**, New size as **1024 MB** and Label as **BOOT**    
    
Second partition as **ext3**, New size as whatever is remaining, and Label as **ROOTFS**  now apply the changes by clicking on Green color Tick.

Lastly, Right click on **fat16** partition, select `Manage Flags > boot`   
   
Copy the MLO-beaglebone-2013.04 from the [pre-built binaries](prebuilt_images/Angstrom_Demo/) and paste it into BOOT partition by renaming it to _MLO_.     
`$ cp MLO-beaglebone-2013.04 /media/<user-name>/BOOT/MLO     
     
Take out the SD card and insert it into BBB and connect both cables (one connect to BBB and another USB-TTL convertor to PC, USB-TLL needed as we cannot see the log messages as Internet over USB is not configured for BBB)     
     
<img src="images/mlo_boot.png" alt="Boot BBB with MLO from SD Card ">   

It will boot the MLO however will encounter with an error as it could not find the u-boot **spl: error reading image u-boot.img, err - -1** which we will flash into BOOT partition in the next section     


## U-boot      
    
The job of the Third stage boot loader is to load and execute the Linux kernel from the DDR memory of the board. Hence the booting actually takes place in 3 stages.

_And to complete the successful boot of the **Linux kernal**, we also need a root file system **RFS**_    
     
<img src="images/uboot_header.png" alt="U-boot image header">    
     

Now, let's see practically booting of the u-boot bootloader on the BeagleBone hardware. For that, first let's use the [pre-built binaries](prebuilt_images/Angstrom_Demo/) named `u-boot-beaglebone-2013.04-r0.img` and placed it into BOOT partition of SD card which was partitioned in the previous section. Now SD card BOOT paritioned drive (fat16) contain **MLO** and **u-boot.img**.     
`$ cp u-boot-beaglebone-2013.04-r0.img /media/<user-name>/BOOT/u-boot.img    

<img src="images/mlo_boot.png" alt="Boot BBB with MLO from SD Card ">    

It will boot until the end where it couldn't find the Linux image as message says **File not found /boot/uImage**     
   

**MLO and u-boot.img summary**   
<img src="images/mlo_uboot_summary.png" alt="MLO and u-boot.img summary">    

<img src="images/u-boot_jobs.png" alt="The job of U-boot">    

You should also provide one file called **uEnv.txt**, which consist of environmental variable values of the u-boot which directs u-boot how to behave. You can override any default u-boot behavior by using this file.        
    
<img src="images/uEnv.png" alt="uEnv file">    
  
Now u-boot always looks for uImage (zImage plus u-boot header). zImage is elf binary format of the Linux kernel and if you append the u-boot header to it, it becomes uImage. From the image header, u-boot gets lot of information about the Linux kernel.         
    
<img src="images/uimage.png" alt="uImage">    
    
<img src="images/uimage_header.png" alt="uImage header">        
     
Image header shown which u-boot expects on top of the zImage. This header is of 64 bytes in total. let's quickly download the [pre-built Linux image](prebuilt_images/Angstrom_Demo/) named `Angstrom-systemd-image-eglibc-ipk-v2012.12-beagleboard.rootfs.tar.xz`, extract and you will find **uImage-3.8.13** in **boot** folder which is pretty old Linux kernel. However we will copy all the extracted folders into our SD card **ROOTFS** partition.     
`$ cp -r * /media/<user-name>/ROOTFS/`    
`$ sync`    
and we'll try to boot it. Then analyse the logs sent by the u-boot.

Later, we will see how to create our own root file system using the Busybox, and by taking the help of Buildroot.   
    
Now you see the ROOTFS partition of the SD card consist of the root file system and u-boot.img (in BOOT partition) supposed to load the Linux kernel. But u-boot has no idea where exactly the Linux kernel is actually residing in the SD card. However the Linux kernel image is actually present in the `ROOTFS/boot` folder of the second partition. Hence we have to use `uEnv.txt` file to tell u-boot where exactly the Linux kernel is present. Add `uEnv.txt` (with the content shown below) into _BOOT_ folder of **fat16** along with **MLO** and **u-boot.img**.   
```
console=ttyO0,115200n8
ipaddr=192.168.7.2
serverip=192.168.7.1
loadaddr=0x82000000
fdtaddr=0x88000000
loadfromsd=load mmc 0:2 ${loadaddr} /boot/uImage;load mmc 0:2 ${fdtaddr} /boot/am335x-boneblack.dtb
linuxbootargs=setenv bootargs console=${console} root=/dev/mmcblk0p2 rw
uenvcmd=setenv autoload no; runloadfromsd; run linuxbootargs; bootm ${loadaddr} - ${fdtaddr}
``` 
We are instructing u-boot to keep the Linux kernel at `0x82000000` and dtb file at `0x88000000`. `runloadfromsd` is a custom name, you can give any of your liking.  
    
```
$ umount /media/<user-name>/BOOT
$ umount /media/<user-name>/ROOTFS
$ sudo minicom
```   
Insert/Boot from the SC card   
    
<img src="images/uboot_boot_kernel.png" alt="uboot hands over control to linux kernel">   

As shown above, uboot hands over control to Linux kernel          
     
**Reading U-boot header information of the uImage manually by using U-boot commands**   

1. Load the uImage from Memory device (SD card/eMMC) in to the DDR memory of the board.   
2. Use the memory dump command of U-boot to dump header information.  
    
<img src="images/uboot_commands.png" alt="uboot commands">    

```
U-Boot# help load
load - load binary file from a filesystem  

# load uImage from 2nd partition into RAM (DDR) location 0x82000000
U-Boot# load mmc 0:2 0x82000000 /boot/uImage   

U-Boot# help md
md - memory display

# display 64 bytes header informtion starting from 0x82000000
U-Boot# md 0x82000000 4

U-Boot# help imi
iminfo - print header information for application image

U-Boot# imi 0x82000000
```         
     
## BeagleBone Board Boot options    
     
you can boot the AM335x SOC from the following boot sources    
      
1. NAND Flash    
2. NOR Flash (eXecute In place, XIP)    
3. USB    
4. eMMC    
5. SD card   
6. Ethernet    
7. UART   
8. SPI          
    
_Page number 4106 of the [TRM](Docs/TRM_AM335x_techincal_reference_manual.pdf) , you will find the below table._    
     
<img src="images/sysboot_config.png" alt="SYSBOOT Configuration">   
    
Take a look at _SYSBOOT[4:0]_ `SYSBOOT` is one of the register of this SOC and its first five bits decide the boot order .   
   
For example,   
When SYSBOOT [4:0] = 00000b (This is reserved, you cannot use this configuration)
When SYSBOOT [4:0] = 00001b then **1st** SOC will try to boot from UART0, if fails, **2nd** it tries to boot from XIP (XIP stands for eXutable In Place memory like NOR Flash), if that also fails, **3rd** it will try to boot from MMC0, if no success, **4th** it tries to boot from SPI0, if that also fails, then SOC outputs the error message and stops.  

## How SOC decides the boot order?    

When you reset the SOC, the code stored in the ROM of the SOC runs first !    
     
<img src="images/boot_order.png" alt="SYSBOOT Configuration">   
    
The code stored in the “ROM” is called **ROM boot loader**, this is programmed in to the ROM of the SOC during taping out of the chip, you cannot change it as it is in the ROM Read only.

The job of the ROM is to set up the SOC clock, watch dog timer, etc and load the second stage boot loader (MLO or SPL). By reading the register SYSBOOT [15:0], and based on the value of SYSBOOT[4:0] it prepares the list of booting devices. The register SYSBOOT [15:0] value is decided by the voltage level on the SYSBOOT pins.

Hence, if SYSBOOT[4:0] = 00011b, then boot order will be , UART0, SPI0, XIP, MMC0 (as shown in the above table). Therefore, we can say that, The SYSBOOT pins configure the boot device order (set by SYSBOOT[4:0]). Some board, will give you the control to change the SYSBOOT[15:0] value by using dip switches like below.      
     
<img src="images/dip_switches.jpg" alt="Board with Dip switches">   
    
However, in the BBB, there are no such dip switches to configure the SYSBOOT pins. BBB has some other circuitry to decide the SYSBOOT pins voltage level, read on!!    
    
## BBB Boot order configuration circuit   
   
In BBB you will find this circuitry, (In the [SRM](Docs/BBB_SRM.pdf))    
     
<img src="images/boot_config_design.png" alt="Processor boot configuration design">   
     
Here observe that SYS_BOOT2 is connected to a button S2 (Boot button) of the BBB.

When you simply give power to the board, You will find the voltage level as below.

SYS_BOOT0 = 0V
SYS_BOOT1 = 0V
SYS_BOOT2 = 1V
SYS_BOOT3 = 1V
SYS_BOOT4 = 1V

You can confirm this by measuring the voltage level using Mutlimeter (voltage of 45, 44, 43,41, 40 pins of the expansion header P8 of the board as SYSBOOT[4:0] = 11100)   
     
<img src="images/expansion_header.png" alt="Expansion headers">   
     
And when you press the S2 button, SYS_BOOT2 will be grounded , so SYSBOOT[4:0]= 11000     
      
Now based on S2 (BBB boot button) we got 2 boot configurations:

1. S2 released (SYSBOOT[4:0] = 11100)

The boot order will be

MMC1 (eMMC)
MMC0 (SD card)
UART0
USB0

2. S2 pressed (SYSBOOT[4:0] = 11000)   
    
The boot order will be

SPI0
MMC0 (SD card)
USB0
UART0

So, to conclude, there are 5 boot sources supported for this board including SPI.    
     
1) eMMC Boot(MMC1):

 eMMC is connected over MMC1 interface, This is the fastest boot mode possible, eMMC is right there on your board, so need not to purchase any external components or memory chip. This is the default boot mode. As soon as you reset the board, the board start booting from loading the images stored in the eMMC.   
 
 If no proper boot image is found in the eMMC, then Processor will automatically try to boot from the next device on the list. 

2) SD Boot:

 If the default ( that is booting from eMMC) boot mode fails, then it will try to boot from the SD card you connected to the sd card connector at MMC0 interface. 
 
 If you press S2 and then apply the power, then the board will try to boot from the SPI first, and if nothing is connected to SPI, it will try to boot from the MMC0 where our SD card is found   
 
 Also remember that we can use SD card boot to flash boot images on the eMMC. So if you want to write new images on the eMMC  then you can boot through sd card, then write new images to eMMC, then reset the board, so that your board can boot using new images stored in the eMMC.  We will do these experiments later in this course. Don’t worry!

3) Serial boot:

In this mode, the ROM code of the SOC will try to download the boot images from the serial port.

We have separate experiment on this boot mode and its very interesting. 

4) USB BOOT:   

You may be familiar with this boot mode, that is booting through usb stick!   

You would have booted your PC through the usb stick. What you do is, you restart the PC, then press bios button to put the PC in to bios mode, there you select boot form usb, right  

It is very similar, when you reset the board, you can make your board to boot from the USB stick. 

## More details about ROM Code Booting procedure!

These are the 2 flow charts, you can find in the [TRM](Docs/TRM_AM335x_techincal_reference_manual.pdf) **page 4103** of the am335x SOC    
     
<img src="images/boot_procedure.png" alt="ROM Code Booting procedure">   
         
Here, you can see that the ROM code goes through its boot device list to load the Second stage boot loader (SPL/MLO). **It will prepare the boot devices list based on the value of SYSBOOT pins**. 

## The ROM Code start-up procedure    
    
(page 4102)       
     
<img src="images/startup_procedure.png" alt="Startup procedure">     


# Linux boot sequence   

<img src="images/linux_boot_control_flow.png" alt="Control flow during Linux boot">    

Take a look into the flow control diagram above, from **U-Boot** to **Linux** to launching of the very **first application** .

1. **U-boot** hands off the control to the `head.s` file in the Boot strap loader of the Linux   
2. Then, the `head.s` calls miscellaneous.c (`misc.c`) file. That also belongs to the **Linux's Bootstrap Loader** to uncompress the compressed image. 
3. Then the control comes to another `head.s` file of the Linux kernel.    
4. And from `head.s` file of the Linux kernel, the control comes to the `head-common.c`   
5. And then on to `main.c` file of the Linux kernel,   
6. Lastly, the first application of the Linux kernel that is `init` is launched.   
     
**How U-boot hands off control to the "Boot Strap Loader" of the Linux kernel??**  

Let's explore from the source file `bootm.c` of the u-boot by cloning git repo `$ git clone https://source.denx.de/u-boot/u-boot.git` and [documentation](https://docs.u-boot.org/en/latest/build/source.html).    

`$ sudo nano arch/arm/lib/bootm.c`     
    
This is the code of the U-Boot which actually picks up Linux kernel from the memory and hands off the control to the Linux kernel. There is a function called `static void boot_jump_linux(struct bootm_headers *images, int flag)` takes two arguments, **bootm_headers** a structure and a flag.   
    
```c
static void boot_jump_linux(struct bootm_headers *images, int flag)
{
#ifdef CONFIG_ARM64
	...
#ifdef CONFIG_ARMV8_PSCI
		...
#else
	unsigned long machid = gd->bd->bi_arch_number;
	char *s;
	void (*kernel_entry)(int zero, int arch, uint params);
	unsigned long r2;
	int fake = (flag & BOOTM_STATE_OS_FAKE_GO);

	kernel_entry = (void (*)(int, int, uint))images->ep;
#ifdef CONFIG_CPU_V7M
	...
#endif
	...
```    
    
`kernel_entry` function pointer is actually initialized to `images->ep` that is an entry point (Linux entry point). You can find the field `ep` in the structure `bootm_headers` by `$ grep -r "bootm_headers" *` found in `include/image.h`   
    
```c
#ifndef USE_HOSTCC
	struct image_info	os;		/* os image info */
	ulong		ep;		/* entry point of OS */

	ulong		rd_start, rd_end;/* ramdisk start/end */

	char		*ft_addr;	/* flat dev tree address */
	ulong		ft_len;		/* length of flat device tree */

	ulong		initrd_start;
	ulong		initrd_end;
	ulong		cmdline_start;
	ulong		cmdline_end;
	struct bd_info		*kbd;
#endif
```    
    
<img src="images/kernel_entry.png" alt="Kernel entery point">    
    
After that, this code is storing the value of `ft_addr` into the variable called `r2`. **ft_addr** is the RAM address at which the device tree binary is located. DTB or FTT, that is Flattened device tree is actually a binary which describes the various peripherals present on the board. That Binary Tree is needed by the Linux kernel during the boot.   
    
<img src="images/ft_addr.png" alt="Device tree binary">    
    
Next the U-Boot is dereferencing the kernel entry point `kernel_entry(0, machid, r2)` and sends three important arguments.   
    
<img src="images/kernel_entery_deref.png" alt="Kernel entry dereference">       
    
It means, I have detected this machine ID and U-boot is passing that information to the Linux kernel And 'r2' is where the ft address is stored. Hence when Linux comes to know about this machine ID, it will execute those initialization routines, which are required for this machine id. At this point the U-Boot is actually handing off control to the Linux kernel's bootstrap loader.   
   
 <img src="images/calling_heads.png" alt="Kernel entry calling head.S">  

This code actually calls the **Start** routine in the `head.S` file of the bootstrap loader. which can be found in the [Linux source of Beaglebone board](https://github.com/beagleboard/linux) at location `$ vi arch/arm/boot/compressed/head.S` and look for `/start:`    
     
<img src="images/start_routine.png" alt="Start Routine">     

If you go little further, you will find two lines of code where it is saving the architecture ID (machine id to `r7`) and the dtb address from `r2` (`kernel_entry(0, machid, r2)`) to `r8`.   
Furthermore, `head.S` file of the bootstrap loader calls the `misc.c` to decompress the kernel (search `/decompress_kernel`) by branching `bl` to `misc.c`

Now go to `misc.c` by typing `$ vi arch/arm/boot/compressed/misc.c` and search again for `/decompress_kernel`. Here you will find the function `void decompress_kernel()`    
    
Next, the control from the `head.S` of **Linux's Boot Strap Loader** to another `head.S` of **Linux Kernel** which you can locate in `vi arch/arm/kernel/head.S`. This `head.S` is architecture specific code (doesn't depend upon any SOC family). It's a generic startup code for arm processors which does arm specific initialization as shown below.   
    
<img src="images/head_s_linux_kernal.png" alt="Linux kernel's head.S responsibilities">     
 
> [!NOTE]    
> Remember that the uncompression and relocation of the Linux kernel image is not the responsibility of the U-Boot rather it is done by the **Linux's Boot Strap Loader** which is glued to the **Linux Kernel** image.    
    
If you read further about `vi arch/arm/kernel/head.S` it says the following. (MMU=off means no virtual addressing is enabled yet)    
     
<img src="images/head_s_linux_kernal2.png" alt="head.S kernel startup entry point">    

Now let's explore some of the important sub routines called by this file.     
    
**Check for proper processor type**     
     
`__lookup_processor_type__` call will search for the processor architecture present on the board. After figuring out the processor type, it calls the appropriate processor specific initialization routinesmfound in the respective **processor specific files** in the path `arch/arm/mm/proc-*.S`.     
   
You will find in the `arch/arm/mm` directory that, every processor has its own processor specific initialization file. Basically the processor specific calls are made to deal with the memory management unit as explained here in these comments. _Perform a soft reset of the system. Put the CPU into the same state as it would be if it had been reset, and branch to what would be the reset vector_    
    
Also note that, the register r10 holds the processor info structure related to a processor which is detected by the call to `__lookup_processor_type__` previously as explained in the comment says that _on return, the CPU will be ready for the memory management unit to be turned on_, which confirms that all the processor specific calls are made to initialize the mmu before turning it on. It means, before giving control to the Linux generic code, mmu initialization and turning on of the MMU is important. That's the duty of these architecture specific codes.    
    
Another important assembly subroutine enable MMU which initializes the page table pointers and turn on the MMU, so that the kernel can start running with virtual address support.   
    
<img src="images/head_s_linux_kernal3.png" alt="head.S kernel startup entry point"> 

Next it branches to `start_kernel()` (C function implemented in architecture independent generic file `main.c`) from **head-common.S** file located in the same path **arch/arm/kernel**. Now from here the flow control comes to the file `main.c` of the Linux kernel.   
     
<img src="images/head_s_linux_kernal4.png" alt="head.S kernel startup entry point">    
     
At this point, all the architecture dependent initialisations are over, your CPU ARM cortex- A8 is ready with the MMU support and Linux is all set to do architecture independent kernel initialisation (through `main.c`). And if you analyse the code of `head.S`, it's particularly interested in searching of CPU type like whether it belongs to ARM 9, ARM 10 or ARM cortex A8, etc. And once it comes to know about the architecture type, it majorly initialises the MMU and creates the initial page table entries and then enables the MMU of the processor for virtual memory support, before giving control to the main.c file of the Linux kernel which is the generic one.
     
**Launch of INIT**    

The function `start_kernel()` in init main.c code does all the startup work for the Linux kernel from initialising the very first kernel thread, all the way to mounting a root file system and executing the very first user space Linux application program.

The entry point into this main.c is `start_kernel()` function (in `linux-4.4/init/main.c`) which is a very huge function calling lots of other initialisation functions.   
     
<img src="images/start_kernel.png" alt="start_kernel() in linux/init/main.c">  		 

Now take a look little further down at line _895_. Here the kernel prints the `linux_banner` string `pr_notice("%s", linux_banner)`, which you can identify in the log.   
    
<img src="images/log_linux.png" alt="Linux log">  		

The `linux_banner` string can be found in the file `linux-4.4/init/version.c`

Furthermore, `start_kernel()` does lots of early initialization of the Linux kernel such as:    
    
- Extracting the command line arguments sent by the boot loader     
- Initialisation of the console to get the error messages    
- Memory management initialization    
- Scheduler initialization    
- Timer initialization    
- High resolution timer initialization    
- Software IRQ initialization

Hence, It initialises various subsystems of a Linux kernel before mounting the root file system and launching the very first Linux application. You can learn more by going through all these helper functions one by one inside `start_kernel()` and exploring what exactly they do.

Finally, It calls a function called `rest_init()` and inside it creates two threads `kernel_init` (with pid 1) and `kthreadd`. It then starts scheduler `schedule_preempt_disabled()` and then kernel is going to **CPU idle loop** which is actually inifinite while(1) loop named `cpu_startup_entry(CPUHP_ONLINE)`.    
    
The `kernel_init` kernel thread will then execute the very first user application called init. That's the reason `init` application actually inherits its kernel threads pid number 1 from `kernel_init`. Whereas `kthreadd` kernel thread is used to spawn other kernel threads.   
    
```c
/*
	 * We need to spawn init first so that it obtains pid 1, however
	 * the init task will end up wanting to create kthreads, which, if
	 * we schedule it before we create kthreadd, will OOPS.
	 */
	pid = user_mode_thread(kernel_init, NULL, CLONE_FS);
	/*
	 * Pin init on the boot CPU. Task migration is not properly working
	 * until sched_init_smp() has been run. It will set the allowed
	 * CPUs for init to the non isolated CPUs.
	 */
	rcu_read_lock();
	tsk = find_task_by_pid_ns(pid, &init_pid_ns);
	tsk->flags |= PF_NO_SETAFFINITY;
	set_cpus_allowed_ptr(tsk, cpumask_of(smp_processor_id()));
	rcu_read_unlock();

	numa_default_policy();
	pid = kernel_thread(kthreadd, NULL, NULL, CLONE_FS | CLONE_FILES);
	rcu_read_lock();
	kthreadd_task = find_task_by_pid_ns(pid, &init_pid_ns);
	rcu_read_unlock();
```   
    
If we visit `kernel_init` function;  

```c
static int __ref kernel_init(void *unused)
{
	int ret;

	/*
	 * Wait until kthreadd is all set-up.
	 */
	wait_for_completion(&kthreadd_done);

	kernel_init_freeable();
	/* need to finish all async __init code before freeing the memory */
	async_synchronize_full();

	system_state = SYSTEM_FREEING_INITMEM;
	kprobe_free_init_mem();
	ftrace_free_init_mem();
	kgdb_free_init_mem();
	exit_boot_config();
	free_initmem();
	mark_readonly();

	/*
	 * Kernel mappings are now finalized - update the userspace page-table
	 * to finalize PTI.
	 */
	pti_finalize();

```				

The function `free_initmem()` reclaims the memory which are being used by the initialisation function so far. Because, those functions are no longer needed. As log shows `Freeing init memory: 248K` which is reclaimed by the kernel.   
    
Further down it tries to run the init application and start from `/sbin/init` if it fails then it tries to find init from other location i.e. `/etc/init` and if everyting fails then it simply executes the shell application `/bin/sh` which is present in the root file system and just returns.

 ```c
 	if (execute_command) {
		ret = run_init_process(execute_command);
		if (!ret)
			return 0;
		panic("Requested init %s failed (error %d).",
		      execute_command, ret);
	}
	...

	if (!try_to_run_init_process("/sbin/init") ||
	    !try_to_run_init_process("/etc/init") ||
	    !try_to_run_init_process("/bin/init") ||
	    !try_to_run_init_process("/bin/sh"))
		return 0;

	panic("No working init found.  Try passing init= option to kernel. "
	      "See Linux Documentation/admin-guide/init.rst for guidance.");
}
```    

If none of these programs found in these location, then it actually throws an error `panic("No working init found.....)`

And note that you can also mention the path of the init program `if (execute_command)` by using the Linux command line argument called init. You have to give the path of the init program, in case you have any customised or some other path. Then it first checks the `execute_command` first. That's how the Linux finally launches the user application.mEither it launches the init `/sbin/init` or if no init found then at least it will launch the shell application `/bin/sh`.

That's how the control comes all the way from boot loaders `u-boot` to Linux bootstrap loader to linux kernel to launching of the very first application. And init is a application which is responsible for launching other applications. As we make a progress, we will experiment practically by creating our own root file system and keeping the init program and we'll see, how we can use the init program to launch other applications or other kernel services.   

<img src="images/control_flow_linux_boot.png" alt="Control flow linux boot">  
    				

# Updating the eMMC memory with the latest debian OS image and BBB Network configurations.   
   
We will flash eMMC of the Beaglebone board and then boot the Beagleboard using the eMMC memory (Revision C, onboard 4GB of eMMC memory) and the board already comes with pre-stored Debian OS, However we will reflash the Debian OS present on the eMMC memory of the board (for learning purposes and understand the working).    
    
The **eMMC** memory is actually connected to the **mmc1** interface and the **micro SD card** connector is connected to the **mmc0** interface of the AM335x SOC, And we also have 512 MB of **DDR** memory connected to the DDR interface of the SOC. 

 <img src="images/bbb_mmc_interface.png" alt="Table of your IP Address for your OS"> 
    
      
> [!NOTE]
> Remember, the board always tries to boot from the mmc1 interface first by default (eMMC Memory) when you power up the board. **However, we will take the help of Micro SD card to flash the eMMC memory** (flashing the bootable images and root file system onto the eMMC memory).   
    
1. Download the latest [Debian OS image](https://www.beagleboard.org/distros) (i.e. am335x-debian-11.7-iot-armhf-2023-09-02-4gb.img.xz). You can use `xz-utils` to extract `$ unxz am335x--.img.xz`      
    
2. Write that bootable image to the SD card using disk writing software [etcher](www.balena.io/etcher) by downloading the software on ubuntu. If it doesn't run by `$ ./balenaEtcher-1.18.11.AppImage` then make it executable by chmod +x. You might as well install `apt-get install fuse` if this package is missing.   
    
3. Insert the SD card into the beaglebone and then make beaglebone boot from the SD card (Power down BBB by long press of Power button, insert the SD card, keep pressing the S2 button while pressing the Power button gently and release the S2 button shortly, and you will see the LEDs of BBB blink linearly, probably take 5-10 mins).     
   
4. Execute the eMMC flasher script by logging into BBB via SSH `$ ssh -l debian 192.168.6.2` (used to be at `/opt/scripts/tools/eMMC` with the name `init-eMMC-flasher-v3.sh` but now you can simply run `sudo enable-beagle-flasher` to flash all the contents of the SD Card on to the eMMC memory) and finally reboot `sudo reboot` and BBB LEDs will blink linearly for awhile when it stopped then you can safely remove the SD Card.   
     
      
> [!NOTE]    
> If your board already running latest version of debian OS image, then you NEED NOT to try this.   
> Check your BBB debian OS version `$ lsb_release -da` and compare the output with debian latest release. (You have to log into BBB by `minicom` if you aren't able to find the right `/dev/<PORT>` then use `$ dmesg` command)

To configure BBB Network connection over USB, follow the Networking [guide](Docs/Networking.pdf) 
   
As disscussed in the Networking guide following commands has to be saved in the **BBB** and **Host** machine.   

<img src="images/internetToTarget_BBB.png" alt="internetToTarget BBB">    

<img src="images/internetToTarget_HOST.png" alt="internetToTarget Host">    
     

# Linux Device Tree		 
     
This is also called as Flattened device tree.   

Imagine, we have our own custom board (Beaglebone hardware or any other board with SOC as shown below) and it is based on ARM architecture and the board has got couple of on board peripherals like the Zigbee transceiver, Serial flash, EEPROM, SD card connector, USB interface etc and they are connected with some bus interfaces like USART, SPI, I2C, SDIO, USB, etc.	    

<img src="images/custom_board.png" alt="Peripheral of our custom board">    
     
Now, interestingly the onboard peripherals are not dynamically discoverable which are connected to SPI, I2C, SDIO, Ethernet, etc., have no capability to announce there existence on the board by themselves to the operating system like Linux. Because, those interfaces (like I2C, SPI, SDIO, etc.) don't have that intelligence to support dynamic discoverability. Even though those peripherals are there on the board, the operating system has no idea about configuring them. On the other hand, When you connect a pen drive or thumb drive via USB to use the port, it has the intelligence to announce its presence to the operating system dynamically by pushing some information.

Now the question is, how can we make Linux kernel know about these platform devices (**USB is not platform device as it is self-discoverable**) or peripherals present on the board or announce their existence to the kernel, since they cannot do it themselves.

One solution was to go for a static way, to hard code these platform device details in a file called the board file (as shown below) and when the kernel calls the function `my_board_init()` add each and every platform device to the kernel subsystem with a platform specific data (i.e. data structure which actually describes the peripheral). As the Board file is basically the part of the Linux kernel, so when you modify to add new entries, you have to recompile the kernel. Then only your changes will take effect 
   
<img src="images/platform_devices.png" alt="Platform devices">    
   
When the corresponding driver is loaded, the Linux calls the "probe" function of the driver and the platform data will be passed to the driver and the driver will then initialize the peripheral.    
    
<img src="images/drivers.png" alt="Drivers">  		
     
For instance, let's say the name of the platform device zigbee is zigbee100. The corresponding driver name must also be same as the platform device name (zigbee100.ko). When you load this driver the Linux binds the device with this driver. So, Linux immediately calls the "probe" function of this driver and the driver will then take care of initializing the peripheral.   
    
<img src="images/zigbee100.png" alt="Zigbee drivers">     
    
When you have different boards, each board will have different on board peripherals. Hence for every board you'll be having one board file. Consequently for each board, you'll be having separate kernel image. Kernal image of one board will not be compatible with other boards.   
    
<img src="images/uimage_several_boards.png" alt="uimage for several boards">  		
    
**This was a problem which the Linux community wanted to solve.** They wanted to cutoff the dependency of platform device enumeration from the Linux kernel. That is hard coding of platform device specific details in to the Linux kernel. Hence the ARM community came up with the idea called **Device Tree** also called as **Flattened Device Tree Model**.    
    
In this case, instead of hard coding the hardware details into the Linux kernel board file, every board vendors has to come up with a file called DTS (Device Tree Source File or Device Tree Structure). This file actually consists of all the details related to the board written using some predefined syntaxes. This file consists of lots of data structures, which describe all the required peripherals of the board.   
    
<img src="images/dts.png" alt="DTS for every board">		
    
And this file will be compiled using a _Device Tree Compiler_ that we call **DTS**. This is one kind of the special compiler to convert this DTS file to the stream of bytes, we call this binary as **DTB**. So, the DTB is a stream of bytes contain encoded details of the hardware, which is derived from DTS compilation.    
     
<img src="images/dtb.png" alt="DTB">				 

Hence there will be one DTB for every board and when you edit that DTS file to add a new entry. You need not to compile the kernel again and again, you just need to compile the DTS file and get the new DTB. Finally when the kernel boots, you should tell the kernel where this DTB resides in the memory, so that the Linux kernel can load that DTB file and extract all the hardware details of the board.     
     
<img src="images/dtb_to_load.png" alt="DTB to load by telling Linux kernel beforehand its location in memory">			


# uEnv.txt file   

Open the minicom, reset the board. Board will boot from eMMC. **Now halt it at the U-Boot by keeping the Space key pressed and then press S3 (power button)**. 

Type the command `help` on the U-Boot command prompt and the U-Boot will list out all the commands which is supported by this version of the U-Boot.   
    
<img src="images/uboot_help.png" alt="uboot help command">		

For example, if I want to know about how sleep works, I just have to type `U-Boot# help sleep` and it will give you the small documentation.

The U-boot actually depends on the various environmental variables, which is used during the development of the U-Boot project. There is a command called `printenv` which shows you all the environmental variables along with its values (i.e. `U-Boot# printenv`). If you want to, for instance, know the environment variable `soc` then you can type `U-Boot# printenv soc`  
    
**Similar to linux environment variables, u-boot also has set of standard as well as user defined environmental variables which can be used to override or change the behaviour of the uboot**   

You can add your own environmental variables (by `setenv`) and also change their values. For example to create an environmental variable `serverip` we type the following `U-Boot# setenv serverip 192.168.27.1`   
    
You can also store the multiple u-boot commands as a value in the env variables (i.e. `bootcmd`).		
    
You can even execute all the commands stored in the env variable in one go. Use the command `run name_of_env_variable`		

**Let's create our own environmental variable which is having a command as a value**.   
    
Let's say `U-Boot# mmc rescan` which will scan for the MMC device and `U-Boot# mmc list` which list out all the supported mmc interfaces on your board (MMC0 and MMC1 is currently available which is connection to the SD card and MMC1 is a interface where our eMMC is connected).   
    
Create environmental variable by using the command `setenv`.    
     
```
U-Boot# setenv my_mmc_list 'mmc list'
U-Boot# printenv my_mmc_list
my_mmc_list=mmc list
U-Boot# run my_mmc_list
OMAP SD/MMC: 0
OMAP SD/MMC: 1
```    
    
**uEnv.txt file is collections of various env variables which are initialised to number of uboot commands and primarily use to automate the command execution.**    
    
Command `boot` will boot the linux kernel. Ultimately give you the login screen.	

**U-boot always try to read the uEnv.txt from the boot source, if uEnv.txt not found, it will use the default value of the env varaibles.**  
**If you don't want u-boot to use default values, enforce new values using uEnv.txt**		
    
<img src="images/load_cmd.png" alt="Load command">		
    
<img src="images/load_cmd2.png" alt="Load command">		

Lets load the linux binary image `uImage` from the second partition of the on-board eMMC memory in to the DDR using `load` command as shown above, where **<interface>** as mmc, <dev[:part]> as 1:2 (dev is 1 and partition is 2), <addr> as 0x82000000, <filename> as /boot/uImage and size[bytes [pos]] we don't know so we ignore this. This will load the Kernel image into DDR memory at address 0x82000000 and we wil then **boot from memory** with `bootm`	(It will not boot the Kernal yet as to boot successfully we also need to provide the dtb file which Boot Stap Load couldn't find)  
     
```
U-Boot# load mmc 1:2 0x82000000 /boot/uImage
4385024 bytes read in 749 ms (5.6 MiB/s)

U-Boot# bootm 0x82000000
```		
     
> [!INFO]     
> **MMC1 interface** -> eMMC (Interface(dev) number 1)	
> **MMC0 interface** -> MicroSD (Interface(dev) number 0)		

**This time we will boot with the dtb file**

```
U-Boot# load mmc 1:2 0x82000000 /boot/uImage
U-Boot# load mmc 1:2 0x88000000 /boot/am335x-boneblack.dtb
U-Boot# bootm 0x82000000 - 0x88000000
```		
    
We will NOT see the logs, confirming either boot was successfull or not **As the kernel has no idea, which serial port of the board is used for sending the boot logs.**  
**The BBB uses UART0 as the serial debug terminal, which is enumerated as /dev/ttyO0 by the serial driver.**		
      
Therefore you have to pass some arguments that we call as Boot arguments (i.e. `U-Boot# printenv bootargs` if not found yu have to create the `bootargs`) from U-Boot to Linux kernel, instructing it to print all your debug messages on to the console ttyS2, ttyO0 (UART0 is enumurated as ttyO0) or ttyusb, etc.		

Since `bootargs` are not defined hence we need to define it first and once again follow the process of loading uImage, dtb and bootm (booting from memory DDR):  

```
U-Boot# setenv bootargs console=ttyO0,115200
U-Boot# load mmc 1:2 0x82000000 /boot/uImage
U-Boot# load mmc 1:2 0x88000000 /boot/am335x-boneblack.dtb
U-Boot# bootm 0x82000000 - 0x88000000
```    
     
**The boot will failed again as linux has no idea from exactly it should mount the filesystem. Therefore you have to send the location and type of file system using `bootargs`. Let's mount the file system which is present at the partition 2 of the MicoSD card**  
    
<img src="images/mmcblk0p2.png" alt="File system">				

```
U-Boot# setenv bootargs console=ttyO0,115200 root=/dev/mmcblk0p2 rw
U-Boot# load mmc 1:2 0x82000000 /boot/uImage
U-Boot# load mmc 1:2 0x88000000 /boot/am335x-boneblack.dtb
U-Boot# bootm 0x82000000 - 0x88000000
```    		 

You have now successfully booted and login with username `root` and password none
      

# Writing uEnv.txt file from scratch    
    
We will automate the steps done in previous section by creating a file called `uEnv.txt`.   
We go into U-Boot once again by pressing the Space key and powering up the board by pressing the S3 button.   

We have to download the uEnv.txt file which we will write and tranfer (using some Transfer protocol x-modem, minicom also provies you with lots of protocol like x-modem, y-modem, z-modem etc) from our PC to the board using commands like loadx, loady and loadz	   

<img src="images/serial_port_protocol_cmd.png" alt="Serial port transfer protocol commands">		

> [!NOTE]
> Type `loady` in the U-Boot prompt and then press `Ctrl+A` once and then type 's' select `ymodem` (as we are using `loady` command), hit **double** Space to tap into the directory where `uEnv.txt` file is located and finally **single** Space to select the `uEnv.txt` file. **Any environment variable in the uEnv.txt file end with carriage return i.e. hit enter at the end of any environment variable for uEnv.txt to work properly**    

`loady` command will only download the uEnv.txt file. To import the environmental variables into U-Boot shell you have to type `U-Boot# env import -t <memory addr> <size in bytes>` and we will create one custom command `mypcip` in uEnv.txt followed by carraige return as **mypcip=setenv serverip 192.168.1.2**   
     
```
U-Boot# env import -t 0x80200000 38
U-Boot# run mypcip
U-Boot# printenv mypcip
```		 
    
Write another command **ipaddr=192.168.27.1** in uEnv.txt file and test it by downloading with `loady` command into U-Boot and importing as follows:  
     
```
U-Boot# env import -t 0x80200000 56
U-Boot# run ipaddr
U-Boot# printenv ipaddr
```	

As when we run `boot` command in the `U-Boot` shell it runs `bootcmd` in turn. Therefore we will create one `bootcmd` in the uEnv.txt file along with `bootargs` as follows:    

```
bootargs=console=ttyO0,115200 root=/dev/mmcblk0p2 rw
bootcmd=echo"************Booting from memory*************;load mmc 1:2 0x82000000 /boot/uImage;load mmc 1:2 0x88000000 /boot/am335x-boneblack.dtb;bootm 0x82000000 - 0x88000000;
```

And once again download the uEnv.txt file and import it in U-Boot shell as follows:    

```
U-Boot# env import -t 0x80200000 290
U-Boot# printenv bootargs
U-Boot# printenv                 # There you will find `bootcmd`
U-Boot# boot
```											
				

# Booting BBB over Serial port    

1. Don’t connect SD card to SD card connector of the BBB      
     
2. The board preferably powered using power adapter (recommended , watch next video to understand why )      
    
3. Use USB to TTL Serial converter hardware to connect BBB's UART0 serial pins to PC.	    

<img src="images/serial_boot.png" alt="Serial boot">	   

In the case of transfering boot images to the board over UART, we should use some protocols which can be Xmodem, Ymodem or Zmodem (These protocols can be used to transfer files from one device to another device over the serial port.)		 		  

<img src="images/protocol_for_serial_port.png" alt="Protocol for serial port">	  

<img src="images/pc_to_host_over_uart.png" alt="PC to host connection over UART">		   

We'll be using RAM based file system initRAMFS which is actually a CPIO archive of the root file system.		

**How Serial booting work?**    

First we have to make our board boots via UART peripheral.   

We have to boot exactly the same way how we used to boot via SD card, that is **press and hold the S2 button, then press and release the S3 button, and make sure that SD card is NOT inserted to the board**    

<img src="images/boot_uart_steps.png" alt="Boot steps for UART when S2 pressed">		

> [!NOTE]  
> As you can see on the above image as why we cannot use USB P4 connection with the BBB to PC as USB0 comes before UART0. Hence we need to power up the Board with External adapter. 		

<img src="images/errata_note.png" alt="Errata note">		 	 

> [!NOTE]   
> When you search for the Errata note then you will find that the system is delayed for up to 4.5 minutes before continuing to the next boot device, if an attempt to boot from the Ethernet fails for any reason and this applies to the USB boot (if it detects the USB cable and it couldn't obtain the boot images from the USB, then the chip will wait for 4.5 minutes)     
     
<img src="images/boot_sequence.png" alt="Boot sequence">	  

Go to TRM document of AM335x SOC under _26.1.8 Peripheral Booting_ section it says it can be booted either through EMAC, Ethernet using TFTP protocol, USB as well as USB. And under _26.1.8.5 UART Boot Procedure_ section it states the boot ROM code uses Xmodem client protocol to receive the boot images. **When you keep the board into UART boot mode, the ROM boot loader is waiting for the second stage boot loader that is the SPL image over xmodem protocol only. Once the SPL executes it also tries to get the third stage boot loader that uboot image over xmodem protocol and you should send the uboot image over xmodem protocol from the host**. Utilities like hyperterm, terateram, minicom can be used on the PC side to download the boot image to the board.		 
     
<img src="images/uart_boot_procedure.png" alt="UART boot procedure">		 
     
When u-boot executes you can use u-boot commands such as xmodem or ymodem to load rest of the images like linux kernel image, DTB, initramfs in to the DDR memory of the board at recommend addresses (as shown below).    

<img src="images/recommended_addresses.png" alt="Recommended Load Addresses">

<img src="images/summary_uart_booting.png" alt="Summar of UART booting procedure">	  

> [!IMPORTANT]      
> If you are facing issues with uboot boot after downloading it through XMODEM, then please refer to these threads where TI Software team suggests to use YMODEM protocol to download the uboot image instead of XMODEM, [Link1](https://e2e.ti.com/support/arm/sitara_arm/f/791/t/646278?AM3358-UART-boot-mode) [Link2](http://processors.wiki.ti.com/index.php/AM335x_U-Boot_User%27s_Guide#Boot_Over_UART)    

## initramfs   

The word "initramfs" is made up of three words "initial" "RAM based" "file system"

This is a file system hierarchy, made to live in the RAM of the device by compressing it (we use compression because RAM is precious, we cannot use whole RAM just to store the FS) and during booting, Linux mounts this file system as the initial file system.  That means you just need RAM to mount the FS and get going with the complete boot Process. 			

**Does that mean usage of initramfs is compulsory? Used everywhere, every time ?**

 No, not necessarily. Using initramfs is optional.

**So, why do we need initramfs ?**

 Let’s understand this with an example. 

Let’s say you have a product and your product has USB interfaces, mass storage devices like SD card and let’s say you also have networking peripherals like Ethernet and also display. 

Now, to operate this wide range of peripherals, all the device drivers must be in place right?

That means all the drivers must be loaded in to the kernel space.

And along with the drivers, some peripherals may require the firmware binaries to operate. 

One idea is make sure that all those drivers are **built in** in to the kernel, that’s not a great idea because that makes your Linux kernel specific to your product and it will drastically increase the Linux kernel image size. 

Another good way is, you come up with the minimal file system, where you store all your drivers and firmware, and load that FS in to the RAM and ask the Linux to mount that file system during boot( Thanks to kernel boot arguments , you can use the kernel boot arguments to indicate kernel that your FS resides in RAM )

When the kernel mounts that file system from RAM, it loads all the required drivers for your product and all the peripherals of your product are ready to operate, because the drivers are in place. 

after That you can even get rid of this RAM based file system and use (switch to) some other advanced file system which resides on your other memory devices like eMMC/SD card or even you can mount from the network. 

**So, basically initramfs embedded into the kernel and loaded at an early stage of the boot process**, where it gives all the minimal requirements to boot the Linux kernel successfully on the board just from RAM without worrying about other peripherals. And what you should store in initramfs is left to your product requirements, you may store all the important drivers and firmware, you may keep your product specific scripts, early graphic display logos, etc. 

**How to keep initramfs in to RAM?**

 There are 2 ways, 

1) You can make initramfs “built in” in to the Linux Kernel during compilation ( i will show you later in this course) , so when the Linux starts booting , it will place the initramfs in the RAM and mounts as the initial root file system and continues.

2) You can load the initramfs from some other sources in to the RAM of your board and tell the Linux Kernel about it (that is , at  what RAM address initramfs is present ) via the kernel boot arguments. 

We will see both methods in this course as we make a progress!

**How to generate the innitramfs ?**

Follow these steps to generate the initramfs

Reproduce these steps at your desk, because we are going to use the generated initramfs  in our course as we move along. 

**Step 1: Download and extract** the [root file system](am335x_tiny_filesystem.zip) which is taken from TI software SDK			 			  

<img src="images/tiny_filesystem_am335x.png" alt="Tiny file system">	   
     
**Step 2: Get in to the extracted folder and run the below 2 commands from the “terminal”**	    
      
```
$ find . | cpio -H newc -o > ../initramfs.cpio

$ cat ../initramfs.cpio | gzip > ../initramfs.gz
```    
    
In the first command we are generating a **cpio** archive and then **gz** archive.		
     
<img src="images/initramfs_gz.png" alt="initrafs.gz">	 		 
     
You will end up with the file **initramfs.gz** which is about 3MB. 	  

**STEP 3: install mkImage command**

For that run `apt-get install u-boot-tools` on your terminal software, this will install all the u-boot related tools along with **mkImage** tool.

`$ apt-get install u-boot-tools`

**STEP 4: Make our initramfs , uboot friendly by attaching the uboot header with load  address and other info**

Run the below command.    
      
`$ mkimage -A arm -O Linux -T ramdisk -C none -a 0x80800000 -n "Root Filesystem" -d ../initramfs.gz  ../initramfs`	   

<img src="images/step4_initramfs.png" alt="initrafs.gz">	   

Great now you will end up with a file **initramfs** which also includes the **uboot header** and this file we will be used as ram based file system whenever required. 		 
       
			  
## Testing Serial Boot   

<img src="images/testing_serial_boot.png" alt="Testing serial boot">	 

We will download all the above images through UART. Now, open the minicom and **put the board in to UART boot mode by pressing and hodling the boot button (S2) and then press and release the power button (S3). make sure nothing is connected on the P4 USB and rather user 5V power supply as well as UART connection**   
     
> [!NOTE]   
> The characters `CCCCCCCC` will be emitted by ROM code of the SOC as soon it goes to UART boot mode(indicating it's waiting to grab the SPL via the UART. if you don't see characters `CCCCCC`, then the board is not in to UART boot mode.)		 
     
**1. Send u-boot-spl.bin**		 
Let's transfer first boot image i.e. SPL also called as Second Stage boot loader i.e. xmodem, ymodem, zmodem, kermit

To invoke x/y/zmodem from minicom press the `Ctrl+A` then `s` and then keep the cursor in front of the folder you wish to enter and then press Space key twice. Now keep cursor on `u-boot-spl.bin` press the space key to select and press enter. Look for `u-boot-spl.bin` in the repository [pre-built-images/serial-boot](prebuilt_images/serial-boot)   
    
> [!INFO]     
> If any stage of the UART transfer timeout occurs then put it back into UART boot mode by pressing the boot (S2) button and then Power button (S3).			

**2. Send u-boot.img**				

Similarly follow the same steps as above to send the `u-boot.img` at [pre-built-images/serial-boot](prebuilt_images/serial-boot) directory through minicom  over UART however choose zmodem if x and y doesn't work.  
    
Now press the SPACR bar to halt at U-Boot, Now let's download the Linux image. You can use the U-Boot (loadx command) to download the Linux image from your host PC into the beaglebone hardware again by using xmodem or ymodem protocol. Following is the recommended addresses at which we have to download the kernel image    
     
<img src="images/recommended_addresses.png" alt="Recommended Load Addresses">	   
      
**3. Send uImage**    
     
```
=> loadx 0x82000000   
```	 	 
    
Using loadx (via xmodem) download the binary image (kernel image) or any file using x-modem protocol at the location `0x82000000` on the DDR (that means if you cut off the power of the board then image will be vanished and you have to startover from step 1 i.e. Send u-boot-spl.bin)    

Now repeat the same steps of pressing the `Ctrl+A` then `s` and so on, finally choose the `uImage` file from [pre-built-images/serial-boot](prebuilt_images/serial-boot) directory.     
      
**4. Send DTB**    
     
```
=> loadx 0x88000000   
```	    

`Ctrl+A` then `s` and so on, finally choose the DTB file `am335x-boneblack.dtb` from [pre-built-images/serial-boot](prebuilt_images/serial-boot) directory. 		 
      
**5. Send initramfs**    
     
```
=> loadx 0x88080000   
```	    

`Ctrl+A` then `s` and so on, finally choose the file `initramfs` from [pre-built-images/serial-boot](prebuilt_images/serial-boot) directory. 		 
    
So far we sent 5 files into the BeagleBone Board as shown below   

<img src="images/5files_into_bbb.png" alt="Trasnfered files into BBB so far">			       
    
**So, we downloaded the `u-boot-spl.bin` into the internal RAM of the SOC. But, we downloaded all the remaining files into the DDR memory of the board using the xmodem protocol**    

**6 boot the linux kernel**		  
     
Let's boot the Linux kernel however before booting, you have to tell the Linux kernel that we are using RAM based file system which is sitting at `0x88080000` location. Otherwise, the booting will not succeed because it will result in a kernel panic saying that it couldn't mount any file system, because Linux will try to mount the file system, whether it could be on NAND Flash, USB, or on the network based file system, so whatever.

Following boot arguments to tell the kernel to take the file system from the RAM based file system which is sitting at `0x88080000`    
    
<img src="images/linux_boot_args.png" alt="Linux boot args">			
<img src="images/bootm_linux_kernel.png" alt="Bootm linux kernel">		
     
```
=> setenv bootargs console=ttyO0,115200 root=/dev/ram0 rw initrd=0x88080000
=> bootm 0x82000000 0x88080000 0x88000000
```    
    
The Linux has booted successfully and you will see the login prompt (log in with username `root`) has come up and the logo appears, TI guys who created this file system for AM335x ebm    
    
<img src="images/ti_fs.png" alt="TI filesystem">		


# Booting BBB over TFTP protocol    
       
1. Power the board using either connecting to PC via USB cable or using DC adapter.     
2. Connect Ethernet port of the BBB hardware to PC's Ethernet port using Ethernet cable.     
3. We will also use SD card for this experiment.	   
      
TFTP stands for **Trivial File Transfer Protocol**, which can be used to transfer files between a TFTP server and a TFTP client.     
      
<img src="images/tft_server_client.png" alt="TFT Server Client">					
     
We will be connecting our Board (TFTP Client) to the Host PC (Ubuntu, TFTP Host) via the Ethernet cable.     
      
<img src="images/file_placement.png" alt="TFT Server Client">					
                 
In our boot scenario (as shown above), the Linux kernel image `uImage`, the `initramfs` and the Device tree binary `am335x-boneblack.dtb` will be present on the **Linux Host PC** at `/var/lib/tftpboot`. And we will keep the Second stage boot loader `SPL`, `u-boot.img`, and `uEnv.txt` file in the **SD card**.      
      
The idea here is that;    
     
- First we boot the board via the SD card. Hence, the ROM code first fetches the SPL present on the SD card      
- And SPL in turn fetches and executes the U-Boot present on the SD card.       
- Then we will use U-Boot to fetch the Linux kernel `uImage`, `dtb` and the `initramfs` present on the TFTP server and place it on the DDR memory of the board at different memory addresses.     
- And after that, we will ask U-Boot to boot from address where the Linux kernel is present.

The reason why we use U-Boot is, it supports TFTP protocol and the TFTP commands. By using TFTP commands of the U-Boot, we can fetch any file from the TFTP server and place it on the DDR memory of the board. **Now to automate all these file transfers from the TFTP server, we should write all the commands in the uEnv.txt file**.   
      
<img src="images/workflow_tftp_protocol.png" alt="TFT protocol workflow">		   
               
<img src="images/summary_tftpboot.png" alt="Summary">						
      

**Preparing TFTP host, Setting up a TFTP server on Ubuntu host**     
      
- **Step 1**:  First on your Ubuntu host run the below command using your terminal program. Which will install the tftpd , xinetd(eXtended InterNET Daemon) . **tftpd** is a server for the Trivial File Transfer Protocol.    
`$ sudo apt-get install xinetd tftp tftpd`    
     
- **Step 2**: Create/Open the file “tftp” in the below directory `$ sudo vi /etc/xinetd.d/tftp` and put the below entry in to this file  and save it     
          
```
service tftp
{
protocol = udp
port = 69
socket_type = dgram
wait = yes
user = nobody
server = /usr/sbin/in.tftpd
server_args = /var/lib/tftpboot -s
disable = no
}
```    

- **Step3**: Create a folder `/var/lib/tftpboot` and execute below commands     
      
```			
$ sudo mkdir /var/lib/tftpboot
$ sudo chmod -R 777 /var/lib/tftpboot
$ sudo chown -R nobody /var/lib/tftpboot
```       
      
- **Step 4**: Restart the xinetd service. Now the xinetd daemon is running `$ sudo /etc/init.d/xinetd restart`		 

As previously said our PC is a TFTP server and Board is TFTP client, and make sure if the PC IP is set properly or not. Hence run ifconfig and if the Ethernet port name doesn't have `192.168.27.1` then you can create with `$ sudo ifconfig <port-name i.e. enp1s0>	192.168.27.1`	    
            
Now, go to our board and run the minicom `$ sudo minicom` and reset the board by pressing the power button (S3) and release and then press Enter to stop the auto booting. (We just want to boot from the eMMC. As we already have our MLO, U-Boot and the Kernel image there)      
       
Now, configure the `serverip` and `ipaddr` environment variables of the U-Boot with the proper value.		

```
=> setenv serverip 192.168.27.1
=> setenv ipaddr 192.168.27.2          # bbb ip address
=> ping 192.168.27.1
```		  

Now, use the TFTP command (i.e. `tftpboot`) to get the binary images. As we are already in the U-Boot. Hence we need not to load SPL and U-boot once again. Now our job is to load the Linux kernel image `uImage`, the device tree binary  `am335x-boneblack.dtb` and the `initramfs`.    
     
```
=> tftpboot 0x82000000 uImage
=> tftpboot 0x88000000 am335x-boneblack.dtb
=> tftpboot 0x88080000 initramfs
=> setenv bootargs console=ttyO0,115200 root=/dev/ram0 rw initrd=0x88080000
=> bootm 0x82000000 0x88080000 0x88000000
```		 
Now you can log in with the username `root`   
    
**Advantage of using TFTP boot**    

- Faster transfer of files from HOST PC to Development board (i.e. BBB)    
       
- During your development if you keep changing your boot binaries or file sytem, then **tftpboot** procedure will save lots of time related to transfer of those image files to the board for testing (You change something on kernel or root file system then recompile and then store somewhere probably on SD card, NAND Flash, or eMMC then you will boot, that is a tedious process, Hence **tftpboot will save you alot of time**)   
      
- You can automate tftpboot using uboot's uEnv.txt, that we will take up next    
     
Below you can see the terminals of the Host PC as well as BBB.     

<img src="images/pc_host_tftpboot.png" alt="PC Host Tftpboot">	   		 

Now, by using TFTP protocol you can transfer any file from a host PC to your beaglebone hardware. For example, let's create the file `helloworld` in the working directory (`BBB_workspace/prebuilt_images/tftp-boot`).  
     
> [!NOTE]
> Remember, whatever file you want to transfer, you have to keep in the folder `/var/lib/tftpboot/`. Because, the TFTP protocol will always look only for this folder from the host PC.		 
     
```
$ cd BBB_workspace/prebuilt_images/tftp-boot
$ echo "Hello, there world!" > helloworld
$ sudo cp helloworld /var/lib/tftpboot/
```		 

Now, let's go to our BeagleBone hardware. So, now here by using TFTP command you can pull the `helloworld` file from the Host PC (as shown below) `-r` means remote file.

<img src="images/bbb_hardware.png" alt="BBB hardware">	 

If at the BeagleBone side it says	`Network is unreachable` then you might as well configure the ip address for Ethernet port by first making sure with `ifconfig` and then setting it up with `$ ifconfig eth0 192.168.27.2`	 
     
**TFTP boot Conclusion**      

TFTP boot is a very handy way of booting when you need to recompile your kernel repeatedly and inserting removing the SD card from the board is a tedious process

       					
# U-boot    
    
**Understanding U-boot source tree**    

As previously seen the u-boot repo downloaded (`$ git clone https://source.denx.de/u-boot/u-boot.git` and [documentation](https://docs.u-boot.org/en/latest/build/source.html))     
     
Now we will look into this directory.	U-boot source code supports various architectures and ports (like ARM, powerpc, AVR, ARC in `arch` directory) and various boards like ti, intel, atmel etc. in `boards` directory.   
    
Under **ti** there are various folders for SOC like `am335x`, `panda`, and `ti814x` etc. and their board related files (i.e. `board.c`) inside respective SOC folder.    	

There are also various architecture for ARM inside `arch/arm/cpu` like arm11, armv8, and armv7 etc.	as we are using Cortex A8 which is based on arm7 architecture. **You will find one `start.S` file in armv7 `arch/arm/cpu/armv7/`**. This is the point where the ROM boot loader hands off control to the SPL (Second stage boot loader). It goes from CPU initialisation to SOC initialisation.		

<img src="images/arch_arm_cpu_amrv7_start_assembly_api.png" alt="Assembly API for SPL">	    
     
There's another interesting folder named `config` where you can find various configuration files of different ports (`u-boot/configs$ ls -1 | wc -l` approx. 1200), There you will any file ends with **defconfig** (default configuration)	is used when you have no idea how to configure the U-Boot source code for your board. As you may not know what are the features you need to enable or disable. (Consequently, basic and required functionalities of the U-Boot will be available on your board.)	   

You can list out various configuration files related to AM335 SOC by `$ ls -l am33`		  
    
In our case we will be using default configuration file for AM335 which named as `am335x_boneblack_defconfig`		 
     
**1. Cross tool-chain installation**      

We will cross-compile the U-Boot source code to generate the binaries of the U-Boot as well as binaries for SPL Second stage boot loader	 	-

1. Download [arm cross toolchain](https://releases.linaro.org/components/toolchain/binaries/7.5-2019.12/) for your Host machine (developed by Linaro)  **arm-linux-gnueabihf** where **hf** stands for hardfloat and look for **gcc-linaro-7.5.0-219.12-x86_64_arm-linux-gnueabihf.tar.xz**.    
      
2. export path of the cross compilation toolchain `export PATH=$PATH:/home/<username>/BBB_Workspace/Downloads/gcc-linaro-*-x86_64_arm-linux-gnueabihf/bin` in bashrc     
```
vi /home/<username>/.bashrc
source /home/<username>/.bashrc
```     
      
**2. U-Boot compilation** 			
     
1. **disclean** deletes all the previously compiled/generated object files, go to working directory (`$ cd ~/BBB_Workspace/Download/u-boot` and) run `make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-	distclean` (mentioning the prefix of the command till **-** consequently the command like (gcc, as, ld) will be added by the "Makefile")    
    
2. Apply board **default configuration** for uboot (alternative configuration to `am335x_evm_defconfig` could be found at `u-boot/configs`) and now run `make CROSS_COMPILE=arm-linux-gnueabihf- am335x_evm_defconfig` and you can check the config which will be written to `.config` in the `u-boot` folder    
      
3. Run **menuconfig**, if you want to do any settings other than default configuration (as done in previous step which was saved in `u-boot/.config` file).	`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menconfig`		
      
4. **Compilation**:
```bash    
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 # use j8 for 8 cores
```   
You will see it has created spl/u-boot-spl.bin and ran `MKIMAGE` on that file to create MLO (SPL + U-Boot header), and if you go to `u-boot/spl` you will find `u-boot-spl.bin` file there and `u-boot.img` in he u-boot directory  
<img src="images/make_cross_compile_arm.png" alt="Make cross compile ARM">	     
		 

      
# Understanding Linux source tree    
     
We'll learn the procedure to compile the Linux source code to generate the Linux kernel binary. Now download the Linux kernel source (`$ git clone --recursive https://github.com/beagleboard/linux`) and let's understand its source tree.     
     
<img src="images/linux_source_tree.png" alt="Linux source tree">		 

As the picture below shows the relationship between the **Processor**, **SOC** and the **Board or a Product**.     
     
<img src="images/board_.png" alt="Beaglebone Board">		 
     
Now, the source code to handle all these three components, are systematically arranged in the Linux kernel source tree at different directories.      
     
<img src="images/arch_specific_code.png" alt="Arch specific code">		 
     
Suppose, if you want to run Linux on ARM based devices, then `linux/arch/arm` is the directory to explore the processor, SOC and board specific details.     
      
The core ARM processor related codes like to handle the memory management unit of the processor, cache memories, or the exceptions of the processors etc. will go into these directories.   
     
<img src="images/arch_specific_code2.png" alt="Arch specific code">		
     
Code specific to the SOC will go into the following directory which has a prefix `mach`.     
     
<img src="images/arch_specific_code3.png" alt="Arch specific code">		
      
Basically every vendor of the SOC has their own machine `mach` directory to keep their SOC specific source codes needed to work with their respective SOCs. Strictly speaking, this machine `mach` specific directory `arch/arm/mach-*` has two parts. One is **Board** related and another one is **Machine (SOC) shared common code**.    
     
<img src="images/arch_specific_code4.png" alt="Arch specific code">
<img src="images/arch_specific_code5.png" alt="Arch specific code">					 
     
For example, the AM335x SOC belongs to Sitara family of SOCs by Texas Instruments. However, there is no directory called Machine Sitara in Linux, but there is a directory called Machine davinci. That's because, the davinci SOCs are for different market purpose (targeted for video applications). Hence the peripheral IPs are entirely different and they need different codes to handle them.     
     
<img src="images/arch_specific_code6.png" alt="Arch specific code">			 

In the case of AM335x vs OMAP 2/3/4/5, even though the SOC belongs to a different family than OMAP, most of the peripheral IPs are exactly same as OMAP2/3/4 family of SOCs. Hence they still refer to machine OMAP2 directory for AM335x.    
     
<img src="images/arch_specific_code7.png" alt="Arch specific code">    
      
Whereas machine OMAP1 `mach-omap1` contains all the SOC shared common code to handle peripherals of the SOCs which are based on OMAP1 family only.

**What are the important files you find in the machine OMAP2 directory?**   
    
You will find various C source files are related to different patterns which will help you to initialize various peripherals (SPI controller, I2C controller, highspeed MMC controller, clocking engine, GPIOs, serial ports etc), pin muxing, power management, clocking etc.    
     
<img src="images/arch_specific_code8.png" alt="Arch specific code"> 		 

And note that, you can even change these file, if required according to you Product Design. And you should also remember that these source files are actually common among all the SOCs which share the same IP as OMAP2 SOC.   
      
**ARM Board configuration files organisation**     
     
Below are the images of some old boards which also had associated board file in the main line Linux kernel source.		 
      
<img src="images/board_config_organisation.png" alt="Board config organisation"> 		  
<img src="images/board_config_organisation2.png" alt="Board config organisation">    
     
Every single board or a product was using their own board file to work with their hardware in the mainline Linux kernel source. Now this is no longer valid with the introduction of DTB.	 

After the introduction of device tree, you may not see separate board files for each new board or a product in the market.
For example, in the `arch/arm/mach-omap2` you see few board files and the newer kernel versions no longer hold board files related to each new board which comes with different variation of the SOC into the market.   

Now, let's open the `board-generic.c` in the `mach-omap2` directory. You won't see any initialisation functions and platform device additions except one omap generic init which is suitable for all the platforms. 

```c
static void __init __maybe_unused omap_generic_init(void)
{
	pdata_quirks_init(omap_dt_match_table);
	omap_soc_device_init();
}
```				 

Previously, board was tied to single platform i.e. You couldn't use Pandora board file for beagleboard black.		     
     
Let's say, you are using a board AM3517 SOC and when the Linux detects your DTB it will read the field called `.dt_compat` from the DTB, that means a DTB will also has a field called `.dt_compat` then it will run a comparison function, in which the Linux compares DTB's `.dt_compat` field with every machine registration. it will end up using `.dt_compat = am3157_boards_compat`.     
     
```c
static const char *const am3517_boards_compat[] __initconst = {
	"ti,am3517",
	NULL,
};

DT_MACHINE_START(AM3517_DT, "Generic AM3517 (Flattened Device Tree)")
	.reserve	= omap_reserve,
	.map_io		= omap3_map_io,
	.init_early	= am35xx_init_early,
	.init_machine	= omap_generic_init,
	.init_late	= omap3_init_late,
	.init_time	= omap_init_time_of,
	.dt_compat	= am3517_boards_compat,
	.restart	= omap3xxx_restart,
MACHINE_END
```		 
      
**SOC specific driver code organisation**     

Drivers related to various device can be found in the `linux/drivers` directory of the linux kernel and it is one of the biggest layer in the linux kernel and contains driver codes for various peripherals like, interfaces, memory controller, bus controller, networking devices, serial devices, serial convertors, USB devices, graphics, LCD crypto engines and related drivers etc.		 

Let's consider our system on chip AM335X SOC has all these following peripherals on chip (you can explore various peripherals in the TRM).    

<img src="images/soc_am335x_peripherals.png" alt="SOC Peripherals">    

Let's explore some of the path of Linux device drivers for various peripherals of this SOC. Driver for LCD controller and touchscreen controller for this SOC can be found in the path.
       
<img src="images/drivers1.png" alt="Drivers for various peripherals">  			
<img src="images/drivers2.png" alt="Drivers for various peripherals">    
    
Now, to enable the connection of the external memory like the NOR flash, the NAND flash, or the external SRAM. The chip has the General Purpose Memory Controller (GPMC).   
    
<img src="images/drivers3.png" alt="Drivers for various peripherals">  
<img src="images/drivers4.png" alt="Drivers for various peripherals"> 	
<img src="images/drivers5.png" alt="Drivers for various peripherals">     

if you want to locate any driver related to On chip Peripherals of a particular SOC, you just have to consult the drivers directory and it should be supporting a various drivers related to various peripherals of different SOC produced by different vendors.    
     
**Configuring and generating linux image**    
      
We will cross-compile our Linux source code to generate `uImage` binary.

1. First you have to download the official kernel, if you haven't done so, at `$ git clone https://github.com/beagleboard/linux` and run `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean`     
     
2. `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bb.org_defconfig`	use `omap2plus_defconfig` if `bb.org_defconfig` not found   

3. `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig`, we won't touch anything here just for learning purposes if you go to **Device Driver > SPI support** and change **User mode SPI device driver support** from **\*** (**y**) to **M** (**m**), **\*** means module will be compiled and included statically in image thus increasing the size of uImage whereas **M** means module is NOT compiled along with the kernel (also called dynamic loadable module). if you go to <Help> it will further tell you the entry name which in the case of **User mode SPI device driver support** is **CONFIG_SPI_SPIDEV:** and now you locate or confirm this entry in `linux/.config` file as `CONFIG_SPI_SPIDEV=m`. Alternatively if you want to change **M** (`m`) entry back to **y** (`*`) you have to go back to `menuconfig`  

4. `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- uImage dtbs LOADADDR=0x80008000 -j4`   

5. `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 modules` and it will create image at `arch/arm/boot/uImage`     
    
6. `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 modules` it will cross compile and generate loadable modules with `.ko` extension 		

7. `linux$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=<path of the RFS> modules_install` the `.ko` files should be transfered to the Root File system and this step is called **modules installation** which we done here. Do this step after `Busybox`.
    		 		 				 

# Busybox    
    
Busybox is a software tool, that enables you to create a cutomised root file system for your embedded linux products.	You can create from very basic to advanced file system according to your requirements by using busybox configuration utilities. 
     
> [!NOTE]    
> Previously, we have used ready made file systems from Angstrom and TI, Now let's create our own file system using a busybox tool.

**Advantages of using busybox tool**    
    
1. It enables you to create customised file system that meets your resource requirements.

2. If your product is a resource limited in terms of memory, then you can customise the file system such a way that, it can fit into your project with limited memory space.    
    
3. You can use this tool to remove all unwanted features which your product doesn't need, like you can remove unwanted Linux commands, features and directories, etc. using the customisation tool.    
    
4. Busybox has the potential to significantly reduce the memory consumed by various Linux commands by merging all the Linux commands into one single executable binary. 
    
Your Linux PC such as Ubuntu has around 350+ commands if you only consider the '/bin' and '/sbin' directories. There are more if you count /user/bin and /user/sbin directories.   
     
<img src="images/general_memory_consumption.png" alt="General memory consumption">   

<img src="images/busybox_executable_binary.png" alt="Busybox executable binary"> 			 
     
This single busybox binary is implemented like a big switch case of C programming, where each case is a Linux command like ls, rcp or ifconfig etc. When you execute this binary with standard Linux command name as an argument, the respective command's output will be achieved.    
    
**Busybox compilation**		
		   		 
1. Download [Busybox](https://busybox.net/downloads) any `bz2`, extract it and you will get the source code for all your Linux commands (separated in multiple folders).
     
<img src="images/busybox_downloaded_dir.png" alt="Busybox downloaded dir">		 
      
 For example, **coreutils** implements all the core utilities (like `chmod`, `cat`, `dd` etc). **miscutils** folder may contain the miscellaneous utilities. **modutils** may be consisting of the modules related commands (like `lsmode` used to list all the loadable modules present in the kernel, `modprobe`, and `depmod` etc) as well as **findutils** etc.     
      
2. 	Apply default configuration `busybox$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- defconfig`		  
     
3. Change default settings if required by `busybox$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig`. For now we want to build the busybox (All the Linux command source codes) in a static way by going in to **Settings >  Build Options (Build static binary (no shared libs))**. However it will increase the size . Later we will build BusyBox as a dynamic binary where we have to use shared libraries of the standard C. Now press space bar to toggle between selecting and deselecting. Next Save and Exit. And the new configuration is actually stored in the `.config` file

4. Generate the busybox binary and minimal file system `busybox$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- CONFIG_PREFIX=<install_path> install -j4`, Point the <install_path> to your workspace	(create `RFS_Static`)	 i.e. `CONFIG_PREFIX=/home/<username>/BBB_Workspace/RFS_Static`. The busybox has generated 3 major directories (`$ ls RFS_Static`) named **bin**, **sbin**, and **usr**. These 3 directories are sufficient to at least boot the Linux successfully.   
    
The default configuration generated around 93 commands (`RFS_Static/bin$ ls -1 | wc -l`) in the **bin** folder (Our Host PC Ubuntu has 1936 commands `ls -1 /bin/ | wc -l`). You ca use the `menuconfig` to increase or decrease these commands. Furthermore, **sbin** (`RFS_Static/sbin$ ls -1 | wc -l)	has 72 commands	(and our Host PC's sbin has 385 commands)

If you do `RF_Static/bin$ ls -l` inside **bin** then you will see these are not commands but softlinks (i.e. `cat -> busybox`), which are pointing to the BusyBox. Even in **sbin** `RF_Static/sbin$ ls -l` all the files pointing to Busybox (i.e. `sysctl -> ../bin/busybox`)	





     










 		  
         


   



    
     


   
    

      
    

   

  
   

   


  
   

   
  
   
    
   
   
    
  
 

