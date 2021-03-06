# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\repositories\embedded\trunk\terminalOutput\CE4920Project1\Design01.cydsn\Design01.cyprj
# Date: Tue, 03 Nov 2015 15:53:09 GMT
#set_units -time ns
create_clock -name {timer_clock_1(routed)} -period 100000 -waveform {0 50000} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {WaveDAC8_1_DacClk(routed)} -period 250000 -waveform {0 125000} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyXTAL} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {CapSense_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {timer_clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2401 4801} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {WaveDAC8_1_DacClk} -source [get_pins {ClockBlock/clk_sync}] -edges {1 6001 12001} [list [get_pins {ClockBlock/dclk_glb_2}]]

set_false_path -from [get_pins {__ZERO__/q}]

# Component constraints for C:\repositories\embedded\trunk\terminalOutput\CE4920Project1\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\repositories\embedded\trunk\terminalOutput\CE4920Project1\Design01.cydsn\Design01.cyprj
# Date: Tue, 03 Nov 2015 15:52:53 GMT
