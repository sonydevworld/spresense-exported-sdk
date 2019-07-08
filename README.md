# spresense-micropython

    $ git clone --recursive https://github.com/sonydevworld/spresense.git
    $ cd spresense/sdk
    $ tools/config.py --kernel release
    $ tools/config.py board/spresense feature/asmp feature/audio_player feature/audio_recorder feature/cmsis feature/dnnrt feature/gnss feature/imageproc feature/step_counter device/adc device/camera device/charger device/pwm device/sdcard
    $ make menuconfig

  │ CONFIG_DNN_RT_MP:                                                       │  
  │                                                                         │  
  │ Enable or disable multicore processing.                                 │  
  │                                                                         │  
  │ Symbol: DNN_RT_MP [=y]                                                  │  
  │ Type  : boolean                                                         │  
  │ Prompt: Use multicore processing                                        │  
  │   Location:                                                             │  
  │     -> DNN runtime library                                              │  
  │       -> DNN runtime library (DNN_RT [=y])                              │  
  │   Defined at modules/dnnrt/Kconfig:16                                   │  
  │   Depends on: DNN_RT [=y]  

  | CONFIG_NSH_BUILTIN_APPS:                                                │  
  │                                                                         │  
  │ Support external registered, "built-in" applications that can be        │  
  │ executed from the NSH command line (see apps/README.txt for             │  
  │ more information).  This options requires support for builtin           │  
  │ applications (BUILTIN).                                                 │  
  │                                                                         │  
  │ Symbol: NSH_BUILTIN_APPS [=n]                                           │  
  │ Type  : boolean                                                         │  
  │ Prompt: Enable built-in applications                                    │  
  │   Location:                                                             │  
  │     -> System tools                                                     │  
  │       -> NSH Library                                                    │  
  │         -> NSH Library (NSH_LIBRARY [=y])                               │  
  │   Defined at /home/CORPUSERS/88882248/test_spresense_sdk/spresense/sdk/ │  
  │   Depends on: NSH_LIBRARY [=y]  

    $ make buildkernel
    $ make
    $ make export

    $ unzip sdk-export.zip
    $ mv sdk-export spresense-sdk
    $ cd spresense-sdk

    $ mv nuttx/include/arch/chip/cxd56_adc.h nuttx/include/arch/chip/adc.h
    $ mv nuttx/include/arch/chip/cxd56_audio.h nuttx/include/arch/chip/audio.h
    $ mv nuttx/include/arch/chip/cxd56_scu.h nuttx/include/arch/chip/scu.h
    $ mv nuttx/include/arch/chip/cxd56_uart0.h nuttx/include/arch/chip/uart0.h