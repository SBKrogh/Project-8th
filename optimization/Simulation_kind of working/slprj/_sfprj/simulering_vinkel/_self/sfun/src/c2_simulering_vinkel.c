/* Include files */

#include "simulering_vinkel_sfun.h"
#include "c2_simulering_vinkel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simulering_vinkel_sfun_debug_macros.h"
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
static const char * c2_debug_family_names[55] = { "Ts", "t_h", "t_h_2", "u_hp",
  "u_hp1", "u_hp2", "data", "Gamma", "Omega", "Phi", "Pi", "Psi", "Theta",
  "constant_dist", "Data_OD", "t_1", "delta_p_0", "d_hp", "U_bar", "U_bar_hp",
  "q_bar_p_hp", "y_low", "y_high", "y_bar", "y1", "y2", "L_y", "x_low", "x_high",
  "x_bar", "delta_p_wt_1", "delta_p_wt_2", "u_low", "u_high", "R", "R1", "R2",
  "f", "A", "b", "lb", "ub", "func", "options", "nargin", "nargout", "Lambda_A",
  "Lambda_B", "Lambda_C", "t_clock", "x", "u_old", "DetR_old", "u", "DetR" };

/* Function Declarations */
static void initialize_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);
static void initialize_params_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance);
static void enable_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);
static void disable_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance);
static void set_sim_state_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);
static void sf_gateway_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);
static void mdl_start_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct *
  chartInstance);
static void c2_chartstep_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance);
static void initSimStructsc2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_DetR, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const char_T *c2_identifier, real_T
  c2_b_y[2]);
static void c2_d_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[2]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
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
static void c2_e_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[144]);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[6912]);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[48]);
static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[24]);
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
static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static real_T c2_det(SFc2_simulering_vinkelInstanceStruct *chartInstance, real_T
                     c2_b_x[2304]);
static void c2_xgetrf(SFc2_simulering_vinkelInstanceStruct *chartInstance,
                      real_T c2_b_A[2304], real_T c2_c_A[2304], int32_T c2_ipiv
                      [48]);
static void c2_error(SFc2_simulering_vinkelInstanceStruct *chartInstance);
static void c2_b_error(SFc2_simulering_vinkelInstanceStruct *chartInstance,
  int32_T c2_varargin_2);
static const mxArray *c2_emlrt_marshallOut(SFc2_simulering_vinkelInstanceStruct *
  chartInstance, const char * c2_b_u);
static void c2_i_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y);
static void c2_j_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y);
static void c2_k_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[168]);
static void c2_l_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y);
static void c2_m_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y);
static void c2_n_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[1152]);
static void c2_o_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y);
static void c2_p_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y);
static void c2_q_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[2304]);
static void c2_r_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y);
static void c2_s_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y);
static void c2_t_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[24]);
static void c2_u_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sjdLzyTh14ULkIImcl6xwW *c2_b_y);
static void c2_v_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sjdLzyTh14ULkIImcl6xwW *c2_b_y);
static void c2_w_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y);
static void c2_x_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y);
static void c2_y_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y);
static void c2_ab_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y);
static void c2_bb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[1152]);
static void c2_cb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y);
static void c2_db_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y);
static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[2304]);
static const mxArray *c2_c_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[48]);
static const mxArray *c2_d_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[7]);
static const mxArray *c2_e_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[9]);
static const mxArray *c2_f_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[14]);
static const mxArray *c2_g_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[48]);
static const mxArray *c2_h_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance);
static void c2_eb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_fmincon, const char_T *c2_identifier, real_T
  c2_b_y[48]);
static void c2_fb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[48]);
static const mxArray *c2_i_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u);
static const mxArray *c2_j_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[24]);
static const mxArray *c2_k_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[2]);
static const mxArray *c2_l_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[2]);
static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_gb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_hb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_simulering_vinkel, const
  char_T *c2_identifier);
static uint8_T c2_ib_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_xgetrf(SFc2_simulering_vinkelInstanceStruct *chartInstance,
  real_T c2_b_A[2304], int32_T c2_ipiv[48]);
static void init_dsm_address_info(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_simulering_vinkelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_simulering_vinkel(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_simulering_vinkel = 0U;
}

static void initialize_params_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_b_y = NULL;
  real_T c2_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(3, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_DetR;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", *chartInstance->c2_u, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_simulering_vinkel;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_b_y, 2, c2_e_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  real_T c2_dv0[2];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  *chartInstance->c2_DetR = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("DetR", c2_b_u, 0)), "DetR");
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("u", c2_b_u, 1)),
                        "u", c2_dv0);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    (*chartInstance->c2_u)[c2_i0] = c2_dv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_simulering_vinkel = c2_hb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_simulering_vinkel",
       c2_b_u, 2)), "is_active_c2_simulering_vinkel");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_simulering_vinkel(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct
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
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_DetR_old, 6U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
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
  c2_chartstep_c2_simulering_vinkel(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_simulering_vinkelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u)[c2_i5], 7U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_DetR, 8U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
}

