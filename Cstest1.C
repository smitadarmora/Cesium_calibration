#define Cstest1_cxx
#include "Cstest1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
using namespace std;

Int_t chanOfInterest[6]={5,4,3,2,12,13}; //C10,D4,E1,E2 pmts
float a[6]={0};
float b[6]={0};
float a1[6]={0};
float b1[6]={0};
//float integralA[6]={0};
//float integralB[6]={0};
//int widthA[6]={0};
//int widthB[6]={0};
float trigdata[2]={0};
float threshOverLeakage[6]={800,800,200,200,500,500};
float TempValB=0;
int pedLowerLimit=0,pedUpperLimit=400,sigLowerLimit=400,sigUpperLimit=18000;
Int_t aentry=0,bentry=0;
Int_t PMT;


void Cstest1::Loop(float pedestal[], float integralA[], float widthA[], float integralB[], float widthB[],char direction,int ModNum)
//void Cstest1::Loop()
{

//  Long64_t nentries = fChain->GetEntriesFast();
//  Long64_t nb=0;

  for (int i=0;i<6;i++) //loop on the interesting channels 
  {
//cout<<"i = "<<i<<endl;
//    float pedestal[6]={0};
    int Range[2]={0},PMTwidthA=0,PMTwidthB=0;
    float threshold=0,PMTpedestal=0,PMTintegralA=0,PMTintegralB=0;
    float firstThreshold[6]={0};
    PMT = chanOfInterest[i];
    pedestal[i] = GetPedestal(pedLowerLimit,pedUpperLimit,PMT);//get the pedestal value for the pmt
    //cout<<"pedestal[i] = "<<pedestal[i]<<"\tthreshOverLeakage before = "<<threshOverLeakage[i]<<endl;

 PMTpedestal = pedestal[i];
 
 
 firstThreshold[i]=GetfirstThreshold(sigLowerLimit,sigUpperLimit,PMT,&PMTpedestal);//get first threshold value of pmt
 if (PMT == 2 || PMT ==3)
   { 
threshold = threshOverLeakage[i] + pedestal[i]; 
   }
 else
   {
    threshold = firstThreshold[i] + pedestal[i];
   }
    //threshold = threshOverLeakage[i] + pedestal[i];//calculate huge threshold
    //cout<<"threshOverLeakage after = "<<threshold<<endl;
    TotalSignalRange(threshold,sigLowerLimit,sigUpperLimit,Range,PMT);//calculate range to integrate from huge threshold
    //PMTpedestal = pedestal[i];
    SignalCalculator(Range,PMT,direction,&PMTpedestal,&PMTintegralA,&PMTintegralB,&PMTwidthA,&PMTwidthB,ModNum);//calc intA&B and widthA&B
    integralA[i] = PMTintegralA;
    integralB[i] = PMTintegralB;
    widthA[i] = PMTwidthA;
    widthB[i] = PMTwidthB;
  }

}

