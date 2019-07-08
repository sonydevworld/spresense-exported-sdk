# Spresense exported SDK

Prepared and exported Spresense SDK. To reproduce this, follow the steps below.

## Step 1 - Clone Spresense SDK

    $ git clone --recursive https://github.com/sonydevworld/spresense.git
    $ cd spresense/sdk

## Step 2 - Configure Spresense SDK

Configure NuttX:

    $ tools/config.py --kernel release

Configure more with menuconfigkernel:

    $ make menuconfigkernel

Select:

* `CONFIG_SYSTEMTICK_HOOK`

Set:

* `CONFIG_USEC_PER_TICK`=1000

Configure sdk:

    $ tools/config.py board/spresense feature/cmsis feature/dnnrt feature/gnss \
    feature/imageproc device/adc device/camera device/charger device/pwm device/sdcard

Configure more with menuconfig:

    $ make menuconfig

Deselect:

* `CONFIG_NSH_BUILTIN_APPS`

* `CONFIG_CXD56_SFC`

## Step 3 - Modify Spresense SDK

In file `nuttx/include/nuttx/compiler.h` (line 81) change

    #if __cplusplus >= 201402L

to

    #if defined(__cplusplus) && __cplusplus >= 201402L

In file `sdk/bsp/board/spresense/src/spresense_main.c` add function

    void weak_function board_timerhook(void)
    {
    }

## Step 4 - Build and export Spresense SDK

    $ make buildkernel
    $ make
    $ make export

## Step 5 - Extract Spresense SDK and change the name of the folder

    $ unzip sdk-export.zip
    $ mv sdk-export spresense-sdk

## Step 6 - Rename files to be compatible with the NuttX repository

    $ cd spresense-sdk
    $ mv nuttx/include/arch/chip/cxd56_adc.h nuttx/include/arch/chip/adc.h
    $ mv nuttx/include/arch/chip/cxd56_audio.h nuttx/include/arch/chip/audio.h
    $ mv nuttx/include/arch/chip/cxd56_scu.h nuttx/include/arch/chip/scu.h
    $ mv nuttx/include/arch/chip/cxd56_uart0.h nuttx/include/arch/chip/uart0.h
