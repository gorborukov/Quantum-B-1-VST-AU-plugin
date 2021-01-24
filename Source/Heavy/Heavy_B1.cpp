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

#include "Heavy_B1.hpp"

#define Context(_c) reinterpret_cast<Heavy_B1 *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_B1_new(double sampleRate) {
    return new Heavy_B1(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_B1_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_B1(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_B1::Heavy_B1(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_uj1Havsk);
  numBytes += sLine_init(&sLine_eHj26nKR);
  numBytes += sPhasor_init(&sPhasor_rfZtVc2y, sampleRate);
  numBytes += sRPole_init(&sRPole_EHeUj3kA);
  numBytes += sPhasor_init(&sPhasor_49Ffpx8t, sampleRate);
  numBytes += cPack_init(&cPack_oWdyDtJF, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cRandom_init(&cRandom_UazWX7TI, -191319218);
  numBytes += cSlice_init(&cSlice_VrPU98bE, 1, 1);
  numBytes += cVar_init_f(&cVar_8imkLu2k, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zCwCKdHu, 2.0f);
  numBytes += cVar_init_f(&cVar_R9jjoj9u, 0.0f);
  numBytes += cIf_init(&cIf_0hyzgXTk, false);
  numBytes += sVarf_init(&sVarf_427qWnkE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_chSZdtQD, 0.0f);
  numBytes += cBinop_init(&cBinop_95Hhz7AX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fSYEDc8W, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_u16GaWa0, 0.0f);
  numBytes += cVar_init_f(&cVar_ByHkyjKs, 0.0f);
  numBytes += cBinop_init(&cBinop_tseXIM8r, 50.0f); // __gte
  numBytes += cIf_init(&cIf_8Uh9nGIJ, false);
  numBytes += cIf_init(&cIf_PRMln7x0, false);
  numBytes += cVar_init_f(&cVar_6Tt7KaRA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HlmeyCgg, 0.0f);
  numBytes += cIf_init(&cIf_69HoHmok, true);
  numBytes += cVar_init_f(&cVar_tkROYVv9, 0.0f);
  numBytes += cIf_init(&cIf_TnGKBeun, false);
  numBytes += cVar_init_f(&cVar_Kh9ZWNZv, 0.0f);
  numBytes += cVar_init_f(&cVar_qZlhbVVA, 0.0f);
  numBytes += cVar_init_f(&cVar_AL07E4e8, 0.0f);
  numBytes += cBinop_init(&cBinop_XxzpcDXr, 1.0f); // __bimod
  numBytes += cDelay_init(this, &cDelay_YGTlBr6z, 0.0f);
  numBytes += cVar_init_f(&cVar_GLcPpbXl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0TVw3DAT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_adhjCVmb, 0.0f);
  numBytes += cVar_init_f(&cVar_3XLskvaG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zBfDpIYz, 0.0f);
  numBytes += cPack_init(&cPack_S6hfViUF, 5, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cIf_init(&cIf_wWHBQQH6, false);
  numBytes += cVar_init_f(&cVar_WJVNQhaF, 1.0f);
  numBytes += cIf_init(&cIf_wxEOf5Ec, false);
  numBytes += cVar_init_f(&cVar_HwORqzwt, 0.0f);
  numBytes += cIf_init(&cIf_U1DA54XZ, false);
  numBytes += cBinop_init(&cBinop_pP9Vkj6Y, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_BHNxZwLP, 0.0f);
  numBytes += cIf_init(&cIf_1NdzquYZ, false);
  numBytes += cVar_init_f(&cVar_aooMPHIH, 0.0f);
  numBytes += cIf_init(&cIf_TYxiUqTy, true);
  numBytes += cVar_init_f(&cVar_sWPTuidC, 1.0f);
  numBytes += cVar_init_f(&cVar_bCHchcYF, 0.0f);
  numBytes += cIf_init(&cIf_j11ScJlJ, false);
  numBytes += cVar_init_f(&cVar_2lA2CD5w, 0.0f);
  numBytes += cIf_init(&cIf_O998vpxW, false);
  numBytes += cVar_init_f(&cVar_RHtcerCB, 0.0f);
  numBytes += cVar_init_f(&cVar_VuO7iZGw, 0.0f);
  numBytes += cVar_init_f(&cVar_5vgWmVTg, 0.0f);
  numBytes += cBinop_init(&cBinop_HtmPQM6z, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_LWMMpoQj, 0.0f);
  numBytes += cVar_init_f(&cVar_S2oi2AZr, 300.0f);
  numBytes += cVar_init_f(&cVar_ov7lLa42, 1.0f);
  numBytes += cVar_init_f(&cVar_S5ciZLVy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TmXufZ8k, 0.0f);
  numBytes += cVar_init_f(&cVar_YQbrqhAS, 0.0f);
  numBytes += cSlice_init(&cSlice_FYtVQIYu, 1, -1);
  numBytes += cSlice_init(&cSlice_KJsOoeKa, 1, 1);
  numBytes += cRandom_init(&cRandom_KKqEEDRT, -967558617);
  numBytes += cVar_init_f(&cVar_oVt6Ruuu, 0.0f);
  numBytes += cVar_init_f(&cVar_VwVdh4Th, 0.0f);
  numBytes += sVarf_init(&sVarf_Lz7Ghxqo, 0.5f, 0.0f, false);
  numBytes += cPack_init(&cPack_W2vT1dEg, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_xF0qaN3Q, 0.0f);
  numBytes += cVar_init_f(&cVar_OxoY7VEe, 0.0f);
  numBytes += cVar_init_f(&cVar_MALI5Xt0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_loIdDoTK, 0.0f);
  numBytes += cVar_init_f(&cVar_44NG8tkT, 0.0f);
  numBytes += cBinop_init(&cBinop_axWRjgP6, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Qq4S8HMB, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_d7tv8Ona, 0.0f);
  numBytes += cIf_init(&cIf_XyKZhTmJ, false);
  numBytes += cBinop_init(&cBinop_ZB1dR3A8, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_EzMDyjvn, 0.0f);
  numBytes += cIf_init(&cIf_Y7tA29TZ, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_B1::~Heavy_B1() {
  cPack_free(&cPack_oWdyDtJF);
  cPack_free(&cPack_S6hfViUF);
  cPack_free(&cPack_W2vT1dEg);
}

HvTable *Heavy_B1::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_B1::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x6C1D372F: { // 1001-bdAddDivider
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4qTGHNZm_sendMessage);
      break;
    }
    case 0x82D58441: { // 1001-bdBaseDivider
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WFY7R6GM_sendMessage);
      break;
    }
    case 0xADF6E53: { // 1001-bdProbability
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Fyu9hNOT_sendMessage);
      break;
    }
    case 0x7BBCF18C: { // 1001-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Jg7OSQ15_sendMessage);
      break;
    }
    case 0x1191161E: { // 1001-bpmTempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GL7V9QY4_sendMessage);
      break;
    }
    case 0x1FB33D63: { // 1001-damp
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bvPPjsLo_sendMessage);
      break;
    }
    case 0x11A5B2CB: { // 1001-decay
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gLGpCtMP_sendMessage);
      break;
    }
    case 0xD5693069: { // 1001-drive
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7wkp9MCO_sendMessage);
      break;
    }
    case 0x6A221B74: { // 1001-randomMode
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VgytAg28_sendMessage);
      break;
    }
    case 0xA4C9EA90: { // 1001-startMachine
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AbQqqYF7_sendMessage);
      break;
    }
    case 0xB2EA2CD: { // 1001-trigDrum
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zuYGFeoI_sendMessage);
      break;
    }
    case 0x59559FD8: { // 1001-tune
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2pNKXWsV_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1dsB90D9_sendMessage);
      break;
    }
    case 0x3C47BA22: { // base_beat
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uLo5ugKo_sendMessage);
      break;
    }
    case 0xD474027C: { // div
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VnCkxkyV_sendMessage);
      break;
    }
    case 0xDAB351DC: { // dly
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2uWitdHX_sendMessage);
      break;
    }
    case 0x1D480570: { // kick
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uPXlbQiy_sendMessage);
      break;
    }
    case 0x79CADF3B: { // multi_beat
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2GXGVFxf_sendMessage);
      break;
    }
    case 0xC4DE63BE: { // random_route
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q9qu64DI_sendMessage);
      break;
    }
    case 0x6FF57CB4: { // start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XU6dLpp4_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_B1::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_B1::cReceive_Q9qu64DI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fMMOSuLz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cPack_oWdyDtJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wrPAus1z_sendMessage(_c, 0, m);
}

