//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  3 20:55:03 2009 by ROOT version 5.22/00
// from TTree DAQ.Data.EBC27/DAQ.Data.EBC27
// found on file: cs00099.root
//////////////////////////////////////////////////////////

#ifndef Cstest1_h
#define Cstest1_h

#include <TString.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>

class Cstest1 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   float d; 
   UInt_t modnum;

// Declaration of leaf types
   UInt_t          timesec;
   Int_t           timemksec;
   UShort_t        trigger;
   UShort_t        data[48];

   // List of branches
   TBranch        *b_timesec;   //!
   TBranch        *b_timemksec;   //!
   TBranch        *b_trigger;   //!
   TBranch        *b_data;   //!

   Cstest1(Int_t modulenumber, TString run1, TString run2, TString run3,char side,int *);
   virtual ~Cstest1();
//   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(float*, float *, float *, float *, float *,char,int);
//   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual float    GetPedestal(int, int, Int_t);
   virtual void     TotalSignalRange(float, int, int, int *, Int_t);
   virtual void     SignalCalculator(int *,Int_t,char,float*,float*,float*,int*,int*,int);
   virtual float  GetfirstThreshold(int, int, Int_t, float *);
};

#endif

#ifdef Cstest1_cxx
Cstest1::Cstest1(int modulenumber,TString run1,TString run2,TString run3,char side,int ModulesOff[])
{
  int k=0;
  modnum=modulenumber;
  TString filename = "/afs/cern.ch/user/s/sdarmora/public/cesium_ITC/";

  char EBside[2] = {'C','A'};
                                                                                                           
  if (side == EBside[0]) filename += "Cside/";
  if (side == EBside[1]) filename += "Aside/";
  if (ModulesOff[k]==modulenumber)
  {
    k++;
    return;
  }
 
//  filename += run1; 

  if (modulenumber>=7&&modulenumber<=26 ) filename += run1;
  if (modulenumber>=27&&modulenumber<=46 ) filename += run2;
  if ((modulenumber>=47&&modulenumber<=64) || modulenumber<=6) filename += run3;

  filename += ".root";


   TFile * f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename);
      if (!f) {
         f = new TFile(filename);
      }

        TString treename="RawData/DAQ.Data.";
        treename += "EB";
        treename += side;
        if (modulenumber<10) { 
	treename+="0"; 
	treename +=modulenumber;
        } else {
        treename +=modulenumber; 
        }
        
  TTree  *   tree= (TTree*) f->Get(treename);
//  cs1000* mod = new cs1000(treename);

//  TTree * tree = new TTree;
//  tree->GetListOfLeaves();
//  if (!treename) return;
//  if (treename) tree= (TTree*) f->Get(treename);

  /* if(!tree) */
  /* { */
  /*   printf("Tree %s not found\n",treename); */
  /* }  */
  /* else  */
  /* { */
  /*   printf("Tree %s found\n",treename); */
  /* } */

   Init(tree);
}

Cstest1::~Cstest1()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Cstest1::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Cstest1::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}
void Cstest1::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("timesec", &timesec, &b_timesec);
   fChain->SetBranchAddress("timemksec", &timemksec, &b_timemksec);
   fChain->SetBranchAddress("trigger", &trigger, &b_trigger);
   fChain->SetBranchAddress("data[48]", data, &b_data);
   Notify();
}

Bool_t Cstest1::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Cstest1::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

//***************CALCULATE PEDESTAL
float Cstest1::GetPedestal(int pedLowerLimit,int pedUpperLimit,Int_t PMT)
{
  float pedestal = 0;
//  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nb = 0;
  for (Long64_t jentry=pedLowerLimit;jentry<pedUpperLimit;jentry++)
  {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);
//cout<<"jentry = "<<jentry<<"\ttrigger = "<<trigger<<endl;
      pedestal += data[PMT];
  }
  pedestal=pedestal/(pedUpperLimit - pedLowerLimit);
  return (pedestal);
}

//******************CALCULATE THRESHOLD

float Cstest1::GetfirstThreshold(int sigLowerLimit,int sigUpperLimit,Int_t PMT,float *pedestal)
{
 
  
  float firstThreshold =0;
  
//  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nb = 0;
 float signalMax=0;  
 for (Long64_t kentry=sigLowerLimit;kentry<sigUpperLimit;kentry++)
   {
      Long64_t k1entry = LoadTree(kentry);
      if (k1entry < 0) break;
      nb = fChain->GetEntry(kentry);
      if (data[PMT]>signalMax) signalMax = data[PMT];
    }
  if (signalMax>50) firstThreshold=(signalMax-*pedestal)/2.;
  return (firstThreshold);
}


