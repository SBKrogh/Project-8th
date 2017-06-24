/* Include files */

#include "simulering_vinkel_2016b_sfun.h"
#include "c2_simulering_vinkel_2016b.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simulering_vinkel_2016b_sfun_debug_macros.h"
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
static const char * c2_debug_family_names[51] = { "Hp", "Ts", "t_h", "t_h_2",
  "u_hp", "u_hp1", "u_hp2", "Gamma", "Omega", "Phi", "Pi", "Psi", "Theta",
  "Q_bar", "constant_dist", "Data_OD", "delta_p_0", "d_hp", "U_bar", "U_bar_hp",
  "y_low", "y_high", "y_bar", "y1", "y2", "L_y", "x_low", "x_high", "x_bar",
  "delta_p_wt_1", "delta_p_wt_2", "u_low", "u_high", "R", "R1", "R2", "f", "A",
  "b", "lb", "ub", "opts", "nargin", "nargout", "Lambda_A", "Lambda_B",
  "Lambda_C", "t_clock", "x", "u_old", "u" };

/* Function Declarations */
static void initialize_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void initialize_params_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void enable_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void disable_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void set_sim_state_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void sf_gateway_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void mdl_start_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void c2_chartstep_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void initSimStructsc2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const char_T *c2_identifier, real_T
  c2_y[2]);
static void c2_b_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
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
static void c2_d_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[138]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6348]);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[46]);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
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
static const mxArray *c2_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char
   * c2_b_u);
static void c2_g_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sIQ3pmxd46lhLR0Qo0qcBsF *c2_y);
static void c2_h_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sIQ3pmxd46lhLR0Qo0qcBsF *c2_y);
static void c2_i_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[1058]);
static void c2_j_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_s454HJ9Zz3PEsaEb4npqG3E *c2_y);
static void c2_k_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_s454HJ9Zz3PEsaEb4npqG3E *c2_y);
static void c2_l_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2116]);
static void c2_m_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sGkAry86wpEobQ8qQO6mmvC *c2_y);
static void c2_n_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sGkAry86wpEobQ8qQO6mmvC *c2_y);
static void c2_o_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[23]);
static void c2_p_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sBYPrnfGIO0jxBCm3vjPz9G *c2_y);
static void c2_q_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sBYPrnfGIO0jxBCm3vjPz9G *c2_y);
static void c2_r_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sYtaFjV9hT44BZtqxYLBdPC *c2_y);
static void c2_s_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sYtaFjV9hT44BZtqxYLBdPC *c2_y);
static void c2_t_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_stkjSRV8bNurnAOIfmNzFv *c2_y);
static void c2_u_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_stkjSRV8bNurnAOIfmNzFv *c2_y);
static void c2_v_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[1058]);
static void c2_w_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sqoxuV7hFFxgljYD64O2e8D *c2_y);
static void c2_x_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sqoxuV7hFFxgljYD64O2e8D *c2_y);
static void c2_y_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[46]);
static void c2_ab_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_y);
static void c2_bb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_y);
static void c2_cb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24]);
static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[8]);
static const mxArray *c2_c_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[9]);
static const mxArray *c2_d_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[21]);
static const mxArray *c2_e_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[7]);
static const mxArray *c2_f_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[4]);
static const mxArray *c2_g_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[2116]);
static const mxArray *c2_h_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[46]);
static const mxArray *c2_i_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[6348]);
static const mxArray *c2_j_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[138]);
static const mxArray *c2_k_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance);
static const mxArray *c2_l_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[46]);
static void c2_db_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_quadprog, const char_T *c2_identifier,
  real_T c2_y[46]);
static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_eb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_fb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_simulering_vinkel_2016b,
  const char_T *c2_identifier);
static uint8_T c2_gb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_simulering_vinkel_2016bInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_simulering_vinkel_2016b(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_simulering_vinkel_2016b = 0U;
}

