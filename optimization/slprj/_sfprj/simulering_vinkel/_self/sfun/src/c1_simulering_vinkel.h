#ifndef __c1_simulering_vinkel_h__
#define __c1_simulering_vinkel_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_tag_ssrCYUAwxEQRtVjetKYahCH
#define struct_tag_ssrCYUAwxEQRtVjetKYahCH

struct tag_ssrCYUAwxEQRtVjetKYahCH
{
  real_T Data_OD[24];
};

#endif                                 /*struct_tag_ssrCYUAwxEQRtVjetKYahCH*/

#ifndef typedef_c1_ssrCYUAwxEQRtVjetKYahCH
#define typedef_c1_ssrCYUAwxEQRtVjetKYahCH

typedef struct tag_ssrCYUAwxEQRtVjetKYahCH c1_ssrCYUAwxEQRtVjetKYahCH;

#endif                                 /*typedef_c1_ssrCYUAwxEQRtVjetKYahCH*/

#ifndef typedef_SFc1_simulering_vinkelInstanceStruct
#define typedef_SFc1_simulering_vinkelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_simulering_vinkel;
  void *c1_fEmlrtCtx;
  real_T *c1_t_clock;
  real_T (*c1_d)[2];
  real_T *c1_Data_OD;
} SFc1_simulering_vinkelInstanceStruct;

#endif                                 /*typedef_SFc1_simulering_vinkelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_simulering_vinkel_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_simulering_vinkel_get_check_sum(mxArray *plhs[]);
extern void c1_simulering_vinkel_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