//**************DETERMINE RANGE TO LOOK FOR SIGNALS
void Cstest1::TotalSignalRange(float threshold,int sigLowerLimit,int sigUpperLimit,int Range[],Int_t PMT)
{
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nb=0;

  cout<<"PMT= "<<PMT<<"\tthreshold= "<<threshold<<endl;
  //cout<<"threshold = "<<threshold<<"\tsigLowerLimit = "<<sigLowerLimit<<"\tsigUpperLimit = "<<sigUpperLimit<<endl;
 for (Long64_t j1entry=sigLowerLimit; j1entry<sigUpperLimit;j1entry++)
   //for (Long64_t j1entry=0; j1entry<=nentries;j1entry++)
  {
    Long64_t i1entry = LoadTree(j1entry);
    if (i1entry < 0) break;
    nb = fChain->GetEntry(j1entry);
      //cout<<"trigger = "<<trigger<<"\tj1entry = "<<j1entry<<"\tdata[PMT] = "<<data[PMT]<<endl;
    if (data[PMT] > threshold)
    {
      if (Range[0]==0) Range[0]=trigger-200.;
       Range[1]=trigger+200.;
    } 
    
    /* if (data[PMT] < threshold) */
    /*   { */
    /* 	if ((Range[0]!=0) && (Range[1]==0)) Range[1]=j1entry+200.; */
    /*   } */
  }
  //cout<<"range[0] = "<<Range[0]<<"\trange[1] = "<<Range[1]<<endl;
}

