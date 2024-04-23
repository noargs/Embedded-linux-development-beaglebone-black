- Run command `$ java -version` in your terminal to see if Java is installed (in this case, it will output the Java version, otherwise error "Command not found") or install Java.   
    
- Download [Eclipse for C/C++](https://www.eclipse.org/downloads/packages/release/2024-03/r/eclipse-ide-cc-developers)      
    
- Download [Linaro toolchain](https://releases.linaro.org/components/toolchain/binaries/), if on **Windows** then choose with following details **gcc-linaro-VERSION-i686-mingw32_arm-linux-gnueabihf.tar.xz**, And extract in the folder (suppose following folder you chose **C:\toolchains\gcc-linaro-7.5.0-2019.12-i686-mingw32_arm-linux-gnueabihf**)    
      
- Download and install [make](https://gnuwin32.sourceforge.net/downlinks/make.php) for Windows      
     
- Now go to Eclipse IDE's **File** > **Project** and click **C/C++** to expand and select **C Project** and click **Next**, Type **Poject name** (i.e. `00_test`) and click **Executable** to expand and choose `Hello World ANSI C Project` and on the next Window **Cross GCC** and click **Next**, Type **Author** your name and leave everything as it is and click **Next**. Go to **Advanced settings**, click **C/C++ Build** to expand and then click **Environment**. There you have to provide the _PATH_ for Linaro toolchain which **;** seperated list (**;C:\toolchains\gcc-linaro-7.5.0-2019.12-i686-mingw32_arm-linux-gnueabihf\bin;**)    
    
You also have to go to the place where **make** for Windows was installed (**GnuWin32** directory) and go into **bin** folder and copy `libiconv2.dll`, `libintl3.dll`, and `make.exe` and paste it into **bin** folder of **gcc-linaro-7.5.0-2019.12-i686-mingw32_arm-linux-gnueabihf**      


**Installing Remote System Explorer and Testing Application**    

Now we have to transfer the binary to the Beaglebone hardware using something called the **Remote System Explorer** (actually an eclipse perspective). It allows you to connect, work with a variety of remote systems.     
     
let's go to **help** and click on **Install new software** and in **Work with:** choose _All Available Sites_ from the dropdown. You will see the Lists appear after sometime. There find and select **Mobile and Device Development** (Under this section among other you will see an entry for _TM Terminal View Remote System Explorer add-in_. Just click **Next** and **Accept the Terms and conditions** when it installed completely, Restart your eclipse.

Now go to **Window** > **Show View** > **Other**, expand the **Remote Systems** and then select **Remote System** and then click on **Open**.    
     
<img src="images/remote_system_connection_button.png" alt="Remote system connection button">	     
     
Click the button as shown above and select _SSH only_ click Next, leave **Parent profile** as it is, **Host name** as _192.168.7.2_ and connection name _BBB_ click Next twice and then Finish. _Connect your BBB to PC now via the mini USB cable. No need to connect Ethernet cable_
        
Just power on your beaglebone hardware and give the power over the USB cable and when you reset the board, it will boot the debian image from the eMMC memory.(open Tera Term and the serial port before reseting your board)





