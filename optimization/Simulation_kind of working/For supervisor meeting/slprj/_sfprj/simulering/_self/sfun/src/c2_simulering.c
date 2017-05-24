/* Include files */

#include "simulering_sfun.h"
#include "c2_simulering.h"
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simulering_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[54] = { "Ts", "t_h", "t_h_2", "u_hp",
  "u_hp1", "u_hp2", "data", "Gamma", "Omega", "Phi", "Pi", "Psi", "Theta",
  "constant_dist", "Data_OD", "d_hp", "delta_p_0", "q_bar_p_hp", "y_low",
  "y_high", "y_bar", "y1", "y2", "L_y", "x_low", "x_high", "x_bar",
  "delta_p_wt_1", "delta_p_wt_2", "U_bar", "U_bar_hp", "u_low", "u_high", "R",
  "R1", "f", "A", "b", "lb", "ub", "func", "options", "fval", "exitflag",
  "output", "nargin", "nargout", "Lambda_A", "Lambda_B", "Lambda_C", "t_clock",
  "x", "u_old", "u" };

static emlrtRTEInfo c2_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 98,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 124,/* lineNo */
  10,                                  /* colNo */
  "MPC/MPC",                           /* fName */
  "#simulering:74"                     /* pName */
};

/* Function Declarations */
static void initialize_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance);
static void initialize_params_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance);
static void enable_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance);
static void disable_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_simulering(SFc2_simuleringInstanceStruct *
  chartInstance);
static void set_sim_state_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance);
static void sf_gateway_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance);
static void mdl_start_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance);
static void c2_chartstep_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance);
static void initSimStructsc2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const char_T *c2_identifier, real_T c2_b_y[2]);
static void c2_b_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[96]);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [4608]);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[48]);
static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_eig(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_g_A
                   [2304], creal_T c2_V[48]);
static boolean_T c2_anyNonFinite(SFc2_simuleringInstanceStruct *chartInstance,
  real_T c2_b_x[2304]);
static boolean_T c2_ishermitian(SFc2_simuleringInstanceStruct *chartInstance,
  real_T c2_g_A[2304]);
static void c2_schur(SFc2_simuleringInstanceStruct *chartInstance, real_T
                     c2_g_A[2304], creal_T c2_V[2304]);
static void c2_triu(SFc2_simuleringInstanceStruct *chartInstance, creal_T
                    c2_b_x[2304], creal_T c2_c_x[2304]);
static void c2_check_forloop_overflow_error(SFc2_simuleringInstanceStruct
  *chartInstance, boolean_T c2_overflow);
static void c2_xgehrd(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_a
                      [2304], real_T c2_b_a[2304]);
static void c2_xzlarfg(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, real_T c2_alpha1, real_T c2_b_x[2304], int32_T c2_ix0, real_T
  *c2_b_alpha1, real_T c2_c_x[2304], real_T *c2_tau);
static real_T c2_xnrm2(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, real_T c2_b_x[2304], int32_T c2_ix0);
static void c2_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_n,
                      int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T
                      c2_ic0, real_T c2_work[48], real_T c2_b_C[2304], real_T
                      c2_b_work[48]);
static void c2_ilazlr(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                      int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, int32_T
                      *c2_i, real_T c2_h_A[2304]);
static void c2_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                     int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T
                     c2_b_x[2304], int32_T c2_ix0, real_T c2_b_y[48], real_T
                     c2_c_y[48]);
static void c2_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                     int32_T c2_n, real_T c2_alpha1, real_T c2_b_x[48], int32_T
                     c2_iy0, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_h_A
                     [2304]);
static void c2_b_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T
  c2_ic0, real_T c2_work[48], real_T c2_b_C[2304], real_T c2_b_work[48]);
static void c2_ilazlc(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                      int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, int32_T
                      c2_lda, int32_T *c2_j, real_T c2_h_A[2304]);
static void c2_b_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_b_x[2304],
  int32_T c2_ix0, real_T c2_b_y[48], real_T c2_c_y[48]);
static void c2_b_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, real_T c2_b_y[48],
  real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_h_A[2304]);
static void c2_xhseqr(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_h
                      [2304], real_T c2_b_h[2304], int32_T *c2_info);
static void c2_error(SFc2_simuleringInstanceStruct *chartInstance);
static void c2_b_error(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_varargin_2);
static void c2_c_error(SFc2_simuleringInstanceStruct *chartInstance);
static void c2_xdlanv2(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_a,
  real_T c2_b_b, real_T c2_c, real_T c2_d, real_T *c2_rt1r, real_T *c2_rt1i,
  real_T *c2_rt2r, real_T *c2_rt2i, real_T *c2_b_a, real_T *c2_c_b, real_T
  *c2_b_c, real_T *c2_b_d, real_T *c2_cs, real_T *c2_sn);
static void c2_eml_rsf2csf(SFc2_simuleringInstanceStruct *chartInstance, real_T
  c2_Tr[2304], creal_T c2_b_T[2304]);
static void c2_warning(SFc2_simuleringInstanceStruct *chartInstance);
static void c2_mainDiagZeroImag(SFc2_simuleringInstanceStruct *chartInstance,
  creal_T c2_D[2304], creal_T c2_d[48]);
static void c2_xgeev(SFc2_simuleringInstanceStruct *chartInstance, real_T
                     c2_g_A[2304], int32_T *c2_info, creal_T c2_W[48]);
static boolean_T c2_infocheck(SFc2_simuleringInstanceStruct *chartInstance,
  int32_T c2_info);
static void c2_d_error(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_varargin_2);
static void c2_b_warning(SFc2_simuleringInstanceStruct *chartInstance);
static const mxArray *c2_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char * c2_b_u);
static void c2_g_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y);
static void c2_h_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y);
static void c2_i_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [168]);
static void c2_j_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y);
static void c2_k_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y);
static void c2_l_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [1152]);
static void c2_m_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y);
static void c2_n_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y);
static void c2_o_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [2304]);
static void c2_p_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y);
static void c2_q_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y);
static void c2_r_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[24]);
static void c2_s_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier, c2_sjdLzyTh14ULkIImcl6xwW
  *c2_b_y);
static void c2_t_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sjdLzyTh14ULkIImcl6xwW *c2_b_y);
static void c2_u_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y);
static void c2_v_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y);
static void c2_w_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y);
static void c2_x_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y);
static void c2_y_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [1152]);
static void c2_ab_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y);
static void c2_bb_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y);
static const mxArray *c2_b_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[48]);
static const mxArray *c2_c_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[2]);
static const mxArray *c2_d_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const creal_T c2_b_u[48]);
static const mxArray *c2_e_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[2304]);
static const mxArray *c2_f_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[48]);
static const mxArray *c2_g_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[7]);
static const mxArray *c2_h_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[4]);
static const mxArray *c2_i_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[9]);
static const mxArray *c2_j_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[14]);
static const mxArray *c2_k_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance);
static void c2_cb_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_u_hp, const char_T *c2_identifier, real_T c2_b_y[48]);
static void c2_db_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[48]);
static const mxArray *c2_l_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const c2_emxArray_real_T *c2_b_u);
static const mxArray *c2_m_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[24]);
static const mxArray *c2_n_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[2]);
static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_eb_emlrt_marshallIn(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_fb_emlrt_marshallIn(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_simulering, const char_T
  *c2_identifier);
static uint8_T c2_gb_emlrt_marshallIn(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_triu(SFc2_simuleringInstanceStruct *chartInstance, creal_T
                      c2_b_x[2304]);
static void c2_b_xgehrd(SFc2_simuleringInstanceStruct *chartInstance, real_T
  c2_a[2304]);
static real_T c2_b_xzlarfg(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, real_T *c2_alpha1, real_T c2_b_x[2304], int32_T c2_ix0);
static void c2_c_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T c2_ic0, real_T
  c2_work[48]);
static int32_T c2_b_ilazlr(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0);
static void c2_c_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_b_x[2304],
  int32_T c2_ix0, real_T c2_b_y[48]);
static void c2_c_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_b_x[48], int32_T c2_iy0,
  real_T c2_g_A[2304], int32_T c2_ia0);
static void c2_d_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T
  c2_ic0, real_T c2_work[48]);
static int32_T c2_b_ilazlc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, int32_T c2_lda);
static void c2_d_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_b_x[2304],
  int32_T c2_ix0, real_T c2_b_y[48]);
static void c2_d_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, real_T c2_b_y[48],
  real_T c2_g_A[2304], int32_T c2_ia0);
static int32_T c2_b_xhseqr(SFc2_simuleringInstanceStruct *chartInstance, real_T
  c2_h[2304]);
static void c2_b_xdlanv2(SFc2_simuleringInstanceStruct *chartInstance, real_T
  *c2_a, real_T *c2_b_b, real_T *c2_c, real_T *c2_d, real_T *c2_rt1r, real_T
  *c2_rt1i, real_T *c2_rt2r, real_T *c2_rt2i, real_T *c2_cs, real_T *c2_sn);
