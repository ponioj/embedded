// ======================================================================
// Design01.v generated from TopDesign.cysch
// 11/03/2015 at 09:56
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_GEN4 2
`define CYDEV_CHIP_REV_GEN4_PRODUCTION 17
`define CYDEV_CHIP_REV_GEN4_ES 17
`define CYDEV_CHIP_REV_GEN4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PANTHER 5
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4D 3
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 4
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 5
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 6
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 7
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_MEMBER_4F 8
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_MEMBER_4M 9
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 10
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 11
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5B 12
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 13
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 12
`define CYDEV_CHIP_REVISION_USED 0
// CharLCD_v2_10(ConversionRoutines=true, CUSTOM0="0,E,8,8,8,E,0,0,", CUSTOM1="0,A,A,4,4,4,0,0,", CUSTOM2="0,E,A,E,8,8,0,0,", CUSTOM3="0,E,A,C,A,A,0,0,", CUSTOM4="0,E,8,C,8,E,0,0,", CUSTOM5="0,E,8,E,2,E,0,0,", CUSTOM6="0,E,8,E,2,E,0,0,", CUSTOM7="0,4,4,4,0,4,0,0,", CustomCharacterSet=1, TypeReplacementString=uint8, CY_COMPONENT_NAME=CharLCD_v2_10, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LCD, CY_INSTANCE_SHORT_NAME=LCD, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=LCD, )
module CharLCD_v2_10_0 ;



	wire [6:0] tmpOE__LCDPort_net;
	wire [6:0] tmpFB_6__LCDPort_net;
	wire [6:0] tmpIO_6__LCDPort_net;
	wire [0:0] tmpINTERRUPT_0__LCDPort_net;
	electrical [0:0] tmpSIOVREF__LCDPort_net;

	cy_psoc3_pins_v1_10
		#(.id("6ea6d78a-8e9e-4562-997b-572b4c437c72/ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(21'b110_110_110_110_110_110_110),
		  .ibuf_enabled(7'b1_1_1_1_1_1_1),
		  .init_dr_st(7'b0_0_0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(7'b1_1_1_1_1_1_1),
		  .input_sync_mode(7'b0_0_0_0_0_0_0),
		  .intr_mode(14'b00_00_00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(",,,,,,"),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(7'b0_0_0_0_0_0_0),
		  .oe_reset(0),
		  .oe_sync(7'b0_0_0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(7'b0_0_0_0_0_0_0),
		  .output_conn(7'b0_0_0_0_0_0_0),
		  .output_mode(7'b0_0_0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(7'b0_0_0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,,,"),
		  .pin_mode("OOOOOOO"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(7'b1_1_1_1_1_1_1),
		  .sio_ibuf(""),
		  .sio_info(14'b00_00_00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(7'b0_0_0_0_0_0_0),
		  .spanning(0),
		  .use_annotation(7'b0_0_0_0_0_0_0),
		  .vtrip(14'b10_10_10_10_10_10_10),
		  .width(7),
		  .ovt_hyst_trim(7'b0_0_0_0_0_0_0),
		  .ovt_needed(7'b0_0_0_0_0_0_0),
		  .ovt_slew_control(14'b00_00_00_00_00_00_00),
		  .input_buffer_sel(14'b00_00_00_00_00_00_00))
		LCDPort
		 (.oe(tmpOE__LCDPort_net),
		  .y({7'b0}),
		  .fb({tmpFB_6__LCDPort_net[6:0]}),
		  .io({tmpIO_6__LCDPort_net[6:0]}),
		  .siovref(tmpSIOVREF__LCDPort_net),
		  .interrupt({tmpINTERRUPT_0__LCDPort_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LCDPort_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{7'b1111111} : {7'b1111111};



endmodule

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// PGA_v2_0(Gain=6, Power=3, VddaValue=5, Vref_Input=0, CY_COMPONENT_NAME=PGA_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PGA_1, CY_INSTANCE_SHORT_NAME=PGA_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=PGA_1, )
module PGA_v2_0_1 (
    Vin,
    Vref,
    Vout);
    inout       Vin;
    electrical  Vin;
    inout       Vref;
    electrical  Vref;
    inout       Vout;
    electrical  Vout;


    electrical  Net_75;
          wire  Net_41;
          wire  Net_40;
    electrical  Net_17;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;

    cy_psoc3_scblock_v1_0 SC (
        .vin(Vin),
        .vref(Net_17),
        .vout(Vout),
        .modout_sync(Net_41),
        .aclk(Net_37),
        .clk_udb(Net_38),
        .dyn_cntl(Net_39),
        .bst_clk(Net_40));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_37));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_38));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_39));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_40));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_17, Net_75);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_75));



endmodule

// Component: demux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// VDAC8_v1_90(Data_Source=0, Initial_Value=100, Strobe_Mode=1, VDAC_Range=0, VDAC_Speed=2, Voltage=400, CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=WaveDAC8_1:VDAC8, CY_INSTANCE_SHORT_NAME=VDAC8, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=WaveDAC8_1_VDAC8, )
module VDAC8_v1_90_2 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 100;
    parameter Strobe_Mode = 1;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: cydff_v1_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`endif

// WaveDAC8_v2_0(Clock_SRC=1, DAC_Range=0, DacModeReplString=VDAC8, Sample_Clock_Freq=6000, Wave1_Amplitude=0.05, Wave1_Data=6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,2u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u, Wave1_DCOffset=0.025, Wave1_Length=4000, Wave1_PhaseShift=0, Wave1_Type=0, Wave2_Amplitude=0, Wave2_Data=0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u, Wave2_DCOffset=0, Wave2_Length=100, Wave2_PhaseShift=0, Wave2_Type=0, CY_COMPONENT_NAME=WaveDAC8_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=WaveDAC8_1, CY_INSTANCE_SHORT_NAME=WaveDAC8_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=WaveDAC8_1, )
module WaveDAC8_v2_0_3 (
    Wave,
    ws,
    clock,
    wc1,
    wc2);
    inout       Wave;
    electrical  Wave;
    input       ws;
    input       clock;
    output      wc1;
    output      wc2;


          wire  Net_280;
    electrical  Net_273;
          wire  Net_202;
          wire  Net_201;
          wire [7:0] Net_171;
          wire [7:0] Net_170;
          wire  Net_339;
          wire  Net_341;
          wire  Net_153;
    electrical  Net_211;
          wire  Net_134;
          wire  Net_107;
          wire  Net_183;
          wire  Net_336;
          wire  Net_279;
          wire  Net_80;
    electrical  Net_247;
    electrical  Net_254;
    electrical  Net_256;
    electrical  Net_190;
    electrical  Net_189;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_211));


	cy_clock_v1_0
		#(.id("69f302ad-2949-409c-b45d-11dd9adbb9c9/77086516-855e-4b7b-abbe-47b22f8543de"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("166666666666.667"),
		  .is_direct(0),
		  .is_digital(1))
		DacClk
		 (.clock_out(Net_279));


	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_189, Net_256);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_190, Net_211);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_254));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		Wave1_DMA
		 (.drq(Net_183),
		  .trq(1'b0),
		  .nrq(wc1));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		Wave2_DMA
		 (.drq(Net_107),
		  .trq(1'b0),
		  .nrq(wc2));


    // -- De Mux start --
    if (1)
    begin : demux
        reg  tmp__demux_0_reg;
        reg  tmp__demux_1_reg;
        always @(Net_336 or Net_134)
        begin
            case (Net_134)
                1'b0:
                begin
                    tmp__demux_0_reg = Net_336;
                    tmp__demux_1_reg = 1'b0;
                end
                1'b1:
                begin
                    tmp__demux_0_reg = 1'b0;
                    tmp__demux_1_reg = Net_336;
                end
            endcase
        end
        assign Net_183 = tmp__demux_0_reg;
        assign Net_107 = tmp__demux_1_reg;
    end
    // -- De Mux end --

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_336 = Net_279;

    VDAC8_v1_90_2 VDAC8 (
        .strobe(Net_336),
        .data(8'b00000000),
        .vOut(Net_189));
    defparam VDAC8.Data_Source = 0;
    defparam VDAC8.Initial_Value = 100;
    defparam VDAC8.Strobe_Mode = 1;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Wave, Net_256);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;


    assign Net_280 = Net_279 | Net_80;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_80));

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge Net_336)
    begin
        cydff_1 <= ws;
    end
    assign Net_134 = cydff_1;
    // -- DFF End --



endmodule

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Comp_v2_0(Hysteresis=0, Pd_Override=0, Polarity=0, PSOC5A=false, Speed=0, Sync=1, CY_COMPONENT_NAME=Comp_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=CapSense:CompCH0, CY_INSTANCE_SHORT_NAME=CompCH0, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=CapSense_CompCH0, )
module Comp_v2_0_4 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_1;


    assign Net_9 = ~Net_1;



endmodule

// IDAC8_v2_0(Current=0, Data_Source=0, Hardware_Enable=true, IDAC_Range=4, IDAC_Speed=0, Initial_Value=0, Polarity=4, Strobe_Mode=0, CY_COMPONENT_NAME=IDAC8_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=CapSense:IdacCH0, CY_INSTANCE_SHORT_NAME=IdacCH0, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=CapSense_IdacCH0, )
module IDAC8_v2_0_5 (
    iOut,
    data,
    strobe,
    en,
    ipolarity);
    inout       iOut;
    electrical  iOut;
    input      [7:0] data;
    input       strobe;
    input       en;
    input       ipolarity;

    parameter Data_Source = 0;
    parameter Initial_Value = 0;
    parameter Strobe_Mode = 0;

          wire  Net_195;
          wire  Net_194;
    electrical  Net_124;
          wire  Net_158;
          wire  Net_157;
          wire  Net_123;
          wire  Net_125;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_125),
        .idir(Net_158),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(Net_124),
        .iout(iOut),
        .ioff(Net_123),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;


    assign Net_157 = ~en;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_125));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_124));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_123 = Net_157;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_158 = Net_195;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_194));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_195));



endmodule

// Component: cy_vref_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`endif

// Component: CapSense_CSD_AMux_v3_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_50"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_50\CapSense_CSD_AMux_v3_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_50\CapSense_CSD_AMux_v3_50.v"
`endif

// Component: CapSense_CSD_MeasureCh_v3_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_50"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_50\CapSense_CSD_MeasureCh_v3_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_50\CapSense_CSD_MeasureCh_v3_50.v"
`endif

// Component: CapSense_CSD_ClockGen_v3_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_50"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_50\CapSense_CSD_ClockGen_v3_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_50\CapSense_CSD_ClockGen_v3_50.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// CapSense_CSD_v3_50(AnalogSwitchDivider=11, ClockSource=0, ConnectInactiveSensors=0, CtlModeReplacementString=SyncCtrl, CurrentSource=1, EnableTuneHelper=false, EzI2CInstanceName=EZI2C, GuardSensorEnable=false, IdacRange=4, Implementation_CH0=1, Implementation_CH1=1, IntClockFrequency=24, LowBaselineReset=5, MaximumSensors=62, MultipleAnalogSwitchDivider=true, NegativeNoiseThreshold=20, NumberOfChannels=1, PrechargePolarity=3, PrescalerOptions=1, PrsOptions=2, RawDataFilterType=0, RbNumber_CH0=0, RbNumber_CH1=0, RemoveCH1=true, RemoveVrefTerm=false, ScanSpeed=7, SensorAutoReset=false, SensorNumber_CH0=7, SensorNumber_CH1=0, SensorNumberChannel0=7, SensorNumberChannel1=0, ShieldEnable=false, SizeReplacementString=uint8, SnsAlias_CH0=<?xml version='1.0'?><PinAliases Version='1'><pin0>Button0__BTN</pin0><pin1>Button1__BTN</pin1><pin2>LinearSlider0_e0__LS</pin2><pin3>LinearSlider0_e1__LS</pin3><pin4>LinearSlider0_e2__LS</pin4><pin5>LinearSlider0_e3__LS</pin5><pin6>LinearSlider0_e4__LS</pin6></PinAliases>, SnsAlias_CH1=<?xml version="1.0" ?><PinAliases Version="1"><pin0>pin1_ch1</pin0></PinAliases>, TunerProperties=, TuningMethod=2, VrefOptions=0, VrefValue=64, WaterProofingEnabled=false, WidgetResolution=8, WidgetsData=<?xml version="1.0" encoding="utf-16"?> <CyWidgetsList xmlns:version="v1.00">   <ListMainTerminal>     <CyTerminal NameIndex="0" WidgetName="Button0__BTN" />     <CyTerminal NameIndex="0" WidgetName="Button1__BTN" />     <CyTerminal NameIndex="0" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="1" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="2" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="3" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="4" WidgetName="LinearSlider0__LS" />   </ListMainTerminal>   <ListButtons>     <CyButton Name="Button0" Type="Button" Channel="First" Count="1" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1">       <Location>         <X>2147483647</X>         <Y>2147483647</Y>       </Location>       <Properties>         <Hysteresis>10</Hysteresis>         <Debounce>20</Debounce>         <FingerThreshold>100</FingerThreshold>         <NoiseThreshold>20</NoiseThreshold>         <ScanResolution>_10</ScanResolution>       </Properties>     </CyButton>     <CyButton Name="Button1" Type="Button" Channel="First" Count="1" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1">       <Location>         <X>2147483647</X>         <Y>2147483647</Y>       </Location>       <Properties>         <Hysteresis>10</Hysteresis>         <Debounce>20</Debounce>         <FingerThreshold>100</FingerThreshold>         <NoiseThreshold>20</NoiseThreshold>         <ScanResolution>_10</ScanResolution>       </Properties>     </CyButton>   </ListButtons>   <ListMatrixButtons />   <ListTouchPads />   <ListSliders>     <CySlider Name="LinearSlider0" Type="SliderLinear" Channel="First" Count="5" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1" Diplexing="false" Resolution="100" FilterPropertiesPos="FirstOrderIIR0_75">       <Location>         <X>2147483647</X>         <Y>2147483647</Y>       </Location>       <Properties>         <Hysteresis>0</Hysteresis>         <Debounce>1</Debounce>         <FingerThreshold>100</FingerThreshold>         <NoiseThreshold>20</NoiseThreshold>         <ScanResolution>_10</ScanResolution>       </Properties>     </CySlider>   </ListSliders>   <GuardSensor Name="GuardSensor" Type="Button" Channel="First" Count="1" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1">     <Location>       <X>2147483647</X>       <Y>2147483647</Y>     </Location>     <Properties>       <Hysteresis>10</Hysteresis>       <Debounce>5</Debounce>       <FingerThreshold>100</FingerThreshold>       <NoiseThreshold>20</NoiseThreshold>       <ScanResolution>_10</ScanResolution>     </Properties>   </GuardSensor>   <GuardSensorTerminal NameIndex="0" WidgetName="GuardSensor__GRD" />   <CyScanSlotsList>     <ListScanSlots>       <CyScanSlot IDACSettings="200" Sensitivity="4" AnalogSwitchDivider="11" WidgetName="Button0__BTN">         <ListTerminalsNames>           <string>Button0__BTN</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="4" AnalogSwitchDivider="11" WidgetName="Button1__BTN">         <ListTerminalsNames>           <string>Button1__BTN</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e0__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e1__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e2__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e3__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e4__LS</string>         </ListTerminalsNames>       </CyScanSlot>     </ListScanSlots>     <GuardSensorScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="GuardSensor__GRD">       <ListTerminalsNames>         <string>GuardSensor__GRD</string>       </ListTerminalsNames>     </GuardSensorScanSlot>   </CyScanSlotsList> </CyWidgetsList>, CY_COMPONENT_NAME=CapSense_CSD_v3_50, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=CapSense, CY_INSTANCE_SHORT_NAME=CapSense, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=50, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=CapSense, )
module CapSense_CSD_v3_50_6 (
    clock,
    shield,
    vref,
    bclk);
    input       clock;
    output      shield;
    inout       vref;
    electrical  vref;
    output      bclk;


          wire  Cmp_CH1;
          wire  Ioff_CH1;
          wire  DigitalClk;
          wire  PreChargeClk;
          wire  ShieldSignal;
          wire  Ioff_CH0;
          wire  Cmp_CH0;
          wire  Net_464;
          wire  Net_460;
          wire  Net_458;
          wire  clk;
          wire  mrst;
    electrical  Net_429;
    electrical  Net_428;
    electrical  Net_427;
    electrical  Net_426;
    electrical  Net_425;
    electrical  Net_424;
          wire  Net_397;
          wire  Net_396;
          wire  Net_371;
          wire  Net_373;
          wire  Net_374;
          wire  Net_372;
          wire  Net_375;
          wire [7:0] Net_423;
          wire  Net_422;
          wire  Net_421;
          wire  Net_474;
          wire [7:0] Net_471;
          wire  Net_470;
          wire  Net_420;
          wire [7:0] Net_413;
          wire  Net_412;
          wire  Net_411;
          wire  Net_469;
          wire [7:0] Net_466;
          wire  Net_465;
          wire  Net_410;
    electrical  Net_2129;
    electrical  Net_2101;
    electrical  Net_1440;
    electrical  Net_2153;
    electrical  Net_2098;
    electrical  Net_2072;
    electrical  Net_2077;
    electrical  Net_2038;
    electrical  Net_2031;
    electrical  Net_1903;
    electrical  Net_2149;
    electrical  Net_2107;
    electrical  Net_1956;
    electrical  Net_1433;
    electrical  Net_2164;
    electrical  Net_1438;
    electrical [6:0] Net_1410;
    electrical  Net_1983;
    electrical  Net_1425;
    electrical  Net_1917;
    electrical  Net_282;
          wire  Net_1644;
          wire  Net_461;
          wire  Net_1603;
          wire  Net_1358;
          wire  Net_1350;

    cy_psoc3_csabuf_v1_0 BufCH0 (
        .vref(Net_2129),
        .vout(Net_2072),
        .vchan(Net_2149));

    Comp_v2_0_4 CompCH0 (
        .Vplus(Net_282),
        .CmpOut(Cmp_CH0),
        .Vminus(Net_1983),
        .clock(1'b0));

    IDAC8_v2_0_5 IdacCH0 (
        .strobe(1'b0),
        .data(8'b00000000),
        .iOut(Net_1425),
        .en(Ioff_CH0),
        .ipolarity(1'b0));
    defparam IdacCH0.Data_Source = 0;
    defparam IdacCH0.Initial_Value = 0;
    defparam IdacCH0.Strobe_Mode = 0;

	wire [0:0] tmpOE__CmodCH0_net;
	wire [0:0] tmpFB_0__CmodCH0_net;
	wire [0:0] tmpIO_0__CmodCH0_net;
	wire [0:0] tmpINTERRUPT_0__CmodCH0_net;
	electrical [0:0] tmpSIOVREF__CmodCH0_net;

	cy_psoc3_pins_v1_10
		#(.id("66585408-645a-40fb-98ae-81509aded694/232398c5-3876-4e07-8f5b-7cd7657055e2"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("Cmod_CH0"),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		CmodCH0
		 (.oe(tmpOE__CmodCH0_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__CmodCH0_net[0:0]}),
		  .analog({Net_1917}),
		  .io({tmpIO_0__CmodCH0_net[0:0]}),
		  .siovref(tmpSIOVREF__CmodCH0_net),
		  .interrupt({tmpINTERRUPT_0__CmodCH0_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CmodCH0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PortCH0_net;

	cy_psoc3_port_v1_0
		#(.width(7),
		  .siorefwidth(4),
		  .id("66585408-645a-40fb-98ae-81509aded694/dd9c1af8-be5a-4b9e-b10c-b2d9f11dc9fc"),
		  .pin_aliases({"Button0__BTN,But","ton1__BTN,Linear","Slider0_e0__LS,L","inearSlider0_e1_","_LS,LinearSlider","0_e2__LS,LinearS","lider0_e3__LS,Li","nearSlider0_e4__","LS"}),
		  .access_mode("HW_ONLY"),
		  .layout_mode("NONCONTIGUOUS"),
		  .port_mode("ANALOG"),
		  .intr_mode(14'b00000000000000),
		  .drive_mode(21'b100100100100100100100),
		  .por_state(0),
		  .enable_shielding(7'b0000000),
		  .cs_mode(2'b11))
		PortCH0
		 (.oe(tmpOE__PortCH0_net),
		  .y(7'b0),
		  .analog(Net_1410[6:0]),
		  .precharge(PreChargeClk));

	assign tmpOE__PortCH0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? 1'b1 : 1'b0;


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("89B398AD-36A8-4627-9212-707F2986319E"),
		  .name("1.024V"))
		VrefRefCH0
		 (.vout(Net_2038));


    // -- AMux AMuxCH0 start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMuxCH0(
        .muxin({
            Net_1425,
            Net_282,
            Net_1917,
            Net_1410[6],
            Net_1410[5],
            Net_1410[4],
            Net_1410[3],
            Net_1410[2],
            Net_1410[1],
            Net_1410[0]
            }),
        .vout(Net_2072)
        );
    
    defparam AMuxCH0.muxin_width = 10;
    defparam AMuxCH0.init_mux_sel = 10'h0;
    defparam AMuxCH0.one_active = 0;
    
    // -- AMux AMuxCH0 end --

	// Select_VrefCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Select_VrefCH0_connect(Net_1983, Net_2038);
	defparam Select_VrefCH0_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_375));

    CapSense_CSD_MeasureCh_v3_50 MeasureCH0 (
        .cmp_in(Cmp_CH0),
        .pulse(DigitalClk),
        .clock(clk),
        .ioff(Ioff_CH0),
        .interrupt(Net_1603),
        .reset(mrst),
        .start(Net_1350),
        .enable(Net_373));
    defparam MeasureCH0.IdacOptions = 1;
    defparam MeasureCH0.ImplementationType = 1;

    CapSense_CSD_ClockGen_v3_50 ClockGen (
        .clock(clk),
        .dpulse(DigitalClk),
        .ppulse(PreChargeClk),
        .start0(Net_1350),
        .mesrst(mrst),
        .start1(Net_1358),
        .enable(Net_371),
        .reset(Net_375),
        .shield(ShieldSignal));
    defparam ClockGen.IdacOptions = 1;
    defparam ClockGen.PrescalerOptions = 1;
    defparam ClockGen.PrsOptions = 2;

    OneTerminal OneTerminal_3 (
        .o(Net_374));

    OneTerminal OneTerminal_2 (
        .o(Net_373));


	cy_isr_v1_0
		#(.int_type(2'b00))
		IsrCH0
		 (.int_signal(Net_1603));


    OneTerminal OneTerminal_1 (
        .o(Net_371));


	cy_clock_v1_0
		#(.id("66585408-645a-40fb-98ae-81509aded694/0ad1a1a8-974e-43a0-841b-3af08590011d"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("41666666.6666667"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_1644));


	// ClockSelect_VirtualMux (cy_virtualmux_v1_0)
	assign clk = Net_1644;

    cy_analog_noconnect_v1_0 NoConnect_VchanCH0 (
        .noconnect(Net_424));

	// Connect_VdacToAmuxCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Connect_VdacToAmuxCH0_connect(Net_1903, Net_425);
	defparam Connect_VdacToAmuxCH0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_1_024ToAMuxCH0 (
        .noconnect(Net_425));

	// Select_VrefOutput (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Select_VrefOutput_connect(vref, Net_2038);
	defparam Select_VrefOutput_connect.sig_width = 1;

	// Select_VrefCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Select_VrefCH1_connect(Net_2164, Net_2038);
	defparam Select_VrefCH1_connect.sig_width = 1;

	// Connect_VdacToAmuxCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Connect_VdacToAmuxCH1_connect(Net_2107, Net_426);
	defparam Connect_VdacToAmuxCH1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_1_024ToAMuxCH1 (
        .noconnect(Net_426));

	// DisableCapSBuf_VrefCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VrefCH0_connect(Net_2129, Net_1983);
	defparam DisableCapSBuf_VrefCH0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_VrefCH0 (
        .noconnect(Net_427));

	// DisableCapSBuf_VchanCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VchanCH1_connect(Net_2153, Net_1956);
	defparam DisableCapSBuf_VchanCH1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_VchanCH1 (
        .noconnect(Net_428));

	// DisableCapSBuf_VrefCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VrefCH1_connect(Net_2098, Net_2164);
	defparam DisableCapSBuf_VrefCH1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_VrefCH1 (
        .noconnect(Net_429));

	// DisableCapSBuf_VchanCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VchanCH0_connect(Net_2149, Net_1917);
	defparam DisableCapSBuf_VchanCH0_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_458));


    assign bclk = Net_460 | Net_458;


	cy_clock_v1_0
		#(.id("66585408-645a-40fb-98ae-81509aded694/52b807b3-40a8-4a39-b1e7-e18f76c3b871"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_tmp
		 (.clock_out(Net_460));



    assign shield = ShieldSignal;


endmodule

// Comp_v2_0(Hysteresis=0, Pd_Override=0, Polarity=0, PSOC5A=false, Speed=1, Sync=1, CY_COMPONENT_NAME=Comp_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Comp, CY_INSTANCE_SHORT_NAME=Comp, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=Comp, )
module Comp_v2_0_7 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_1;


    assign Net_9 = ~Net_1;



endmodule

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// USBFS_v2_80(AudioDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_80">   <Tree_x0020_Descriptors>     <DescriptorNode Key="Audio">       <Nodes />     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, CDCDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_80">   <Tree_x0020_Descriptors>     <DescriptorNode Key="CDC">       <Nodes>         <DescriptorNode Key="Interface718">           <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>ALTERNATE</bDescriptorType>             <bLength>0</bLength>             <DisplayName>CDC Interface 1</DisplayName>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor717">               <Value d8p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>INTERFACE</bDescriptorType>                 <bLength>9</bLength>                 <iwInterface>649</iwInterface>                 <bInterfaceClass>2</bInterfaceClass>                 <bNumEndpoints>1</bNumEndpoints>                 <bInterfaceSubClass>2</bInterfaceSubClass>                 <bInterfaceProtocol>1</bInterfaceProtocol>                 <iInterface>3</iInterface>                 <sInterface>CDC Communication Interface</sInterface>               </Value>               <Nodes>                 <DescriptorNode Key="USBDescriptor719">                   <Value d10p1:type="CyCDCHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>CDC</bDescriptorType>                     <bLength>5</bLength>                     <bDescriptorSubtype>HEADER</bDescriptorSubtype>                     <bcdADC>272</bcdADC>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor720">                   <Value d10p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>CDC</bDescriptorType>                     <bLength>4</bLength>                     <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>                     <bmCapabilities>2</bmCapabilities>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor721">                   <Value d10p1:type="CyCDCUnionDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>CDC</bDescriptorType>                     <bLength>5</bLength>                     <bDescriptorSubtype>UNION</bDescriptorSubtype>                     <bSubordinateInterface>AQ==</bSubordinateInterface>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor722">                   <Value d10p1:type="CyCDCCallManagementDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>CDC</bDescriptorType>                     <bLength>5</bLength>                     <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>                     <bDataInterface>1</bDataInterface>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor723">                   <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ENDPOINT</bDescriptorType>                     <bLength>7</bLength>                     <DoubleBuffer>false</DoubleBuffer>                     <bEndpointAddress>129</bEndpointAddress>                     <bmAttributes>3</bmAttributes>                   </Value>                   <Nodes />                 </DescriptorNode>               </Nodes>             </DescriptorNode>           </Nodes>         </DescriptorNode>         <DescriptorNode Key="Interface725">           <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>ALTERNATE</bDescriptorType>             <bLength>0</bLength>             <DisplayName>CDC Interface 2</DisplayName>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor724">               <Value d8p1:type="CyDataInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>INTERFACE</bDescriptorType>                 <bLength>9</bLength>                 <iwInterface>650</iwInterface>                 <bInterfaceClass>10</bInterfaceClass>                 <bInterfaceNumber>1</bInterfaceNumber>                 <bNumEndpoints>2</bNumEndpoints>                 <bInterfaceSubClass>0</bInterfaceSubClass>                 <bInterfaceProtocol>0</bInterfaceProtocol>                 <iInterface>4</iInterface>                 <sInterface>CDC Data Interface</sInterface>               </Value>               <Nodes>                 <DescriptorNode Key="USBDescriptor726">                   <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ENDPOINT</bDescriptorType>                     <bLength>7</bLength>                     <DoubleBuffer>false</DoubleBuffer>                     <bEndpointAddress>130</bEndpointAddress>                     <bmAttributes>2</bmAttributes>                     <wMaxPacketSize>64</wMaxPacketSize>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor727">                   <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ENDPOINT</bDescriptorType>                     <bLength>7</bLength>                     <DoubleBuffer>false</DoubleBuffer>                     <bEndpointAddress>3</bEndpointAddress>                     <bmAttributes>2</bmAttributes>                     <wMaxPacketSize>64</wMaxPacketSize>                   </Value>                   <Nodes />                 </DescriptorNode>               </Nodes>             </DescriptorNode>           </Nodes>         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, DeviceDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_80">   <Tree_x0020_Descriptors>     <DescriptorNode Key="Device">       <Nodes>         <DescriptorNode Key="USBDescriptor651">           <Value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>DEVICE</bDescriptorType>             <bLength>18</bLength>             <iwManufacturer>647</iwManufacturer>             <iwProduct>648</iwProduct>             <sManufacturer>Cypress Semiconductor</sManufacturer>             <sProduct>USBUART</sProduct>             <sSerialNumber />             <bDeviceClass>2</bDeviceClass>             <bDeviceSubClass>0</bDeviceSubClass>             <bDeviceProtocol>0</bDeviceProtocol>             <bMaxPacketSize0>0</bMaxPacketSize0>             <idVendor>1204</idVendor>             <idProduct>62002</idProduct>             <bcdDevice>1</bcdDevice>             <iManufacturer>1</iManufacturer>             <iProduct>2</iProduct>             <iSerialNumber>128</iSerialNumber>             <bNumConfigurations>1</bNumConfigurations>             <bMemoryMgmt>0</bMemoryMgmt>             <bMemoryAlloc>0</bMemoryAlloc>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor656">               <Value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>CONFIGURATION</bDescriptorType>                 <bLength>9</bLength>                 <iwConfiguration>647</iwConfiguration>                 <sConfiguration>Cypress Semiconductor</sConfiguration>                 <wTotalLength>67</wTotalLength>                 <bNumInterfaces>2</bNumInterfaces>                 <bConfigurationValue>0</bConfigurationValue>                 <iConfiguration>1</iConfiguration>                 <bmAttributes>192</bmAttributes>                 <bMaxPower>50</bMaxPower>               </Value>               <Nodes>                 <DescriptorNode Key="Interface718">                   <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ALTERNATE</bDescriptorType>                     <bLength>0</bLength>                     <DisplayName>CDC Interface 1</DisplayName>                   </Value>                   <Nodes>                     <DescriptorNode Key="USBDescriptor717">                       <Value d12p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>INTERFACE</bDescriptorType>                         <bLength>9</bLength>                         <iwInterface>649</iwInterface>                         <bInterfaceClass>2</bInterfaceClass>                         <bNumEndpoints>1</bNumEndpoints>                         <bInterfaceSubClass>2</bInterfaceSubClass>                         <bInterfaceProtocol>1</bInterfaceProtocol>                         <iInterface>3</iInterface>                         <sInterface>CDC Communication Interface</sInterface>                       </Value>                       <Nodes>                         <DescriptorNode Key="USBDescriptor719">                           <Value d14p1:type="CyCDCHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>CDC</bDescriptorType>                             <bLength>5</bLength>                             <bDescriptorSubtype>HEADER</bDescriptorSubtype>                             <bcdADC>272</bcdADC>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor720">                           <Value d14p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>CDC</bDescriptorType>                             <bLength>4</bLength>                             <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>                             <bmCapabilities>2</bmCapabilities>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor721">                           <Value d14p1:type="CyCDCUnionDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>CDC</bDescriptorType>                             <bLength>5</bLength>                             <bDescriptorSubtype>UNION</bDescriptorSubtype>                             <bSubordinateInterface>AQ==</bSubordinateInterface>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor722">                           <Value d14p1:type="CyCDCCallManagementDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>CDC</bDescriptorType>                             <bLength>5</bLength>                             <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>                             <bDataInterface>1</bDataInterface>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor723">                           <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>ENDPOINT</bDescriptorType>                             <bLength>7</bLength>                             <DoubleBuffer>false</DoubleBuffer>                             <bEndpointAddress>129</bEndpointAddress>                             <bmAttributes>3</bmAttributes>                           </Value>                           <Nodes />                         </DescriptorNode>                       </Nodes>                     </DescriptorNode>                   </Nodes>                 </DescriptorNode>                 <DescriptorNode Key="Interface725">                   <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ALTERNATE</bDescriptorType>                     <bLength>0</bLength>                     <DisplayName>CDC Interface 2</DisplayName>                   </Value>                   <Nodes>                     <DescriptorNode Key="USBDescriptor724">                       <Value d12p1:type="CyDataInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>INTERFACE</bDescriptorType>                         <bLength>9</bLength>                         <iwInterface>650</iwInterface>                         <bInterfaceClass>10</bInterfaceClass>                         <bInterfaceNumber>1</bInterfaceNumber>                         <bNumEndpoints>2</bNumEndpoints>                         <bInterfaceSubClass>0</bInterfaceSubClass>                         <bInterfaceProtocol>0</bInterfaceProtocol>                         <iInterface>4</iInterface>                         <sInterface>CDC Data Interface</sInterface>                       </Value>                       <Nodes>                         <DescriptorNode Key="USBDescriptor726">                           <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>ENDPOINT</bDescriptorType>                             <bLength>7</bLength>                             <DoubleBuffer>false</DoubleBuffer>                             <bEndpointAddress>130</bEndpointAddress>                             <bmAttributes>2</bmAttributes>                             <wMaxPacketSize>64</wMaxPacketSize>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor727">                           <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>ENDPOINT</bDescriptorType>                             <bLength>7</bLength>                             <DoubleBuffer>false</DoubleBuffer>                             <bEndpointAddress>3</bEndpointAddress>                             <bmAttributes>2</bmAttributes>                             <wMaxPacketSize>64</wMaxPacketSize>                           </Value>                           <Nodes />                         </DescriptorNode>                       </Nodes>                     </DescriptorNode>                   </Nodes>                 </DescriptorNode>               </Nodes>             </DescriptorNode>           </Nodes>         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, EnableCDCApi=true, EnableMidiApi=true, endpointMA=0, endpointMM=0, epDMAautoOptimization=false, extern_cls=false, extern_vbus=false, extern_vnd=false, extJackCount=0, HIDReportDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_80">   <Tree_x0020_Descriptors>     <DescriptorNode Key="HIDReport">       <Nodes />     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, max_interfaces_num=2, MidiDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_80">   <Tree_x0020_Descriptors>     <DescriptorNode Key="Midi">       <Nodes />     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, Mode=false, mon_vbus=false, out_sof=false, Pid=F232, rm_arb_int=false, rm_dma_1=true, rm_dma_2=true, rm_dma_3=true, rm_dma_4=true, rm_dma_5=true, rm_dma_6=true, rm_dma_7=true, rm_dma_8=true, rm_dp_int=false, rm_ep_isr_0=false, rm_ep_isr_1=false, rm_ep_isr_2=false, rm_ep_isr_3=false, rm_ep_isr_4=true, rm_ep_isr_5=true, rm_ep_isr_6=true, rm_ep_isr_7=true, rm_ep_isr_8=true, rm_ord_int=true, rm_sof_int=false, rm_usb_int=false, StringDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_80">   <Tree_x0020_Descriptors>     <DescriptorNode Key="String">       <Nodes>         <DescriptorNode Key="LANGID">           <Value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>4</bLength>             <wLANGID>1033</wLANGID>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor647">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>44</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Cypress Semiconductor</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor648">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>16</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>USBUART</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor649">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>56</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>CDC Communication Interface</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor650">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>38</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>CDC Data Interface</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>       </Nodes>     </DescriptorNode>     <DescriptorNode Key="SpecialString">       <Nodes>         <DescriptorNode Key="Serial">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>2</bLength>             <snType>SILICON_NUMBER</snType>             <bString />             <bUsed>true</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="EE">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>16</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>MSFT100</bString>             <bUsed>true</bUsed>           </Value>           <Nodes />         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, Vid=04B4, CY_COMPONENT_NAME=USBFS_v2_80, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=USBUART, CY_INSTANCE_SHORT_NAME=USBUART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=80, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=USBUART, )
module USBFS_v2_80_8 (
    sof,
    vbusdet);
    output      sof;
    input       vbusdet;

    parameter epDMAautoOptimization = 0;

          wire [7:0] Net_1790;
          wire  Net_1789;
          wire  Net_1788;
          wire  Net_1787;
          wire  Net_1786;
          wire  Net_1785;
          wire  Net_1783;
          wire  Net_1782;
          wire  Net_1781;
          wire  Net_1802;
          wire  Net_1824;
          wire  Net_1823;
          wire  Net_1822;
          wire  Net_1821;
          wire  Net_1784;
          wire [7:0] Net_1816;
          wire  Net_1815;
          wire  Net_1814;
          wire  Net_1813;
          wire  Net_1812;
          wire  Net_1811;
          wire  Net_1810;
          wire  Net_1809;
          wire  Net_1808;
          wire  Net_1807;
          wire  Net_1806;
          wire  Net_1805;
          wire  Net_1804;
          wire  Net_1799;
          wire  Net_1798;
          wire  Net_1797;
          wire  Net_1796;
          wire  Net_1795;
          wire  Net_1794;
          wire  Net_1793;
          wire  Net_1792;
          wire  Net_1791;
          wire  Net_1801;
          wire  Net_1803;
          wire  Net_1800;
          wire  Net_1768;
          wire [8:0] ept_int;
          wire [7:0] dma_req;
          wire [7:0] dma_nrq;
          wire  Net_1522;
          wire  Net_1591;
          wire  Net_1588;
          wire [7:0] dma_nrq_sync;
          wire  Net_1579;
          wire  Net_1576;
          wire  Net_1567;
          wire  Net_1559;
          wire  Net_1498;
          wire  Net_1495;
          wire  Net_1010;
    electrical  Net_1000;
          wire  Net_824;
    electrical  Net_597;
          wire  Net_95;
          wire  Net_81;
          wire  Net_79;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign dma_nrq[0] = Net_1800;


	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_0
		 (.int_signal(ept_int[0:0]));


	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign dma_nrq[3] = Net_1803;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_1801));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign dma_nrq[1] = Net_1801;

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_1803));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_1800));

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign dma_nrq[4] = Net_1804;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign dma_nrq[5] = Net_1805;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_1804));

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_1805));

	// VirtualMux_7 (cy_virtualmux_v1_0)
	assign dma_nrq[6] = Net_1806;

	// VirtualMux_8 (cy_virtualmux_v1_0)
	assign dma_nrq[7] = Net_1807;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_1806));


	cy_isr_v1_0
		#(.int_type(2'b10))
		bus_reset
		 (.int_signal(Net_81));



	cy_isr_v1_0
		#(.int_type(2'b10))
		arb_int
		 (.int_signal(Net_79));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_2
		 (.int_signal(ept_int[2:2]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_1
		 (.int_signal(ept_int[1:1]));


    ZeroTerminal ZeroTerminal_8 (
        .z(Net_1807));


	cy_clock_v1_0
		#(.id("2b269b96-47a4-4e9a-937e-76d4080bb211/03f503a7-085a-4304-b786-de885b1c2f21"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_vbus
		 (.clock_out(Net_1784));


	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign dma_nrq[2] = Net_1802;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1802));


	cy_isr_v1_0
		#(.int_type(2'b10))
		dp_int
		 (.int_signal(Net_1010));


	wire [0:0] tmpOE__Dm_net;
	wire [0:0] tmpFB_0__Dm_net;
	wire [0:0] tmpIO_0__Dm_net;
	wire [0:0] tmpINTERRUPT_0__Dm_net;
	electrical [0:0] tmpSIOVREF__Dm_net;

	cy_psoc3_pins_v1_10
		#(.id("2b269b96-47a4-4e9a-937e-76d4080bb211/8b77a6c4-10a0-4390-971c-672353e2a49c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dm
		 (.oe(tmpOE__Dm_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dm_net[0:0]}),
		  .analog({Net_597}),
		  .io({tmpIO_0__Dm_net[0:0]}),
		  .siovref(tmpSIOVREF__Dm_net),
		  .interrupt({tmpINTERRUPT_0__Dm_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dm_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Dp_net;
	wire [0:0] tmpFB_0__Dp_net;
	wire [0:0] tmpIO_0__Dp_net;
	electrical [0:0] tmpSIOVREF__Dp_net;

	cy_psoc3_pins_v1_10
		#(.id("2b269b96-47a4-4e9a-937e-76d4080bb211/618a72fc-5ddd-4df5-958f-a3d55102db42"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b10),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dp
		 (.oe(tmpOE__Dp_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dp_net[0:0]}),
		  .analog({Net_1000}),
		  .io({tmpIO_0__Dp_net[0:0]}),
		  .siovref(tmpSIOVREF__Dp_net),
		  .interrupt({Net_1010}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_psoc3_usb_v1_0 USB (
        .dp(Net_1000),
        .dm(Net_597),
        .sof_int(sof),
        .arb_int(Net_79),
        .usb_int(Net_81),
        .ept_int(ept_int[8:0]),
        .ord_int(Net_95),
        .dma_req(dma_req[7:0]),
        .dma_termin(Net_824));


	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_3
		 (.int_signal(ept_int[3:3]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		sof_int
		 (.int_signal(sof));




endmodule

// Component: B_Counter_v3_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`endif

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=128, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, EnableMode=2, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=4294967295, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=4294967295, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, ReloadOnCapture=false, ReloadOnCompare=true, ReloadOnOverUnder=false, ReloadOnReset=true, Resolution=32, RunMode=0, UDB16=false, UDB24=false, UDB32=true, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC32, CY_COMPONENT_NAME=Counter_v3_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=HeartbeatCounter, CY_INSTANCE_SHORT_NAME=HeartbeatCounter, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=HeartbeatCounter, )
module Counter_v3_0_9 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 3;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 2;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 1;
    parameter ReloadOnOverUnder = 0;
    parameter ReloadOnReset = 1;
    parameter Resolution = 32;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = Net_95;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 3;
    defparam CounterUDB.CompareMode = 1;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 2;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 1;
    defparam CounterUDB.ReloadOnOverUnder = 0;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 32;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: B_PWM_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`endif

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=127, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=65535, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=false, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=false, UseStatus=false, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v3_30, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM, CY_INSTANCE_SHORT_NAME=PWM, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.2 SP1, INSTANCE_NAME=PWM, )
module PWM_v3_30_10 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v3_30 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 0;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// top
module top ;

          wire  Net_1666;
          wire  Net_1665;
          wire  Net_1664;
          wire  Net_1662;
          wire  Net_1661;
          wire  Net_1660;
          wire  Net_1659;
          wire  Net_1658;
          wire  Net_1657;
          wire  Net_1656;
          wire  Net_1655;
          wire  Net_1651;
          wire  Net_1653;
          wire  Net_1652;
          wire  Net_1547;
          wire  Net_1546;
          wire  Net_1545;
          wire  Net_1544;
          wire  Net_1540;
          wire  Net_1543;
          wire  Net_1542;
          wire  Net_1541;
          wire  Net_1399;
          wire  Net_1398;
          wire  Net_1300;
          wire  Net_1485;
    electrical  Net_1677;
          wire  Net_171;
          wire  Net_134;
    electrical  Net_133;
          wire  Net_132;
          wire  Net_131;
          wire  Net_523;
          wire  Net_522;
          wire  Net_521;
    electrical  Net_167;
          wire  Net_1675;
          wire  Net_1668;
          wire  Net_353;
          wire  Net_1200;
          wire  Net_1487;
          wire  Net_1146;
    electrical  Net_157;
          wire  Net_1032;
    electrical  Net_1667;
    electrical  Net_569;

    CharLCD_v2_10_0 LCD ();

    PGA_v2_0_1 PGA_1 (
        .Vin(Net_1667),
        .Vref(Net_167),
        .Vout(Net_569));

    WaveDAC8_v2_0_3 WaveDAC8_1 (
        .Wave(Net_1667),
        .ws(Net_353),
        .clock(1'b0),
        .wc1(Net_522),
        .wc2(Net_523));

	wire [0:0] tmpOE__Speaker_Output_net;
	wire [0:0] tmpFB_0__Speaker_Output_net;
	wire [0:0] tmpIO_0__Speaker_Output_net;
	wire [0:0] tmpINTERRUPT_0__Speaker_Output_net;
	electrical [0:0] tmpSIOVREF__Speaker_Output_net;

	cy_psoc3_pins_v1_10
		#(.id("6578865f-394e-4ed2-9257-0ddbe1184c39"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Speaker_Output
		 (.oe(tmpOE__Speaker_Output_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Speaker_Output_net[0:0]}),
		  .io({tmpIO_0__Speaker_Output_net[0:0]}),
		  .siovref(tmpSIOVREF__Speaker_Output_net),
		  .interrupt({tmpINTERRUPT_0__Speaker_Output_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Speaker_Output_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CapSense_CSD_v3_50_6 CapSense (
        .clock(1'b0),
        .shield(Net_132),
        .vref(Net_133),
        .bclk(Net_134));


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("4720866E-BC14-478d-B8A0-3E44F38CADAC"),
		  .name("Vdda/2"))
		vRef
		 (.vout(Net_157));


    Comp_v2_0_7 Comp (
        .Vplus(Net_569),
        .CmpOut(Net_1032),
        .Vminus(Net_157),
        .clock(1'b0));

	wire [0:0] tmpOE__HEARTRATE_ANALOG_IN_net;
	wire [0:0] tmpFB_0__HEARTRATE_ANALOG_IN_net;
	wire [0:0] tmpIO_0__HEARTRATE_ANALOG_IN_net;
	wire [0:0] tmpINTERRUPT_0__HEARTRATE_ANALOG_IN_net;
	electrical [0:0] tmpSIOVREF__HEARTRATE_ANALOG_IN_net;

	cy_psoc3_pins_v1_10
		#(.id("77715107-f8d5-47e5-a629-0fb83101ac6b"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		HEARTRATE_ANALOG_IN
		 (.oe(tmpOE__HEARTRATE_ANALOG_IN_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__HEARTRATE_ANALOG_IN_net[0:0]}),
		  .analog({Net_1677}),
		  .io({tmpIO_0__HEARTRATE_ANALOG_IN_net[0:0]}),
		  .siovref(tmpSIOVREF__HEARTRATE_ANALOG_IN_net),
		  .interrupt({tmpINTERRUPT_0__HEARTRATE_ANALOG_IN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__HEARTRATE_ANALOG_IN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("c0fb34bd-1044-4931-9788-16b01ce89812"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		timer_clock
		 (.clock_out(Net_1487));



	cy_clock_v1_0
		#(.id("988d0bd4-c15d-425a-b587-33d6076c6f1a"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("100000000000"),
		  .is_direct(0),
		  .is_digital(1))
		timer_clock_1
		 (.clock_out(Net_1200));


    assign Net_353 = 1'h0;

	wire [0:0] tmpOE__Pin_1_net;
	wire [0:0] tmpFB_0__Pin_1_net;
	wire [0:0] tmpIO_0__Pin_1_net;
	wire [0:0] tmpINTERRUPT_0__Pin_1_net;
	electrical [0:0] tmpSIOVREF__Pin_1_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_1
		 (.oe(tmpOE__Pin_1_net),
		  .y({Net_1032}),
		  .fb({tmpFB_0__Pin_1_net[0:0]}),
		  .io({tmpIO_0__Pin_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_1_net),
		  .interrupt({tmpINTERRUPT_0__Pin_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__amp_net;
	wire [0:0] tmpFB_0__amp_net;
	wire [0:0] tmpIO_0__amp_net;
	wire [0:0] tmpINTERRUPT_0__amp_net;
	electrical [0:0] tmpSIOVREF__amp_net;

	cy_psoc3_pins_v1_10
		#(.id("81cc58cc-0eba-44cb-9f20-a0ccdee9573a"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		amp
		 (.oe(tmpOE__amp_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__amp_net[0:0]}),
		  .analog({Net_569}),
		  .io({tmpIO_0__amp_net[0:0]}),
		  .siovref(tmpSIOVREF__amp_net),
		  .interrupt({tmpINTERRUPT_0__amp_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__amp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		Compint
		 (.int_signal(Net_1032));


    ZeroTerminal ZeroTerminal_1 (
        .z(Net_1146));

    USBFS_v2_80_8 USBUART (
        .sof(Net_1398),
        .vbusdet(1'b0));
    defparam USBUART.epDMAautoOptimization = 0;

    Counter_v3_0_9 HeartbeatCounter (
        .reset(Net_1146),
        .tc(Net_1541),
        .comp(Net_1542),
        .clock(Net_1487),
        .interrupt(Net_1543),
        .enable(Net_1540),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_1200));
    defparam HeartbeatCounter.CaptureMode = 0;
    defparam HeartbeatCounter.ClockMode = 3;
    defparam HeartbeatCounter.CompareMode = 1;
    defparam HeartbeatCounter.CompareStatusEdgeSense = 1;
    defparam HeartbeatCounter.EnableMode = 2;
    defparam HeartbeatCounter.ReloadOnCapture = 0;
    defparam HeartbeatCounter.ReloadOnCompare = 1;
    defparam HeartbeatCounter.ReloadOnOverUnder = 0;
    defparam HeartbeatCounter.ReloadOnReset = 1;
    defparam HeartbeatCounter.Resolution = 32;
    defparam HeartbeatCounter.RunMode = 0;
    defparam HeartbeatCounter.UseInterrupt = 1;

    assign Net_1540 = 1'h1;

    PWM_v3_30_10 PWM (
        .reset(1'b0),
        .clock(Net_1653),
        .tc(Net_1651),
        .pwm1(Net_1655),
        .pwm2(Net_1656),
        .interrupt(Net_1657),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_1668),
        .ph1(Net_1664),
        .ph2(Net_1665));
    defparam PWM.Resolution = 16;


	cy_clock_v1_0
		#(.id("149f0702-0721-40a6-be18-4d64214f60c2"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		timer_clock_2
		 (.clock_out(Net_1653));


	wire [0:0] tmpOE__PWM_Output_net;
	wire [0:0] tmpFB_0__PWM_Output_net;
	wire [0:0] tmpIO_0__PWM_Output_net;
	wire [0:0] tmpINTERRUPT_0__PWM_Output_net;
	electrical [0:0] tmpSIOVREF__PWM_Output_net;

	cy_psoc3_pins_v1_10
		#(.id("12e5fc5f-0ee4-40f1-afb0-63c8783970f1"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PWM_Output
		 (.oe(tmpOE__PWM_Output_net),
		  .y({Net_1668}),
		  .fb({tmpFB_0__PWM_Output_net[0:0]}),
		  .io({tmpIO_0__PWM_Output_net[0:0]}),
		  .siovref(tmpSIOVREF__PWM_Output_net),
		  .interrupt({tmpINTERRUPT_0__PWM_Output_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PWM_Output_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__STOP_REQUEST_net;
	wire [0:0] tmpIO_0__STOP_REQUEST_net;
	wire [0:0] tmpINTERRUPT_0__STOP_REQUEST_net;
	electrical [0:0] tmpSIOVREF__STOP_REQUEST_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STOP_REQUEST
		 (.oe(tmpOE__STOP_REQUEST_net),
		  .y({1'b0}),
		  .fb({Net_1675}),
		  .io({tmpIO_0__STOP_REQUEST_net[0:0]}),
		  .siovref(tmpSIOVREF__STOP_REQUEST_net),
		  .interrupt({tmpINTERRUPT_0__STOP_REQUEST_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STOP_REQUEST_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		STOP
		 (.int_signal(Net_1675));




endmodule

