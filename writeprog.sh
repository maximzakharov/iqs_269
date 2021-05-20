#!/bin/bash

STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -w build/band_fw.hex

STM32_Programmer_CLI -c port=SWD -run