void Heavy_B1::cCast_5RwBGTCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1V0DbzTC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ixgp2XJq_sendMessage);
}

void Heavy_B1::cCast_u4A7aenu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lhaSE5qA_sendMessage);
}

void Heavy_B1::cCast_k25ozL9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cUnop_exU20b5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_44NG8tkT, 0, m, &cVar_44NG8tkT_sendMessage);
}

void Heavy_B1::cBinop_DSEzruMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_exU20b5W_sendMessage);
}

void Heavy_B1::cRandom_UazWX7TI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_DSEzruMg_sendMessage);
}

void Heavy_B1::cSwitchcase_fMMOSuLz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VrPU98bE, 0, m, &cSlice_VrPU98bE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_UazWX7TI, 0, m, &cRandom_UazWX7TI_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cSlice_VrPU98bE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_UazWX7TI, 1, m, &cRandom_UazWX7TI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_B1::cCast_1V0DbzTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2rKnmBhV_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_8imkLu2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oVt6Ruuu, 0, m, &cVar_oVt6Ruuu_sendMessage);
}

void Heavy_B1::cCast_0Fm5mxnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zCwCKdHu, 0, m, &cDelay_zCwCKdHu_sendMessage);
}

void Heavy_B1::cSwitchcase_KzXZM9th_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Z0efa3fR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Z0efa3fR_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_zCwCKdHu, 1, m, &cDelay_zCwCKdHu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0Fm5mxnj_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cDelay_zCwCKdHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zCwCKdHu, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aooMPHIH, 0, m, &cVar_aooMPHIH_sendMessage);
}

void Heavy_B1::cMsg_Z0efa3fR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zCwCKdHu, 0, m, &cDelay_zCwCKdHu_sendMessage);
}

void Heavy_B1::cVar_R9jjoj9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Lz7Ghxqo, m);
}

void Heavy_B1::cCast_JmHD5Cja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OxoY7VEe, 0, m, &cVar_OxoY7VEe_sendMessage);
  cMsg_cb9RJGyZ_sendMessage(_c, 0, m);
  cSwitchcase_ht7aCMln_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cCast_o5teGmwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_prgssIbO_sendMessage(_c, 0, m);
}

