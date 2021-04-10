# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\PSoC\Projects\Stepper_Ctrl\Design01.cydsn\Design01.cyprj
# Date: Sat, 10 Apr 2021 09:06:56 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ck_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for D:\PSoC\Projects\Stepper_Ctrl\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: D:\PSoC\Projects\Stepper_Ctrl\Design01.cydsn\Design01.cyprj
# Date: Sat, 10 Apr 2021 09:06:51 GMT
