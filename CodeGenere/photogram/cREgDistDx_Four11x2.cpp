// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cREgDistDx_Four11x2.h"


cREgDistDx_Four11x2::cREgDistDx_Four11x2():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,16));
   Close(false);
}



void cREgDistDx_Four11x2::ComputeVal()
{
   double tmp0_ = mLocRegDistu1_x - mLocFour11x2_State_1_0;
   double tmp1_ = (tmp0_) / mLocFour11x2_State_0_0;
   double tmp2_ = mLocRegDistu1_y - mLocFour11x2_State_2_0;
   double tmp3_ = (tmp2_) / mLocFour11x2_State_0_0;
   double tmp4_ = mCompCoord[9];
   double tmp5_ = tmp1_ - tmp4_;
   double tmp6_ = mCompCoord[10];
   double tmp7_ = tmp3_ - tmp6_;
   double tmp8_ = (tmp5_) * (tmp5_);
   double tmp9_ = (tmp7_) * (tmp7_);
   double tmp10_ = tmp8_ + tmp9_;
   double tmp11_ = (tmp10_) * (tmp10_);
   double tmp12_ = tmp11_ * (tmp10_);
   double tmp13_ = tmp12_ * (tmp10_);
   double tmp14_ = mCompCoord[3];
   double tmp15_ = 1 + tmp14_;
   double tmp16_ = mCompCoord[4];
   double tmp17_ = mCompCoord[5];
   double tmp18_ = tmp17_ * 2;
   double tmp19_ = mLocRegDistu2_x - mLocFour11x2_State_1_0;
   double tmp20_ = (tmp19_) / mLocFour11x2_State_0_0;
   double tmp21_ = mCompCoord[6];
   double tmp22_ = mLocRegDistu2_y - mLocFour11x2_State_2_0;
   double tmp23_ = (tmp22_) / mLocFour11x2_State_0_0;
   double tmp24_ = mCompCoord[7];
   double tmp25_ = mCompCoord[11];
   double tmp26_ = tmp20_ - tmp4_;
   double tmp27_ = tmp23_ - tmp6_;
   double tmp28_ = mCompCoord[12];
   double tmp29_ = (tmp26_) * (tmp26_);
   double tmp30_ = (tmp27_) * (tmp27_);
   double tmp31_ = tmp29_ + tmp30_;
   double tmp32_ = mCompCoord[13];
   double tmp33_ = (tmp31_) * (tmp31_);
   double tmp34_ = mCompCoord[14];
   double tmp35_ = tmp33_ * (tmp31_);
   double tmp36_ = mCompCoord[15];
   double tmp37_ = tmp35_ * (tmp31_);
   double tmp38_ = (tmp1_) * (tmp3_);
   double tmp39_ = (tmp3_) * (tmp3_);
   double tmp40_ = (tmp1_) * (tmp1_);
   double tmp41_ = tmp25_ * (tmp10_);
   double tmp42_ = tmp28_ * tmp11_;
   double tmp43_ = tmp41_ + tmp42_;
   double tmp44_ = tmp32_ * tmp12_;
   double tmp45_ = tmp43_ + tmp44_;
   double tmp46_ = tmp34_ * tmp13_;
   double tmp47_ = tmp45_ + tmp46_;
   double tmp48_ = tmp13_ * (tmp10_);
   double tmp49_ = tmp36_ * tmp48_;
   double tmp50_ = tmp47_ + tmp49_;
   double tmp51_ = 1 - tmp14_;
   double tmp52_ = (tmp20_) * (tmp23_);
   double tmp53_ = tmp21_ * 2;
   double tmp54_ = (tmp23_) * (tmp23_);
   double tmp55_ = mCompCoord[8];
   double tmp56_ = (tmp20_) * (tmp20_);
   double tmp57_ = tmp25_ * (tmp31_);
   double tmp58_ = tmp28_ * tmp33_;
   double tmp59_ = tmp57_ + tmp58_;
   double tmp60_ = tmp32_ * tmp35_;
   double tmp61_ = tmp59_ + tmp60_;
   double tmp62_ = tmp34_ * tmp37_;
   double tmp63_ = tmp61_ + tmp62_;
   double tmp64_ = tmp37_ * (tmp31_);
   double tmp65_ = tmp36_ * tmp64_;
   double tmp66_ = tmp63_ + tmp65_;

  mVal[0] = (mLocFour11x2_State_1_0 + (((tmp15_) * (tmp1_) + tmp16_ * (tmp3_)) - tmp18_ * tmp40_ + tmp21_ * tmp38_ + tmp24_ * tmp39_ + (tmp5_) * (tmp50_)) * mLocFour11x2_State_0_0) - (mLocFour11x2_State_1_0 + (((tmp15_) * (tmp20_) + tmp16_ * (tmp23_)) - tmp18_ * tmp56_ + tmp21_ * tmp52_ + tmp24_ * tmp54_ + (tmp26_) * (tmp66_)) * mLocFour11x2_State_0_0) - mLocRegDistu3_x;

  mVal[1] = (mLocFour11x2_State_2_0 + (((tmp51_) * (tmp3_) + tmp16_ * (tmp1_) + tmp17_ * tmp38_) - tmp53_ * tmp39_ + tmp55_ * tmp40_ + (tmp7_) * (tmp50_)) * mLocFour11x2_State_0_0) - (mLocFour11x2_State_2_0 + (((tmp51_) * (tmp23_) + tmp16_ * (tmp20_) + tmp17_ * tmp52_) - tmp53_ * tmp54_ + tmp55_ * tmp56_ + (tmp27_) * (tmp66_)) * mLocFour11x2_State_0_0) - mLocRegDistu3_y;

}