static void initialize_params_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_u, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_simulering_vinkel_2016b;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const mxArray
   *c2_st)
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

  chartInstance->c2_is_active_c2_simulering_vinkel_2016b =
    c2_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c2_simulering_vinkel_2016b", c2_b_u, 1)),
    "is_active_c2_simulering_vinkel_2016b");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_simulering_vinkel_2016b(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
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
  for (c2_i2 = 0; c2_i2 < 1058; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_Lambda_C)[c2_i2], 2U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i3 = 0; c2_i3 < 2116; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_Lambda_B)[c2_i3], 1U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i4 = 0; c2_i4 < 2116; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_Lambda_A)[c2_i4], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_simulering_vinkel_2016b(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_simulering_vinkel_2016bMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u)[c2_i5], 6U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void mdl_start_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_b_t_clock;
  real_T c2_b_Lambda_C[1058];
  real_T c2_b_x;
  int32_T c2_i9;
  uint32_T c2_debug_family_var_map[51];
  real_T c2_b_u_old[2];
  real_T c2_Hp;
  real_T c2_Ts;
  real_T c2_t_h;
  real_T c2_t_h_2;
  real_T c2_u_hp[46];
  real_T c2_u_hp1[23];
  real_T c2_u_hp2[23];
  c2_sIQ3pmxd46lhLR0Qo0qcBsF c2_Gamma;
  c2_sGkAry86wpEobQ8qQO6mmvC c2_Phi;
  c2_sYtaFjV9hT44BZtqxYLBdPC c2_Psi;
  c2_stkjSRV8bNurnAOIfmNzFv c2_Theta;
  c2_sqoxuV7hFFxgljYD64O2e8D c2_Q_bar;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_constant_dist;
  real_T c2_Data_OD[24];
  real_T c2_delta_p_0;
  real_T c2_d_hp[46];
  real_T c2_U_bar;
  real_T c2_U_bar_hp[46];
  real_T c2_y_low[46];
  real_T c2_y_high[46];
  real_T c2_y_bar[46];
  real_T c2_y1[46];
  real_T c2_y2[46];
  real_T c2_x_low[23];
  real_T c2_x_high[23];
  real_T c2_x_bar[23];
  real_T c2_delta_p_wt_1[23];
  real_T c2_delta_p_wt_2[23];
  real_T c2_u_low[46];
  real_T c2_u_high;
  real_T c2_f[46];
  real_T c2_b[138];
  real_T c2_lb[46];
  real_T c2_ub[46];
  const mxArray *c2_opts = NULL;
  real_T c2_b_Gamma[1058];
  real_T c2_b_Phi[23];
  real_T c2_b_Psi[1058];
  real_T c2_b_Theta[1058];
  real_T c2_b_Q_bar[46];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_u[2];
  real_T c2_b_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_c_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_y;
  real_T c2_i_x;
  real_T c2_j_x;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  c2_sIQ3pmxd46lhLR0Qo0qcBsF c2_r0;
  int32_T c2_i15;
  c2_s454HJ9Zz3PEsaEb4npqG3E c2_r1;
  int32_T c2_i16;
  c2_sGkAry86wpEobQ8qQO6mmvC c2_r2;
  int32_T c2_i17;
  c2_sBYPrnfGIO0jxBCm3vjPz9G c2_r3;
  int32_T c2_i18;
  c2_sYtaFjV9hT44BZtqxYLBdPC c2_r4;
  int32_T c2_i19;
  c2_stkjSRV8bNurnAOIfmNzFv c2_r5;
  int32_T c2_i20;
  c2_sqoxuV7hFFxgljYD64O2e8D c2_r6;
  int32_T c2_i21;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_r7;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  static real_T c2_dv1[46] = { 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562,
    0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562,
    0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991, 0.1562, 0.0991,
    0.1562, 0.0991, 0.1562, 0.0991 };

  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_a[1058];
  real_T c2_alpha1;
  real_T c2_b_b[23];
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  int32_T c2_i29;
  ptrdiff_t c2_m_t;
  real_T c2_c_y[46];
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  real_T c2_c_b;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  real_T c2_b_alpha1;
  real_T c2_d_b[1058];
  real_T c2_b_beta1;
  char_T c2_b_TRANSB;
  char_T c2_b_TRANSA;
  int32_T c2_i33;
  ptrdiff_t c2_b_m_t;
  real_T c2_d_y[2116];
  ptrdiff_t c2_b_n_t;
  ptrdiff_t c2_b_k_t;
  ptrdiff_t c2_b_lda_t;
  ptrdiff_t c2_b_ldb_t;
  ptrdiff_t c2_b_ldc_t;
  int32_T c2_i34;
  int32_T c2_i35;
  real_T c2_c_alpha1;
  real_T c2_e_b[46];
  real_T c2_c_beta1;
  char_T c2_c_TRANSB;
  char_T c2_c_TRANSA;
  int32_T c2_i36;
  ptrdiff_t c2_c_m_t;
  real_T c2_e_y[46];
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
  real_T c2_f_b;
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
  real_T c2_g_b;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  real_T c2_h_alpha1;
  real_T c2_h_beta1;
  char_T c2_h_TRANSB;
  char_T c2_h_TRANSA;
  int32_T c2_i60;
  ptrdiff_t c2_h_m_t;
  real_T c2_f_y[23];
  ptrdiff_t c2_h_n_t;
  ptrdiff_t c2_h_k_t;
  ptrdiff_t c2_h_lda_t;
  ptrdiff_t c2_h_ldb_t;
  ptrdiff_t c2_h_ldc_t;
  int32_T c2_i61;
  int32_T c2_i62;
  real_T c2_h_b;
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
  static real_T c2_dv2[46] = { -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17,
    -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15,
    -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17,
    -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15, -0.17, -0.15,
    -0.17, -0.15, -0.17, -0.15, -0.17, -0.15 };

  int32_T c2_i69;
  int32_T c2_i70;
  real_T c2_j_alpha1;
  real_T c2_j_beta1;
  char_T c2_j_TRANSB;
  char_T c2_j_TRANSA;
  int32_T c2_i71;
  ptrdiff_t c2_j_m_t;
  ptrdiff_t c2_j_n_t;
  ptrdiff_t c2_j_k_t;
  ptrdiff_t c2_j_lda_t;
  ptrdiff_t c2_j_ldb_t;
  ptrdiff_t c2_j_ldc_t;
  int32_T c2_i72;
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
  real_T c2_k_alpha1;
  real_T c2_k_beta1;
  char_T c2_k_TRANSB;
  char_T c2_k_TRANSA;
  int32_T c2_i86;
  ptrdiff_t c2_k_m_t;
  ptrdiff_t c2_k_n_t;
  ptrdiff_t c2_k_k_t;
  ptrdiff_t c2_k_lda_t;
  ptrdiff_t c2_k_ldb_t;
  ptrdiff_t c2_k_ldc_t;
  int32_T c2_i87;
  real_T c2_l_alpha1;
  int32_T c2_i88;
  real_T c2_l_beta1;
  real_T c2_d_A[46];
  char_T c2_l_TRANSB;
  char_T c2_l_TRANSA;
  int32_T c2_i89;
  ptrdiff_t c2_l_m_t;
  real_T c2_g_y[46];
  ptrdiff_t c2_l_n_t;
  ptrdiff_t c2_l_k_t;
  ptrdiff_t c2_l_lda_t;
  ptrdiff_t c2_l_ldb_t;
  ptrdiff_t c2_l_ldc_t;
  int32_T c2_i90;
  int32_T c2_i91;
  real_T c2_m_alpha1;
  real_T c2_m_beta1;
  char_T c2_m_TRANSB;
  char_T c2_m_TRANSA;
  int32_T c2_i92;
  ptrdiff_t c2_m_m_t;
  ptrdiff_t c2_m_n_t;
  ptrdiff_t c2_m_k_t;
  ptrdiff_t c2_m_lda_t;
  ptrdiff_t c2_m_ldb_t;
  ptrdiff_t c2_m_ldc_t;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  real_T c2_n_alpha1;
  int32_T c2_i96;
  real_T c2_n_beta1;
  int32_T c2_i97;
  char_T c2_n_TRANSB;
  char_T c2_n_TRANSA;
  int32_T c2_i98;
  real_T c2_i_b[2116];
  ptrdiff_t c2_n_m_t;
  real_T c2_h_y[46];
  ptrdiff_t c2_n_n_t;
  ptrdiff_t c2_n_k_t;
  ptrdiff_t c2_n_lda_t;
  ptrdiff_t c2_n_ldb_t;
  ptrdiff_t c2_n_ldc_t;
  int32_T c2_i99;
  int32_T c2_i100;
  real_T c2_o_alpha1;
  real_T c2_o_beta1;
  char_T c2_o_TRANSB;
  char_T c2_o_TRANSA;
  int32_T c2_i101;
  ptrdiff_t c2_o_m_t;
  ptrdiff_t c2_o_n_t;
  ptrdiff_t c2_o_k_t;
  ptrdiff_t c2_o_lda_t;
  ptrdiff_t c2_o_ldb_t;
  ptrdiff_t c2_o_ldc_t;
  real_T c2_b_a;
  int32_T c2_i102;
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
  static char_T c2_cv0[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  static char_T c2_cv1[9] = { 'A', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm' };

  static char_T c2_cv2[21] = { 'i', 'n', 't', 'e', 'r', 'i', 'o', 'r', '-', 'p',
    'o', 'i', 'n', 't', '-', 'c', 'o', 'n', 'v', 'e', 'x' };

  static char_T c2_cv3[7] = { 'D', 'i', 's', 'p', 'l', 'a', 'y' };

  static char_T c2_cv4[4] = { 'i', 't', 'e', 'r' };

  int32_T c2_i127;
  real_T c2_b_lb[46];
  real_T c2_dv3[46];
  int32_T c2_i128;
  int32_T c2_i129;
  int32_T c2_i130;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_t_clock;
  c2_b_hoistedGlobal = *chartInstance->c2_x;
  for (c2_i6 = 0; c2_i6 < 2116; c2_i6++) {
    chartInstance->c2_Lambda_A[c2_i6] = (*chartInstance->c2_b_Lambda_A)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 2116; c2_i7++) {
    chartInstance->c2_Lambda_B[c2_i7] = (*chartInstance->c2_b_Lambda_B)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 1058; c2_i8++) {
    c2_b_Lambda_C[c2_i8] = (*chartInstance->c2_Lambda_C)[c2_i8];
  }

  c2_b_t_clock = c2_hoistedGlobal;
  c2_b_x = c2_b_hoistedGlobal;
  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    c2_b_u_old[c2_i9] = (*chartInstance->c2_u_old)[c2_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 51U, 58U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Hp, 0U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Ts, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_t_h, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_t_h_2, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp, 4U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp1, 5U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_hp2, 6U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Q_bar, MAX_uint32_T,
    c2_n_sf_marshallOut, c2_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_constant_dist, 14U,
    c2_m_sf_marshallOut, c2_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Data_OD, 15U, c2_l_sf_marshallOut,
    c2_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_delta_p_0, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d_hp, 17U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_U_bar, 18U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_U_bar_hp, 19U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_low, 20U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_high, 21U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y_bar, 22U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y1, 23U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y2, 24U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_L_y, 25U,
    c2_d_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_low, 26U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_high, 27U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x_bar, 28U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_delta_p_wt_1, 29U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_delta_p_wt_2, 30U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_low, 31U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_u_high, 32U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R, 33U,
    c2_d_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R1, 34U,
    c2_d_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_R2, 35U,
    c2_d_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_f, 36U, c2_k_sf_marshallOut,
    c2_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_A, 37U,
    c2_j_sf_marshallOut, c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b, 38U, c2_i_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_lb, 39U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_ub, 40U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_opts, 41U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Gamma, MAX_uint32_T,
    c2_f_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_b_Omega, MAX_uint32_T,
    c2_d_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Phi, MAX_uint32_T,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_b_Pi, MAX_uint32_T,
    c2_d_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Psi, MAX_uint32_T,
    c2_f_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Theta, MAX_uint32_T,
    c2_c_sf_marshallOut, c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_Q_bar, MAX_uint32_T,
    c2_e_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 42U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 43U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Lambda_A, 44U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Lambda_B, 45U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_Lambda_C, 46U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_t_clock, 47U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_x, 48U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u_old, 49U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_u, 50U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_Hp = 23.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_Ts = 89.33;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_b_A = c2_b_t_clock;
  c2_c_x = c2_b_A;
  c2_d_x = c2_c_x;
  c2_y = c2_d_x / 3600.0;
  c2_e_x = c2_y;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarFloor(c2_f_x);
  c2_t_h = 1.0 + c2_f_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_c_A = c2_b_t_clock - c2_Ts;
  c2_g_x = c2_c_A;
  c2_h_x = c2_g_x;
  c2_b_y = c2_h_x / 3600.0;
  c2_i_x = c2_b_y;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarFloor(c2_j_x);
  c2_t_h_2 = 1.0 + c2_j_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_t_h, c2_t_h_2, -1, 1U,
        c2_t_h != c2_t_h_2))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    for (c2_i11 = 0; c2_i11 < 46; c2_i11++) {
      c2_u_hp[c2_i11] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    for (c2_i12 = 0; c2_i12 < 23; c2_i12++) {
      c2_u_hp1[c2_i12] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    for (c2_i14 = 0; c2_i14 < 23; c2_i14++) {
      c2_u_hp2[c2_i14] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    _SFD_SYMBOL_SWITCH(7U, 7U);
    c2_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Gamma.mat")), "load", &c2_r0);
    c2_Gamma = c2_r0;
    _SFD_SYMBOL_SWITCH(7U, 7U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    for (c2_i15 = 0; c2_i15 < 1058; c2_i15++) {
      c2_b_Gamma[c2_i15] = c2_Gamma.Gamma[c2_i15];
    }

    _SFD_SYMBOL_SWITCH(7U, 42U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    _SFD_SYMBOL_SWITCH(8U, 8U);
    c2_j_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Omega.mat")), "load", &c2_r1);
    chartInstance->c2_Omega = c2_r1;
    _SFD_SYMBOL_SWITCH(8U, 8U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
    for (c2_i16 = 0; c2_i16 < 2116; c2_i16++) {
      chartInstance->c2_b_Omega[c2_i16] = chartInstance->c2_Omega.Omega[c2_i16];
    }

    _SFD_SYMBOL_SWITCH(8U, 43U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
    _SFD_SYMBOL_SWITCH(9U, 9U);
    c2_m_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Phi.mat")), "load", &c2_r2);
    c2_Phi = c2_r2;
    _SFD_SYMBOL_SWITCH(9U, 9U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
    for (c2_i17 = 0; c2_i17 < 23; c2_i17++) {
      c2_b_Phi[c2_i17] = c2_Phi.Phi[c2_i17];
    }

    _SFD_SYMBOL_SWITCH(9U, 44U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    _SFD_SYMBOL_SWITCH(10U, 10U);
    c2_p_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Pi.mat")), "load", &c2_r3);
    chartInstance->c2_Pi = c2_r3;
    _SFD_SYMBOL_SWITCH(10U, 10U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
    for (c2_i18 = 0; c2_i18 < 2116; c2_i18++) {
      chartInstance->c2_b_Pi[c2_i18] = chartInstance->c2_Pi.Pi[c2_i18];
    }

    _SFD_SYMBOL_SWITCH(10U, 45U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
    _SFD_SYMBOL_SWITCH(11U, 11U);
    c2_r_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Psi.mat")), "load", &c2_r4);
    c2_Psi = c2_r4;
    _SFD_SYMBOL_SWITCH(11U, 11U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
    for (c2_i19 = 0; c2_i19 < 1058; c2_i19++) {
      c2_b_Psi[c2_i19] = c2_Psi.Psi[c2_i19];
    }

    _SFD_SYMBOL_SWITCH(11U, 46U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
    _SFD_SYMBOL_SWITCH(12U, 12U);
    c2_t_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Theta.mat")), "load", &c2_r5);
    c2_Theta = c2_r5;
    _SFD_SYMBOL_SWITCH(12U, 12U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
    for (c2_i20 = 0; c2_i20 < 1058; c2_i20++) {
      c2_b_Theta[c2_i20] = c2_Theta.Theta[c2_i20];
    }

    _SFD_SYMBOL_SWITCH(12U, 47U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
    _SFD_SYMBOL_SWITCH(13U, 13U);
    c2_w_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14,
      c2_emlrt_marshallOut(chartInstance, "Q_bar.mat")), "load", &c2_r6);
    c2_Q_bar = c2_r6;
    _SFD_SYMBOL_SWITCH(13U, 13U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
    for (c2_i21 = 0; c2_i21 < 46; c2_i21++) {
      c2_b_Q_bar[c2_i21] = c2_Q_bar.Q_bar[c2_i21];
    }

    _SFD_SYMBOL_SWITCH(13U, 48U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_ab_emlrt_marshallIn(chartInstance, sf_mex_call_debug
      (sfGlobalDebugInstanceStruct, "load", 1U, 1U, 14, c2_emlrt_marshallOut
       (chartInstance, "constant_dist.mat")), "load", &c2_r7);
    c2_constant_dist = c2_r7;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
    for (c2_i22 = 0; c2_i22 < 24; c2_i22++) {
      c2_Data_OD[c2_i22] = c2_constant_dist.constant_dist[c2_i22];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
    c2_delta_p_0 = c2_b_x;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
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
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    c2_U_bar = 0.2;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
    for (c2_i23 = 0; c2_i23 < 46; c2_i23++) {
      c2_U_bar_hp[c2_i23] = 0.2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 82);
    for (c2_i24 = 0; c2_i24 < 46; c2_i24++) {
      c2_y_low[c2_i24] = 0.08;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
    for (c2_i25 = 0; c2_i25 < 46; c2_i25++) {
      c2_y_high[c2_i25] = 0.18;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 86);
    for (c2_i26 = 0; c2_i26 < 46; c2_i26++) {
      c2_y_bar[c2_i26] = c2_dv1[c2_i26];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
    for (c2_i27 = 0; c2_i27 < 1058; c2_i27++) {
      c2_a[c2_i27] = c2_b_Theta[c2_i27];
    }

    for (c2_i28 = 0; c2_i28 < 23; c2_i28++) {
      c2_b_b[c2_i28] = c2_b_Phi[c2_i28];
    }

    c2_alpha1 = 1.0;
    c2_beta1 = 0.0;
    c2_TRANSB = 'N';
    c2_TRANSA = 'N';
    for (c2_i29 = 0; c2_i29 < 46; c2_i29++) {
      c2_c_y[c2_i29] = 0.0;
    }

    c2_m_t = (ptrdiff_t)46;
    c2_n_t = (ptrdiff_t)1;
    c2_k_t = (ptrdiff_t)23;
    c2_lda_t = (ptrdiff_t)46;
    c2_ldb_t = (ptrdiff_t)23;
    c2_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1, &c2_a[0],
          &c2_lda_t, &c2_b_b[0], &c2_ldb_t, &c2_beta1, &c2_c_y[0], &c2_ldc_t);
    c2_c_b = c2_delta_p_0;
    for (c2_i30 = 0; c2_i30 < 46; c2_i30++) {
      c2_c_y[c2_i30] *= c2_c_b;
    }

    for (c2_i31 = 0; c2_i31 < 1058; c2_i31++) {
      c2_a[c2_i31] = c2_b_Theta[c2_i31];
    }

    for (c2_i32 = 0; c2_i32 < 1058; c2_i32++) {
      c2_d_b[c2_i32] = c2_b_Psi[c2_i32];
    }

    c2_b_alpha1 = 1.0;
    c2_b_beta1 = 0.0;
    c2_b_TRANSB = 'N';
    c2_b_TRANSA = 'N';
    for (c2_i33 = 0; c2_i33 < 2116; c2_i33++) {
      c2_d_y[c2_i33] = 0.0;
    }

    c2_b_m_t = (ptrdiff_t)46;
    c2_b_n_t = (ptrdiff_t)46;
    c2_b_k_t = (ptrdiff_t)23;
    c2_b_lda_t = (ptrdiff_t)46;
    c2_b_ldb_t = (ptrdiff_t)23;
    c2_b_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_b_TRANSA, &c2_b_TRANSB, &c2_b_m_t, &c2_b_n_t, &c2_b_k_t,
          &c2_b_alpha1, &c2_a[0], &c2_b_lda_t, &c2_d_b[0], &c2_b_ldb_t,
          &c2_b_beta1, &c2_d_y[0], &c2_b_ldc_t);
    for (c2_i34 = 0; c2_i34 < 2116; c2_i34++) {
      c2_d_y[c2_i34] += chartInstance->c2_b_Pi[c2_i34];
    }

    for (c2_i35 = 0; c2_i35 < 46; c2_i35++) {
      c2_e_b[c2_i35] = c2_d_hp[c2_i35];
    }

    c2_c_alpha1 = 1.0;
    c2_c_beta1 = 0.0;
    c2_c_TRANSB = 'N';
    c2_c_TRANSA = 'N';
    for (c2_i36 = 0; c2_i36 < 46; c2_i36++) {
      c2_e_y[c2_i36] = 0.0;
    }

    c2_c_m_t = (ptrdiff_t)46;
    c2_c_n_t = (ptrdiff_t)1;
    c2_c_k_t = (ptrdiff_t)46;
    c2_c_lda_t = (ptrdiff_t)46;
    c2_c_ldb_t = (ptrdiff_t)46;
    c2_c_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_c_TRANSA, &c2_c_TRANSB, &c2_c_m_t, &c2_c_n_t, &c2_c_k_t,
          &c2_c_alpha1, &c2_d_y[0], &c2_c_lda_t, &c2_e_b[0], &c2_c_ldb_t,
          &c2_c_beta1, &c2_e_y[0], &c2_c_ldc_t);
    for (c2_i37 = 0; c2_i37 < 46; c2_i37++) {
      c2_y1[c2_i37] = ((c2_y_low[c2_i37] - c2_y_bar[c2_i37]) - c2_c_y[c2_i37]) -
        c2_e_y[c2_i37];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
    for (c2_i38 = 0; c2_i38 < 1058; c2_i38++) {
      c2_a[c2_i38] = c2_b_Theta[c2_i38];
    }

    for (c2_i39 = 0; c2_i39 < 23; c2_i39++) {
      c2_b_b[c2_i39] = c2_b_Phi[c2_i39];
    }

    c2_d_alpha1 = 1.0;
    c2_d_beta1 = 0.0;
    c2_d_TRANSB = 'N';
    c2_d_TRANSA = 'N';
    for (c2_i40 = 0; c2_i40 < 46; c2_i40++) {
      c2_c_y[c2_i40] = 0.0;
    }

    c2_d_m_t = (ptrdiff_t)46;
    c2_d_n_t = (ptrdiff_t)1;
    c2_d_k_t = (ptrdiff_t)23;
    c2_d_lda_t = (ptrdiff_t)46;
    c2_d_ldb_t = (ptrdiff_t)23;
    c2_d_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_d_TRANSA, &c2_d_TRANSB, &c2_d_m_t, &c2_d_n_t, &c2_d_k_t,
          &c2_d_alpha1, &c2_a[0], &c2_d_lda_t, &c2_b_b[0], &c2_d_ldb_t,
          &c2_d_beta1, &c2_c_y[0], &c2_d_ldc_t);
    c2_f_b = c2_delta_p_0;
    for (c2_i41 = 0; c2_i41 < 46; c2_i41++) {
      c2_c_y[c2_i41] *= c2_f_b;
    }

    for (c2_i42 = 0; c2_i42 < 1058; c2_i42++) {
      c2_a[c2_i42] = c2_b_Theta[c2_i42];
    }

    for (c2_i43 = 0; c2_i43 < 1058; c2_i43++) {
      c2_d_b[c2_i43] = c2_b_Psi[c2_i43];
    }

    c2_e_alpha1 = 1.0;
    c2_e_beta1 = 0.0;
    c2_e_TRANSB = 'N';
    c2_e_TRANSA = 'N';
    for (c2_i44 = 0; c2_i44 < 2116; c2_i44++) {
      c2_d_y[c2_i44] = 0.0;
    }

    c2_e_m_t = (ptrdiff_t)46;
    c2_e_n_t = (ptrdiff_t)46;
    c2_e_k_t = (ptrdiff_t)23;
    c2_e_lda_t = (ptrdiff_t)46;
    c2_e_ldb_t = (ptrdiff_t)23;
    c2_e_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_e_TRANSA, &c2_e_TRANSB, &c2_e_m_t, &c2_e_n_t, &c2_e_k_t,
          &c2_e_alpha1, &c2_a[0], &c2_e_lda_t, &c2_d_b[0], &c2_e_ldb_t,
          &c2_e_beta1, &c2_d_y[0], &c2_e_ldc_t);
    for (c2_i45 = 0; c2_i45 < 2116; c2_i45++) {
      c2_d_y[c2_i45] += chartInstance->c2_b_Pi[c2_i45];
    }

    for (c2_i46 = 0; c2_i46 < 46; c2_i46++) {
      c2_e_b[c2_i46] = c2_d_hp[c2_i46];
    }

    c2_f_alpha1 = 1.0;
    c2_f_beta1 = 0.0;
    c2_f_TRANSB = 'N';
    c2_f_TRANSA = 'N';
    for (c2_i47 = 0; c2_i47 < 46; c2_i47++) {
      c2_e_y[c2_i47] = 0.0;
    }

    c2_f_m_t = (ptrdiff_t)46;
    c2_f_n_t = (ptrdiff_t)1;
    c2_f_k_t = (ptrdiff_t)46;
    c2_f_lda_t = (ptrdiff_t)46;
    c2_f_ldb_t = (ptrdiff_t)46;
    c2_f_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_f_TRANSA, &c2_f_TRANSB, &c2_f_m_t, &c2_f_n_t, &c2_f_k_t,
          &c2_f_alpha1, &c2_d_y[0], &c2_f_lda_t, &c2_e_b[0], &c2_f_ldb_t,
          &c2_f_beta1, &c2_e_y[0], &c2_f_ldc_t);
    for (c2_i48 = 0; c2_i48 < 46; c2_i48++) {
      c2_y2[c2_i48] = ((c2_y_high[c2_i48] - c2_y_bar[c2_i48]) - c2_c_y[c2_i48])
        - c2_e_y[c2_i48];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
    for (c2_i49 = 0; c2_i49 < 1058; c2_i49++) {
      c2_a[c2_i49] = c2_b_Theta[c2_i49];
    }

    for (c2_i50 = 0; c2_i50 < 1058; c2_i50++) {
      c2_d_b[c2_i50] = c2_b_Gamma[c2_i50];
    }

    c2_g_alpha1 = 1.0;
    c2_g_beta1 = 0.0;
    c2_g_TRANSB = 'N';
    c2_g_TRANSA = 'N';
    for (c2_i51 = 0; c2_i51 < 2116; c2_i51++) {
      c2_d_y[c2_i51] = 0.0;
    }

    c2_g_m_t = (ptrdiff_t)46;
    c2_g_n_t = (ptrdiff_t)46;
    c2_g_k_t = (ptrdiff_t)23;
    c2_g_lda_t = (ptrdiff_t)46;
    c2_g_ldb_t = (ptrdiff_t)23;
    c2_g_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_g_TRANSA, &c2_g_TRANSB, &c2_g_m_t, &c2_g_n_t, &c2_g_k_t,
          &c2_g_alpha1, &c2_a[0], &c2_g_lda_t, &c2_d_b[0], &c2_g_ldb_t,
          &c2_g_beta1, &c2_d_y[0], &c2_g_ldc_t);
    for (c2_i52 = 0; c2_i52 < 2116; c2_i52++) {
      chartInstance->c2_L_y[c2_i52] = c2_d_y[c2_i52] + chartInstance->
        c2_b_Omega[c2_i52];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
    for (c2_i53 = 0; c2_i53 < 23; c2_i53++) {
      c2_x_low[c2_i53] = 0.055;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 98);
    for (c2_i54 = 0; c2_i54 < 23; c2_i54++) {
      c2_x_high[c2_i54] = 0.16;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 99);
    for (c2_i55 = 0; c2_i55 < 23; c2_i55++) {
      c2_x_bar[c2_i55] = 0.127;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
    for (c2_i56 = 0; c2_i56 < 23; c2_i56++) {
      c2_b_b[c2_i56] = c2_b_Phi[c2_i56];
    }

    c2_g_b = c2_delta_p_0;
    for (c2_i57 = 0; c2_i57 < 23; c2_i57++) {
      c2_b_b[c2_i57] *= c2_g_b;
    }

    for (c2_i58 = 0; c2_i58 < 1058; c2_i58++) {
      c2_d_b[c2_i58] = c2_b_Psi[c2_i58];
    }

    for (c2_i59 = 0; c2_i59 < 46; c2_i59++) {
      c2_e_b[c2_i59] = c2_d_hp[c2_i59];
    }

    c2_h_alpha1 = 1.0;
    c2_h_beta1 = 0.0;
    c2_h_TRANSB = 'N';
    c2_h_TRANSA = 'N';
    for (c2_i60 = 0; c2_i60 < 23; c2_i60++) {
      c2_f_y[c2_i60] = 0.0;
    }

    c2_h_m_t = (ptrdiff_t)23;
    c2_h_n_t = (ptrdiff_t)1;
    c2_h_k_t = (ptrdiff_t)46;
    c2_h_lda_t = (ptrdiff_t)23;
    c2_h_ldb_t = (ptrdiff_t)46;
    c2_h_ldc_t = (ptrdiff_t)23;
    dgemm(&c2_h_TRANSA, &c2_h_TRANSB, &c2_h_m_t, &c2_h_n_t, &c2_h_k_t,
          &c2_h_alpha1, &c2_d_b[0], &c2_h_lda_t, &c2_e_b[0], &c2_h_ldb_t,
          &c2_h_beta1, &c2_f_y[0], &c2_h_ldc_t);
    for (c2_i61 = 0; c2_i61 < 23; c2_i61++) {
      c2_delta_p_wt_1[c2_i61] = ((c2_x_low[c2_i61] - c2_x_bar[c2_i61]) -
        c2_b_b[c2_i61]) - c2_f_y[c2_i61];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 102);
    for (c2_i62 = 0; c2_i62 < 23; c2_i62++) {
      c2_b_b[c2_i62] = c2_b_Phi[c2_i62];
    }

    c2_h_b = c2_delta_p_0;
    for (c2_i63 = 0; c2_i63 < 23; c2_i63++) {
      c2_b_b[c2_i63] *= c2_h_b;
    }

    for (c2_i64 = 0; c2_i64 < 1058; c2_i64++) {
      c2_d_b[c2_i64] = c2_b_Psi[c2_i64];
    }

    for (c2_i65 = 0; c2_i65 < 46; c2_i65++) {
      c2_e_b[c2_i65] = c2_d_hp[c2_i65];
    }

    c2_i_alpha1 = 1.0;
    c2_i_beta1 = 0.0;
    c2_i_TRANSB = 'N';
    c2_i_TRANSA = 'N';
    for (c2_i66 = 0; c2_i66 < 23; c2_i66++) {
      c2_f_y[c2_i66] = 0.0;
    }

    c2_i_m_t = (ptrdiff_t)23;
    c2_i_n_t = (ptrdiff_t)1;
    c2_i_k_t = (ptrdiff_t)46;
    c2_i_lda_t = (ptrdiff_t)23;
    c2_i_ldb_t = (ptrdiff_t)46;
    c2_i_ldc_t = (ptrdiff_t)23;
    dgemm(&c2_i_TRANSA, &c2_i_TRANSB, &c2_i_m_t, &c2_i_n_t, &c2_i_k_t,
          &c2_i_alpha1, &c2_d_b[0], &c2_i_lda_t, &c2_e_b[0], &c2_i_ldb_t,
          &c2_i_beta1, &c2_f_y[0], &c2_i_ldc_t);
    for (c2_i67 = 0; c2_i67 < 23; c2_i67++) {
      c2_delta_p_wt_2[c2_i67] = ((c2_x_high[c2_i67] - c2_x_bar[c2_i67]) -
        c2_b_b[c2_i67]) - c2_f_y[c2_i67];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 105);
    for (c2_i68 = 0; c2_i68 < 46; c2_i68++) {
      c2_u_low[c2_i68] = c2_dv2[c2_i68];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 110);
    c2_u_high = 0.75;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 116);
    for (c2_i69 = 0; c2_i69 < 1058; c2_i69++) {
      c2_a[c2_i69] = c2_b_Lambda_C[c2_i69];
    }

    for (c2_i70 = 0; c2_i70 < 1058; c2_i70++) {
      c2_d_b[c2_i70] = c2_b_Gamma[c2_i70];
    }

    c2_j_alpha1 = 1.0;
    c2_j_beta1 = 0.0;
    c2_j_TRANSB = 'N';
    c2_j_TRANSA = 'N';
    for (c2_i71 = 0; c2_i71 < 2116; c2_i71++) {
      c2_d_y[c2_i71] = 0.0;
    }

    c2_j_m_t = (ptrdiff_t)46;
    c2_j_n_t = (ptrdiff_t)46;
    c2_j_k_t = (ptrdiff_t)23;
    c2_j_lda_t = (ptrdiff_t)46;
    c2_j_ldb_t = (ptrdiff_t)23;
    c2_j_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_j_TRANSA, &c2_j_TRANSB, &c2_j_m_t, &c2_j_n_t, &c2_j_k_t,
          &c2_j_alpha1, &c2_a[0], &c2_j_lda_t, &c2_d_b[0], &c2_j_ldb_t,
          &c2_j_beta1, &c2_d_y[0], &c2_j_ldc_t);
    for (c2_i72 = 0; c2_i72 < 2116; c2_i72++) {
      c2_d_y[c2_i72] += chartInstance->c2_Lambda_A[c2_i72];
    }

    for (c2_i73 = 0; c2_i73 < 2116; c2_i73++) {
      chartInstance->c2_R[c2_i73] = 2.0 * c2_d_y[c2_i73];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
    c2_i74 = 0;
    for (c2_i75 = 0; c2_i75 < 46; c2_i75++) {
      c2_i77 = 0;
      for (c2_i78 = 0; c2_i78 < 46; c2_i78++) {
        c2_d_y[c2_i78 + c2_i74] = chartInstance->c2_R[c2_i78 + c2_i74] +
          chartInstance->c2_R[c2_i77 + c2_i75];
        c2_i77 += 46;
      }

      c2_i74 += 46;
    }

    for (c2_i76 = 0; c2_i76 < 2116; c2_i76++) {
      chartInstance->c2_R1[c2_i76] = c2_d_y[c2_i76] / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 119);
    c2_i79 = 0;
    for (c2_i80 = 0; c2_i80 < 46; c2_i80++) {
      c2_i82 = 0;
      for (c2_i83 = 0; c2_i83 < 46; c2_i83++) {
        c2_d_y[c2_i83 + c2_i79] = chartInstance->c2_R[c2_i83 + c2_i79] -
          chartInstance->c2_R[c2_i82 + c2_i80];
        c2_i82 += 46;
      }

      c2_i79 += 46;
    }

    for (c2_i81 = 0; c2_i81 < 2116; c2_i81++) {
      chartInstance->c2_R2[c2_i81] = c2_d_y[c2_i81] / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
    for (c2_i84 = 0; c2_i84 < 1058; c2_i84++) {
      c2_a[c2_i84] = c2_b_Lambda_C[c2_i84];
    }

    for (c2_i85 = 0; c2_i85 < 1058; c2_i85++) {
      c2_d_b[c2_i85] = c2_b_Gamma[c2_i85];
    }

    c2_k_alpha1 = 1.0;
    c2_k_beta1 = 0.0;
    c2_k_TRANSB = 'N';
    c2_k_TRANSA = 'N';
    for (c2_i86 = 0; c2_i86 < 2116; c2_i86++) {
      c2_d_y[c2_i86] = 0.0;
    }

    c2_k_m_t = (ptrdiff_t)46;
    c2_k_n_t = (ptrdiff_t)46;
    c2_k_k_t = (ptrdiff_t)23;
    c2_k_lda_t = (ptrdiff_t)46;
    c2_k_ldb_t = (ptrdiff_t)23;
    c2_k_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_k_TRANSA, &c2_k_TRANSB, &c2_k_m_t, &c2_k_n_t, &c2_k_k_t,
          &c2_k_alpha1, &c2_a[0], &c2_k_lda_t, &c2_d_b[0], &c2_k_ldb_t,
          &c2_k_beta1, &c2_d_y[0], &c2_k_ldc_t);
    for (c2_i87 = 0; c2_i87 < 2116; c2_i87++) {
      c2_d_y[c2_i87] += chartInstance->c2_Lambda_A[c2_i87];
    }

    c2_l_alpha1 = 1.0;
    for (c2_i88 = 0; c2_i88 < 46; c2_i88++) {
      c2_d_A[c2_i88] = 0.2;
    }

    c2_l_beta1 = 0.0;
    c2_l_TRANSB = 'N';
    c2_l_TRANSA = 'N';
    for (c2_i89 = 0; c2_i89 < 46; c2_i89++) {
      c2_g_y[c2_i89] = 0.0;
    }

    c2_l_m_t = (ptrdiff_t)1;
    c2_l_n_t = (ptrdiff_t)46;
    c2_l_k_t = (ptrdiff_t)46;
    c2_l_lda_t = (ptrdiff_t)1;
    c2_l_ldb_t = (ptrdiff_t)46;
    c2_l_ldc_t = (ptrdiff_t)1;
    dgemm(&c2_l_TRANSA, &c2_l_TRANSB, &c2_l_m_t, &c2_l_n_t, &c2_l_k_t,
          &c2_l_alpha1, &c2_d_A[0], &c2_l_lda_t, &c2_d_y[0], &c2_l_ldb_t,
          &c2_l_beta1, &c2_g_y[0], &c2_l_ldc_t);
    for (c2_i90 = 0; c2_i90 < 1058; c2_i90++) {
      c2_a[c2_i90] = c2_b_Lambda_C[c2_i90];
    }

    for (c2_i91 = 0; c2_i91 < 1058; c2_i91++) {
      c2_d_b[c2_i91] = c2_b_Psi[c2_i91];
    }

    c2_m_alpha1 = 1.0;
    c2_m_beta1 = 0.0;
    c2_m_TRANSB = 'N';
    c2_m_TRANSA = 'N';
    for (c2_i92 = 0; c2_i92 < 2116; c2_i92++) {
      c2_d_y[c2_i92] = 0.0;
    }

    c2_m_m_t = (ptrdiff_t)46;
    c2_m_n_t = (ptrdiff_t)46;
    c2_m_k_t = (ptrdiff_t)23;
    c2_m_lda_t = (ptrdiff_t)46;
    c2_m_ldb_t = (ptrdiff_t)23;
    c2_m_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_m_TRANSA, &c2_m_TRANSB, &c2_m_m_t, &c2_m_n_t, &c2_m_k_t,
          &c2_m_alpha1, &c2_a[0], &c2_m_lda_t, &c2_d_b[0], &c2_m_ldb_t,
          &c2_m_beta1, &c2_d_y[0], &c2_m_ldc_t);
    for (c2_i93 = 0; c2_i93 < 46; c2_i93++) {
      c2_d_A[c2_i93] = c2_d_hp[c2_i93];
    }

    c2_i94 = 0;
    for (c2_i95 = 0; c2_i95 < 46; c2_i95++) {
      c2_i96 = 0;
      for (c2_i97 = 0; c2_i97 < 46; c2_i97++) {
        c2_i_b[c2_i97 + c2_i94] = chartInstance->c2_Lambda_B[c2_i96 + c2_i95] +
          c2_d_y[c2_i96 + c2_i95];
        c2_i96 += 46;
      }

      c2_i94 += 46;
    }

    c2_n_alpha1 = 1.0;
    c2_n_beta1 = 0.0;
    c2_n_TRANSB = 'N';
    c2_n_TRANSA = 'N';
    for (c2_i98 = 0; c2_i98 < 46; c2_i98++) {
      c2_h_y[c2_i98] = 0.0;
    }

    c2_n_m_t = (ptrdiff_t)1;
    c2_n_n_t = (ptrdiff_t)46;
    c2_n_k_t = (ptrdiff_t)46;
    c2_n_lda_t = (ptrdiff_t)1;
    c2_n_ldb_t = (ptrdiff_t)46;
    c2_n_ldc_t = (ptrdiff_t)1;
    dgemm(&c2_n_TRANSA, &c2_n_TRANSB, &c2_n_m_t, &c2_n_n_t, &c2_n_k_t,
          &c2_n_alpha1, &c2_d_A[0], &c2_n_lda_t, &c2_i_b[0], &c2_n_ldb_t,
          &c2_n_beta1, &c2_h_y[0], &c2_n_ldc_t);
    for (c2_i99 = 0; c2_i99 < 1058; c2_i99++) {
      c2_a[c2_i99] = c2_b_Lambda_C[c2_i99];
    }

    for (c2_i100 = 0; c2_i100 < 23; c2_i100++) {
      c2_b_b[c2_i100] = c2_b_Phi[c2_i100];
    }

    c2_o_alpha1 = 1.0;
    c2_o_beta1 = 0.0;
    c2_o_TRANSB = 'N';
    c2_o_TRANSA = 'N';
    for (c2_i101 = 0; c2_i101 < 46; c2_i101++) {
      c2_c_y[c2_i101] = 0.0;
    }

    c2_o_m_t = (ptrdiff_t)46;
    c2_o_n_t = (ptrdiff_t)1;
    c2_o_k_t = (ptrdiff_t)23;
    c2_o_lda_t = (ptrdiff_t)46;
    c2_o_ldb_t = (ptrdiff_t)23;
    c2_o_ldc_t = (ptrdiff_t)46;
    dgemm(&c2_o_TRANSA, &c2_o_TRANSB, &c2_o_m_t, &c2_o_n_t, &c2_o_k_t,
          &c2_o_alpha1, &c2_a[0], &c2_o_lda_t, &c2_b_b[0], &c2_o_ldb_t,
          &c2_o_beta1, &c2_c_y[0], &c2_o_ldc_t);
    c2_b_a = c2_delta_p_0;
    for (c2_i102 = 0; c2_i102 < 46; c2_i102++) {
      c2_d_A[c2_i102] = c2_c_y[c2_i102];
    }

    for (c2_i103 = 0; c2_i103 < 46; c2_i103++) {
      c2_d_A[c2_i103] *= c2_b_a;
    }

    for (c2_i104 = 0; c2_i104 < 46; c2_i104++) {
      c2_f[c2_i104] = ((c2_g_y[c2_i104] + c2_h_y[c2_i104]) + c2_d_A[c2_i104]) +
        c2_b_Q_bar[c2_i104];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 123);
    c2_i105 = 0;
    c2_i106 = 0;
    for (c2_i107 = 0; c2_i107 < 46; c2_i107++) {
      for (c2_i109 = 0; c2_i109 < 46; c2_i109++) {
        chartInstance->c2_A[c2_i109 + c2_i105] = -chartInstance->c2_L_y[c2_i109
          + c2_i106];
      }

      c2_i105 += 138;
      c2_i106 += 46;
    }

    c2_i108 = 0;
    c2_i110 = 0;
    for (c2_i111 = 0; c2_i111 < 46; c2_i111++) {
      for (c2_i113 = 0; c2_i113 < 46; c2_i113++) {
        chartInstance->c2_A[(c2_i113 + c2_i108) + 46] = chartInstance->
          c2_L_y[c2_i113 + c2_i110];
      }

      c2_i108 += 138;
      c2_i110 += 46;
    }

    c2_i112 = 0;
    c2_i114 = 0;
    for (c2_i115 = 0; c2_i115 < 46; c2_i115++) {
      for (c2_i117 = 0; c2_i117 < 23; c2_i117++) {
        chartInstance->c2_A[(c2_i117 + c2_i112) + 92] = -c2_b_Gamma[c2_i117 +
          c2_i114];
      }

      c2_i112 += 138;
      c2_i114 += 23;
    }

    c2_i116 = 0;
    c2_i118 = 0;
    for (c2_i119 = 0; c2_i119 < 46; c2_i119++) {
      for (c2_i120 = 0; c2_i120 < 23; c2_i120++) {
        chartInstance->c2_A[(c2_i120 + c2_i116) + 115] = c2_b_Gamma[c2_i120 +
          c2_i118];
      }

      c2_i116 += 138;
      c2_i118 += 23;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 124);
    for (c2_i121 = 0; c2_i121 < 46; c2_i121++) {
      c2_b[c2_i121] = -c2_y1[c2_i121];
    }

    for (c2_i122 = 0; c2_i122 < 46; c2_i122++) {
      c2_b[c2_i122 + 46] = c2_y2[c2_i122];
    }

    for (c2_i123 = 0; c2_i123 < 23; c2_i123++) {
      c2_b[c2_i123 + 92] = -c2_delta_p_wt_1[c2_i123];
    }

    for (c2_i124 = 0; c2_i124 < 23; c2_i124++) {
      c2_b[c2_i124 + 115] = c2_delta_p_wt_2[c2_i124];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 126);
    for (c2_i125 = 0; c2_i125 < 46; c2_i125++) {
      c2_lb[c2_i125] = c2_u_low[c2_i125];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, MAX_int8_T);
    for (c2_i126 = 0; c2_i126 < 46; c2_i126++) {
      c2_ub[c2_i126] = 0.75;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 135U);
    sf_mex_assign(&c2_opts, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "optimoptions", 1U, 5U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv0),
      14, c2_c_emlrt_marshallOut(chartInstance, c2_cv1), 14,
      c2_d_emlrt_marshallOut(chartInstance, c2_cv2), 14, c2_e_emlrt_marshallOut
      (chartInstance, c2_cv3), 14, c2_f_emlrt_marshallOut(chartInstance, c2_cv4)),
                  false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 137U);
    for (c2_i127 = 0; c2_i127 < 46; c2_i127++) {
      c2_b_lb[c2_i127] = c2_lb[c2_i127] - 0.5;
    }

    c2_db_emlrt_marshallIn(chartInstance, sf_mex_call_debug
      (sfGlobalDebugInstanceStruct, "quadprog", 1U, 10U, 14,
       c2_g_emlrt_marshallOut(chartInstance, chartInstance->c2_R), 14,
       c2_h_emlrt_marshallOut(chartInstance, c2_f), 14, c2_i_emlrt_marshallOut
       (chartInstance, chartInstance->c2_A), 14, c2_j_emlrt_marshallOut
       (chartInstance, c2_b), 14, c2_k_emlrt_marshallOut(chartInstance), 14,
       c2_k_emlrt_marshallOut(chartInstance), 14, c2_l_emlrt_marshallOut
       (chartInstance, c2_b_lb), 14, c2_l_emlrt_marshallOut(chartInstance, c2_ub),
       14, c2_k_emlrt_marshallOut(chartInstance), 14, sf_mex_dup(c2_opts)),
      "quadprog", c2_dv3);
    for (c2_i128 = 0; c2_i128 < 46; c2_i128++) {
      c2_u_hp[c2_i128] = c2_dv3[c2_i128];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 142U);
    c2_i129 = 0;
    for (c2_i130 = 0; c2_i130 < 23; c2_i130++) {
      c2_u_hp1[c2_i130] = c2_u_hp[c2_i129];
      c2_i129 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 143U);
    c2_i131 = 0;
    for (c2_i132 = 0; c2_i132 < 23; c2_i132++) {
      c2_u_hp2[c2_i132] = c2_u_hp[c2_i131 + 1];
      c2_i131 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 155U);
    c2_b_u[0] = c2_u_hp1[0];
    c2_b_u[1] = c2_u_hp2[0];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 156U);
    for (c2_i133 = 0; c2_i133 < 2; c2_i133++) {
      c2_b_u_old[c2_i133] = c2_b_u[c2_i133];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 158U);
    for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
      c2_b_u[c2_i10] = c2_b_u_old[c2_i10];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -158);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c2_opts);
  for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
    (*chartInstance->c2_u)[c2_i13] = c2_b_u[c2_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_simulering_vinkel_2016b
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i134;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[2];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i134 = 0; c2_i134 < 2; c2_i134++) {
    c2_b_u[c2_i134] = (*(real_T (*)[2])c2_inData)[c2_i134];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const char_T *c2_identifier, real_T
  c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_u);
}

static void c2_b_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2])
{
  real_T c2_dv4[2];
  int32_T c2_i135;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv4, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i135 = 0; c2_i135 < 2; c2_i135++) {
    c2_y[c2_i135] = c2_dv4[c2_i135];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i136;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_b_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_u);
  for (c2_i136 = 0; c2_i136 < 2; c2_i136++) {
    (*(real_T (*)[2])c2_outData)[c2_i136] = c2_y[c2_i136];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i137;
  int32_T c2_i138;
  const mxArray *c2_y = NULL;
  int32_T c2_i139;
  real_T c2_b_u[1058];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i137 = 0;
  for (c2_i138 = 0; c2_i138 < 23; c2_i138++) {
    for (c2_i139 = 0; c2_i139 < 46; c2_i139++) {
      c2_b_u[c2_i139 + c2_i137] = (*(real_T (*)[1058])c2_inData)[c2_i139 +
        c2_i137];
    }

    c2_i137 += 46;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 46, 23),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i140;
  int32_T c2_i141;
  const mxArray *c2_y = NULL;
  int32_T c2_i142;
  real_T c2_b_u[2116];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i140 = 0;
  for (c2_i141 = 0; c2_i141 < 46; c2_i141++) {
    for (c2_i142 = 0; c2_i142 < 46; c2_i142++) {
      c2_b_u[c2_i142 + c2_i140] = (*(real_T (*)[2116])c2_inData)[c2_i142 +
        c2_i140];
    }

    c2_i140 += 46;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 46, 46),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i143;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[46];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i143 = 0; c2_i143 < 46; c2_i143++) {
    c2_b_u[c2_i143] = (*(real_T (*)[46])c2_inData)[c2_i143];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 46), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_quadprog;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[46];
  int32_T c2_i144;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_quadprog = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_quadprog), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_quadprog);
  for (c2_i144 = 0; c2_i144 < 46; c2_i144++) {
    (*(real_T (*)[46])c2_outData)[c2_i144] = c2_y[c2_i144];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Theta;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[1058];
  int32_T c2_i145;
  int32_T c2_i146;
  int32_T c2_i147;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_Theta = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Theta), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Theta);
  c2_i145 = 0;
  for (c2_i146 = 0; c2_i146 < 23; c2_i146++) {
    for (c2_i147 = 0; c2_i147 < 46; c2_i147++) {
      (*(real_T (*)[1058])c2_outData)[c2_i147 + c2_i145] = c2_y[c2_i147 +
        c2_i145];
    }

    c2_i145 += 46;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i148;
  int32_T c2_i149;
  const mxArray *c2_y = NULL;
  int32_T c2_i150;
  real_T c2_b_u[1058];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i148 = 0;
  for (c2_i149 = 0; c2_i149 < 46; c2_i149++) {
    for (c2_i150 = 0; c2_i150 < 23; c2_i150++) {
      c2_b_u[c2_i150 + c2_i148] = (*(real_T (*)[1058])c2_inData)[c2_i150 +
        c2_i148];
    }

    c2_i148 += 23;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 23, 46),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Psi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[1058];
  int32_T c2_i151;
  int32_T c2_i152;
  int32_T c2_i153;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_Psi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Psi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Psi);
  c2_i151 = 0;
  for (c2_i152 = 0; c2_i152 < 46; c2_i152++) {
    for (c2_i153 = 0; c2_i153 < 23; c2_i153++) {
      (*(real_T (*)[1058])c2_outData)[c2_i153 + c2_i151] = c2_y[c2_i153 +
        c2_i151];
    }

    c2_i151 += 23;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_c_Pi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2116];
  int32_T c2_i154;
  int32_T c2_i155;
  int32_T c2_i156;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_c_Pi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_Pi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_c_Pi);
  c2_i154 = 0;
  for (c2_i155 = 0; c2_i155 < 46; c2_i155++) {
    for (c2_i156 = 0; c2_i156 < 46; c2_i156++) {
      (*(real_T (*)[2116])c2_outData)[c2_i156 + c2_i154] = c2_y[c2_i156 +
        c2_i154];
    }

    c2_i154 += 46;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i157;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[23];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i157 = 0; c2_i157 < 23; c2_i157++) {
    c2_b_u[c2_i157] = (*(real_T (*)[23])c2_inData)[c2_i157];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 23), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Phi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[23];
  int32_T c2_i158;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_Phi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Phi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Phi);
  for (c2_i158 = 0; c2_i158 < 23; c2_i158++) {
    (*(real_T (*)[23])c2_outData)[c2_i158] = c2_y[c2_i158];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  const mxArray *c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = sf_mex_dup(*(const mxArray **)c2_inData);
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_b_u), false);
  sf_mex_destroy(&c2_b_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i159;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[138];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i159 = 0; c2_i159 < 138; c2_i159++) {
    c2_b_u[c2_i159] = (*(real_T (*)[138])c2_inData)[c2_i159];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[138])
{
  real_T c2_dv5[138];
  int32_T c2_i160;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv5, 1, 0, 0U, 1, 0U, 1, 138);
  for (c2_i160 = 0; c2_i160 < 138; c2_i160++) {
    c2_y[c2_i160] = c2_dv5[c2_i160];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[138];
  int32_T c2_i161;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_b = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b);
  for (c2_i161 = 0; c2_i161 < 138; c2_i161++) {
    (*(real_T (*)[138])c2_outData)[c2_i161] = c2_y[c2_i161];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i162;
  int32_T c2_i163;
  const mxArray *c2_y = NULL;
  int32_T c2_i164;
  real_T c2_b_u[6348];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i162 = 0;
  for (c2_i163 = 0; c2_i163 < 46; c2_i163++) {
    for (c2_i164 = 0; c2_i164 < 138; c2_i164++) {
      c2_b_u[c2_i164 + c2_i162] = (*(real_T (*)[6348])c2_inData)[c2_i164 +
        c2_i162];
    }

    c2_i162 += 138;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 138, 46),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6348])
{
  real_T c2_dv6[6348];
  int32_T c2_i165;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 138,
                46);
  for (c2_i165 = 0; c2_i165 < 6348; c2_i165++) {
    c2_y[c2_i165] = c2_dv6[c2_i165];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_A;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6348];
  int32_T c2_i166;
  int32_T c2_i167;
  int32_T c2_i168;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_b_A = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_A), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_A);
  c2_i166 = 0;
  for (c2_i167 = 0; c2_i167 < 46; c2_i167++) {
    for (c2_i168 = 0; c2_i168 < 138; c2_i168++) {
      (*(real_T (*)[6348])c2_outData)[c2_i168 + c2_i166] = c2_y[c2_i168 +
        c2_i166];
    }

    c2_i166 += 138;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i169;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[46];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i169 = 0; c2_i169 < 46; c2_i169++) {
    c2_b_u[c2_i169] = (*(real_T (*)[46])c2_inData)[c2_i169];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 46),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[46])
{
  real_T c2_dv7[46];
  int32_T c2_i170;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                46);
  for (c2_i170 = 0; c2_i170 < 46; c2_i170++) {
    c2_y[c2_i170] = c2_dv7[c2_i170];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_f;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[46];
  int32_T c2_i171;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_f = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_f), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_f);
  for (c2_i171 = 0; c2_i171 < 46; c2_i171++) {
    (*(real_T (*)[46])c2_outData)[c2_i171] = c2_y[c2_i171];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i172;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[24];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i172 = 0; c2_i172 < 24; c2_i172++) {
    c2_b_u[c2_i172] = (*(real_T (*)[24])c2_inData)[c2_i172];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Data_OD;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[24];
  int32_T c2_i173;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_Data_OD = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Data_OD), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Data_OD);
  for (c2_i173 = 0; c2_i173 < 24; c2_i173++) {
    (*(real_T (*)[24])c2_outData)[c2_i173] = c2_y[c2_i173];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i174;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[24];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_shjtd7pXyPLVVdClb9GNBeB *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i174 = 0; c2_i174 < 24; c2_i174++) {
    c2_c_u[c2_i174] = c2_b_u.constant_dist[c2_i174];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_addfield(c2_y, c2_b_y, "constant_dist", "constant_dist", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_shjtd7pXyPLVVdClb9GNBeB c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_shjtd7pXyPLVVdClb9GNBeB *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sqoxuV7hFFxgljYD64O2e8D c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i175;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[46];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sqoxuV7hFFxgljYD64O2e8D *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i175 = 0; c2_i175 < 46; c2_i175++) {
    c2_c_u[c2_i175] = c2_b_u.Q_bar[c2_i175];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 46), false);
  sf_mex_addfield(c2_y, c2_b_y, "Q_bar", "Q_bar", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sqoxuV7hFFxgljYD64O2e8D c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_sqoxuV7hFFxgljYD64O2e8D *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_stkjSRV8bNurnAOIfmNzFv c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i176;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[1058];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_stkjSRV8bNurnAOIfmNzFv *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i176 = 0; c2_i176 < 1058; c2_i176++) {
    c2_c_u[c2_i176] = c2_b_u.Theta[c2_i176];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 46, 23),
                false);
  sf_mex_addfield(c2_y, c2_b_y, "Theta", "Theta", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_stkjSRV8bNurnAOIfmNzFv c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_stkjSRV8bNurnAOIfmNzFv *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sYtaFjV9hT44BZtqxYLBdPC c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i177;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[1058];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sYtaFjV9hT44BZtqxYLBdPC *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i177 = 0; c2_i177 < 1058; c2_i177++) {
    c2_c_u[c2_i177] = c2_b_u.Psi[c2_i177];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 23, 46),
                false);
  sf_mex_addfield(c2_y, c2_b_y, "Psi", "Psi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sYtaFjV9hT44BZtqxYLBdPC c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_sYtaFjV9hT44BZtqxYLBdPC *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sBYPrnfGIO0jxBCm3vjPz9G c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i178;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[2116];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sBYPrnfGIO0jxBCm3vjPz9G *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i178 = 0; c2_i178 < 2116; c2_i178++) {
    c2_c_u[c2_i178] = c2_b_u.Pi[c2_i178];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 46, 46),
                false);
  sf_mex_addfield(c2_y, c2_b_y, "Pi", "Pi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sBYPrnfGIO0jxBCm3vjPz9G c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_sBYPrnfGIO0jxBCm3vjPz9G *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sGkAry86wpEobQ8qQO6mmvC c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i179;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[23];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sGkAry86wpEobQ8qQO6mmvC *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i179 = 0; c2_i179 < 23; c2_i179++) {
    c2_c_u[c2_i179] = c2_b_u.Phi[c2_i179];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 23), false);
  sf_mex_addfield(c2_y, c2_b_y, "Phi", "Phi", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sGkAry86wpEobQ8qQO6mmvC c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_sGkAry86wpEobQ8qQO6mmvC *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_s454HJ9Zz3PEsaEb4npqG3E c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i180;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[2116];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_s454HJ9Zz3PEsaEb4npqG3E *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i180 = 0; c2_i180 < 2116; c2_i180++) {
    c2_c_u[c2_i180] = c2_b_u.Omega[c2_i180];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 46, 46),
                false);
  sf_mex_addfield(c2_y, c2_b_y, "Omega", "Omega", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_s454HJ9Zz3PEsaEb4npqG3E c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_s454HJ9Zz3PEsaEb4npqG3E *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sIQ3pmxd46lhLR0Qo0qcBsF c2_b_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i181;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u[1058];
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_sIQ3pmxd46lhLR0Qo0qcBsF *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i181 = 0; c2_i181 < 1058; c2_i181++) {
    c2_c_u[c2_i181] = c2_b_u.Gamma[c2_i181];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 23, 46),
                false);
  sf_mex_addfield(c2_y, c2_b_y, "Gamma", "Gamma", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_load;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sIQ3pmxd46lhLR0Qo0qcBsF c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_load = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_load);
  *(c2_sIQ3pmxd46lhLR0Qo0qcBsF *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_simulering_vinkel_2016b_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char
   * c2_b_u)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_b_u)), false);
  return c2_y;
}