static void mdl_start_c2_simulering_vinkel(SFc2_simulering_vinkelInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance)
{
  boolean_T c2_b0;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_b_t_clock;
  real_T c2_b_Lambda_C[1152];
  real_T c2_b_x;
  int32_T c2_i9;
  real_T c2_b_DetR_old;
  real_T c2_b_u_old[2];
  uint32_T c2_debug_family_var_map[55];
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
  real_T c2_t_1[24];
  real_T c2_delta_p_0;
  real_T c2_d_hp[48];
  real_T c2_U_bar;
  real_T c2_U_bar_hp[48];
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
  real_T c2_u_low;
  real_T c2_u_high;
  real_T c2_f[48];
  real_T c2_b[144];
  real_T c2_lb[48];
  real_T c2_ub[48];
  const mxArray *c2_func = NULL;
  const mxArray *c2_options = NULL;
  real_T c2_b_data[168];
  real_T c2_b_Gamma[1152];
  real_T c2_b_Phi[24];
  real_T c2_b_Psi[1152];
  real_T c2_b_Theta[1152];
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 2.0;
  real_T c2_b_u[2];
  real_T c2_b_DetR;
  real_T c2_b_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_c_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_j_x;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_r0;
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
  int32_T c2_i27;
  int32_T c2_i28;
  static real_T c2_dv1[48] = { 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562,
    0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562,
    0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991 };

  int32_T c2_i29;
  int32_T c2_i30;
  real_T c2_a[1152];
  real_T c2_alpha1;
  real_T c2_b_b[24];
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  int32_T c2_i31;
  ptrdiff_t c2_m_t;
  real_T c2_d_y[48];
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  real_T c2_c_b;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  real_T c2_b_alpha1;
  real_T c2_d_b[1152];
  real_T c2_b_beta1;
  char_T c2_b_TRANSB;
  char_T c2_b_TRANSA;
  int32_T c2_i35;
  ptrdiff_t c2_b_m_t;
  ptrdiff_t c2_b_n_t;
  ptrdiff_t c2_b_k_t;
  ptrdiff_t c2_b_lda_t;
  ptrdiff_t c2_b_ldb_t;
  ptrdiff_t c2_b_ldc_t;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_c_alpha1;
  real_T c2_e_b[48];
  real_T c2_c_beta1;
  char_T c2_c_TRANSB;
  char_T c2_c_TRANSA;
  int32_T c2_i38;
  ptrdiff_t c2_c_m_t;
  real_T c2_e_y[48];
  ptrdiff_t c2_c_n_t;
  ptrdiff_t c2_c_k_t;
  ptrdiff_t c2_c_lda_t;
  ptrdiff_t c2_c_ldb_t;
  ptrdiff_t c2_c_ldc_t;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  real_T c2_d_alpha1;
  real_T c2_d_beta1;
  char_T c2_d_TRANSB;
  char_T c2_d_TRANSA;
  int32_T c2_i42;
  ptrdiff_t c2_d_m_t;
  ptrdiff_t c2_d_n_t;
  ptrdiff_t c2_d_k_t;
  ptrdiff_t c2_d_lda_t;
  ptrdiff_t c2_d_ldb_t;
  ptrdiff_t c2_d_ldc_t;
  real_T c2_f_b;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  real_T c2_e_alpha1;
  real_T c2_e_beta1;
  char_T c2_e_TRANSB;
  char_T c2_e_TRANSA;
  int32_T c2_i46;
  ptrdiff_t c2_e_m_t;
  ptrdiff_t c2_e_n_t;
  ptrdiff_t c2_e_k_t;
  ptrdiff_t c2_e_lda_t;
  ptrdiff_t c2_e_ldb_t;
  ptrdiff_t c2_e_ldc_t;
  int32_T c2_i47;
  int32_T c2_i48;
  real_T c2_f_alpha1;
  real_T c2_f_beta1;
  char_T c2_f_TRANSB;
  char_T c2_f_TRANSA;
  int32_T c2_i49;
  ptrdiff_t c2_f_m_t;
  ptrdiff_t c2_f_n_t;
  ptrdiff_t c2_f_k_t;
  ptrdiff_t c2_f_lda_t;
  ptrdiff_t c2_f_ldb_t;
  ptrdiff_t c2_f_ldc_t;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  real_T c2_g_alpha1;
  real_T c2_g_beta1;
  char_T c2_g_TRANSB;
  char_T c2_g_TRANSA;
  int32_T c2_i53;
  ptrdiff_t c2_g_m_t;
  ptrdiff_t c2_g_n_t;
  ptrdiff_t c2_g_k_t;
  ptrdiff_t c2_g_lda_t;
  ptrdiff_t c2_g_ldb_t;
  ptrdiff_t c2_g_ldc_t;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  real_T c2_g_b;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  real_T c2_h_alpha1;
  real_T c2_h_beta1;
  char_T c2_h_TRANSB;
  char_T c2_h_TRANSA;
  int32_T c2_i62;
  ptrdiff_t c2_h_m_t;
  real_T c2_f_y[24];
  ptrdiff_t c2_h_n_t;
  ptrdiff_t c2_h_k_t;
  ptrdiff_t c2_h_lda_t;
  ptrdiff_t c2_h_ldb_t;
  ptrdiff_t c2_h_ldc_t;
  int32_T c2_i63;
  int32_T c2_i64;
  real_T c2_h_b;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  real_T c2_i_alpha1;
  real_T c2_i_beta1;
  char_T c2_i_TRANSB;
  char_T c2_i_TRANSA;
  int32_T c2_i68;
  ptrdiff_t c2_i_m_t;
  ptrdiff_t c2_i_n_t;
  ptrdiff_t c2_i_k_t;
  ptrdiff_t c2_i_lda_t;
  ptrdiff_t c2_i_ldb_t;
  ptrdiff_t c2_i_ldc_t;
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  real_T c2_j_alpha1;
  real_T c2_j_beta1;
  char_T c2_j_TRANSB;
  char_T c2_j_TRANSA;
  int32_T c2_i72;
  ptrdiff_t c2_j_m_t;
  ptrdiff_t c2_j_n_t;
  ptrdiff_t c2_j_k_t;
  ptrdiff_t c2_j_lda_t;
  ptrdiff_t c2_j_ldb_t;
  ptrdiff_t c2_j_ldc_t;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  real_T c2_k_alpha1;
  real_T c2_k_beta1;
  char_T c2_k_TRANSB;
  char_T c2_k_TRANSA;
  int32_T c2_i87;
  ptrdiff_t c2_k_m_t;
  ptrdiff_t c2_k_n_t;
  ptrdiff_t c2_k_k_t;
  ptrdiff_t c2_k_lda_t;
  ptrdiff_t c2_k_ldb_t;
  ptrdiff_t c2_k_ldc_t;
  int32_T c2_i88;
  real_T c2_l_alpha1;
  int32_T c2_i89;
  real_T c2_l_beta1;
  real_T c2_d_A[48];
  char_T c2_l_TRANSB;
  char_T c2_l_TRANSA;
  int32_T c2_i90;
  ptrdiff_t c2_l_m_t;
  real_T c2_g_y[48];
  ptrdiff_t c2_l_n_t;
  ptrdiff_t c2_l_k_t;
  ptrdiff_t c2_l_lda_t;
  ptrdiff_t c2_l_ldb_t;
  ptrdiff_t c2_l_ldc_t;
  int32_T c2_i91;
  int32_T c2_i92;
  real_T c2_m_alpha1;
  real_T c2_m_beta1;
  char_T c2_m_TRANSB;
  char_T c2_m_TRANSA;
  int32_T c2_i93;
  ptrdiff_t c2_m_m_t;
  ptrdiff_t c2_m_n_t;
  ptrdiff_t c2_m_k_t;
  ptrdiff_t c2_m_lda_t;
  ptrdiff_t c2_m_ldb_t;
  ptrdiff_t c2_m_ldc_t;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  real_T c2_n_alpha1;
  int32_T c2_i97;
  real_T c2_n_beta1;
  int32_T c2_i98;
  char_T c2_n_TRANSB;
  char_T c2_n_TRANSA;
  int32_T c2_i99;
  real_T c2_i_b[2304];
  ptrdiff_t c2_n_m_t;
  real_T c2_h_y[48];
  ptrdiff_t c2_n_n_t;
  ptrdiff_t c2_n_k_t;
  ptrdiff_t c2_n_lda_t;
  ptrdiff_t c2_n_ldb_t;
  ptrdiff_t c2_n_ldc_t;
  int32_T c2_i100;
  int32_T c2_i101;
  real_T c2_o_alpha1;
  real_T c2_o_beta1;
  char_T c2_o_TRANSB;
  char_T c2_o_TRANSA;
  int32_T c2_i102;
  ptrdiff_t c2_o_m_t;
  ptrdiff_t c2_o_n_t;
  ptrdiff_t c2_o_k_t;
  ptrdiff_t c2_o_lda_t;
  ptrdiff_t c2_o_ldb_t;
  ptrdiff_t c2_o_ldc_t;
  real_T c2_b_a;
  int32_T c2_i103;
  int32_T c2_i104;
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
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  int32_T c2_i126;
  int32_T c2_i127;
  static char_T c2_cv0[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  static char_T c2_cv1[9] = { 'A', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm' };

  static char_T c2_cv2[14] = { 'i', 'n', 't', 'e', 'r', 'i', 'o', 'r', '-', 'p',
    'o', 'i', 'n', 't' };

  int32_T c2_i128;
  real_T c2_dv2[48];
  real_T c2_dv3[48];
  int32_T c2_i129;
  int32_T c2_i130;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  static char_T c2_cv3[2] = { 'o', 'n' };

  int32_T c2_i134;
  real_T c2_c_data[24];
  int32_T c2_i135;
  int32_T c2_i136;
  real_T c2_b_R[2304];
  c2_b0 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_t_clock;
  c2_b_hoistedGlobal = *chartInstance->c2_x;
  c2_c_hoistedGlobal = *chartInstance->c2_DetR_old;
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

  c2_b_DetR_old = c2_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 55U, 62U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Ts, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_t_h, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_t_h_2, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp, 3U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp1, 4U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp2, 5U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_data, MAX_uint32_T,
    c2_u_sf_marshallOut, c2_t_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Gamma, MAX_uint32_T,
    c2_t_sf_marshallOut, c2_s_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Omega, MAX_uint32_T,
    c2_s_sf_marshallOut, c2_r_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Phi, MAX_uint32_T,
    c2_r_sf_marshallOut, c2_q_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_Pi, MAX_uint32_T,
    c2_q_sf_marshallOut, c2_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Psi, MAX_uint32_T,
    c2_p_sf_marshallOut, c2_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Theta, MAX_uint32_T,
    c2_o_sf_marshallOut, c2_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_constant_dist, 13U,
    c2_n_sf_marshallOut, c2_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Data_OD, 14U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_t_1, 15U, c2_m_sf_marshallOut,
    c2_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_delta_p_0, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d_hp, 17U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_U_bar, 18U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_U_bar_hp, 19U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q_bar_p_hp, 20U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_low, 21U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_high, 22U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_bar, 23U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y1, 24U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y2, 25U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_L_y, 26U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_low, 27U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_high, 28U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_bar, 29U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_delta_p_wt_1, 30U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_delta_p_wt_2, 31U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_u_low, 32U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_u_high, 33U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R, 34U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R1, 35U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R2, 36U,
    c2_d_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_f, 37U, c2_l_sf_marshallOut,
    c2_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_A, 38U,
    c2_k_sf_marshallOut, c2_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b, 39U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_lb, 40U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_ub, 41U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_func, 42U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_options, 43U, c2_h_sf_marshallOut);
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 44U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 45U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Lambda_A, 46U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Lambda_B, 47U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_Lambda_C, 48U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_t_clock, 49U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_x, 50U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u_old, 51U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_DetR_old, 52U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_u, 53U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_DetR, 54U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_Ts = 6.4385;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_b_A = c2_b_t_clock;
  c2_c_x = c2_b_A;
  c2_d_x = c2_c_x;
  c2_b_y = c2_d_x / 3600.0;
  c2_e_x = c2_b_y;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarFloor(c2_f_x);
  c2_t_h = 1.0 + c2_f_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_c_A = c2_b_t_clock - c2_Ts;
  c2_g_x = c2_c_A;
  c2_h_x = c2_g_x;
  c2_c_y = c2_h_x / 3600.0;
  c2_i_x = c2_c_y;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarFloor(c2_j_x);
  c2_t_h_2 = 1.0 + c2_j_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_t_h, c2_t_h_2, -1, 1U,
        c2_t_h != c2_t_h_2))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    for (c2_i11 = 0; c2_i11 < 48; c2_i11++) {
      c2_u_hp[c2_i11] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    for (c2_i12 = 0; c2_i12 < 24; c2_i12++) {
      c2_u_hp1[c2_i12] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    for (c2_i13 = 0; c2_i13 < 24; c2_i13++) {
      c2_u_hp2[c2_i13] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
    _SFD_SYMBOL_SWITCH(6U, 6U);
    c2_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "data.mat")), "load", &c2_r0);
    c2_data = c2_r0;
    _SFD_SYMBOL_SWITCH(6U, 6U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
    for (c2_i15 = 0; c2_i15 < 168; c2_i15++) {
      c2_b_data[c2_i15] = c2_data.data[c2_i15];
    }

    _SFD_SYMBOL_SWITCH(6U, 44U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
    _SFD_SYMBOL_SWITCH(7U, 7U);
    c2_l_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Gamma.mat")), "load", &c2_r1);
    c2_Gamma = c2_r1;
    _SFD_SYMBOL_SWITCH(7U, 7U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
    for (c2_i16 = 0; c2_i16 < 1152; c2_i16++) {
      c2_b_Gamma[c2_i16] = c2_Gamma.Gamma[c2_i16];
    }

    _SFD_SYMBOL_SWITCH(7U, 45U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    _SFD_SYMBOL_SWITCH(8U, 8U);
    c2_o_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Omega.mat")), "load",
                          &chartInstance->c2_r2);
    chartInstance->c2_Omega = chartInstance->c2_r2;
    _SFD_SYMBOL_SWITCH(8U, 8U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    for (c2_i17 = 0; c2_i17 < 2304; c2_i17++) {
      chartInstance->c2_b_Omega[c2_i17] = chartInstance->c2_Omega.Omega[c2_i17];
    }

    _SFD_SYMBOL_SWITCH(8U, 46U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    _SFD_SYMBOL_SWITCH(9U, 9U);
    c2_r_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Phi.mat")), "load", &c2_r3);
    c2_Phi = c2_r3;
    _SFD_SYMBOL_SWITCH(9U, 9U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
    for (c2_i18 = 0; c2_i18 < 24; c2_i18++) {
      c2_b_Phi[c2_i18] = c2_Phi.Phi[c2_i18];
    }

    _SFD_SYMBOL_SWITCH(9U, 47U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
    _SFD_SYMBOL_SWITCH(10U, 10U);
    c2_u_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Pi.mat")), "load",
                          &chartInstance->c2_r4);
    chartInstance->c2_Pi = chartInstance->c2_r4;
    _SFD_SYMBOL_SWITCH(10U, 10U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
    for (c2_i19 = 0; c2_i19 < 2304; c2_i19++) {
      chartInstance->c2_b_Pi[c2_i19] = chartInstance->c2_Pi.Pi[c2_i19];
    }

    _SFD_SYMBOL_SWITCH(10U, 48U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    _SFD_SYMBOL_SWITCH(11U, 11U);
    c2_w_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Psi.mat")), "load", &c2_r5);
    c2_Psi = c2_r5;
    _SFD_SYMBOL_SWITCH(11U, 11U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
    for (c2_i20 = 0; c2_i20 < 1152; c2_i20++) {
      c2_b_Psi[c2_i20] = c2_Psi.Psi[c2_i20];
    }

    _SFD_SYMBOL_SWITCH(11U, 49U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
    _SFD_SYMBOL_SWITCH(12U, 12U);
    c2_y_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Theta.mat")), "load", &c2_r6);
    c2_Theta = c2_r6;
    _SFD_SYMBOL_SWITCH(12U, 12U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
    for (c2_i21 = 0; c2_i21 < 1152; c2_i21++) {
      c2_b_Theta[c2_i21] = c2_Theta.Theta[c2_i21];
    }

    _SFD_SYMBOL_SWITCH(12U, 50U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
    c2_cb_emlrt_marshallIn(chartInstance, sf_mex_call_debug
      (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14, c2_emlrt_marshallOut
       (chartInstance, "constant_dist.mat")), "load", &c2_r7);
    c2_constant_dist = c2_r7;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
    for (c2_i22 = 0; c2_i22 < 24; c2_i22++) {
      c2_Data_OD[c2_i22] = c2_constant_dist.constant_dist[c2_i22];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
    for (c2_i23 = 0; c2_i23 < 24; c2_i23++) {
      c2_t_1[c2_i23] = 3600.0 * (real_T)c2_i23;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
    c2_delta_p_0 = c2_b_x;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
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
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
    c2_U_bar = 0.2;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
    for (c2_i24 = 0; c2_i24 < 48; c2_i24++) {
      c2_U_bar_hp[c2_i24] = 0.2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
    for (c2_i25 = 0; c2_i25 < 48; c2_i25++) {
      c2_q_bar_p_hp[c2_i25] = 0.45;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
    for (c2_i26 = 0; c2_i26 < 48; c2_i26++) {
      c2_y_low[c2_i26] = 0.08;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    for (c2_i27 = 0; c2_i27 < 48; c2_i27++) {
      c2_y_high[c2_i27] = 0.18;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 82);
    for (c2_i28 = 0; c2_i28 < 48; c2_i28++) {
      c2_y_bar[c2_i28] = c2_dv1[c2_i28];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
    for (c2_i29 = 0; c2_i29 < 1152; c2_i29++) {
      c2_a[c2_i29] = c2_b_Theta[c2_i29];
    }

    for (c2_i30 = 0; c2_i30 < 24; c2_i30++) {
      c2_b_b[c2_i30] = c2_b_Phi[c2_i30];
    }

    c2_alpha1 = 1.0;
    c2_beta1 = 0.0;
    c2_TRANSB = 'N';
    c2_TRANSA = 'N';
    for (c2_i31 = 0; c2_i31 < 48; c2_i31++) {
      c2_d_y[c2_i31] = 0.0;
    }

    c2_m_t = (ptrdiff_t)48;
    c2_n_t = (ptrdiff_t)1;
    c2_k_t = (ptrdiff_t)24;
    c2_lda_t = (ptrdiff_t)48;
    c2_ldb_t = (ptrdiff_t)24;
    c2_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1, &c2_a[0],
          &c2_lda_t, &c2_b_b[0], &c2_ldb_t, &c2_beta1, &c2_d_y[0], &c2_ldc_t);
    c2_c_b = c2_delta_p_0;
    for (c2_i32 = 0; c2_i32 < 48; c2_i32++) {
      c2_d_y[c2_i32] *= c2_c_b;
    }

    for (c2_i33 = 0; c2_i33 < 1152; c2_i33++) {
      c2_a[c2_i33] = c2_b_Theta[c2_i33];
    }

    for (c2_i34 = 0; c2_i34 < 1152; c2_i34++) {
      c2_d_b[c2_i34] = c2_b_Psi[c2_i34];
    }

    c2_b_alpha1 = 1.0;
    c2_b_beta1 = 0.0;
    c2_b_TRANSB = 'N';
    c2_b_TRANSA = 'N';
    for (c2_i35 = 0; c2_i35 < 2304; c2_i35++) {
      chartInstance->c2_y[c2_i35] = 0.0;
    }

    c2_b_m_t = (ptrdiff_t)48;
    c2_b_n_t = (ptrdiff_t)48;
    c2_b_k_t = (ptrdiff_t)24;
    c2_b_lda_t = (ptrdiff_t)48;
    c2_b_ldb_t = (ptrdiff_t)24;
    c2_b_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_b_TRANSA, &c2_b_TRANSB, &c2_b_m_t, &c2_b_n_t, &c2_b_k_t,
          &c2_b_alpha1, &c2_a[0], &c2_b_lda_t, &c2_d_b[0], &c2_b_ldb_t,
          &c2_b_beta1, &chartInstance->c2_y[0], &c2_b_ldc_t);
    for (c2_i36 = 0; c2_i36 < 2304; c2_i36++) {
      chartInstance->c2_y[c2_i36] += chartInstance->c2_b_Pi[c2_i36];
    }

    for (c2_i37 = 0; c2_i37 < 48; c2_i37++) {
      c2_e_b[c2_i37] = c2_d_hp[c2_i37];
    }

    c2_c_alpha1 = 1.0;
    c2_c_beta1 = 0.0;
    c2_c_TRANSB = 'N';
    c2_c_TRANSA = 'N';
    for (c2_i38 = 0; c2_i38 < 48; c2_i38++) {
      c2_e_y[c2_i38] = 0.0;
    }

    c2_c_m_t = (ptrdiff_t)48;
    c2_c_n_t = (ptrdiff_t)1;
    c2_c_k_t = (ptrdiff_t)48;
    c2_c_lda_t = (ptrdiff_t)48;
    c2_c_ldb_t = (ptrdiff_t)48;
    c2_c_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_c_TRANSA, &c2_c_TRANSB, &c2_c_m_t, &c2_c_n_t, &c2_c_k_t,
          &c2_c_alpha1, &chartInstance->c2_y[0], &c2_c_lda_t, &c2_e_b[0],
          &c2_c_ldb_t, &c2_c_beta1, &c2_e_y[0], &c2_c_ldc_t);
    for (c2_i39 = 0; c2_i39 < 48; c2_i39++) {
      c2_y1[c2_i39] = ((c2_y_low[c2_i39] - c2_y_bar[c2_i39]) - c2_d_y[c2_i39]) -
        c2_e_y[c2_i39];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
    for (c2_i40 = 0; c2_i40 < 1152; c2_i40++) {
      c2_a[c2_i40] = c2_b_Theta[c2_i40];
    }

    for (c2_i41 = 0; c2_i41 < 24; c2_i41++) {
      c2_b_b[c2_i41] = c2_b_Phi[c2_i41];
    }

    c2_d_alpha1 = 1.0;
    c2_d_beta1 = 0.0;
    c2_d_TRANSB = 'N';
    c2_d_TRANSA = 'N';
    for (c2_i42 = 0; c2_i42 < 48; c2_i42++) {
      c2_d_y[c2_i42] = 0.0;
    }

    c2_d_m_t = (ptrdiff_t)48;
    c2_d_n_t = (ptrdiff_t)1;
    c2_d_k_t = (ptrdiff_t)24;
    c2_d_lda_t = (ptrdiff_t)48;
    c2_d_ldb_t = (ptrdiff_t)24;
    c2_d_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_d_TRANSA, &c2_d_TRANSB, &c2_d_m_t, &c2_d_n_t, &c2_d_k_t,
          &c2_d_alpha1, &c2_a[0], &c2_d_lda_t, &c2_b_b[0], &c2_d_ldb_t,
          &c2_d_beta1, &c2_d_y[0], &c2_d_ldc_t);
    c2_f_b = c2_delta_p_0;
    for (c2_i43 = 0; c2_i43 < 48; c2_i43++) {
      c2_d_y[c2_i43] *= c2_f_b;
    }

    for (c2_i44 = 0; c2_i44 < 1152; c2_i44++) {
      c2_a[c2_i44] = c2_b_Theta[c2_i44];
    }

    for (c2_i45 = 0; c2_i45 < 1152; c2_i45++) {
      c2_d_b[c2_i45] = c2_b_Psi[c2_i45];
    }

    c2_e_alpha1 = 1.0;
    c2_e_beta1 = 0.0;
    c2_e_TRANSB = 'N';
    c2_e_TRANSA = 'N';
    for (c2_i46 = 0; c2_i46 < 2304; c2_i46++) {
      chartInstance->c2_y[c2_i46] = 0.0;
    }

    c2_e_m_t = (ptrdiff_t)48;
    c2_e_n_t = (ptrdiff_t)48;
    c2_e_k_t = (ptrdiff_t)24;
    c2_e_lda_t = (ptrdiff_t)48;
    c2_e_ldb_t = (ptrdiff_t)24;
    c2_e_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_e_TRANSA, &c2_e_TRANSB, &c2_e_m_t, &c2_e_n_t, &c2_e_k_t,
          &c2_e_alpha1, &c2_a[0], &c2_e_lda_t, &c2_d_b[0], &c2_e_ldb_t,
          &c2_e_beta1, &chartInstance->c2_y[0], &c2_e_ldc_t);
    for (c2_i47 = 0; c2_i47 < 2304; c2_i47++) {
      chartInstance->c2_y[c2_i47] += chartInstance->c2_b_Pi[c2_i47];
    }

    for (c2_i48 = 0; c2_i48 < 48; c2_i48++) {
      c2_e_b[c2_i48] = c2_d_hp[c2_i48];
    }

    c2_f_alpha1 = 1.0;
    c2_f_beta1 = 0.0;
    c2_f_TRANSB = 'N';
    c2_f_TRANSA = 'N';
    for (c2_i49 = 0; c2_i49 < 48; c2_i49++) {
      c2_e_y[c2_i49] = 0.0;
    }

    c2_f_m_t = (ptrdiff_t)48;
    c2_f_n_t = (ptrdiff_t)1;
    c2_f_k_t = (ptrdiff_t)48;
    c2_f_lda_t = (ptrdiff_t)48;
    c2_f_ldb_t = (ptrdiff_t)48;
    c2_f_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_f_TRANSA, &c2_f_TRANSB, &c2_f_m_t, &c2_f_n_t, &c2_f_k_t,
          &c2_f_alpha1, &chartInstance->c2_y[0], &c2_f_lda_t, &c2_e_b[0],
          &c2_f_ldb_t, &c2_f_beta1, &c2_e_y[0], &c2_f_ldc_t);
    for (c2_i50 = 0; c2_i50 < 48; c2_i50++) {
      c2_y2[c2_i50] = ((c2_y_high[c2_i50] - c2_y_bar[c2_i50]) - c2_d_y[c2_i50])
        - c2_e_y[c2_i50];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
    for (c2_i51 = 0; c2_i51 < 1152; c2_i51++) {
      c2_a[c2_i51] = c2_b_Theta[c2_i51];
    }

    for (c2_i52 = 0; c2_i52 < 1152; c2_i52++) {
      c2_d_b[c2_i52] = c2_b_Gamma[c2_i52];
    }

    c2_g_alpha1 = 1.0;
    c2_g_beta1 = 0.0;
    c2_g_TRANSB = 'N';
    c2_g_TRANSA = 'N';
    for (c2_i53 = 0; c2_i53 < 2304; c2_i53++) {
      chartInstance->c2_y[c2_i53] = 0.0;
    }

    c2_g_m_t = (ptrdiff_t)48;
    c2_g_n_t = (ptrdiff_t)48;
    c2_g_k_t = (ptrdiff_t)24;
    c2_g_lda_t = (ptrdiff_t)48;
    c2_g_ldb_t = (ptrdiff_t)24;
    c2_g_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_g_TRANSA, &c2_g_TRANSB, &c2_g_m_t, &c2_g_n_t, &c2_g_k_t,
          &c2_g_alpha1, &c2_a[0], &c2_g_lda_t, &c2_d_b[0], &c2_g_ldb_t,
          &c2_g_beta1, &chartInstance->c2_y[0], &c2_g_ldc_t);
    for (c2_i54 = 0; c2_i54 < 2304; c2_i54++) {
      chartInstance->c2_L_y[c2_i54] = chartInstance->c2_y[c2_i54] +
        chartInstance->c2_b_Omega[c2_i54];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
    for (c2_i55 = 0; c2_i55 < 24; c2_i55++) {
      c2_x_low[c2_i55] = 0.055;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
    for (c2_i56 = 0; c2_i56 < 24; c2_i56++) {
      c2_x_high[c2_i56] = 0.16;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
    for (c2_i57 = 0; c2_i57 < 24; c2_i57++) {
      c2_x_bar[c2_i57] = 0.127;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 96);
    for (c2_i58 = 0; c2_i58 < 24; c2_i58++) {
      c2_b_b[c2_i58] = c2_b_Phi[c2_i58];
    }

    c2_g_b = c2_delta_p_0;
    for (c2_i59 = 0; c2_i59 < 24; c2_i59++) {
      c2_b_b[c2_i59] *= c2_g_b;
    }

    for (c2_i60 = 0; c2_i60 < 1152; c2_i60++) {
      c2_d_b[c2_i60] = c2_b_Psi[c2_i60];
    }

    for (c2_i61 = 0; c2_i61 < 48; c2_i61++) {
      c2_e_b[c2_i61] = c2_d_hp[c2_i61];
    }

    c2_h_alpha1 = 1.0;
    c2_h_beta1 = 0.0;
    c2_h_TRANSB = 'N';
    c2_h_TRANSA = 'N';
    for (c2_i62 = 0; c2_i62 < 24; c2_i62++) {
      c2_f_y[c2_i62] = 0.0;
    }

    c2_h_m_t = (ptrdiff_t)24;
    c2_h_n_t = (ptrdiff_t)1;
    c2_h_k_t = (ptrdiff_t)48;
    c2_h_lda_t = (ptrdiff_t)24;
    c2_h_ldb_t = (ptrdiff_t)48;
    c2_h_ldc_t = (ptrdiff_t)24;
    dgemm(&c2_h_TRANSA, &c2_h_TRANSB, &c2_h_m_t, &c2_h_n_t, &c2_h_k_t,
          &c2_h_alpha1, &c2_d_b[0], &c2_h_lda_t, &c2_e_b[0], &c2_h_ldb_t,
          &c2_h_beta1, &c2_f_y[0], &c2_h_ldc_t);
    for (c2_i63 = 0; c2_i63 < 24; c2_i63++) {
      c2_delta_p_wt_1[c2_i63] = ((c2_x_low[c2_i63] - c2_x_bar[c2_i63]) -
        c2_b_b[c2_i63]) - c2_f_y[c2_i63];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
    for (c2_i64 = 0; c2_i64 < 24; c2_i64++) {
      c2_b_b[c2_i64] = c2_b_Phi[c2_i64];
    }

    c2_h_b = c2_delta_p_0;
    for (c2_i65 = 0; c2_i65 < 24; c2_i65++) {
      c2_b_b[c2_i65] *= c2_h_b;
    }

    for (c2_i66 = 0; c2_i66 < 1152; c2_i66++) {
      c2_d_b[c2_i66] = c2_b_Psi[c2_i66];
    }

    for (c2_i67 = 0; c2_i67 < 48; c2_i67++) {
      c2_e_b[c2_i67] = c2_d_hp[c2_i67];
    }

    c2_i_alpha1 = 1.0;
    c2_i_beta1 = 0.0;
    c2_i_TRANSB = 'N';
    c2_i_TRANSA = 'N';
    for (c2_i68 = 0; c2_i68 < 24; c2_i68++) {
      c2_f_y[c2_i68] = 0.0;
    }

    c2_i_m_t = (ptrdiff_t)24;
    c2_i_n_t = (ptrdiff_t)1;
    c2_i_k_t = (ptrdiff_t)48;
    c2_i_lda_t = (ptrdiff_t)24;
    c2_i_ldb_t = (ptrdiff_t)48;
    c2_i_ldc_t = (ptrdiff_t)24;
    dgemm(&c2_i_TRANSA, &c2_i_TRANSB, &c2_i_m_t, &c2_i_n_t, &c2_i_k_t,
          &c2_i_alpha1, &c2_d_b[0], &c2_i_lda_t, &c2_e_b[0], &c2_i_ldb_t,
          &c2_i_beta1, &c2_f_y[0], &c2_i_ldc_t);
    for (c2_i69 = 0; c2_i69 < 24; c2_i69++) {
      c2_delta_p_wt_2[c2_i69] = ((c2_x_high[c2_i69] - c2_x_bar[c2_i69]) -
        c2_b_b[c2_i69]) - c2_f_y[c2_i69];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 100);
    c2_u_low = -0.15000000000000002;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
    c2_u_high = 0.75;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
    for (c2_i70 = 0; c2_i70 < 1152; c2_i70++) {
      c2_a[c2_i70] = c2_b_Lambda_C[c2_i70];
    }

    for (c2_i71 = 0; c2_i71 < 1152; c2_i71++) {
      c2_d_b[c2_i71] = c2_b_Gamma[c2_i71];
    }

    c2_j_alpha1 = 1.0;
    c2_j_beta1 = 0.0;
    c2_j_TRANSB = 'N';
    c2_j_TRANSA = 'N';
    for (c2_i72 = 0; c2_i72 < 2304; c2_i72++) {
      chartInstance->c2_y[c2_i72] = 0.0;
    }

    c2_j_m_t = (ptrdiff_t)48;
    c2_j_n_t = (ptrdiff_t)48;
    c2_j_k_t = (ptrdiff_t)24;
    c2_j_lda_t = (ptrdiff_t)48;
    c2_j_ldb_t = (ptrdiff_t)24;
    c2_j_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_j_TRANSA, &c2_j_TRANSB, &c2_j_m_t, &c2_j_n_t, &c2_j_k_t,
          &c2_j_alpha1, &c2_a[0], &c2_j_lda_t, &c2_d_b[0], &c2_j_ldb_t,
          &c2_j_beta1, &chartInstance->c2_y[0], &c2_j_ldc_t);
    for (c2_i73 = 0; c2_i73 < 2304; c2_i73++) {
      chartInstance->c2_y[c2_i73] += chartInstance->c2_Lambda_A[c2_i73];
    }

    for (c2_i74 = 0; c2_i74 < 2304; c2_i74++) {
      chartInstance->c2_R[c2_i74] = 2.0 * chartInstance->c2_y[c2_i74];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 109);
    c2_i75 = 0;
    for (c2_i76 = 0; c2_i76 < 48; c2_i76++) {
      c2_i78 = 0;
      for (c2_i79 = 0; c2_i79 < 48; c2_i79++) {
        chartInstance->c2_y[c2_i79 + c2_i75] = chartInstance->c2_R[c2_i79 +
          c2_i75] + chartInstance->c2_R[c2_i78 + c2_i76];
        c2_i78 += 48;
      }

      c2_i75 += 48;
    }

    for (c2_i77 = 0; c2_i77 < 2304; c2_i77++) {
      chartInstance->c2_R1[c2_i77] = chartInstance->c2_y[c2_i77] / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 110);
    c2_i80 = 0;
    for (c2_i81 = 0; c2_i81 < 48; c2_i81++) {
      c2_i83 = 0;
      for (c2_i84 = 0; c2_i84 < 48; c2_i84++) {
        chartInstance->c2_y[c2_i84 + c2_i80] = chartInstance->c2_R[c2_i84 +
          c2_i80] - chartInstance->c2_R[c2_i83 + c2_i81];
        c2_i83 += 48;
      }

      c2_i80 += 48;
    }

    for (c2_i82 = 0; c2_i82 < 2304; c2_i82++) {
      chartInstance->c2_R2[c2_i82] = chartInstance->c2_y[c2_i82] / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 111);
    for (c2_i85 = 0; c2_i85 < 1152; c2_i85++) {
      c2_a[c2_i85] = c2_b_Lambda_C[c2_i85];
    }

    for (c2_i86 = 0; c2_i86 < 1152; c2_i86++) {
      c2_d_b[c2_i86] = c2_b_Gamma[c2_i86];
    }

    c2_k_alpha1 = 1.0;
    c2_k_beta1 = 0.0;
    c2_k_TRANSB = 'N';
    c2_k_TRANSA = 'N';
    for (c2_i87 = 0; c2_i87 < 2304; c2_i87++) {
      chartInstance->c2_y[c2_i87] = 0.0;
    }

    c2_k_m_t = (ptrdiff_t)48;
    c2_k_n_t = (ptrdiff_t)48;
    c2_k_k_t = (ptrdiff_t)24;
    c2_k_lda_t = (ptrdiff_t)48;
    c2_k_ldb_t = (ptrdiff_t)24;
    c2_k_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_k_TRANSA, &c2_k_TRANSB, &c2_k_m_t, &c2_k_n_t, &c2_k_k_t,
          &c2_k_alpha1, &c2_a[0], &c2_k_lda_t, &c2_d_b[0], &c2_k_ldb_t,
          &c2_k_beta1, &chartInstance->c2_y[0], &c2_k_ldc_t);
    for (c2_i88 = 0; c2_i88 < 2304; c2_i88++) {
      chartInstance->c2_y[c2_i88] += chartInstance->c2_Lambda_A[c2_i88];
    }

    c2_l_alpha1 = 1.0;
    for (c2_i89 = 0; c2_i89 < 48; c2_i89++) {
      c2_d_A[c2_i89] = 0.2;
    }

    c2_l_beta1 = 0.0;
    c2_l_TRANSB = 'N';
    c2_l_TRANSA = 'N';
    for (c2_i90 = 0; c2_i90 < 48; c2_i90++) {
      c2_g_y[c2_i90] = 0.0;
    }

    c2_l_m_t = (ptrdiff_t)1;
    c2_l_n_t = (ptrdiff_t)48;
    c2_l_k_t = (ptrdiff_t)48;
    c2_l_lda_t = (ptrdiff_t)1;
    c2_l_ldb_t = (ptrdiff_t)48;
    c2_l_ldc_t = (ptrdiff_t)1;
    dgemm(&c2_l_TRANSA, &c2_l_TRANSB, &c2_l_m_t, &c2_l_n_t, &c2_l_k_t,
          &c2_l_alpha1, &c2_d_A[0], &c2_l_lda_t, &chartInstance->c2_y[0],
          &c2_l_ldb_t, &c2_l_beta1, &c2_g_y[0], &c2_l_ldc_t);
    for (c2_i91 = 0; c2_i91 < 1152; c2_i91++) {
      c2_a[c2_i91] = c2_b_Lambda_C[c2_i91];
    }

    for (c2_i92 = 0; c2_i92 < 1152; c2_i92++) {
      c2_d_b[c2_i92] = c2_b_Psi[c2_i92];
    }

    c2_m_alpha1 = 1.0;
    c2_m_beta1 = 0.0;
    c2_m_TRANSB = 'N';
    c2_m_TRANSA = 'N';
    for (c2_i93 = 0; c2_i93 < 2304; c2_i93++) {
      chartInstance->c2_y[c2_i93] = 0.0;
    }

    c2_m_m_t = (ptrdiff_t)48;
    c2_m_n_t = (ptrdiff_t)48;
    c2_m_k_t = (ptrdiff_t)24;
    c2_m_lda_t = (ptrdiff_t)48;
    c2_m_ldb_t = (ptrdiff_t)24;
    c2_m_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_m_TRANSA, &c2_m_TRANSB, &c2_m_m_t, &c2_m_n_t, &c2_m_k_t,
          &c2_m_alpha1, &c2_a[0], &c2_m_lda_t, &c2_d_b[0], &c2_m_ldb_t,
          &c2_m_beta1, &chartInstance->c2_y[0], &c2_m_ldc_t);
    for (c2_i94 = 0; c2_i94 < 48; c2_i94++) {
      c2_d_A[c2_i94] = c2_d_hp[c2_i94];
    }

    c2_i95 = 0;
    for (c2_i96 = 0; c2_i96 < 48; c2_i96++) {
      c2_i97 = 0;
      for (c2_i98 = 0; c2_i98 < 48; c2_i98++) {
        c2_i_b[c2_i98 + c2_i95] = chartInstance->c2_Lambda_B[c2_i97 + c2_i96] +
          chartInstance->c2_y[c2_i97 + c2_i96];
        c2_i97 += 48;
      }

      c2_i95 += 48;
    }

    c2_n_alpha1 = 1.0;
    c2_n_beta1 = 0.0;
    c2_n_TRANSB = 'N';
    c2_n_TRANSA = 'N';
    for (c2_i99 = 0; c2_i99 < 48; c2_i99++) {
      c2_h_y[c2_i99] = 0.0;
    }

    c2_n_m_t = (ptrdiff_t)1;
    c2_n_n_t = (ptrdiff_t)48;
    c2_n_k_t = (ptrdiff_t)48;
    c2_n_lda_t = (ptrdiff_t)1;
    c2_n_ldb_t = (ptrdiff_t)48;
    c2_n_ldc_t = (ptrdiff_t)1;
    dgemm(&c2_n_TRANSA, &c2_n_TRANSB, &c2_n_m_t, &c2_n_n_t, &c2_n_k_t,
          &c2_n_alpha1, &c2_d_A[0], &c2_n_lda_t, &c2_i_b[0], &c2_n_ldb_t,
          &c2_n_beta1, &c2_h_y[0], &c2_n_ldc_t);
    for (c2_i100 = 0; c2_i100 < 1152; c2_i100++) {
      c2_a[c2_i100] = c2_b_Lambda_C[c2_i100];
    }

    for (c2_i101 = 0; c2_i101 < 24; c2_i101++) {
      c2_b_b[c2_i101] = c2_b_Phi[c2_i101];
    }

    c2_o_alpha1 = 1.0;
    c2_o_beta1 = 0.0;
    c2_o_TRANSB = 'N';
    c2_o_TRANSA = 'N';
    for (c2_i102 = 0; c2_i102 < 48; c2_i102++) {
      c2_d_y[c2_i102] = 0.0;
    }

    c2_o_m_t = (ptrdiff_t)48;
    c2_o_n_t = (ptrdiff_t)1;
    c2_o_k_t = (ptrdiff_t)24;
    c2_o_lda_t = (ptrdiff_t)48;
    c2_o_ldb_t = (ptrdiff_t)24;
    c2_o_ldc_t = (ptrdiff_t)48;
    dgemm(&c2_o_TRANSA, &c2_o_TRANSB, &c2_o_m_t, &c2_o_n_t, &c2_o_k_t,
          &c2_o_alpha1, &c2_a[0], &c2_o_lda_t, &c2_b_b[0], &c2_o_ldb_t,
          &c2_o_beta1, &c2_d_y[0], &c2_o_ldc_t);
    c2_b_a = c2_delta_p_0;
    for (c2_i103 = 0; c2_i103 < 48; c2_i103++) {
      c2_d_A[c2_i103] = c2_d_y[c2_i103];
    }

    for (c2_i104 = 0; c2_i104 < 48; c2_i104++) {
      c2_d_A[c2_i104] *= c2_b_a;
    }

    for (c2_i105 = 0; c2_i105 < 48; c2_i105++) {
      c2_f[c2_i105] = -(((c2_g_y[c2_i105] + c2_h_y[c2_i105]) + c2_d_A[c2_i105])
                        + c2_q_bar_p_hp[c2_i105]);
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 114);
    c2_i106 = 0;
    c2_i107 = 0;
    for (c2_i108 = 0; c2_i108 < 48; c2_i108++) {
      for (c2_i110 = 0; c2_i110 < 48; c2_i110++) {
        chartInstance->c2_A[c2_i110 + c2_i106] = -chartInstance->c2_L_y[c2_i110
          + c2_i107];
      }

      c2_i106 += 144;
      c2_i107 += 48;
    }

    c2_i109 = 0;
    c2_i111 = 0;
    for (c2_i112 = 0; c2_i112 < 48; c2_i112++) {
      for (c2_i114 = 0; c2_i114 < 48; c2_i114++) {
        chartInstance->c2_A[(c2_i114 + c2_i109) + 48] = chartInstance->
          c2_L_y[c2_i114 + c2_i111];
      }

      c2_i109 += 144;
      c2_i111 += 48;
    }

    c2_i113 = 0;
    c2_i115 = 0;
    for (c2_i116 = 0; c2_i116 < 48; c2_i116++) {
      for (c2_i118 = 0; c2_i118 < 24; c2_i118++) {
        chartInstance->c2_A[(c2_i118 + c2_i113) + 96] = -c2_b_Gamma[c2_i118 +
          c2_i115];
      }

      c2_i113 += 144;
      c2_i115 += 24;
    }

    c2_i117 = 0;
    c2_i119 = 0;
    for (c2_i120 = 0; c2_i120 < 48; c2_i120++) {
      for (c2_i121 = 0; c2_i121 < 24; c2_i121++) {
        chartInstance->c2_A[(c2_i121 + c2_i117) + 120] = c2_b_Gamma[c2_i121 +
          c2_i119];
      }

      c2_i117 += 144;
      c2_i119 += 24;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 115);
    for (c2_i122 = 0; c2_i122 < 48; c2_i122++) {
      c2_b[c2_i122] = c2_y1[c2_i122];
    }

    for (c2_i123 = 0; c2_i123 < 48; c2_i123++) {
      c2_b[c2_i123 + 48] = c2_y2[c2_i123];
    }

    for (c2_i124 = 0; c2_i124 < 24; c2_i124++) {
      c2_b[c2_i124 + 96] = c2_delta_p_wt_1[c2_i124];
    }

    for (c2_i125 = 0; c2_i125 < 24; c2_i125++) {
      c2_b[c2_i125 + 120] = c2_delta_p_wt_2[c2_i125];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 117);
    for (c2_i126 = 0; c2_i126 < 48; c2_i126++) {
      c2_lb[c2_i126] = -0.15000000000000002;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
    for (c2_i127 = 0; c2_i127 < 48; c2_i127++) {
      c2_ub[c2_i127] = 0.75;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
    sf_mex_assign(&c2_func, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "QP_func", 1U, 2U, 14, c2_b_emlrt_marshallOut(chartInstance,
      chartInstance->c2_R), 14, c2_c_emlrt_marshallOut(chartInstance, c2_f)),
                  false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 122);
    sf_mex_assign(&c2_options, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "optimoptions", 1U, 3U, 14, c2_d_emlrt_marshallOut(chartInstance, c2_cv0),
      14, c2_e_emlrt_marshallOut(chartInstance, c2_cv1), 14,
      c2_f_emlrt_marshallOut(chartInstance, c2_cv2)), false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 123);
    if (!c2_b0) {
      for (c2_i128 = 0; c2_i128 < 48; c2_i128++) {
        c2_dv2[c2_i128] = 0.0;
      }

      c2_b0 = true;
    }

    c2_eb_emlrt_marshallIn(chartInstance, sf_mex_call_debug
      (sfGlobalDebugInstanceStruct, "fmincon", 1U, 10U, 14, sf_mex_dup(c2_func),
       14, c2_g_emlrt_marshallOut(chartInstance, c2_dv2), 14,
       c2_h_emlrt_marshallOut(chartInstance), 14, c2_h_emlrt_marshallOut
       (chartInstance), 14, c2_h_emlrt_marshallOut(chartInstance), 14,
       c2_h_emlrt_marshallOut(chartInstance), 14, c2_g_emlrt_marshallOut
       (chartInstance, c2_lb), 14, c2_g_emlrt_marshallOut(chartInstance, c2_ub),
       14, c2_h_emlrt_marshallOut(chartInstance), 14, sf_mex_dup(c2_options)),
      "fmincon", c2_dv3);
    for (c2_i129 = 0; c2_i129 < 48; c2_i129++) {
      c2_u_hp[c2_i129] = c2_dv3[c2_i129];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, MAX_int8_T);
    c2_i130 = 0;
    for (c2_i131 = 0; c2_i131 < 24; c2_i131++) {
      c2_u_hp1[c2_i131] = c2_u_hp[c2_i130];
      c2_i130 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 128U);
    c2_i132 = 0;
    for (c2_i133 = 0; c2_i133 < 24; c2_i133++) {
      c2_u_hp2[c2_i133] = c2_u_hp[c2_i132 + 1];
      c2_i132 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 130U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "figure", 0U, 0U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 131U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "subplot", 0U, 3U, 14,
                      c2_i_emlrt_marshallOut(chartInstance, 2.0), 14,
                      c2_i_emlrt_marshallOut(chartInstance, 1.0), 14,
                      c2_i_emlrt_marshallOut(chartInstance, 1.0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 132U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_j_emlrt_marshallOut(chartInstance, c2_u_hp1));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 133U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14,
                      c2_k_emlrt_marshallOut(chartInstance, c2_cv3));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 134U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_j_emlrt_marshallOut(chartInstance, c2_u_hp2));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 135U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "grid", 0U, 1U, 14,
                      c2_k_emlrt_marshallOut(chartInstance, c2_cv3));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 136U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "subplot", 0U, 3U, 14,
                      c2_i_emlrt_marshallOut(chartInstance, 2.0), 14,
                      c2_i_emlrt_marshallOut(chartInstance, 1.0), 14,
                      c2_i_emlrt_marshallOut(chartInstance, 2.0));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 137U);
    for (c2_i134 = 0; c2_i134 < 24; c2_i134++) {
      c2_c_data[c2_i134] = c2_b_data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 4555, 18,
         MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 4555U,
          18U, c2_t_h + (real_T)c2_i134), 1, 168) - 1];
    }

    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 1U, 14,
                      c2_j_emlrt_marshallOut(chartInstance, c2_c_data));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 138U);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "grid", 0U, 1U, 14,
                      c2_k_emlrt_marshallOut(chartInstance, c2_cv3));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 140U);
    c2_b_u[0] = c2_u_hp1[0];
    c2_b_u[1] = c2_u_hp2[0];
    sf_mex_printf("%s =\\n", "u");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                      c2_l_emlrt_marshallOut(chartInstance, c2_b_u));
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 141U);
    for (c2_i135 = 0; c2_i135 < 2; c2_i135++) {
      c2_b_u_old[c2_i135] = c2_b_u[c2_i135];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 142U);
    for (c2_i136 = 0; c2_i136 < 2304; c2_i136++) {
      c2_b_R[c2_i136] = chartInstance->c2_R[c2_i136];
    }

    c2_b_DetR = c2_det(chartInstance, c2_b_R);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 143U);
    c2_b_DetR_old = c2_b_DetR;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 145U);
    for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
      c2_b_u[c2_i10] = c2_b_u_old[c2_i10];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 146U);
    c2_b_DetR = c2_b_DetR_old;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -146);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c2_func);
  sf_mex_destroy(&c2_options);
  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    (*chartInstance->c2_u)[c2_i14] = c2_b_u[c2_i14];
  }

  *chartInstance->c2_DetR = c2_b_DetR;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_simulering_vinkel
  (SFc2_simulering_vinkelInstanceStruct *chartInstance)
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
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_DetR, const char_T *c2_identifier)
{
  real_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_DetR),
    &c2_thisId);
  sf_mex_destroy(&c2_b_DetR);
  return c2_b_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_DetR;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_b_DetR = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_DetR),
    &c2_thisId);
  sf_mex_destroy(&c2_b_DetR);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i137;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[2];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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