static void c2_emxEnsureCapacity(SFc2_simuleringInstanceStruct *chartInstance,
  c2_emxArray__common *c2_emxArray, int32_T c2_oldNumel, uint32_T c2_elementSize,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T(SFc2_simuleringInstanceStruct *chartInstance,
  c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real_T(SFc2_simuleringInstanceStruct *chartInstance,
  c2_emxArray_real_T **c2_pEmxArray);
static int32_T c2_div_nzp_s32(SFc2_simuleringInstanceStruct *chartInstance,
  int32_T c2_numerator, int32_T c2_denominator, uint32_T c2_ssid_src_loc,
  int32_T c2_offset_src_loc, int32_T c2_length_src_loc);
static void init_dsm_address_info(SFc2_simuleringInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_simuleringInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_simulering(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_simulering = 0U;
}

static void initialize_params_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_simulering(SFc2_simuleringInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(2, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_u, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_simulering;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  real_T c2_dv0[2];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("u", c2_b_u, 0)),
                      "u", c2_dv0);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    (*chartInstance->c2_u)[c2_i0] = c2_dv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_simulering = c2_fb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_simulering", c2_b_u,
       1)), "is_active_c2_simulering");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_simulering(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u_old)[c2_i1], 5U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x, 4U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_t_clock, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  for (c2_i2 = 0; c2_i2 < 1152; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_Lambda_C)[c2_i2], 2U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i3 = 0; c2_i3 < 2304; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_Lambda_B)[c2_i3], 1U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i4 = 0; c2_i4 < 2304; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_Lambda_A)[c2_i4], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_simulering(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_simuleringMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u)[c2_i5], 6U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void mdl_start_c2_simulering(SFc2_simuleringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_b_t_clock;
  real_T c2_b_Lambda_C[1152];
  real_T c2_b_x;
  int32_T c2_i9;
  uint32_T c2_debug_family_var_map[54];
  real_T c2_b_u_old[2];
  real_T c2_Ts;
  real_T c2_t_h;
  real_T c2_t_h_2;
  real_T c2_u_hp[48];
  real_T c2_u_hp1[24];
  real_T c2_u_hp2[24];
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_data;
  c2_sDEl41izlL3fNQfEgJJ5XBH c2_Gamma;
  c2_sXRXp7aMGjI8fA8IXQDoqtG c2_Phi;
  c2_sVXPIQCYRVtgDunkSIgrZND c2_Psi;
  c2_spEGmxEyHM6EoZZcXmG7jeB c2_Theta;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_constant_dist;
  real_T c2_Data_OD[24];
  real_T c2_d_hp[48];
  real_T c2_delta_p_0;
  real_T c2_q_bar_p_hp[48];
  real_T c2_y_low[48];
  real_T c2_y_high[48];
  real_T c2_y_bar[48];
  real_T c2_y1[48];
  real_T c2_y2[48];
  real_T c2_x_low[24];
  real_T c2_x_high[24];
  real_T c2_x_bar[24];
  real_T c2_delta_p_wt_1[24];
  real_T c2_delta_p_wt_2[24];
  real_T c2_U_bar;
  real_T c2_U_bar_hp[48];
  real_T c2_u_low;
  real_T c2_u_high;
  real_T c2_f[48];
  real_T c2_b_b[96];
  real_T c2_lb[48];
  real_T c2_ub[48];
  const mxArray *c2_func = NULL;
  const mxArray *c2_options = NULL;
  const mxArray *c2_fval = NULL;
  const mxArray *c2_exitflag = NULL;
  const mxArray *c2_output = NULL;
  real_T c2_b_data[168];
  real_T c2_b_Gamma[1152];
  real_T c2_b_Phi[24];
  real_T c2_b_Psi[1152];
  real_T c2_b_Theta[1152];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_u[2];
  real_T c2_g_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_h_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_j_x;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  const mxArray *c2_b_u_hp = NULL;
  const mxArray *c2_b_fval = NULL;
  const mxArray *c2_b_exitflag = NULL;
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_r0;
  const mxArray *c2_b_output = NULL;
  int32_T c2_i14;
  int32_T c2_i15;
  c2_sDEl41izlL3fNQfEgJJ5XBH c2_r1;
  int32_T c2_i16;
  int32_T c2_i17;
  c2_sXRXp7aMGjI8fA8IXQDoqtG c2_r3;
  int32_T c2_i18;
  int32_T c2_i19;
  c2_sVXPIQCYRVtgDunkSIgrZND c2_r5;
  int32_T c2_i20;
  c2_spEGmxEyHM6EoZZcXmG7jeB c2_r6;
  int32_T c2_i21;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_r7;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  static real_T c2_dv1[48] = { 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562,
    0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562,
    0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991 };

  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_a[1152];
  real_T c2_alpha1;
  real_T c2_c_b[24];
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  int32_T c2_i29;
  ptrdiff_t c2_m_t;
  real_T c2_d_y[48];
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  real_T c2_d_b;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  real_T c2_b_alpha1;
  real_T c2_e_b[1152];
  real_T c2_b_beta1;
  char_T c2_b_TRANSB;
  char_T c2_b_TRANSA;
  int32_T c2_i33;
  ptrdiff_t c2_b_m_t;
  ptrdiff_t c2_b_n_t;
  ptrdiff_t c2_b_k_t;
  ptrdiff_t c2_b_lda_t;
  ptrdiff_t c2_b_ldb_t;
  ptrdiff_t c2_b_ldc_t;
  int32_T c2_i34;
  int32_T c2_i35;
  real_T c2_c_alpha1;
  real_T c2_f_b[48];
  real_T c2_c_beta1;
  char_T c2_c_TRANSB;
  char_T c2_c_TRANSA;
  int32_T c2_i36;
  ptrdiff_t c2_c_m_t;
  real_T c2_e_y[48];
  ptrdiff_t c2_c_n_t;
  ptrdiff_t c2_c_k_t;
  ptrdiff_t c2_c_lda_t;
  ptrdiff_t c2_c_ldb_t;
  ptrdiff_t c2_c_ldc_t;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_d_alpha1;
  real_T c2_d_beta1;
  char_T c2_d_TRANSB;
  char_T c2_d_TRANSA;
  int32_T c2_i40;
  ptrdiff_t c2_d_m_t;
  ptrdiff_t c2_d_n_t;
  ptrdiff_t c2_d_k_t;
  ptrdiff_t c2_d_lda_t;
  ptrdiff_t c2_d_ldb_t;
  ptrdiff_t c2_d_ldc_t;
  real_T c2_g_b;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  real_T c2_e_alpha1;
  real_T c2_e_beta1;
  char_T c2_e_TRANSB;
  char_T c2_e_TRANSA;
  int32_T c2_i44;
  ptrdiff_t c2_e_m_t;
  ptrdiff_t c2_e_n_t;
  ptrdiff_t c2_e_k_t;
  ptrdiff_t c2_e_lda_t;
  ptrdiff_t c2_e_ldb_t;
  ptrdiff_t c2_e_ldc_t;
  int32_T c2_i45;
  int32_T c2_i46;
  real_T c2_f_alpha1;
  real_T c2_f_beta1;
  char_T c2_f_TRANSB;
  char_T c2_f_TRANSA;
  int32_T c2_i47;
  ptrdiff_t c2_f_m_t;
  ptrdiff_t c2_f_n_t;
  ptrdiff_t c2_f_k_t;
  ptrdiff_t c2_f_lda_t;
  ptrdiff_t c2_f_ldb_t;
  ptrdiff_t c2_f_ldc_t;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_g_alpha1;
  real_T c2_g_beta1;
  char_T c2_g_TRANSB;
  char_T c2_g_TRANSA;
  int32_T c2_i51;
  ptrdiff_t c2_g_m_t;
  ptrdiff_t c2_g_n_t;
  ptrdiff_t c2_g_k_t;
  ptrdiff_t c2_g_lda_t;
  ptrdiff_t c2_g_ldb_t;
  ptrdiff_t c2_g_ldc_t;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  real_T c2_h_b;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  real_T c2_h_alpha1;
  real_T c2_h_beta1;
  char_T c2_h_TRANSB;
  char_T c2_h_TRANSA;
  int32_T c2_i60;
  ptrdiff_t c2_h_m_t;
  real_T c2_f_y[24];
  ptrdiff_t c2_h_n_t;
  ptrdiff_t c2_h_k_t;
  ptrdiff_t c2_h_lda_t;
  ptrdiff_t c2_h_ldb_t;
  ptrdiff_t c2_h_ldc_t;
  int32_T c2_i61;
  int32_T c2_i62;
  real_T c2_i_b;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  real_T c2_i_alpha1;
  real_T c2_i_beta1;
  char_T c2_i_TRANSB;
  char_T c2_i_TRANSA;
  int32_T c2_i66;
  ptrdiff_t c2_i_m_t;
  ptrdiff_t c2_i_n_t;
  ptrdiff_t c2_i_k_t;
  ptrdiff_t c2_i_lda_t;
  ptrdiff_t c2_i_ldb_t;
  ptrdiff_t c2_i_ldc_t;
  int32_T c2_i67;
  int32_T c2_i68;
  static char_T c2_cv0[2] = { 'o', 'n' };

  int32_T c2_i69;
  int32_T c2_i70;
  real_T c2_b_delta_p_wt_1[48];
  int32_T c2_i71;
  int32_T c2_i72;
  real_T c2_b_delta_p_wt_2[48];
  int32_T c2_i73;
  int32_T c2_i74;
  real_T c2_j_alpha1;
  real_T c2_j_beta1;
  char_T c2_j_TRANSB;
  char_T c2_j_TRANSA;
  int32_T c2_i75;
  ptrdiff_t c2_j_m_t;
  ptrdiff_t c2_j_n_t;
  ptrdiff_t c2_j_k_t;
  ptrdiff_t c2_j_lda_t;
  ptrdiff_t c2_j_ldb_t;
  ptrdiff_t c2_j_ldc_t;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  real_T c2_k_alpha1;
  real_T c2_k_beta1;
  char_T c2_k_TRANSB;
  char_T c2_k_TRANSA;
  int32_T c2_i85;
  ptrdiff_t c2_k_m_t;
  ptrdiff_t c2_k_n_t;
  ptrdiff_t c2_k_k_t;
  ptrdiff_t c2_k_lda_t;
  ptrdiff_t c2_k_ldb_t;
  ptrdiff_t c2_k_ldc_t;
  int32_T c2_i86;
  real_T c2_l_alpha1;
  int32_T c2_i87;
  real_T c2_l_beta1;
  real_T c2_i_A[48];
  char_T c2_l_TRANSB;
  char_T c2_l_TRANSA;
  int32_T c2_i88;
  ptrdiff_t c2_l_m_t;
  real_T c2_g_y[48];
  ptrdiff_t c2_l_n_t;
  ptrdiff_t c2_l_k_t;
  ptrdiff_t c2_l_lda_t;
  ptrdiff_t c2_l_ldb_t;
  ptrdiff_t c2_l_ldc_t;
  int32_T c2_i89;
  int32_T c2_i90;
  real_T c2_m_alpha1;
  real_T c2_m_beta1;
  char_T c2_m_TRANSB;
  char_T c2_m_TRANSA;
  int32_T c2_i91;
  ptrdiff_t c2_m_m_t;
  ptrdiff_t c2_m_n_t;
  ptrdiff_t c2_m_k_t;
  ptrdiff_t c2_m_lda_t;
  ptrdiff_t c2_m_ldb_t;
  ptrdiff_t c2_m_ldc_t;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  real_T c2_n_alpha1;
  int32_T c2_i95;
  real_T c2_n_beta1;
  int32_T c2_i96;
  char_T c2_n_TRANSB;
  char_T c2_n_TRANSA;
  int32_T c2_i97;
  ptrdiff_t c2_n_m_t;
  real_T c2_h_y[48];
  ptrdiff_t c2_n_n_t;
  ptrdiff_t c2_n_k_t;
  ptrdiff_t c2_n_lda_t;
  ptrdiff_t c2_n_ldb_t;
  ptrdiff_t c2_n_ldc_t;
  int32_T c2_i98;
  int32_T c2_i99;
  real_T c2_o_alpha1;
  real_T c2_o_beta1;
  char_T c2_o_TRANSB;
  char_T c2_o_TRANSA;
  int32_T c2_i100;
  ptrdiff_t c2_o_m_t;
  ptrdiff_t c2_o_n_t;
  ptrdiff_t c2_o_k_t;
  ptrdiff_t c2_o_lda_t;
  ptrdiff_t c2_o_ldb_t;
  ptrdiff_t c2_o_ldc_t;
  real_T c2_b_a;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  creal_T c2_dcv0[48];
  int32_T c2_i105;
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i110;
  int32_T c2_i111;
  int32_T c2_i112;
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  static char_T c2_cv1[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  static char_T c2_cv2[7] = { 'D', 'i', 's', 'p', 'l', 'a', 'y' };

  static char_T c2_cv3[4] = { 'i', 't', 'e', 'r' };

  static char_T c2_cv4[9] = { 'A', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm' };

  static char_T c2_cv5[14] = { 'i', 'n', 't', 'e', 'r', 'i', 'o', 'r', '-', 'p',
    'o', 'i', 'n', 't' };

  real_T c2_dv2[48];
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  c2_emxArray_real_T *c2_i_y;
  real_T c2_c_a;
  real_T c2_d;
  real_T c2_d_a;
  real_T c2_j_b;
  real_T c2_k_x;
  boolean_T c2_k_b;
  real_T c2_l_x;
  boolean_T c2_l_b;
  int32_T c2_i122;
  real_T c2_m_x;
  int32_T c2_i123;
  boolean_T c2_m_b;
  int32_T c2_j_y;
  int32_T c2_k_y;
  real_T c2_n_x;
  boolean_T c2_n_b;
  int32_T c2_l_y;
  int32_T c2_i124;
  int32_T c2_m_y;
  real_T c2_o_x;
  real_T c2_p_x;
  int32_T c2_n_y;
  real_T c2_e_a;
  real_T c2_f_a;
  int32_T c2_i125;
  int32_T c2_o_y;
  real_T c2_b_d;
  real_T c2_o_b;
  real_T c2_g_a;
  real_T c2_h_a;
  real_T c2_p_b;
  real_T c2_q_b;
  real_T c2_q_x;
  real_T c2_anew;
  int32_T c2_loop_ub;
  boolean_T c2_r_b;
  real_T c2_r_x;
  int32_T c2_i126;
  real_T c2_ndbl;
  real_T c2_s_x;
  boolean_T c2_s_b;
  int32_T c2_i127;
  real_T c2_apnd;
  real_T c2_cdiff;
  real_T c2_t_x;
  real_T c2_u_x;
  int32_T c2_i128;
  real_T c2_v_x;
  boolean_T c2_t_b;
  int32_T c2_p_y;
  real_T c2_w_x;
  int32_T c2_q_y;
  real_T c2_r_y;
  real_T c2_x_x;
  real_T c2_i_a;
  boolean_T c2_u_b;
  int32_T c2_s_y;
  real_T c2_v_b;
  int32_T c2_i129;
  int32_T c2_t_y;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_absa;
  int32_T c2_u_y;
  real_T c2_eb_x;
  real_T c2_j_a;
  int32_T c2_i130;
  int32_T c2_v_y;
  real_T c2_fb_x;
  real_T c2_w_b;
  real_T c2_gb_x;
  real_T c2_k_a;
  real_T c2_absb;
  real_T c2_x_b;
  int32_T c2_i131;
  real_T c2_c;
  real_T c2_b_anew;
  int32_T c2_b_loop_ub;
  real_T c2_hb_x;
  int32_T c2_i132;
  real_T c2_b_ndbl;
  real_T c2_bnew;
  real_T c2_b_apnd;
  real_T c2_l_a;
  real_T c2_b_cdiff;
  real_T c2_m_a;
  real_T c2_ib_x;
  real_T c2_flt;
  real_T c2_jb_x;
  boolean_T c2_n_too_large;
  real_T c2_kb_x;
  real_T c2_w_y;
  int32_T c2_n;
  real_T c2_n_a;
  real_T c2_y_b;
  boolean_T c2_p;
  real_T c2_lb_x;
  real_T c2_mb_x;
  const mxArray *c2_x_y = NULL;
  real_T c2_nb_x;
  static char_T c2_cv6[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T c2_i133;
  real_T c2_b_absa;
  real_T c2_ob_x;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_b_absb;
  real_T c2_b_c;
  int32_T c2_o_a;
  real_T c2_b_bnew;
  int32_T c2_nm1;
  int32_T c2_p_a;
  real_T c2_q_a;
  int32_T c2_nm1d2;
  real_T c2_r_a;
  int32_T c2_s_a;
  real_T c2_b_flt;
  int32_T c2_i134;
  boolean_T c2_b_n_too_large;
  int32_T c2_ab_b;
  int32_T c2_bb_b;
  int32_T c2_b_n;
  boolean_T c2_overflow;
  boolean_T c2_b_p;
  int32_T c2_k;
  const mxArray *c2_y_y = NULL;
  static char_T c2_cv7[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T c2_i135;
  int32_T c2_cb_b;
  real_T c2_kd;
  int32_T c2_c_c;
  int32_T c2_t_a;
  int32_T c2_d_c;
  int32_T c2_u_a;
  int32_T c2_v_a;
  int32_T c2_e_c;
  int32_T c2_w_a;
  int32_T c2_f_c;
  int32_T c2_db_b;
  int32_T c2_g_c;
  int32_T c2_x_a;
  int32_T c2_y_a;
  int32_T c2_b_nm1;
  int32_T c2_h_c;
  int32_T c2_ab_a;
  int32_T c2_b_nm1d2;
  int32_T c2_bb_a;
  int32_T c2_i136;
  int32_T c2_eb_b;
  int32_T c2_fb_b;
  boolean_T c2_b_overflow;
  int32_T c2_b_k;
  int32_T c2_gb_b;
  real_T c2_b_kd;
  int32_T c2_i_c;
  int32_T c2_cb_a;
  int32_T c2_j_c;
  int32_T c2_db_a;
  int32_T c2_eb_a;
  int32_T c2_k_c;
  int32_T c2_fb_a;
  int32_T c2_l_c;
  int32_T c2_hb_b;
  int32_T c2_m_c;
  int32_T c2_gb_a;
  int32_T c2_n_c;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_t_clock;
  c2_b_hoistedGlobal = *chartInstance->c2_x;
  for (c2_i6 = 0; c2_i6 < 2304; c2_i6++) {
    chartInstance->c2_Lambda_A[c2_i6] = (*chartInstance->c2_b_Lambda_A)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 2304; c2_i7++) {
    chartInstance->c2_Lambda_B[c2_i7] = (*chartInstance->c2_b_Lambda_B)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 1152; c2_i8++) {
    c2_b_Lambda_C[c2_i8] = (*chartInstance->c2_Lambda_C)[c2_i8];
  }

  c2_b_t_clock = c2_hoistedGlobal;
  c2_b_x = c2_b_hoistedGlobal;
  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    c2_b_u_old[c2_i9] = (*chartInstance->c2_u_old)[c2_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 54U, 61U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Ts, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_t_h, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_t_h_2, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp, 3U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp1, 4U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp2, 5U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_data, MAX_uint32_T,
    c2_t_sf_marshallOut, c2_s_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Gamma, MAX_uint32_T,
    c2_s_sf_marshallOut, c2_r_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Omega, MAX_uint32_T,
    c2_r_sf_marshallOut, c2_q_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Phi, MAX_uint32_T,
    c2_q_sf_marshallOut, c2_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Pi, MAX_uint32_T,
    c2_p_sf_marshallOut, c2_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Psi, MAX_uint32_T,
    c2_o_sf_marshallOut, c2_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Theta, MAX_uint32_T,
    c2_n_sf_marshallOut, c2_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_constant_dist, 13U,
    c2_m_sf_marshallOut, c2_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Data_OD, 14U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d_hp, 15U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_delta_p_0, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q_bar_p_hp, 17U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_low, 18U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_high, 19U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_bar, 20U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y1, 21U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y2, 22U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_L_y, 23U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_low, 24U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_high, 25U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_bar, 26U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_delta_p_wt_1, 27U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_delta_p_wt_2, 28U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_U_bar, 29U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_U_bar_hp, 30U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_u_low, 31U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_u_high, 32U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R, 33U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R1, 34U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_f, 35U, c2_l_sf_marshallOut,
    c2_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_A, 36U,
    c2_k_sf_marshallOut, c2_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_b, 37U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_lb, 38U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_ub, 39U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_func, 40U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_options, 41U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_fval, 42U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_exitflag, 43U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_output, 44U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_data, MAX_uint32_T,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Gamma, MAX_uint32_T,
    c2_e_sf_marshallOut, c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_b_Omega, MAX_uint32_T,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Phi, MAX_uint32_T,
    c2_f_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_b_Pi, MAX_uint32_T,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Psi, MAX_uint32_T,
    c2_e_sf_marshallOut, c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Theta, MAX_uint32_T,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 45U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 46U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Lambda_A, 47U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Lambda_B, 48U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_Lambda_C, 49U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_t_clock, 50U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_x, 51U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u_old, 52U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_u, 53U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_Ts = 6.4385;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_g_A = c2_b_t_clock;
  c2_c_x = c2_g_A;
  c2_d_x = c2_c_x;
  c2_b_y = c2_d_x / 3600.0;
  c2_e_x = c2_b_y;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarFloor(c2_f_x);
  c2_t_h = 1.0 + c2_f_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_h_A = c2_b_t_clock - 6.4385;
  c2_g_x = c2_h_A;
  c2_h_x = c2_g_x;
  c2_c_y = c2_h_x / 3600.0;
  c2_i_x = c2_c_y;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarFloor(c2_j_x);
  c2_t_h_2 = 1.0 + c2_j_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_t_h, c2_t_h_2, -1, 1U,
        c2_t_h != c2_t_h_2))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    for (c2_i11 = 0; c2_i11 < 48; c2_i11++) {
      c2_u_hp[c2_i11] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    for (c2_i12 = 0; c2_i12 < 24; c2_i12++) {
      c2_u_hp1[c2_i12] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    for (c2_i13 = 0; c2_i13 < 24; c2_i13++) {
      c2_u_hp2[c2_i13] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
    _SFD_SYMBOL_SWITCH(6U, 6U);
    c2_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "data.mat")), "load", &c2_r0);
    c2_data = c2_r0;
    _SFD_SYMBOL_SWITCH(6U, 6U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
    for (c2_i15 = 0; c2_i15 < 168; c2_i15++) {
      c2_b_data[c2_i15] = c2_data.data[c2_i15];
    }

    _SFD_SYMBOL_SWITCH(6U, 45U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
    _SFD_SYMBOL_SWITCH(7U, 7U);
    c2_j_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Gamma.mat")), "load", &c2_r1);
    c2_Gamma = c2_r1;
    _SFD_SYMBOL_SWITCH(7U, 7U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    for (c2_i16 = 0; c2_i16 < 1152; c2_i16++) {
      c2_b_Gamma[c2_i16] = c2_Gamma.Gamma[c2_i16];
    }

    _SFD_SYMBOL_SWITCH(7U, 46U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    _SFD_SYMBOL_SWITCH(8U, 8U);
    c2_m_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Omega.mat")), "load",
                          &chartInstance->c2_r2);
    chartInstance->c2_Omega = chartInstance->c2_r2;
    _SFD_SYMBOL_SWITCH(8U, 8U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    for (c2_i17 = 0; c2_i17 < 2304; c2_i17++) {
      chartInstance->c2_b_Omega[c2_i17] = chartInstance->c2_Omega.Omega[c2_i17];
    }

    _SFD_SYMBOL_SWITCH(8U, 47U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
    _SFD_SYMBOL_SWITCH(9U, 9U);
    c2_p_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Phi.mat")), "load", &c2_r3);
    c2_Phi = c2_r3;
    _SFD_SYMBOL_SWITCH(9U, 9U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
    for (c2_i18 = 0; c2_i18 < 24; c2_i18++) {
      c2_b_Phi[c2_i18] = c2_Phi.Phi[c2_i18];
    }

    _SFD_SYMBOL_SWITCH(9U, 48U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
    _SFD_SYMBOL_SWITCH(10U, 10U);
    c2_s_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Pi.mat")), "load",
                          &chartInstance->c2_r4);
    chartInstance->c2_Pi = chartInstance->c2_r4;
    _SFD_SYMBOL_SWITCH(10U, 10U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    for (c2_i19 = 0; c2_i19 < 2304; c2_i19++) {
      chartInstance->c2_b_Pi[c2_i19] = chartInstance->c2_Pi.Pi[c2_i19];
    }

    _SFD_SYMBOL_SWITCH(10U, 49U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
    _SFD_SYMBOL_SWITCH(11U, 11U);
    c2_u_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Psi.mat")), "load", &c2_r5);
    c2_Psi = c2_r5;
    _SFD_SYMBOL_SWITCH(11U, 11U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
    for (c2_i20 = 0; c2_i20 < 1152; c2_i20++) {
      c2_b_Psi[c2_i20] = c2_Psi.Psi[c2_i20];
    }

    _SFD_SYMBOL_SWITCH(11U, 50U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
    _SFD_SYMBOL_SWITCH(12U, 12U);
    c2_w_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Theta.mat")), "load", &c2_r6);
    c2_Theta = c2_r6;
    _SFD_SYMBOL_SWITCH(12U, 12U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
    for (c2_i21 = 0; c2_i21 < 1152; c2_i21++) {
      c2_b_Theta[c2_i21] = c2_Theta.Theta[c2_i21];
    }

    _SFD_SYMBOL_SWITCH(12U, 51U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    c2_ab_emlrt_marshallIn(chartInstance, sf_mex_call_debug
      (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14, c2_emlrt_marshallOut
       (chartInstance, "constant_dist.mat")), "load", &c2_r7);
    c2_constant_dist = c2_r7;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    for (c2_i22 = 0; c2_i22 < 24; c2_i22++) {
      c2_Data_OD[c2_i22] = c2_constant_dist.constant_dist[c2_i22];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
    c2_d_hp[0] = c2_Data_OD[0];
    c2_d_hp[1] = c2_Data_OD[0];
    c2_d_hp[2] = c2_Data_OD[1];
    c2_d_hp[3] = c2_Data_OD[1];
    c2_d_hp[4] = c2_Data_OD[2];
    c2_d_hp[5] = c2_Data_OD[2];
    c2_d_hp[6] = c2_Data_OD[3];
    c2_d_hp[7] = c2_Data_OD[3];
    c2_d_hp[8] = c2_Data_OD[4];
    c2_d_hp[9] = c2_Data_OD[4];
    c2_d_hp[10] = c2_Data_OD[5];
    c2_d_hp[11] = c2_Data_OD[5];
    c2_d_hp[12] = c2_Data_OD[6];
    c2_d_hp[13] = c2_Data_OD[6];
    c2_d_hp[14] = c2_Data_OD[7];
    c2_d_hp[15] = c2_Data_OD[7];
    c2_d_hp[16] = c2_Data_OD[8];
    c2_d_hp[17] = c2_Data_OD[8];
    c2_d_hp[18] = c2_Data_OD[9];
    c2_d_hp[19] = c2_Data_OD[9];
    c2_d_hp[20] = c2_Data_OD[10];
    c2_d_hp[21] = c2_Data_OD[10];
    c2_d_hp[22] = c2_Data_OD[11];
    c2_d_hp[23] = c2_Data_OD[11];
    c2_d_hp[24] = c2_Data_OD[12];
    c2_d_hp[25] = c2_Data_OD[12];
    c2_d_hp[26] = c2_Data_OD[13];
    c2_d_hp[27] = c2_Data_OD[13];
    c2_d_hp[28] = c2_Data_OD[14];
    c2_d_hp[29] = c2_Data_OD[14];
    c2_d_hp[30] = c2_Data_OD[15];
    c2_d_hp[31] = c2_Data_OD[15];
    c2_d_hp[32] = c2_Data_OD[16];
    c2_d_hp[33] = c2_Data_OD[16];
    c2_d_hp[34] = c2_Data_OD[17];
    c2_d_hp[35] = c2_Data_OD[17];
    c2_d_hp[36] = c2_Data_OD[18];
    c2_d_hp[37] = c2_Data_OD[18];
    c2_d_hp[38] = c2_Data_OD[19];
    c2_d_hp[39] = c2_Data_OD[19];
    c2_d_hp[40] = c2_Data_OD[20];
    c2_d_hp[41] = c2_Data_OD[20];
    c2_d_hp[42] = c2_Data_OD[21];
    c2_d_hp[43] = c2_Data_OD[21];
    c2_d_hp[44] = c2_Data_OD[22];
    c2_d_hp[45] = c2_Data_OD[22];
    c2_d_hp[46] = c2_Data_OD[23];
    c2_d_hp[47] = c2_Data_OD[23];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    c2_delta_p_0 = c2_b_x;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
    for (c2_i23 = 0; c2_i23 < 48; c2_i23++) {
      c2_q_bar_p_hp[c2_i23] = 0.45;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
    for (c2_i24 = 0; c2_i24 < 48; c2_i24++) {
      c2_y_low[c2_i24] = 0.08;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
    for (c2_i25 = 0; c2_i25 < 48; c2_i25++) {
      c2_y_high[c2_i25] = 0.18;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
    for (c2_i26 = 0; c2_i26 < 48; c2_i26++) {
      c2_y_bar[c2_i26] = c2_dv1[c2_i26];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
    for (c2_i27 = 0; c2_i27 < 1152; c2_i27++) {
      c2_a[c2_i27] = c2_b_Theta[c2_i27];
    }

    for (c2_i28 = 0; c2_i28 < 24; c2_i28++) {
      c2_c_b[c2_i28] = c2_b_Phi[c2_i28];
    }

    c2_alpha1 = 1.0;
    c2_beta1 = 0.0;
    c2_TRANSB = 'N';
    c2_TRANSA = 'N';
    for (c2_i29 = 0; c2_i29 < 48; c2_i29++) {
      c2_d_y[c2_i29] = 0.0;
    }

    c2_m_t = (ptrdiff_t)48;
    c2_n_t = (ptrdiff_t)1;
    c2_k_t = (ptrdiff_t)24;
    c2_lda_t = (ptrdiff_t)48;
    c2_ldb_t = (ptrdiff_t)24;
    c2_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1, &c2_a[0],
          &c2_lda_t, &c2_c_b[0], &c2_ldb_t, &c2_beta1, &c2_d_y[0], &c2_ldc_t);
    c2_d_b = c2_delta_p_0;
    for (c2_i30 = 0; c2_i30 < 48; c2_i30++) {
      c2_d_y[c2_i30] *= c2_d_b;
    }

    for (c2_i31 = 0; c2_i31 < 1152; c2_i31++) {
      c2_a[c2_i31] = c2_b_Theta[c2_i31];
    }

    for (c2_i32 = 0; c2_i32 < 1152; c2_i32++) {
      c2_e_b[c2_i32] = c2_b_Psi[c2_i32];
    }

    c2_b_alpha1 = 1.0;
    c2_b_beta1 = 0.0;
    c2_b_TRANSB = 'N';
    c2_b_TRANSA = 'N';
    for (c2_i33 = 0; c2_i33 < 2304; c2_i33++) {
      chartInstance->c2_y[c2_i33] = 0.0;
    }

    c2_b_m_t = (ptrdiff_t)48;
    c2_b_n_t = (ptrdiff_t)48;
    c2_b_k_t = (ptrdiff_t)24;
    c2_b_lda_t = (ptrdiff_t)48;
    c2_b_ldb_t = (ptrdiff_t)24;
    c2_b_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_b_TRANSA, &c2_b_TRANSB, &c2_b_m_t, &c2_b_n_t, &c2_b_k_t,
          &c2_b_alpha1, &c2_a[0], &c2_b_lda_t, &c2_e_b[0], &c2_b_ldb_t,
          &c2_b_beta1, &chartInstance->c2_y[0], &c2_b_ldc_t);
    for (c2_i34 = 0; c2_i34 < 2304; c2_i34++) {
      chartInstance->c2_y[c2_i34] += chartInstance->c2_b_Pi[c2_i34];
    }

    for (c2_i35 = 0; c2_i35 < 48; c2_i35++) {
      c2_f_b[c2_i35] = c2_d_hp[c2_i35];
    }

    c2_c_alpha1 = 1.0;
    c2_c_beta1 = 0.0;
    c2_c_TRANSB = 'N';
    c2_c_TRANSA = 'N';
    for (c2_i36 = 0; c2_i36 < 48; c2_i36++) {
      c2_e_y[c2_i36] = 0.0;
    }

    c2_c_m_t = (ptrdiff_t)48;
    c2_c_n_t = (ptrdiff_t)1;
    c2_c_k_t = (ptrdiff_t)48;
    c2_c_lda_t = (ptrdiff_t)48;
    c2_c_ldb_t = (ptrdiff_t)48;
    c2_c_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_c_TRANSA, &c2_c_TRANSB, &c2_c_m_t, &c2_c_n_t, &c2_c_k_t,
          &c2_c_alpha1, &chartInstance->c2_y[0], &c2_c_lda_t, &c2_f_b[0],
          &c2_c_ldb_t, &c2_c_beta1, &c2_e_y[0], &c2_c_ldc_t);
    for (c2_i37 = 0; c2_i37 < 48; c2_i37++) {
      c2_y1[c2_i37] = ((c2_y_low[c2_i37] - c2_y_bar[c2_i37]) - c2_d_y[c2_i37]) -
        c2_e_y[c2_i37];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
    for (c2_i38 = 0; c2_i38 < 1152; c2_i38++) {
      c2_a[c2_i38] = c2_b_Theta[c2_i38];
    }

    for (c2_i39 = 0; c2_i39 < 24; c2_i39++) {
      c2_c_b[c2_i39] = c2_b_Phi[c2_i39];
    }

    c2_d_alpha1 = 1.0;
    c2_d_beta1 = 0.0;
    c2_d_TRANSB = 'N';
    c2_d_TRANSA = 'N';
    for (c2_i40 = 0; c2_i40 < 48; c2_i40++) {
      c2_d_y[c2_i40] = 0.0;
    }

    c2_d_m_t = (ptrdiff_t)48;
    c2_d_n_t = (ptrdiff_t)1;
    c2_d_k_t = (ptrdiff_t)24;
    c2_d_lda_t = (ptrdiff_t)48;
    c2_d_ldb_t = (ptrdiff_t)24;
    c2_d_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_d_TRANSA, &c2_d_TRANSB, &c2_d_m_t, &c2_d_n_t, &c2_d_k_t,
          &c2_d_alpha1, &c2_a[0], &c2_d_lda_t, &c2_c_b[0], &c2_d_ldb_t,
          &c2_d_beta1, &c2_d_y[0], &c2_d_ldc_t);
    c2_g_b = c2_delta_p_0;
    for (c2_i41 = 0; c2_i41 < 48; c2_i41++) {
      c2_d_y[c2_i41] *= c2_g_b;
    }

    for (c2_i42 = 0; c2_i42 < 1152; c2_i42++) {
      c2_a[c2_i42] = c2_b_Theta[c2_i42];
    }

    for (c2_i43 = 0; c2_i43 < 1152; c2_i43++) {
      c2_e_b[c2_i43] = c2_b_Psi[c2_i43];
    }

    c2_e_alpha1 = 1.0;
    c2_e_beta1 = 0.0;
    c2_e_TRANSB = 'N';
    c2_e_TRANSA = 'N';
    for (c2_i44 = 0; c2_i44 < 2304; c2_i44++) {
      chartInstance->c2_y[c2_i44] = 0.0;
    }

    c2_e_m_t = (ptrdiff_t)48;
    c2_e_n_t = (ptrdiff_t)48;
    c2_e_k_t = (ptrdiff_t)24;
    c2_e_lda_t = (ptrdiff_t)48;
    c2_e_ldb_t = (ptrdiff_t)24;
    c2_e_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_e_TRANSA, &c2_e_TRANSB, &c2_e_m_t, &c2_e_n_t, &c2_e_k_t,
          &c2_e_alpha1, &c2_a[0], &c2_e_lda_t, &c2_e_b[0], &c2_e_ldb_t,
          &c2_e_beta1, &chartInstance->c2_y[0], &c2_e_ldc_t);
    for (c2_i45 = 0; c2_i45 < 2304; c2_i45++) {
      chartInstance->c2_y[c2_i45] += chartInstance->c2_b_Pi[c2_i45];
    }

    for (c2_i46 = 0; c2_i46 < 48; c2_i46++) {
      c2_f_b[c2_i46] = c2_d_hp[c2_i46];
    }

    c2_f_alpha1 = 1.0;
    c2_f_beta1 = 0.0;
    c2_f_TRANSB = 'N';
    c2_f_TRANSA = 'N';
    for (c2_i47 = 0; c2_i47 < 48; c2_i47++) {
      c2_e_y[c2_i47] = 0.0;
    }

    c2_f_m_t = (ptrdiff_t)48;
    c2_f_n_t = (ptrdiff_t)1;
    c2_f_k_t = (ptrdiff_t)48;
    c2_f_lda_t = (ptrdiff_t)48;
    c2_f_ldb_t = (ptrdiff_t)48;
    c2_f_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_f_TRANSA, &c2_f_TRANSB, &c2_f_m_t, &c2_f_n_t, &c2_f_k_t,
          &c2_f_alpha1, &chartInstance->c2_y[0], &c2_f_lda_t, &c2_f_b[0],
          &c2_f_ldb_t, &c2_f_beta1, &c2_e_y[0], &c2_f_ldc_t);
    for (c2_i48 = 0; c2_i48 < 48; c2_i48++) {
      c2_y2[c2_i48] = ((c2_y_high[c2_i48] - c2_y_bar[c2_i48]) - c2_d_y[c2_i48])
        - c2_e_y[c2_i48];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
    for (c2_i49 = 0; c2_i49 < 1152; c2_i49++) {
      c2_a[c2_i49] = c2_b_Theta[c2_i49];
    }

    for (c2_i50 = 0; c2_i50 < 1152; c2_i50++) {
      c2_e_b[c2_i50] = c2_b_Gamma[c2_i50];
    }

    c2_g_alpha1 = 1.0;
    c2_g_beta1 = 0.0;
    c2_g_TRANSB = 'N';
    c2_g_TRANSA = 'N';
    for (c2_i51 = 0; c2_i51 < 2304; c2_i51++) {
      chartInstance->c2_y[c2_i51] = 0.0;
    }

    c2_g_m_t = (ptrdiff_t)48;
    c2_g_n_t = (ptrdiff_t)48;
    c2_g_k_t = (ptrdiff_t)24;
    c2_g_lda_t = (ptrdiff_t)48;
    c2_g_ldb_t = (ptrdiff_t)24;
    c2_g_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_g_TRANSA, &c2_g_TRANSB, &c2_g_m_t, &c2_g_n_t, &c2_g_k_t,
          &c2_g_alpha1, &c2_a[0], &c2_g_lda_t, &c2_e_b[0], &c2_g_ldb_t,
          &c2_g_beta1, &chartInstance->c2_y[0], &c2_g_ldc_t);
    for (c2_i52 = 0; c2_i52 < 2304; c2_i52++) {
      chartInstance->c2_L_y[c2_i52] = chartInstance->c2_y[c2_i52] +
        chartInstance->c2_b_Omega[c2_i52];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
    for (c2_i53 = 0; c2_i53 < 24; c2_i53++) {
      c2_x_low[c2_i53] = 0.055;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
    for (c2_i54 = 0; c2_i54 < 24; c2_i54++) {
      c2_x_high[c2_i54] = 0.16;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    for (c2_i55 = 0; c2_i55 < 24; c2_i55++) {
      c2_x_bar[c2_i55] = 0.127;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    for (c2_i56 = 0; c2_i56 < 24; c2_i56++) {
      c2_c_b[c2_i56] = c2_b_Phi[c2_i56];
    }

    c2_h_b = c2_delta_p_0;
    for (c2_i57 = 0; c2_i57 < 24; c2_i57++) {
      c2_c_b[c2_i57] *= c2_h_b;
    }

    for (c2_i58 = 0; c2_i58 < 1152; c2_i58++) {
      c2_e_b[c2_i58] = c2_b_Psi[c2_i58];
    }

    for (c2_i59 = 0; c2_i59 < 48; c2_i59++) {
      c2_f_b[c2_i59] = c2_d_hp[c2_i59];
    }

    c2_h_alpha1 = 1.0;
    c2_h_beta1 = 0.0;
    c2_h_TRANSB = 'N';
    c2_h_TRANSA = 'N';
    for (c2_i60 = 0; c2_i60 < 24; c2_i60++) {
      c2_f_y[c2_i60] = 0.0;
    }

    c2_h_m_t = (ptrdiff_t)24;
    c2_h_n_t = (ptrdiff_t)1;
    c2_h_k_t = (ptrdiff_t)48;
    c2_h_lda_t = (ptrdiff_t)24;
    c2_h_ldb_t = (ptrdiff_t)48;
    c2_h_ldc_t = (ptrdiff_t)24;
    dgemm(&c2_h_TRANSA, &c2_h_TRANSB, &c2_h_m_t, &c2_h_n_t, &c2_h_k_t,
          &c2_h_alpha1, &c2_e_b[0], &c2_h_lda_t, &c2_f_b[0], &c2_h_ldb_t,
          &c2_h_beta1, &c2_f_y[0], &c2_h_ldc_t);
    for (c2_i61 = 0; c2_i61 < 24; c2_i61++) {
      c2_delta_p_wt_1[c2_i61] = ((c2_x_low[c2_i61] - c2_x_bar[c2_i61]) -
        c2_c_b[c2_i61]) - c2_f_y[c2_i61];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 74);
    for (c2_i62 = 0; c2_i62 < 24; c2_i62++) {
      c2_c_b[c2_i62] = c2_b_Phi[c2_i62];
    }

    c2_i_b = c2_delta_p_0;
    for (c2_i63 = 0; c2_i63 < 24; c2_i63++) {
      c2_c_b[c2_i63] *= c2_i_b;
    }

    for (c2_i64 = 0; c2_i64 < 1152; c2_i64++) {
      c2_e_b[c2_i64] = c2_b_Psi[c2_i64];
    }

    for (c2_i65 = 0; c2_i65 < 48; c2_i65++) {
      c2_f_b[c2_i65] = c2_d_hp[c2_i65];
    }

    c2_i_alpha1 = 1.0;
    c2_i_beta1 = 0.0;
    c2_i_TRANSB = 'N';
    c2_i_TRANSA = 'N';
    for (c2_i66 = 0; c2_i66 < 24; c2_i66++) {
      c2_f_y[c2_i66] = 0.0;
    }

    c2_i_m_t = (ptrdiff_t)24;
    c2_i_n_t = (ptrdiff_t)1;
    c2_i_k_t = (ptrdiff_t)48;
    c2_i_lda_t = (ptrdiff_t)24;
    c2_i_ldb_t = (ptrdiff_t)48;
    c2_i_ldc_t = (ptrdiff_t)24;
    dgemm(&c2_i_TRANSA, &c2_i_TRANSB, &c2_i_m_t, &c2_i_n_t, &c2_i_k_t,
          &c2_i_alpha1, &c2_e_b[0], &c2_i_lda_t, &c2_f_b[0], &c2_i_ldb_t,
          &c2_i_beta1, &c2_f_y[0], &c2_i_ldc_t);
    for (c2_i67 = 0; c2_i67 < 24; c2_i67++) {
      c2_delta_p_wt_2[c2_i67] = ((c2_x_high[c2_i67] - c2_x_bar[c2_i67]) -
        c2_c_b[c2_i67]) - c2_f_y[c2_i67];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
    c2_U_bar = 0.2;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
    for (c2_i68 = 0; c2_i68 < 48; c2_i68++) {
      c2_U_bar_hp[c2_i68] = 0.2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    c2_u_low = -0.15000000000000002;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
    c2_u_high = 0.75;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 82);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_y1));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14,
                      c2_c_emlrt_marshallOut(chartInstance, c2_cv0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 84);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_y2));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 85);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14,
                      c2_c_emlrt_marshallOut(chartInstance, c2_cv0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 86);
    for (c2_i69 = 0; c2_i69 < 24; c2_i69++) {
      c2_b_delta_p_wt_1[c2_i69] = c2_delta_p_wt_1[c2_i69];
    }

    for (c2_i70 = 0; c2_i70 < 24; c2_i70++) {
      c2_b_delta_p_wt_1[c2_i70 + 24] = c2_delta_p_wt_1[c2_i70];
    }

    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_b_delta_p_wt_1));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14,
                      c2_c_emlrt_marshallOut(chartInstance, c2_cv0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
    for (c2_i71 = 0; c2_i71 < 24; c2_i71++) {
      c2_b_delta_p_wt_2[c2_i71] = c2_delta_p_wt_2[c2_i71];
    }

    for (c2_i72 = 0; c2_i72 < 24; c2_i72++) {
      c2_b_delta_p_wt_2[c2_i72 + 24] = c2_delta_p_wt_2[c2_i72];
    }

    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_b_delta_p_wt_2));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
    for (c2_i73 = 0; c2_i73 < 1152; c2_i73++) {
      c2_a[c2_i73] = c2_b_Lambda_C[c2_i73];
    }

    for (c2_i74 = 0; c2_i74 < 1152; c2_i74++) {
      c2_e_b[c2_i74] = c2_b_Gamma[c2_i74];
    }

    c2_j_alpha1 = 1.0;
    c2_j_beta1 = 0.0;
    c2_j_TRANSB = 'N';
    c2_j_TRANSA = 'N';
    for (c2_i75 = 0; c2_i75 < 2304; c2_i75++) {
      chartInstance->c2_y[c2_i75] = 0.0;
    }

    c2_j_m_t = (ptrdiff_t)48;
    c2_j_n_t = (ptrdiff_t)48;
    c2_j_k_t = (ptrdiff_t)24;
    c2_j_lda_t = (ptrdiff_t)48;
    c2_j_ldb_t = (ptrdiff_t)24;
    c2_j_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_j_TRANSA, &c2_j_TRANSB, &c2_j_m_t, &c2_j_n_t, &c2_j_k_t,
          &c2_j_alpha1, &c2_a[0], &c2_j_lda_t, &c2_e_b[0], &c2_j_ldb_t,
          &c2_j_beta1, &chartInstance->c2_y[0], &c2_j_ldc_t);
    for (c2_i76 = 0; c2_i76 < 2304; c2_i76++) {
      chartInstance->c2_y[c2_i76] += chartInstance->c2_Lambda_A[c2_i76];
    }

    for (c2_i77 = 0; c2_i77 < 2304; c2_i77++) {
      chartInstance->c2_R[c2_i77] = 2.0 * chartInstance->c2_y[c2_i77];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
    c2_i78 = 0;
    for (c2_i79 = 0; c2_i79 < 48; c2_i79++) {
      c2_i81 = 0;
      for (c2_i82 = 0; c2_i82 < 48; c2_i82++) {
        chartInstance->c2_y[c2_i82 + c2_i78] = chartInstance->c2_R[c2_i82 +
          c2_i78] + chartInstance->c2_R[c2_i81 + c2_i79];
        c2_i81 += 48;
      }

      c2_i78 += 48;
    }

    for (c2_i80 = 0; c2_i80 < 2304; c2_i80++) {
      chartInstance->c2_R1[c2_i80] = chartInstance->c2_y[c2_i80] / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
    for (c2_i83 = 0; c2_i83 < 1152; c2_i83++) {
      c2_a[c2_i83] = c2_b_Lambda_C[c2_i83];
    }

    for (c2_i84 = 0; c2_i84 < 1152; c2_i84++) {
      c2_e_b[c2_i84] = c2_b_Gamma[c2_i84];
    }

    c2_k_alpha1 = 1.0;
    c2_k_beta1 = 0.0;
    c2_k_TRANSB = 'N';
    c2_k_TRANSA = 'N';
    for (c2_i85 = 0; c2_i85 < 2304; c2_i85++) {
      chartInstance->c2_y[c2_i85] = 0.0;
    }

    c2_k_m_t = (ptrdiff_t)48;
    c2_k_n_t = (ptrdiff_t)48;
    c2_k_k_t = (ptrdiff_t)24;
    c2_k_lda_t = (ptrdiff_t)48;
    c2_k_ldb_t = (ptrdiff_t)24;
    c2_k_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_k_TRANSA, &c2_k_TRANSB, &c2_k_m_t, &c2_k_n_t, &c2_k_k_t,
          &c2_k_alpha1, &c2_a[0], &c2_k_lda_t, &c2_e_b[0], &c2_k_ldb_t,
          &c2_k_beta1, &chartInstance->c2_y[0], &c2_k_ldc_t);
    for (c2_i86 = 0; c2_i86 < 2304; c2_i86++) {
      chartInstance->c2_y[c2_i86] += chartInstance->c2_Lambda_A[c2_i86];
    }

    c2_l_alpha1 = 1.0;
    for (c2_i87 = 0; c2_i87 < 48; c2_i87++) {
      c2_i_A[c2_i87] = 0.2;
    }

    c2_l_beta1 = 0.0;
    c2_l_TRANSB = 'N';
    c2_l_TRANSA = 'N';
    for (c2_i88 = 0; c2_i88 < 48; c2_i88++) {
      c2_g_y[c2_i88] = 0.0;
    }

    c2_l_m_t = (ptrdiff_t)1;
    c2_l_n_t = (ptrdiff_t)48;
    c2_l_k_t = (ptrdiff_t)48;
    c2_l_lda_t = (ptrdiff_t)1;
    c2_l_ldb_t = (ptrdiff_t)48;
    c2_l_ldc_t = (ptrdiff_t)1;
    dgemm(&c2_l_TRANSA, &c2_l_TRANSB, &c2_l_m_t, &c2_l_n_t, &c2_l_k_t,
          &c2_l_alpha1, &c2_i_A[0], &c2_l_lda_t, &chartInstance->c2_y[0],
          &c2_l_ldb_t, &c2_l_beta1, &c2_g_y[0], &c2_l_ldc_t);
    for (c2_i89 = 0; c2_i89 < 1152; c2_i89++) {
      c2_a[c2_i89] = c2_b_Lambda_C[c2_i89];
    }

    for (c2_i90 = 0; c2_i90 < 1152; c2_i90++) {
      c2_e_b[c2_i90] = c2_b_Psi[c2_i90];
    }

    c2_m_alpha1 = 1.0;
    c2_m_beta1 = 0.0;
    c2_m_TRANSB = 'N';
    c2_m_TRANSA = 'N';
    for (c2_i91 = 0; c2_i91 < 2304; c2_i91++) {
      chartInstance->c2_y[c2_i91] = 0.0;
    }

    c2_m_m_t = (ptrdiff_t)48;
    c2_m_n_t = (ptrdiff_t)48;
    c2_m_k_t = (ptrdiff_t)24;
    c2_m_lda_t = (ptrdiff_t)48;
    c2_m_ldb_t = (ptrdiff_t)24;
    c2_m_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_m_TRANSA, &c2_m_TRANSB, &c2_m_m_t, &c2_m_n_t, &c2_m_k_t,
          &c2_m_alpha1, &c2_a[0], &c2_m_lda_t, &c2_e_b[0], &c2_m_ldb_t,
          &c2_m_beta1, &chartInstance->c2_y[0], &c2_m_ldc_t);
    for (c2_i92 = 0; c2_i92 < 48; c2_i92++) {
      c2_i_A[c2_i92] = c2_d_hp[c2_i92];
    }

    c2_i93 = 0;
    for (c2_i94 = 0; c2_i94 < 48; c2_i94++) {
      c2_i95 = 0;
      for (c2_i96 = 0; c2_i96 < 48; c2_i96++) {
        chartInstance->c2_b[c2_i96 + c2_i93] = chartInstance->c2_Lambda_B[c2_i95
          + c2_i94] + chartInstance->c2_y[c2_i95 + c2_i94];
        c2_i95 += 48;
      }

      c2_i93 += 48;
    }

    c2_n_alpha1 = 1.0;
    c2_n_beta1 = 0.0;
    c2_n_TRANSB = 'N';
    c2_n_TRANSA = 'N';
    for (c2_i97 = 0; c2_i97 < 48; c2_i97++) {
      c2_h_y[c2_i97] = 0.0;
    }

    c2_n_m_t = (ptrdiff_t)1;
    c2_n_n_t = (ptrdiff_t)48;
    c2_n_k_t = (ptrdiff_t)48;
    c2_n_lda_t = (ptrdiff_t)1;
    c2_n_ldb_t = (ptrdiff_t)48;
    c2_n_ldc_t = (ptrdiff_t)1;
    dgemm(&c2_n_TRANSA, &c2_n_TRANSB, &c2_n_m_t, &c2_n_n_t, &c2_n_k_t,
          &c2_n_alpha1, &c2_i_A[0], &c2_n_lda_t, &chartInstance->c2_b[0],
          &c2_n_ldb_t, &c2_n_beta1, &c2_h_y[0], &c2_n_ldc_t);
    for (c2_i98 = 0; c2_i98 < 1152; c2_i98++) {
      c2_a[c2_i98] = c2_b_Lambda_C[c2_i98];
    }

    for (c2_i99 = 0; c2_i99 < 24; c2_i99++) {
      c2_c_b[c2_i99] = c2_b_Phi[c2_i99];
    }

    c2_o_alpha1 = 1.0;
    c2_o_beta1 = 0.0;
    c2_o_TRANSB = 'N';
    c2_o_TRANSA = 'N';
    for (c2_i100 = 0; c2_i100 < 48; c2_i100++) {
      c2_d_y[c2_i100] = 0.0;
    }

    c2_o_m_t = (ptrdiff_t)48;
    c2_o_n_t = (ptrdiff_t)1;
    c2_o_k_t = (ptrdiff_t)24;
    c2_o_lda_t = (ptrdiff_t)48;
    c2_o_ldb_t = (ptrdiff_t)24;
    c2_o_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_o_TRANSA, &c2_o_TRANSB, &c2_o_m_t, &c2_o_n_t, &c2_o_k_t,
          &c2_o_alpha1, &c2_a[0], &c2_o_lda_t, &c2_c_b[0], &c2_o_ldb_t,
          &c2_o_beta1, &c2_d_y[0], &c2_o_ldc_t);
    c2_b_a = c2_delta_p_0;
    for (c2_i101 = 0; c2_i101 < 48; c2_i101++) {
      c2_i_A[c2_i101] = c2_d_y[c2_i101];
    }

    for (c2_i102 = 0; c2_i102 < 48; c2_i102++) {
      c2_i_A[c2_i102] *= c2_b_a;
    }

    for (c2_i103 = 0; c2_i103 < 48; c2_i103++) {
      c2_f[c2_i103] = ((c2_g_y[c2_i103] + c2_h_y[c2_i103]) + c2_i_A[c2_i103]) +
        c2_q_bar_p_hp[c2_i103];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
    sf_mex_printf("%s =\\n", "ans");
    for (c2_i104 = 0; c2_i104 < 2304; c2_i104++) {
      chartInstance->c2_b_R[c2_i104] = chartInstance->c2_R[c2_i104];
    }

    c2_eig(chartInstance, chartInstance->c2_b_R, c2_dcv0);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                      c2_d_emlrt_marshallOut(chartInstance, c2_dcv0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 103);
    c2_i105 = 0;
    c2_i106 = 0;
    for (c2_i107 = 0; c2_i107 < 48; c2_i107++) {
      for (c2_i109 = 0; c2_i109 < 48; c2_i109++) {
        chartInstance->c2_A[c2_i109 + c2_i105] = -chartInstance->c2_L_y[c2_i109
          + c2_i106];
      }

      c2_i105 += 96;
      c2_i106 += 48;
    }

    c2_i108 = 0;
    c2_i110 = 0;
    for (c2_i111 = 0; c2_i111 < 48; c2_i111++) {
      for (c2_i112 = 0; c2_i112 < 48; c2_i112++) {
        chartInstance->c2_A[(c2_i112 + c2_i108) + 48] = chartInstance->
          c2_L_y[c2_i112 + c2_i110];
      }

      c2_i108 += 96;
      c2_i110 += 48;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 104);
    for (c2_i113 = 0; c2_i113 < 48; c2_i113++) {
      c2_b_b[c2_i113] = c2_y1[c2_i113];
    }

    for (c2_i114 = 0; c2_i114 < 48; c2_i114++) {
      c2_b_b[c2_i114 + 48] = c2_y2[c2_i114];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 110);
    for (c2_i115 = 0; c2_i115 < 48; c2_i115++) {
      c2_lb[c2_i115] = -0.15000000000000002;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 111);
    for (c2_i116 = 0; c2_i116 < 48; c2_i116++) {
      c2_ub[c2_i116] = 0.75;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 113);
    sf_mex_assign(&c2_func, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "QP_func", 1U, 2U, 14, c2_e_emlrt_marshallOut(chartInstance,
      chartInstance->c2_R), 14, c2_f_emlrt_marshallOut(chartInstance, c2_f)),
                  false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 117);
    sf_mex_assign(&c2_options, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "optimoptions", 1U, 5U, 14, c2_g_emlrt_marshallOut(chartInstance, c2_cv1),
      14, c2_g_emlrt_marshallOut(chartInstance, c2_cv2), 14,
      c2_h_emlrt_marshallOut(chartInstance, c2_cv3), 14, c2_i_emlrt_marshallOut
      (chartInstance, c2_cv4), 14, c2_j_emlrt_marshallOut(chartInstance, c2_cv5)),
                  false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "quadprog", 4U, 10U, 14,
                      c2_e_emlrt_marshallOut(chartInstance, chartInstance->c2_R),
                      14, c2_f_emlrt_marshallOut(chartInstance, c2_f), 14,
                      c2_k_emlrt_marshallOut(chartInstance), 14,
                      c2_k_emlrt_marshallOut(chartInstance), 14,
                      c2_k_emlrt_marshallOut(chartInstance), 14,
                      c2_k_emlrt_marshallOut(chartInstance), 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_lb), 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_ub), 14,
                      c2_k_emlrt_marshallOut(chartInstance), 14, sf_mex_dup
                      (c2_options), &c2_b_u_hp, &c2_b_fval, &c2_b_exitflag,
                      &c2_b_output);
    c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u_hp), "u_hp", c2_dv2);
    for (c2_i117 = 0; c2_i117 < 48; c2_i117++) {
      c2_u_hp[c2_i117] = c2_dv2[c2_i117];
    }

    sf_mex_assign(&c2_fval, sf_mex_dup(c2_b_fval), false);
    sf_mex_assign(&c2_exitflag, sf_mex_dup(c2_b_exitflag), false);
    sf_mex_assign(&c2_output, sf_mex_dup(c2_b_output), false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 119);
    sf_mex_printf("%s =\\n", "exitflag");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                      sf_mex_dup(c2_exitflag));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
    c2_i118 = 0;
    for (c2_i119 = 0; c2_i119 < 24; c2_i119++) {
      c2_u_hp1[c2_i119] = c2_u_hp[c2_i118];
      c2_i118 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 121);
    c2_i120 = 0;
    for (c2_i121 = 0; c2_i121 < 24; c2_i121++) {
      c2_u_hp2[c2_i121] = c2_u_hp[c2_i120 + 1];
      c2_i120 += 2;
    }

    c2_emxInit_real_T(chartInstance, &c2_i_y, 2, &c2_c_emlrtRTEI);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 123);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14,
                      c2_c_emlrt_marshallOut(chartInstance, c2_cv0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 124);
    c2_c_a = c2_t_h;
    c2_d = c2_t_h + 23.0;
    c2_d_a = c2_c_a;
    c2_j_b = c2_d;
    c2_k_x = c2_d_a;
    c2_k_b = muDoubleScalarIsNaN(c2_k_x);
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (c2_k_b) {
      guard2 = true;
    } else {
      c2_l_x = c2_j_b;
      c2_l_b = muDoubleScalarIsNaN(c2_l_x);
      if (c2_l_b) {
        guard2 = true;
      } else if (c2_j_b < c2_d_a) {
        c2_i123 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = 0;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i123, sizeof(real_T), &c2_emlrtRTEI);
        c2_l_y = c2_i_y->size[0];
        c2_m_y = c2_i_y->size[1];
      } else {
        c2_m_x = c2_d_a;
        c2_m_b = muDoubleScalarIsInf(c2_m_x);
        if (c2_m_b) {
          guard3 = true;
        } else {
          c2_n_x = c2_j_b;
          c2_n_b = muDoubleScalarIsInf(c2_n_x);
          if (c2_n_b) {
            guard3 = true;
          } else {
            guard1 = true;
          }
        }
      }
    }

    if (guard3) {
      if (c2_d_a == c2_j_b) {
        c2_i124 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = 1;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i124, sizeof(real_T), &c2_emlrtRTEI);
        c2_n_y = c2_i_y->size[0];
        c2_o_y = c2_i_y->size[1];
        c2_i_y->data[0] = rtNaN;
      } else {
        guard1 = true;
      }
    }

    if (guard2) {
      c2_i122 = c2_i_y->size[0] * c2_i_y->size[1];
      c2_i_y->size[0] = 1;
      c2_i_y->size[1] = 1;
      c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y, c2_i122,
                           sizeof(real_T), &c2_emlrtRTEI);
      c2_j_y = c2_i_y->size[0];
      c2_k_y = c2_i_y->size[1];
      c2_i_y->data[0] = rtNaN;
    }

    if (guard1) {
      c2_o_x = c2_d_a;
      c2_p_x = c2_o_x;
      c2_p_x = muDoubleScalarFloor(c2_p_x);
      if (c2_p_x == c2_d_a) {
        c2_i125 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = (int32_T)muDoubleScalarFloor(c2_j_b - c2_d_a) + 1;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i125, sizeof(real_T), &c2_emlrtRTEI);
        c2_loop_ub = (int32_T)muDoubleScalarFloor(c2_j_b - c2_d_a);
        for (c2_i126 = 0; c2_i126 <= c2_loop_ub; c2_i126++) {
          c2_i_y->data[c2_i_y->size[0] * c2_i126] = c2_d_a + (real_T)c2_i126;
        }
      } else {
        c2_f_a = c2_d_a;
        c2_o_b = c2_j_b;
        c2_h_a = c2_f_a;
        c2_q_b = c2_o_b;
        c2_anew = c2_h_a;
        c2_r_x = (c2_q_b - c2_h_a) + 0.5;
        c2_ndbl = c2_r_x;
        c2_ndbl = muDoubleScalarFloor(c2_ndbl);
        c2_apnd = c2_h_a + c2_ndbl;
        c2_cdiff = c2_apnd - c2_q_b;
        c2_t_x = c2_cdiff;
        c2_v_x = c2_t_x;
        c2_w_x = c2_v_x;
        c2_r_y = muDoubleScalarAbs(c2_w_x);
        c2_i_a = c2_h_a;
        c2_v_b = c2_q_b;
        c2_y_x = c2_i_a;
        c2_bb_x = c2_y_x;
        c2_db_x = c2_bb_x;
        c2_absa = muDoubleScalarAbs(c2_db_x);
        c2_eb_x = c2_v_b;
        c2_fb_x = c2_eb_x;
        c2_gb_x = c2_fb_x;
        c2_absb = muDoubleScalarAbs(c2_gb_x);
        c2_c = muDoubleScalarMax(c2_absa, c2_absb);
        if (c2_r_y < 4.4408920985006262E-16 * c2_c) {
          c2_ndbl++;
          c2_bnew = c2_q_b;
        } else if (c2_cdiff > 0.0) {
          c2_bnew = c2_h_a + (c2_ndbl - 1.0);
        } else {
          c2_ndbl++;
          c2_bnew = c2_apnd;
        }

        c2_l_a = c2_ndbl;
        c2_m_a = c2_l_a;
        c2_flt = c2_m_a;
        c2_n_too_large = (2.147483647E+9 < c2_flt);
        if (c2_ndbl >= 0.0) {
          c2_n = (int32_T)muDoubleScalarFloor(c2_ndbl);
        } else {
          c2_n = 0;
        }

        c2_p = !c2_n_too_large;
        if (c2_p) {
        } else {
          c2_x_y = NULL;
          sf_mex_assign(&c2_x_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1,
            21), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_x_y));
        }

        c2_i133 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = c2_n;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i133, sizeof(real_T), &c2_b_emlrtRTEI);
        if (c2_n > 0) {
          c2_i_y->data[0] = c2_anew;
          if (c2_n > 1) {
            c2_i_y->data[c2_n - 1] = c2_bnew;
            c2_o_a = c2_n - 1;
            c2_nm1 = c2_o_a;
            c2_p_a = c2_nm1;
            c2_nm1d2 = c2_div_nzp_s32(chartInstance, c2_p_a, 2, 1U, 4650U, 12U);
            c2_s_a = c2_nm1d2 - 1;
            c2_i134 = c2_s_a;
            c2_ab_b = c2_i134;
            c2_bb_b = c2_ab_b;
            c2_overflow = ((!(1 > c2_bb_b)) && (c2_bb_b > 2147483646));
            if (c2_overflow) {
              c2_check_forloop_overflow_error(chartInstance, true);
            }

            for (c2_k = 1; c2_k <= c2_i134; c2_k++) {
              c2_kd = (real_T)c2_k;
              c2_t_a = c2_k + 1;
              c2_d_c = c2_t_a - 1;
              c2_i_y->data[c2_d_c] = c2_anew + c2_kd;
              c2_w_a = c2_n;
              c2_db_b = c2_k;
              c2_g_c = (c2_w_a - c2_db_b) - 1;
              c2_i_y->data[c2_g_c] = c2_bnew - c2_kd;
            }

            c2_cb_b = c2_nm1d2;
            c2_c_c = c2_cb_b << 1;
            if (c2_c_c == c2_nm1) {
              c2_u_a = c2_nm1d2 + 1;
              c2_e_c = c2_u_a - 1;
              c2_i_y->data[c2_e_c] = (c2_anew + c2_bnew) / 2.0;
            } else {
              c2_kd = (real_T)c2_nm1d2;
              c2_v_a = c2_nm1d2 + 1;
              c2_f_c = c2_v_a - 1;
              c2_i_y->data[c2_f_c] = c2_anew + c2_kd;
              c2_y_a = c2_nm1d2 + 2;
              c2_h_c = c2_y_a - 1;
              c2_i_y->data[c2_h_c] = c2_bnew - c2_kd;
            }
          }
        }
      }
    }

    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 2U, 14,
                      c2_l_emlrt_marshallOut(chartInstance, c2_i_y), 14,
                      c2_m_emlrt_marshallOut(chartInstance, c2_u_hp1));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 125);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14,
                      c2_c_emlrt_marshallOut(chartInstance, c2_cv0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 126);
    c2_e_a = c2_t_h;
    c2_b_d = c2_t_h + 23.0;
    c2_g_a = c2_e_a;
    c2_p_b = c2_b_d;
    c2_q_x = c2_g_a;
    c2_r_b = muDoubleScalarIsNaN(c2_q_x);
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (c2_r_b) {
      guard2 = true;
    } else {
      c2_s_x = c2_p_b;
      c2_s_b = muDoubleScalarIsNaN(c2_s_x);
      if (c2_s_b) {
        guard2 = true;
      } else if (c2_p_b < c2_g_a) {
        c2_i128 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = 0;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i128, sizeof(real_T), &c2_emlrtRTEI);
        c2_s_y = c2_i_y->size[0];
        c2_t_y = c2_i_y->size[1];
      } else {
        c2_u_x = c2_g_a;
        c2_t_b = muDoubleScalarIsInf(c2_u_x);
        if (c2_t_b) {
          guard3 = true;
        } else {
          c2_x_x = c2_p_b;
          c2_u_b = muDoubleScalarIsInf(c2_x_x);
          if (c2_u_b) {
            guard3 = true;
          } else {
            guard1 = true;
          }
        }
      }
    }

    if (guard3) {
      if (c2_g_a == c2_p_b) {
        c2_i129 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = 1;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i129, sizeof(real_T), &c2_emlrtRTEI);
        c2_u_y = c2_i_y->size[0];
        c2_v_y = c2_i_y->size[1];
        c2_i_y->data[0] = rtNaN;
      } else {
        guard1 = true;
      }
    }

    if (guard2) {
      c2_i127 = c2_i_y->size[0] * c2_i_y->size[1];
      c2_i_y->size[0] = 1;
      c2_i_y->size[1] = 1;
      c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y, c2_i127,
                           sizeof(real_T), &c2_emlrtRTEI);
      c2_p_y = c2_i_y->size[0];
      c2_q_y = c2_i_y->size[1];
      c2_i_y->data[0] = rtNaN;
    }

    if (guard1) {
      c2_ab_x = c2_g_a;
      c2_cb_x = c2_ab_x;
      c2_cb_x = muDoubleScalarFloor(c2_cb_x);
      if (c2_cb_x == c2_g_a) {
        c2_i130 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = (int32_T)muDoubleScalarFloor(c2_p_b - c2_g_a) + 1;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i130, sizeof(real_T), &c2_emlrtRTEI);
        c2_b_loop_ub = (int32_T)muDoubleScalarFloor(c2_p_b - c2_g_a);
        for (c2_i132 = 0; c2_i132 <= c2_b_loop_ub; c2_i132++) {
          c2_i_y->data[c2_i_y->size[0] * c2_i132] = c2_g_a + (real_T)c2_i132;
        }
      } else {
        c2_j_a = c2_g_a;
        c2_w_b = c2_p_b;
        c2_k_a = c2_j_a;
        c2_x_b = c2_w_b;
        c2_b_anew = c2_k_a;
        c2_hb_x = (c2_x_b - c2_k_a) + 0.5;
        c2_b_ndbl = c2_hb_x;
        c2_b_ndbl = muDoubleScalarFloor(c2_b_ndbl);
        c2_b_apnd = c2_k_a + c2_b_ndbl;
        c2_b_cdiff = c2_b_apnd - c2_x_b;
        c2_ib_x = c2_b_cdiff;
        c2_jb_x = c2_ib_x;
        c2_kb_x = c2_jb_x;
        c2_w_y = muDoubleScalarAbs(c2_kb_x);
        c2_n_a = c2_k_a;
        c2_y_b = c2_x_b;
        c2_lb_x = c2_n_a;
        c2_mb_x = c2_lb_x;
        c2_nb_x = c2_mb_x;
        c2_b_absa = muDoubleScalarAbs(c2_nb_x);
        c2_ob_x = c2_y_b;
        c2_pb_x = c2_ob_x;
        c2_qb_x = c2_pb_x;
        c2_b_absb = muDoubleScalarAbs(c2_qb_x);
        c2_b_c = muDoubleScalarMax(c2_b_absa, c2_b_absb);
        if (c2_w_y < 4.4408920985006262E-16 * c2_b_c) {
          c2_b_ndbl++;
          c2_b_bnew = c2_x_b;
        } else if (c2_b_cdiff > 0.0) {
          c2_b_bnew = c2_k_a + (c2_b_ndbl - 1.0);
        } else {
          c2_b_ndbl++;
          c2_b_bnew = c2_b_apnd;
        }

        c2_q_a = c2_b_ndbl;
        c2_r_a = c2_q_a;
        c2_b_flt = c2_r_a;
        c2_b_n_too_large = (2.147483647E+9 < c2_b_flt);
        if (c2_b_ndbl >= 0.0) {
          c2_b_n = (int32_T)muDoubleScalarFloor(c2_b_ndbl);
        } else {
          c2_b_n = 0;
        }

        c2_b_p = !c2_b_n_too_large;
        if (c2_b_p) {
        } else {
          c2_y_y = NULL;
          sf_mex_assign(&c2_y_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1,
            21), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_y_y));
        }

        c2_i135 = c2_i_y->size[0] * c2_i_y->size[1];
        c2_i_y->size[0] = 1;
        c2_i_y->size[1] = c2_b_n;
        c2_emxEnsureCapacity(chartInstance, (c2_emxArray__common *)c2_i_y,
                             c2_i135, sizeof(real_T), &c2_b_emlrtRTEI);
        if (c2_b_n > 0) {
          c2_i_y->data[0] = c2_b_anew;
          if (c2_b_n > 1) {
            c2_i_y->data[c2_b_n - 1] = c2_b_bnew;
            c2_x_a = c2_b_n - 1;
            c2_b_nm1 = c2_x_a;
            c2_ab_a = c2_b_nm1;
            c2_b_nm1d2 = c2_div_nzp_s32(chartInstance, c2_ab_a, 2, 1U, 4691U,
              12U);
            c2_bb_a = c2_b_nm1d2 - 1;
            c2_i136 = c2_bb_a;
            c2_eb_b = c2_i136;
            c2_fb_b = c2_eb_b;
            c2_b_overflow = ((!(1 > c2_fb_b)) && (c2_fb_b > 2147483646));
            if (c2_b_overflow) {
              c2_check_forloop_overflow_error(chartInstance, true);
            }

            for (c2_b_k = 1; c2_b_k <= c2_i136; c2_b_k++) {
              c2_b_kd = (real_T)c2_b_k;
              c2_cb_a = c2_b_k + 1;
              c2_j_c = c2_cb_a - 1;
              c2_i_y->data[c2_j_c] = c2_b_anew + c2_b_kd;
              c2_fb_a = c2_b_n;
              c2_hb_b = c2_b_k;
              c2_m_c = (c2_fb_a - c2_hb_b) - 1;
              c2_i_y->data[c2_m_c] = c2_b_bnew - c2_b_kd;
            }

            c2_gb_b = c2_b_nm1d2;
            c2_i_c = c2_gb_b << 1;
            if (c2_i_c == c2_b_nm1) {
              c2_db_a = c2_b_nm1d2 + 1;
              c2_k_c = c2_db_a - 1;
              c2_i_y->data[c2_k_c] = (c2_b_anew + c2_b_bnew) / 2.0;
            } else {
              c2_b_kd = (real_T)c2_b_nm1d2;
              c2_eb_a = c2_b_nm1d2 + 1;
              c2_l_c = c2_eb_a - 1;
              c2_i_y->data[c2_l_c] = c2_b_anew + c2_b_kd;
              c2_gb_a = c2_b_nm1d2 + 2;
              c2_n_c = c2_gb_a - 1;
              c2_i_y->data[c2_n_c] = c2_b_bnew - c2_b_kd;
            }
          }
        }
      }
    }

    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 2U, 14,
                      c2_l_emlrt_marshallOut(chartInstance, c2_i_y), 14,
                      c2_m_emlrt_marshallOut(chartInstance, c2_u_hp2));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 128U);
    c2_b_u[0] = c2_u_hp1[0];
    c2_b_u[1] = c2_u_hp2[0];
    sf_mex_printf("%s =\\n", "u");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                      c2_n_emlrt_marshallOut(chartInstance, c2_b_u));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 129U);
    c2_emxFree_real_T(chartInstance, &c2_i_y);
    for (c2_i131 = 0; c2_i131 < 2; c2_i131++) {
      c2_b_u_old[c2_i131] = c2_b_u[c2_i131];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 131U);
    for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
      c2_b_u[c2_i10] = c2_b_u_old[c2_i10];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -131);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c2_func);
  sf_mex_destroy(&c2_options);
  sf_mex_destroy(&c2_fval);
  sf_mex_destroy(&c2_exitflag);
  sf_mex_destroy(&c2_output);
  sf_mex_destroy(&c2_b_u_hp);
  sf_mex_destroy(&c2_b_fval);
  sf_mex_destroy(&c2_b_exitflag);
  sf_mex_destroy(&c2_b_output);
  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    (*chartInstance->c2_u)[c2_i14] = c2_b_u[c2_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_simulering(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i137;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[2];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i137 = 0; c2_i137 < 2; c2_i137++) {
    c2_b_u[c2_i137] = (*(real_T (*)[2])c2_inData)[c2_i137];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const char_T *c2_identifier, real_T c2_b_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b_u);
}

