#include <mod/amlmod.h>
#include <mod/logger.h>
#include <math.h>

#include "cleo.h"
cleo_ifs_t* cleo = nullptr;

MYMOD(net.rusjj.mathops, CLEO MathOperations, 1.0, RusJJ)
BEGIN_DEPLIST()
    ADD_DEPENDENCY_VER(net.rusjj.cleolib, 2.0.1.3)
END_DEPLIST()

#define CLEO_RegisterOpcode(x, h) cleo->RegisterOpcode(x, h); cleo->RegisterOpcodeFunction(#h, h)
#define CLEO_Fn(h) void h (void *handle, uint32_t *ip, uint16_t opcode, const char *name)

// ------------------------------------[1C00 - 1C09]---------------------------------------------

CLEO_Fn(DEGREE_TO_RADIAN)
{
    float degree = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = degree * (M_PI / 180.0);
}
CLEO_Fn(RADIAN_TO_DEGREE)
{
    float radian = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = radian * (180.0 / M_PI);
}
CLEO_Fn(INT_MODULO)
{
    int x = cleo->ReadParam(handle)->i;
    int y = cleo->ReadParam(handle)->i;
    cleo->GetPointerToScriptVar(handle)->i = x % y;
}
CLEO_Fn(FLOAT_MODULO)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = fmod(x, y);
}
CLEO_Fn(ACOS)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = acos(f);
}
CLEO_Fn(ASIN)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = asin(f);
}
CLEO_Fn(ATAN)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = atan(f);
}
CLEO_Fn(CUBEROOT)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = cbrt(f);
}
CLEO_Fn(CEIL)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = ceil(f);
}
CLEO_Fn(COS)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = cos(f);
}

// ------------------------------------[1C10 - 1C19]---------------------------------------------

CLEO_Fn(COSH)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = cosh(f);
}
CLEO_Fn(EXPM1)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = expm1(f);
}
CLEO_Fn(FDIM)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = fdim(x, y);
}
CLEO_Fn(FLOOR)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = floor(f);
}
CLEO_Fn(HYPOT)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = hypot(x, y);
}
CLEO_Fn(FMA)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    float z = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = fma(x, y, z);
}
CLEO_Fn(FMAX)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = fmax(x, y);
}
CLEO_Fn(FMIN)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = fmin(x, y);
}
CLEO_Fn(SIN)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = sin(f);
}
CLEO_Fn(SINH)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = sinh(f);
}

// ------------------------------------[1C20 - 1C29]---------------------------------------------

CLEO_Fn(TAN)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = tan(f);
}
CLEO_Fn(TANH)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = tanh(f);
}
CLEO_Fn(ATAN2)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = atan2(x, y);
}
CLEO_Fn(FREXP)
{
    float f = cleo->ReadParam(handle)->f;
    int expVar = 0;
    cleo->GetPointerToScriptVar(handle)->f = frexp(f, &expVar);
    cleo->GetPointerToScriptVar(handle)->i = expVar;
}
CLEO_Fn(LDEXP)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = ldexp(x, y);
}
CLEO_Fn(MODF)
{
    float x = cleo->ReadParam(handle)->f;
    float y = 0.0f;
    cleo->GetPointerToScriptVar(handle)->f = modf(x, &y);
    cleo->GetPointerToScriptVar(handle)->f = y;
}
CLEO_Fn(SCALBN)
{
    float x = cleo->ReadParam(handle)->f;
    int n = cleo->ReadParam(handle)->i;
    cleo->GetPointerToScriptVar(handle)->f = scalbn(x, n);
}
CLEO_Fn(TRUNC)
{
    float x = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = trunc(x);
}
CLEO_Fn(REMAINDER)
{
    float x = cleo->ReadParam(handle)->f;
    float y = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->f = remainder(x, y);
}
CLEO_Fn(FPCLASSIFY)
{
    float f = cleo->ReadParam(handle)->f;
    cleo->GetPointerToScriptVar(handle)->i = fpclassify(f);
}

// ----------------------------------------------------------------------------------------------

