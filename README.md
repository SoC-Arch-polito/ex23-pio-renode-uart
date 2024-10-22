# Simple demo for the usage of platformio and renode

This simple demo shows how to use platformio and renode to develop a simple **zephyr** application.

The target is the **STM32F0 discovery**.


3 environments are created:
 - One for renode upload
 - One for renode debug
 - One for the real hardware upload and debug


# Zephyr version.
The example has two releases.
 - V1.0.0 which supports version 2.7 of zephyr.
 - V2.0.0 which supports version 3.4 of zephyr.

I suggest to use the version V2.0.0

The example is inspired by this [zephyr post](https://www.zephyrproject.org/developing-zephyr-rtos-embedded-applications-on-platformio-and-simulating-on-antmicro-renode/), for the version V1.0.0, which supports the version 2.7 of zephyr. It has then been adapted to support version 3.4 of zephyr.


## STM32F0 and renode

For the renode env, you need to download the platform description from [renodepedia](https://zephyr-dashboard.renode.io/stm32f0_disco-hello_world/stm32f0_disco-hello_world.repl) as renode does not officially support this platform. Keep in mind the repl at the link is valid for the zephyr framework only.

Then create a simple script, as renode does not provide a script for this platform. Platform and script files are provided in this repo. Copy them to the corresponding renode path:

```bash
/opt/renode/platforms/boards/
/opt/renode/scripts/single-node/
```

The application simply reads lines from an UART, and echo the lines back to the user with some additional info.

As the usart1 is not connected by default on the real hardware of the stm32f0disco board, we are using usart2. To make zephyr use usart2 as the console and shell-uart, we use a dts overlay. See file `./zephyr/dts_overlay.dts` and `./zephyr/CMkaeList.txt`

For testing purposes, the app opens an analyzer for the uart, and creates a socket in the port **3456**. From the host it is possible to access the uart by connecting to the port with:



```bash
$ telnet localhost 3456
```
