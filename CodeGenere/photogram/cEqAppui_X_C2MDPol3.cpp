// File Automatically generated by eLiSe

#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_X_C2MDPol3.h"


cEqAppui_X_C2MDPol3::cEqAppui_X_C2MDPol3():
    cElCompiledFonc(1)
{
   AddIntRef (cIncIntervale("Intr",0,20));
   AddIntRef (cIncIntervale("Orient",20,26));
   Close(false);
}



void cEqAppui_X_C2MDPol3::ComputeVal()
{
   double tmp0_ = mCompCoord[20];
   double tmp1_ = mCompCoord[21];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[22];
   double tmp7_ = mCompCoord[23];
   double tmp8_ = mLocXTer-tmp7_;
   double tmp9_ = sin(tmp6_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp5_);
   double tmp12_ = cos(tmp6_);
   double tmp13_ = mCompCoord[24];
   double tmp14_ = mLocYTer-tmp13_;
   double tmp15_ = mCompCoord[25];
   double tmp16_ = mLocZTer-tmp15_;
   double tmp17_ = ElSquare(mLocYIm);
   double tmp18_ = ElSquare(mLocXIm);

  mVal[0] = (tmp4_*tmp2_*(tmp8_)+tmp3_*tmp2_*(tmp14_)+tmp5_*(tmp16_))/((-(tmp3_)*tmp10_+tmp4_*tmp11_*tmp12_)*(tmp8_)+(tmp4_*tmp10_+tmp3_*tmp11_*tmp12_)*(tmp14_)+tmp2_*tmp12_*(tmp16_))-(mCompCoord[0]+mCompCoord[1]*mLocYIm+mCompCoord[2]*mLocXIm+mCompCoord[3]*tmp17_+mCompCoord[4]*mLocXIm*mLocYIm+mCompCoord[5]*tmp18_+mCompCoord[6]*VCube(mLocYIm)+mCompCoord[7]*mLocXIm*tmp17_+mCompCoord[8]*tmp18_*mLocYIm+mCompCoord[9]*VCube(mLocXIm));

}