extern "C" void OnModLoad()
{
    logger->SetTag("[CLEO] MathOperations");
    if(!(cleo = (cleo_ifs_t*)GetInterface("CLEO")))
    {
        logger->Error("CLEO is not installed!");
        return;
    }

    CLEO_RegisterOpcode(0x1C00, DEGREE_TO_RADIAN); // 1C00=2,%2d% = to_radian %1d%
    CLEO_RegisterOpcode(0x1C01, RADIAN_TO_DEGREE); // 1C01=2,%2d% = to_degree %1d%
    CLEO_RegisterOpcode(0x1C02, INT_MODULO); // 1C02=3,%3d% = modulo_int %1d% %2d%
    CLEO_RegisterOpcode(0x1C03, FLOAT_MODULO); // 1C03=3,%3d% = modulo_float %1d% %2d%
    CLEO_RegisterOpcode(0x1C04, ACOS); // 1C04=2,%2d% = acos %1d%
    CLEO_RegisterOpcode(0x1C05, ASIN); // 1C05=2,%2d% = asin %1d%
    CLEO_RegisterOpcode(0x1C06, ATAN); // 1C06=2,%2d% = atan %1d%
    CLEO_RegisterOpcode(0x1C07, CUBEROOT); // 1C07=2,%2d% = cbrt %1d%
    CLEO_RegisterOpcode(0x1C08, CEIL); // 1C08=2,%2d% = ceil %1d%
    CLEO_RegisterOpcode(0x1C09, COS); // 1C09=2,%2d% = cos %1d%

    CLEO_RegisterOpcode(0x1C10, COSH); // 1C10=2,%2d% = cosh %1d%
    CLEO_RegisterOpcode(0x1C11, EXPM1); // 1C11=2,%2d% = expm1 %1d%
    CLEO_RegisterOpcode(0x1C12, FDIM); // 1C12=3,%3d% = fdim %1d% %2d%
    CLEO_RegisterOpcode(0x1C13, FLOOR); // 1C13=2,%2d% = floor %1d%
    CLEO_RegisterOpcode(0x1C14, HYPOT); // 1C14=3,%3d% = hypot %1d% %2d%
    CLEO_RegisterOpcode(0x1C15, FMA); // 1C15=4,%4d% = fma %1d% %2d% %3d%
    CLEO_RegisterOpcode(0x1C16, FMAX); // 1C16=3,%3d% = fmax %1d% %2d%
    CLEO_RegisterOpcode(0x1C17, FMIN); // 1C17=3,%3d% = fmin %1d% %2d%
    CLEO_RegisterOpcode(0x1C18, SIN); // 1C18=2,%2d% = sin %1d%
    CLEO_RegisterOpcode(0x1C19, SINH); // 1C19=2,%2d% = sinh %1d%

    CLEO_RegisterOpcode(0x1C20, TAN); // 1C20=2,%2d% = tan %1d%
    CLEO_RegisterOpcode(0x1C21, TANH); // 1C21=2,%2d% = tanh %1d%
    CLEO_RegisterOpcode(0x1C22, ATAN2); // 1C22=3,%3d% = atan2 %1d% %2d%
    CLEO_RegisterOpcode(0x1C23, FREXP); // 1C23=3,%2d% exp %3d% = frexp %1d%
    CLEO_RegisterOpcode(0x1C24, LDEXP); // 1C24=3,%3d% = ldexp %1d% exp %2d%
    CLEO_RegisterOpcode(0x1C25, MODF); // 1C25=3,%2d% intpart %3d% = modf %1d%
    CLEO_RegisterOpcode(0x1C26, SCALBN); // 1C26=3,%3d% = scalbn %1d% int_n %2d%
    CLEO_RegisterOpcode(0x1C27, TRUNC); // 1C27=2,%2d% = trunc %1d%
    CLEO_RegisterOpcode(0x1C28, REMAINDER); // 1C28=3,%3d% = remainder %1d% %2d%
    CLEO_RegisterOpcode(0x1C29, FPCLASSIFY); // 1C29=2,%2d% = fpclassify %1d%
}