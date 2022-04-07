// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _abs_diff_HH_
#define _abs_diff_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

template<unsigned int C_M_AXI_C_ADDR_WIDTH = 32,
         unsigned int C_M_AXI_C_ID_WIDTH = 1,
         unsigned int C_M_AXI_C_AWUSER_WIDTH = 1,
         unsigned int C_M_AXI_C_DATA_WIDTH = 32,
         unsigned int C_M_AXI_C_WUSER_WIDTH = 1,
         unsigned int C_M_AXI_C_ARUSER_WIDTH = 1,
         unsigned int C_M_AXI_C_RUSER_WIDTH = 1,
         unsigned int C_M_AXI_C_BUSER_WIDTH = 1>
struct abs_diff : public sc_module {
    // Port declarations 74
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_out< sc_lv<32> > y_TDATA;
    sc_out< sc_logic > y_TVALID;
    sc_in< sc_logic > y_TREADY;
    sc_out< sc_lv<4> > y_TKEEP;
    sc_out< sc_lv<4> > y_TSTRB;
    sc_out< sc_lv<1> > y_TUSER;
    sc_out< sc_lv<1> > y_TLAST;
    sc_out< sc_lv<1> > y_TID;
    sc_out< sc_lv<1> > y_TDEST;
    sc_out< sc_logic > m_axi_c_AWVALID;
    sc_in< sc_logic > m_axi_c_AWREADY;
    sc_out< sc_uint<C_M_AXI_C_ADDR_WIDTH> > m_axi_c_AWADDR;
    sc_out< sc_uint<C_M_AXI_C_ID_WIDTH> > m_axi_c_AWID;
    sc_out< sc_lv<8> > m_axi_c_AWLEN;
    sc_out< sc_lv<3> > m_axi_c_AWSIZE;
    sc_out< sc_lv<2> > m_axi_c_AWBURST;
    sc_out< sc_lv<2> > m_axi_c_AWLOCK;
    sc_out< sc_lv<4> > m_axi_c_AWCACHE;
    sc_out< sc_lv<3> > m_axi_c_AWPROT;
    sc_out< sc_lv<4> > m_axi_c_AWQOS;
    sc_out< sc_lv<4> > m_axi_c_AWREGION;
    sc_out< sc_uint<C_M_AXI_C_AWUSER_WIDTH> > m_axi_c_AWUSER;
    sc_out< sc_logic > m_axi_c_WVALID;
    sc_in< sc_logic > m_axi_c_WREADY;
    sc_out< sc_uint<C_M_AXI_C_DATA_WIDTH> > m_axi_c_WDATA;
    sc_out< sc_uint<C_M_AXI_C_DATA_WIDTH/8> > m_axi_c_WSTRB;
    sc_out< sc_logic > m_axi_c_WLAST;
    sc_out< sc_uint<C_M_AXI_C_ID_WIDTH> > m_axi_c_WID;
    sc_out< sc_uint<C_M_AXI_C_WUSER_WIDTH> > m_axi_c_WUSER;
    sc_out< sc_logic > m_axi_c_ARVALID;
    sc_in< sc_logic > m_axi_c_ARREADY;
    sc_out< sc_uint<C_M_AXI_C_ADDR_WIDTH> > m_axi_c_ARADDR;
    sc_out< sc_uint<C_M_AXI_C_ID_WIDTH> > m_axi_c_ARID;
    sc_out< sc_lv<8> > m_axi_c_ARLEN;
    sc_out< sc_lv<3> > m_axi_c_ARSIZE;
    sc_out< sc_lv<2> > m_axi_c_ARBURST;
    sc_out< sc_lv<2> > m_axi_c_ARLOCK;
    sc_out< sc_lv<4> > m_axi_c_ARCACHE;
    sc_out< sc_lv<3> > m_axi_c_ARPROT;
    sc_out< sc_lv<4> > m_axi_c_ARQOS;
    sc_out< sc_lv<4> > m_axi_c_ARREGION;
    sc_out< sc_uint<C_M_AXI_C_ARUSER_WIDTH> > m_axi_c_ARUSER;
    sc_in< sc_logic > m_axi_c_RVALID;
    sc_out< sc_logic > m_axi_c_RREADY;
    sc_in< sc_uint<C_M_AXI_C_DATA_WIDTH> > m_axi_c_RDATA;
    sc_in< sc_logic > m_axi_c_RLAST;
    sc_in< sc_uint<C_M_AXI_C_ID_WIDTH> > m_axi_c_RID;
    sc_in< sc_uint<C_M_AXI_C_RUSER_WIDTH> > m_axi_c_RUSER;
    sc_in< sc_lv<2> > m_axi_c_RRESP;
    sc_in< sc_logic > m_axi_c_BVALID;
    sc_out< sc_logic > m_axi_c_BREADY;
    sc_in< sc_lv<2> > m_axi_c_BRESP;
    sc_in< sc_uint<C_M_AXI_C_ID_WIDTH> > m_axi_c_BID;
    sc_in< sc_uint<C_M_AXI_C_BUSER_WIDTH> > m_axi_c_BUSER;
    sc_in< sc_lv<32> > img1_TDATA;
    sc_in< sc_logic > img1_TVALID;
    sc_out< sc_logic > img1_TREADY;
    sc_in< sc_lv<4> > img1_TKEEP;
    sc_in< sc_lv<4> > img1_TSTRB;
    sc_in< sc_lv<1> > img1_TUSER;
    sc_in< sc_lv<1> > img1_TLAST;
    sc_in< sc_lv<1> > img1_TID;
    sc_in< sc_lv<1> > img1_TDEST;
    sc_in< sc_lv<32> > img2_TDATA;
    sc_in< sc_logic > img2_TVALID;
    sc_out< sc_logic > img2_TREADY;
    sc_in< sc_lv<4> > img2_TKEEP;
    sc_in< sc_lv<4> > img2_TSTRB;
    sc_in< sc_lv<1> > img2_TUSER;
    sc_in< sc_lv<1> > img2_TLAST;
    sc_in< sc_lv<1> > img2_TID;
    sc_in< sc_lv<1> > img2_TDEST;