void Heavy_B1::cSwitchcase_oL5a9Lka_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o5teGmwn_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_B1::cBinop_nMNQLHFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0hyzgXTk, 1, m, &cIf_0hyzgXTk_sendMessage);
}

void Heavy_B1::cIf_0hyzgXTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d4ln8nuy_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JmHD5Cja_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5RwBGTCa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cSend_lpH3hugx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2GXGVFxf_sendMessage(_c, 0, m);
}

void Heavy_B1::cMsg_9qCbk7N1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Kh9ZWNZv, 0, m, &cVar_Kh9ZWNZv_sendMessage);
}

void Heavy_B1::cMsg_wrPAus1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_eHj26nKR, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 2);
  sLine_onMessage(_c, &Context(_c)->sLine_eHj26nKR, 0, m, NULL);
}

void Heavy_B1::cCast_UCv7UiEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZB1dR3A8, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZB1dR3A8_sendMessage);
}

void Heavy_B1::cMsg_qUvHE6MK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 41.2f);
  cVar_onMessage(_c, &Context(_c)->cVar_AL07E4e8, 0, m, &cVar_AL07E4e8_sendMessage);
}

void Heavy_B1::cSend_Y0gSic0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XU6dLpp4_sendMessage(_c, 0, m);
}

void Heavy_B1::cMsg_Zgtc8p6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_69HoHmok, 1, m, &cIf_69HoHmok_sendMessage);
}

void Heavy_B1::cReceive_WFY7R6GM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XxzpcDXr, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_XxzpcDXr_sendMessage);
}

void Heavy_B1::cBinop_Tf0iFZCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3XLskvaG, 0, m, &cVar_3XLskvaG_sendMessage);
}

void Heavy_B1::cReceive_zuYGFeoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9iwpgEfH_sendMessage(_c, 0, m);
}

void Heavy_B1::cCast_rrYOBb2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VwVdh4Th, 1, m, &cVar_VwVdh4Th_sendMessage);
}

void Heavy_B1::cCast_JWcOQPET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3hBekC95_sendMessage(_c, 0, m);
  cMsg_5XOX2VD6_sendMessage(_c, 0, m);
}

void Heavy_B1::cSwitchcase_KO9zCjik_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JWcOQPET_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_B1::cBinop_zCDNGtTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fSYEDc8W, m);
}

void Heavy_B1::cVar_chSZdtQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_95Hhz7AX, HV_BINOP_MULTIPLY, 0, m, &cBinop_95Hhz7AX_sendMessage);
}

void Heavy_B1::cBinop_CWEGSQN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_95Hhz7AX, HV_BINOP_MULTIPLY, 1, m, &cBinop_95Hhz7AX_sendMessage);
}

void Heavy_B1::cMsg_UvkCFxW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CWEGSQN4_sendMessage);
}

void Heavy_B1::cSystem_foEYxnCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UvkCFxW1_sendMessage(_c, 0, m);
}

void Heavy_B1::cMsg_nNoghZEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_foEYxnCN_sendMessage);
}

void Heavy_B1::cBinop_95Hhz7AX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_exoV0Drz_sendMessage);
}

void Heavy_B1::cBinop_exoV0Drz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HIYUWVTU_sendMessage);
}

void Heavy_B1::cBinop_HIYUWVTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zCDNGtTZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_427qWnkE, m);
}

void Heavy_B1::cReceive_Jg7OSQ15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AL07E4e8, 0, m, &cVar_AL07E4e8_sendMessage);
}

void Heavy_B1::cCast_lhaSE5qA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cSend_xoRgfKbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uPXlbQiy_sendMessage(_c, 0, m);
}

void Heavy_B1::cBinop_noCoNdos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PRMln7x0, 1, m, &cIf_PRMln7x0_sendMessage);
}

void Heavy_B1::cCast_02Lt1YNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_u16GaWa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Tf0iFZCS_sendMessage);
}

void Heavy_B1::cVar_ByHkyjKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qTGyA69C_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P7qAnlRE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dgUN4EEO_sendMessage);
}

void Heavy_B1::cBinop_tseXIM8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8Uh9nGIJ, 1, m, &cIf_8Uh9nGIJ_sendMessage);
}

void Heavy_B1::cIf_8Uh9nGIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_iryXiG7d_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_B1::cMsg_SJbI0YfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2umdo06e_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OJlAFlVc_sendMessage);
}

void Heavy_B1::cReceive_gLGpCtMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oVt6Ruuu, 0, m, &cVar_oVt6Ruuu_sendMessage);
}

void Heavy_B1::cCast_gKlGCgPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_48pBLBUw_sendMessage);
  cSwitchcase_wg939qOZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cMsg_2rKnmBhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 2.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_uj1Havsk, 0, m, NULL);
}

void Heavy_B1::cIf_PRMln7x0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_reFvfNDA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cVar_6Tt7KaRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OxoY7VEe, 1, m, &cVar_OxoY7VEe_sendMessage);
}

void Heavy_B1::cMsg_Any1u7sQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HlmeyCgg, 0, m, &cDelay_HlmeyCgg_sendMessage);
}

void Heavy_B1::cCast_kdyuQtXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HlmeyCgg, 0, m, &cDelay_HlmeyCgg_sendMessage);
}