static void c2_c_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const char_T *c2_identifier, real_T
  c2_b_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b_u);
}

static void c2_d_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[2])
{
  real_T c2_dv4[2];
  int32_T c2_i138;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv4, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i138 = 0; c2_i138 < 2; c2_i138++) {
    c2_b_y[c2_i138] = c2_dv4[c2_i138];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[2];
  int32_T c2_i139;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_b_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b_u);
  for (c2_i139 = 0; c2_i139 < 2; c2_i139++) {
    (*(real_T (*)[2])c2_outData)[c2_i139] = c2_b_y[c2_i139];
  }

  sf_mex_destroy(&c2_mxArrayInData);
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_Theta = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Theta), &c2_thisId, c2_b_y);
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_Psi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Psi), &c2_thisId, c2_b_y);
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_c_Pi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_Pi), &c2_thisId, c2_b_y);
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_Phi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Phi), &c2_thisId, c2_b_y);
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_data), &c2_thisId, c2_b_y);
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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
  const mxArray *c2_fmincon;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[48];
  int32_T c2_i163;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_fmincon = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_fmincon), &c2_thisId,
    c2_b_y);
  sf_mex_destroy(&c2_fmincon);
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
  real_T c2_b_u[144];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i164 = 0; c2_i164 < 144; c2_i164++) {
    c2_b_u[c2_i164] = (*(real_T (*)[144])c2_inData)[c2_i164];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 144),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[144])
{
  real_T c2_dv5[144];
  int32_T c2_i165;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv5, 1, 0, 0U, 1, 0U, 1, 144);
  for (c2_i165 = 0; c2_i165 < 144; c2_i165++) {
    c2_b_y[c2_i165] = c2_dv5[c2_i165];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[144];
  int32_T c2_i166;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_b = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b);
  for (c2_i166 = 0; c2_i166 < 144; c2_i166++) {
    (*(real_T (*)[144])c2_outData)[c2_i166] = c2_b_y[c2_i166];
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
  real_T c2_b_u[6912];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i167 = 0;
  for (c2_i168 = 0; c2_i168 < 48; c2_i168++) {
    for (c2_i169 = 0; c2_i169 < 144; c2_i169++) {
      c2_b_u[c2_i169 + c2_i167] = (*(real_T (*)[6912])c2_inData)[c2_i169 +
        c2_i167];
    }

    c2_i167 += 144;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 144, 48),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[6912])
{
  real_T c2_dv6[6912];
  int32_T c2_i170;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 144,
                48);
  for (c2_i170 = 0; c2_i170 < 6912; c2_i170++) {
    c2_b_y[c2_i170] = c2_dv6[c2_i170];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_A;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[6912];
  int32_T c2_i171;
  int32_T c2_i172;
  int32_T c2_i173;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_b_A = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_A), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_b_A);
  c2_i171 = 0;
  for (c2_i172 = 0; c2_i172 < 48; c2_i172++) {
    for (c2_i173 = 0; c2_i173 < 144; c2_i173++) {
      (*(real_T (*)[6912])c2_outData)[c2_i173 + c2_i171] = c2_b_y[c2_i173 +
        c2_i171];
    }

    c2_i171 += 144;
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
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

static void c2_g_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[48])
{
  real_T c2_dv7[48];
  int32_T c2_i175;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                48);
  for (c2_i175 = 0; c2_i175 < 48; c2_i175++) {
    c2_b_y[c2_i175] = c2_dv7[c2_i175];
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
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_f = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_f), &c2_thisId, c2_b_y);
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
  int32_T c2_i177;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u[24];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i177 = 0; c2_i177 < 24; c2_i177++) {
    c2_b_u[c2_i177] = (*(real_T (*)[24])c2_inData)[c2_i177];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[24])
{
  real_T c2_dv8[24];
  int32_T c2_i178;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv8, 1, 0, 0U, 1, 0U, 2, 1,
                24);
  for (c2_i178 = 0; c2_i178 < 24; c2_i178++) {
    c2_b_y[c2_i178] = c2_dv8[c2_i178];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_t_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[24];
  int32_T c2_i179;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_t_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_t_1), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_t_1);
  for (c2_i179 = 0; c2_i179 < 24; c2_i179++) {
    (*(real_T (*)[24])c2_outData)[c2_i179] = c2_b_y[c2_i179];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i180;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[24];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_shjtd7pXyPLVVdClb9GNBeB *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i180 = 0; c2_i180 < 24; c2_i180++) {
    c2_c_u[c2_i180] = c2_b_u.constant_dist[c2_i180];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "constant_dist", "constant_dist", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_shjtd7pXyPLVVdClb9GNBeB *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_spEGmxEyHM6EoZZcXmG7jeB c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i181;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[1152];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_spEGmxEyHM6EoZZcXmG7jeB *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i181 = 0; c2_i181 < 1152; c2_i181++) {
    c2_c_u[c2_i181] = c2_b_u.Theta[c2_i181];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 48, 24),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Theta", "Theta", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_spEGmxEyHM6EoZZcXmG7jeB c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_spEGmxEyHM6EoZZcXmG7jeB *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sVXPIQCYRVtgDunkSIgrZND c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i182;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[1152];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sVXPIQCYRVtgDunkSIgrZND *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i182 = 0; c2_i182 < 1152; c2_i182++) {
    c2_c_u[c2_i182] = c2_b_u.Psi[c2_i182];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 24, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Psi", "Psi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sVXPIQCYRVtgDunkSIgrZND c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sVXPIQCYRVtgDunkSIgrZND *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sjdLzyTh14ULkIImcl6xwW c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i183;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[2304];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sjdLzyTh14ULkIImcl6xwW *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i183 = 0; c2_i183 < 2304; c2_i183++) {
    c2_c_u[c2_i183] = c2_b_u.Pi[c2_i183];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Pi", "Pi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sjdLzyTh14ULkIImcl6xwW c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sjdLzyTh14ULkIImcl6xwW *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sXRXp7aMGjI8fA8IXQDoqtG c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i184;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[24];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sXRXp7aMGjI8fA8IXQDoqtG *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i184 = 0; c2_i184 < 24; c2_i184++) {
    c2_c_u[c2_i184] = c2_b_u.Phi[c2_i184];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Phi", "Phi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sXRXp7aMGjI8fA8IXQDoqtG c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sXRXp7aMGjI8fA8IXQDoqtG *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sHr555XKyGoUpad7tsiNQiE c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i185;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[2304];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sHr555XKyGoUpad7tsiNQiE *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i185 = 0; c2_i185 < 2304; c2_i185++) {
    c2_c_u[c2_i185] = c2_b_u.Omega[c2_i185];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Omega", "Omega", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sHr555XKyGoUpad7tsiNQiE c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sHr555XKyGoUpad7tsiNQiE *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sDEl41izlL3fNQfEgJJ5XBH c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i186;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[1152];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sDEl41izlL3fNQfEgJJ5XBH *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i186 = 0; c2_i186 < 1152; c2_i186++) {
    c2_c_u[c2_i186] = c2_b_u.Gamma[c2_i186];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 24, 48),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "Gamma", "Gamma", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sDEl41izlL3fNQfEgJJ5XBH c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sDEl41izlL3fNQfEgJJ5XBH *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i187;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u[168];
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sAv0WliXUXwSlTp2NM3P4jE *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i187 = 0; c2_i187 < 168; c2_i187++) {
    c2_c_u[c2_i187] = c2_b_u.data[c2_i187];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 168),
                false);
  sf_mex_addfield(c2_b_y, c2_c_y, "data", "data", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sAv0WliXUXwSlTp2NM3P4jE c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_load);
  *(c2_sAv0WliXUXwSlTp2NM3P4jE *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_simulering_vinkel_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static real_T c2_det(SFc2_simulering_vinkelInstanceStruct *chartInstance, real_T
                     c2_b_x[2304])
{
  real_T c2_b_y;
  int32_T c2_i188;
  real_T c2_c_x[2304];
  int32_T c2_ipiv[48];
  int32_T c2_k;
  boolean_T c2_isodd;
  real_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_a;
  real_T c2_b;
  int32_T c2_b_a;
  real_T c2_b_b;
  int32_T c2_idx;
  real_T c2_flt;
  boolean_T c2_p;
  for (c2_i188 = 0; c2_i188 < 2304; c2_i188++) {
    c2_c_x[c2_i188] = c2_b_x[c2_i188];
  }

  c2_b_xgetrf(chartInstance, c2_c_x, c2_ipiv);
  c2_b_y = c2_c_x[0];
  for (c2_k = 0; c2_k < 47; c2_k++) {
    c2_b_k = 2.0 + (real_T)c2_k;
    c2_b_y *= c2_c_x[((int32_T)c2_b_k + 48 * ((int32_T)c2_b_k - 1)) - 1];
  }

  c2_isodd = false;
  for (c2_c_k = 0; c2_c_k < 47; c2_c_k++) {
    c2_b_k = 1.0 + (real_T)c2_c_k;
    c2_a = c2_ipiv[(int32_T)c2_b_k - 1];
    c2_b = c2_b_k;
    c2_b_a = c2_a;
    c2_b_b = c2_b;
    c2_idx = c2_b_a;
    c2_flt = c2_b_b;
    c2_p = ((real_T)c2_idx > c2_flt);
    if (c2_p) {
      c2_isodd = !c2_isodd;
    }
  }

  if (c2_isodd) {
    c2_b_y = -c2_b_y;
  }

  return c2_b_y;
}

static void c2_xgetrf(SFc2_simulering_vinkelInstanceStruct *chartInstance,
                      real_T c2_b_A[2304], real_T c2_c_A[2304], int32_T c2_ipiv
                      [48])
{
  int32_T c2_i189;
  for (c2_i189 = 0; c2_i189 < 2304; c2_i189++) {
    c2_c_A[c2_i189] = c2_b_A[c2_i189];
  }

  c2_b_xgetrf(chartInstance, c2_c_A, c2_ipiv);
}

static void c2_error(SFc2_simulering_vinkelInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv4[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_b_y));
}

