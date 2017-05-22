#ifndef __c2_simulering_vinkel_h__
#define __c2_simulering_vinkel_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_tag_sXRXp7aMGjI8fA8IXQDoqtG
#define struct_tag_sXRXp7aMGjI8fA8IXQDoqtG

struct tag_sXRXp7aMGjI8fA8IXQDoqtG
{
  real_T Phi[24];
};

#endif                                 /*struct_tag_sXRXp7aMGjI8fA8IXQDoqtG*/

#ifndef typedef_c2_sXRXp7aMGjI8fA8IXQDoqtG
#define typedef_c2_sXRXp7aMGjI8fA8IXQDoqtG

typedef struct tag_sXRXp7aMGjI8fA8IXQDoqtG c2_sXRXp7aMGjI8fA8IXQDoqtG;

#endif                                 /*typedef_c2_sXRXp7aMGjI8fA8IXQDoqtG*/

#ifndef struct_tag_ssrCYUAwxEQRtVjetKYahCH
#define struct_tag_ssrCYUAwxEQRtVjetKYahCH

struct tag_ssrCYUAwxEQRtVjetKYahCH
{
  real_T Data_OD[24];
};

#endif                                 /*struct_tag_ssrCYUAwxEQRtVjetKYahCH*/

#ifndef typedef_c2_ssrCYUAwxEQRtVjetKYahCH
#define typedef_c2_ssrCYUAwxEQRtVjetKYahCH

typedef struct tag_ssrCYUAwxEQRtVjetKYahCH c2_ssrCYUAwxEQRtVjetKYahCH;

#endif                                 /*typedef_c2_ssrCYUAwxEQRtVjetKYahCH*/

#ifndef struct_tag_sDEl41izlL3fNQfEgJJ5XBH
#define struct_tag_sDEl41izlL3fNQfEgJJ5XBH

struct tag_sDEl41izlL3fNQfEgJJ5XBH
{
  real_T Gamma[1152];
};

#endif                                 /*struct_tag_sDEl41izlL3fNQfEgJJ5XBH*/

#ifndef typedef_c2_sDEl41izlL3fNQfEgJJ5XBH
#define typedef_c2_sDEl41izlL3fNQfEgJJ5XBH

typedef struct tag_sDEl41izlL3fNQfEgJJ5XBH c2_sDEl41izlL3fNQfEgJJ5XBH;

#endif                                 /*typedef_c2_sDEl41izlL3fNQfEgJJ5XBH*/

#ifndef struct_tag_sHr555XKyGoUpad7tsiNQiE
#define struct_tag_sHr555XKyGoUpad7tsiNQiE

struct tag_sHr555XKyGoUpad7tsiNQiE
{
  real_T Omega[2304];
};

#endif                                 /*struct_tag_sHr555XKyGoUpad7tsiNQiE*/

#ifndef typedef_c2_sHr555XKyGoUpad7tsiNQiE
#define typedef_c2_sHr555XKyGoUpad7tsiNQiE

typedef struct tag_sHr555XKyGoUpad7tsiNQiE c2_sHr555XKyGoUpad7tsiNQiE;

#endif                                 /*typedef_c2_sHr555XKyGoUpad7tsiNQiE*/

#ifndef struct_tag_sjdLzyTh14ULkIImcl6xwW
#define struct_tag_sjdLzyTh14ULkIImcl6xwW

struct tag_sjdLzyTh14ULkIImcl6xwW
{
  real_T Pi[2304];
};

#endif                                 /*struct_tag_sjdLzyTh14ULkIImcl6xwW*/

#ifndef typedef_c2_sjdLzyTh14ULkIImcl6xwW
#define typedef_c2_sjdLzyTh14ULkIImcl6xwW

typedef struct tag_sjdLzyTh14ULkIImcl6xwW c2_sjdLzyTh14ULkIImcl6xwW;

#endif                                 /*typedef_c2_sjdLzyTh14ULkIImcl6xwW*/

#ifndef struct_tag_sVXPIQCYRVtgDunkSIgrZND
#define struct_tag_sVXPIQCYRVtgDunkSIgrZND

struct tag_sVXPIQCYRVtgDunkSIgrZND
{
  real_T Psi[1152];
};

#endif                                 /*struct_tag_sVXPIQCYRVtgDunkSIgrZND*/

#ifndef typedef_c2_sVXPIQCYRVtgDunkSIgrZND
#define typedef_c2_sVXPIQCYRVtgDunkSIgrZND

typedef struct tag_sVXPIQCYRVtgDunkSIgrZND c2_sVXPIQCYRVtgDunkSIgrZND;

#endif                                 /*typedef_c2_sVXPIQCYRVtgDunkSIgrZND*/

#ifndef struct_tag_spEGmxEyHM6EoZZcXmG7jeB
#define struct_tag_spEGmxEyHM6EoZZcXmG7jeB

struct tag_spEGmxEyHM6EoZZcXmG7jeB
{
  real_T Theta[1152];
};

#endif                                 /*struct_tag_spEGmxEyHM6EoZZcXmG7jeB*/

#ifndef typedef_c2_spEGmxEyHM6EoZZcXmG7jeB
#define typedef_c2_spEGmxEyHM6EoZZcXmG7jeB

typedef struct tag_spEGmxEyHM6EoZZcXmG7jeB c2_spEGmxEyHM6EoZZcXmG7jeB;

#endif                                 /*typedef_c2_spEGmxEyHM6EoZZcXmG7jeB*/

#ifndef typedef_SFc2_simulering_vinkelInstanceStruct
#define typedef_SFc2_simulering_vinkelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_simulering_vinkel;
  real_T c2_A[6912];
  real_T c2_Lambda_A[2304];
  real_T c2_Lambda_B[2304];
  c2_sHr555XKyGoUpad7tsiNQiE c2_Omega;
  c2_sjdLzyTh14ULkIImcl6xwW c2_Pi;
  real_T c2_L_y[2304];
  real_T c2_R[2304];
  real_T c2_R1[2304];
  real_T c2_R2[2304];
  real_T c2_b_Omega[2304];
  real_T c2_b_Pi[2304];
  c2_sHr555XKyGoUpad7tsiNQiE c2_r1;
  void *c2_fEmlrtCtx;
  real_T (*c2_b_Lambda_A)[2304];
  real_T (*c2_b_Lambda_B)[2304];
  real_T (*c2_Lambda_C)[1152];
  real_T *c2_t_clock;
  real_T *c2_x;
  real_T (*c2_u_old)[2];
  real_T (*c2_u)[2];
} SFc2_simulering_vinkelInstanceStruct;

#endif                                 /*typedef_SFc2_simulering_vinkelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_simulering_vinkel_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_simulering_vinkel_get_check_sum(mxArray *plhs[]);
extern void c2_simulering_vinkel_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
