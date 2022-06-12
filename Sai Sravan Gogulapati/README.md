===== CALIT2 firmware Reaserch ======


Author:
Sai Sravan Gogulapati

Affiliated with University of California Irvine

Date: 06/13/2022

===============================================================================

The above projects above are as follows:
 - The example project from esp32-camera that grabs the frame buffer and prints its size
 - An extension of the esp-idf's UDP client example that sends packets to a given IP address
 - A combination of the above projects which grabs the frame buffer and sends it over wifi

Building:

The above files projects are built using ESP-IDF.

For the esp-cam projects to work, follow these instructions to install the esp32-camera component:
https://github.com/espressif/esp32-camera#using-esp-idf

Since only the main files of each project are included in this repository, I suggest starting 
with an example project and replacing the main folder with one from this repository.
An example project can be created this way:
```
cd %userprofile%\esp
xcopy /e /i %IDF_PATH%\examples\get-started\hello_world hello_world
```

You can copy this esp32-cam example as the starting point: https://github.com/espressif/esp32-camera/tree/master/examples
If capturing the frame buffer is resulting in an error, try going to `idf.py menuconfig` and enabling 
Component config -> ESP32-specific -> Support for external, SPI-connected RAM.

The udp_client_and_camera project includes an sdkconfig file. Replace the example project's sdkconfig with this one.
Before building the udp_client_and_camera project, go to `idf.py menuconfig` and set the 
Example Configuration's WiFi SSID and WiFi Password fields.
The IP address and port of the UDP server are specified in the code itself.

What you use as the UDP server server is up to you. I used a software called USR-TCP232, which you can download 
from this website: https://www.pusr.com/products/1-port-rs232-to-ethernet-converters-usr-tcp232-302.html
The software acts as a UDP server.
I also wrote python scripts that act as UDP servers for testing purposes.
The scripts I wrote are very similar to what is described here: 
https://pythontic.com/modules/socket/udp-client-server-example
