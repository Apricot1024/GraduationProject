//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1SteppingAction.cc
/// \brief Implementation of the B1SteppingAction class
#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::B1SteppingAction(B1EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::~B1SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4int i = 0;//排除电子对效应影响的总粒子数
G4int j = 0;//未经散射的粒子数
G4int c = 0;//由于电子对效应的粒子数
G4int count1 = 0;
G4int count2 = 0;
G4float Eall = 0.0;
G4float Enoco = 0.0;
double muenrho[35] = {3599.0,1188.0,526.2,161.4,133.0,
146.0,76.36,39.31,22.7,9.466,4.742,1.334,0.5389,0.1537,
0.06833,0.04098,0.03041,0.02407,0.02325,0.02496,0.02672,
0.02872,0.02949,0.02966,0.02953,0.02882,0.02789,0.02666,
0.02547,0.02345,0.02057,0.01870,0.0174,0.01647,0.01525};
G4double muenrho11 = 0.01647;
// G4int eventIDmax = 0;
G4int flagcodeRP = 0;
G4int flagcodeConv = 0;
G4int outputcode = 10; //是否输出判断

void B1SteppingAction::UserSteppingAction(const G4Step* step)
{
  // G4cout<<"UserSteppingAction1"<<G4endl;
  if (!fScoringVolume) { 
    const B1DetectorConstruction* detectorConstruction
      = static_cast<const B1DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
  }

  // get volume of the current step
  G4LogicalVolume* volume 
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
 
  G4StepPoint* prePoint = step->GetPreStepPoint();
  // G4StepPoint* endPoint = step->GetPostStepPoint();
  G4String nowvolumename= prePoint->GetTouchableHandle()->GetVolume()->GetName();
  G4Track *aTrack = step->GetTrack();
  G4VPhysicalVolume* nextpv=aTrack->GetNextVolume();
  G4int eventID = (G4EventManager::GetEventManager())->GetConstCurrentEvent()->GetEventID();
  G4String PostProcessName = step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
  
  if (nextpv!=NULL)
  {
    G4String nextvolumename = nextpv->GetName();
    if(nextvolumename=="Shape2")
    {
      G4double E = aTrack->GetKineticEnergy();
      G4String particleName = step->GetTrack()->GetDefinition()->GetParticleName();
      if (particleName == "gamma")
      {
        j += 1;
        if (E == 6)
        {
          count1 += 1;
          Enoco = Enoco + (E * muenrho11);
          Eall = Eall + (E * muenrho11);
        }else if ((E > 7)&&(E <= 8))
        {
          Eall = Eall + (E * muenrho[34]);
        }else if ((E > 5.5)&&(E <= 7))
        {
          Eall = Eall + (E * muenrho[33]);
        }else if ((E > 4.5)&&(E <= 5.5))
        {
          Eall = Eall + (E * muenrho[32]);
        }else if ((E > 3.5)&&(E <= 4.5))
        {
          Eall = Eall + (E * muenrho[31]);
        }else if ((E > 2.5)&&(E <= 3.5))
        {
          Eall = Eall + (E * muenrho[30]);
        }else if ((E > 1.75)&&(E <= 2.5))
        {
          Eall = Eall + (E * muenrho[29]);
        }else if ((E > 1.375)&&(E <= 1.75))
        {
          Eall = Eall + (E * muenrho[28]);
        }else if ((E > 1.125)&&(E <= 1.375))
        {
          Eall = Eall + (E * muenrho[27]);
        }else if ((E > 0.9)&&(E <= 1.125))
        {
          Eall = Eall + (E * muenrho[26]);
        }else if ((E > 0.7)&&(E <= 0.9))
        {
          Eall = Eall + (E * muenrho[25]);
        }else if ((E > 0.55)&&(E <= 0.7))
        {
          Eall = Eall + (E * muenrho[24]);
        }else if ((E > 0.45)&&(E <= 0.55))
        {
          Eall = Eall + (E * muenrho[23]);
        }else if ((E > 0.35)&&(E <= 0.45))
        {
          Eall = Eall + (E * muenrho[22]);
        }else if ((E > 0.25)&&(E <= 0.35))
        {
          Eall = Eall + (E * muenrho[21]);
        }else if ((E > 0.175)&&(E <= 0.25))
        {
          Eall = Eall + (E * muenrho[20]);
        }else if ((E > 0.125)&&(E <= 0.175))
        {
          Eall = Eall + (E * muenrho[19]);
        }else if ((E > 0.09)&&(E <= 0.125))
        {
          Eall = Eall + (E * muenrho[18]);
        }else if ((E > 0.07)&&(E <= 0.09))
        {
          Eall = Eall + (E * muenrho[17]);
        }else if ((E > 0.055)&&(E <= 0.07))
        {
          Eall = Eall + (E * muenrho[16]);
        }else if ((E > 0.045)&&(E <= 0.055))
        {
          Eall = Eall + (E * muenrho[15]);
        }else if ((E > 0.035)&&(E <= 0.045))
        {
          Eall = Eall + (E * muenrho[14]);
        }else if ((E > 0.025)&&(E <= 0.035))
        {
          Eall = Eall + (E * muenrho[13]);
        }else if ((E > 0.0175)&&(E <= 0.025))
        {
          Eall = Eall + (E * muenrho[12]);
        }else if ((E > 0.0125)&&(E <= 0.0175))
        {
          Eall = Eall + (E * muenrho[11]);
        }else if ((E > 0.009)&&(E <= 0.0125))
        {
          Eall = Eall + (E * muenrho[10]);
        }else if ((E > 0.007)&&(E <= 0.009))
        {
          Eall = Eall + (E * muenrho[9]);
        }else if ((E > 0.0055)&&(E <= 0.007))
        {
          Eall = Eall + (E * muenrho[8]);
        }else if ((E > 0.0045)&&(E <= 0.0055))
        {
          Eall = Eall + (E * muenrho[7]);
        }else if ((E > 0.0036)&&(E <= 0.0045))
        {
          Eall = Eall + (E * muenrho[6]);
        }else if ((E > 0.0032)&&(E <= 0.0036))
        {
          Eall = Eall + (E * muenrho[5]);
        }else if ((E > 0.0031)&&(E <= 0.0032))
        {
          Eall = Eall + (E * muenrho[4]);
        }else if ((E > 0.0025)&&(E <= 0.0031))
        {
          Eall = Eall + (E * muenrho[3]);
        }else if ((E > 0.00175)&&(E <= 0.0025))
        {
          Eall = Eall + (E * muenrho[2]);
        }else if ((E > 0.00125)&&(E <= 0.00175))
        {
          Eall = Eall + (E * muenrho[1]);
        }else if (E <= 0.00125)
        {
          Eall = Eall + (E * muenrho[0]);
        }
        
      }
      

    }
    if ((eventID == 9999999) & (outputcode == 10))
    if ((eventID == 9999999) & (outputcode == 10))
    {
      outputcode = eventID; //使eventID最大时只输出一次，不重复输出。
      G4cout<<"EffectiveCountall:"<< j <<G4endl;
      G4cout<<"EffectiveCountnoscattering:"<< count1 <<G4endl;
      G4cout<<"countEall="<< Eall <<G4endl;
      G4cout<<"countEnoco="<< Enoco <<G4endl;
    }
  }

  
  // check if we are in scoring volume
  if (volume != fScoringVolume) return;

  // collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);  
  // G4cout<<"UserSteppingAction2"<<G4endl;

}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