//**************CALCULATE INTEGRAL AND WIDTHS OF EACH SIGNAL
void Cstest1::SignalCalculator(int Range[],Int_t PMT, char direction, float *pedestal,float *integralA,float *integralB,int *widthA,int *widthB, int ModNum)
{
  Float_t trigdata[2] = {0};
  int threshForIntegral=50.;//originally at 50
  int aa = 0;//start trigger for first signal
  int bb = 0;//end trigger for first signal
  int aa1 = 0;//start trigger for second signal
  int bb1 = 0;//end trigger for second signal
//  float integralA = 0;
//  float integralB = 0;
//  int widthA = 0;
//  int widthB = 0;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nb=0;
  //cout<<"PMT = "<<PMT<<"\trange[0] = "<<Range[0]<<"\trange[1] = "<<Range[1]<<"\tpedestal = "<<*pedestal<<endl;
  bool firstSignal = false;
  for (Long64_t centry =0; centry <= nentries; centry++) 
  //for (Long64_t centry = Range[0];centry <= Range[1];centry++)
  { 
    Long64_t ientry = LoadTree(centry);
    if (ientry<0) break;
    nb = fChain->GetEntry(centry);
    trigdata[1]=data[PMT];
    if (trigger < Range[0]) continue; 
    if (trigger > Range[1] ) continue; 

    
    if (!firstSignal) {
      //start of first signal
      
      if ((trigdata[1] >= *pedestal+threshForIntegral) && (aa==0) )
	{
	  aa = trigger;
       
	  
    }
      if ( bb==0)  *integralA += (trigdata[1]-*pedestal); 
      //end of first signal
      if ((trigdata[1] < *pedestal+threshForIntegral)  && (bb == 0) && (aa!=0 ))
	{
	  bb=trigger;

	
      firstSignal = true;
    }	
    } else {
      //start of second signal
      //if (bb != 0) 
      
	  if (trigdata[1] >= *pedestal+threshForIntegral && (aa1==0))
	    {
	      
		
		  aa1 = trigger;
	   
	    }
	  if ( bb1==0)  *integralB += (trigdata[1]-*pedestal);  
	  //end of second signal
	  if ((trigdata[1] < *pedestal+threshForIntegral) && (bb1 ==0) && (aa1!=0)) 
	    { 
	     
	      
		  bb1 = trigger;
		
	    }
	
    }
    
    
    if (aa!= 0 && bb != 0 && aa1 != 0 && bb1 != 0) break; 
    //for ( *integralA += (trigdata[1]-*pedestal); 
    
  }//closes loop over signal range 
  
  //if (trigger == aa) *integralA += (trigdata[1]-*pedestal); 
 
  //if (trigger == aa1) *integralB += (trigdata[1]-*pedestal);


/* //Find start of first signal */
/*     if (trigdata[1] >= *pedestal+threshForIntegral) */
/*     { */
/*       if (aa == 0) */
/*       { */
/* //        a = trigger; //get first point of first signal */
/*         aa = trigger; //get first point of first signal */
/* //        cout<<"a = "<<a<<endl; */
/*       } */
/*         if (bb == 0) *integralA += (trigdata[1]-*pedestal); */
/*     } */

/* //Find end of first signal */
/*     if ((trigdata[1] < *pedestal+threshForIntegral) && (trigdata[0] >= *pedestal+threshForIntegral) && (aa1 == 0)) */
/*     { */
/*       if (bb == 0) */
/*       { */
/*         bb = trigger; //get last point of first signal */
/*  //       cout<<"b = "<<b<<endl; */
/*       } */
/*     } */

/* //Find start of second signal */
/*     if (bb != 0) */
/*     { */
/*       if (trigdata[1] >= *pedestal+threshForIntegral) */
/*       { */
/*         if (aa1 == 0) */
/*         { */
/*           aa1 = trigger; //get first point of second signal */
/*  //         cout<<"a1 = "<<a1<<endl; */
/*         } */
/*         if (bb1 == 0) *integralB += (trigdata[1]-*pedestal); */
/*       } */

/* //Find end of second signal */
/*       if ((trigdata[1] < *pedestal+threshForIntegral) && (trigdata[0] >= *pedestal+threshForIntegral) && (aa1 != 0)) */
/*       { */
/*         if (trigger != bb) */
/*         { */
/*           bb1 = trigger;// get last point of second signal */
/*  //         cout<<"b1 = "<<b1<<endl; */
/*         } */
/*       } */
/*     } */
/*     trigdata[0] = trigdata[1]; */
/*     if (aa!= 0 && bb != 0 && aa1 != 0 && bb1 != 0) break; */
/*   }//closes loop over signal range */

  *widthA = bb - aa;
  *widthB = bb1 - aa1;

  cout<<"widthA before = "<<*widthA<<endl;
  cout<<"widthB before = "<<*widthB<<endl;
  cout<< "Range[0]="<<Range[0]<<"\tRange[1]="<<Range[1]<<"\tRangeDiff="<<Range[1]-Range[0]<<"\twidthA = "<<*widthA<<"\twidthB = "<<*widthB<<endl;
  cout<<"integralA= "<<*integralA<<"\tintegralB= "<<*integralB<<endl;
  cout<<" start of first signal: "<<aa<<"\tend of first signal: "<<bb<<endl;
  cout<<" start of second signal: "<<aa1<<"\tend of second signal: "<<bb1<<endl;
 
//***Sets bad signals equal to 0 for D4,E1,E2 - same for both A and C sides
  if (direction=='2')//DIRECTION 2
  {
    if (ModNum%2==1)//ODD
    {
      if (PMT ==3 || PMT == 2 || PMT==12) *widthA = 0; //D4 or E1 - first signal is trash
      else if (PMT==13) *widthB = 0;                //E2       - second signal is trash
    }
    if (ModNum%2==0)//EVEN
    {
      if (PMT ==3 || PMT == 2 ||PMT==12) *widthB = 0; //D4 or E1 - second signal is trash
      else if (PMT==13) *widthA = 0;                //E2       - first signal is trash
    }
  }//end of direction 1
  if (direction=='1')//DIRECTION 1
  {
    if (ModNum%2==1)//ODD
    { 
      if (PMT ==3 || PMT == 2 ||  PMT==12) *widthB = 0; //D4 or E1 - second signal is trash
      else if (PMT==13) *widthA = 0;                //E2       - first signal is trash
    }
    if (ModNum%2==0)//EVEN
    {
      if ( PMT ==3 || PMT == 2 ||  PMT==12) *widthA = 0; //D4 or E1 - first signal is trash
      else if (PMT==13) *widthB = 0;                //E2       - second signal i trash
    }
  }//end of direction 2
  /* cout<<"widthA after = "<<*widthA<<endl; */
  /* cout<<"widthB after = "<<*widthB<<endl; */
  /* cout<<"integralA = "<<*integralA<<endl; */
  /* cout<<"integralB = "<<*integralB<<endl; */



}//end of signal selector

#endif // #ifdef cstest_cxx