void cREgDistDx_Four11x2::ComputeValDeriv()
{
   double tmp0_ = mLocRegDistu1_x - mLocFour11x2_State_1_0;
   double tmp1_ = (tmp0_) / mLocFour11x2_State_0_0;
   double tmp2_ = mLocRegDistu1_y - mLocFour11x2_State_2_0;
   double tmp3_ = (tmp2_) / mLocFour11x2_State_0_0;
   double tmp4_ = mCompCoord[9];
   double tmp5_ = tmp1_ - tmp4_;
   double tmp6_ = mCompCoord[10];
   double tmp7_ = tmp3_ - tmp6_;
   double tmp8_ = (tmp5_) * (tmp5_);
   double tmp9_ = (tmp7_) * (tmp7_);
   double tmp10_ = tmp8_ + tmp9_;
   double tmp11_ = (tmp10_) * (tmp10_);
   double tmp12_ = tmp11_ * (tmp10_);
   double tmp13_ = tmp12_ * (tmp10_);
   double tmp14_ = mCompCoord[3];
   double tmp15_ = 1 + tmp14_;
   double tmp16_ = mCompCoord[4];
   double tmp17_ = mCompCoord[5];
   double tmp18_ = tmp17_ * 2;
   double tmp19_ = mLocRegDistu2_x - mLocFour11x2_State_1_0;
   double tmp20_ = (tmp19_) / mLocFour11x2_State_0_0;
   double tmp21_ = mCompCoord[6];
   double tmp22_ = mLocRegDistu2_y - mLocFour11x2_State_2_0;
   double tmp23_ = (tmp22_) / mLocFour11x2_State_0_0;
   double tmp24_ = mCompCoord[7];
   double tmp25_ = mCompCoord[11];
   double tmp26_ = tmp20_ - tmp4_;
   double tmp27_ = tmp23_ - tmp6_;
   double tmp28_ = mCompCoord[12];
   double tmp29_ = (tmp26_) * (tmp26_);
   double tmp30_ = (tmp27_) * (tmp27_);
   double tmp31_ = tmp29_ + tmp30_;
   double tmp32_ = mCompCoord[13];
   double tmp33_ = (tmp31_) * (tmp31_);
   double tmp34_ = mCompCoord[14];
   double tmp35_ = tmp33_ * (tmp31_);
   double tmp36_ = mCompCoord[15];
   double tmp37_ = tmp35_ * (tmp31_);
   double tmp38_ = (tmp1_) * (tmp1_);
   double tmp39_ = (tmp20_) * (tmp20_);
   double tmp40_ = (tmp1_) * (tmp3_);
   double tmp41_ = (tmp20_) * (tmp23_);
   double tmp42_ = (tmp3_) * (tmp3_);
   double tmp43_ = (tmp23_) * (tmp23_);
   double tmp44_ = tmp25_ * (tmp10_);
   double tmp45_ = tmp28_ * tmp11_;
   double tmp46_ = tmp44_ + tmp45_;
   double tmp47_ = tmp32_ * tmp12_;
   double tmp48_ = tmp46_ + tmp47_;
   double tmp49_ = tmp34_ * tmp13_;
   double tmp50_ = tmp48_ + tmp49_;
   double tmp51_ = tmp13_ * (tmp10_);
   double tmp52_ = tmp36_ * tmp51_;
   double tmp53_ = tmp50_ + tmp52_;
   double tmp54_ = -(1);
   double tmp55_ = tmp54_ * (tmp5_);
   double tmp56_ = tmp55_ + tmp55_;
   double tmp57_ = (tmp56_) * (tmp10_);
   double tmp58_ = tmp57_ + tmp57_;
   double tmp59_ = (tmp58_) * (tmp10_);
   double tmp60_ = (tmp56_) * tmp11_;
   double tmp61_ = tmp59_ + tmp60_;
   double tmp62_ = (tmp61_) * (tmp10_);
   double tmp63_ = (tmp56_) * tmp12_;
   double tmp64_ = tmp62_ + tmp63_;
   double tmp65_ = tmp25_ * (tmp31_);
   double tmp66_ = tmp28_ * tmp33_;
   double tmp67_ = tmp65_ + tmp66_;
   double tmp68_ = tmp32_ * tmp35_;
   double tmp69_ = tmp67_ + tmp68_;
   double tmp70_ = tmp34_ * tmp37_;
   double tmp71_ = tmp69_ + tmp70_;
   double tmp72_ = tmp37_ * (tmp31_);
   double tmp73_ = tmp36_ * tmp72_;
   double tmp74_ = tmp71_ + tmp73_;
   double tmp75_ = tmp54_ * (tmp26_);
   double tmp76_ = tmp75_ + tmp75_;
   double tmp77_ = (tmp76_) * (tmp31_);
   double tmp78_ = tmp77_ + tmp77_;
   double tmp79_ = (tmp78_) * (tmp31_);
   double tmp80_ = (tmp76_) * tmp33_;
   double tmp81_ = tmp79_ + tmp80_;
   double tmp82_ = (tmp81_) * (tmp31_);
   double tmp83_ = (tmp76_) * tmp35_;
   double tmp84_ = tmp82_ + tmp83_;
   double tmp85_ = tmp54_ * (tmp7_);
   double tmp86_ = tmp85_ + tmp85_;
   double tmp87_ = (tmp86_) * (tmp10_);
   double tmp88_ = tmp87_ + tmp87_;
   double tmp89_ = (tmp88_) * (tmp10_);
   double tmp90_ = (tmp86_) * tmp11_;
   double tmp91_ = tmp89_ + tmp90_;
   double tmp92_ = (tmp91_) * (tmp10_);
   double tmp93_ = (tmp86_) * tmp12_;
   double tmp94_ = tmp92_ + tmp93_;
   double tmp95_ = tmp54_ * (tmp27_);
   double tmp96_ = tmp95_ + tmp95_;
   double tmp97_ = (tmp96_) * (tmp31_);
   double tmp98_ = tmp97_ + tmp97_;
   double tmp99_ = (tmp98_) * (tmp31_);
   double tmp100_ = (tmp96_) * tmp33_;
   double tmp101_ = tmp99_ + tmp100_;
   double tmp102_ = (tmp101_) * (tmp31_);
   double tmp103_ = (tmp96_) * tmp35_;
   double tmp104_ = tmp102_ + tmp103_;
   double tmp105_ = 1 - tmp14_;
   double tmp106_ = tmp21_ * 2;
   double tmp107_ = mCompCoord[8];
   double tmp108_ = (tmp1_) * mLocFour11x2_State_0_0;
   double tmp109_ = (tmp20_) * mLocFour11x2_State_0_0;
   double tmp110_ = tmp108_ - tmp109_;
   double tmp111_ = tmp40_ * mLocFour11x2_State_0_0;
   double tmp112_ = tmp41_ * mLocFour11x2_State_0_0;
   double tmp113_ = tmp111_ - tmp112_;
   double tmp114_ = (tmp56_) * tmp25_;
   double tmp115_ = (tmp58_) * tmp28_;
   double tmp116_ = tmp114_ + tmp115_;
   double tmp117_ = (tmp61_) * tmp32_;
   double tmp118_ = tmp116_ + tmp117_;
   double tmp119_ = (tmp64_) * tmp34_;
   double tmp120_ = tmp118_ + tmp119_;
   double tmp121_ = (tmp64_) * (tmp10_);
   double tmp122_ = (tmp56_) * tmp13_;
   double tmp123_ = tmp121_ + tmp122_;
   double tmp124_ = (tmp123_) * tmp36_;
   double tmp125_ = tmp120_ + tmp124_;
   double tmp126_ = (tmp76_) * tmp25_;
   double tmp127_ = (tmp78_) * tmp28_;
   double tmp128_ = tmp126_ + tmp127_;
   double tmp129_ = (tmp81_) * tmp32_;
   double tmp130_ = tmp128_ + tmp129_;
   double tmp131_ = (tmp84_) * tmp34_;
   double tmp132_ = tmp130_ + tmp131_;
   double tmp133_ = (tmp84_) * (tmp31_);
   double tmp134_ = (tmp76_) * tmp37_;
   double tmp135_ = tmp133_ + tmp134_;
   double tmp136_ = (tmp135_) * tmp36_;
   double tmp137_ = tmp132_ + tmp136_;
   double tmp138_ = tmp54_ * (tmp53_);
   double tmp139_ = (tmp86_) * tmp25_;
   double tmp140_ = (tmp88_) * tmp28_;
   double tmp141_ = tmp139_ + tmp140_;
   double tmp142_ = (tmp91_) * tmp32_;
   double tmp143_ = tmp141_ + tmp142_;
   double tmp144_ = (tmp94_) * tmp34_;
   double tmp145_ = tmp143_ + tmp144_;
   double tmp146_ = (tmp94_) * (tmp10_);
   double tmp147_ = (tmp86_) * tmp13_;
   double tmp148_ = tmp146_ + tmp147_;
   double tmp149_ = (tmp148_) * tmp36_;
   double tmp150_ = tmp145_ + tmp149_;
   double tmp151_ = tmp54_ * (tmp74_);
   double tmp152_ = (tmp96_) * tmp25_;
   double tmp153_ = (tmp98_) * tmp28_;
   double tmp154_ = tmp152_ + tmp153_;
   double tmp155_ = (tmp101_) * tmp32_;
   double tmp156_ = tmp154_ + tmp155_;
   double tmp157_ = (tmp104_) * tmp34_;
   double tmp158_ = tmp156_ + tmp157_;
   double tmp159_ = (tmp104_) * (tmp31_);
   double tmp160_ = (tmp96_) * tmp37_;
   double tmp161_ = tmp159_ + tmp160_;
   double tmp162_ = (tmp161_) * tmp36_;
   double tmp163_ = tmp158_ + tmp162_;

  mVal[0] = (mLocFour11x2_State_1_0 + (((tmp15_) * (tmp1_) + tmp16_ * (tmp3_)) - tmp18_ * tmp38_ + tmp21_ * tmp40_ + tmp24_ * tmp42_ + (tmp5_) * (tmp53_)) * mLocFour11x2_State_0_0) - (mLocFour11x2_State_1_0 + (((tmp15_) * (tmp20_) + tmp16_ * (tmp23_)) - tmp18_ * tmp39_ + tmp21_ * tmp41_ + tmp24_ * tmp43_ + (tmp26_) * (tmp74_)) * mLocFour11x2_State_0_0) - mLocRegDistu3_x;

  mCompDer[0][0] = 0;
  mCompDer[0][1] = 0;
  mCompDer[0][2] = 0;
  mCompDer[0][3] = tmp110_;
  mCompDer[0][4] = (tmp3_) * mLocFour11x2_State_0_0 - (tmp23_) * mLocFour11x2_State_0_0;
  mCompDer[0][5] = -(2 * tmp38_) * mLocFour11x2_State_0_0 - -(2 * tmp39_) * mLocFour11x2_State_0_0;
  mCompDer[0][6] = tmp113_;
  mCompDer[0][7] = tmp42_ * mLocFour11x2_State_0_0 - tmp43_ * mLocFour11x2_State_0_0;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = (tmp138_ + (tmp125_) * (tmp5_)) * mLocFour11x2_State_0_0 - (tmp151_ + (tmp137_) * (tmp26_)) * mLocFour11x2_State_0_0;
  mCompDer[0][10] = (tmp150_) * (tmp5_) * mLocFour11x2_State_0_0 - (tmp163_) * (tmp26_) * mLocFour11x2_State_0_0;
  mCompDer[0][11] = (tmp10_) * (tmp5_) * mLocFour11x2_State_0_0 - (tmp31_) * (tmp26_) * mLocFour11x2_State_0_0;
  mCompDer[0][12] = tmp11_ * (tmp5_) * mLocFour11x2_State_0_0 - tmp33_ * (tmp26_) * mLocFour11x2_State_0_0;
  mCompDer[0][13] = tmp12_ * (tmp5_) * mLocFour11x2_State_0_0 - tmp35_ * (tmp26_) * mLocFour11x2_State_0_0;
  mCompDer[0][14] = tmp13_ * (tmp5_) * mLocFour11x2_State_0_0 - tmp37_ * (tmp26_) * mLocFour11x2_State_0_0;
  mCompDer[0][15] = tmp51_ * (tmp5_) * mLocFour11x2_State_0_0 - tmp72_ * (tmp26_) * mLocFour11x2_State_0_0;
  mVal[1] = (mLocFour11x2_State_2_0 + (((tmp105_) * (tmp3_) + tmp16_ * (tmp1_) + tmp17_ * tmp40_) - tmp106_ * tmp42_ + tmp107_ * tmp38_ + (tmp7_) * (tmp53_)) * mLocFour11x2_State_0_0) - (mLocFour11x2_State_2_0 + (((tmp105_) * (tmp23_) + tmp16_ * (tmp20_) + tmp17_ * tmp41_) - tmp106_ * tmp43_ + tmp107_ * tmp39_ + (tmp27_) * (tmp74_)) * mLocFour11x2_State_0_0) - mLocRegDistu3_y;

  mCompDer[1][0] = 0;
  mCompDer[1][1] = 0;
  mCompDer[1][2] = 0;
  mCompDer[1][3] = tmp54_ * (tmp3_) * mLocFour11x2_State_0_0 - tmp54_ * (tmp23_) * mLocFour11x2_State_0_0;
  mCompDer[1][4] = tmp110_;
  mCompDer[1][5] = tmp113_;
  mCompDer[1][6] = -(2 * tmp42_) * mLocFour11x2_State_0_0 - -(2 * tmp43_) * mLocFour11x2_State_0_0;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = tmp38_ * mLocFour11x2_State_0_0 - tmp39_ * mLocFour11x2_State_0_0;
  mCompDer[1][9] = (tmp125_) * (tmp7_) * mLocFour11x2_State_0_0 - (tmp137_) * (tmp27_) * mLocFour11x2_State_0_0;
  mCompDer[1][10] = (tmp138_ + (tmp150_) * (tmp7_)) * mLocFour11x2_State_0_0 - (tmp151_ + (tmp163_) * (tmp27_)) * mLocFour11x2_State_0_0;
  mCompDer[1][11] = (tmp10_) * (tmp7_) * mLocFour11x2_State_0_0 - (tmp31_) * (tmp27_) * mLocFour11x2_State_0_0;
  mCompDer[1][12] = tmp11_ * (tmp7_) * mLocFour11x2_State_0_0 - tmp33_ * (tmp27_) * mLocFour11x2_State_0_0;
  mCompDer[1][13] = tmp12_ * (tmp7_) * mLocFour11x2_State_0_0 - tmp35_ * (tmp27_) * mLocFour11x2_State_0_0;
  mCompDer[1][14] = tmp13_ * (tmp7_) * mLocFour11x2_State_0_0 - tmp37_ * (tmp27_) * mLocFour11x2_State_0_0;
  mCompDer[1][15] = tmp51_ * (tmp7_) * mLocFour11x2_State_0_0 - tmp72_ * (tmp27_) * mLocFour11x2_State_0_0;
}


