
#include "Riostream.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

void rrev() {

   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("rrev.C","");
   dir.ReplaceAll("/./","/");

   TFile *f = new TFile("SMSdata.root","RECREATE");
   TTree *tree = new TTree("ntuple","data from csv file");
   tree->ReadFile("ScoringSMSdb.txt","MINDATE/I:TEL/l:RECENCY/I:MONETARY_VALUE/F:FREQUENCY/I",' ');
   f->Write();
}





/*
#include "Riostream.h"
void rrev() {
//  Read data from an ascii file and create a root file with an histogram and an ntuple.
//   see a variant of this macro in basic2.C
//Author: Rene Brun


// read file $ROOTSYS/tutorials/tree/ScoringSMSdb.csv
// this file has 3 columns of float data
   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("rrev.C","");
   dir.ReplaceAll("/./","/");
   ifstream in;
   in.open(Form("%sScoringSMSdb.csv",dir.Data()));

   Float_t MINDATE,TEL,RECENCY,MONETARY_VALUE,FREQUENCY;
   Int_t nlines = 0;
   TFile *f = new TFile("basic.root","RECREATE");
   TH1F *h1 = new TH1F("h1","x distribution",100,-4,4);
   TNtuple *ntuple = new TNtuple("ddata","data from ascii file","MINDATE:TEL:RECENCY:MONETARY_VALUE:FREQUENCY");

   while (1) {
      in >> MINDATE >> TEL >> RECENCY >> MONETARY_VALUE >> FREQUENCY;
      if (!in.good()) break;
      if (nlines < 5) printf("MINDATE=%8f, TEL=%8f, RECENCY=%8f,MONETARY_VALUE=%8f,FREQUENCY=%8f\n",MINDATE,TEL,RECENCY,MONETARY_VALUE,FREQUENCY);
      h1->Fill(MINDATE);
      ntuple->Fill(MINDATE,TEL,RECENCY,MONETARY_VALUE,FREQUENCY);
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

   f->Write();
}
*/