static void c2_b_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[2])
{
  real_T c2_dv3[2];
  int32_T c2_i138;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i138 = 0; c2_i138 < 2; c2_i138++) {
    c2_b_y[c2_i138] = c2_dv3[c2_i138];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[2];
  int32_T c2_i139;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_b_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b_u);
  for (c2_i139 = 0; c2_i139 < 2; c2_i139++) {
    (*(real_T (*)[2])c2_outData)[c2_i139] = c2_b_y[c2_i139];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i140;
  int32_T c2_i141;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i142;
  real_T c2_b_u[1152];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i140 = 0;
  for (c2_i141 = 0; c2_i141 < 24; c2_i141++) {
    for (c2_i142 = 0; c2_i142 < 48; c2_i142++) {
      c2_b_u[c2_i142 + c2_i140] = (*(real_T (*)[1152])c2_inData)[c2_i142 +
        c2_i140];
    }

    c2_i140 += 48;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 48, 24),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i143;
  int32_T c2_i144;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i145;
  real_T c2_b_u[2304];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i143 = 0;
  for (c2_i144 = 0; c2_i144 < 48; c2_i144++) {
    for (c2_i145 = 0; c2_i145 < 48; c2_i145++) {
      c2_b_u[c2_i145 + c2_i143] = (*(real_T (*)[2304])c2_inData)[c2_i145 +
        c2_i143];
    }

    c2_i143 += 48;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout),
    &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Theta;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[1152];
  int32_T c2_i146;
  int32_T c2_i147;
  int32_T c2_i148;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_Theta = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Theta), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_Theta);
  c2_i146 = 0;
  for (c2_i147 = 0; c2_i147 < 24; c2_i147++) {
    for (c2_i148 = 0; c2_i148 < 48; c2_i148++) {
      (*(real_T (*)[1152])c2_outData)[c2_i148 + c2_i146] = c2_b_y[c2_i148 +
        c2_i146];
    }

    c2_i146 += 48;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i149;
  int32_T c2_i150;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i151;
  real_T c2_b_u[1152];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i149 = 0;
  for (c2_i150 = 0; c2_i150 < 48; c2_i150++) {
    for (c2_i151 = 0; c2_i151 < 24; c2_i151++) {
      c2_b_u[c2_i151 + c2_i149] = (*(real_T (*)[1152])c2_inData)[c2_i151 +
        c2_i149];
    }

    c2_i149 += 24;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 24, 48),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Psi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[1152];
  int32_T c2_i152;
  int32_T c2_i153;
  int32_T c2_i154;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_Psi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Psi), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_Psi);
  c2_i152 = 0;
  for (c2_i153 = 0; c2_i153 < 48; c2_i153++) {
    for (c2_i154 = 0; c2_i154 < 24; c2_i154++) {
      (*(real_T (*)[1152])c2_outData)[c2_i154 + c2_i152] = c2_b_y[c2_i154 +
        c2_i152];
    }

    c2_i152 += 24;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_c_Pi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[2304];
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_i157;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_c_Pi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_Pi), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_c_Pi);
  c2_i155 = 0;
  for (c2_i156 = 0; c2_i156 < 48; c2_i156++) {
    for (c2_i157 = 0; c2_i157 < 48; c2_i157++) {
      (*(real_T (*)[2304])c2_outData)[c2_i157 + c2_i155] = c2_b_y[c2_i157 +
        c2_i155];
    }

    c2_i155 += 48;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i158;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[24];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i158 = 0; c2_i158 < 24; c2_i158++) {
    c2_b_u[c2_i158] = (*(real_T (*)[24])c2_inData)[c2_i158];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Phi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[24];
  int32_T c2_i159;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_Phi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Phi), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_Phi);
  for (c2_i159 = 0; c2_i159 < 24; c2_i159++) {
    (*(real_T (*)[24])c2_outData)[c2_i159] = c2_b_y[c2_i159];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i160;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[168];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i160 = 0; c2_i160 < 168; c2_i160++) {
    c2_b_u[c2_i160] = (*(real_T (*)[168])c2_inData)[c2_i160];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 168),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_data;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[168];
  int32_T c2_i161;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_data), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_data);
  for (c2_i161 = 0; c2_i161 < 168; c2_i161++) {
    (*(real_T (*)[168])c2_outData)[c2_i161] = c2_b_y[c2_i161];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  const mxArray *c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = sf_mex_dup(*(const mxArray **)c2_inData);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_duplicatearraysafe(&c2_b_u), false);
  sf_mex_destroy(&c2_b_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i162;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[48];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i162 = 0; c2_i162 < 48; c2_i162++) {
    c2_b_u[c2_i162] = (*(real_T (*)[48])c2_inData)[c2_i162];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 48), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_u_hp;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[48];
  int32_T c2_i163;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_u_hp = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_u_hp), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_u_hp);
  for (c2_i163 = 0; c2_i163 < 48; c2_i163++) {
    (*(real_T (*)[48])c2_outData)[c2_i163] = c2_b_y[c2_i163];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i164;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[96];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i164 = 0; c2_i164 < 96; c2_i164++) {
    c2_b_u[c2_i164] = (*(real_T (*)[96])c2_inData)[c2_i164];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 96), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[96])
{
  real_T c2_dv4[96];
  int32_T c2_i165;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv4, 1, 0, 0U, 1, 0U, 1, 96);
  for (c2_i165 = 0; c2_i165 < 96; c2_i165++) {
    c2_b_y[c2_i165] = c2_dv4[c2_i165];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_b;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[96];
  int32_T c2_i166;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_b_b = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_b), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b_b);
  for (c2_i166 = 0; c2_i166 < 96; c2_i166++) {
    (*(real_T (*)[96])c2_outData)[c2_i166] = c2_b_y[c2_i166];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i167;
  int32_T c2_i168;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i169;
  real_T c2_b_u[4608];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i167 = 0;
  for (c2_i168 = 0; c2_i168 < 48; c2_i168++) {
    for (c2_i169 = 0; c2_i169 < 96; c2_i169++) {
      c2_b_u[c2_i169 + c2_i167] = (*(real_T (*)[4608])c2_inData)[c2_i169 +
        c2_i167];
    }

    c2_i167 += 96;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 96, 48),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [4608])
{
  real_T c2_dv5[4608];
  int32_T c2_i170;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv5, 1, 0, 0U, 1, 0U, 2, 96,
                48);
  for (c2_i170 = 0; c2_i170 < 4608; c2_i170++) {
    c2_b_y[c2_i170] = c2_dv5[c2_i170];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_g_A;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[4608];
  int32_T c2_i171;
  int32_T c2_i172;
  int32_T c2_i173;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_g_A = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_g_A), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_g_A);
  c2_i171 = 0;
  for (c2_i172 = 0; c2_i172 < 48; c2_i172++) {
    for (c2_i173 = 0; c2_i173 < 96; c2_i173++) {
      (*(real_T (*)[4608])c2_outData)[c2_i173 + c2_i171] = c2_b_y[c2_i173 +
        c2_i171];
    }

    c2_i171 += 96;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i174;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[48];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i174 = 0; c2_i174 < 48; c2_i174++) {
    c2_b_u[c2_i174] = (*(real_T (*)[48])c2_inData)[c2_i174];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 48),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[48])
{
  real_T c2_dv6[48];
  int32_T c2_i175;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                48);
  for (c2_i175 = 0; c2_i175 < 48; c2_i175++) {
    c2_b_y[c2_i175] = c2_dv6[c2_i175];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_f;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[48];
  int32_T c2_i176;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_f = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_f), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_f);
  for (c2_i176 = 0; c2_i176 < 48; c2_i176++) {
    (*(real_T (*)[48])c2_outData)[c2_i176] = c2_b_y[c2_i176];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i177;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[24];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_shjtd7pXyPLVVdClb9GNBeB *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i177 = 0; c2_i177 < 24; c2_i177++) {
    c2_c_u[c2_i177] = c2_b_u.constant_dist[c2_i177];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "constant_dist", "constant_dist", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_shjtd7pXyPLVVdClb9GNBeB *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_spEGmxEyHM6EoZZcXmG7jeB c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i178;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[1152];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_spEGmxEyHM6EoZZcXmG7jeB *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i178 = 0; c2_i178 < 1152; c2_i178++) {
    c2_c_u[c2_i178] = c2_b_u.Theta[c2_i178];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 48, 24),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Theta", "Theta", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_spEGmxEyHM6EoZZcXmG7jeB c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_spEGmxEyHM6EoZZcXmG7jeB *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sVXPIQCYRVtgDunkSIgrZND c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i179;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[1152];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sVXPIQCYRVtgDunkSIgrZND *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i179 = 0; c2_i179 < 1152; c2_i179++) {
    c2_c_u[c2_i179] = c2_b_u.Psi[c2_i179];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 24, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Psi", "Psi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sVXPIQCYRVtgDunkSIgrZND c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sVXPIQCYRVtgDunkSIgrZND *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sjdLzyTh14ULkIImcl6xwW c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i180;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[2304];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sjdLzyTh14ULkIImcl6xwW *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i180 = 0; c2_i180 < 2304; c2_i180++) {
    c2_c_u[c2_i180] = c2_b_u.Pi[c2_i180];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Pi", "Pi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sjdLzyTh14ULkIImcl6xwW c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sjdLzyTh14ULkIImcl6xwW *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sXRXp7aMGjI8fA8IXQDoqtG c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i181;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[24];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sXRXp7aMGjI8fA8IXQDoqtG *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i181 = 0; c2_i181 < 24; c2_i181++) {
    c2_c_u[c2_i181] = c2_b_u.Phi[c2_i181];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Phi", "Phi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sXRXp7aMGjI8fA8IXQDoqtG c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sXRXp7aMGjI8fA8IXQDoqtG *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sHr555XKyGoUpad7tsiNQiE c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i182;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[2304];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sHr555XKyGoUpad7tsiNQiE *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i182 = 0; c2_i182 < 2304; c2_i182++) {
    c2_c_u[c2_i182] = c2_b_u.Omega[c2_i182];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Omega", "Omega", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sHr555XKyGoUpad7tsiNQiE c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sHr555XKyGoUpad7tsiNQiE *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sDEl41izlL3fNQfEgJJ5XBH c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i183;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[1152];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sDEl41izlL3fNQfEgJJ5XBH *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i183 = 0; c2_i183 < 1152; c2_i183++) {
    c2_c_u[c2_i183] = c2_b_u.Gamma[c2_i183];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 24, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Gamma", "Gamma", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sDEl41izlL3fNQfEgJJ5XBH c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sDEl41izlL3fNQfEgJJ5XBH *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i184;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[168];
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sAv0WliXUXwSlTp2NM3P4jE *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i184 = 0; c2_i184 < 168; c2_i184++) {
    c2_c_u[c2_i184] = c2_b_u.data[c2_i184];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 168),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "data", "data", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sAv0WliXUXwSlTp2NM3P4jE *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_simulering_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_eig(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_g_A
                   [2304], creal_T c2_V[48])
{
  int32_T c2_info;
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_i187;
  int32_T c2_i188;
  int32_T c2_i189;
  int32_T c2_b_info;
  c2_info = 0;
  for (c2_i185 = 0; c2_i185 < 2304; c2_i185++) {
    chartInstance->c2_b_A[c2_i185] = c2_g_A[c2_i185];
  }

  if (c2_anyNonFinite(chartInstance, chartInstance->c2_b_A)) {
    for (c2_i187 = 0; c2_i187 < 48; c2_i187++) {
      c2_V[c2_i187].re = rtNaN;
      c2_V[c2_i187].im = 0.0;
    }
  } else {
    for (c2_i186 = 0; c2_i186 < 2304; c2_i186++) {
      chartInstance->c2_c_A[c2_i186] = c2_g_A[c2_i186];
    }

    if (c2_ishermitian(chartInstance, chartInstance->c2_c_A)) {
      for (c2_i189 = 0; c2_i189 < 2304; c2_i189++) {
        chartInstance->c2_e_A[c2_i189] = c2_g_A[c2_i189];
      }

      c2_schur(chartInstance, chartInstance->c2_e_A, chartInstance->c2_T);
      c2_mainDiagZeroImag(chartInstance, chartInstance->c2_T, c2_V);
    } else {
      for (c2_i188 = 0; c2_i188 < 2304; c2_i188++) {
        chartInstance->c2_d_A[c2_i188] = c2_g_A[c2_i188];
      }

      c2_xgeev(chartInstance, chartInstance->c2_d_A, &c2_b_info, c2_V);
      c2_info = c2_b_info;
    }

    if ((real_T)c2_info != 0.0) {
      c2_b_warning(chartInstance);
    }
  }
}

