/* Include files */

#include "blascompat32.h"
#include "chooseTapB_sfun.h"
#include "c2_chooseTapB.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "chooseTapB_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[4] = { "nargin", "nargout", "ave",
  "tap" };

/* Function Declarations */
static void initialize_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance);
static void initialize_params_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance);
static void enable_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance);
static void disable_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *
  chartInstance);
static void set_sim_state_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance);
static void sf_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c2_chooseTapB
  (SFc2_chooseTapBInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_chooseTapBInstanceStruct *chartInstance,
  const mxArray *c2_tap, const char_T *c2_name);
static uint8_T c2_b_emlrt_marshallIn(SFc2_chooseTapBInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_chooseTapB, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_chooseTapBInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_chooseTapB = 0U;
}

static void initialize_params_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance)
{
}

static void enable_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_tap;
  c2_tap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_tap;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_chooseTapB;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_chooseTapB(SFc2_chooseTapBInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_tap;
  c2_tap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_tap = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "tap");
  chartInstance->c2_is_active_c2_chooseTapB = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_chooseTapB");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_chooseTapB(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance)
{
}

static void sf_c2_chooseTapB(SFc2_chooseTapBInstanceStruct *chartInstance)
{
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_ave;
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_tap;
  real_T *c2_b_ave;
  real_T *c2_b_tap;
  c2_b_tap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_ave = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  _SFD_DATA_RANGE_CHECK(*c2_b_ave, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_tap, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  c2_hoistedGlobal = *c2_b_ave;
  c2_ave = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_ave, c2_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_tap, c2_sf_marshall, 3U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  if (CV_EML_IF(0, 0, c2_ave >= 60.0)) {
    _SFD_EML_CALL(0, 5);
    c2_tap = 4.0;
  } else {
    _SFD_EML_CALL(0, 6);
    if (CV_EML_COND(0, 0, c2_ave < 60.0)) {
      if (CV_EML_COND(0, 1, c2_ave > 20.0)) {
        CV_EML_MCDC(0, 0, TRUE);
        CV_EML_IF(0, 1, TRUE);
        _SFD_EML_CALL(0, 7);
        c2_tap = 3.0;
        goto label_1;
      }
    }

    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 1, FALSE);
    _SFD_EML_CALL(0, 8);
    if (CV_EML_COND(0, 2, c2_ave <= 20.0)) {
      if (CV_EML_COND(0, 3, c2_ave >= -20.0)) {
        CV_EML_MCDC(0, 1, TRUE);
        CV_EML_IF(0, 2, TRUE);
        _SFD_EML_CALL(0, 9);
        c2_tap = 2.0;
        goto label_2;
      }
    }

    CV_EML_MCDC(0, 1, FALSE);
    CV_EML_IF(0, 2, FALSE);
    _SFD_EML_CALL(0, 10);
    if (CV_EML_COND(0, 4, c2_ave < -20.0)) {
      if (CV_EML_COND(0, 5, c2_ave > -60.0)) {
        CV_EML_MCDC(0, 2, TRUE);
        CV_EML_IF(0, 3, TRUE);
        _SFD_EML_CALL(0, 11);
        c2_tap = 1.0;
        goto label_3;
      }
    }

    CV_EML_MCDC(0, 2, FALSE);
    CV_EML_IF(0, 3, FALSE);
    _SFD_EML_CALL(0, 13);
    c2_tap = 0.0;
   label_3:
    ;
   label_2:
    ;
   label_1:
    ;
  }

  _SFD_EML_CALL(0, -13);
  sf_debug_symbol_scope_pop();
  *c2_b_tap = c2_tap;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_chooseTapBMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c2_chooseTapB
  (SFc2_chooseTapBInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_chooseTapBInstanceStruct *chartInstance;
  chartInstance = (SFc2_chooseTapBInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_chooseTapB_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[5];
  c2_ResolvedFunctionInfo (*c2_b_info)[5];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[5])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "ge";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved = "[B]ge";
  (*c2_b_info)[0].fileLength = 0U;
  (*c2_b_info)[0].fileTime1 = 0U;
  (*c2_b_info)[0].fileTime2 = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "lt";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved = "[B]lt";
  (*c2_b_info)[1].fileLength = 0U;
  (*c2_b_info)[1].fileTime1 = 0U;
  (*c2_b_info)[1].fileTime2 = 0U;
  (*c2_b_info)[2].context = "";
  (*c2_b_info)[2].name = "gt";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved = "[B]gt";
  (*c2_b_info)[2].fileLength = 0U;
  (*c2_b_info)[2].fileTime1 = 0U;
  (*c2_b_info)[2].fileTime2 = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "le";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved = "[B]le";
  (*c2_b_info)[3].fileLength = 0U;
  (*c2_b_info)[3].fileTime1 = 0U;
  (*c2_b_info)[3].fileTime2 = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "uminus";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved = "[B]uminus";
  (*c2_b_info)[4].fileLength = 0U;
  (*c2_b_info)[4].fileTime1 = 0U;
  (*c2_b_info)[4].fileTime2 = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5));
  for (c2_i0 = 0; c2_i0 < 5; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_chooseTapBInstanceStruct *chartInstance;
  chartInstance = (SFc2_chooseTapBInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_chooseTapBInstanceStruct *chartInstance,
  const mxArray *c2_tap, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_tap), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_tap);
  return c2_y;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_chooseTapBInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_chooseTapB,
  const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_chooseTapB), &c2_u0, 1, 3,
                0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_chooseTapB);
  return c2_y;
}

