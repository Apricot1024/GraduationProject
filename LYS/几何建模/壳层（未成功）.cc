  //
  //shape2
  //
  G4Material* shape2_mat = nist->FindOrBuildMaterial("G4_C");
  G4ThreeVector pos2 = G4ThreeVector(0, 0, 0*cm);
  G4Box* box2 = new G4Box("Box2", 20.*cm, 20.*cm, 30.*cm);
  G4Box* box3 = new G4Box("Box3", 10.*cm, 10.*cm, 20.*cm);

  G4SubtractionSolid*subtraction=
       new G4SubtractionSolid("Box2-Box3",box2,box3);
  
  G4LogicalVolume* logicShape2 =                         
    new G4LogicalVolume(subtraction,         //its solid
                        shape2_mat,          //its material
                        "Shape2");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    logicShape2,             //its logical volume
                    "Shape2",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