static boolean_T c2_anyNonFinite(SFc2_simuleringInstanceStruct *chartInstance,
  real_T c2_b_x[2304])
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_c_x;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  real_T c2_d_x;
  boolean_T c2_c_b;
  (void)chartInstance;
  c2_p = false;
  for (c2_k = 0; c2_k + 1 < 2305; c2_k++) {
    if (c2_p) {
      c2_b_p = true;
    } else {
      c2_c_x = c2_b_x[c2_k];
      c2_b_b = muDoubleScalarIsInf(c2_c_x);
      if (c2_b_b) {
        c2_b_p = true;
      } else {
        c2_d_x = c2_b_x[c2_k];
        c2_c_b = muDoubleScalarIsNaN(c2_d_x);
        if (c2_c_b) {
          c2_b_p = true;
        } else {
          c2_b_p = false;
        }
      }
    }

    c2_p = c2_b_p;
  }

  return c2_p;
}

static boolean_T c2_ishermitian(SFc2_simuleringInstanceStruct *chartInstance,
  real_T c2_g_A[2304])
{
  boolean_T c2_p;
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i190;
  int32_T c2_i;
  real_T c2_b_i;
  int32_T exitg1;
  boolean_T exitg2;
  (void)chartInstance;
  c2_p = true;
  c2_j = 0;
  exitg2 = false;
  while ((!exitg2) && (c2_j < 48)) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_i190 = (int32_T)c2_b_j - 1;
    c2_i = 0;
    do {
      exitg1 = 0;
      if (c2_i <= c2_i190) {
        c2_b_i = 1.0 + (real_T)c2_i;
        if (!(c2_g_A[((int32_T)c2_b_i + 48 * ((int32_T)c2_b_j - 1)) - 1] ==
              c2_g_A[((int32_T)c2_b_j + 48 * ((int32_T)c2_b_i - 1)) - 1])) {
          c2_p = false;
          exitg1 = 1;
        } else {
          c2_i++;
        }
      } else {
        c2_j++;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return c2_p;
}

static void c2_schur(SFc2_simuleringInstanceStruct *chartInstance, real_T
                     c2_g_A[2304], creal_T c2_V[2304])
{
  int32_T c2_i191;
  int32_T c2_i192;
  int32_T c2_i193;
  int32_T c2_info;
  real_T c2_Vr[2304];
  for (c2_i191 = 0; c2_i191 < 2304; c2_i191++) {
    chartInstance->c2_f_A[c2_i191] = c2_g_A[c2_i191];
  }

  if (c2_anyNonFinite(chartInstance, chartInstance->c2_f_A)) {
    for (c2_i192 = 0; c2_i192 < 2304; c2_i192++) {
      c2_V[c2_i192].re = rtNaN;
      c2_V[c2_i192].im = 0.0;
    }

    c2_b_triu(chartInstance, c2_V);
  } else {
    c2_b_xgehrd(chartInstance, c2_g_A);
    for (c2_i193 = 0; c2_i193 < 2304; c2_i193++) {
      c2_Vr[c2_i193] = c2_g_A[c2_i193];
    }

    c2_info = c2_b_xhseqr(chartInstance, c2_Vr);
    c2_eml_rsf2csf(chartInstance, c2_Vr, c2_V);
    if ((real_T)c2_info != 0.0) {
      c2_warning(chartInstance);
    }
  }
}

static void c2_triu(SFc2_simuleringInstanceStruct *chartInstance, creal_T
                    c2_b_x[2304], creal_T c2_c_x[2304])
{
  int32_T c2_i194;
  for (c2_i194 = 0; c2_i194 < 2304; c2_i194++) {
    c2_c_x[c2_i194] = c2_b_x[c2_i194];
  }

  c2_b_triu(chartInstance, c2_c_x);
}

static void c2_check_forloop_overflow_error(SFc2_simuleringInstanceStruct
  *chartInstance, boolean_T c2_overflow)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv8[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv9[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c2_overflow;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_b_y, 14, c2_c_y));
}

static void c2_xgehrd(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_a
                      [2304], real_T c2_b_a[2304])
{
  int32_T c2_i195;
  for (c2_i195 = 0; c2_i195 < 2304; c2_i195++) {
    c2_b_a[c2_i195] = c2_a[c2_i195];
  }

  c2_b_xgehrd(chartInstance, c2_b_a);
}

static void c2_xzlarfg(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, real_T c2_alpha1, real_T c2_b_x[2304], int32_T c2_ix0, real_T
  *c2_b_alpha1, real_T c2_c_x[2304], real_T *c2_tau)
{
  int32_T c2_i196;
  *c2_b_alpha1 = c2_alpha1;
  for (c2_i196 = 0; c2_i196 < 2304; c2_i196++) {
    c2_c_x[c2_i196] = c2_b_x[c2_i196];
  }

  *c2_tau = c2_b_xzlarfg(chartInstance, c2_n, c2_b_alpha1, c2_c_x, c2_ix0);
}

static real_T c2_xnrm2(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, real_T c2_b_x[2304], int32_T c2_ix0)
{
  real_T c2_b_y;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  real_T c2_scale;
  real_T c2_c_x;
  int32_T c2_a;
  real_T c2_d_x;
  int32_T c2_c;
  real_T c2_e_x;
  int32_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_c_a;
  int32_T c2_b_b;
  int32_T c2_kend;
  int32_T c2_d_a;
  int32_T c2_c_b;
  int32_T c2_e_a;
  int32_T c2_d_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_absxk;
  real_T c2_t;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_y = 0.0;
  if (c2_b_n < 1) {
  } else if (c2_b_n == 1) {
    c2_c_x = c2_b_x[c2_b_ix0 - 1];
    c2_d_x = c2_c_x;
    c2_e_x = c2_d_x;
    c2_b_y = muDoubleScalarAbs(c2_e_x);
  } else {
    c2_scale = 2.2250738585072014E-308;
    c2_a = c2_b_n;
    c2_c = c2_a;
    c2_b_a = c2_c - 1;
    c2_b_c = c2_b_a;
    c2_c_a = c2_b_ix0;
    c2_b_b = c2_b_c;
    c2_kend = c2_c_a + c2_b_b;
    c2_d_a = c2_b_ix0;
    c2_c_b = c2_kend;
    c2_e_a = c2_d_a;
    c2_d_b = c2_c_b;
    c2_overflow = ((!(c2_e_a > c2_d_b)) && (c2_d_b > 2147483646));
    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k = c2_b_ix0; c2_k <= c2_kend; c2_k++) {
      c2_f_x = c2_b_x[c2_k - 1];
      c2_g_x = c2_f_x;
      c2_h_x = c2_g_x;
      c2_absxk = muDoubleScalarAbs(c2_h_x);
      if (c2_absxk > c2_scale) {
        c2_t = c2_scale / c2_absxk;
        c2_b_y = 1.0 + c2_b_y * c2_t * c2_t;
        c2_scale = c2_absxk;
      } else {
        c2_t = c2_absxk / c2_scale;
        c2_b_y += c2_t * c2_t;
      }
    }

    c2_b_y = c2_scale * muDoubleScalarSqrt(c2_b_y);
  }

  return c2_b_y;
}