static void init_dsm_address_info(SFc2_chooseTapBInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_chooseTapB_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2027818605U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2655586846U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2224993867U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2174905880U);
}

mxArray *sf_c2_chooseTapB_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2968906768U);
    pr[1] = (double)(484985574U);
    pr[2] = (double)(162178795U);
    pr[3] = (double)(2744820555U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_chooseTapB(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"tap\",},{M[8],M[0],T\"is_active_c2_chooseTapB\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_chooseTapB_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_chooseTapBInstanceStruct *chartInstance;
    chartInstance = (SFc2_chooseTapBInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_chooseTapBMachineNumber_,
           2,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_chooseTapBMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_chooseTapBMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_chooseTapBMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"ave");
          _SFD_SET_DATA_PROPS(1,2,0,1,"tap");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,4,0,0,0,0,6,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,180);
        _SFD_CV_INIT_EML_IF(0,0,35,45,57,180);
        _SFD_CV_INIT_EML_IF(0,1,57,78,90,180);
        _SFD_CV_INIT_EML_IF(0,2,90,114,126,180);
        _SFD_CV_INIT_EML_IF(0,3,126,149,161,180);

        {
          static int condStart[] = { 64, 72 };

          static int condEnd[] = { 70, 78 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,64,78,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 97, 106 };

          static int condEnd[] = { 104, 114 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,97,114,2,2,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 133, 142 };

          static int condEnd[] = { 140, 149 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,2,133,149,2,4,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);

        {
          real_T *c2_ave;
          real_T *c2_tap;
          c2_tap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_ave = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_ave);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_tap);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_chooseTapBMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_chooseTapB(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_chooseTapBInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*)
    chartInstanceVar);
  initialize_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_chooseTapB(void *chartInstanceVar)
{
  enable_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_chooseTapB(void *chartInstanceVar)
{
  disable_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_chooseTapB(void *chartInstanceVar)
{
  sf_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_chooseTapB(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_chooseTapB
    ((SFc2_chooseTapBInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_chooseTapB();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c2_chooseTapB(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_chooseTapB();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_chooseTapB(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_chooseTapB(S);
}

static void sf_opaque_set_sim_state_c2_chooseTapB(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_chooseTapB(S, st);
}

static void sf_opaque_terminate_c2_chooseTapB(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_chooseTapBInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_chooseTapB(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_chooseTapB((SFc2_chooseTapBInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_chooseTapB(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"chooseTapB","chooseTapB",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"chooseTapB","chooseTapB",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"chooseTapB",
      "chooseTapB",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"chooseTapB","chooseTapB",2,1);
      sf_mark_chart_reusable_outputs(S,"chooseTapB","chooseTapB",2,1);
    }

    sf_set_rtw_dwork_info(S,"chooseTapB","chooseTapB",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3360615682U));
  ssSetChecksum1(S,(3293175533U));
  ssSetChecksum2(S,(168251990U));
  ssSetChecksum3(S,(819124666U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_chooseTapB(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "chooseTapB", "chooseTapB",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_chooseTapB(SimStruct *S)
{
  SFc2_chooseTapBInstanceStruct *chartInstance;
  chartInstance = (SFc2_chooseTapBInstanceStruct *)malloc(sizeof
    (SFc2_chooseTapBInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_chooseTapBInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_chooseTapB;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_chooseTapB;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_chooseTapB;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_chooseTapB;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_chooseTapB;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_chooseTapB;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_chooseTapB;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_chooseTapB;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_chooseTapB;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_chooseTapB;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_chooseTapB;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_chooseTapB_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_chooseTapB(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_chooseTapB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_chooseTapB(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_chooseTapB_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