static void c2_g_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sIQ3pmxd46lhLR0Qo0qcBsF *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_h_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sIQ3pmxd46lhLR0Qo0qcBsF *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Gamma" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Gamma";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Gamma", "Gamma", 0)), &c2_thisId, c2_y->Gamma);
  sf_mex_destroy(&c2_b_u);
}

static void c2_i_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[1058])
{
  real_T c2_dv8[1058];
  int32_T c2_i182;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv8, 1, 0, 0U, 1, 0U, 2, 23,
                46);
  for (c2_i182 = 0; c2_i182 < 1058; c2_i182++) {
    c2_y[c2_i182] = c2_dv8[c2_i182];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_j_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_s454HJ9Zz3PEsaEb4npqG3E *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_k_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_s454HJ9Zz3PEsaEb4npqG3E *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Omega" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Omega";
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Omega", "Omega", 0)), &c2_thisId, c2_y->Omega);
  sf_mex_destroy(&c2_b_u);
}

static void c2_l_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2116])
{
  real_T c2_dv9[2116];
  int32_T c2_i183;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv9, 1, 0, 0U, 1, 0U, 2, 46,
                46);
  for (c2_i183 = 0; c2_i183 < 2116; c2_i183++) {
    c2_y[c2_i183] = c2_dv9[c2_i183];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_m_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sGkAry86wpEobQ8qQO6mmvC *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_n_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sGkAry86wpEobQ8qQO6mmvC *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Phi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Phi";
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Phi",
    "Phi", 0)), &c2_thisId, c2_y->Phi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_o_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[23])
{
  real_T c2_dv10[23];
  int32_T c2_i184;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv10, 1, 0, 0U, 1, 0U, 1, 23);
  for (c2_i184 = 0; c2_i184 < 23; c2_i184++) {
    c2_y[c2_i184] = c2_dv10[c2_i184];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_p_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sBYPrnfGIO0jxBCm3vjPz9G *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_q_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sBYPrnfGIO0jxBCm3vjPz9G *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Pi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Pi";
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Pi",
    "Pi", 0)), &c2_thisId, c2_y->Pi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_r_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sYtaFjV9hT44BZtqxYLBdPC *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_s_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sYtaFjV9hT44BZtqxYLBdPC *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Psi" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Psi";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "Psi",
    "Psi", 0)), &c2_thisId, c2_y->Psi);
  sf_mex_destroy(&c2_b_u);
}