static void c2_b_error(SFc2_simulering_vinkelInstanceStruct *chartInstance,
  int32_T c2_varargin_2)
{
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv5[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c2_c_y = NULL;
  static char_T c2_cv6[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y));
}

static const mxArray *c2_emlrt_marshallOut(SFc2_simulering_vinkelInstanceStruct *
  chartInstance, const char * c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_b_u)), false);
  return c2_b_y;
}

static void c2_i_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_j_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sAv0WliXUXwSlTp2NM3P4jE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "data" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "data";
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "data",
    "data", 0)), &c2_thisId, c2_b_y->data);
  sf_mex_destroy(&c2_b_u);
}

static void c2_k_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[168])
{
  real_T c2_dv9[168];
  int32_T c2_i190;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv9, 1, 0, 0U, 1, 0U, 1, 168);
  for (c2_i190 = 0; c2_i190 < 168; c2_i190++) {
    c2_b_y[c2_i190] = c2_dv9[c2_i190];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_l_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_m_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sDEl41izlL3fNQfEgJJ5XBH *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Gamma" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Gamma";
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Gamma", "Gamma", 0)), &c2_thisId, c2_b_y->Gamma);
  sf_mex_destroy(&c2_b_u);
}

static void c2_n_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[1152])
{
  real_T c2_dv10[1152];
  int32_T c2_i191;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 24,
                48);
  for (c2_i191 = 0; c2_i191 < 1152; c2_i191++) {
    c2_b_y[c2_i191] = c2_dv10[c2_i191];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_o_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_p_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sHr555XKyGoUpad7tsiNQiE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Omega" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Omega";
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Omega", "Omega", 0)), &c2_thisId, c2_b_y->Omega);
  sf_mex_destroy(&c2_b_u);
}

