static double array_x_sf_psi_0[16] = {
-1.829874037639078779e+03,
-1.829873978776362947e+03,
-1.829873978776362947e+03,
-1.829873949345005258e+03,
-1.829873934629326413e+03,
-1.829873927271486991e+03,
-1.829873923592567280e+03,
-1.829873919913647342e+03,
-1.829873919913647342e+03,
-1.829873916228208600e+03,
-1.829873912542769631e+03,
-1.829873905171892147e+03,
-1.829873890430137180e+03,
-1.829873875688381986e+03,
-1.829873860946626792e+03,
-1.829873831463116403e+03,
};
static double array_y_sf_psi_0[16] = {
-7.812499252927858004e-03,
-3.904521393750296897e-03,
-3.904521393750296897e-03,
-1.951828953634123778e-03,
-9.758065867023818420e-04,
-4.878763333638489927e-04,
-2.439314350839488148e-04,
-5.743609863643113040e-12,
-5.743609863643113040e-12,
2.443501352966590250e-04,
4.886867619427044630e-04,
9.773194014370371885e-04,
1.954422379120140593e-03,
2.931309033511696454e-03,
3.907979425568617465e-03,
5.860671726617841873e-03,
};
static double array_e_y_sf_psi_0[16] = {
-5.858077962830953583e-03,
-5.858077962830953583e-03,
-2.928067197382347789e-03,
-2.928067197382347789e-03,
-1.951828953634123778e-03,
-9.758065867023818420e-04,
-4.878763333638489927e-04,
-2.439314350839488148e-04,
2.443501352966590250e-04,
4.886867619427044630e-04,
9.773194014370371885e-04,
1.954422379120140593e-03,
2.931309033511696454e-03,
3.907979425568617465e-03,
5.860671726617841873e-03,
7.812499874742624348e-03,
};
static double array_detla_sf_psi_0[16] = {
1.509899588596943055e-11,
1.509231543322723636e-11,
1.508730802555659797e-11,
1.508397131636446256e-11,
1.508063577841710637e-11,
1.507813485668572493e-11,
1.507688465184308213e-11,
1.507605127943207300e-11,
1.507521724188456785e-11,
1.507438253936492038e-11,
1.507313063232194709e-11,
1.507062733170017149e-11,
1.506729057512684625e-11,
1.506395499118601526e-11,
1.505895395922201332e-11,
1.505228982047154660e-11,
};
static double array_idx_sf_psi_0[17] = {
0.000000000000000000e+00,
1.294404810000000000e+08,
2.588809620000000000e+08,
3.236012020000000000e+08,
3.883214420000000000e+08,
4.530416820000000000e+08,
4.854018020000000000e+08,
5.015818620000000000e+08,
5.177619230000000000e+08,
5.339706540000000000e+08,
5.501793860000000000e+08,
5.825968480000000000e+08,
6.474317720000000000e+08,
7.122666970000000000e+08,
7.771016220000000000e+08,
9.067714720000000000e+08,
1.036441321000000000e+09,
};
static double array_maxE_sf_psi_0[16] = {
-4.993188283689810305e+02,
-4.989682083270289468e+02,
-4.987054529524889404e+02,
-4.985303882680476590e+02,
-4.983554052725664860e+02,
-4.982242203287191273e+02,
-4.981586453821715281e+02,
-4.981149353466065008e+02,
-4.980711916732490181e+02,
-4.980274144024875227e+02,
-4.979617583951567212e+02,
-4.978304815518804958e+02,
-4.976555156052209554e+02,
-4.974806313888310001e+02,
-4.972184633027618474e+02,
-4.968691846727379016e+02,
};
double accuracy_improve_patch_of_gsl_sf_psi_0(double x)
{
 long int n = 1036441322;
 int len_glob = 16;
 double ulp_x = 2.2737367544323206e-13;
 double x_0 = -1829.8740376390788;
 double compen = 0.0;
 double n_x = ((x-x_0)/ulp_x);
 int idx = floor(n_x*len_glob/n);
 while((idx>=0)&&(idx<len_glob)){
     if((n_x>array_idx_sf_psi_0[idx])&&(n_x<array_idx_sf_psi_0[idx+1])){
         compen = ulp_x*ulp_x * (n_x-array_idx_sf_psi_0[idx+1])*(n_x-array_idx_sf_psi_0[idx])*array_maxE_sf_psi_0[idx];
         return (x-array_x_sf_psi_0[idx])/ulp_x*array_detla_sf_psi_0[idx]+array_y_sf_psi_0[idx]+compen;
     }
     else if(n_x<array_idx_sf_psi_0[idx]){
         idx = idx - 1;
     }
     else if(n_x>array_idx_sf_psi_0[idx+1]){
         idx = idx + 1;
     }
     else if(x==array_x_sf_psi_0[idx]){
         return array_y_sf_psi_0[idx];
     }
     else{
         return array_e_y_sf_psi_0[idx];
     }
 }
}
double accuracy_improve_patch_of_gsl_sf_psi(double x)
{
if(x<=-1829.8738019796062){
 return accuracy_improve_patch_of_gsl_sf_psi_0(x);
}
}