void Heavy_B1::cSwitchcase_k5RjYIsK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Any1u7sQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Any1u7sQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HlmeyCgg, 1, m, &cDelay_HlmeyCgg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kdyuQtXg_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cDelay_HlmeyCgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HlmeyCgg, m);
  cIf_onMessage(_c, &Context(_c)->cIf_U1DA54XZ, 0, m, &cIf_U1DA54XZ_sendMessage);
  cSwitchcase_lzm3Ojkm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cReceive_Fyu9hNOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BHNxZwLP, 0, m, &cVar_BHNxZwLP_sendMessage);
}

void Heavy_B1::cBinop_GDv7GJMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XyKZhTmJ, 1, m, &cIf_XyKZhTmJ_sendMessage);
}

void Heavy_B1::cCast_xwRFIR5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wWHBQQH6, 0, m, &cIf_wWHBQQH6_sendMessage);
}

void Heavy_B1::cBinop_7D7ucuYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1NdzquYZ, 1, m, &cIf_1NdzquYZ_sendMessage);
}

void Heavy_B1::cMsg_OWNueYkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_uj1Havsk, 0, m, NULL);
}

void Heavy_B1::cSend_7vWEinME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q9qu64DI_sendMessage(_c, 0, m);
}

void Heavy_B1::cSend_pBt1l3Hu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2uWitdHX_sendMessage(_c, 0, m);
}

void Heavy_B1::cIf_69HoHmok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cMsg_LrMLgkQd_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cBinop_iy97yNVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Y7tA29TZ, 1, m, &cIf_Y7tA29TZ_sendMessage);
}

void Heavy_B1::cCast_reFvfNDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KjQB5V3T_sendMessage);
  cSend_7vWEinME_sendMessage(_c, 0, m);
}

void Heavy_B1::cReceive_2GXGVFxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5zEAnRj8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xwRFIR5A_sendMessage);
}

void Heavy_B1::cCast_QqBjvVEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_B1::cVar_tkROYVv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AL07E4e8, 0, m, &cVar_AL07E4e8_sendMessage);
}

void Heavy_B1::cIf_TnGKBeun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KumJ5Vhd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cCast_i8KVvJnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VwVdh4Th, 0, m, &cVar_VwVdh4Th_sendMessage);
}

void Heavy_B1::cSwitchcase_SWiiyrj9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i8KVvJnz_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_B1::cVar_Kh9ZWNZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ik1N6eiI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XxzpcDXr, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_XxzpcDXr_sendMessage);
}

void Heavy_B1::cBinop_vZlLBlSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O998vpxW, 1, m, &cIf_O998vpxW_sendMessage);
}

void Heavy_B1::cVar_qZlhbVVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_kRMZ8vXP_sendMessage);
}

void Heavy_B1::cCast_KumJ5Vhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_AL07E4e8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oWdyDtJF, 1, m, &cPack_oWdyDtJF_sendMessage);
}

void Heavy_B1::cBinop_XxzpcDXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_d47zIDZV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cBinop_lOdVDqRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TnGKBeun, 1, m, &cIf_TnGKBeun_sendMessage);
}

void Heavy_B1::cCast_KjQB5V3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_B1::cBinop_FoQzt2UW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sWPTuidC, 1, m, &cVar_sWPTuidC_sendMessage);
}

void Heavy_B1::cMsg_LrMLgkQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.25f);
  sPhasor_onMessage(_c, &Context(_c)->sPhasor_49Ffpx8t, 1, m);
}

void Heavy_B1::cMsg_9hVLgzXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xrwrk48g_sendMessage);
}

void Heavy_B1::cCast_jF1jbPg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wg939qOZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cSwitchcase_1vI0KCKk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jF1jbPg5_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_B1::cMsg_bmskit7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 114.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_5vgWmVTg, 0, m, &cVar_5vgWmVTg_sendMessage);
}

void Heavy_B1::cBinop_HMcru0MO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R9jjoj9u, 0, m, &cVar_R9jjoj9u_sendMessage);
}

void Heavy_B1::cReceive_1dsB90D9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IYqLJfCT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_S2oi2AZr, 0, m, &cVar_S2oi2AZr_sendMessage);
  cMsg_nNoghZEL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_chSZdtQD, 0, m, &cVar_chSZdtQD_sendMessage);
  cMsg_RpUVPLGb_sendMessage(_c, 0, m);
  cMsg_bZaRM7r2_sendMessage(_c, 0, m);
  cMsg_XjlYgJ5I_sendMessage(_c, 0, m);
  cMsg_gsvnhAHY_sendMessage(_c, 0, m);
  cMsg_qUvHE6MK_sendMessage(_c, 0, m);
  cMsg_bmskit7i_sendMessage(_c, 0, m);
  cMsg_SJbI0YfO_sendMessage(_c, 0, m);
}

void Heavy_B1::cSwitchcase_ht7aCMln_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WiVsbvTn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WiVsbvTn_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_YGTlBr6z, 1, m, &cDelay_YGTlBr6z_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZBXd2f6w_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cCast_ZBXd2f6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YGTlBr6z, 0, m, &cDelay_YGTlBr6z_sendMessage);
}

void Heavy_B1::cMsg_WiVsbvTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YGTlBr6z, 0, m, &cDelay_YGTlBr6z_sendMessage);
}

void Heavy_B1::cDelay_YGTlBr6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YGTlBr6z, m);
  cMsg_Zgtc8p6g_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_GLcPpbXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pBt1l3Hu_sendMessage(_c, 0, m);
}