static void c2_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_n,
                      int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T
                      c2_ic0, real_T c2_work[48], real_T c2_b_C[2304], real_T
                      c2_b_work[48])
{
  int32_T c2_i197;
  int32_T c2_i198;
  for (c2_i197 = 0; c2_i197 < 2304; c2_i197++) {
    c2_b_C[c2_i197] = c2_C[c2_i197];
  }

  for (c2_i198 = 0; c2_i198 < 48; c2_i198++) {
    c2_b_work[c2_i198] = c2_work[c2_i198];
  }

  c2_c_xzlarf(chartInstance, c2_n, c2_iv0, c2_tau, c2_b_C, c2_ic0, c2_b_work);
}

static void c2_ilazlr(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                      int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, int32_T
                      *c2_i, real_T c2_h_A[2304])
{
  int32_T c2_i199;
  for (c2_i199 = 0; c2_i199 < 2304; c2_i199++) {
    c2_h_A[c2_i199] = c2_g_A[c2_i199];
  }

  *c2_i = c2_b_ilazlr(chartInstance, c2_m, c2_n, c2_h_A, c2_ia0);
}

static void c2_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                     int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T
                     c2_b_x[2304], int32_T c2_ix0, real_T c2_b_y[48], real_T
                     c2_c_y[48])
{
  int32_T c2_i200;
  int32_T c2_i201;
  int32_T c2_i202;
  real_T c2_h_A[2304];
  real_T c2_c_x[2304];
  for (c2_i200 = 0; c2_i200 < 48; c2_i200++) {
    c2_c_y[c2_i200] = c2_b_y[c2_i200];
  }

  for (c2_i201 = 0; c2_i201 < 2304; c2_i201++) {
    c2_h_A[c2_i201] = c2_g_A[c2_i201];
  }

  for (c2_i202 = 0; c2_i202 < 2304; c2_i202++) {
    c2_c_x[c2_i202] = c2_b_x[c2_i202];
  }

  c2_c_xgemv(chartInstance, c2_m, c2_n, c2_h_A, c2_ia0, c2_c_x, c2_ix0, c2_c_y);
}

static void c2_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                     int32_T c2_n, real_T c2_alpha1, real_T c2_b_x[48], int32_T
                     c2_iy0, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_h_A
                     [2304])
{
  int32_T c2_i203;
  int32_T c2_i204;
  real_T c2_c_x[48];
  for (c2_i203 = 0; c2_i203 < 2304; c2_i203++) {
    c2_h_A[c2_i203] = c2_g_A[c2_i203];
  }

  for (c2_i204 = 0; c2_i204 < 48; c2_i204++) {
    c2_c_x[c2_i204] = c2_b_x[c2_i204];
  }

  c2_c_xgerc(chartInstance, c2_m, c2_n, c2_alpha1, c2_c_x, c2_iy0, c2_h_A,
             c2_ia0);
}

static void c2_b_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T
  c2_ic0, real_T c2_work[48], real_T c2_b_C[2304], real_T c2_b_work[48])
{
  int32_T c2_i205;
  int32_T c2_i206;
  for (c2_i205 = 0; c2_i205 < 2304; c2_i205++) {
    c2_b_C[c2_i205] = c2_C[c2_i205];
  }

  for (c2_i206 = 0; c2_i206 < 48; c2_i206++) {
    c2_b_work[c2_i206] = c2_work[c2_i206];
  }

  c2_d_xzlarf(chartInstance, c2_m, c2_n, c2_iv0, c2_tau, c2_b_C, c2_ic0,
              c2_b_work);
}

static void c2_ilazlc(SFc2_simuleringInstanceStruct *chartInstance, int32_T c2_m,
                      int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, int32_T
                      c2_lda, int32_T *c2_j, real_T c2_h_A[2304])
{
  int32_T c2_i207;
  for (c2_i207 = 0; c2_i207 < 2304; c2_i207++) {
    c2_h_A[c2_i207] = c2_g_A[c2_i207];
  }

  *c2_j = c2_b_ilazlc(chartInstance, c2_m, c2_n, c2_h_A, c2_ia0, c2_lda);
}

static void c2_b_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_b_x[2304],
  int32_T c2_ix0, real_T c2_b_y[48], real_T c2_c_y[48])
{
  int32_T c2_i208;
  int32_T c2_i209;
  int32_T c2_i210;
  real_T c2_h_A[2304];
  real_T c2_c_x[2304];
  for (c2_i208 = 0; c2_i208 < 48; c2_i208++) {
    c2_c_y[c2_i208] = c2_b_y[c2_i208];
  }

  for (c2_i209 = 0; c2_i209 < 2304; c2_i209++) {
    c2_h_A[c2_i209] = c2_g_A[c2_i209];
  }

  for (c2_i210 = 0; c2_i210 < 2304; c2_i210++) {
    c2_c_x[c2_i210] = c2_b_x[c2_i210];
  }

  c2_d_xgemv(chartInstance, c2_m, c2_n, c2_h_A, c2_ia0, c2_c_x, c2_ix0, c2_c_y);
}

static void c2_b_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, real_T c2_b_y[48],
  real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_h_A[2304])
{
  int32_T c2_i211;
  int32_T c2_i212;
  real_T c2_c_y[48];
  for (c2_i211 = 0; c2_i211 < 2304; c2_i211++) {
    c2_h_A[c2_i211] = c2_g_A[c2_i211];
  }

  for (c2_i212 = 0; c2_i212 < 48; c2_i212++) {
    c2_c_y[c2_i212] = c2_b_y[c2_i212];
  }

  c2_d_xgerc(chartInstance, c2_m, c2_n, c2_alpha1, c2_ix0, c2_c_y, c2_h_A,
             c2_ia0);
}

static void c2_xhseqr(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_h
                      [2304], real_T c2_b_h[2304], int32_T *c2_info)
{
  int32_T c2_i213;
  for (c2_i213 = 0; c2_i213 < 2304; c2_i213++) {
    c2_b_h[c2_i213] = c2_h[c2_i213];
  }

  *c2_info = c2_b_xhseqr(chartInstance, c2_b_h);
}

static void c2_error(SFc2_simuleringInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv10[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv10, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_b_y));
}

static void c2_b_error(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_varargin_2)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv11[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv12[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'h',
    's', 'e', 'q', 'r' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv11, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv12, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y));
}

static void c2_c_error(SFc2_simuleringInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv13[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv14[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv13, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv14, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_b_y, 14, c2_c_y));
}

static void c2_xdlanv2(SFc2_simuleringInstanceStruct *chartInstance, real_T c2_a,
  real_T c2_b_b, real_T c2_c, real_T c2_d, real_T *c2_rt1r, real_T *c2_rt1i,
  real_T *c2_rt2r, real_T *c2_rt2i, real_T *c2_b_a, real_T *c2_c_b, real_T
  *c2_b_c, real_T *c2_b_d, real_T *c2_cs, real_T *c2_sn)
{
  *c2_b_a = c2_a;
  *c2_c_b = c2_b_b;
  *c2_b_c = c2_c;
  *c2_b_d = c2_d;
  c2_b_xdlanv2(chartInstance, c2_b_a, c2_c_b, c2_b_c, c2_b_d, c2_rt1r, c2_rt1i,
               c2_rt2r, c2_rt2i, c2_cs, c2_sn);
}

