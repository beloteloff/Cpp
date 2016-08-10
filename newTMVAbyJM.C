#include "TMVA/Types.h"
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"

//TMVA::Tools::Instance();

void newTMVAbyJM()
{
std::cout << std::endl;
   std::cout << "==> Start TMVAClassification" << std::endl;
TFile* outputFile = new TFile("OutFileName.root", "RECREATE"); 
TMVA::Factory *factory = new TMVA::Factory("TMVAClassification",outputFile,"V:!Silent:Color:Transformations=I:DrawProgressBar:AnalysisType=Classification");

TFile* signal = new TFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTreeDebtors.root");
TTree* sigTree = (TTree*)signal->Get("panopticon_basic");
//TFile* data = new TFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_935-936.root");
 TChain* dataTree = new TChain("panopticon_basic"); 
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_900-901.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_901-902.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9030-9035.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9035-9040.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9060-9065.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9065-9070.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_913-914.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_919-920.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_921-922.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_922-923.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_925-926.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_930-931.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_932-933.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_933-934.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_934-935.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_935-936.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_936-937.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_937-938.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_938-939.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_939-940.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_940-941.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_941-942.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_942-943.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_954-955.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_957-958.root");
 dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_958-959.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_959-960.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9600-9605.root");
 dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9610-9615.root");
 dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9615-9620.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9640-9645.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9645-9650.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9650-9655.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9675-9680.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_9680-9685.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_969-970.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_978-979.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_979-980.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_980-981.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_981-982.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_983-984.root");
 dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_984-985.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_985-986.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_986-987.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_990-991.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_991-992.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_992-993.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_993-994.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_994-995.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_995-996.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_996-997.root");
  dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_997-998.root");
 //dataTree->AddFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_998-999.root");

//TTree* dataTree = (TTree*)dataTree->Get("panopticon_basic");

//Double_t signalWeight = 1;
//Double_t backgroundWeight= 1;
factory->AddSignalTree(sigTree,1);
factory->AddBackgroundTree(dataTree,1);
//factory->SetSignalWeightExpression( "2" );
//factory->SetBackgroundWeightExpression( "0.5" );
//factory->AddSignalTree(sigTree,signalWeight);
//factory->AddBackgroundTree(dataTree,backgroundWeight);
TCut mycutB = "pPnone%100==0";
TCut mycutS = "";
 factory->AddVariable("pEquifaxResponse",'F');
 factory->AddVariable("pEquifaxDefault",'F');
 factory->AddVariable("pSex := log(pSex)",'I');
 factory->AddVariable("pAge := log(pAge)",'I');
 factory->AddVariable("pTopQwCat3",'I');
 factory->AddVariable("pQdTopRegionId",'I');
 factory->AddVariable("pQd6MAvrg",'I');
 factory->AddVariable("pTopQwCat1",'I');
 factory->AddVariable("pTopQwCat2",'I');
 factory->AddVariable("pTopOsmpPrv3",'F');
 factory->AddVariable("pTopOsmpPrv2",'F');
 factory->AddVariable("pTopOsmpPrv1",'F');
 factory->AddVariable("pQd6MCount",'I');
 //factory->PrepareTrainingAndTestTree("", "nTrain_Signal=704342:nTest_Signal=704342:nTrain_Background=3000000:nTest_Background=3000000:VerboseLevel=Debug");

 factory->PrepareTrainingAndTestTree(mycutS, mycutB, "nTrain_Signal=200000:nTest_Signal=200000:VerboseLevel=Debug:random");
//factory->BookMethod(TMVA::Types::kBDT, "BDT", "IgnoreNegWeightsInTraining=True");
factory->BookMethod(TMVA::Types::kBDT, "BDT", "MaxDepth=7:IgnoreNegWeightsInTraining=True:NTrees=1000:MinNodeSize=9%:CreateMVAPdfs=True:UseRandomisedTrees=True");

factory->PrintHelpMessage("BDT");
cout << ">>>> doing TrainAllMethods\n";
factory->TrainAllMethods();
cout << ">>>> doing TestAllMethods\n";
factory->TestAllMethods();
cout << ">>>> doing EvaluateAllMethods\n";
factory->EvaluateAllMethods();

 // Save the output
   outputFile->Close();

   std::cout << "===> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "===> TMVAClassification is done!" << std::endl;

   delete factory;

   // Launch the GUI for the root macros
   // if (!gROOT->IsBatch()) TMVAGui("outfileName.root"); 

 
cout <<" >>>> _________________________________________________________Reader application launched_________________________________________________________\n";

TFile* realdata = new TFile("/home/v.vasilev/RootMonitor/run/panopticonForBDTinRandomForestTMVA/panopticonBasicTTree_998-999.root");

TTree* realdataTree = ((TTree*)realdata->Get("panopticon_basic"));

TFile *target = new TFile("real_data-mva_output.root","RECREATE" );

TTree *tree = new TTree("panopticon_basic","treelibrated tree");

cout <<" >>>> Does it really work (2-nd)?\n";
//TMVA::Tools::Instance();
TMVA::Reader *reader = new TMVA::Reader( "V:Color:!Silent" );
cout <<" >>>> Does it really work (3-nd)?\n";

Float_t var[13];
    reader->AddVariable ("pEquifaxResponse", &var[0]);
    reader->AddVariable ("pEquifaxDefault", &var[1]);
    reader->AddVariable ("log(pSex)", &var[2]);
    reader->AddVariable ("log(pAge)", &var[3]);
    reader->AddVariable ("pTopQwCat3", &var[4]);
    reader->AddVariable ("pQdTopRegionId", &var[5]);
    reader->AddVariable("pQd6MAvrg", &var[6]);
    reader->AddVariable("pTopQwCat1", &var[7]);
    reader->AddVariable("pTopQwCat2", &var[8]);
    reader->AddVariable("pTopOsmpPrv3", &var[9]);
    reader->AddVariable("pTopOsmpPrv2", &var[10]);
    reader->AddVariable("pTopOsmpPrv1", &var[11]);
    reader->AddVariable("pQd6MCount", &var[12]);

cout <<" >>>> Does it really work (4-th)?\n";
 reader->BookMVA("BDT", "weights/TMVAClassification_BDT.weights.xml");

cout <<" >>>> Does it really work (5-th)?\n";

Float_t uservar[3];
Short_t pSex, pTopQwCat3, pTopQwCat1, pTopQwCat2; 
UShort_t pAge;
Int_t pQdTopRegionId;
UInt_t pTopOsmpPrv3, pTopOsmpPrv2, pTopOsmpPrv1;
Int_t pQd6MCount;
 realdataTree->SetBranchAddress("pEquifaxResponse",&uservar[0]);
 realdataTree->SetBranchAddress("pEquifaxDefault",&uservar[1]);
 realdataTree->SetBranchAddress("pSex",&pSex);
 realdataTree->SetBranchAddress("pAge",&pAge);
 realdataTree->SetBranchAddress("pTopQwCat3",&pTopQwCat3);
 realdataTree->SetBranchAddress("pQdTopRegionId",&pQdTopRegionId);
 realdataTree->SetBranchAddress("pQd6MAvrg",&uservar[2]);

 realdataTree->SetBranchAddress("pTopQwCat1",&pTopQwCat1);
 realdataTree->SetBranchAddress("pTopQwCat2",&pTopQwCat2);
 realdataTree->SetBranchAddress("pTopOsmpPrv3",&pTopOsmpPrv3);
 realdataTree->SetBranchAddress("pTopOsmpPrv2",&pTopOsmpPrv2);
 realdataTree->SetBranchAddress("pTopOsmpPrv1",&pTopOsmpPrv1);
 realdataTree->SetBranchAddress("pQd6MCount",&pQd6MCount);

cout <<" >>>> Does it really work (6-th)?\n";

 //tree->Branch("pQd6MCount",&pQd6MCount);

Float_t BDT_response;

 tree->Branch("BDT_response",&BDT_response);

for (Long64_t ievt=0; ievt<realdataTree->GetEntries();ievt++) {

 if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt <<std::endl;
 

 realdataTree->GetEntry(ievt);

 var[0]=TMath::Log(uservar[0]);
 var[1]=uservar[1];
 var[2]=1+pSex;
 var[3]=pAge;
 var[4]=pTopQwCat3;
 var[5]=pQdTopRegionId;
 var[6]=1-uservar[2];
 var[7]=pTopQwCat1;
 var[8]=pTopQwCat2;
 var[9]=pTopOsmpPrv3;
 var[10]=pTopOsmpPrv2;
 var[11]=pTopOsmpPrv1;
 var[12]=pQd6MCount;
 
BDT_response=reader->EvaluateMVA("BDT");


 tree->Fill();

}
 delete reader;

 tree->Write();
}