void Heavy_B1::cDelay_0TVw3DAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0TVw3DAT, m);
  cIf_onMessage(_c, &Context(_c)->cIf_O998vpxW, 0, m, &cIf_O998vpxW_sendMessage);
  cSwitchcase_Q5tW1ipt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cCast_Y3S9R6OL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0TVw3DAT, 0, m, &cDelay_0TVw3DAT_sendMessage);
}

void Heavy_B1::cSwitchcase_dWQGx1Q0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ItygN1N9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ItygN1N9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_0TVw3DAT, 1, m, &cDelay_0TVw3DAT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3S9R6OL_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cMsg_ItygN1N9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0TVw3DAT, 0, m, &cDelay_0TVw3DAT_sendMessage);
}

void Heavy_B1::cDelay_adhjCVmb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_adhjCVmb, m);
  cIf_onMessage(_c, &Context(_c)->cIf_XyKZhTmJ, 0, m, &cIf_XyKZhTmJ_sendMessage);
}

void Heavy_B1::cSwitchcase_oEj4Fl9u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ffwBu5k5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ffwBu5k5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_adhjCVmb, 1, m, &cDelay_adhjCVmb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lylT1F6T_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cCast_lylT1F6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_adhjCVmb, 0, m, &cDelay_adhjCVmb_sendMessage);
}

void Heavy_B1::cMsg_ffwBu5k5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_adhjCVmb, 0, m, &cDelay_adhjCVmb_sendMessage);
}

void Heavy_B1::cSend_SlTr7fax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uPXlbQiy_sendMessage(_c, 0, m);
}

void Heavy_B1::cMsg_XjlYgJ5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.47f);
  cVar_onMessage(_c, &Context(_c)->cVar_oVt6Ruuu, 0, m, &cVar_oVt6Ruuu_sendMessage);
}

void Heavy_B1::cReceive_VnCkxkyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 3.0f, 0, m, &cBinop_iy97yNVh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 2.0f, 0, m, &cBinop_lOdVDqRm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 1.0f, 0, m, &cBinop_buemBbSE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 4.0f, 0, m, &cBinop_9k3qbiCH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 5.0f, 0, m, &cBinop_vZlLBlSb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 6.0f, 0, m, &cBinop_7D7ucuYh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 6.0f, 0, m, &cBinop_GDv7GJMt_sendMessage);
}

void Heavy_B1::cVar_3XLskvaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pP9Vkj6Y, HV_BINOP_DIVIDE, 1, m, &cBinop_pP9Vkj6Y_sendMessage);
  cSend_YI3RTO1z_sendMessage(_c, 0, m);
}

void Heavy_B1::cCast_zSRLVHCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d4fqGiL9_sendMessage(_c, 0, m);
}

void Heavy_B1::cSwitchcase_d47zIDZV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zSRLVHCW_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_B1::cCast_Ixgp2XJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KzXZM9th_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cCast_7fJZHxj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zBfDpIYz, 0, m, &cDelay_zBfDpIYz_sendMessage);
}

void Heavy_B1::cSwitchcase_Q5tW1ipt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_dYimtKp7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_dYimtKp7_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_zBfDpIYz, 1, m, &cDelay_zBfDpIYz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7fJZHxj2_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cMsg_dYimtKp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zBfDpIYz, 0, m, &cDelay_zBfDpIYz_sendMessage);
}

void Heavy_B1::cDelay_zBfDpIYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zBfDpIYz, m);
  cIf_onMessage(_c, &Context(_c)->cIf_1NdzquYZ, 0, m, &cIf_1NdzquYZ_sendMessage);
  cSwitchcase_oEj4Fl9u_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cReceive_2uWitdHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HlmeyCgg, 1, m, &cDelay_HlmeyCgg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d7tv8Ona, 1, m, &cDelay_d7tv8Ona_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmXufZ8k, 1, m, &cDelay_TmXufZ8k_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_loIdDoTK, 1, m, &cDelay_loIdDoTK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0TVw3DAT, 1, m, &cDelay_0TVw3DAT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zBfDpIYz, 1, m, &cDelay_zBfDpIYz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_adhjCVmb, 1, m, &cDelay_adhjCVmb_sendMessage);
}

void Heavy_B1::cPack_S6hfViUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8bVV4rcS_sendMessage(_c, 0, m);
}

void Heavy_B1::cIf_wWHBQQH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gKlGCgPi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cCast_d4ln8nuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_69HoHmok, 0, m, &cIf_69HoHmok_sendMessage);
}

void Heavy_B1::cVar_WJVNQhaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Wh8qjZpj_sendMessage);
  cSwitchcase_NKsDWuyq_onMessage(_c, NULL, 0, m, NULL);
  cSend_Y0gSic0R_sendMessage(_c, 0, m);
}

void Heavy_B1::cBinop_Wh8qjZpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WJVNQhaF, 1, m, &cVar_WJVNQhaF_sendMessage);
}

void Heavy_B1::cIf_wxEOf5Ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8uY1EJG6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cCast_P7qAnlRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VuO7iZGw, 0, m, &cVar_VuO7iZGw_sendMessage);
}

void Heavy_B1::cVar_HwORqzwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j11ScJlJ, 1, m, &cIf_j11ScJlJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_j11ScJlJ, 0, m, &cIf_j11ScJlJ_sendMessage);
}

void Heavy_B1::cReceive_4qTGHNZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u16GaWa0, 0, m, &cVar_u16GaWa0_sendMessage);
}