static void c2_t_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_stkjSRV8bNurnAOIfmNzFv *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_u_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_stkjSRV8bNurnAOIfmNzFv *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Theta" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Theta";
  c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Theta", "Theta", 0)), &c2_thisId, c2_y->Theta);
  sf_mex_destroy(&c2_b_u);
}

static void c2_v_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[1058])
{
  real_T c2_dv11[1058];
  int32_T c2_i185;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 46,
                23);
  for (c2_i185 = 0; c2_i185 < 1058; c2_i185++) {
    c2_y[c2_i185] = c2_dv11[c2_i185];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_w_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_sqoxuV7hFFxgljYD64O2e8D *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_x_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sqoxuV7hFFxgljYD64O2e8D *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "Q_bar" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Q_bar";
  c2_y_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "Q_bar", "Q_bar", 0)), &c2_thisId, c2_y->Q_bar);
  sf_mex_destroy(&c2_b_u);
}

static void c2_y_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[46])
{
  real_T c2_dv12[46];
  int32_T c2_i186;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 46);
  for (c2_i186 = 0; c2_i186 < 46; c2_i186++) {
    c2_y[c2_i186] = c2_dv12[c2_i186];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_ab_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_load, const char_T *c2_identifier,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_load), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_load);
}

static void c2_bb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_shjtd7pXyPLVVdClb9GNBeB *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "constant_dist" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "constant_dist";
  c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u,
    "constant_dist", "constant_dist", 0)), &c2_thisId, c2_y->constant_dist);
  sf_mex_destroy(&c2_b_u);
}