static void c2_eml_rsf2csf(SFc2_simuleringInstanceStruct *chartInstance, real_T
  c2_Tr[2304], creal_T c2_b_T[2304])
{
  int32_T c2_i214;
  int32_T c2_m;
  int32_T c2_a;
  int32_T c2_mm1;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c;
  real_T c2_d;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_b_c;
  real_T c2_b_d;
  real_T c2_rt1r;
  real_T c2_rt1i;
  real_T c2_rt2r;
  real_T c2_rt2i;
  real_T c2_cs;
  real_T c2_sn;
  real_T c2_b_rt1r;
  real_T c2_b_rt1i;
  creal_T c2_mu1;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_x2;
  real_T c2_d_a;
  real_T c2_r;
  real_T c2_B;
  real_T c2_e_y;
  real_T c2_f_y;
  real_T c2_ar;
  real_T c2_ai;
  real_T c2_br;
  real_T c2_bi;
  real_T c2_brm;
  creal_T c2_c_c;
  real_T c2_bim;
  real_T c2_s;
  real_T c2_c_d;
  real_T c2_g_A;
  real_T c2_sgnbr;
  real_T c2_nr;
  real_T c2_b_B;
  real_T c2_ni;
  real_T c2_b_x;
  real_T c2_g_y;
  real_T c2_sgnbi;
  real_T c2_c_x;
  real_T c2_h_y;
  real_T c2_b_s;
  int32_T c2_j;
  int32_T c2_d_b;
  creal_T c2_t1;
  int32_T c2_e_b;
  creal_T c2_z;
  boolean_T c2_overflow;
  real_T c2_e_a;
  int32_T c2_i;
  static creal_T c2_dc0 = { 0.0,       /* re */
    0.0                                /* im */
  };

  real_T c2_f_a;
  real_T c2_g_a;
  creal_T c2_d_c;
  creal_T c2_e_c;
  real_T c2_h_a;
  for (c2_i214 = 0; c2_i214 < 2304; c2_i214++) {
    c2_b_T[c2_i214].re = c2_Tr[c2_i214];
    c2_b_T[c2_i214].im = 0.0;
  }

  c2_m = 47;
  while (c2_m + 1 >= 2) {
    c2_a = c2_m - 1;
    c2_mm1 = c2_a;
    if (c2_Tr[c2_m + 48 * c2_mm1] != 0.0) {
      c2_b_a = c2_Tr[c2_mm1 + 48 * c2_mm1];
      c2_b_b = c2_Tr[c2_mm1 + 48 * c2_m];
      c2_c = c2_Tr[c2_m + 48 * c2_mm1];
      c2_d = c2_Tr[c2_m + 48 * c2_m];
      c2_c_a = c2_b_a;
      c2_c_b = c2_b_b;
      c2_b_c = c2_c;
      c2_b_d = c2_d;
      c2_b_xdlanv2(chartInstance, &c2_c_a, &c2_c_b, &c2_b_c, &c2_b_d, &c2_rt1r,
                   &c2_rt1i, &c2_rt2r, &c2_rt2i, &c2_cs, &c2_sn);
      c2_b_rt1r = c2_rt1r;
      c2_b_rt1i = c2_rt1i;
      c2_mu1.re = c2_b_rt1r - c2_Tr[c2_m + 48 * c2_m];
      c2_mu1.im = c2_b_rt1i;
      c2_b_y = c2_Tr[c2_m + 48 * c2_mm1];
      c2_c_y = c2_b_y;
      c2_d_y = c2_c_y;
      c2_x2 = c2_d_y;
      c2_d_a = muDoubleScalarHypot(c2_mu1.re, c2_mu1.im);
      c2_r = muDoubleScalarHypot(c2_d_a, c2_x2);
      c2_B = c2_r;
      c2_e_y = c2_B;
      c2_f_y = c2_e_y;
      c2_ar = c2_mu1.re;
      c2_ai = c2_mu1.im;
      c2_br = c2_f_y;
      c2_bi = 0.0;
      if (c2_bi == 0.0) {
        if (c2_ai == 0.0) {
          c2_c_c.re = c2_ar / c2_br;
          c2_c_c.im = 0.0;
        } else if (c2_ar == 0.0) {
          c2_c_c.re = 0.0;
          c2_c_c.im = c2_ai / c2_br;
        } else {
          c2_c_c.re = c2_ar / c2_br;
          c2_c_c.im = c2_ai / c2_br;
        }
      } else if (c2_br == 0.0) {
        if (c2_ar == 0.0) {
          c2_c_c.re = c2_ai / c2_bi;
          c2_c_c.im = 0.0;
        } else if (c2_ai == 0.0) {
          c2_c_c.re = 0.0;
          c2_c_c.im = -(c2_ar / c2_bi);
        } else {
          c2_c_c.re = c2_ai / c2_bi;
          c2_c_c.im = -(c2_ar / c2_bi);
        }
      } else {
        c2_brm = muDoubleScalarAbs(c2_br);
        c2_bim = muDoubleScalarAbs(c2_bi);
        if (c2_brm > c2_bim) {
          c2_s = c2_bi / c2_br;
          c2_c_d = c2_br + c2_s * c2_bi;
          c2_nr = c2_ar + c2_s * c2_ai;
          c2_ni = c2_ai - c2_s * c2_ar;
          c2_c_c.re = c2_nr / c2_c_d;
          c2_c_c.im = c2_ni / c2_c_d;
        } else if (c2_bim == c2_brm) {
          if (c2_br > 0.0) {
            c2_sgnbr = 0.5;
          } else {
            c2_sgnbr = -0.5;
          }

          if (c2_bi > 0.0) {
            c2_sgnbi = 0.5;
          } else {
            c2_sgnbi = -0.5;
          }

          c2_nr = c2_ar * c2_sgnbr + c2_ai * c2_sgnbi;
          c2_ni = c2_ai * c2_sgnbr - c2_ar * c2_sgnbi;
          c2_c_c.re = c2_nr / c2_brm;
          c2_c_c.im = c2_ni / c2_brm;
        } else {
          c2_s = c2_br / c2_bi;
          c2_c_d = c2_bi + c2_s * c2_br;
          c2_nr = c2_s * c2_ar + c2_ai;
          c2_ni = c2_s * c2_ai - c2_ar;
          c2_c_c.re = c2_nr / c2_c_d;
          c2_c_c.im = c2_ni / c2_c_d;
        }
      }

      c2_g_A = c2_Tr[c2_m + 48 * c2_mm1];
      c2_b_B = c2_r;
      c2_b_x = c2_g_A;
      c2_g_y = c2_b_B;
      c2_c_x = c2_b_x;
      c2_h_y = c2_g_y;
      c2_b_s = c2_c_x / c2_h_y;
      for (c2_j = c2_mm1; c2_j + 1 < 49; c2_j++) {
        c2_t1 = c2_b_T[c2_mm1 + 48 * c2_j];
        c2_z.re = c2_c_c.re * c2_t1.re + c2_c_c.im * c2_t1.im;
        c2_z.im = c2_c_c.re * c2_t1.im - c2_c_c.im * c2_t1.re;
        c2_e_a = c2_b_s;
        c2_mu1 = c2_b_T[c2_m + 48 * c2_j];
        c2_mu1.re *= c2_e_a;
        c2_mu1.im *= c2_e_a;
        c2_b_T[c2_mm1 + 48 * c2_j].re = c2_z.re + c2_mu1.re;
        c2_b_T[c2_mm1 + 48 * c2_j].im = c2_z.im + c2_mu1.im;
        c2_g_a = c2_b_s;
        c2_mu1.re = c2_g_a * c2_t1.re;
        c2_mu1.im = c2_g_a * c2_t1.im;
        c2_d_c.re = c2_c_c.re * c2_b_T[c2_m + 48 * c2_j].re - c2_c_c.im *
          c2_b_T[c2_m + 48 * c2_j].im;
        c2_d_c.im = c2_c_c.re * c2_b_T[c2_m + 48 * c2_j].im + c2_c_c.im *
          c2_b_T[c2_m + 48 * c2_j].re;
        c2_b_T[c2_m + 48 * c2_j].re = c2_d_c.re - c2_mu1.re;
        c2_b_T[c2_m + 48 * c2_j].im = c2_d_c.im - c2_mu1.im;
      }

      c2_d_b = c2_m + 1;
      c2_e_b = c2_d_b;
      c2_overflow = ((!(1 > c2_e_b)) && (c2_e_b > 2147483646));
      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_i = 0; c2_i + 1 <= c2_m + 1; c2_i++) {
        c2_t1 = c2_b_T[c2_i + 48 * c2_mm1];
        c2_f_a = c2_b_s;
        c2_mu1 = c2_b_T[c2_i + 48 * c2_m];
        c2_z.re = c2_f_a * c2_mu1.re;
        c2_z.im = c2_f_a * c2_mu1.im;
        c2_e_c.re = c2_c_c.re * c2_t1.re - c2_c_c.im * c2_t1.im;
        c2_e_c.im = c2_c_c.re * c2_t1.im + c2_c_c.im * c2_t1.re;
        c2_b_T[c2_i + 48 * c2_mm1].re = c2_e_c.re + c2_z.re;
        c2_b_T[c2_i + 48 * c2_mm1].im = c2_e_c.im + c2_z.im;
        c2_mu1 = c2_b_T[c2_i + 48 * c2_m];
        c2_z.re = c2_c_c.re * c2_mu1.re + c2_c_c.im * c2_mu1.im;
        c2_z.im = c2_c_c.re * c2_mu1.im - c2_c_c.im * c2_mu1.re;
        c2_h_a = c2_b_s;
        c2_mu1.re = c2_h_a * c2_t1.re;
        c2_mu1.im = c2_h_a * c2_t1.im;
        c2_b_T[c2_i + 48 * c2_m].re = c2_z.re - c2_mu1.re;
        c2_b_T[c2_i + 48 * c2_m].im = c2_z.im - c2_mu1.im;
      }

      c2_b_T[c2_m + 48 * c2_mm1] = c2_dc0;
    }

    c2_m = c2_mm1;
  }
}

static void c2_warning(SFc2_simuleringInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv15[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv16[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_msgID[26] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 's', 'c', 'h', 'u', 'r', '_', 'f', 'a', 'i', 'l',
    'e', 'd' };

  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv15, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv16, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 26),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_b_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_c_y, 14, c2_d_y));
}

static void c2_mainDiagZeroImag(SFc2_simuleringInstanceStruct *chartInstance,
  creal_T c2_D[2304], creal_T c2_d[48])
{
  int32_T c2_k;
  (void)chartInstance;
  for (c2_k = 0; c2_k + 1 < 49; c2_k++) {
    c2_d[c2_k] = c2_D[c2_k + 48 * c2_k];
  }
}

static void c2_xgeev(SFc2_simuleringInstanceStruct *chartInstance, real_T
                     c2_g_A[2304], int32_T *c2_info, creal_T c2_W[48])
{
  int32_T c2_i215;
  ptrdiff_t c2_ldvl_t;
  creal_T c2_h_A[2304];
  ptrdiff_t c2_ldvr_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_info_t;
  creal_T c2_vl;
  creal_T c2_vr;
  int32_T c2_b_info;
  for (c2_i215 = 0; c2_i215 < 2304; c2_i215++) {
    c2_h_A[c2_i215].re = c2_g_A[c2_i215];
    c2_h_A[c2_i215].im = 0.0;
  }

  c2_ldvl_t = (ptrdiff_t)1;
  c2_ldvr_t = (ptrdiff_t)1;
  c2_n_t = (ptrdiff_t)48;
  c2_lda_t = (ptrdiff_t)48;
  c2_info_t = LAPACKE_zgeev(102, 'N', 'N', c2_n_t, (lapack_complex_double *)
    &c2_h_A[0], c2_lda_t, (lapack_complex_double *)&c2_W[0],
    (lapack_complex_double *)&c2_vl, c2_ldvl_t, (lapack_complex_double *)&c2_vr,
    c2_ldvr_t);
  c2_b_info = (int32_T)c2_info_t;
  c2_infocheck(chartInstance, c2_b_info);
  *c2_info = c2_b_info;
}

static boolean_T c2_infocheck(SFc2_simuleringInstanceStruct *chartInstance,
  int32_T c2_info)
{
  boolean_T c2_p;
  int32_T c2_b_info;
  boolean_T c2_b_p;
  c2_b_info = c2_info;
  c2_b_p = (c2_b_info < 0);
  if (c2_b_p) {
    if (c2_info == -1010) {
      c2_error(chartInstance);
    } else {
      c2_d_error(chartInstance, c2_info);
    }
  } else {
    c2_p = false;
  }

  return c2_p;
}

static void c2_d_error(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_varargin_2)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv17[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv18[13] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z', 'g',
    'e', 'e', 'v' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv17, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv18, 10, 0U, 1U, 0U, 2, 1, 13),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y));
}

static void c2_b_warning(SFc2_simuleringInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv19[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv20[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv19, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv20, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_b_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_c_y, 14, c2_d_y));
}

static const mxArray *c2_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char * c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_b_u)), false);
  return c2_b_y;
}

static void c2_g_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_h_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "data" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "data";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "data",
    "data", 0)), &c2_thisId, c2_b_y->data);
  sf_mex_destroy(&c2_b_u);
}

static void c2_i_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [168])
{
  real_T c2_dv7[168];
  int32_T c2_i216;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv7, 1, 0, 0U, 1, 0U, 1, 168);
  for (c2_i216 = 0; c2_i216 < 168; c2_i216++) {
    c2_b_y[c2_i216] = c2_dv7[c2_i216];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_j_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_k_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Gamma" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Gamma";
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Gamma", "Gamma", 0)), &c2_thisId, c2_b_y->Gamma);
  sf_mex_destroy(&c2_b_u);
}

static void c2_l_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [1152])
{
  real_T c2_dv8[1152];
  int32_T c2_i217;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv8, 1, 0, 0U, 1, 0U, 2, 24,
                48);
  for (c2_i217 = 0; c2_i217 < 1152; c2_i217++) {
    c2_b_y[c2_i217] = c2_dv8[c2_i217];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_m_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_n_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Omega" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Omega";
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Omega", "Omega", 0)), &c2_thisId, c2_b_y->Omega);
  sf_mex_destroy(&c2_b_u);
}

static void c2_o_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [2304])
{
  real_T c2_dv9[2304];
  int32_T c2_i218;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv9, 1, 0, 0U, 1, 0U, 2, 48,
                48);
  for (c2_i218 = 0; c2_i218 < 2304; c2_i218++) {
    c2_b_y[c2_i218] = c2_dv9[c2_i218];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_p_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_q_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Phi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Phi";
  c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Phi",
    "Phi", 0)), &c2_thisId, c2_b_y->Phi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_r_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[24])
{
  real_T c2_dv10[24];
  int32_T c2_i219;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv10, 1, 0, 0U, 1, 0U, 1, 24);
  for (c2_i219 = 0; c2_i219 < 24; c2_i219++) {
    c2_b_y[c2_i219] = c2_dv10[c2_i219];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_s_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier, c2_sjdLzyTh14ULkIImcl6xwW
  *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_t_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sjdLzyTh14ULkIImcl6xwW *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Pi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Pi";
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Pi",
    "Pi", 0)), &c2_thisId, c2_b_y->Pi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_u_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_v_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Psi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Psi";
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Psi",
    "Psi", 0)), &c2_thisId, c2_b_y->Psi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_w_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_x_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Theta" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Theta";
  c2_y_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Theta", "Theta", 0)), &c2_thisId, c2_b_y->Theta);
  sf_mex_destroy(&c2_b_u);
}

static void c2_y_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y
  [1152])
{
  real_T c2_dv11[1152];
  int32_T c2_i220;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 48,
                24);
  for (c2_i220 = 0; c2_i220 < 1152; c2_i220++) {
    c2_b_y[c2_i220] = c2_dv11[c2_i220];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_ab_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_load, const char_T *c2_identifier,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_bb_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "constant_dist" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "constant_dist";
  c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "constant_dist", "constant_dist", 0)), &c2_thisId, c2_b_y->constant_dist);
  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_b_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[48])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 48), false);
  return c2_b_y;
}

static const mxArray *c2_c_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[2])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  return c2_b_y;
}

static const mxArray *c2_d_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const creal_T c2_b_u[48])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 1U, 1U, 0U, 1, 48), false);
  return c2_b_y;
}

static const mxArray *c2_e_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[2304])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  return c2_b_y;
}

static const mxArray *c2_f_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[48])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 48),
                false);
  return c2_b_y;
}

static const mxArray *c2_g_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[7])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  return c2_b_y;
}

static const mxArray *c2_h_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[4])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  return c2_b_y;
}

static const mxArray *c2_i_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[9])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  return c2_b_y;
}

static const mxArray *c2_j_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const char_T c2_b_u[14])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  return c2_b_y;
}

static const mxArray *c2_k_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  return c2_b_y;
}

static void c2_cb_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_u_hp, const char_T *c2_identifier, real_T c2_b_y[48])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_u_hp), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_u_hp);
}

static void c2_db_emlrt_marshallIn(SFc2_simuleringInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[48])
{
  real_T c2_dv12[48];
  int32_T c2_i221;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 48);
  for (c2_i221 = 0; c2_i221 < 48; c2_i221++) {
    c2_b_y[c2_i221] = c2_dv12[c2_i221];
  }

  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_l_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const c2_emxArray_real_T *c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u->data, 0, 0U, 1U, 0U, 2,
    c2_b_u->size[0], c2_b_u->size[1]), false);
  return c2_b_y;
}

static const mxArray *c2_m_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[24])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 24), false);
  return c2_b_y;
}

static const mxArray *c2_n_emlrt_marshallOut(SFc2_simuleringInstanceStruct
  *chartInstance, const real_T c2_b_u[2])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  return c2_b_y;
}

static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_eb_emlrt_marshallIn(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_b_y;
  int32_T c2_i222;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i222, 1, 6, 0U, 0, 0U, 0);
  c2_b_y = c2_i222;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_b_y;
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_fb_emlrt_marshallIn(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_simulering, const char_T
  *c2_identifier)
{
  uint8_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_gb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_simulering), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_simulering);
  return c2_b_y;
}

static uint8_T c2_gb_emlrt_marshallIn(SFc2_simuleringInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_b_triu(SFc2_simuleringInstanceStruct *chartInstance, creal_T
                      c2_b_x[2304])
{
  int32_T c2_istart;
  int32_T c2_j;
  int32_T c2_i;
  int32_T c2_a;
  static creal_T c2_dc1 = { 0.0,       /* re */
    0.0                                /* im */
  };

  (void)chartInstance;
  c2_istart = 3;
  for (c2_j = 0; c2_j + 1 < 47; c2_j++) {
    for (c2_i = c2_istart; c2_i < 49; c2_i++) {
      c2_b_x[(c2_i + 48 * c2_j) - 1] = c2_dc1;
    }

    c2_a = c2_istart + 1;
    c2_istart = c2_a;
  }
}

static void c2_b_xgehrd(SFc2_simuleringInstanceStruct *chartInstance, real_T
  c2_a[2304])
{
  int32_T c2_i223;
  int32_T c2_i;
  real_T c2_work[48];
  int32_T c2_b_a;
  int32_T c2_im1;
  int32_T c2_c_a;
  int32_T c2_ip1;
  int32_T c2_d_a;
  int32_T c2_im1n;
  int32_T c2_e_a;
  int32_T c2_in;
  real_T c2_alpha1;
  int32_T c2_f_a;
  int32_T c2_c;
  int32_T c2_varargin_1;
  int32_T c2_varargin_2;
  int32_T c2_b_x;
  int32_T c2_c_x;
  int32_T c2_d_x;
  int32_T c2_minval;
  int32_T c2_g_a;
  int32_T c2_b_c;
  int32_T c2_h_a;
  int32_T c2_b_b;
  int32_T c2_ia0;
  int32_T c2_c_b;
  int32_T c2_c_c;
  real_T c2_b_alpha1;
  real_T c2_d1;
  real_T c2_tau[47];
  int32_T c2_d_b;
  int32_T c2_d_c;
  int32_T c2_i_a;
  int32_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_j_a;
  int32_T c2_f_c;
  int32_T c2_f_b;
  int32_T c2_g_c;
  int32_T c2_g_b;
  int32_T c2_h_c;
  int32_T c2_k_a;
  int32_T c2_h_b;
  int32_T c2_i_c;
  int32_T c2_l_a;
  int32_T c2_i_b;
  int32_T c2_j_c;
  for (c2_i223 = 0; c2_i223 < 48; c2_i223++) {
    c2_work[c2_i223] = 0.0;
  }

  for (c2_i = 1; c2_i < 48; c2_i++) {
    c2_b_a = c2_i - 1;
    c2_im1 = c2_b_a;
    c2_c_a = c2_i;
    c2_ip1 = c2_c_a;
    c2_d_a = c2_im1;
    c2_im1n = c2_d_a * 48;
    c2_e_a = c2_i;
    c2_in = c2_e_a * 48;
    c2_alpha1 = c2_a[c2_ip1 + 48 * (c2_i - 1)];
    c2_f_a = c2_i;
    c2_c = c2_f_a;
    c2_varargin_1 = c2_c + 2;
    c2_varargin_2 = c2_varargin_1;
    c2_b_x = c2_varargin_2;
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_minval = muIntScalarMin_sint32(c2_d_x, 48);
    c2_g_a = c2_im1;
    c2_b_c = c2_g_a * 48;
    c2_h_a = c2_minval;
    c2_b_b = c2_b_c;
    c2_ia0 = c2_h_a + c2_b_b;
    c2_c_b = c2_i;
    c2_c_c = 48 - c2_c_b;
    c2_b_alpha1 = c2_alpha1;
    c2_d1 = c2_b_xzlarfg(chartInstance, c2_c_c, &c2_b_alpha1, c2_a, c2_ia0);
    c2_tau[c2_i - 1] = c2_d1;
    c2_a[c2_ip1 + 48 * (c2_i - 1)] = 1.0;
    c2_d_b = c2_i;
    c2_d_c = 48 - c2_d_b;
    c2_i_a = c2_ip1 + 1;
    c2_e_b = c2_im1n;
    c2_e_c = c2_i_a + c2_e_b;
    c2_j_a = c2_in;
    c2_f_c = c2_j_a;
    c2_c_xzlarf(chartInstance, c2_d_c, c2_e_c, c2_tau[c2_i - 1], c2_a, c2_f_c +
                1, c2_work);
    c2_f_b = c2_i;
    c2_g_c = 48 - c2_f_b;
    c2_g_b = c2_i;
    c2_h_c = 48 - c2_g_b;
    c2_k_a = c2_ip1 + 1;
    c2_h_b = c2_im1n;
    c2_i_c = c2_k_a + c2_h_b;
    c2_l_a = c2_ip1 + 1;
    c2_i_b = c2_in;
    c2_j_c = c2_l_a + c2_i_b;
    c2_d_xzlarf(chartInstance, c2_g_c, c2_h_c, c2_i_c, c2_tau[c2_i - 1], c2_a,
                c2_j_c, c2_work);
    c2_a[c2_ip1 + 48 * (c2_i - 1)] = c2_b_alpha1;
  }
}

static real_T c2_b_xzlarfg(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, real_T *c2_alpha1, real_T c2_b_x[2304], int32_T c2_ix0)
{
  real_T c2_tau;
  int32_T c2_nm1;
  int32_T c2_i224;
  real_T c2_xnorm;
  real_T c2_c_x[2304];
  real_T c2_x1;
  real_T c2_x2;
  real_T c2_beta1;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_g_x;
  int32_T c2_knt;
  real_T c2_c_y;
  int32_T c2_a;
  real_T c2_d_y;
  int32_T c2_b_n;
  int32_T c2_c_n;
  int32_T c2_b_ix0;
  real_T c2_b_a;
  int32_T c2_d_n;
  int32_T c2_c_ix0;
  int32_T c2_d_ix0;
  int32_T c2_e_n;
  int32_T c2_c_a;
  real_T c2_d_a;
  int32_T c2_c;
  int32_T c2_e_ix0;
  int32_T c2_b_b;
  int32_T c2_e_a;
  int32_T c2_b_c;
  int32_T c2_c_c;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_d_c;
  int32_T c2_i225;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_e_b;
  int32_T c2_f_b;
  int32_T c2_i226;
  int32_T c2_i_a;
  int32_T c2_j_a;
  int32_T c2_g_b;
  int32_T c2_h_b;
  boolean_T c2_overflow;
  int32_T c2_k_a;
  int32_T c2_i_b;
  boolean_T c2_b_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_e_y;
  int32_T c2_i227;
  real_T c2_k_x[2304];
  real_T c2_b_x1;
  real_T c2_b_x2;
  real_T c2_l_x;
  real_T c2_f_y;
  real_T c2_g_y;
  int32_T c2_f_n;
  real_T c2_l_a;
  int32_T c2_f_ix0;
  int32_T c2_g_n;
  real_T c2_m_a;
  int32_T c2_g_ix0;
  int32_T c2_n_a;
  int32_T c2_e_c;
  int32_T c2_j_b;
  int32_T c2_f_c;
  int32_T c2_o_a;
  int32_T c2_k_b;
  int32_T c2_i228;
  int32_T c2_p_a;
  int32_T c2_l_b;
  int32_T c2_q_a;
  int32_T c2_m_b;
  boolean_T c2_c_overflow;
  int32_T c2_c_k;
  int32_T c2_n_b;
  int32_T c2_o_b;
  boolean_T c2_d_overflow;
  int32_T c2_d_k;
  c2_tau = 0.0;
  if (c2_n <= 0) {
  } else {
    c2_nm1 = c2_n - 1;
    for (c2_i224 = 0; c2_i224 < 2304; c2_i224++) {
      c2_c_x[c2_i224] = c2_b_x[c2_i224];
    }

    c2_xnorm = c2_xnrm2(chartInstance, c2_nm1, c2_c_x, c2_ix0);
    if (c2_xnorm != 0.0) {
      c2_x1 = *c2_alpha1;
      c2_x2 = c2_xnorm;
      c2_beta1 = muDoubleScalarHypot(c2_x1, c2_x2);
      if (*c2_alpha1 >= 0.0) {
        c2_beta1 = -c2_beta1;
      }

      c2_d_x = c2_beta1;
      c2_e_x = c2_d_x;
      c2_f_x = c2_e_x;
      c2_b_y = muDoubleScalarAbs(c2_f_x);
      if (c2_b_y < 1.0020841800044864E-292) {
        c2_knt = 0;
        do {
          c2_a = c2_knt + 1;
          c2_knt = c2_a;
          c2_b_n = c2_nm1;
          c2_b_ix0 = c2_ix0;
          c2_d_n = c2_b_n;
          c2_d_ix0 = c2_b_ix0;
          c2_c_a = c2_d_n;
          c2_c = c2_c_a;
          c2_b_b = c2_c - 1;
          c2_b_c = c2_b_b;
          c2_f_a = c2_d_ix0;
          c2_d_b = c2_b_c;
          c2_i225 = c2_f_a + c2_d_b;
          c2_h_a = c2_d_ix0;
          c2_f_b = c2_i225;
          c2_i_a = c2_h_a;
          c2_g_b = c2_f_b;
          c2_overflow = ((!(c2_i_a > c2_g_b)) && (c2_g_b > 2147483646));
          if (c2_overflow) {
            c2_check_forloop_overflow_error(chartInstance, true);
          }

          for (c2_k = c2_d_ix0 - 1; c2_k + 1 <= c2_i225; c2_k++) {
            c2_b_x[c2_k] *= 9.9792015476736E+291;
          }

          c2_beta1 *= 9.9792015476736E+291;
          *c2_alpha1 *= 9.9792015476736E+291;
          c2_h_x = c2_beta1;
          c2_i_x = c2_h_x;
          c2_j_x = c2_i_x;
          c2_e_y = muDoubleScalarAbs(c2_j_x);
        } while (!(c2_e_y >= 1.0020841800044864E-292));

        for (c2_i227 = 0; c2_i227 < 2304; c2_i227++) {
          c2_k_x[c2_i227] = c2_b_x[c2_i227];
        }

        c2_xnorm = c2_xnrm2(chartInstance, c2_nm1, c2_k_x, c2_ix0);
        c2_b_x1 = *c2_alpha1;
        c2_b_x2 = c2_xnorm;
        c2_beta1 = muDoubleScalarHypot(c2_b_x1, c2_b_x2);
        if (*c2_alpha1 >= 0.0) {
          c2_beta1 = -c2_beta1;
        }

        c2_l_x = c2_beta1 - *c2_alpha1;
        c2_f_y = c2_beta1;
        c2_tau = c2_l_x / c2_f_y;
        c2_g_y = *c2_alpha1 - c2_beta1;
        *c2_alpha1 = 1.0 / c2_g_y;
        c2_f_n = c2_nm1;
        c2_l_a = *c2_alpha1;
        c2_f_ix0 = c2_ix0;
        c2_g_n = c2_f_n;
        c2_m_a = c2_l_a;
        c2_g_ix0 = c2_f_ix0;
        c2_n_a = c2_g_n;
        c2_e_c = c2_n_a;
        c2_j_b = c2_e_c - 1;
        c2_f_c = c2_j_b;
        c2_o_a = c2_g_ix0;
        c2_k_b = c2_f_c;
        c2_i228 = c2_o_a + c2_k_b;
        c2_p_a = c2_g_ix0;
        c2_l_b = c2_i228;
        c2_q_a = c2_p_a;
        c2_m_b = c2_l_b;
        c2_c_overflow = ((!(c2_q_a > c2_m_b)) && (c2_m_b > 2147483646));
        if (c2_c_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_c_k = c2_g_ix0 - 1; c2_c_k + 1 <= c2_i228; c2_c_k++) {
          c2_b_x[c2_c_k] *= c2_m_a;
        }

        c2_n_b = c2_knt;
        c2_o_b = c2_n_b;
        c2_d_overflow = ((!(1 > c2_o_b)) && (c2_o_b > 2147483646));
        if (c2_d_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_d_k = 1; c2_d_k <= c2_knt; c2_d_k++) {
          c2_beta1 *= 1.0020841800044864E-292;
        }

        *c2_alpha1 = c2_beta1;
      } else {
        c2_g_x = c2_beta1 - *c2_alpha1;
        c2_c_y = c2_beta1;
        c2_tau = c2_g_x / c2_c_y;
        c2_d_y = *c2_alpha1 - c2_beta1;
        *c2_alpha1 = 1.0 / c2_d_y;
        c2_c_n = c2_nm1;
        c2_b_a = *c2_alpha1;
        c2_c_ix0 = c2_ix0;
        c2_e_n = c2_c_n;
        c2_d_a = c2_b_a;
        c2_e_ix0 = c2_c_ix0;
        c2_e_a = c2_e_n;
        c2_c_c = c2_e_a;
        c2_c_b = c2_c_c - 1;
        c2_d_c = c2_c_b;
        c2_g_a = c2_e_ix0;
        c2_e_b = c2_d_c;
        c2_i226 = c2_g_a + c2_e_b;
        c2_j_a = c2_e_ix0;
        c2_h_b = c2_i226;
        c2_k_a = c2_j_a;
        c2_i_b = c2_h_b;
        c2_b_overflow = ((!(c2_k_a > c2_i_b)) && (c2_i_b > 2147483646));
        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_b_k = c2_e_ix0 - 1; c2_b_k + 1 <= c2_i226; c2_b_k++) {
          c2_b_x[c2_b_k] *= c2_d_a;
        }

        *c2_alpha1 = c2_beta1;
      }
    }
  }

  return c2_tau;
}

