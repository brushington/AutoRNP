static double array_x_sf_airy_Bi_0[2] = {
-4.220967154532811492e+02,
-4.220967154532811492e+02,
};
static double array_y_sf_airy_Bi_0[2] = {
-2.384408282942121184e-13,
-2.384408282942121184e-13,
};
static double array_e_y_sf_airy_Bi_0[2] = {
-1.525878489563766448e-05,
1.525878238365354570e-05,
};
static double array_detla_sf_airy_Bi_0[2] = {
1.453644625658013491e-13,
1.453644625658014754e-13,
};
static double array_idx_sf_airy_Bi_0[3] = {
0.000000000000000000e+00,
1.049691540000000000e+08,
2.099382940000000000e+08,
};
static double array_maxE_sf_airy_Bi_0[2] = {
1.610170811830434002e-03,
-1.610170480016660712e-03,
};
double accuracy_improve_patch_of_gsl_sf_airy_Bi_0(double x)
{
 long int n = 209938295;
 int len_glob = 2;
 double ulp_x = 5.684341886080802e-14;
 double x_0 = -422.09672142008674;
 double compen = 0.0;
 double n_x = ((x-x_0)/ulp_x);
 int idx = floor(n_x*len_glob/n);
 while((idx>=0)&&(idx<len_glob)){
     if((n_x>array_idx_sf_airy_Bi_0[idx])&&(n_x<array_idx_sf_airy_Bi_0[idx+1])){
         compen = ulp_x*ulp_x * (n_x-array_idx_sf_airy_Bi_0[idx+1])*(n_x-array_idx_sf_airy_Bi_0[idx])*array_maxE_sf_airy_Bi_0[idx];
         return (x-array_x_sf_airy_Bi_0[idx])/ulp_x*array_detla_sf_airy_Bi_0[idx]+array_y_sf_airy_Bi_0[idx]+compen;
     }
     else if(n_x<array_idx_sf_airy_Bi_0[idx]){
         idx = idx - 1;
     }
     else if(n_x>array_idx_sf_airy_Bi_0[idx+1]){
         idx = idx + 1;
     }
     else if(x==array_x_sf_airy_Bi_0[idx]){
         return array_y_sf_airy_Bi_0[idx];
     }
     else{
         return array_e_y_sf_airy_Bi_0[idx];
     }
 }
}
double accuracy_improve_patch_of_gsl_sf_airy_Bi(double x)
{
if(x<=-422.09670948647636){
 return accuracy_improve_patch_of_gsl_sf_airy_Bi_0(x);
}
}