static void c2_cb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24])
{
  real_T c2_dv13[24];
  int32_T c2_i187;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv13, 1, 0, 0U, 1, 0U, 1, 24);
  for (c2_i187 = 0; c2_i187 < 24; c2_i187++) {
    c2_y[c2_i187] = c2_dv13[c2_i187];
  }

  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[8])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 8),
                false);
  return c2_y;
}

static const mxArray *c2_c_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[9])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  return c2_y;
}

static const mxArray *c2_d_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[21])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  return c2_y;
}

static const mxArray *c2_e_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[7])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  return c2_y;
}

static const mxArray *c2_f_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const char_T
   c2_b_u[4])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  return c2_y;
}

static const mxArray *c2_g_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[2116])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 46, 46),
                false);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[46])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 46),
                false);
  return c2_y;
}

static const mxArray *c2_i_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[6348])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 138, 46),
                false);
  return c2_y;
}

static const mxArray *c2_j_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[138])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 138), false);
  return c2_y;
}

static const mxArray *c2_k_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  return c2_y;
}

static const mxArray *c2_l_emlrt_marshallOut
  (SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance, const real_T
   c2_b_u[46])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 46), false);
  return c2_y;
}

static void c2_db_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_quadprog, const char_T *c2_identifier,
  real_T c2_y[46])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_quadprog), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_quadprog);
}