static void c2_q_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[2304])
{
  real_T c2_dv11[2304];
  int32_T c2_i192;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 48,
                48);
  for (c2_i192 = 0; c2_i192 < 2304; c2_i192++) {
    c2_b_y[c2_i192] = c2_dv11[c2_i192];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_r_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_s_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sXRXp7aMGjI8fA8IXQDoqtG *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Phi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Phi";
  c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Phi",
    "Phi", 0)), &c2_thisId, c2_b_y->Phi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_t_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[24])
{
  real_T c2_dv12[24];
  int32_T c2_i193;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 24);
  for (c2_i193 = 0; c2_i193 < 24; c2_i193++) {
    c2_b_y[c2_i193] = c2_dv12[c2_i193];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_u_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sjdLzyTh14ULkIImcl6xwW *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_v_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sjdLzyTh14ULkIImcl6xwW *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Pi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Pi";
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Pi",
    "Pi", 0)), &c2_thisId, c2_b_y->Pi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_w_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_x_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sVXPIQCYRVtgDunkSIgrZND *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Psi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Psi";
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Psi",
    "Psi", 0)), &c2_thisId, c2_b_y->Psi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_y_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_ab_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_spEGmxEyHM6EoZZcXmG7jeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Theta" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Theta";
  c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Theta", "Theta", 0)), &c2_thisId, c2_b_y->Theta);
  sf_mex_destroy(&c2_b_u);
}

