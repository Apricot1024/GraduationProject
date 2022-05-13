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

G4int totalNum = 0;//排除电子对效应影响的总粒子数
G4int convNum = 0;//
G4int photNum =0;
G4int comptNum = 0;
G4int RaylNum = 0;
G4int noComptNum = 0;
G4int noComptnRaylNum = 0;
G4int noCoNum = 0;
int eventIDflag[3000000] = {3000001};
int eventIDconvflag[3000000] = {3000001};
int eventIDRaylflag[3000000] = {3000001};
int eventIDcomptflag[3000000] = {3000001};
int eventIDphotflag[3000000] = {3000001};
int eventIDcomptRaylflag[3000000] = {3000001};
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
  if (PostProcessName == "conv")
  {
    eventIDconvflag[eventID] = eventID;
  }

  if (PostProcessName == "compt")
  {
    eventIDcomptflag[eventID] = eventID;
    eventIDcomptRaylflag[eventID] = eventID;
  }

  if (PostProcessName == "Rayl")
  {
    eventIDRaylflag[eventID] = eventID;
    eventIDcomptRaylflag[eventID] = eventID;
  }

  if (PostProcessName == "phot")
  {
    eventIDphotflag[eventID] = eventID;
  }
  
  if (nextpv!=NULL)
  {
    G4String nextvolumename = nextpv->GetName();
    if((nextvolumename=="Shape2")&&(eventID>=300000))
    {
      G4double E=aTrack->GetKineticEnergy();
      G4String particleName =  step->GetTrack()->GetDefinition()->GetParticleName();
      if (E == 3)
      {
        noCoNum += 1;
      }


      if (eventID == eventIDflag[eventID])
      {
        
      }else{
        eventIDflag[eventID] = eventID;
        if (particleName == "gamma")
        {
          totalNum += 1;
        }
      }
      
      if ((eventID == eventIDconvflag[eventID])&&(particleName == "gamma"))
      {
        convNum += 1;
      }

      if ((eventID == eventIDphotflag[eventID])&&(particleName == "gamma"))
      {
        photNum += 1;
      }

      if ((eventID == eventIDcomptflag[eventID])&&(particleName == "gamma"))
      {
        comptNum += 1;
      }

      if ((eventID == eventIDRaylflag[eventID])&&(particleName == "gamma"))
      {
        RaylNum += 1;
      }

      if ((eventID != eventIDcomptflag[eventID])&&(particleName == "gamma"))
      {
        noComptNum += 1;
      }

      if ((eventID != eventIDcomptRaylflag[eventID])&&(particleName == "gamma"))
      {
        noComptnRaylNum += 1;
      }

    }


    if ((eventID == 2999999) & (outputcode == 10))
    {
      outputcode = eventID; //使eventID最大时只输出一次，不重复输出。
      G4cout<<"EffectivetotalNum:"<< totalNum <<G4endl;
      G4cout<<"EffectivenoCoNum:"<< noCoNum <<G4endl;
      G4cout<<"EffectivenoComptNum:"<< noComptNum <<G4endl;
      G4cout<<"EffectivenoComptnRaylNum:"<< noComptnRaylNum <<G4endl;
      G4cout<<"EffectivephotNum:"<< photNum <<G4endl;
      G4cout<<"EffectiveconvNum:"<< convNum <<G4endl;
      G4cout<<"EffectivecomptNum:"<< comptNum <<G4endl;
      G4cout<<"EffectiveRaylNum:"<< RaylNum <<G4endl;
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