void Heavy_B1::cIf_U1DA54XZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oLwXpVUJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cBinop_pP9Vkj6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GLcPpbXl, 0, m, &cVar_GLcPpbXl_sendMessage);
}

void Heavy_B1::cVar_BHNxZwLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tseXIM8r, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_tseXIM8r_sendMessage);
}

void Heavy_B1::cMsg_cb9RJGyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_69HoHmok, 1, m, &cIf_69HoHmok_sendMessage);
}

void Heavy_B1::cCast_qOajqmbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cBinop_9k3qbiCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wxEOf5Ec, 1, m, &cIf_wxEOf5Ec_sendMessage);
}

void Heavy_B1::cIf_1NdzquYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qOajqmbV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cVar_aooMPHIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W2vT1dEg, 0, m, &cPack_W2vT1dEg_sendMessage);
}

void Heavy_B1::cMsg_gsvnhAHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 189.2f);
  cVar_onMessage(_c, &Context(_c)->cVar_6Tt7KaRA, 0, m, &cVar_6Tt7KaRA_sendMessage);
}

void Heavy_B1::cCast_dgUN4EEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EzMDyjvn, 0, m, &cVar_EzMDyjvn_sendMessage);
}

void Heavy_B1::cCast_dRxVQhYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3pDK8DGW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u4A7aenu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sWPTuidC, 0, m, &cVar_sWPTuidC_sendMessage);
}

void Heavy_B1::cReceive_bvPPjsLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5vgWmVTg, 0, m, &cVar_5vgWmVTg_sendMessage);
}

void Heavy_B1::cBinop_jRHPNdnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oL5a9Lka_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_KO9zCjik_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_S5ciZLVy, 0, m, &cVar_S5ciZLVy_sendMessage);
}

void Heavy_B1::cSend_8bVV4rcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_B1::cMsg_9iwpgEfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_SlTr7fax_sendMessage(_c, 0, m);
}

void Heavy_B1::cReceive_GL7V9QY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MALI5Xt0, 0, m, &cVar_MALI5Xt0_sendMessage);
}

void Heavy_B1::cBinop_buemBbSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_U1DA54XZ, 1, m, &cIf_U1DA54XZ_sendMessage);
}

void Heavy_B1::cSend_WSoyFNV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uLo5ugKo_sendMessage(_c, 0, m);
}

void Heavy_B1::cMsg_iryXiG7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_xoRgfKbu_sendMessage(_c, 0, m);
}

void Heavy_B1::cReceive_uLo5ugKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Kh9ZWNZv, 0, m, &cVar_Kh9ZWNZv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dRxVQhYF_sendMessage);
}

void Heavy_B1::cMsg_iQKJ0JPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 36.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_S6hfViUF, 0, m, &cPack_S6hfViUF_sendMessage);
  cPrint_onMessage(_c, m, "0");
}

void Heavy_B1::cReceive_2pNKXWsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6Tt7KaRA, 0, m, &cVar_6Tt7KaRA_sendMessage);
}

void Heavy_B1::cCast_2umdo06e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_noCoNdos_sendMessage);
}

void Heavy_B1::cIf_TYxiUqTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_g0cq2HxK_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_L4Xo4GXe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cVar_sWPTuidC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_alHPyiSS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TYxiUqTy, 0, m, &cIf_TYxiUqTy_sendMessage);
}

void Heavy_B1::cUnop_g0cq2HxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FoQzt2UW_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_jRHPNdnx_sendMessage);
}

void Heavy_B1::cBinop_alHPyiSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TYxiUqTy, 1, m, &cIf_TYxiUqTy_sendMessage);
}

void Heavy_B1::cUnop_L4Xo4GXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FoQzt2UW_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_jRHPNdnx_sendMessage);
}

void Heavy_B1::cVar_bCHchcYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6Tt7KaRA, 0, m, &cVar_6Tt7KaRA_sendMessage);
}

void Heavy_B1::cIf_j11ScJlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cMsg_9qCbk7N1_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cReceive_uPXlbQiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0001f, 0, m, &cBinop_nMNQLHFN_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_0hyzgXTk, 0, m, &cIf_0hyzgXTk_sendMessage);
  cMsg_iQKJ0JPi_sendMessage(_c, 0, m);
  cMsg_y5CDLS23_sendMessage(_c, 0, m);
}

void Heavy_B1::cSend_YI3RTO1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VnCkxkyV_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_2lA2CD5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pP9Vkj6Y, HV_BINOP_DIVIDE, 0, m, &cBinop_pP9Vkj6Y_sendMessage);
}

void Heavy_B1::cIf_O998vpxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_02Lt1YNO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cVar_RHtcerCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YQbrqhAS, 0, m, &cVar_YQbrqhAS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HMcru0MO_sendMessage);
}

void Heavy_B1::cCast_8uY1EJG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_VuO7iZGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rrYOBb2Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QqBjvVEK_sendMessage);
}

void Heavy_B1::cReceive_XU6dLpp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HwORqzwt, 0, m, &cVar_HwORqzwt_sendMessage);
}

void Heavy_B1::cMsg_bZaRM7r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_BHNxZwLP, 0, m, &cVar_BHNxZwLP_sendMessage);
}

void Heavy_B1::cReceive_VgytAg28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ov7lLa42, 0, m, &cVar_ov7lLa42_sendMessage);
}