static void c2_bb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[1152])
{
  real_T c2_dv13[1152];
  int32_T c2_i194;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv13, 1, 0, 0U, 1, 0U, 2, 48,
                24);
  for (c2_i194 = 0; c2_i194 < 1152; c2_i194++) {
    c2_b_y[c2_i194] = c2_dv13[c2_i194];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_cb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_load);
}

static void c2_db_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "constant_dist" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "constant_dist";
  c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "constant_dist", "constant_dist", 0)), &c2_thisId, c2_b_y->constant_dist);
  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[2304])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 48, 48),
                false);
  return c2_b_y;
}

static const mxArray *c2_c_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[48])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 48),
                false);
  return c2_b_y;
}

static const mxArray *c2_d_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[7])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  return c2_b_y;
}

static const mxArray *c2_e_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[9])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  return c2_b_y;
}

static const mxArray *c2_f_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[14])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  return c2_b_y;
}

static const mxArray *c2_g_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[48])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 48), false);
  return c2_b_y;
}

static const mxArray *c2_h_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  return c2_b_y;
}

static void c2_eb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_fmincon, const char_T *c2_identifier, real_T
  c2_b_y[48])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_fmincon), &c2_thisId,
    c2_b_y);
  sf_mex_destroy(&c2_fmincon);
}