    // Module declarations
    abs_diff(sc_module_name name);
    SC_HAS_PROCESS(abs_diff);

    ~abs_diff();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    regslice_both<32>* regslice_both_y_data_V_U;
    regslice_both<4>* regslice_both_y_keep_V_U;
    regslice_both<4>* regslice_both_y_strb_V_U;
    regslice_both<1>* regslice_both_y_user_V_U;
    regslice_both<1>* regslice_both_y_last_V_U;
    regslice_both<1>* regslice_both_y_id_V_U;
    regslice_both<1>* regslice_both_y_dest_V_U;
    regslice_both<32>* regslice_both_img1_data_V_U;
    regslice_both<4>* regslice_both_img1_keep_V_U;
    regslice_both<4>* regslice_both_img1_strb_V_U;
    regslice_both<1>* regslice_both_img1_user_V_U;
    regslice_both<1>* regslice_both_img1_last_V_U;
    regslice_both<1>* regslice_both_img1_id_V_U;
    regslice_both<1>* regslice_both_img1_dest_V_U;
    regslice_both<32>* regslice_both_img2_data_V_U;
    regslice_both<4>* regslice_both_img2_keep_V_U;
    regslice_both<4>* regslice_both_img2_strb_V_U;
    regslice_both<1>* regslice_both_img2_user_V_U;
    regslice_both<1>* regslice_both_img2_last_V_U;
    regslice_both<1>* regslice_both_img2_id_V_U;
    regslice_both<1>* regslice_both_img2_dest_V_U;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_logic > y_TDATA_blk_n;
    sc_signal< sc_lv<2> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > img1_TDATA_blk_n;
    sc_signal< sc_logic > img2_TDATA_blk_n;
    sc_signal< bool > ap_block_state1;
    sc_signal< sc_lv<32> > sub_ln22_fu_173_p2;
    sc_signal< sc_lv<1> > abscond_100_fu_185_p2;
    sc_signal< sc_lv<32> > neg_100_fu_179_p2;
    sc_signal< sc_lv<2> > ap_NS_fsm;
    sc_signal< sc_logic > regslice_both_y_data_V_U_apdone_blk;
    sc_signal< sc_lv<32> > y_TDATA_int;
    sc_signal< sc_logic > y_TVALID_int;
    sc_signal< sc_logic > y_TREADY_int;
    sc_signal< sc_logic > regslice_both_y_data_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_y_keep_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_y_keep_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_y_keep_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_y_strb_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_y_strb_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_y_strb_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_y_user_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_y_user_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_y_user_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_y_last_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_y_last_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_y_last_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_y_id_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_y_id_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_y_id_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_y_dest_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_y_dest_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_y_dest_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_data_V_U_apdone_blk;
    sc_signal< sc_lv<32> > img1_TDATA_int;
    sc_signal< sc_logic > img1_TVALID_int;
    sc_signal< sc_logic > img1_TREADY_int;
    sc_signal< sc_logic > regslice_both_img1_data_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img1_keep_V_U_apdone_blk;
    sc_signal< sc_lv<4> > img1_TKEEP_int;
    sc_signal< sc_logic > regslice_both_img1_keep_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_keep_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img1_strb_V_U_apdone_blk;
    sc_signal< sc_lv<4> > img1_TSTRB_int;
    sc_signal< sc_logic > regslice_both_img1_strb_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_strb_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img1_user_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img1_TUSER_int;
    sc_signal< sc_logic > regslice_both_img1_user_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_user_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img1_last_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img1_TLAST_int;
    sc_signal< sc_logic > regslice_both_img1_last_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_last_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img1_id_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img1_TID_int;
    sc_signal< sc_logic > regslice_both_img1_id_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_id_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img1_dest_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img1_TDEST_int;
    sc_signal< sc_logic > regslice_both_img1_dest_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img1_dest_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_data_V_U_apdone_blk;
    sc_signal< sc_lv<32> > img2_TDATA_int;
    sc_signal< sc_logic > img2_TVALID_int;
    sc_signal< sc_logic > img2_TREADY_int;
    sc_signal< sc_logic > regslice_both_img2_data_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_keep_V_U_apdone_blk;
    sc_signal< sc_lv<4> > img2_TKEEP_int;
    sc_signal< sc_logic > regslice_both_img2_keep_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img2_keep_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_strb_V_U_apdone_blk;
    sc_signal< sc_lv<4> > img2_TSTRB_int;
    sc_signal< sc_logic > regslice_both_img2_strb_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img2_strb_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_user_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img2_TUSER_int;
    sc_signal< sc_logic > regslice_both_img2_user_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img2_user_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_last_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img2_TLAST_int;
    sc_signal< sc_logic > regslice_both_img2_last_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img2_last_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_id_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img2_TID_int;
    sc_signal< sc_logic > regslice_both_img2_id_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img2_id_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_img2_dest_V_U_apdone_blk;
    sc_signal< sc_lv<1> > img2_TDEST_int;
    sc_signal< sc_logic > regslice_both_img2_dest_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_img2_dest_V_U_ack_in;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<2> ap_ST_fsm_state1;
    static const sc_lv<2> ap_ST_fsm_state2;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const int C_M_AXI_C_TARGET_ADDR;
    static const int C_M_AXI_C_USER_VALUE;
    static const int C_M_AXI_C_PROT_VALUE;
    static const int C_M_AXI_C_CACHE_VALUE;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<4> ap_const_lv4_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_abscond_100_fu_185_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_block_state1();
    void thread_ap_rst_n_inv();
    void thread_img1_TDATA_blk_n();
    void thread_img1_TREADY();
    void thread_img1_TREADY_int();
    void thread_img2_TDATA_blk_n();
    void thread_img2_TREADY();
    void thread_img2_TREADY_int();
    void thread_m_axi_c_ARADDR();
    void thread_m_axi_c_ARBURST();
    void thread_m_axi_c_ARCACHE();
    void thread_m_axi_c_ARID();
    void thread_m_axi_c_ARLEN();
    void thread_m_axi_c_ARLOCK();
    void thread_m_axi_c_ARPROT();
    void thread_m_axi_c_ARQOS();
    void thread_m_axi_c_ARREGION();
    void thread_m_axi_c_ARSIZE();
    void thread_m_axi_c_ARUSER();
    void thread_m_axi_c_ARVALID();
    void thread_m_axi_c_AWADDR();
    void thread_m_axi_c_AWBURST();
    void thread_m_axi_c_AWCACHE();
    void thread_m_axi_c_AWID();
    void thread_m_axi_c_AWLEN();
    void thread_m_axi_c_AWLOCK();
    void thread_m_axi_c_AWPROT();
    void thread_m_axi_c_AWQOS();
    void thread_m_axi_c_AWREGION();
    void thread_m_axi_c_AWSIZE();
    void thread_m_axi_c_AWUSER();
    void thread_m_axi_c_AWVALID();
    void thread_m_axi_c_BREADY();
    void thread_m_axi_c_RREADY();
    void thread_m_axi_c_WDATA();
    void thread_m_axi_c_WID();
    void thread_m_axi_c_WLAST();
    void thread_m_axi_c_WSTRB();
    void thread_m_axi_c_WUSER();
    void thread_m_axi_c_WVALID();
    void thread_neg_100_fu_179_p2();
    void thread_sub_ln22_fu_173_p2();
    void thread_y_TDATA_blk_n();
    void thread_y_TDATA_int();
    void thread_y_TVALID();
    void thread_y_TVALID_int();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
