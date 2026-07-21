# ESP32C3-mini Collatz conjecture experiment

I wasn't thinking when I named this codebase. This base will be a node.
This is so I can create the first controller on a PC

The idea is to have a cluster of these really cheap ESP32-C3-minis to
nothing but find Collatz conjecture largest stopping time.

Starting setup for the Controller.

1. Have a ESP32 act as the AP and respond to requests for next blocks.
2. Have the ESP32 accept pushes of largest stopping times from the block assigned.
3. Sort stopping times removing the ones that are not optimum.

Starting setup for the Node.

1. Connect to the Controller AP.
2. Request a block.
3. Process block.
4. When finished send steps to the Controller.
5. ***Or*** take steps as they are found to simplify the API.

This project was created and maintained using PlatformIO.