static void c2_fb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_b_y[48])
{
  real_T c2_dv14[48];
  int32_T c2_i195;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv14, 1, 0, 0U, 1, 0U, 1, 48);
  for (c2_i195 = 0; c2_i195 < 48; c2_i195++) {
    c2_b_y[c2_i195] = c2_dv14[c2_i195];
  }

  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_i_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  return c2_b_y;
}

static const mxArray *c2_j_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[24])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 24), false);
  return c2_b_y;
}

static const mxArray *c2_k_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const char_T c2_b_u[2])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  return c2_b_y;
}

static const mxArray *c2_l_emlrt_marshallOut
  (SFc2_simulering_vinkelInstanceStruct *chartInstance, const real_T c2_b_u[2])
{
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  return c2_b_y;
}

static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_gb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_b_y;
  int32_T c2_i196;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i196, 1, 6, 0U, 0, 0U, 0);
  c2_b_y = c2_i196;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_b_y;
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_hb_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_simulering_vinkel, const
  char_T *c2_identifier)
{
  uint8_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_ib_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_simulering_vinkel), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_simulering_vinkel);
  return c2_b_y;
}

static uint8_T c2_ib_emlrt_marshallIn(SFc2_simulering_vinkelInstanceStruct
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

static void c2_b_xgetrf(SFc2_simulering_vinkelInstanceStruct *chartInstance,
  real_T c2_b_A[2304], int32_T c2_ipiv[48])
{
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_info_t;
  ptrdiff_t c2_ipiv_t[48];
  int32_T c2_info;
  int32_T c2_b_info;
  int32_T c2_c_info;
  boolean_T c2_p;
  int32_T c2_k;
  c2_m_t = (ptrdiff_t)48;
  c2_n_t = (ptrdiff_t)48;
  c2_lda_t = (ptrdiff_t)48;
  c2_info_t = LAPACKE_dgetrf_work(102, c2_m_t, c2_n_t, &c2_b_A[0], c2_lda_t,
    &c2_ipiv_t[0]);
  c2_info = (int32_T)c2_info_t;
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_p = (c2_c_info < 0);
  if (c2_p) {
    if (c2_b_info == -1010) {
      c2_error(chartInstance);
    } else {
      c2_b_error(chartInstance, c2_b_info);
    }
  }

  for (c2_k = 0; c2_k < 48; c2_k++) {
    c2_ipiv[c2_k] = (int32_T)c2_ipiv_t[c2_k];
  }
}

static void init_dsm_address_info(SFc2_simulering_vinkelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_simulering_vinkelInstanceStruct
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
  chartInstance->c2_DetR = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_DetR_old = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
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

void sf_c2_simulering_vinkel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(707660875U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3553793265U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(794438997U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2720664373U);
}

mxArray* sf_c2_simulering_vinkel_get_post_codegen_info(void);
mxArray *sf_c2_simulering_vinkel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9LyW9eVsQLauYJJlW8ZZC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_simulering_vinkel_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_simulering_vinkel_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c2_simulering_vinkel_jit_fallback_info(void)
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

mxArray *sf_c2_simulering_vinkel_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_simulering_vinkel_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_simulering_vinkel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[15],T\"DetR\",},{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c2_simulering_vinkel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_simulering_vinkel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simulering_vinkelInstanceStruct *chartInstance =
      (SFc2_simulering_vinkelInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _simulering_vinkelMachineNumber_,
           2,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_simulering_vinkelMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_simulering_vinkelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _simulering_vinkelMachineNumber_,
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
          _SFD_SET_DATA_PROPS(6,1,1,0,"DetR_old");
          _SFD_SET_DATA_PROPS(7,2,0,1,"u");
          _SFD_SET_DATA_PROPS(8,2,0,1,"DetR");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4737);
        _SFD_CV_INIT_EML_IF(0,1,0,267,282,4687,4732);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,270,282,-1,1);

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
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _simulering_vinkelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simulering_vinkelInstanceStruct *chartInstance =
      (SFc2_simulering_vinkelInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_b_Lambda_A);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_b_Lambda_B);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_Lambda_C);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_t_clock);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_x);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_u_old);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c2_DetR);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_DetR_old);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "spiB7gYCm9QlECdWzPpkGAE";
}

