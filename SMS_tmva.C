#include "TMVA/Types.h"
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
using std::cout;
std::string outputListFileName;

//TMVA::Tools::Instance();

void SMS_tmva()
{
std::cout << std::endl;

std::cout << "===> Start TMVAClassification" << std::endl;
TFile* outSMSputFile = new TFile("SMSHappy_Model.root", "RECREATE"); 
TMVA::Factory *factory = new TMVA::Factory("TMVAClassification_RG",outSMSputFile,"V:!Silent:Color:Transformations=I:DrawProgressBar:AnalysisType=Classification");

TString sigFile="trainSMSample.csv";
TString bkgFile ="ScoringSMSdb.csv";

cout << ">>>> Adding variables phase\n";
factory->AddVariable("MINDATE",'I');
factory->AddVariable("RECENCY",'I');
factory->AddVariable("FREQUENCY",'I');
factory->AddVariable("MONETARY_VALUE",'F');

Double_t sigWeight = 1.0; // overall weight for all signal events
Double_t bkgWeight = 1.0; // overall weight for all background events
factory->SetInputTrees( sigFile, bkgFile, sigWeight, bkgWeight );
// Modify the binning in the ROC curve (for classification only)
/*(TMVA::gConfig().GetVariablePlotting()).fNbinsXOfROCCurve = 100;

(TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
(TMVA::gConfig().GetVariablePlotting()).fNbins1D = 60.0;
(TMVA::gConfig().GetVariablePlotting()).fNbins2D = 300.0;*/
cout << ">>>> Cutting\n";
TCut preselectionCut("MONETARY_VALUE > 0. && MONETARY_VALUE<500000 && FREQUENCY>1");
TCut mycutB = "MONETARY_VALUE > 0. && MONETARY_VALUE<500000 && FREQUENCY>1";
TCut mycutS = "MONETARY_VALUE > 0. && MONETARY_VALUE<500000 && FREQUENCY>1";
//factory->AddSpectator("TEL", 'I');
factory->PrepareTrainingAndTestTree(preselectionCut, "nTrain_Signal=16000:nTest_Signal=1451:nTrain_Background=800000:nTest_Background=118416:VerboseLevel=Debug");
factory->PrepareTrainingAndTestTree(mycutS, mycutB, "VerboseLevel=Debug:random");
//factory->BookMethod( TMVA::Types::kMLP, "MLPBFGS","H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS" );
factory->BookMethod(TMVA::Types::kBDT, "BDT", "MaxDepth=5:NTrees=10:MinNodeSize=9%:PruneStrength=10:SeparationType=GiniIndex");

factory->PrintHelpMessage("BDT");
cout << ">>>> doing TrainAllMethods\n";
factory->TrainAllMethods();
cout << ">>>> doing TestAllMethods\n";
factory->TestAllMethods();
cout << ">>>> doing EvaluateAllMethods\n";
factory->EvaluateAllMethods();

 // Save the output
   outSMSputFile->Close();

   std::cout << "===> Wrote root file: " << outSMSputFile->GetName() << std::endl;
   std::cout << "===> TMVAClassification is done!" << std::endl;

   delete factory;

cout <<" >>>> _________________________________________________________Reader application launched_________________________________________________________\n";

TFile* realdata = new TFile("SMSdata.root");

//realdata = "ip%2==1";

TFile *target = new TFile("real_data-mva_outputSMS.root","RECREATE" );
//TTree* realdataTree = ((TTree*)realdata->Get("ntuple"));
TTree* realdataTree = ((TTree*)realdata->Get("ntuple"));
TTree *tree = new TTree("panopticon_basic","treelibrated tree");
TMVA::Reader *reader = new TMVA::Reader( "V:Color:!Silent" );

Float_t var[4];

    reader->AddVariable ("MINDATE", &var[0]);
    reader->AddVariable ("RECENCY", &var[1]);
    reader->AddVariable ("FREQUENCY", &var[2]);
    reader->AddVariable ("MONETARY_VALUE", &var[3]);

//reader->AddVariable("TEL", &var[4]);
cout <<" >>>> All is good, next phase \n";
 reader->BookMVA("BDT", "weights/TMVAClassification_RG_BDT.weights.xml");

Float_t uservar[0];

//Short_t address_live_month, sex, married, service_month; 
//UShort_t age;
//UInt_t address_live_month,last_work_month;
Int_t MINDATE,RECENCY,FREQUENCY;
ULong64_t TEL;
 realdataTree->SetBranchAddress("MINDATE",&MINDATE);
 realdataTree->SetBranchAddress("RECENCY",&RECENCY);
 realdataTree->SetBranchAddress("FREQUENCY",&FREQUENCY);
 realdataTree->SetBranchAddress("MONETARY_VALUE",&uservar[0]);
 realdataTree->SetBranchAddress("TEL",&TEL);

Float_t BDT_response;

 tree->Branch("BDT_response",&BDT_response);
outputListFileName = "SMS_mva.csv";
cout << "opening file "<<outputListFileName <<"\n";

ofstream* outCsv = new ofstream(outputListFileName.c_str());
for (Long64_t ievt=0; ievt<realdataTree->GetEntries();ievt++) 
{

 if (ievt%200000 == 0) std::cout << "--- ... Processing event: " << ievt <<std::endl;
 
realdataTree->GetEntry(ievt);

 var[0]=MINDATE;
 var[1]=RECENCY;
 var[2]=FREQUENCY;
 var[3]=uservar[0];
 

BDT_response=reader->EvaluateMVA("BDT");

if (BDT_response >= 0.1)

*outCsv << TEL << ";" << BDT_response <<"\n";

tree->Fill();

}

outCsv->close();
delete outCsv;
 delete reader;

 tree->Write();
}
