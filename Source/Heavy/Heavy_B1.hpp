/**
 * Copyright (c) 2020 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_B1_HPP_
#define _HEAVY_CONTEXT_B1_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlPrint.h"
#include "HvControlIf.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlVar.h"
#include "HvSignalRPole.h"
#include "HvControlRandom.h"
#include "HvMath.h"
#include "HvControlPack.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"

class Heavy_B1 : public HeavyContext {

 public:
  Heavy_B1(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_B1();

  const char *getName() override { return "B1"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    
    struct Out {
      enum ParameterOut : hv_uint32_t {
        __HV_NOTEOUT = 0xD1D4AC2, // __hv_noteout
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cReceive_Q9qu64DI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_oWdyDtJF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5RwBGTCa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_u4A7aenu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_k25ozL9j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_exU20b5W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DSEzruMg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_UazWX7TI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fMMOSuLz_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_VrPU98bE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1V0DbzTC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8imkLu2k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0Fm5mxnj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KzXZM9th_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_zCwCKdHu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Z0efa3fR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_R9jjoj9u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JmHD5Cja_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o5teGmwn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oL5a9Lka_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_nMNQLHFN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_0hyzgXTk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_lpH3hugx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9qCbk7N1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wrPAus1z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UCv7UiEc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qUvHE6MK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Y0gSic0R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Zgtc8p6g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_WFY7R6GM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Tf0iFZCS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zuYGFeoI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rrYOBb2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JWcOQPET_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KO9zCjik_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_zCDNGtTZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_chSZdtQD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CWEGSQN4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UvkCFxW1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_foEYxnCN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nNoghZEL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_95Hhz7AX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_exoV0Drz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HIYUWVTU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Jg7OSQ15_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lhaSE5qA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_xoRgfKbu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_noCoNdos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_02Lt1YNO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_u16GaWa0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ByHkyjKs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tseXIM8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_8Uh9nGIJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SJbI0YfO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_gLGpCtMP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gKlGCgPi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2rKnmBhV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_PRMln7x0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6Tt7KaRA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Any1u7sQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kdyuQtXg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_k5RjYIsK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_HlmeyCgg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Fyu9hNOT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GDv7GJMt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xwRFIR5A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7D7ucuYh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OWNueYkI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_7vWEinME_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_pBt1l3Hu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_69HoHmok_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iy97yNVh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_reFvfNDA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2GXGVFxf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QqBjvVEK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tkROYVv9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_TnGKBeun_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i8KVvJnz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SWiiyrj9_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_Kh9ZWNZv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vZlLBlSb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qZlhbVVA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KumJ5Vhd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AL07E4e8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XxzpcDXr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lOdVDqRm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KjQB5V3T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FoQzt2UW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LrMLgkQd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9hVLgzXi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jF1jbPg5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1vI0KCKk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_bmskit7i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HMcru0MO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1dsB90D9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ht7aCMln_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ZBXd2f6w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WiVsbvTn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_YGTlBr6z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GLcPpbXl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_0TVw3DAT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Y3S9R6OL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dWQGx1Q0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_ItygN1N9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_adhjCVmb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oEj4Fl9u_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_lylT1F6T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ffwBu5k5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_SlTr7fax_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XjlYgJ5I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VnCkxkyV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3XLskvaG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zSRLVHCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_d47zIDZV_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Ixgp2XJq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7fJZHxj2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Q5tW1ipt_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_dYimtKp7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zBfDpIYz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2uWitdHX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_S6hfViUF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_wWHBQQH6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d4ln8nuy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WJVNQhaF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wh8qjZpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_wxEOf5Ec_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P7qAnlRE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HwORqzwt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4qTGHNZm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_U1DA54XZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pP9Vkj6Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BHNxZwLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cb9RJGyZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qOajqmbV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9k3qbiCH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_1NdzquYZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aooMPHIH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gsvnhAHY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dgUN4EEO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dRxVQhYF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bvPPjsLo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jRHPNdnx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_8bVV4rcS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9iwpgEfH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GL7V9QY4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_buemBbSE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_WSoyFNV9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iryXiG7d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uLo5ugKo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iQKJ0JPi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2pNKXWsV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2umdo06e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_TYxiUqTy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sWPTuidC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_g0cq2HxK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_alHPyiSS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_L4Xo4GXe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bCHchcYF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_j11ScJlJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uPXlbQiy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_YI3RTO1z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2lA2CD5w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_O998vpxW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RHtcerCB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8uY1EJG6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VuO7iZGw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_XU6dLpp4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bZaRM7r2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VgytAg28_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5zEAnRj8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qTGyA69C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5vgWmVTg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aCjUOas4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fzsE09gL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HtmPQM6z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WqRF6wcn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IYqLJfCT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_LWMMpoQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_NKsDWuyq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_DrGPA2kz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_S2oi2AZr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gJSKMQIj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M9hjqAf7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ov7lLa42_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OJlAFlVc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_AbQqqYF7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kRMZ8vXP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7wkp9MCO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_S5ciZLVy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aSyxoreD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_TmXufZ8k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ttNRrGW6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_2lLpZg9C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ik1N6eiI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aO3RHwfB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YQbrqhAS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FYtVQIYu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qIIRGzuZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSwitchcase_wg939qOZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_eqXSgi1y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_uVeddOkc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KJsOoeKa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_KKqEEDRT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oLwXpVUJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oVt6Ruuu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VwVdh4Th_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_W2vT1dEg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xF0qaN3Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OxoY7VEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MALI5Xt0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oLvTbQyZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_loIdDoTK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_NMV172NP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_TUY8ft1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_44NG8tkT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_prgssIbO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_t6OOCHRL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6hfa7H2d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_axWRjgP6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0pPVJx5w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3hBekC95_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qq4S8HMB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5XOX2VD6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YDYsY0YJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3pDK8DGW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L9DiyU1x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FUv7JQBl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_d7tv8Ona_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_lzm3Ojkm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_2Cl12A1t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RpUVPLGb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_y5CDLS23_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_XyKZhTmJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xrwrk48g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZB1dR3A8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_48pBLBUw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EzMDyjvn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d4fqGiL9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KTDoQmGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Y7tA29TZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_uj1Havsk;
  SignalLine sLine_eHj26nKR;
  SignalPhasor sPhasor_rfZtVc2y;
  SignalRPole sRPole_EHeUj3kA;
  SignalPhasor sPhasor_49Ffpx8t;
  ControlPack cPack_oWdyDtJF;
  ControlBinop cBinop_DSEzruMg;
  ControlRandom cRandom_UazWX7TI;
  ControlSlice cSlice_VrPU98bE;
  ControlVar cVar_8imkLu2k;
  ControlDelay cDelay_zCwCKdHu;
  ControlVar cVar_R9jjoj9u;
  ControlBinop cBinop_nMNQLHFN;
  ControlIf cIf_0hyzgXTk;
  ControlBinop cBinop_Tf0iFZCS;
  SignalVarf sVarf_427qWnkE;
  ControlBinop cBinop_zCDNGtTZ;
  ControlVar cVar_chSZdtQD;
  ControlBinop cBinop_CWEGSQN4;
  ControlBinop cBinop_95Hhz7AX;
  SignalVarf sVarf_fSYEDc8W;
  ControlBinop cBinop_exoV0Drz;
  ControlBinop cBinop_HIYUWVTU;
  ControlBinop cBinop_noCoNdos;
  ControlVar cVar_u16GaWa0;
  ControlVar cVar_ByHkyjKs;
  ControlBinop cBinop_tseXIM8r;
  ControlIf cIf_8Uh9nGIJ;
  ControlIf cIf_PRMln7x0;
  ControlVar cVar_6Tt7KaRA;
  ControlDelay cDelay_HlmeyCgg;
  ControlBinop cBinop_GDv7GJMt;
  ControlBinop cBinop_7D7ucuYh;
  ControlIf cIf_69HoHmok;
  ControlBinop cBinop_iy97yNVh;
  ControlVar cVar_tkROYVv9;
  ControlIf cIf_TnGKBeun;
  ControlVar cVar_Kh9ZWNZv;
  ControlBinop cBinop_vZlLBlSb;
  ControlVar cVar_qZlhbVVA;
  ControlVar cVar_AL07E4e8;
  ControlBinop cBinop_XxzpcDXr;
  ControlBinop cBinop_lOdVDqRm;
  ControlBinop cBinop_FoQzt2UW;
  ControlBinop cBinop_HMcru0MO;
  ControlDelay cDelay_YGTlBr6z;
  ControlVar cVar_GLcPpbXl;
  ControlDelay cDelay_0TVw3DAT;
  ControlDelay cDelay_adhjCVmb;
  ControlVar cVar_3XLskvaG;
  ControlDelay cDelay_zBfDpIYz;
  ControlPack cPack_S6hfViUF;
  ControlIf cIf_wWHBQQH6;
  ControlVar cVar_WJVNQhaF;
  ControlBinop cBinop_Wh8qjZpj;
  ControlIf cIf_wxEOf5Ec;
  ControlVar cVar_HwORqzwt;
  ControlIf cIf_U1DA54XZ;
  ControlBinop cBinop_pP9Vkj6Y;
  ControlVar cVar_BHNxZwLP;
  ControlBinop cBinop_9k3qbiCH;
  ControlIf cIf_1NdzquYZ;
  ControlVar cVar_aooMPHIH;
  ControlBinop cBinop_buemBbSE;
  ControlIf cIf_TYxiUqTy;
  ControlVar cVar_sWPTuidC;
  ControlBinop cBinop_alHPyiSS;
  ControlVar cVar_bCHchcYF;
  ControlIf cIf_j11ScJlJ;
  ControlVar cVar_2lA2CD5w;
  ControlIf cIf_O998vpxW;
  ControlVar cVar_RHtcerCB;
  ControlVar cVar_VuO7iZGw;
  ControlVar cVar_5vgWmVTg;
  ControlBinop cBinop_HtmPQM6z;
  ControlDelay cDelay_LWMMpoQj;
  ControlBinop cBinop_DrGPA2kz;
  ControlVar cVar_S2oi2AZr;
  ControlBinop cBinop_gJSKMQIj;
  ControlBinop cBinop_M9hjqAf7;
  ControlVar cVar_ov7lLa42;
  ControlBinop cBinop_kRMZ8vXP;
  ControlVar cVar_S5ciZLVy;
  ControlDelay cDelay_TmXufZ8k;
  ControlBinop cBinop_Ik1N6eiI;
  ControlBinop cBinop_aO3RHwfB;
  ControlVar cVar_YQbrqhAS;
  ControlSlice cSlice_FYtVQIYu;
  ControlBinop cBinop_eqXSgi1y;
  ControlSlice cSlice_KJsOoeKa;
  ControlRandom cRandom_KKqEEDRT;
  ControlVar cVar_oVt6Ruuu;
  ControlVar cVar_VwVdh4Th;
  SignalVarf sVarf_Lz7Ghxqo;
  ControlPack cPack_W2vT1dEg;
  ControlVar cVar_xF0qaN3Q;
  ControlVar cVar_OxoY7VEe;
  ControlVar cVar_MALI5Xt0;
  ControlDelay cDelay_loIdDoTK;
  ControlVar cVar_44NG8tkT;
  ControlBinop cBinop_6hfa7H2d;
  ControlBinop cBinop_axWRjgP6;
  ControlBinop cBinop_Qq4S8HMB;
  ControlDelay cDelay_d7tv8Ona;
  ControlIf cIf_XyKZhTmJ;
  ControlBinop cBinop_xrwrk48g;
  ControlBinop cBinop_ZB1dR3A8;
  ControlVar cVar_EzMDyjvn;
  ControlIf cIf_Y7tA29TZ;
};

#endif // _HEAVY_CONTEXT_B1_HPP_