static void sf_opaque_initialize_c2_simulering_vinkel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar);
  initialize_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_simulering_vinkel(void *chartInstanceVar)
{
  enable_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_simulering_vinkel(void *chartInstanceVar)
{
  disable_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_simulering_vinkel(void *chartInstanceVar)
{
  sf_gateway_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_simulering_vinkel(SimStruct* S)
{
  return get_sim_state_c2_simulering_vinkel
    ((SFc2_simulering_vinkelInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_simulering_vinkel(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_simulering_vinkel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_simulering_vinkelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_simulering_vinkel_optimization_info();
    }

    finalize_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_simulering_vinkel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_simulering_vinkel((SFc2_simulering_vinkelInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_simulering_vinkel(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simulering_vinkel_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
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
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(488663403U));
  ssSetChecksum1(S,(3245128937U));
  ssSetChecksum2(S,(2426111364U));
  ssSetChecksum3(S,(1624092414U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_simulering_vinkel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_simulering_vinkel(SimStruct *S)
{
  SFc2_simulering_vinkelInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkelInstanceStruct *)utMalloc(sizeof
    (SFc2_simulering_vinkelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_simulering_vinkelInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_simulering_vinkel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_simulering_vinkel;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_simulering_vinkel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_simulering_vinkel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_simulering_vinkel;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_simulering_vinkel;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_simulering_vinkel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_simulering_vinkel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_simulering_vinkel;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_simulering_vinkel;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_simulering_vinkel;
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
  mdl_start_c2_simulering_vinkel(chartInstance);
}

void c2_simulering_vinkel_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_simulering_vinkel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_simulering_vinkel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_simulering_vinkel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_simulering_vinkel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