void Heavy_B1::cCast_5zEAnRj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PRMln7x0, 0, m, &cIf_PRMln7x0_sendMessage);
}

void Heavy_B1::cCast_qTGyA69C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qZlhbVVA, 0, m, &cVar_qZlhbVVA_sendMessage);
}

void Heavy_B1::cVar_5vgWmVTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oWdyDtJF, 2, m, &cPack_oWdyDtJF_sendMessage);
}

void Heavy_B1::cMsg_aCjUOas4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LWMMpoQj, 0, m, &cDelay_LWMMpoQj_sendMessage);
}

void Heavy_B1::cCast_fzsE09gL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aCjUOas4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LWMMpoQj, 0, m, &cDelay_LWMMpoQj_sendMessage);
  cSend_WSoyFNV9_sendMessage(_c, 0, m);
}

void Heavy_B1::cBinop_HtmPQM6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_DrGPA2kz_sendMessage);
}

void Heavy_B1::cSystem_WqRF6wcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gJSKMQIj_sendMessage);
}

void Heavy_B1::cMsg_IYqLJfCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WqRF6wcn_sendMessage);
}

void Heavy_B1::cDelay_LWMMpoQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LWMMpoQj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LWMMpoQj, 0, m, &cDelay_LWMMpoQj_sendMessage);
  cSend_WSoyFNV9_sendMessage(_c, 0, m);
}

void Heavy_B1::cSwitchcase_NKsDWuyq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_aCjUOas4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_aCjUOas4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fzsE09gL_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cBinop_DrGPA2kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LWMMpoQj, 2, m, &cDelay_LWMMpoQj_sendMessage);
}

void Heavy_B1::cVar_S2oi2AZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtmPQM6z, HV_BINOP_MULTIPLY, 0, m, &cBinop_HtmPQM6z_sendMessage);
}

void Heavy_B1::cBinop_gJSKMQIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtmPQM6z, HV_BINOP_MULTIPLY, 1, m, &cBinop_HtmPQM6z_sendMessage);
}

void Heavy_B1::cBinop_M9hjqAf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ov7lLa42, 1, m, &cVar_ov7lLa42_sendMessage);
}

void Heavy_B1::cVar_ov7lLa42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_M9hjqAf7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2umdo06e_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OJlAFlVc_sendMessage);
}

void Heavy_B1::cCast_OJlAFlVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wWHBQQH6, 1, m, &cIf_wWHBQQH6_sendMessage);
}

void Heavy_B1::cReceive_AbQqqYF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WJVNQhaF, 0, m, &cVar_WJVNQhaF_sendMessage);
}

void Heavy_B1::cBinop_kRMZ8vXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EzMDyjvn, 1, m, &cVar_EzMDyjvn_sendMessage);
}

void Heavy_B1::cReceive_7wkp9MCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YQbrqhAS, 0, m, &cVar_YQbrqhAS_sendMessage);
}

void Heavy_B1::cVar_S5ciZLVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_B1::cCast_aSyxoreD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmXufZ8k, 0, m, &cDelay_TmXufZ8k_sendMessage);
}

void Heavy_B1::cDelay_TmXufZ8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TmXufZ8k, m);
  cIf_onMessage(_c, &Context(_c)->cIf_Y7tA29TZ, 0, m, &cIf_Y7tA29TZ_sendMessage);
  cSwitchcase_NMV172NP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cSwitchcase_ttNRrGW6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_2lLpZg9C_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_2lLpZg9C_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TmXufZ8k, 1, m, &cDelay_TmXufZ8k_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aSyxoreD_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cMsg_2lLpZg9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmXufZ8k, 0, m, &cDelay_TmXufZ8k_sendMessage);
}

void Heavy_B1::cBinop_Ik1N6eiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Kh9ZWNZv, 1, m, &cVar_Kh9ZWNZv_sendMessage);
}

void Heavy_B1::cBinop_aO3RHwfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aooMPHIH, 1, m, &cVar_aooMPHIH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YGTlBr6z, 1, m, &cDelay_YGTlBr6z_sendMessage);
}

void Heavy_B1::cVar_YQbrqhAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_chSZdtQD, 0, m, &cVar_chSZdtQD_sendMessage);
}

void Heavy_B1::cSlice_FYtVQIYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_B1::cSwitchcase_qIIRGzuZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FYtVQIYu, 0, m, &cSlice_FYtVQIYu_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_2lA2CD5w, 0, m, &cVar_2lA2CD5w_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cSwitchcase_wg939qOZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KJsOoeKa, 0, m, &cSlice_KJsOoeKa_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KKqEEDRT, 0, m, &cRandom_KKqEEDRT_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cBinop_eqXSgi1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uVeddOkc_sendMessage);
}

void Heavy_B1::cUnop_uVeddOkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ByHkyjKs, 0, m, &cVar_ByHkyjKs_sendMessage);
}

void Heavy_B1::cSlice_KJsOoeKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KKqEEDRT, 1, m, &cRandom_KKqEEDRT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_B1::cRandom_KKqEEDRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_eqXSgi1y_sendMessage);
}

void Heavy_B1::cCast_oLwXpVUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_oVt6Ruuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UCv7UiEc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KTDoQmGD_sendMessage);
}

void Heavy_B1::cVar_VwVdh4Th_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_44NG8tkT, 0, m, &cVar_44NG8tkT_sendMessage);
}