static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_eb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i188;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i188, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i188;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_fb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_simulering_vinkel_2016b,
  const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_gb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_simulering_vinkel_2016b), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_simulering_vinkel_2016b);
  return c2_y;
}

static uint8_T c2_gb_emlrt_marshallIn(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_simulering_vinkel_2016bInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_simulering_vinkel_2016bInstanceStruct *
  chartInstance)
{
  chartInstance->c2_b_Lambda_A = (real_T (*)[2116])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_b_Lambda_B = (real_T (*)[2116])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_Lambda_C = (real_T (*)[1058])ssGetInputPortSignal_wrapper
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

void sf_c2_simulering_vinkel_2016b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2103754093U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3879883042U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1193541258U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2990207583U);
}

mxArray* sf_c2_simulering_vinkel_2016b_get_post_codegen_info(void);
mxArray *sf_c2_simulering_vinkel_2016b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bTAUkn84PLTcU9z3bAawDH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(46);
      pr[1] = (double)(46);
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
      pr[0] = (double)(46);
      pr[1] = (double)(46);
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
      pr[0] = (double)(46);
      pr[1] = (double)(23);
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
    mxArray* mxPostCodegenInfo =
      sf_c2_simulering_vinkel_2016b_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_simulering_vinkel_2016b_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c2_simulering_vinkel_2016b_jit_fallback_info(void)
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

