


#include <iostream>
#include <fstream>
#include <TROOT.h>
#include <TFile.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TLegend.h>
#include "Cstest1.C"
#include <vector>
using namespace std;


//void ModuleLoop(TString run1,TString run2,TString run3)
void ModuleLoop()
{

//  gROOT->LoadMacro("ATLAS_Style/atlasstyle-00-03-03/AtlasStyle.C");
//  SetAtlasStyle();

  float Xaxis[64]={0};
// PEDESTAL ARRAYS
  float Yaxis_pmt5pedestal[64] = {0};
  float Yaxis_pmt4pedestal[64] = {0};
  float Yaxis_pmt3pedestal[64] = {0};
  float Yaxis_pmt2pedestal[64] = {0};
  float Yaxis_pmt12pedestal[64] = {0};
  float Yaxis_pmt13pedestal[64] = {0};
  
//INTEGRAL ARRAY
float Yaxis_pmt5Aintegral[64] = {0};
float Yaxis_pmt4Aintegral[64] = {0};
float Yaxis_pmt5Bintegral[64] = {0};
float Yaxis_pmt4Bintegral[64] = {0};
float Yaxis_pmt3integral[64] = {0};
float Yaxis_pmt2integral[64] = {0};
float Yaxis_pmt12integral[64] = {0};
 float Yaxis_pmt13integral[64] = {0};

// WIDTH ARRAYS
  float Yaxis_pmt5Awidth[64] = {0};
  float Yaxis_pmt4Awidth[64] = {0};
  float Yaxis_pmt5Bwidth[64] = {0};
  float Yaxis_pmt4Bwidth[64] = {0};
  float Yaxis_pmt3width[64] = {0};
  float Yaxis_pmt2width[64] = {0};
  float Yaxis_pmt12width[64] = {0};
  float Yaxis_pmt13width[64] = {0};
// SIGNAL HEIGHT ARRAYS
  float Yaxis_pmt5Asignal[64] = {0};
  float Yaxis_pmt4Asignal[64] = {0};
  float Yaxis_pmt5Bsignal[64] = {0};
  float Yaxis_pmt4Bsignal[64] = {0};
  float Yaxis_pmt3signal[64] = {0};
  float Yaxis_pmt2signal[64] = {0};
  float Yaxis_pmt12signal[64] = {0};
  float Yaxis_pmt13signal[64] = {0};

// CONSTANT ARRAYS
float Yaxis_pmt5constant[64] = {0};
float Yaxis_pmt4constant[64] = {0};
float Yaxis_pmt3constant[64] = {0};
float Yaxis_pmt2constant[64] = {0};
float Yaxis_pmt12constant[64] = {0};
float Yaxis_pmt13constant[64] = {0};

float pmt5constant[64] = {0};
float pmt4constant[64] = {0};
float pmt3constant[64] = {0};
float pmt2constant[64] = {0};
float pmt12constant[64] = {0};
float pmt13constant[64] = {0};




  float SignalMatrix[64][8] = {{0},{0}};// FINAL SIGNAL MATRIX
  float ConstantMatrix[64][8] = {{0},{0}};// CONSTANT MATRIX
  float AvgDirConstantMatrix[64][6] = {{0},{0}};// FINAL CONSTANT MATRIX (WITH AVERAGED DIRECTIONS)

  int ModulesOff[64] = {0};
  int ModOffInput,h=0,k=0;
  int startmod=0, finmod=0, ModuleNumber=0;
  float J=1;
  char side,direction,outputfilename;
TString run,run1="cs0",run2="cs0",run3="cs0", command="";
  
  string RunNo;

  cout<<"Which SIDE would you like?"<<endl;
  cin>>side;
  RunNo += side;
  cout<<"Which DIRECTION would you like?"<<endl;
  cin>>direction;
  RunNo += "D";
  RunNo += direction;
  cout<<"Which 3 RUNS would you like?"<<endl;
  cin>>run;
 run1 += run;
  cin>>run;
  run2 += run;
  cin>>run;
  run3 += run;
cout<<"run1 = "<<run1<<"\trun2 = "<<run2<<"\trun3 = "<<run3<<endl;
  cout<<"Which MODULES are OFF? Type '0' to exit."<<endl;
  cin>>ModOffInput;
  while (ModOffInput!=0) 
  {
    ModulesOff[h] = ModOffInput;
    cin>>ModOffInput;
    h++;
  }


/*
  for (int input=0;input<4;input++)
  {
    if (input==0) cin>>side;
    if (input==1) cin>>ModuleNumber;
    if (input==2){ cin>>run; run1 += run;}
    if (input==3) cin>>outputfilename;
  }
*/
//    cin>>side>>direction;
/*
  side = 'A';
  direction = '1';
 
//Side A, Direction1 (2010 data) 

  //run1 += 3162;
  //run2 += 3164;
  //run3 += 3175;

//Side A, Direction 2 (2010 data)
  //run1 += 3169;
  //run2 += 3167;
  //run3 += 3172;


//Side C, Direction 1 (2010 data)
  // run1 += 3176;
  //run2 += 3163;
  //run3 += 3173;

//Side C, Direction 2 (2010 data)
  // run1 += 3069;
  // run2 += 3067;
  //run3 += 3072;

//Side C, Direction 1 (2011 data)
  //run1 += 4294;
  //run2 += 4296;
  //run3 += 4307;

//Side C, Direction 2 (2011 data)
  //run1 += 4302;
  //run2 += 4299;
  //run3 += 4304;

//Side A, Direction 2 (2011 data)
  //run1 += 4301;
  //run2 += 4298;
  //run3 += 4303;
 
//Side A, Direction 1 (2011 data)
  run1 += 4293;
  run2 += 4295;
  run3 += 4306;


// ModulesOff[0] = 40;
 // ModulesOff[1] = 58;
// ModulesOff[2] =57;
 // ModulesOff[3] = 57;
 // ModulesOff[4] = 63;
*/
cout<<"run1 = "<<run1<<"\trun2 = "<<run2<<"\trun3 = "<<run3<<endl;

 RunNo += side;
  RunNo += "D";
  RunNo += direction;
  RunNo +="r";
 RunNo += run1;
 RunNo +="r";
 RunNo += run2;
 RunNo +="r";
 RunNo += run3;


  TCanvas *c0 = new TCanvas("c0","C10 - Pmt 5",400,600);
  c0->Divide(2,4);
  TCanvas *c1 = new TCanvas("c1","C10 - Pmt 4",400,600);
  c1->Divide(2,4);
  TCanvas *c2 = new TCanvas("c2","D4 - Pmt 3",600,600);
  c2->Divide(2,3);
  TCanvas *c3 = new TCanvas("c3","D4 - Pmt 2",600,600);
  c3->Divide(2,3);
  TCanvas *c4 = new TCanvas("c4","E1 - Pmt 12",600,600);
  c4->Divide(2,3);
  TCanvas *c5 = new TCanvas("c5","E2 - Pmt 13",600,600);

  c5->Divide(2,3);
  TCanvas *c6 = new TCanvas("c6","constant_allPMT's",400,600);
  c6->Divide(2,3);
 
 



 
  //summing signal values of normal and special cells. A and B are first and second complete signals of C10. The number (4,5,3,2,12,13) corresponds to the PMT number
  float norm5Asigsum=0,spec5Asigsum=0,norm5Bsigsum=0,spec5Bsigsum=0,norm4Asigsum=0,spec4Asigsum=0,norm4Bsigsum=0,spec4Bsigsum=0;//C10 
  int NonZeroNorm5A=0,NonZeroNorm5B=0,NonZeroNorm4A=0,NonZeroNorm4B=0,NonZeroSpec5A=0,NonZeroSpec5B=0,NonZeroSpec4A=0,NonZeroSpec4B=0;
  float Norm5Aavg=0,Norm4Aavg=0,Norm5Bavg=0,Norm4Bavg=0,Spec5Aavg=0,Spec4Aavg=0,Spec5Bavg=0,Spec4Bavg=0;

  float norm3sigsum=0,spec3sigsum=0,norm2sigsum=0,spec2sigsum=0;//D4
  int NonZeroNorm3=0,NonZeroNorm2=0,NonZeroSpec3=0,NonZeroSpec2=0;
  float Norm3avg=0,Norm2avg=0,Spec3avg=0,Spec2avg=0;

  float norm12sigsum=0,norm13sigsum=0;//E1 and E2
  int NonZeroNorm12=0,NonZeroNorm13=0;
  float Norm12avg=0,Norm13avg=0;
  ofstream constants;//write
  ofstream signal;
  constants.open("Constants_Dec7,2012_C2.txt");//write
   signal.open("signal_Dec7,2012_C2.txt");//write signal
  //constants.open("test_constant.txt");//write
  //signal.open("test_signal.txt");//write signal


/*
  if (ModuleNumber==0) 
  {
    startmod=0;
    finmod=64;
  }
  else if (ModuleNumber!=0)
  {
    startmod=ModuleNumber;
    finmod=ModuleNumber+1;
  }
*/
//  for (int j1=startmod;j1<finmod;j1++)

  for (int j1=0;j1<64;j1++)
  {     
          int j=j1+1;
      cout<< "Looping on Module No. "<<j<<'\n';
      Xaxis[j1]=j;
      float pedestal[6]={0};
      float integralA[6]={0};
      float integralB[6]={0};
      float widthA[6]={0};
      float widthB[6]={0};
      float SignalHeightA[6]={0};
      float SignalHeightB[6]={0};
      float firstThreshold[6]={0};

      if (ModulesOff[k]==j)
      {
//        cout<<"\t0\t0\t0\t0\t0\t0\t0\t0"<<endl;
        k++;
        continue;
      }


      Cstest1 *c = new Cstest1(j,run1,run2,run3,side,ModulesOff);
      c->Loop(pedestal,integralA,widthA,integralB,widthB,direction,j);

      if (pedestal[0]!=0) Yaxis_pmt5pedestal[j1] = pedestal[0];
      Yaxis_pmt4pedestal[j1] = pedestal[1];
      Yaxis_pmt3pedestal[j1] = pedestal[2];
      Yaxis_pmt2pedestal[j1] = pedestal[3];
      Yaxis_pmt12pedestal[j1] = pedestal[4];
      Yaxis_pmt13pedestal[j1] = pedestal[5];


      for (int p=0;p<6;p++)
      {
        SignalHeightA[p]=0;
        SignalHeightB[p]=0;
        if (widthA[p]!=0) SignalHeightA[p]=integralA[p]/widthA[p];
        if (widthB[p]!=0) SignalHeightB[p]=integralB[p]/widthB[p];
        if (SignalHeightA[p]<0) SignalHeightA[p]=0;
        if (SignalHeightB[p]<0) SignalHeightB[p]=0;

        //summing normal signals of C10 PMT 5 and 4
        if ((p==0 || p==1) && (j<39 || (j>42 && j<55) || j>58))
        {
          if (SignalHeightA[p]>0)
          {
            if (p==0){ norm5Asigsum += SignalHeightA[p]; NonZeroNorm5A++; }
            if (p==1){ norm4Asigsum += SignalHeightA[p]; NonZeroNorm4A++; }
          }
          if (SignalHeightB[p]>0)
          {
            if (p==0){ norm5Bsigsum += SignalHeightB[p]; NonZeroNorm5B++; }
            if (p==1){ norm4Bsigsum += SignalHeightB[p]; NonZeroNorm4B++; }
          }
        }
        //summing special signals of C10 PMT 5 and 4
        if ((p==0 || p==1) && ((j>=39 && j<=42) || (j>=55 && j<=58)))
        {
          if (SignalHeightA[p]>0)
          {
            if (p==0){ spec5Asigsum += SignalHeightA[p]; NonZeroSpec5A++; }
            if (p==1){ spec4Asigsum += SignalHeightA[p]; NonZeroSpec4A++; }
          }
          if (SignalHeightB[p]>0)
          {
            if (p==0){ spec5Bsigsum += SignalHeightB[p]; NonZeroSpec5B++; }
            if (p==1){ spec4Bsigsum += SignalHeightB[p]; NonZeroSpec4B++; }
          }
        }

        //zeroing out the meaningless signal for D4 PMT 3 nd 2
        if ((p==2 || p==3) && side=='C' && j==18) 
        {
          SignalHeightA[p]=0;
          SignalHeightB[p]=0;
        }
        if ((p==2 || p==3) && side=='A' && j==15) 
        {
          SignalHeightA[p]=0;
          SignalHeightB[p]=0;
        }

        //summing normal signals of D4 PMT 3 and 2
        if ((p==2 || p==3) && (j<14 || (j>15 && j<18) || j>19))
        {
          if (SignalHeightA[p] + SignalHeightB[p]>0)
          {
            if (p==2){ norm3sigsum += SignalHeightA[p] + SignalHeightB[p]; NonZeroNorm3++; }
            if (p==3){ norm2sigsum += SignalHeightA[p] + SignalHeightB[p]; NonZeroNorm2++; }
          }
        }

        //summing special signals of D4 PMT 3 and 2
        if ((p==2 || p==3) && (j==14 || j==15 || j==18 || j==19))
        {
          if (SignalHeightA[p] + SignalHeightB[p]>0)
          {
            if (p==2){ spec3sigsum += SignalHeightA[p] + SignalHeightB[p]; NonZeroSpec3++; }
            if (p==3){ spec2sigsum += SignalHeightA[p] + SignalHeightB[p]; NonZeroSpec2++; }
          }
        }

        //summing signals of E1 PMT 12
        if (p==4 && SignalHeightA[p] + SignalHeightB[p]>0){ norm12sigsum += SignalHeightA[p] + SignalHeightB[p]; NonZeroNorm12++; }

        //summing signals of E2 PMT 13
        if (p==5 && SignalHeightA[p] + SignalHeightB[p]>0){ norm13sigsum += SignalHeightA[p] + SignalHeightB[p]; NonZeroNorm13++; }

      }//end loop over the 6 pmt's
      //*******************************************************
      Yaxis_pmt5Aintegral[j1] = integralA[0];
      Yaxis_pmt4Aintegral[j1] = integralA[1];
      Yaxis_pmt5Bintegral[j1] = integralB[0];
      Yaxis_pmt4Bintegral[j1] = integralB[1];

      //*******************************************************

      Yaxis_pmt5Awidth[j1] = widthA[0];
      Yaxis_pmt4Awidth[j1] = widthA[1];
      Yaxis_pmt5Bwidth[j1] = widthB[0];
      Yaxis_pmt4Bwidth[j1] = widthB[1];
      Yaxis_pmt5Asignal[j1] = SignalHeightA[0];
      Yaxis_pmt4Asignal[j1] = SignalHeightA[1];
      Yaxis_pmt5Bsignal[j1] = SignalHeightB[0];
      Yaxis_pmt4Bsignal[j1] = SignalHeightB[1];
      SignalMatrix[j1][0] = SignalHeightA[0];
      SignalMatrix[j1][1] = SignalHeightA[1];
      SignalMatrix[j1][2] = SignalHeightB[0];
      SignalMatrix[j1][3] = SignalHeightB[1];
//      cout<<"\t"<<SignalHeightA[0]<<"\t"<<SignalHeightA[1]<<"\t"<<SignalHeightB[0]<<"\t"<<SignalHeightB[1];
//      cout<<"\t"<<SignalMatrix[j1][0]<<"\t"<<SignalMatrix[j1][1]<<"\t"<<SignalMatrix[j1][2]<<"\t"<<SignalMatrix[j1][3];
      if (direction == '2')
      {
        if (j%2==0)
        {
	  //**********************************************
      Yaxis_pmt3integral[j1] = integralA[2];
      Yaxis_pmt2integral[j1] = integralA[3];
      Yaxis_pmt12integral[j1] = integralA[4];
      Yaxis_pmt13integral[j1] = integralB[5];

      //*********************************************

          Yaxis_pmt3width[j1]  = widthA[2];
          Yaxis_pmt2width[j1]  = widthA[3];
          Yaxis_pmt12width[j1] = widthA[4];
          Yaxis_pmt13width[j1] = widthB[5];
          Yaxis_pmt3signal[j1]  = SignalHeightA[2];
          Yaxis_pmt2signal[j1]  = SignalHeightA[3];
          Yaxis_pmt12signal[j1] = SignalHeightA[4];
          Yaxis_pmt13signal[j1] = SignalHeightB[5];
          SignalMatrix[j1][4] = SignalHeightA[2];
          SignalMatrix[j1][5] = SignalHeightA[3];
          SignalMatrix[j1][6] = SignalHeightA[4];
          SignalMatrix[j1][7] = SignalHeightB[5];
//          cout<<"\t"<<SignalHeightA[2]<<"\t"<<SignalHeightA[3]<<"\t"<<SignalHeightA[4]<<"\t"<<SignalHeightB[5]<<endl;
//          cout<<"\t"<<SignalMatrix[j1][4]<<"\t"<<SignalMatrix[j1][5]<<"\t"<<SignalMatrix[j1][6]<<"\t"<<SignalMatrix[j1][7]<<endl;
        }
        if (j%2==1)
        {
	  //*********************************************88
      Yaxis_pmt3integral[j1] = integralB[2];
      Yaxis_pmt2integral[j1] = integralB[3];
      Yaxis_pmt12integral[j1] = integralB[4];
      Yaxis_pmt13integral[j1] = integralA[5];

      //******************************************

          Yaxis_pmt3width[j1]  = widthB[2];
          Yaxis_pmt2width[j1]  = widthB[3];
          Yaxis_pmt12width[j1] = widthB[4];
          Yaxis_pmt13width[j1] = widthA[5];
          Yaxis_pmt3signal[j1]  = SignalHeightB[2];
          Yaxis_pmt2signal[j1]  = SignalHeightB[3];
          Yaxis_pmt12signal[j1] = SignalHeightB[4];
          Yaxis_pmt13signal[j1] = SignalHeightA[5];
          SignalMatrix[j1][4] = SignalHeightB[2];
          SignalMatrix[j1][5] = SignalHeightB[3];
          SignalMatrix[j1][6] = SignalHeightB[4];
          SignalMatrix[j1][7] = SignalHeightA[5];
//          cout<<"\t"<<SignalHeightB[2]<<"\t"<<SignalHeightB[3]<<"\t"<<SignalHeightB[4]<<"\t"<<SignalHeightA[5]<<endl;
//          cout<<"\t"<<SignalMatrix[j1][4]<<"\t"<<SignalMatrix[j1][5]<<"\t"<<SignalMatrix[j1][6]<<"\t"<<SignalMatrix[j1][7]<<endl;
        }
      }
      if (direction == '1')
      {
        if (j%2==0)
        {
	  //*****************************************
      Yaxis_pmt3integral[j1] = integralB[2];
      Yaxis_pmt2integral[j1] = integralB[3];
      Yaxis_pmt12integral[j1] = integralB[4];
      Yaxis_pmt13integral[j1] = integralA[5];

      //*****************************************

          Yaxis_pmt3width[j1]  = widthB[2];
          Yaxis_pmt2width[j1]  = widthB[3];
          Yaxis_pmt12width[j1] = widthB[4];
          Yaxis_pmt13width[j1] = widthA[5];
          Yaxis_pmt3signal[j1]  = SignalHeightB[2];
          Yaxis_pmt2signal[j1]  = SignalHeightB[3];
          Yaxis_pmt12signal[j1] = SignalHeightB[4];
          Yaxis_pmt13signal[j1] = SignalHeightA[5];
          SignalMatrix[j1][4] = SignalHeightB[2];
          SignalMatrix[j1][5] = SignalHeightB[3];
          SignalMatrix[j1][6] = SignalHeightB[4];
          SignalMatrix[j1][7] = SignalHeightA[5];
//          cout<<"\t"<<SignalHeightB[2]<<"\t"<<SignalHeightB[3]<<"\t"<<SignalHeightB[4]<<"\t"<<SignalHeightA[5]<<endl;
//          cout<<"\t"<<SignalMatrix[j1][4]<<"\t"<<SignalMatrix[j1][5]<<"\t"<<SignalMatrix[j1][6]<<"\t"<<SignalMatrix[j1][7]<<endl;
        }
        if (j%2==1)
        {
	  //******************************************
 Yaxis_pmt3integral[j1] = integralA[2];
      Yaxis_pmt2integral[j1] = integralA[3];
      Yaxis_pmt12integral[j1] = integralA[4];
      Yaxis_pmt13integral[j1] = integralB[5];

      //************************************************

          Yaxis_pmt3width[j1]  = widthA[2];
          Yaxis_pmt2width[j1]  = widthA[3];
          Yaxis_pmt12width[j1] = widthA[4];
          Yaxis_pmt13width[j1] = widthB[5];
          Yaxis_pmt3signal[j1]  = SignalHeightA[2];
          Yaxis_pmt2signal[j1]  = SignalHeightA[3];
          Yaxis_pmt12signal[j1] = SignalHeightA[4];
          Yaxis_pmt13signal[j1] = SignalHeightB[5];
          SignalMatrix[j1][4] = SignalHeightA[2];
          SignalMatrix[j1][5] = SignalHeightA[3];
          SignalMatrix[j1][6] = SignalHeightA[4];
          SignalMatrix[j1][7] = SignalHeightB[5];
//          cout<<"\t"<<SignalHeightA[2]<<"\t"<<SignalHeightA[3]<<"\t"<<SignalHeightA[4]<<"\t"<<SignalHeightB[5]<<endl;
//          cout<<"\t"<<SignalMatrix[j1][4]<<"\t"<<SignalMatrix[j1][5]<<"\t"<<SignalMatrix[j1][6]<<"\t"<<SignalMatrix[j1][7]<<endl;
        }
      }
      J++;

   }// closes loop over j1
/*
cout<<"norm5Asigsum = "<<norm5Asigsum<<"  norm5Bsigsum = "<<norm5Bsigsum<<endl;
cout<<"norm4Asigsum = "<<norm4Asigsum<<"  norm4Bsigsum = "<<norm4Bsigsum<<endl;
cout<<"spec5Asigsum = "<<spec5Asigsum<<"  spec5Bsigsum = "<<spec5Bsigsum<<endl;
cout<<"spec4Asigsum = "<<spec4Asigsum<<"  spec4Bsigsum = "<<spec4Bsigsum<<endl<<endl;

cout<<"norm3sigsum = "<<norm3sigsum<<"  norm2sigsum = "<<norm2sigsum<<endl;
cout<<"spec3sigsum = "<<spec3sigsum<<"  spec2sigsum = "<<spec2sigsum<<endl;

cout<<"norm12sigsum = "<<norm12sigsum<<"  norm13sigsum = "<<norm13sigsum<<endl;

cout<<"5A= "<<NonZeroSpec5A<<"   4A= "<<NonZeroSpec4A<<"   5B= "<<NonZeroSpec5B<<"   4B= "<<NonZeroSpec4B<<"   3= "<<NonZeroSpec3<<"   2= "<<NonZeroSpec2<<endl;
*/
  
// setting the normal averages
  if (NonZeroNorm5A!=0) Norm5Aavg = norm5Asigsum / NonZeroNorm5A; 
  else if (NonZeroNorm5A==0) Norm5Aavg = 0;
  if (NonZeroNorm4A!=0) Norm4Aavg = norm4Asigsum / NonZeroNorm4A; 
  else if (NonZeroNorm4A==0) Norm4Aavg = 0;
  if (NonZeroNorm5B!=0) Norm5Bavg = norm5Bsigsum / NonZeroNorm5B; 
  else if (NonZeroNorm5B==0) Norm5Bavg = 0;
  if (NonZeroNorm4B!=0) Norm4Bavg = norm4Bsigsum / NonZeroNorm4B; 
  else if (NonZeroNorm4B==0) Norm4Bavg = 0;
  if (NonZeroNorm3!=0) Norm3avg = norm3sigsum / NonZeroNorm3; 
  else if (NonZeroNorm3==0) Norm3avg = 0;
  if (NonZeroNorm2!=0) Norm2avg = norm2sigsum / NonZeroNorm2; 
  else if (NonZeroNorm2==0) Norm2avg = 0;
  if (NonZeroNorm12!=0) Norm12avg = norm12sigsum / NonZeroNorm12; 
  else if (NonZeroNorm12==0) Norm12avg = 0;
  if (NonZeroNorm13!=0) Norm13avg = norm13sigsum / NonZeroNorm13; 
  else if (NonZeroNorm13==0) Norm13avg = 0;
//  cout<<"5A= "<<Norm5Aavg<<"   4A= "<<Norm4Aavg<<"   5B= "<<Norm5Bavg<<"   4B= "<<Norm4Bavg<<"   3= "<<Norm3avg<<"   2= "<<Norm2avg<<"   12= "<<Norm12avg<<"   13= "<<Norm13avg<<endl;

// setting the special averages
  if (NonZeroSpec5A!=0) Spec5Aavg = spec5Asigsum / NonZeroSpec5A; 
  else if (NonZeroSpec5A==0) Spec5Aavg = 0;
  if (NonZeroSpec4A!=0) Spec4Aavg = spec4Asigsum / NonZeroSpec4A; 
  else if (NonZeroSpec4A==0) Spec4Aavg = 0;
  if (NonZeroSpec5B!=0) Spec5Bavg = spec5Bsigsum / NonZeroSpec5B; 
  else if (NonZeroSpec5B==0) Spec5Bavg = 0;
  if (NonZeroSpec4B!=0) Spec4Bavg = spec4Bsigsum / NonZeroSpec4B; 
  else if (NonZeroSpec4B==0) Spec4Bavg = 0;
  if (NonZeroSpec3!=0) Spec3avg = spec3sigsum / NonZeroSpec3; 
  else if (NonZeroSpec3==0) Spec3avg = 0;
  if (NonZeroSpec2!=0) Spec2avg = spec2sigsum / NonZeroSpec2; 
  else if (NonZeroSpec2==0) Spec2avg = 0;
//  cout<<"5A= "<<Spec5Aavg<<"   4A= "<<Spec4Aavg<<"   5B= "<<Spec5Bavg<<"   4B= "<<Spec4Bavg<<"   3= "<<Spec3avg<<"   2= "<<Spec2avg<<endl;

// setting the constants and filling the ConstantMatrix - includes constants for 5A,4A,5B,4B
  for (int k1=0;k1<64;k1++)
  {
    // constants for C10
    if (k1<38 || (k1>41 && k1<54) || k1>57)
    {
      if (SignalMatrix[k1][0]!=0) ConstantMatrix[k1][0] = Norm5Aavg / SignalMatrix[k1][0];
      if (SignalMatrix[k1][1]!=0) ConstantMatrix[k1][1] = Norm4Aavg / SignalMatrix[k1][1];
      if (SignalMatrix[k1][2]!=0) ConstantMatrix[k1][2] = Norm5Bavg / SignalMatrix[k1][2];
      if (SignalMatrix[k1][3]!=0) ConstantMatrix[k1][3] = Norm4Bavg / SignalMatrix[k1][3];
    }
    else if ((k1>=38 && k1<=41) || (k1>=54 && k1<=57))
    {
      if (SignalMatrix[k1][0]!=0) ConstantMatrix[k1][0] = Spec5Aavg / SignalMatrix[k1][0];
      if (SignalMatrix[k1][1]!=0) ConstantMatrix[k1][1] = Spec4Aavg / SignalMatrix[k1][1];
      if (SignalMatrix[k1][2]!=0) ConstantMatrix[k1][2] = Spec5Bavg / SignalMatrix[k1][2];
      if (SignalMatrix[k1][3]!=0) ConstantMatrix[k1][3] = Spec4Bavg / SignalMatrix[k1][3];
    }

    //constants for D4
    if (k1<13 || (k1>14 && k1<17) || k1>18)
    {
      if (SignalMatrix[k1][4]!=0) ConstantMatrix[k1][4] = Norm3avg / SignalMatrix[k1][4];
      if (SignalMatrix[k1][5]!=0) ConstantMatrix[k1][5] = Norm2avg / SignalMatrix[k1][5];
    }
    else if (k1==13 || k1==14 || k1==17 || k1==18)
    {
      if (SignalMatrix[k1][4]!=0) ConstantMatrix[k1][4] = Spec3avg / SignalMatrix[k1][4];
      if (SignalMatrix[k1][5]!=0) ConstantMatrix[k1][5] = Spec2avg / SignalMatrix[k1][5];
    }

    //constants for E1 and E2
    if (SignalMatrix[k1][6]!=0) ConstantMatrix[k1][6] = Norm12avg / SignalMatrix[k1][6];
    if (SignalMatrix[k1][7]!=0) ConstantMatrix[k1][7] = Norm13avg / SignalMatrix[k1][7];
//    cout<<k1<<"\t"<<ConstantMatrix[k1][0]<<"\t"<<ConstantMatrix[k1][1]<<"\t"<<ConstantMatrix[k1][2]<<"\t"<<ConstantMatrix[k1][3]<<"\t"<<ConstantMatrix[k1][4]<<"\t"<<ConstantMatrix[k1][5]<<"\t"<<ConstantMatrix[k1][6]<<"\t"<<ConstantMatrix[k1][7]<<"\t"<<endl;
  }

  constants<<"constants for pmt5 and pmt4 represent the average of the two constants of the two signals for that pmt. for example, module1 pmt5 has two signals. a calib constant was determined for each signal and then averaged to provide one constant for mod1's pmt5."<<endl;
  signal<<"mod\tC10:Pmt5\tD4:Pmt4\tD4:Pmt3\tD4:Pmt2\tE1:Pmt12\tE2:Pmt13"<<endl;
  constants<<"mod\tPmt5\tPmt4\tPmt3\tPmt2\tPmt12\tPmt13"<<endl;
  cout<<"mod\tPmt5\tPmt4\tPmt3\tPmt2\tPmt12\tPmt13"<<endl;

  for (int m1=0;m1<64;m1++)//averaged 5A,5B and 4A,4B constants with constants from constantmatrix for pmts 3,2,12,13
  {
    //PMT 5A,5B
    if (ConstantMatrix[m1][0]!=0 && ConstantMatrix[m1][2]!=0) AvgDirConstantMatrix[m1][0] = (ConstantMatrix[m1][0] + ConstantMatrix[m1][2])/2;
    if (ConstantMatrix[m1][0]==0 && ConstantMatrix[m1][2]!=0) AvgDirConstantMatrix[m1][0] = ConstantMatrix[m1][2];
    if (ConstantMatrix[m1][0]!=0 && ConstantMatrix[m1][2]==0) AvgDirConstantMatrix[m1][0] = ConstantMatrix[m1][0];
    //PMT 4A,4B
    if (ConstantMatrix[m1][1]!=0 && ConstantMatrix[m1][3]!=0) AvgDirConstantMatrix[m1][1] = (ConstantMatrix[m1][1] + ConstantMatrix[m1][3])/2;
    if (ConstantMatrix[m1][1]==0 && ConstantMatrix[m1][3]!=0) AvgDirConstantMatrix[m1][1] = ConstantMatrix[m1][3];
    if (ConstantMatrix[m1][1]!=0 && ConstantMatrix[m1][3]==0) AvgDirConstantMatrix[m1][1] = ConstantMatrix[m1][1];
    //PMTs 3,2,12,13
    AvgDirConstantMatrix[m1][2] = ConstantMatrix[m1][4];
    AvgDirConstantMatrix[m1][3] = ConstantMatrix[m1][5];
    AvgDirConstantMatrix[m1][4] = ConstantMatrix[m1][6];
    AvgDirConstantMatrix[m1][5] = ConstantMatrix[m1][7];


    Yaxis_pmt5constant[m1] = AvgDirConstantMatrix[m1][0];
    Yaxis_pmt4constant[m1] = AvgDirConstantMatrix[m1][1];
    Yaxis_pmt3constant[m1] = AvgDirConstantMatrix[m1][2];
    Yaxis_pmt2constant[m1] = AvgDirConstantMatrix[m1][3];
    Yaxis_pmt12constant[m1] = AvgDirConstantMatrix[m1][4];
    Yaxis_pmt13constant[m1] = AvgDirConstantMatrix[m1][5];

  // pmt5constant[m1]=1/(Yaxis_pmt5constant[m1]);
  //   pmt4constant[m1]=1/(Yaxis_pmt4constant[m1]);
  //   pmt3constant[m1]=1/(Yaxis_pmt3constant[m1]);
  //   pmt2constant[m1]=1/(Yaxis_pmt2constant[m1]);
  //   pmt12constant[m1]=1/(Yaxis_pmt12constant[m1]);
  //   pmt13constant[m1]=1/(Yaxis_pmt13constant[m1]);

 


    if (Yaxis_pmt5constant[m1]==0) pmt5constant[m1] = 0; 
    else if (Yaxis_pmt5constant[m1]!=0) pmt5constant[m1] = 1/(Yaxis_pmt5constant[m1]);
    if (Yaxis_pmt4constant[m1]==0) pmt4constant[m1] = 0; 
    else if (Yaxis_pmt4constant[m1]!=0) pmt4constant[m1] = 1/(Yaxis_pmt4constant[m1]);
    if (Yaxis_pmt3constant[m1]==0) pmt3constant[m1] = 0; 
    else if (Yaxis_pmt3constant[m1]!=0) pmt3constant[m1] = 1/(Yaxis_pmt3constant[m1]);
    if (Yaxis_pmt2constant[m1]==0) pmt2constant[m1] = 0; 
    else if (Yaxis_pmt2constant[m1]!=0) pmt2constant[m1] = 1/(Yaxis_pmt2constant[m1]);
    if (Yaxis_pmt12constant[m1]==0) pmt12constant[m1] = 0; 
    else if (Yaxis_pmt12constant[m1]!=0) pmt12constant[m1] = 1/(Yaxis_pmt12constant[m1]);
    if (Yaxis_pmt13constant[m1]==0) pmt13constant[m1] = 0; 
    else if (Yaxis_pmt13constant[m1]!=0) pmt13constant[m1] = 1/(Yaxis_pmt13constant[m1]);



    constants<<m1+1<<"\t"<< pmt5constant[m1]<<"\t"<< pmt4constant[m1]  <<"\t"<<  pmt3constant[m1]  <<"\t"<<  pmt2constant[m1]  <<"\t"<<  pmt12constant[m1]   <<"\t"<<  pmt13constant[m1]<<endl;

    if (Yaxis_pmt5Asignal[m1]==0)Yaxis_pmt5Asignal[m1]= Yaxis_pmt5Bsignal[m1];
    if (Yaxis_pmt5Bsignal[m1]==0)Yaxis_pmt5Bsignal[m1]= Yaxis_pmt5Asignal[m1];
    if (Yaxis_pmt4Asignal[m1]==0)Yaxis_pmt4Asignal[m1]= Yaxis_pmt4Bsignal[m1];
    if (Yaxis_pmt4Bsignal[m1]==0)Yaxis_pmt4Bsignal[m1]= Yaxis_pmt4Asignal[m1];

    signal<<m1+1<<"\t"<< (Yaxis_pmt5Asignal[m1] + Yaxis_pmt5Bsignal[m1])/2<<"\t"<< (Yaxis_pmt4Asignal[m1]+ Yaxis_pmt4Bsignal[m1])/2  <<"\t"<<  Yaxis_pmt3signal[m1]  <<"\t"<<  Yaxis_pmt2signal[m1]  <<"\t"<<  Yaxis_pmt12signal[m1]   <<"\t"<<  Yaxis_pmt13signal[m1]<<endl;
    cout<<m1+1<<"\t"<< pmt5constant[m1]<<"\t"<< pmt4constant[m1]  <<"\t"<<  pmt3constant[m1]  <<"\t"<<  pmt2constant[m1]  <<"\t"<<  pmt12constant[m1]   <<"\t"<<  pmt13constant[m1]<<endl;
 
  
    // constants<<m1+1<<"\t"<<1/(Yaxis_pmt5constant[m1])<<"\t"<< 1/(Yaxis_pmt4constant[m1])<<"\t"<<1/(Yaxis_pmt3constant[m1])<<"\t"<<1/(Yaxis_pmt2constant[m1])<<"\t"<<1/( Yaxis_pmt12constant[m1])<<"\t"<<1/(Yaxis_pmt13constant[m1])<<endl;

 
    //cout<<m1+1<<"\t"<<AvgDirConstantMatrix[m1][0]<<"\t"<<AvgDirConstantMatrix[m1][1]<<"\t"<<AvgDirConstantMatrix[m1][2]<<"\t"<<AvgDirConstantMatrix[m1][3]<<"\t"<<AvgDirConstantMatrix[m1][4]<<"\t"<<AvgDirConstantMatrix[m1][5]<<endl;
  }
  signal.close();
  constants.close();


   TString file = "/afs/cern.ch/user/s/sdarmora/public/cesium_ITC/";
   file += "cesium_"; 
   file += RunNo;
   file += ".root"; 
   TFile *f = new TFile(file,"RECREATE");


// CONSTANT PLOTS
  

TGraph *F1 = new TGraph(64,Xaxis,Yaxis_pmt5constant);
   c6->cd(1);
   F1->SetName("pmt5Constant");
   F1->SetTitle("C10 - Pmt 5 - Constant");
   F1->GetXaxis()->SetTitle("Module");
   F1->GetYaxis()->SetTitle("Constant");
   F1->Draw("AP");
   F1->Write();
   TGraph *F2 = new TGraph(64,Xaxis,Yaxis_pmt4constant);
   c6->cd(2);
   F2->SetName("pmt4Constant");
   F2->SetTitle("C10 - Pmt 4 - Constant");
   F2->GetXaxis()->SetTitle("Module");
   F2->GetYaxis()->SetTitle("Constant");
   F2->Draw("AP");
   F2->Write();
   TGraph *F3 = new TGraph(64,Xaxis,Yaxis_pmt3constant);
   c6->cd(3);
   F3->SetName("pmt3Constant");
   F3->SetTitle("D4 - Pmt 3 - Constant");
   F3->GetXaxis()->SetTitle("Module");
   F3->GetYaxis()->SetTitle("Constant");
   F3->Draw("AP");
   F3->Write();
   TGraph *F4 = new TGraph(64,Xaxis,Yaxis_pmt2constant);
   c6->cd(4);
   F4->SetName("pmt2Constant");
   F4->SetTitle("D4 - Pmt 2 - Constant");
   F4->GetXaxis()->SetTitle("Module");
   F4->GetYaxis()->SetTitle("Constant");
   F4->Draw("AP");
   F4->Write();
   TGraph *F5 = new TGraph(64,Xaxis,Yaxis_pmt12constant);
   c6->cd(5);
   F5->SetName("pmt12Constant");
   F5->SetTitle("E1 - Pmt 12 - Constant");
   F5->GetXaxis()->SetTitle("Module");
   F5->GetYaxis()->SetTitle("Constant");
   F5->Draw("AP");
   F5->Write();
   TGraph *F6 = new TGraph(64,Xaxis,Yaxis_pmt13constant);
   c6->cd(6);
   F6->SetName("pmt13Constant");
   F6->SetTitle("E2 - Pmt 13 - Constant");
   F6->GetXaxis()->SetTitle("Module");
   F6->GetYaxis()->SetTitle("Constant");
   F6->Draw("AP");
   F6->Write();
 //c6->SaveAs("Constants_2011_A1.pdf");



// PEDESTAL PLOTS
   TGraph *A = new TGraph(64,Xaxis,Yaxis_pmt5pedestal);
   c0->cd(1);
   A->SetName("pmt5Pedestal");
   A->SetTitle("C10 - Pmt 5 - Pedestal");
   A->GetXaxis()->SetTitle("Module");
   A->GetYaxis()->SetTitle("Pedestal");
   A->Draw("A*");
   A->Write();
   TGraph *A1 = new TGraph(64,Xaxis,Yaxis_pmt4pedestal);
   c1->cd(1);
   A1->SetName("pmt4Pedestal");
   A1->SetTitle("C10 - Pmt 4 - Pedestal");
   A1->GetXaxis()->SetTitle("Module");
   A1->GetYaxis()->SetTitle("Pedestal");
   A1->Draw("A*");
   A1->Write();
   TGraph *a2 = new TGraph(64,Xaxis,Yaxis_pmt3pedestal);
   c2->cd(1);
   a2->SetName("pmt3Pedestal");
   a2->SetTitle("D4 - Pmt 3 - Pedestal");
   a2->GetXaxis()->SetTitle("Module");
   a2->GetYaxis()->SetTitle("Pedestal");
   a2->Draw("A*");
   a2->Write();
   TGraph *a3 = new TGraph(64,Xaxis,Yaxis_pmt2pedestal);
   c3->cd(1);
   a3->SetName("pmt2Pedestal");
   a3->SetTitle("D4 - Pmt 2 - Pedestal");
   a3->GetXaxis()->SetTitle("Module");
   a3->GetYaxis()->SetTitle("Pedestal");
   a3->Draw("A*");
   a3->Write();
   TGraph *a4 = new TGraph(64,Xaxis,Yaxis_pmt12pedestal);
   c4->cd(1);
   a4->SetName("pmt12Pedestal");
   a4->SetTitle("E1 - Pmt 12 - Pedestal");
   a4->GetXaxis()->SetTitle("Module");
   a4->GetYaxis()->SetTitle("Pedestal");
   a4->Draw("A*");
   a4->Write();
   TGraph *a5 = new TGraph(64,Xaxis,Yaxis_pmt13pedestal);
   c5->cd(1);
   a5->SetName("pmt13Pedestal");
   a5->SetTitle("E2 - Pmt 13 - Pedestal");
   a5->GetXaxis()->SetTitle("Module");
   a5->GetYaxis()->SetTitle("Pedestal");
   a5->Draw("A*");
   a5->Write();
   

// WIDTH PLOTS
   TGraph *B = new TGraph(64,Xaxis,Yaxis_pmt5Awidth);
   c0->cd(3);
   B->SetName("pmt5Awidth");
   B->SetTitle("C10 - Pmt 5 - Width");
   B->GetXaxis()->SetTitle("Module");
   B->GetYaxis()->SetTitle("Width");
   B->Draw("A*");
   B->Write();
   TGraph *bb = new TGraph(64,Xaxis,Yaxis_pmt5Bwidth);
   c0->cd(4);
   bb->SetName("pmt5Bwidth");
   bb->SetTitle("C10 - Pmt 5B - Width");
   bb->GetXaxis()->SetTitle("Module");
   bb->GetYaxis()->SetTitle("Width");
   bb->Draw("A*");
   bb->Write();
   TGraph *B1 = new TGraph(64,Xaxis,Yaxis_pmt4Awidth);
   c1->cd(3);
   B1->SetName("pmt4Awidth");
   B1->SetTitle("C10 - Pmt 4 - Width");
   B1->GetXaxis()->SetTitle("Module");
   B1->GetYaxis()->SetTitle("Width");
   B1->Draw("A*");
   B1->Write();
   TGraph *bb1 = new TGraph(64,Xaxis,Yaxis_pmt4Bwidth);
   c1->cd(4);
   bb1->SetName("pmt4Bwidth");
   bb1->SetTitle("C10 - Pmt 4B - Width");
   bb1->GetXaxis()->SetTitle("Module");
   bb1->GetYaxis()->SetTitle("Width");
   bb1->Draw("A*");
   bb1->Write();
   TGraph *b2 = new TGraph(64,Xaxis,Yaxis_pmt3width);
   c2->cd(2);
   b2->SetName("pmt3width");
   b2->SetTitle("D4 - Pmt 3 - Width");
   b2->GetXaxis()->SetTitle("Module");
   b2->GetYaxis()->SetTitle("Width");
   b2->Draw("A*");
   b2->Write();
   TGraph *b3 = new TGraph(64,Xaxis,Yaxis_pmt2width);
   c3->cd(2);
   b3->SetName("pmt2width");
   b3->SetTitle("D4 - Pmt 2 - Width");
   b3->GetXaxis()->SetTitle("Module");
   b3->GetYaxis()->SetTitle("Width");
   b3->Draw("A*");
   b3->Write();
   TGraph *b4 = new TGraph(64,Xaxis,Yaxis_pmt12width);
   c4->cd(2);
   b4->SetName("pmt12width");
   b4->SetTitle("E1 - Pmt 12 - Width");
   b4->GetXaxis()->SetTitle("Module");
   b4->GetYaxis()->SetTitle("Width");
   b4->Draw("A*");
   b4->Write();
   TGraph *b5 = new TGraph(64,Xaxis,Yaxis_pmt13width);
   c5->cd(2);
   b5->SetName("pmt13width");
   b5->SetTitle("E2 - Pmt 13 - Width");
   b5->GetXaxis()->SetTitle("Module");
   b5->GetYaxis()->SetTitle("Width");
   b5->Draw("A*");
   b5->Write();
   
   // INTEGRAL PLOTS


 TGraph *I = new TGraph(64,Xaxis,Yaxis_pmt5Aintegral);
   c0->cd(5);
   I->SetName("pmt5Aintegral");
   I->SetTitle("C10 - Pmt 5 - Integtal");
   I->GetXaxis()->SetTitle("Module");
   I->GetYaxis()->SetTitle("Integral");
   I->Draw("A*");
   I->Write();
   TGraph *ii = new TGraph(64,Xaxis,Yaxis_pmt5Bintegral);
   c0->cd(6);
   ii->SetName("pmt5Bintegral");
   ii->SetTitle("C10 - Pmt 5B - Integral");
   ii->GetXaxis()->SetTitle("Module");
   ii->GetYaxis()->SetTitle("Integral");
   ii->Draw("A*");
   ii->Write();
   TGraph *I1 = new TGraph(64,Xaxis,Yaxis_pmt4Aintegral);
   c1->cd(5);
   I1->SetName("pmt4Aintegral");
   I1->SetTitle("C10 - Pmt 4 - Integral");
   I1->GetXaxis()->SetTitle("Module");
   I1->GetYaxis()->SetTitle("Integral");
   I1->Draw("A*");
   I1->Write();
   TGraph *ii1 = new TGraph(64,Xaxis,Yaxis_pmt4Bintegral);
   c1->cd(6);
   ii1->SetName("pmt4Bintegral");
   ii1->SetTitle("C10 - Pmt 4B - Integral");
   ii1->GetXaxis()->SetTitle("Module");
   ii1->GetYaxis()->SetTitle("Integral");
   ii1->Draw("A*");
   bb1->Write();
   TGraph *I2 = new TGraph(64,Xaxis,Yaxis_pmt3integral);
   c2->cd(3);
   I2->SetName("pmt3integral");
   I2->SetTitle("D4 - Pmt 3 - Integral");
   I2->GetXaxis()->SetTitle("Module");
   I2->GetYaxis()->SetTitle("Integral");
   I2->Draw("A*");
   I2->Write();
   TGraph *I3 = new TGraph(64,Xaxis,Yaxis_pmt2integral);
   c3->cd(3);
   I3->SetName("pmt2integral");
   I3->SetTitle("D4 - Pmt 2 -Integral ");
   I3->GetXaxis()->SetTitle("Module");
   I3->GetYaxis()->SetTitle("Integral");
   I3->Draw("A*");
   I3->Write();
   TGraph *I4 = new TGraph(64,Xaxis,Yaxis_pmt12integral);
   c4->cd(3);
   I4->SetName("pmt12integral");
   I4->SetTitle("E1 - Pmt 12 - Integral");
   I4->GetXaxis()->SetTitle("Module");
   I4->GetYaxis()->SetTitle("Integral");
   I4->Draw("A*");
   I4->Write();
   TGraph *I5 = new TGraph(64,Xaxis,Yaxis_pmt13integral);
   c5->cd(3);
   I5->SetName("pmt13integral");
   I5->SetTitle("E2 - Pmt 13 - Integral");
   I5->GetXaxis()->SetTitle("Module");
   I5->GetYaxis()->SetTitle("Integral");
   I5->Draw("A*");
   I5->Write();




// SIGNAL PLOTS
   TGraph *d = new TGraph(64,Xaxis,Yaxis_pmt5Asignal);
   c0->cd(7);
   d->SetName("pmt5Asignal");
   d->SetTitle("C10 - Pmt 5 - Signal");
   d->GetXaxis()->SetTitle("Module");
   d->GetYaxis()->SetTitle("Signal");
   d->Draw("A*");
   d->Write();
   TGraph *dd = new TGraph(64,Xaxis,Yaxis_pmt5Bsignal);
   c0->cd(8);
   dd->SetName("pmt5Bsignal");
   dd->SetTitle("C10 - Pmt 5B - Signal");
   dd->GetXaxis()->SetTitle("Module");
   dd->GetYaxis()->SetTitle("Signal");
   dd->Draw("A*");
   dd->Write();
   TGraph *d1 = new TGraph(64,Xaxis,Yaxis_pmt4Asignal);
   c1->cd(7);
   d1->SetName("pmt4Asignal");
   d1->SetTitle("C10 - Pmt 4 - Signal");
   d1->GetXaxis()->SetTitle("Module");
   d1->GetYaxis()->SetTitle("Signal");
   d1->Draw("A*");
   d1->Write();
   TGraph *dd1 = new TGraph(64,Xaxis,Yaxis_pmt4Bsignal);
   c1->cd(8);
   dd1->SetName("pmt4Bsignal");
   dd1->SetTitle("C10 - Pmt 4B - Signal");
   dd1->GetXaxis()->SetTitle("Module");
   dd1->GetYaxis()->SetTitle("Signal");
   dd1->Draw("A*");
   dd1->Write();
   TGraph *d2 = new TGraph(64,Xaxis,Yaxis_pmt3signal);
   c2->cd(4);
   d2->SetName("pmt3signal");
   d2->SetTitle("D4 - Pmt 3 - Signal");
   d2->GetXaxis()->SetTitle("Module");
   d2->GetYaxis()->SetTitle("Signal");
   d2->Draw("A*");
   d2->Write();
   TGraph *d3 = new TGraph(64,Xaxis,Yaxis_pmt2signal);
   c3->cd(4);
   d3->SetName("pmt2signal");
   d3->SetTitle("D4 - Pmt 2 - Signal");
   d3->GetXaxis()->SetTitle("Module");
   d3->GetYaxis()->SetTitle("Signal");
   d3->Draw("A*");
   d3->Write();
   TGraph *d4 = new TGraph(64,Xaxis,Yaxis_pmt12signal);
   c4->cd(4);
   d4->SetName("pmt12signal");
   d4->SetTitle("E1 - Pmt 12 - Signal");
   d4->GetXaxis()->SetTitle("Module");
   d4->GetYaxis()->SetTitle("Signal");
   d4->Draw("A*");
   d4->Write();
   TGraph *d5 = new TGraph(64,Xaxis,Yaxis_pmt13signal);
   c5->cd(4);
   d5->SetName("pmt13signal");
   d5->SetTitle("E2 - Pmt 13 - Signal");
   d5->GetXaxis()->SetTitle("Module");
   d5->GetYaxis()->SetTitle("Signal");
   d5->Draw("A*");
   d5->Write();
   
// c0->SaveAs("PMT5_Oct9,2010_A1.pdf");
// c1->SaveAs("PMT4_Oct9,2010_A1.pdf");
// c2->SaveAs("PMT3_Oct9,2010_A1.pdf");
// c3->SaveAs("PMT2_Oct9,2010_A1.pdf");
// c4->SaveAs("PMT12_Sept2,2010_C2.pdf");
// c5->SaveAs("PMT13_Sept2,2010_C2.pdf");
// c6->SaveAs("Constants_Sept2,2010_C2.pdf");
  




   f->Close();

}//closes loop over HeatherModuleLoop