static void c2_c_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T c2_ic0, real_T
  c2_work[48])
{
  int32_T c2_lastv;
  int32_T c2_lastc;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_b;
  int32_T c2_i229;
  int32_T c2_b_c;
  int32_T c2_b_a;
  int32_T c2_c_b;
  int32_T c2_i230;
  real_T c2_b_C[2304];
  int32_T c2_i;
  real_T c2_c_C[2304];
  int32_T c2_i231;
  int32_T c2_b_lastc;
  int32_T c2_c_a;
  int32_T c2_d_a;
  real_T c2_b_work[48];
  if (c2_tau != 0.0) {
    c2_lastv = c2_n;
    c2_a = c2_n;
    c2_c = c2_a;
    c2_b_b = c2_c - 1;
    c2_b_c = c2_b_b;
    c2_b_a = c2_iv0;
    c2_c_b = c2_b_c;
    c2_i = c2_b_a + c2_c_b;
    while ((c2_lastv > 0) && (c2_C[c2_i - 1] == 0.0)) {
      c2_c_a = c2_lastv - 1;
      c2_lastv = c2_c_a;
      c2_d_a = c2_i - 1;
      c2_i = c2_d_a;
    }

    c2_b_lastc = c2_b_ilazlr(chartInstance, 48, c2_lastv, c2_C, c2_ic0);
    c2_lastc = c2_b_lastc;
  } else {
    c2_lastv = 0;
    c2_lastc = 0;
  }

  if (c2_lastv > 0) {
    for (c2_i229 = 0; c2_i229 < 2304; c2_i229++) {
      c2_b_C[c2_i229] = c2_C[c2_i229];
    }

    for (c2_i230 = 0; c2_i230 < 2304; c2_i230++) {
      c2_c_C[c2_i230] = c2_C[c2_i230];
    }

    c2_c_xgemv(chartInstance, c2_lastc, c2_lastv, c2_b_C, c2_ic0, c2_c_C, c2_iv0,
               c2_work);
    for (c2_i231 = 0; c2_i231 < 48; c2_i231++) {
      c2_b_work[c2_i231] = c2_work[c2_i231];
    }

    c2_c_xgerc(chartInstance, c2_lastc, c2_lastv, -c2_tau, c2_b_work, c2_iv0,
               c2_C, c2_ic0);
  }
}

static int32_T c2_b_ilazlr(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0)
{
  int32_T c2_i;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_rowleft;
  int32_T c2_c_a;
  int32_T c2_b_c;
  int32_T c2_d_a;
  int32_T c2_c_c;
  int32_T c2_e_a;
  int32_T c2_c_b;
  int32_T c2_rowright;
  int32_T c2_f_a;
  int32_T c2_d_b;
  int32_T c2_g_a;
  int32_T c2_e_b;
  boolean_T c2_overflow;
  int32_T c2_ia;
  int32_T c2_h_a;
  int32_T exitg1;
  boolean_T exitg2;
  (void)c2_m;
  c2_i = 48;
  exitg2 = false;
  while ((!exitg2) && (c2_i > 0)) {
    c2_a = c2_i;
    c2_c = c2_a;
    c2_b_a = c2_ia0;
    c2_b_b = c2_c - 1;
    c2_rowleft = c2_b_a + c2_b_b;
    c2_c_a = c2_n;
    c2_b_c = c2_c_a;
    c2_d_a = c2_b_c - 1;
    c2_c_c = c2_d_a * 48;
    c2_e_a = c2_rowleft;
    c2_c_b = c2_c_c;
    c2_rowright = c2_e_a + c2_c_b;
    c2_f_a = c2_rowleft;
    c2_d_b = c2_rowright;
    c2_g_a = c2_f_a;
    c2_e_b = c2_d_b;
    c2_overflow = ((!(c2_g_a > c2_e_b)) && (c2_e_b > 2147483599));
    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    c2_ia = c2_rowleft;
    do {
      exitg1 = 0;
      if (c2_ia <= c2_rowright) {
        if (c2_g_A[c2_ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          c2_ia += 48;
        }
      } else {
        c2_h_a = c2_i - 1;
        c2_i = c2_h_a;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return c2_i;
}

static void c2_c_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_b_x[2304],
  int32_T c2_ix0, real_T c2_b_y[48])
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_alpha1;
  int32_T c2_b_ia0;
  int32_T c2_b_ix0;
  real_T c2_beta1;
  char_T c2_TRANSA;
  int32_T c2_var;
  ptrdiff_t c2_m_t;
  int32_T c2_b_var;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_incx_t;
  ptrdiff_t c2_incy_t;
  (void)chartInstance;
  if (c2_m < 1) {
  } else {
    c2_b_m = c2_m;
    c2_b_n = c2_n;
    c2_alpha1 = 1.0;
    c2_b_ia0 = c2_ia0 - 1;
    c2_b_ix0 = c2_ix0 - 1;
    c2_beta1 = 0.0;
    c2_TRANSA = 'N';
    c2_var = c2_b_m;
    c2_m_t = (ptrdiff_t)c2_var;
    c2_b_var = c2_b_n;
    c2_n_t = (ptrdiff_t)c2_b_var;
    c2_lda_t = (ptrdiff_t)48;
    c2_incx_t = (ptrdiff_t)1;
    c2_incy_t = (ptrdiff_t)1;
    dgemv(&c2_TRANSA, &c2_m_t, &c2_n_t, &c2_alpha1, &c2_g_A[c2_b_ia0], &c2_lda_t,
          &c2_b_x[c2_b_ix0], &c2_incx_t, &c2_beta1, &c2_b_y[0], &c2_incy_t);
  }
}

static void c2_c_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_b_x[48], int32_T c2_iy0,
  real_T c2_g_A[2304], int32_T c2_ia0)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_iy0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_c_iy0;
  int32_T c2_c_ia0;
  int32_T c2_var;
  ptrdiff_t c2_m_t;
  int32_T c2_b_var;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_incx_t;
  ptrdiff_t c2_incy_t;
  ptrdiff_t c2_lda_t;
  (void)chartInstance;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_iy0 = c2_iy0;
  c2_b_ia0 = c2_ia0;
  if (c2_b_m < 1) {
  } else {
    c2_c_m = c2_b_m;
    c2_c_n = c2_b_n;
    c2_c_alpha1 = c2_b_alpha1;
    c2_c_iy0 = c2_b_iy0 - 1;
    c2_c_ia0 = c2_b_ia0 - 1;
    c2_var = c2_c_m;
    c2_m_t = (ptrdiff_t)c2_var;
    c2_b_var = c2_c_n;
    c2_n_t = (ptrdiff_t)c2_b_var;
    c2_incx_t = (ptrdiff_t)1;
    c2_incy_t = (ptrdiff_t)1;
    c2_lda_t = (ptrdiff_t)48;
    dger(&c2_m_t, &c2_n_t, &c2_c_alpha1, &c2_b_x[0], &c2_incx_t,
         &c2_g_A[c2_c_iy0], &c2_incy_t, &c2_g_A[c2_c_ia0], &c2_lda_t);
  }
}

static void c2_d_xzlarf(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[2304], int32_T
  c2_ic0, real_T c2_work[48])
{
  int32_T c2_lastv;
  int32_T c2_lastc;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_b;
  int32_T c2_i232;
  int32_T c2_b_c;
  int32_T c2_b_a;
  int32_T c2_c_b;
  int32_T c2_i233;
  real_T c2_b_C[2304];
  int32_T c2_i;
  real_T c2_c_C[2304];
  int32_T c2_i234;
  int32_T c2_b_lastc;
  int32_T c2_c_a;
  int32_T c2_d_a;
  real_T c2_b_work[48];
  if (c2_tau != 0.0) {
    c2_lastv = c2_m;
    c2_a = c2_m;
    c2_c = c2_a;
    c2_b_b = c2_c - 1;
    c2_b_c = c2_b_b;
    c2_b_a = c2_iv0;
    c2_c_b = c2_b_c;
    c2_i = c2_b_a + c2_c_b;
    while ((c2_lastv > 0) && (c2_C[c2_i - 1] == 0.0)) {
      c2_c_a = c2_lastv - 1;
      c2_lastv = c2_c_a;
      c2_d_a = c2_i - 1;
      c2_i = c2_d_a;
    }

    c2_b_lastc = c2_b_ilazlc(chartInstance, c2_lastv, c2_n, c2_C, c2_ic0, 48);
    c2_lastc = c2_b_lastc;
  } else {
    c2_lastv = 0;
    c2_lastc = 0;
  }

  if (c2_lastv > 0) {
    for (c2_i232 = 0; c2_i232 < 2304; c2_i232++) {
      c2_b_C[c2_i232] = c2_C[c2_i232];
    }

    for (c2_i233 = 0; c2_i233 < 2304; c2_i233++) {
      c2_c_C[c2_i233] = c2_C[c2_i233];
    }

    c2_d_xgemv(chartInstance, c2_lastv, c2_lastc, c2_b_C, c2_ic0, c2_c_C, c2_iv0,
               c2_work);
    for (c2_i234 = 0; c2_i234 < 48; c2_i234++) {
      c2_b_work[c2_i234] = c2_work[c2_i234];
    }

    c2_d_xgerc(chartInstance, c2_lastv, c2_lastc, -c2_tau, c2_iv0, c2_b_work,
               c2_C, c2_ic0);
  }
}

