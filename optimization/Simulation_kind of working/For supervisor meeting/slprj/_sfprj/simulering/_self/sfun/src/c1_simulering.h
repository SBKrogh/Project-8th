#ifndef __c1_simulering_h__
#define __c1_simulering_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_tag_shjtd7pXyPLVVdClb9GNBeB
#define struct_tag_shjtd7pXyPLVVdClb9GNBeB

struct tag_shjtd7pXyPLVVdClb9GNBeB
{
  real_T constant_dist[24];
};

#endif                                 /*struct_tag_shjtd7pXyPLVVdClb9GNBeB*/

#ifndef typedef_c1_shjtd7pXyPLVVdClb9GNBeB
#define typedef_c1_shjtd7pXyPLVVdClb9GNBeB

typedef struct tag_shjtd7pXyPLVVdClb9GNBeB c1_shjtd7pXyPLVVdClb9GNBeB;

#endif                                 /*typedef_c1_shjtd7pXyPLVVdClb9GNBeB*/

#ifndef typedef_SFc1_simuleringInstanceStruct
#define typedef_SFc1_simuleringInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_simulering;
  void *c1_fEmlrtCtx;
  real_T *c1_Data_OD;
  real_T *c1_t_clock;
  real_T (*c1_d)[2];
} SFc1_simuleringInstanceStruct;

#endif                                 /*typedef_SFc1_simuleringInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_simulering_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_simulering_get_check_sum(mxArray *plhs[]);
extern void c1_simulering_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