void cEqAppui_X_C2MDPol3::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[20];
   double tmp1_ = mCompCoord[21];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[22];
   double tmp7_ = mCompCoord[23];
   double tmp8_ = mLocXTer-tmp7_;
   double tmp9_ = sin(tmp6_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp5_);
   double tmp12_ = cos(tmp6_);
   double tmp13_ = mCompCoord[24];
   double tmp14_ = mLocYTer-tmp13_;
   double tmp15_ = mCompCoord[25];
   double tmp16_ = mLocZTer-tmp15_;
   double tmp17_ = ElSquare(mLocYIm);
   double tmp18_ = ElSquare(mLocXIm);
   double tmp19_ = VCube(mLocYIm);
   double tmp20_ = VCube(mLocXIm);
   double tmp21_ = -(1);
   double tmp22_ = tmp4_*tmp2_;
   double tmp23_ = -(tmp3_);
   double tmp24_ = tmp23_*tmp10_;
   double tmp25_ = tmp4_*tmp11_;
   double tmp26_ = tmp25_*tmp12_;
   double tmp27_ = tmp24_+tmp26_;
   double tmp28_ = (tmp27_)*(tmp8_);
   double tmp29_ = tmp4_*tmp10_;
   double tmp30_ = tmp3_*tmp11_;
   double tmp31_ = tmp30_*tmp12_;
   double tmp32_ = tmp29_+tmp31_;
   double tmp33_ = (tmp32_)*(tmp14_);
   double tmp34_ = tmp28_+tmp33_;
   double tmp35_ = tmp2_*tmp12_;
   double tmp36_ = tmp35_*(tmp16_);
   double tmp37_ = tmp34_+tmp36_;
   double tmp38_ = tmp22_*(tmp8_);
   double tmp39_ = tmp3_*tmp2_;
   double tmp40_ = tmp39_*(tmp14_);
   double tmp41_ = tmp38_+tmp40_;
   double tmp42_ = tmp5_*(tmp16_);
   double tmp43_ = tmp41_+tmp42_;
   double tmp44_ = tmp21_*tmp3_;
   double tmp45_ = tmp21_*tmp5_;
   double tmp46_ = -(tmp2_);
   double tmp47_ = ElSquare(tmp37_);
   double tmp48_ = -(tmp12_);
   double tmp49_ = tmp21_*tmp9_;

  mVal[0] = (tmp43_)/(tmp37_)-(mCompCoord[0]+mCompCoord[1]*mLocYIm+mCompCoord[2]*mLocXIm+mCompCoord[3]*tmp17_+mCompCoord[4]*mLocXIm*mLocYIm+mCompCoord[5]*tmp18_+mCompCoord[6]*tmp19_+mCompCoord[7]*mLocXIm*tmp17_+mCompCoord[8]*tmp18_*mLocYIm+mCompCoord[9]*tmp20_);

  mCompDer[0][0] = tmp21_;
  mCompDer[0][1] = -(mLocYIm);
  mCompDer[0][2] = -(mLocXIm);
  mCompDer[0][3] = -(tmp17_);
  mCompDer[0][4] = -(mLocXIm*mLocYIm);
  mCompDer[0][5] = -(tmp18_);
  mCompDer[0][6] = -(tmp19_);
  mCompDer[0][7] = -(mLocXIm*tmp17_);
  mCompDer[0][8] = -(tmp18_*mLocYIm);
  mCompDer[0][9] = -(tmp20_);
  mCompDer[0][10] = 0;
  mCompDer[0][11] = 0;
  mCompDer[0][12] = 0;
  mCompDer[0][13] = 0;
  mCompDer[0][14] = 0;
  mCompDer[0][15] = 0;
  mCompDer[0][16] = 0;
  mCompDer[0][17] = 0;
  mCompDer[0][18] = 0;
  mCompDer[0][19] = 0;
  mCompDer[0][20] = ((tmp44_*tmp2_*(tmp8_)+tmp22_*(tmp14_))*(tmp37_)-(tmp43_)*((-(tmp4_)*tmp10_+tmp44_*tmp11_*tmp12_)*(tmp8_)+(tmp44_*tmp10_+tmp26_)*(tmp14_)))/tmp47_;
  mCompDer[0][21] = ((tmp45_*tmp4_*(tmp8_)+tmp45_*tmp3_*(tmp14_)+tmp2_*(tmp16_))*(tmp37_)-(tmp43_)*(tmp46_*tmp4_*tmp12_*(tmp8_)+tmp46_*tmp3_*tmp12_*(tmp14_)+tmp45_*tmp12_*(tmp16_)))/tmp47_;
  mCompDer[0][22] = -((tmp43_)*((tmp48_*tmp23_+tmp49_*tmp25_)*(tmp8_)+(tmp48_*tmp4_+tmp49_*tmp30_)*(tmp14_)+tmp49_*tmp2_*(tmp16_)))/tmp47_;
  mCompDer[0][23] = (tmp21_*tmp22_*(tmp37_)-(tmp43_)*tmp21_*(tmp27_))/tmp47_;
  mCompDer[0][24] = (tmp21_*tmp39_*(tmp37_)-(tmp43_)*tmp21_*(tmp32_))/tmp47_;
  mCompDer[0][25] = (tmp45_*(tmp37_)-(tmp43_)*tmp21_*tmp35_)/tmp47_;
}


void cEqAppui_X_C2MDPol3::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_X_C2MDPol3 Has no Der Sec");
}

void cEqAppui_X_C2MDPol3::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_X_C2MDPol3::SetXTer(double aVal){ mLocXTer = aVal;}
void cEqAppui_X_C2MDPol3::SetYIm(double aVal){ mLocYIm = aVal;}
void cEqAppui_X_C2MDPol3::SetYTer(double aVal){ mLocYTer = aVal;}
void cEqAppui_X_C2MDPol3::SetZTer(double aVal){ mLocZTer = aVal;}



double * cEqAppui_X_C2MDPol3::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "XIm") return & mLocXIm;
   if (aName == "XTer") return & mLocXTer;
   if (aName == "YIm") return & mLocYIm;
   if (aName == "YTer") return & mLocYTer;
   if (aName == "ZTer") return & mLocZTer;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_X_C2MDPol3::mTheAuto("cEqAppui_X_C2MDPol3",cEqAppui_X_C2MDPol3::Alloc);


cElCompiledFonc *  cEqAppui_X_C2MDPol3::Alloc()
{  return new cEqAppui_X_C2MDPol3();
}