mxArray *sf_c2_simulering_vinkel_2016b_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_simulering_vinkel_2016b_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_simulering_vinkel_2016b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c2_simulering_vinkel_2016b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_simulering_vinkel_2016b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance =
      (SFc2_simulering_vinkel_2016bInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _simulering_vinkel_2016bMachineNumber_,
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
        init_script_number_translation(_simulering_vinkel_2016bMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_simulering_vinkel_2016bMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _simulering_vinkel_2016bMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,5278);
        _SFD_CV_INIT_EML_IF(0,1,0,276,291,5249,5273);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,279,291,-1,1);

        {
          unsigned int dimVector[2];
          dimVector[0]= 46U;
          dimVector[1]= 46U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 46U;
          dimVector[1]= 46U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 46U;
          dimVector[1]= 23U;
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
        _simulering_vinkel_2016bMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance =
      (SFc2_simulering_vinkel_2016bInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_b_Lambda_A);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c2_b_Lambda_B);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c2_Lambda_C);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_t_clock);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_x);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c2_u_old);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c2_u);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sve4EV0OdeejgaYm7HX2SmG";
}

static void sf_opaque_initialize_c2_simulering_vinkel_2016b(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_simulering_vinkel_2016bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_simulering_vinkel_2016b
    ((SFc2_simulering_vinkel_2016bInstanceStruct*) chartInstanceVar);
  initialize_c2_simulering_vinkel_2016b
    ((SFc2_simulering_vinkel_2016bInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_simulering_vinkel_2016b(void *chartInstanceVar)
{
  enable_c2_simulering_vinkel_2016b((SFc2_simulering_vinkel_2016bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_simulering_vinkel_2016b(void *chartInstanceVar)
{
  disable_c2_simulering_vinkel_2016b((SFc2_simulering_vinkel_2016bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_simulering_vinkel_2016b(void *chartInstanceVar)
{
  sf_gateway_c2_simulering_vinkel_2016b
    ((SFc2_simulering_vinkel_2016bInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_simulering_vinkel_2016b
  (SimStruct* S)
{
  return get_sim_state_c2_simulering_vinkel_2016b
    ((SFc2_simulering_vinkel_2016bInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_simulering_vinkel_2016b(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c2_simulering_vinkel_2016b
    ((SFc2_simulering_vinkel_2016bInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c2_simulering_vinkel_2016b(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_simulering_vinkel_2016bInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_simulering_vinkel_2016b_optimization_info();
    }

    finalize_c2_simulering_vinkel_2016b
      ((SFc2_simulering_vinkel_2016bInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_simulering_vinkel_2016b
    ((SFc2_simulering_vinkel_2016bInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_simulering_vinkel_2016b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_simulering_vinkel_2016b
      ((SFc2_simulering_vinkel_2016bInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_simulering_vinkel_2016b(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simulering_vinkel_2016b_optimization_info
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
  ssSetChecksum0(S,(3328794011U));
  ssSetChecksum1(S,(255597540U));
  ssSetChecksum2(S,(676787137U));
  ssSetChecksum3(S,(3277040144U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_simulering_vinkel_2016b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_simulering_vinkel_2016b(SimStruct *S)
{
  SFc2_simulering_vinkel_2016bInstanceStruct *chartInstance;
  chartInstance = (SFc2_simulering_vinkel_2016bInstanceStruct *)utMalloc(sizeof
    (SFc2_simulering_vinkel_2016bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_simulering_vinkel_2016bInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_simulering_vinkel_2016b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_simulering_vinkel_2016b;
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
  mdl_start_c2_simulering_vinkel_2016b(chartInstance);
}

void c2_simulering_vinkel_2016b_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_simulering_vinkel_2016b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_simulering_vinkel_2016b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_simulering_vinkel_2016b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_simulering_vinkel_2016b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
