//--------------------------------------------------------------------------------------------------
// $Id $
//
// MuonEffectiveArea
//
// Helper Class for storing effective areas
//
// Authors: S.Xie, E. DiMarco
//--------------------------------------------------------------------------------------------------


/// --> NOTE if you want to use this class as standalone without the CMSSW part 
///  you need to uncomment the below line and compile normally with scramv1 b 
///  Then you need just to load it in your root macro the lib with the correct path
//#define STANDALONE   // <---- this line

#ifndef MuonEffectiveArea_H
#define MuonEffectiveArea_H

#ifndef STANDALONE
#endif

using namespace std;

class MuonEffectiveArea{
 public:
  MuonEffectiveArea();
  ~MuonEffectiveArea(); 
  
  enum MuonEffectiveAreaType {
    kMuTrkIso03, 
    kMuEcalIso03, 
    kMuHcalIso03, 
    kMuTrkIso05, 
    kMuEcalIso05, 
    kMuHcalIso05, 
    kMuChargedIso03, 
    kMuGammaIso03, 
    kMuNeutralHadronIso03, 
    kMuGammaAndNeutralHadronIso03,
    kMuGammaIso03Tight, 
    kMuNeutralHadronIso03Tight, 
    kMuGammaAndNeutralHadronIso03Tight,
    kMuChargedIso04, 
    kMuGammaIso04, 
    kMuNeutralHadronIso04, 
    kMuGammaAndNeutralHadronIso04,
    kMuGammaIso04Tight, 
    kMuNeutralHadronIso04Tight, 
    kMuGammaAndNeutralHadronIso04Tight,
    kMuGammaIsoDR0p0To0p1,
    kMuGammaIsoDR0p1To0p2,
    kMuGammaIsoDR0p2To0p3,
    kMuGammaIsoDR0p3To0p4,
    kMuGammaIsoDR0p4To0p5,
    kMuNeutralHadronIsoDR0p0To0p1,
    kMuNeutralHadronIsoDR0p1To0p2,
    kMuNeutralHadronIsoDR0p2To0p3,
    kMuNeutralHadronIsoDR0p3To0p4,
    kMuNeutralHadronIsoDR0p4To0p5,
    kMuGammaIso05,
    kMuNeutralIso05
  };
  
  enum MuonEffectiveAreaTarget {
    kMuEANoCorr,
    kMuEAData2011,
    kMuEASummer11MC,
    kMuEAFall11MC,
    kMuEAData2012
  };

