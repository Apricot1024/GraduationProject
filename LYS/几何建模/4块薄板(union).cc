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
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"

#include "G4MultiUnion.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  
  // Envelope parameters
  //
  G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_Galactic");
   
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World
  //
  G4double world_sizeXY = 1.2*env_sizeXY;
  G4double world_sizeZ  = 1.2*env_sizeZ;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  //     
  // Envelope
  //  
  G4Box* solidEnv =    
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size
      
  G4LogicalVolume* logicEnv =                         
    new G4LogicalVolume(solidEnv,            //its solid
                        env_mat,             //its material
                        "Envelope");         //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
 
  // Define three -G4Box- shapes
  //
  G4Material* muion_mat = nist->FindOrBuildMaterial("G4_Pb");
  G4ThreeVector pos = G4ThreeVector(0, 0, 0);

  G4Box* box1 = new G4Box("Box1", 10.*cm, 10.*cm, 4.*um);
  G4Box* box2 = new G4Box("Box2", 10.*cm, 10.*cm, 4.*um);
  G4Box* box3 = new G4Box("Box3", 10.*cm, 10.*cm, 4.*um);
  G4Box* box4 = new G4Box("Box3", 10.*cm, 10.*cm, 4.*um);

  // Define displacements for the shapes
  //
  G4RotationMatrix rotm = G4RotationMatrix();
  G4ThreeVector position1 = G4ThreeVector(0.,0.,-10*cm);
  G4ThreeVector position2 = G4ThreeVector(0.,0.,-9.9*cm);
  G4ThreeVector position3 = G4ThreeVector(0.,0.,-9.8*cm);
  G4ThreeVector position4 = G4ThreeVector(0.,0.,-9.7*cm);

  G4Transform3D tr1 = G4Transform3D(rotm,position1);
  G4Transform3D tr2 = G4Transform3D(rotm,position2);
  G4Transform3D tr3 = G4Transform3D(rotm,position3);
  G4Transform3D tr4 = G4Transform3D(rotm,position4);

  // Initialise a MultiUnion structure
  //
  G4MultiUnion* munion_solid = new G4MultiUnion("Boxes_Union");
  // Add the shapes to the structure
  //
  munion_solid->AddNode(*box1,tr1);
  munion_solid->AddNode(*box2,tr2);
  munion_solid->AddNode(*box3,tr3);
  munion_solid->AddNode(*box3,tr4);

  // Finally close the structure
  //
  munion_solid->Voxelize();
  // Associate it to a logical volume as a normal solid
  //
  G4LogicalVolume* lvol =
  new G4LogicalVolume(munion_solid, // its solid
                                       muion_mat, // its material
                                    "Boxes_Union_LV"); // its name

  new G4PVPlacement(0,                       //no rotation
                    pos,                    //at position
                    lvol,             //its logical volume
                    "Boxes_Union_LV",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // Set munion_solid as scoring volume
  //
  fScoringVolume = lvol;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