void Heavy_B1::cPack_W2vT1dEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OWNueYkI_sendMessage(_c, 0, m);
}

void Heavy_B1::cVar_xF0qaN3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5vgWmVTg, 0, m, &cVar_5vgWmVTg_sendMessage);
}

void Heavy_B1::cVar_OxoY7VEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oWdyDtJF, 0, m, &cPack_oWdyDtJF_sendMessage);
}

void Heavy_B1::cVar_MALI5Xt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9hVLgzXi_sendMessage(_c, 0, m);
}

void Heavy_B1::cCast_oLvTbQyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_loIdDoTK, 0, m, &cDelay_loIdDoTK_sendMessage);
}

void Heavy_B1::cDelay_loIdDoTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_loIdDoTK, m);
  cIf_onMessage(_c, &Context(_c)->cIf_wxEOf5Ec, 0, m, &cIf_wxEOf5Ec_sendMessage);
  cSwitchcase_dWQGx1Q0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cSwitchcase_NMV172NP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TUY8ft1D_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TUY8ft1D_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_loIdDoTK, 1, m, &cDelay_loIdDoTK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oLvTbQyZ_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cMsg_TUY8ft1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_loIdDoTK, 0, m, &cDelay_loIdDoTK_sendMessage);
}

void Heavy_B1::cVar_44NG8tkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tseXIM8r, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_tseXIM8r_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8Uh9nGIJ, 0, m, &cIf_8Uh9nGIJ_sendMessage);
}

void Heavy_B1::cMsg_prgssIbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_t6OOCHRL_sendMessage);
}

void Heavy_B1::cSystem_t6OOCHRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_axWRjgP6, HV_BINOP_SUBTRACT, 1, m, &cBinop_axWRjgP6_sendMessage);
}

void Heavy_B1::cBinop_6hfa7H2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qq4S8HMB, HV_BINOP_DIVIDE, 1, m, &cBinop_Qq4S8HMB_sendMessage);
}

void Heavy_B1::cBinop_axWRjgP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qq4S8HMB, HV_BINOP_DIVIDE, 0, m, &cBinop_Qq4S8HMB_sendMessage);
}

void Heavy_B1::cSystem_0pPVJx5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6hfa7H2d_sendMessage);
}

void Heavy_B1::cMsg_3hBekC95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0pPVJx5w_sendMessage);
}

void Heavy_B1::cBinop_Qq4S8HMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qIIRGzuZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cMsg_5XOX2VD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YDYsY0YJ_sendMessage);
}

void Heavy_B1::cSystem_YDYsY0YJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_axWRjgP6, HV_BINOP_SUBTRACT, 0, m, &cBinop_axWRjgP6_sendMessage);
}

void Heavy_B1::cCast_3pDK8DGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_k5RjYIsK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cCast_L9DiyU1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_d7tv8Ona, 0, m, &cDelay_d7tv8Ona_sendMessage);
}

void Heavy_B1::cMsg_FUv7JQBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_d7tv8Ona, 0, m, &cDelay_d7tv8Ona_sendMessage);
}

void Heavy_B1::cDelay_d7tv8Ona_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_d7tv8Ona, m);
  cIf_onMessage(_c, &Context(_c)->cIf_TnGKBeun, 0, m, &cIf_TnGKBeun_sendMessage);
  cSwitchcase_ttNRrGW6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cSwitchcase_lzm3Ojkm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_FUv7JQBl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_FUv7JQBl_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_d7tv8Ona, 1, m, &cDelay_d7tv8Ona_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L9DiyU1x_sendMessage);
      break;
    }
  }
}

void Heavy_B1::cCast_2Cl12A1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lpH3hugx_sendMessage(_c, 0, m);
}

void Heavy_B1::cMsg_RpUVPLGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 120.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_MALI5Xt0, 0, m, &cVar_MALI5Xt0_sendMessage);
}

void Heavy_B1::cMsg_y5CDLS23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_S6hfViUF, 1, m, &cPack_S6hfViUF_sendMessage);
}

void Heavy_B1::cIf_XyKZhTmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2Cl12A1t_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_B1::cBinop_xrwrk48g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S2oi2AZr, 0, m, &cVar_S2oi2AZr_sendMessage);
}

void Heavy_B1::cBinop_ZB1dR3A8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_aO3RHwfB_sendMessage);
}

void Heavy_B1::cCast_48pBLBUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_B1::cVar_EzMDyjvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1vI0KCKk_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_SWiiyrj9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_B1::cMsg_d4fqGiL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_xoRgfKbu_sendMessage(_c, 0, m);
}

void Heavy_B1::cCast_KTDoQmGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZB1dR3A8, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZB1dR3A8_sendMessage);
}

void Heavy_B1::cIf_Y7tA29TZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k25ozL9j_sendMessage);
      break;
    }
    default: return;
  }
}




/*
 * Context Process Implementation
 */

int Heavy_B1::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_line_f(&sLine_uj1Havsk, VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_eHj26nKR, VOf(Bf1));
    __hv_phasor_f(&sPhasor_rfZtVc2y, VIf(Bf1), VOf(Bf2));
    __hv_varread_f(&sVarf_427qWnkE, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_fSYEDc8W, VOf(Bf2));
    __hv_rpole_f(&sRPole_EHeUj3kA, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Lz7Ghxqo, VOf(Bf3));
    __hv_phasor_f(&sPhasor_49Ffpx8t, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_B1::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_B1::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