void cREgDistDx_Four11x2::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cREgDistDx_Four11x2 Has no Der Sec");
}

void cREgDistDx_Four11x2::SetFour11x2_State_0_0(double aVal){ mLocFour11x2_State_0_0 = aVal;}
void cREgDistDx_Four11x2::SetFour11x2_State_1_0(double aVal){ mLocFour11x2_State_1_0 = aVal;}
void cREgDistDx_Four11x2::SetFour11x2_State_2_0(double aVal){ mLocFour11x2_State_2_0 = aVal;}
void cREgDistDx_Four11x2::SetRegDistu1_x(double aVal){ mLocRegDistu1_x = aVal;}
void cREgDistDx_Four11x2::SetRegDistu1_y(double aVal){ mLocRegDistu1_y = aVal;}
void cREgDistDx_Four11x2::SetRegDistu2_x(double aVal){ mLocRegDistu2_x = aVal;}
void cREgDistDx_Four11x2::SetRegDistu2_y(double aVal){ mLocRegDistu2_y = aVal;}
void cREgDistDx_Four11x2::SetRegDistu3_x(double aVal){ mLocRegDistu3_x = aVal;}
void cREgDistDx_Four11x2::SetRegDistu3_y(double aVal){ mLocRegDistu3_y = aVal;}



double * cREgDistDx_Four11x2::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "Four11x2_State_0_0") return & mLocFour11x2_State_0_0;
   if (aName == "Four11x2_State_1_0") return & mLocFour11x2_State_1_0;
   if (aName == "Four11x2_State_2_0") return & mLocFour11x2_State_2_0;
   if (aName == "RegDistu1_x") return & mLocRegDistu1_x;
   if (aName == "RegDistu1_y") return & mLocRegDistu1_y;
   if (aName == "RegDistu2_x") return & mLocRegDistu2_x;
   if (aName == "RegDistu2_y") return & mLocRegDistu2_y;
   if (aName == "RegDistu3_x") return & mLocRegDistu3_x;
   if (aName == "RegDistu3_y") return & mLocRegDistu3_y;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cREgDistDx_Four11x2::mTheAuto("cREgDistDx_Four11x2",cREgDistDx_Four11x2::Alloc);


cElCompiledFonc *  cREgDistDx_Four11x2::Alloc()
{  return new cREgDistDx_Four11x2();
}

