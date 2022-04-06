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
int eventIDflag[1000000] = {10000001};  //重复计数排除数组
int eventIDconvflag[1000000] = {10000001};  // 对发生电子对效应的粒子进行统计
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
  if (PostProcessName == "conv") //conv表示电子对效应
  {
    eventIDflag[eventID] = eventID;
    eventIDconvflag[eventID] = eventID;
  }
  
  if (nextpv!=NULL)
  {
    G4String nextvolumename = nextpv->GetName();
    if(nextvolumename=="Shape2")
    {
      G4double E=aTrack->GetKineticEnergy();
      G4String particleName =  step->GetTrack()->GetDefinition()->GetParticleName();
      if (E == 0.5)
      {
        j = j + 1;
      }
      for (int k = 0; k < 1000000; k++)
      {
        if (eventID == eventIDflag[k])
        {
          flagcodeRP = 1;
          break;
        }
      }


      //若该粒子的event发生过电子对效应，则将flagcodeConv标为1.
      for (int k = 0; k < 1000000; k++)
      {
        if (eventID == eventIDconvflag[k])
        {
          flagcodeConv = 1;
          break;
        }
      }
      
      

      if (flagcodeRP == 1)
      {
        flagcodeRP = 0;
      }else{
        eventIDflag[eventID] = eventID;
        if (particleName == "gamma")
        {
          i = i + 1;
        }
      }

      //若该粒子的event发生过电子对效应(flagcodeConv==1),则计数c
      if (flagcodeConv == 1)
      {
        if (particleName == "gamma")
        {
          c = c + 1;
        }
        flagcodeConv = 0;
      }
      
      
    }


    if ((eventID == 999999) & (outputcode == 10))
    {
      outputcode = eventID; //使eventID最大时只输出一次，不重复输出。
      G4cout<<"EffectiveCountallnoconv:"<< i <<G4endl;
      G4cout<<"EffectiveCountnoscattering:"<< j <<G4endl;
      G4cout<<"EffectiveCountconv:"<< c <<G4endl;
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

