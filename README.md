### What are those opcodes?
These are giving an access to math functions such as sine, cosine and more.

### How to add these opcodes in Sanny Builder 3?
1. Enter the directory of Sanny Builder 3
2. Enter ../data/sa_mobile (or ../data/vc_mobile for GTA:VC Android)
3. Open and add these lines at the end of the file SASCM.ini (or VCSCM.ini):
```
1C00=2,%2d% = to_radian %1d%
1C01=2,%2d% = to_degree %1d%
1C02=3,%3d% = modulo_int %1d% %2d%
1C03=3,%3d% = modulo_float %1d% %2d%
1C04=2,%2d% = acos %1d%
1C05=2,%2d% = asin %1d%
1C06=2,%2d% = atan %1d%
1C07=2,%2d% = cbrt %1d%
1C08=2,%2d% = ceil %1d%
1C09=2,%2d% = cos %1d%
1C10=2,%2d% = cosh %1d%
1C11=2,%2d% = expm1 %1d%
1C12=3,%3d% = fdim %1d% %2d%
1C13=2,%2d% = floor %1d%
1C14=3,%3d% = hypot %1d% %2d%
1C15=4,%4d% = fma %1d% %2d% %3d%
1C16=3,%3d% = fmax %1d% %2d%
1C17=3,%3d% = fmin %1d% %2d%
1C18=2,%2d% = sin %1d%
1C19=2,%2d% = sinh %1d%
1C20=2,%2d% = tan %1d%
1C21=2,%2d% = tanh %1d%
1C22=3,%3d% = atan2 %1d% %2d%
1C23=3,%2d% exp %3d% = frexp %1d%
1C24=3,%3d% = ldexp %1d% exp %2d%
1C25=3,%2d% intpart %3d% = modf %1d%
1C26=3,%3d% = scalbn %1d% int_n %2d%
1C27=2,%2d% = trunc %1d%
1C28=3,%3d% = remainder %1d% %2d%
1C29=2,%2d% = fpclassify %1d%
```

### Notes
About fpclassify (opcode 1C29):
```
The returned value is an integer:
-1 = Normal float number
-2 = Subnormal float number
1 = Infinite float number
2 = NaN
0 = The number is just... a zero.
```