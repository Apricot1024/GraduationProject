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
  G4Box* box4 = new G4Box("Box4", 10.*cm, 10.*cm, 4.*um);
  G4Box* box5 = new G4Box("Box5", 10.*cm, 10.*cm, 4.*um);
  G4Box* box6 = new G4Box("Box6", 10.*cm, 10.*cm, 4.*um);
  G4Box* box7 = new G4Box("Box7", 10.*cm, 10.*cm, 4.*um);
  G4Box* box8 = new G4Box("Box8", 10.*cm, 10.*cm, 4.*um);
  G4Box* box9 = new G4Box("Box9", 10.*cm, 10.*cm, 4.*um);
  G4Box* box10 = new G4Box("Box10", 10.*cm, 10.*cm, 4.*um);
  G4Box* box11 = new G4Box("Box11", 10.*cm, 10.*cm, 4.*um);
  G4Box* box12 = new G4Box("Box12", 10.*cm, 10.*cm, 4.*um);
  G4Box* box13 = new G4Box("Box13", 10.*cm, 10.*cm, 4.*um);
  G4Box* box14 = new G4Box("Box14", 10.*cm, 10.*cm, 4.*um);
  G4Box* box15 = new G4Box("Box15", 10.*cm, 10.*cm, 4.*um);
  G4Box* box16 = new G4Box("Box16", 10.*cm, 10.*cm, 4.*um);
  G4Box* box17 = new G4Box("Box17", 10.*cm, 10.*cm, 4.*um);
  G4Box* box18 = new G4Box("Box18", 10.*cm, 10.*cm, 4.*um);
  G4Box* box19 = new G4Box("Box19", 10.*cm, 10.*cm, 4.*um);
  G4Box* box20 = new G4Box("Box20", 10.*cm, 10.*cm, 4.*um);
  G4Box* box21 = new G4Box("Box21", 10.*cm, 10.*cm, 4.*um);
  G4Box* box22 = new G4Box("Box22", 10.*cm, 10.*cm, 4.*um);
  G4Box* box23 = new G4Box("Box23", 10.*cm, 10.*cm, 4.*um);
  G4Box* box24 = new G4Box("Box24", 10.*cm, 10.*cm, 4.*um);
  G4Box* box25 = new G4Box("Box25", 10.*cm, 10.*cm, 4.*um);
  G4Box* box26 = new G4Box("Box26", 10.*cm, 10.*cm, 4.*um);
  G4Box* box27 = new G4Box("Box27", 10.*cm, 10.*cm, 4.*um);
  G4Box* box28 = new G4Box("Box28", 10.*cm, 10.*cm, 4.*um);
  G4Box* box29 = new G4Box("Box29", 10.*cm, 10.*cm, 4.*um);
  G4Box* box30 = new G4Box("Box30", 10.*cm, 10.*cm, 4.*um);
  G4Box* box31 = new G4Box("Box31", 10.*cm, 10.*cm, 4.*um);
  G4Box* box32 = new G4Box("Box32", 10.*cm, 10.*cm, 4.*um);
  G4Box* box33 = new G4Box("Box33", 10.*cm, 10.*cm, 4.*um);
  G4Box* box34 = new G4Box("Box34", 10.*cm, 10.*cm, 4.*um);
  G4Box* box35 = new G4Box("Box35", 10.*cm, 10.*cm, 4.*um);
  G4Box* box36 = new G4Box("Box36", 10.*cm, 10.*cm, 4.*um);
  G4Box* box37 = new G4Box("Box37", 10.*cm, 10.*cm, 4.*um);
  G4Box* box38 = new G4Box("Box38", 10.*cm, 10.*cm, 4.*um);
  G4Box* box39 = new G4Box("Box39", 10.*cm, 10.*cm, 4.*um);
  G4Box* box40 = new G4Box("Box40", 10.*cm, 10.*cm, 4.*um);
  G4Box* box41 = new G4Box("Box41", 10.*cm, 10.*cm, 4.*um);


  // Define displacements for the shapes
  //
  G4RotationMatrix rotm = G4RotationMatrix();
  G4ThreeVector position1 = G4ThreeVector(0.,0.,-10*cm);
  G4ThreeVector position2 = G4ThreeVector(0.,0.,-9.5*cm);
  G4ThreeVector position3 = G4ThreeVector(0.,0.,-9.0*cm);
  G4ThreeVector position4 = G4ThreeVector(0.,0.,-8.5*cm);
  G4ThreeVector position5 = G4ThreeVector(0.,0.,-8*cm);
  G4ThreeVector position6 = G4ThreeVector(0.,0.,-7.5*cm);
  G4ThreeVector position7 = G4ThreeVector(0.,0.,-7*cm);
  G4ThreeVector position8 = G4ThreeVector(0.,0.,-6.5*cm);
  G4ThreeVector position9 = G4ThreeVector(0.,0.,-6*cm);
  G4ThreeVector position10 = G4ThreeVector(0.,0.,-5.5*cm);
  G4ThreeVector position11 = G4ThreeVector(0.,0.,-5*cm);
  G4ThreeVector position12 = G4ThreeVector(0.,0.,-4.5*cm);
  G4ThreeVector position13 = G4ThreeVector(0.,0.,-4*cm);
  G4ThreeVector position14 = G4ThreeVector(0.,0.,-3.5*cm);
  G4ThreeVector position15 = G4ThreeVector(0.,0.,-3*cm);
  G4ThreeVector position16 = G4ThreeVector(0.,0.,-2.5*cm);
  G4ThreeVector position17 = G4ThreeVector(0.,0.,-2*cm);
  G4ThreeVector position18 = G4ThreeVector(0.,0.,-1.5*cm);
  G4ThreeVector position19 = G4ThreeVector(0.,0.,-1*cm);
  G4ThreeVector position20 = G4ThreeVector(0.,0.,-0.5*cm);
  G4ThreeVector position21 = G4ThreeVector(0.,0.,0);
  G4ThreeVector position41 = G4ThreeVector(0.,0.,10*cm);
  G4ThreeVector position40 = G4ThreeVector(0.,0.,9.5*cm);
  G4ThreeVector position39 = G4ThreeVector(0.,0.,9.0*cm);
  G4ThreeVector position38 = G4ThreeVector(0.,0.,8.5*cm);
  G4ThreeVector position37 = G4ThreeVector(0.,0.,8*cm);
  G4ThreeVector position36 = G4ThreeVector(0.,0.,7.5*cm);
  G4ThreeVector position35 = G4ThreeVector(0.,0.,7*cm);
  G4ThreeVector position34 = G4ThreeVector(0.,0.,6.5*cm);
  G4ThreeVector position33 = G4ThreeVector(0.,0.,6*cm);
  G4ThreeVector position32 = G4ThreeVector(0.,0.,5.5*cm);
  G4ThreeVector position31 = G4ThreeVector(0.,0.,5*cm);
  G4ThreeVector position30 = G4ThreeVector(0.,0.,4.5*cm);
  G4ThreeVector position29 = G4ThreeVector(0.,0.,4*cm);
  G4ThreeVector position28 = G4ThreeVector(0.,0.,3.5*cm);
  G4ThreeVector position27 = G4ThreeVector(0.,0.,3*cm);
  G4ThreeVector position26 = G4ThreeVector(0.,0.,2.5*cm);
  G4ThreeVector position25 = G4ThreeVector(0.,0.,2*cm);
  G4ThreeVector position24 = G4ThreeVector(0.,0.,1.5*cm);
  G4ThreeVector position23 = G4ThreeVector(0.,0.,1*cm);
  G4ThreeVector position22 = G4ThreeVector(0.,0.,0.5*cm);

  G4Transform3D tr1 = G4Transform3D(rotm,position1);
  G4Transform3D tr2 = G4Transform3D(rotm,position2);
  G4Transform3D tr3 = G4Transform3D(rotm,position3);
  G4Transform3D tr4 = G4Transform3D(rotm,position4);
  G4Transform3D tr5 = G4Transform3D(rotm,position5);
  G4Transform3D tr6 = G4Transform3D(rotm,position6);
  G4Transform3D tr7 = G4Transform3D(rotm,position7);
  G4Transform3D tr8 = G4Transform3D(rotm,position8);
  G4Transform3D tr9 = G4Transform3D(rotm,position9);
  G4Transform3D tr10 = G4Transform3D(rotm,position10);
  G4Transform3D tr11 = G4Transform3D(rotm,position11);
  G4Transform3D tr12 = G4Transform3D(rotm,position12);
  G4Transform3D tr13 = G4Transform3D(rotm,position13);
  G4Transform3D tr14 = G4Transform3D(rotm,position14);
  G4Transform3D tr15 = G4Transform3D(rotm,position15);
  G4Transform3D tr16 = G4Transform3D(rotm,position16);
  G4Transform3D tr17 = G4Transform3D(rotm,position17);
  G4Transform3D tr18 = G4Transform3D(rotm,position18);
  G4Transform3D tr19 = G4Transform3D(rotm,position19);
  G4Transform3D tr20 = G4Transform3D(rotm,position20);
  G4Transform3D tr21 = G4Transform3D(rotm,position21);
  G4Transform3D tr22 = G4Transform3D(rotm,position22);
  G4Transform3D tr23 = G4Transform3D(rotm,position23);
  G4Transform3D tr24 = G4Transform3D(rotm,position24);
  G4Transform3D tr25 = G4Transform3D(rotm,position25);
  G4Transform3D tr26 = G4Transform3D(rotm,position26);
  G4Transform3D tr27 = G4Transform3D(rotm,position27);
  G4Transform3D tr28 = G4Transform3D(rotm,position28);
  G4Transform3D tr29 = G4Transform3D(rotm,position29);
  G4Transform3D tr30 = G4Transform3D(rotm,position30);
  G4Transform3D tr31 = G4Transform3D(rotm,position31);
  G4Transform3D tr32 = G4Transform3D(rotm,position32);
  G4Transform3D tr33 = G4Transform3D(rotm,position33);
  G4Transform3D tr34 = G4Transform3D(rotm,position34);
  G4Transform3D tr35 = G4Transform3D(rotm,position35);
  G4Transform3D tr36 = G4Transform3D(rotm,position36);
  G4Transform3D tr37 = G4Transform3D(rotm,position37);
  G4Transform3D tr38 = G4Transform3D(rotm,position38);
  G4Transform3D tr39 = G4Transform3D(rotm,position39);
  G4Transform3D tr40 = G4Transform3D(rotm,position40);
  G4Transform3D tr41 = G4Transform3D(rotm,position41);
  // Initialise a MultiUnion structure
  //
  G4MultiUnion* munion_solid = new G4MultiUnion("Boxes_Union");
  // Add the shapes to the structure
  //
  munion_solid->AddNode(*box1,tr1);
  munion_solid->AddNode(*box2,tr2);
  munion_solid->AddNode(*box3,tr3);
  munion_solid->AddNode(*box4,tr4);
  munion_solid->AddNode(*box5,tr5);
  munion_solid->AddNode(*box6,tr6);
  munion_solid->AddNode(*box7,tr7);
  munion_solid->AddNode(*box8,tr8);
  munion_solid->AddNode(*box9,tr9);
  munion_solid->AddNode(*box10,tr10);
  munion_solid->AddNode(*box11,tr11);
  munion_solid->AddNode(*box12,tr12);
  munion_solid->AddNode(*box13,tr13);
  munion_solid->AddNode(*box14,tr14);
  munion_solid->AddNode(*box15,tr15);
  munion_solid->AddNode(*box16,tr16);
  munion_solid->AddNode(*box17,tr17);
  munion_solid->AddNode(*box18,tr18);
  munion_solid->AddNode(*box19,tr19);
  munion_solid->AddNode(*box20,tr20);
  munion_solid->AddNode(*box21,tr21);
  munion_solid->AddNode(*box22,tr22);
  munion_solid->AddNode(*box23,tr23);
  munion_solid->AddNode(*box24,tr24);
  munion_solid->AddNode(*box25,tr25);
  munion_solid->AddNode(*box26,tr26);
  munion_solid->AddNode(*box27,tr27);
  munion_solid->AddNode(*box28,tr28);
  munion_solid->AddNode(*box29,tr29);
  munion_solid->AddNode(*box30,tr30);
  munion_solid->AddNode(*box31,tr31);
  munion_solid->AddNode(*box32,tr32);
  munion_solid->AddNode(*box33,tr33);
  munion_solid->AddNode(*box34,tr34);
  munion_solid->AddNode(*box35,tr35);
  munion_solid->AddNode(*box36,tr36);
  munion_solid->AddNode(*box37,tr37);
  munion_solid->AddNode(*box38,tr38);
  munion_solid->AddNode(*box39,tr39);
  munion_solid->AddNode(*box40,tr40);
  munion_solid->AddNode(*box41,tr41);
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

  //
  //shape0
  //
  G4Material* shape0_mat = nist->FindOrBuildMaterial("G4_Pb");
  G4ThreeVector pos0 = G4ThreeVector(0, 0, -10.5*cm);
  G4Box* box0 = new G4Box("Box0", 10.*cm, 10.*cm, 4.*um);
  
  G4LogicalVolume* logicShape0 =                         
    new G4LogicalVolume(box0,         //its solid
                        shape0_mat,          //its material
                        "Shape0");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    pos0,                    //at position
                    logicShape0,             //its logical volume
                    "Shape0",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // Set munion_solid as scoring volume
  //
  fScoringVolume = logicShape0 ;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