  static Double_t GetMuonEffectiveArea(MuonEffectiveAreaType type, Double_t SCEta, 
				       MuonEffectiveAreaTarget EffectiveAreaTarget = kMuEAData2011) {
    
    Double_t EffectiveArea = 0;
    
    
    if (EffectiveAreaTarget == kMuEANoCorr) {
      return 0.0;
    }
    
    //2012 Data Effective Areas
    else if (EffectiveAreaTarget == kMuEAData2012) {
      if (type == kMuGammaIso04){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.50419;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.30582;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.19765;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.28723;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.52529;
	if (fabs(SCEta) >= 2.3 )                        EffectiveArea = 0.48818;
      }
      if (type == kMuNeutralHadronIso04){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.16580;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.25904;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.24695;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.22021;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.34045;
	if (fabs(SCEta) >= 2.3 )                        EffectiveArea = 0.21592;
      }
      if (type == kMuGammaAndNeutralHadronIso04){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.674;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.565;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.442;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.515;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.821;
	if (fabs(SCEta) >= 2.3 )                        EffectiveArea = 0.660;
      }
      if (type == kMuGammaAndNeutralHadronIso03){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.382;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.317;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.242;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.326;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.462;
	if (fabs(SCEta) >= 2.3 )                        EffectiveArea = 0.372;
      }
      if (type == kMuGammaAndNeutralHadronIso04Tight){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.340;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.310;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.315;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.415;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.658;
	if (fabs(SCEta) >= 2.3 )                        EffectiveArea = 0.405;
      }
      if (type == kMuGammaAndNeutralHadronIso03Tight){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.207;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.183;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.177;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.271;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.348;
	if (fabs(SCEta) >= 2.3 )                        EffectiveArea = 0.246;
      }
    }

    //2011 Data Effective Areas
    else if (EffectiveAreaTarget == kMuEAData2011) {
      
      if (type == kMuGammaIsoDR0p0To0p1) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.004;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.002;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.002;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.3 ) EffectiveArea = 0.005;
      }
      if (type == kMuGammaIsoDR0p1To0p2) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.011;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.005;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 2.3 ) EffectiveArea = 0.011;
      }
      if (type == kMuGammaIsoDR0p2To0p3) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.023;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.016;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.010;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.014;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.017;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.021;
      }
      if (type == kMuGammaIsoDR0p3To0p4) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.036;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.026;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.017;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.023;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.028;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.032;
      }
      if (type == kMuGammaIsoDR0p4To0p5) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.051;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.037;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.028;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.033;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.042;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.052;
      }
      if (type == kMuNeutralHadronIsoDR0p0To0p1) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.002;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.001;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.001;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.001;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.005;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.007;
      }
      if (type == kMuNeutralHadronIsoDR0p1To0p2) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.005;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.010;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.014;
      }
      if (type == kMuNeutralHadronIsoDR0p2To0p3) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.010;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.015;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.017;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.017;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.019;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.024;
      }
      if (type == kMuNeutralHadronIsoDR0p3To0p4) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.015;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.021;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.024;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.032;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.038;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.038;
      }
      if (type == kMuNeutralHadronIsoDR0p4To0p5) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.020;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.026;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.033;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.045;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.051;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.114;
      }
      /// BEGIN FROM SLIDE 11 OF  https://indico.cern.ch/getFile.py/access?contribId=1&resId=0&materialId=slides&confId=188494
      /// NOTE: to be used with the rho from ALL pf candidates within |eta|<2.5
      if (type == kMuGammaIso03){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.049;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.5 ) EffectiveArea = 0.030;
	if (fabs(SCEta) >= 1.5 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.022;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.034;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.041;
	if (fabs(SCEta) >= 2.3 )                      EffectiveArea = 0.048;
      }
      if (type == kMuGammaIso04){
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.085;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.5 ) EffectiveArea = 0.052;
	if (fabs(SCEta) >= 1.5 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.038;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.055;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.070;
	if (fabs(SCEta) >= 2.3 )                      EffectiveArea = 0.081;
      }
      if (type == kMuNeutralHadronIso03){
          if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.027;
          if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.5 ) EffectiveArea = 0.039;
          if (fabs(SCEta) >= 1.5 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.044;
          if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.047;
          if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.055;
          if (fabs(SCEta) >= 2.3 )                      EffectiveArea = 0.065;
      }
      if (type == kMuNeutralHadronIso04){
          if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.046;
          if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.5 ) EffectiveArea = 0.067;
          if (fabs(SCEta) >= 1.5 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.074;
          if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.083;
          if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.095;
          if (fabs(SCEta) >= 2.3 )                      EffectiveArea = 0.105;
      }
      if (type == kMuGammaAndNeutralHadronIso03){
          if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.076;
          if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.5 ) EffectiveArea = 0.070;
          if (fabs(SCEta) >= 1.5 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.067;
          if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.082;
          if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.097;
          if (fabs(SCEta) >= 2.3 )                      EffectiveArea = 0.115;
      }
      if (type == kMuGammaAndNeutralHadronIso04){
          if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.132;
          if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.5 ) EffectiveArea = 0.120;
          if (fabs(SCEta) >= 1.5 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.114;
          if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.139;
          if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.168;
          if (fabs(SCEta) >= 2.3 )                      EffectiveArea = 0.189;
      }
      /// END FROM SLIDE 11 OF  https://indico.cern.ch/getFile.py/access?contribId=1&resId=0&materialId=slides&confId=188494

      if (type == kMuGammaIso05){
 	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.05317;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.03502;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.03689;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.05221;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.06668;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.0744;
      }
      if (type == kMuNeutralIso05) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.06408;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.07557;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.08864;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.11492;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.13784;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.18745;
      }
    } 
    
    //Summer11 MC Effective Areas
    else if (EffectiveAreaTarget == kMuEASummer11MC) {
      if (type == kMuGammaIsoDR0p0To0p1) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.006;
      }
      if (type == kMuGammaIsoDR0p1To0p2) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.012;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.007;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.006;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.019;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.015;
      }
      if (type == kMuGammaIsoDR0p2To0p3) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.023;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.018;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.013;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.016;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.024;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.036;
      }
      if (type == kMuGammaIsoDR0p3To0p4) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.038;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.027;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.019;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.033;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.041;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.062;
      }
      if (type == kMuGammaIsoDR0p4To0p5) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.055;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.038;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.032;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.052;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.066;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.093;
      }
      if (type == kMuNeutralHadronIsoDR0p0To0p1) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.002;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.005;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.000;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.003;
      }
      if (type == kMuNeutralHadronIsoDR0p1To0p2) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.005;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.006;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.013;
      }
      if (type == kMuNeutralHadronIsoDR0p2To0p3) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.013;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.015;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.016;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.020;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.024;
      }
      if (type == kMuNeutralHadronIsoDR0p3To0p4) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.012;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.019;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.021;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.025;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.030;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.044;
      }
      if (type == kMuNeutralHadronIsoDR0p4To0p5) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.016;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.026;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.030;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.038;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.048;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.118;
      }
    } 
  
    //Fall11 MC Effective Areas
    else if (EffectiveAreaTarget == kMuEAFall11MC) {
      if (type == kMuGammaIsoDR0p0To0p1) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.004;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.002;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.003;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.003;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.011;
      }
      if (type == kMuGammaIsoDR0p1To0p2) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.012;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.008;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.006;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.012;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.019;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.024;
      }
      if (type == kMuGammaIsoDR0p2To0p3) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.026;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.020;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.012;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.022;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.027;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.034;
      }
      if (type == kMuGammaIsoDR0p3To0p4) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.042;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.033;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.022;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.036;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.059;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.068;
      }
      if (type == kMuGammaIsoDR0p4To0p5) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.060;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.043;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.036;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.055;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.092;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.115;
      }
      if (type == kMuNeutralHadronIsoDR0p0To0p1) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.002;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.004;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.004;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.004;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.010;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.014;
      }
      if (type == kMuNeutralHadronIsoDR0p1To0p2) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 )   EffectiveArea = 0.005;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.007;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 )   EffectiveArea = 0.009;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 )   EffectiveArea = 0.015;
	if (fabs(SCEta) >= 2.3  )                       EffectiveArea = 0.017;
      }
      if (type == kMuNeutralHadronIsoDR0p2To0p3) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.009;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.015;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.016;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.018;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.022;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.026;
      }
      if (type == kMuNeutralHadronIsoDR0p3To0p4) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.013;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.021;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.026;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.032;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.037;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.042;
      }
      if (type == kMuNeutralHadronIsoDR0p4To0p5) {
	if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.017;
	if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.026;
	if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.035;
	if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.046;
	if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.063;
	if (fabs(SCEta) >= 2.3  ) EffectiveArea = 0.135;
      }
    }

    
    return EffectiveArea;  
  }
};

#endif