static int32_T c2_b_ilazlc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, int32_T c2_lda)
{
  int32_T c2_j;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_c_a;
  int32_T c2_b_b;
  int32_T c2_coltop;
  int32_T c2_d_a;
  int32_T c2_c_c;
  int32_T c2_e_a;
  int32_T c2_c_b;
  int32_T c2_colbottom;
  int32_T c2_f_a;
  int32_T c2_d_b;
  int32_T c2_g_a;
  int32_T c2_e_b;
  boolean_T c2_overflow;
  int32_T c2_ia;
  int32_T c2_h_a;
  int32_T exitg1;
  boolean_T exitg2;
  (void)c2_lda;
  c2_j = c2_n;
  exitg2 = false;
  while ((!exitg2) && (c2_j > 0)) {
    c2_a = c2_j;
    c2_c = c2_a;
    c2_b_a = c2_c - 1;
    c2_b_c = c2_b_a * 48;
    c2_c_a = c2_ia0;
    c2_b_b = c2_b_c;
    c2_coltop = c2_c_a + c2_b_b;
    c2_d_a = c2_m;
    c2_c_c = c2_d_a;
    c2_e_a = c2_coltop;
    c2_c_b = c2_c_c - 1;
    c2_colbottom = c2_e_a + c2_c_b;
    c2_f_a = c2_coltop;
    c2_d_b = c2_colbottom;
    c2_g_a = c2_f_a;
    c2_e_b = c2_d_b;
    c2_overflow = ((!(c2_g_a > c2_e_b)) && (c2_e_b > 2147483646));
    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    c2_ia = c2_coltop;
    do {
      exitg1 = 0;
      if (c2_ia <= c2_colbottom) {
        if (c2_g_A[c2_ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          c2_ia++;
        }
      } else {
        c2_h_a = c2_j - 1;
        c2_j = c2_h_a;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return c2_j;
}

static void c2_d_xgemv(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_g_A[2304], int32_T c2_ia0, real_T c2_b_x[2304],
  int32_T c2_ix0, real_T c2_b_y[48])
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_alpha1;
  int32_T c2_b_ia0;
  int32_T c2_b_ix0;
  real_T c2_beta1;
  char_T c2_TRANSA;
  int32_T c2_var;
  ptrdiff_t c2_m_t;
  int32_T c2_b_var;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_incx_t;
  ptrdiff_t c2_incy_t;
  (void)chartInstance;
  if (c2_n < 1) {
  } else {
    c2_b_m = c2_m;
    c2_b_n = c2_n;
    c2_alpha1 = 1.0;
    c2_b_ia0 = c2_ia0 - 1;
    c2_b_ix0 = c2_ix0 - 1;
    c2_beta1 = 0.0;
    c2_TRANSA = 'C';
    c2_var = c2_b_m;
    c2_m_t = (ptrdiff_t)c2_var;
    c2_b_var = c2_b_n;
    c2_n_t = (ptrdiff_t)c2_b_var;
    c2_lda_t = (ptrdiff_t)48;
    c2_incx_t = (ptrdiff_t)1;
    c2_incy_t = (ptrdiff_t)1;
    dgemv(&c2_TRANSA, &c2_m_t, &c2_n_t, &c2_alpha1, &c2_g_A[c2_b_ia0], &c2_lda_t,
          &c2_b_x[c2_b_ix0], &c2_incx_t, &c2_beta1, &c2_b_y[0], &c2_incy_t);
  }
}

static void c2_d_xgerc(SFc2_simuleringInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, real_T c2_b_y[48],
  real_T c2_g_A[2304], int32_T c2_ia0)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ix0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_c_ix0;
  int32_T c2_c_ia0;
  int32_T c2_var;
  ptrdiff_t c2_m_t;
  int32_T c2_b_var;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_incx_t;
  ptrdiff_t c2_incy_t;
  ptrdiff_t c2_lda_t;
  (void)chartInstance;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ix0 = c2_ix0;
  c2_b_ia0 = c2_ia0;
  if (c2_b_n < 1) {
  } else {
    c2_c_m = c2_b_m;
    c2_c_n = c2_b_n;
    c2_c_alpha1 = c2_b_alpha1;
    c2_c_ix0 = c2_b_ix0 - 1;
    c2_c_ia0 = c2_b_ia0 - 1;
    c2_var = c2_c_m;
    c2_m_t = (ptrdiff_t)c2_var;
    c2_b_var = c2_c_n;
    c2_n_t = (ptrdiff_t)c2_b_var;
    c2_incx_t = (ptrdiff_t)1;
    c2_incy_t = (ptrdiff_t)1;
    c2_lda_t = (ptrdiff_t)48;
    dger(&c2_m_t, &c2_n_t, &c2_c_alpha1, &c2_g_A[c2_c_ix0], &c2_incx_t, &c2_b_y
         [0], &c2_incy_t, &c2_g_A[c2_c_ia0], &c2_lda_t);
  }
}

static int32_T c2_b_xhseqr(SFc2_simuleringInstanceStruct *chartInstance, real_T
  c2_h[2304])
{
  real_T c2_z;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_ilo_t;
  ptrdiff_t c2_ihi_t;
  ptrdiff_t c2_ldz_t;
  ptrdiff_t c2_info_t;
  real_T c2_wr[48];
  real_T c2_wi[48];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_val;
  boolean_T c2_c_p;
  int32_T c2_i235;
  c2_z = 0.0;
  c2_n_t = (ptrdiff_t)48;
  c2_ilo_t = (ptrdiff_t)1;
  c2_ihi_t = (ptrdiff_t)48;
  c2_ldz_t = (ptrdiff_t)48;
  c2_info_t = LAPACKE_dhseqr(102, 'S', 'N', c2_n_t, c2_ilo_t, c2_ihi_t, &c2_h[0],
    c2_n_t, &c2_wr[0], &c2_wi[0], &c2_z, c2_ldz_t);
  c2_b_info = (int32_T)c2_info_t;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  c2_p = (c2_d_info < 0);
  if (c2_p) {
    c2_b_p = true;
    c2_val = c2_c_info;
    c2_c_p = false;
    if (c2_val == -7) {
      c2_c_p = true;
    } else {
      if (c2_val == -11) {
        c2_c_p = true;
      }
    }

    if (!c2_c_p) {
      if (c2_c_info == -1010) {
        c2_error(chartInstance);
      } else {
        c2_b_error(chartInstance, c2_c_info);
      }
    }
  } else {
    c2_b_p = false;
  }

  if (c2_b_p) {
    for (c2_i235 = 0; c2_i235 < 2304; c2_i235++) {
      c2_h[c2_i235] = rtNaN;
    }
  }

  return c2_b_info;
}

static void c2_b_xdlanv2(SFc2_simuleringInstanceStruct *chartInstance, real_T
  *c2_a, real_T *c2_b_b, real_T *c2_c, real_T *c2_d, real_T *c2_rt1r, real_T
  *c2_rt1i, real_T *c2_rt2r, real_T *c2_rt2i, real_T *c2_cs, real_T *c2_sn)
{
  real_T c2_temp;
  real_T c2_p;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_d_y;
  real_T c2_m_x;
  real_T c2_varargin_1;
  boolean_T c2_b_p;
  real_T c2_varargin_2;
  boolean_T c2_c_p;
  real_T c2_b_varargin_2;
  real_T c2_varargin_3;
  real_T c2_n_x;
  real_T c2_e_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_f_y;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_t_x;
  real_T c2_bcmax;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  boolean_T c2_d_p;
  real_T c2_y_x;
  boolean_T c2_e_p;
  real_T c2_i_y;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_j_y;
  real_T c2_b_varargin_1;
  real_T c2_c_varargin_2;
  real_T c2_d_varargin_2;
  real_T c2_b_varargin_3;
  real_T c2_db_x;
  real_T c2_k_y;
  real_T c2_eb_x;
  real_T c2_l_y;
  real_T c2_fb_x;
  real_T c2_m_y;
  real_T c2_minval;
  real_T c2_c_b;
  real_T c2_n_y;
  real_T c2_d_b;
  real_T c2_o_y;
  real_T c2_bcmis;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_p_y;
  real_T c2_c_varargin_1;
  real_T c2_e_varargin_2;
  real_T c2_f_varargin_2;
  real_T c2_c_varargin_3;
  real_T c2_jb_x;
  real_T c2_q_y;
  real_T c2_kb_x;
  real_T c2_r_y;
  real_T c2_lb_x;
  real_T c2_s_y;
  real_T c2_scale;
  real_T c2_g_A;
  real_T c2_B;
  real_T c2_mb_x;
  real_T c2_t_y;
  real_T c2_nb_x;
  real_T c2_u_y;
  real_T c2_v_y;
  real_T c2_h_A;
  real_T c2_b_B;
  real_T c2_ob_x;
  real_T c2_w_y;
  real_T c2_pb_x;
  real_T c2_x_y;
  real_T c2_y_y;
  real_T c2_z;
  real_T c2_sigma;
  real_T c2_qb_x;
  real_T c2_x1;
  real_T c2_rb_x;
  real_T c2_x2;
  real_T c2_sb_x;
  real_T c2_tau;
  boolean_T c2_f_p;
  real_T c2_tb_x;
  boolean_T c2_g_p;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_ab_y;
  real_T c2_i_A;
  real_T c2_wb_x;
  real_T c2_c_B;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bb_y;
  boolean_T c2_h_p;
  real_T c2_bc_x;
  boolean_T c2_i_p;
  real_T c2_cb_y;
  real_T c2_db_y;
  real_T c2_cc_x;
  real_T c2_b_a;
  real_T c2_dc_x;
  real_T c2_e_b;
  boolean_T c2_j_p;
  boolean_T c2_k_p;
  real_T c2_eb_y;
  real_T c2_j_A;
  real_T c2_k_A;
  real_T c2_d_B;
  real_T c2_e_B;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_fb_y;
  real_T c2_gb_y;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_hb_y;
  real_T c2_ib_y;
  real_T c2_jb_y;
  real_T c2_kb_y;
  real_T c2_f_b;
  real_T c2_b_x1;
  real_T c2_lb_y;
  real_T c2_b_x2;
  real_T c2_l_A;
  real_T c2_aa;
  real_T c2_f_B;
  real_T c2_bb;
  real_T c2_ic_x;
  real_T c2_cc;
  real_T c2_mb_y;
  real_T c2_dd;
  real_T c2_jc_x;
  real_T c2_nb_y;
  real_T c2_m_A;
  real_T c2_g_B;
  real_T c2_kc_x;
  real_T c2_ob_y;
  real_T c2_lc_x;
  real_T c2_pb_y;
  real_T c2_mc_x;
  real_T c2_nc_x;
  real_T c2_oc_x;
  real_T c2_qb_y;
  real_T c2_pc_x;
  real_T c2_sab;
  real_T c2_qc_x;
  boolean_T c2_l_p;
  boolean_T c2_m_p;
  real_T c2_rc_x;
  real_T c2_sc_x;
  real_T c2_tc_x;
  real_T c2_rb_y;
  real_T c2_uc_x;
  real_T c2_sac;
  real_T c2_vc_x;
  boolean_T c2_n_p;
  boolean_T c2_o_p;
  real_T c2_c_a;
  real_T c2_g_b;
  real_T c2_wc_x;
  real_T c2_xc_x;
  real_T c2_yc_x;
  real_T c2_sb_y;
  real_T c2_ad_x;
  real_T c2_bd_x;
  real_T c2_cd_x;
  boolean_T c2_p_p;
  boolean_T c2_q_p;
  real_T c2_h_B;
  real_T c2_tb_y;
  real_T c2_ub_y;
  real_T c2_cs1;
  real_T c2_sn1;
  if (*c2_c == 0.0) {
    *c2_cs = 1.0;
    *c2_sn = 0.0;
  } else if (*c2_b_b == 0.0) {
    *c2_cs = 0.0;
    *c2_sn = 1.0;
    c2_temp = *c2_d;
    *c2_d = *c2_a;
    *c2_a = c2_temp;
    *c2_b_b = -*c2_c;
    *c2_c = 0.0;
  } else if ((*c2_a - *c2_d == 0.0) && (*c2_b_b < 0.0 != *c2_c < 0.0)) {
    *c2_cs = 1.0;
    *c2_sn = 0.0;
  } else {
    c2_temp = *c2_a - *c2_d;
    c2_p = 0.5 * c2_temp;
    c2_b_x = *c2_b_b;
    c2_c_x = c2_b_x;
    c2_e_x = c2_c_x;
    c2_b_y = muDoubleScalarAbs(c2_e_x);
    c2_h_x = *c2_c;
    c2_i_x = c2_h_x;
    c2_k_x = c2_i_x;
    c2_d_y = muDoubleScalarAbs(c2_k_x);
    c2_varargin_1 = c2_b_y;
    c2_varargin_2 = c2_d_y;
    c2_b_varargin_2 = c2_varargin_1;
    c2_varargin_3 = c2_varargin_2;
    c2_n_x = c2_b_varargin_2;
    c2_e_y = c2_varargin_3;
    c2_p_x = c2_n_x;
    c2_f_y = c2_e_y;
    c2_s_x = c2_p_x;
    c2_h_y = c2_f_y;
    c2_bcmax = muDoubleScalarMax(c2_s_x, c2_h_y);
    c2_v_x = *c2_b_b;
    c2_x_x = c2_v_x;
    c2_y_x = c2_x_x;
    c2_i_y = muDoubleScalarAbs(c2_y_x);
    c2_ab_x = *c2_c;
    c2_bb_x = c2_ab_x;
    c2_cb_x = c2_bb_x;
    c2_j_y = muDoubleScalarAbs(c2_cb_x);
    c2_b_varargin_1 = c2_i_y;
    c2_c_varargin_2 = c2_j_y;
    c2_d_varargin_2 = c2_b_varargin_1;
    c2_b_varargin_3 = c2_c_varargin_2;
    c2_db_x = c2_d_varargin_2;
    c2_k_y = c2_b_varargin_3;
    c2_eb_x = c2_db_x;
    c2_l_y = c2_k_y;
    c2_fb_x = c2_eb_x;
    c2_m_y = c2_l_y;
    c2_minval = muDoubleScalarMin(c2_fb_x, c2_m_y);
    c2_c_b = *c2_b_b;
    if (!(c2_c_b < 0.0)) {
      c2_n_y = 1.0;
    } else {
      c2_n_y = -1.0;
    }

    c2_d_b = *c2_c;
    if (!(c2_d_b < 0.0)) {
      c2_o_y = 1.0;
    } else {
      c2_o_y = -1.0;
    }

    c2_bcmis = c2_minval * c2_n_y * c2_o_y;
    c2_gb_x = c2_p;
    c2_hb_x = c2_gb_x;
    c2_ib_x = c2_hb_x;
    c2_p_y = muDoubleScalarAbs(c2_ib_x);
    c2_c_varargin_1 = c2_p_y;
    c2_e_varargin_2 = c2_bcmax;
    c2_f_varargin_2 = c2_c_varargin_1;
    c2_c_varargin_3 = c2_e_varargin_2;
    c2_jb_x = c2_f_varargin_2;
    c2_q_y = c2_c_varargin_3;
    c2_kb_x = c2_jb_x;
    c2_r_y = c2_q_y;
    c2_lb_x = c2_kb_x;
    c2_s_y = c2_r_y;
    c2_scale = muDoubleScalarMax(c2_lb_x, c2_s_y);
    c2_g_A = c2_p;
    c2_B = c2_scale;
    c2_mb_x = c2_g_A;
    c2_t_y = c2_B;
    c2_nb_x = c2_mb_x;
    c2_u_y = c2_t_y;
    c2_v_y = c2_nb_x / c2_u_y;
    c2_h_A = c2_bcmax;
    c2_b_B = c2_scale;
    c2_ob_x = c2_h_A;
    c2_w_y = c2_b_B;
    c2_pb_x = c2_ob_x;
    c2_x_y = c2_w_y;
    c2_y_y = c2_pb_x / c2_x_y;
    c2_z = c2_v_y * c2_p + c2_y_y * c2_bcmis;
    if (c2_z >= 8.8817841970012523E-16) {
      c2_qb_x = c2_scale;
      c2_rb_x = c2_qb_x;
      c2_sb_x = c2_rb_x;
      c2_f_p = (c2_sb_x < 0.0);
      c2_g_p = c2_f_p;
      if (c2_g_p) {
        c2_c_error(chartInstance);
      }

      c2_rb_x = muDoubleScalarSqrt(c2_rb_x);
      c2_wb_x = c2_z;
      c2_xb_x = c2_wb_x;
      c2_ac_x = c2_xb_x;
      c2_h_p = (c2_ac_x < 0.0);
      c2_i_p = c2_h_p;
      if (c2_i_p) {
        c2_c_error(chartInstance);
      }

      c2_xb_x = muDoubleScalarSqrt(c2_xb_x);
      c2_b_a = c2_rb_x * c2_xb_x;
      c2_e_b = c2_p;
      if (c2_e_b < 0.0 == c2_b_a < 0.0) {
        c2_eb_y = c2_b_a;
      } else {
        c2_eb_y = -c2_b_a;
      }

      c2_z = c2_p + c2_eb_y;
      *c2_a = *c2_d + c2_z;
      c2_k_A = c2_bcmax;
      c2_e_B = c2_z;
      c2_fc_x = c2_k_A;
      c2_gb_y = c2_e_B;
      c2_hc_x = c2_fc_x;
      c2_ib_y = c2_gb_y;
      c2_kb_y = c2_hc_x / c2_ib_y;
      *c2_d -= c2_kb_y * c2_bcmis;
      c2_b_x1 = *c2_c;
      c2_b_x2 = c2_z;
      c2_tau = muDoubleScalarHypot(c2_b_x1, c2_b_x2);
      c2_l_A = c2_z;
      c2_f_B = c2_tau;
      c2_ic_x = c2_l_A;
      c2_mb_y = c2_f_B;
      c2_jc_x = c2_ic_x;
      c2_nb_y = c2_mb_y;
      *c2_cs = c2_jc_x / c2_nb_y;
      c2_m_A = *c2_c;
      c2_g_B = c2_tau;
      c2_kc_x = c2_m_A;
      c2_ob_y = c2_g_B;
      c2_lc_x = c2_kc_x;
      c2_pb_y = c2_ob_y;
      *c2_sn = c2_lc_x / c2_pb_y;
      *c2_b_b -= *c2_c;
      *c2_c = 0.0;
    } else {
      c2_sigma = *c2_b_b + *c2_c;
      c2_x1 = c2_sigma;
      c2_x2 = c2_temp;
      c2_tau = muDoubleScalarHypot(c2_x1, c2_x2);
      c2_tb_x = c2_sigma;
      c2_ub_x = c2_tb_x;
      c2_vb_x = c2_ub_x;
      c2_ab_y = muDoubleScalarAbs(c2_vb_x);
      c2_i_A = c2_ab_y;
      c2_c_B = c2_tau;
      c2_yb_x = c2_i_A;
      c2_bb_y = c2_c_B;
      c2_bc_x = c2_yb_x;
      c2_cb_y = c2_bb_y;
      c2_db_y = c2_bc_x / c2_cb_y;
      c2_cc_x = 0.5 * (1.0 + c2_db_y);
      *c2_cs = c2_cc_x;
      c2_dc_x = *c2_cs;
      c2_j_p = (c2_dc_x < 0.0);
      c2_k_p = c2_j_p;
      if (c2_k_p) {
        c2_c_error(chartInstance);
      }

      *c2_cs = muDoubleScalarSqrt(*c2_cs);
      c2_j_A = c2_p;
      c2_d_B = c2_tau * *c2_cs;
      c2_ec_x = c2_j_A;
      c2_fb_y = c2_d_B;
      c2_gc_x = c2_ec_x;
      c2_hb_y = c2_fb_y;
      c2_jb_y = c2_gc_x / c2_hb_y;
      c2_f_b = c2_sigma;
      if (!(c2_f_b < 0.0)) {
        c2_lb_y = 1.0;
      } else {
        c2_lb_y = -1.0;
      }

      *c2_sn = -c2_jb_y * c2_lb_y;
      c2_aa = *c2_a * *c2_cs + *c2_b_b * *c2_sn;
      c2_bb = -*c2_a * *c2_sn + *c2_b_b * *c2_cs;
      c2_cc = *c2_c * *c2_cs + *c2_d * *c2_sn;
      c2_dd = -*c2_c * *c2_sn + *c2_d * *c2_cs;
      *c2_a = c2_aa * *c2_cs + c2_cc * *c2_sn;
      *c2_b_b = c2_bb * *c2_cs + c2_dd * *c2_sn;
      *c2_c = -c2_aa * *c2_sn + c2_cc * *c2_cs;
      *c2_d = -c2_bb * *c2_sn + c2_dd * *c2_cs;
      c2_temp = 0.5 * (*c2_a + *c2_d);
      *c2_a = c2_temp;
      *c2_d = c2_temp;
      if (*c2_c != 0.0) {
        if (*c2_b_b != 0.0) {
          if (*c2_b_b < 0.0 == *c2_c < 0.0) {
            c2_mc_x = *c2_b_b;
            c2_nc_x = c2_mc_x;
            c2_oc_x = c2_nc_x;
            c2_qb_y = muDoubleScalarAbs(c2_oc_x);
            c2_pc_x = c2_qb_y;
            c2_sab = c2_pc_x;
            c2_qc_x = c2_sab;
            c2_l_p = (c2_qc_x < 0.0);
            c2_m_p = c2_l_p;
            if (c2_m_p) {
              c2_c_error(chartInstance);
            }

            c2_sab = muDoubleScalarSqrt(c2_sab);
            c2_rc_x = *c2_c;
            c2_sc_x = c2_rc_x;
            c2_tc_x = c2_sc_x;
            c2_rb_y = muDoubleScalarAbs(c2_tc_x);
            c2_uc_x = c2_rb_y;
            c2_sac = c2_uc_x;
            c2_vc_x = c2_sac;
            c2_n_p = (c2_vc_x < 0.0);
            c2_o_p = c2_n_p;
            if (c2_o_p) {
              c2_c_error(chartInstance);
            }

            c2_sac = muDoubleScalarSqrt(c2_sac);
            c2_c_a = c2_sab * c2_sac;
            c2_g_b = *c2_c;
            if (c2_g_b < 0.0 == c2_c_a < 0.0) {
              c2_p = c2_c_a;
            } else {
              c2_p = -c2_c_a;
            }

            c2_wc_x = *c2_b_b + *c2_c;
            c2_xc_x = c2_wc_x;
            c2_yc_x = c2_xc_x;
            c2_sb_y = muDoubleScalarAbs(c2_yc_x);
            c2_ad_x = c2_sb_y;
            c2_bd_x = c2_ad_x;
            c2_cd_x = c2_bd_x;
            c2_p_p = (c2_cd_x < 0.0);
            c2_q_p = c2_p_p;
            if (c2_q_p) {
              c2_c_error(chartInstance);
            }

            c2_bd_x = muDoubleScalarSqrt(c2_bd_x);
            c2_h_B = c2_bd_x;
            c2_tb_y = c2_h_B;
            c2_ub_y = c2_tb_y;
            c2_tau = 1.0 / c2_ub_y;
            *c2_a = c2_temp + c2_p;
            *c2_d = c2_temp - c2_p;
            *c2_b_b -= *c2_c;
            *c2_c = 0.0;
            c2_cs1 = c2_sab * c2_tau;
            c2_sn1 = c2_sac * c2_tau;
            c2_temp = *c2_cs * c2_cs1 - *c2_sn * c2_sn1;
            *c2_sn = *c2_cs * c2_sn1 + *c2_sn * c2_cs1;
            *c2_cs = c2_temp;
          }
        } else {
          *c2_b_b = -*c2_c;
          *c2_c = 0.0;
          c2_temp = *c2_cs;
          *c2_cs = -*c2_sn;
          *c2_sn = c2_temp;
        }
      }
    }
  }

  *c2_rt1r = *c2_a;
  *c2_rt2r = *c2_d;
  if (*c2_c == 0.0) {
    *c2_rt1i = 0.0;
    *c2_rt2i = 0.0;
  } else {
    c2_d_x = *c2_b_b;
    c2_f_x = c2_d_x;
    c2_g_x = c2_f_x;
    c2_c_y = muDoubleScalarAbs(c2_g_x);
    c2_j_x = c2_c_y;
    c2_l_x = c2_j_x;
    c2_m_x = c2_l_x;
    c2_b_p = (c2_m_x < 0.0);
    c2_c_p = c2_b_p;
    if (c2_c_p) {
      c2_c_error(chartInstance);
    }

    c2_l_x = muDoubleScalarSqrt(c2_l_x);
    c2_o_x = *c2_c;
    c2_q_x = c2_o_x;
    c2_r_x = c2_q_x;
    c2_g_y = muDoubleScalarAbs(c2_r_x);
    c2_t_x = c2_g_y;
    c2_u_x = c2_t_x;
    c2_w_x = c2_u_x;
    c2_d_p = (c2_w_x < 0.0);
    c2_e_p = c2_d_p;
    if (c2_e_p) {
      c2_c_error(chartInstance);
    }

    c2_u_x = muDoubleScalarSqrt(c2_u_x);
    *c2_rt1i = c2_l_x * c2_u_x;
    *c2_rt2i = -*c2_rt1i;
  }
}

static void c2_emxEnsureCapacity(SFc2_simuleringInstanceStruct *chartInstance,
  c2_emxArray__common *c2_emxArray, int32_T c2_oldNumel, uint32_T c2_elementSize,
  const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, c2_elementSize);
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, c2_elementSize * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real_T(SFc2_simuleringInstanceStruct *chartInstance,
  c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions, const
  emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real_T(SFc2_simuleringInstanceStruct *chartInstance,
  c2_emxArray_real_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c2_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c2_pEmxArray)->size);
    emlrtFreeMex((void *)*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real_T *)NULL;
  }
}

static int32_T c2_div_nzp_s32(SFc2_simuleringInstanceStruct *chartInstance,
  int32_T c2_numerator, int32_T c2_denominator, uint32_T c2_ssid_src_loc,
  int32_T c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_quotient;
  uint32_T c2_absNumerator;
  uint32_T c2_absDenominator;
  boolean_T c2_quotientNeedsNegation;
  uint32_T c2_tempAbsQuotient;
  (void)chartInstance;
  (void)c2_ssid_src_loc;
  (void)c2_offset_src_loc;
  (void)c2_length_src_loc;
  if (c2_numerator < 0) {
    c2_absNumerator = ~(uint32_T)c2_numerator + 1U;
  } else {
    c2_absNumerator = (uint32_T)c2_numerator;
  }

  if (c2_denominator < 0) {
    c2_absDenominator = ~(uint32_T)c2_denominator + 1U;
  } else {
    c2_absDenominator = (uint32_T)c2_denominator;
  }

  c2_quotientNeedsNegation = (c2_numerator < 0 != c2_denominator < 0);
  c2_tempAbsQuotient = c2_absNumerator / c2_absDenominator;
  if (c2_quotientNeedsNegation) {
    c2_quotient = -(int32_T)c2_tempAbsQuotient;
  } else {
    c2_quotient = (int32_T)c2_tempAbsQuotient;
  }

  return c2_quotient;
}

static void init_dsm_address_info(SFc2_simuleringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_simuleringInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_b_Lambda_A = (real_T (*)[2304])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_b_Lambda_B = (real_T (*)[2304])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_Lambda_C = (real_T (*)[1152])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_t_clock = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_x = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c2_u_old = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_u = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_simulering_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2130888599U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2713778060U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2641644732U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(44720207U);
}

mxArray* sf_c2_simulering_get_post_codegen_info(void);
mxArray *sf_c2_simulering_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BFlp2aGQCPNygN5z2Wu3vC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(48);
      pr[1] = (double)(48);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(48);
      pr[1] = (double)(48);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(48);
      pr[1] = (double)(24);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_simulering_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_simulering_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c2_simulering_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_simulering_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_simulering_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_simulering(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c2_simulering\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_simulering_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simuleringInstanceStruct *chartInstance =
      (SFc2_simuleringInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _simuleringMachineNumber_,
           2,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_simuleringMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_simuleringMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _simuleringMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Lambda_A");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Lambda_B");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Lambda_C");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t_clock");
          _SFD_SET_DATA_PROPS(4,1,1,0,"x");
          _SFD_SET_DATA_PROPS(5,1,1,0,"u_old");
          _SFD_SET_DATA_PROPS(6,2,0,1,"u");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4827);
        _SFD_CV_INIT_EML_IF(0,1,0,279,294,4771,4795);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,282,294,-1,1);

        {
          unsigned int dimVector[2];
          dimVector[0]= 48U;
          dimVector[1]= 48U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 48U;
          dimVector[1]= 48U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 48U;
          dimVector[1]= 24U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _simuleringMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simuleringInstanceStruct *chartInstance =
      (SFc2_simuleringInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_b_Lambda_A);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_b_Lambda_B);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_Lambda_C);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_t_clock);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_x);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_u_old);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_u);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s3t03d2I3C6xTivZ384l4XF";
}

static void sf_opaque_initialize_c2_simulering(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_simuleringInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_simulering((SFc2_simuleringInstanceStruct*)
    chartInstanceVar);
  initialize_c2_simulering((SFc2_simuleringInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_simulering(void *chartInstanceVar)
{
  enable_c2_simulering((SFc2_simuleringInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_simulering(void *chartInstanceVar)
{
  disable_c2_simulering((SFc2_simuleringInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_simulering(void *chartInstanceVar)
{
  sf_gateway_c2_simulering((SFc2_simuleringInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_simulering(SimStruct* S)
{
  return get_sim_state_c2_simulering((SFc2_simuleringInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_simulering(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c2_simulering((SFc2_simuleringInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_simulering(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_simuleringInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_simulering_optimization_info();
    }

    finalize_c2_simulering((SFc2_simuleringInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_simulering((SFc2_simuleringInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_simulering(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_simulering((SFc2_simuleringInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_simulering(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simulering_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1043582707U));
  ssSetChecksum1(S,(3328630336U));
  ssSetChecksum2(S,(750091280U));
  ssSetChecksum3(S,(403716713U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_simulering(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_simulering(SimStruct *S)
{
  SFc2_simuleringInstanceStruct *chartInstance;
  chartInstance = (SFc2_simuleringInstanceStruct *)utMalloc(sizeof
    (SFc2_simuleringInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_simuleringInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_simulering;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_simulering;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_simulering;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_simulering;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_simulering;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_simulering;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_simulering;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_simulering;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_simulering;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_simulering;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_simulering;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_simulering(chartInstance);
}

void c2_simulering_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_simulering(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_simulering(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_simulering(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_simulering_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
