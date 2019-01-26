#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4VisAttributes.hh"


// Cylindrical Ioffe trap dimensionss


G4double electrodes_total_length = 384.86*mm;
G4double electrodes_zpos = electrodes_total_length/2-175.3*mm;
G4double electrodes_inner_r = 34.1*mm;
G4double electrodes_outer_r = 35.0*mm;

G4double AuPlate_total_length = 384.86*mm;
G4double AuPlate_zpos = electrodes_total_length/2-175.3*mm;
G4double AuPlate_inner_r = 33.9*mm;
G4double AuPlate_outer_r = 34.1*mm;


G4double G10_sleeve_total_length = 393.71*mm;
G4double G10_sleeve_zpos =  12.705*mm;
G4double G10_sleeve_inner_r = 35.0*mm;
G4double G10_sleeve_outer_r = 37.5*mm;


G4double Ti_sleeve_total_length = 368.3*mm;
G4double Ti_sleeve_inner_r = 37.5*mm;
G4double Ti_sleeve_outer_r = 39.0*mm;

G4double G10_holder_total_length = 317.5*mm;
G4double G10_holder_inner_r = 39.0*mm;
G4double G10_holder_outer_r = 106.7*mm;

G4double G10_sideSleeve_total_length = 25.4*mm;
G4double G10_sideSleeve_inner_r = 39.0*mm;
G4double G10_sideSleeve_outer_r = 41.68*mm;
G4double G10_sideSleeve1_zpos = 171.45*mm;

G4double Coil1_total_length = 109.05*mm;
G4double Coil1_inner_r = 42.6*mm;
G4double Coil1_outer_r = 56.2*mm;
G4double Coil1_zpos = 84.575*mm;

G4double Coil2_total_length = 112.17*mm;
G4double Coil2_inner_r = 62.6*mm;
G4double Coil2_outer_r = 77*mm;
G4double Coil2_zpos = 86.915*mm;

G4double Coil3_total_length = 22*mm;
G4double Coil3_inner_r = 83.8*mm;
G4double Coil3_outer_r = 99.5*mm;
G4double Coil3_zpos = 43.0*mm;

G4double Coil4_total_length = 59.7*mm;
G4double Coil4_inner_r = 83.8*mm;
G4double Coil4_outer_r = 99.5*mm;
G4double Coil4_zpos = 120.05*mm;

G4double LHe1_total_length = 317.5*mm;
G4double LHe1_inner_r = 106.7*mm;
G4double LHe1_outer_r = 109.0*mm;

G4double LHe2_total_length = 13*mm;
G4double LHe2_inner_r = 41.68*mm;
G4double LHe2_outer_r = 109.0*mm;
G4double Lhe2_zpos = 165.25*mm;

G4double TiEnclosure1_total_length = 368.3*mm;
G4double TiEnclosure1_inner_r = 109.0*mm;
G4double TiEnclosure1_outer_r = 119.4*mm;

G4double TiEnclosure2_total_length = 12.4*mm;
G4double TiEnclosure2_inner_r = 41.68*mm;
G4double TiEnclosure2_outer_r = 109.0*mm;
G4double TiEnclosure2_zpos = 177.95*mm;

G4double cone_total_length = 53.11*mm;
G4double cone_inner_r1 = 34.1*mm;
G4double cone_outer_r1 = 35.0*mm;
G4double cone_inner_r2 = 18.0*mm;
G4double cone_outer_r2 = 35.0*mm;
G4double cone_zpos = cone_total_length/2 +175.3*mm;

G4double Goldcone_total_length = 53.11*mm;
G4double Goldcone_inner_r1 = 33.9*mm;
G4double Goldcone_outer_r1 = 34.1*mm;
G4double Goldcone_inner_r2 = 17.8*mm;
G4double Goldcone_outer_r2 = 18.0*mm;
G4double Goldcone_zpos = cone_total_length/2 +175.3*mm;

G4double ConeG10_sleeve_total_length = 53.11*mm - 8.85*mm;
G4double ConeG10_sleeve_zpos = cone_total_length/2 +175.3*mm+8.85/2*mm;
G4double ConeG10_sleeve_inner_r = 35.0*mm;
G4double ConeG10_sleeve_outer_r = 37.5*mm;

G4double lowerelectrodes_total_length = 318.8*mm;
G4double lowerelectrodes_zpos = lowerelectrodes_total_length/2 +175.3*mm + 53.11*mm;
G4double lowerelectrodes_inner_r = 18.0*mm;
G4double lowerelectrodes_outer_r = 20.63*mm;

G4double Goldlowerelectrodes_total_length = 318.8*mm;
G4double Goldlowerelectrodes_zpos = lowerelectrodes_total_length/2 +175.3*mm + 53.11*mm;
G4double Goldlowerelectrodes_inner_r = 17.8*mm;
G4double Goldlowerelectrodes_outer_r = 18.0*mm;

G4double bellows_total_length = 152.18*mm;
G4double bellows_zpos = 209.56*mm + bellows_total_length/2 - 12.7*mm;
G4double bellows_inner_r = 50.0*mm;
G4double bellows_outer_r = 51.5*mm;

G4double windowFlange_total_length = 90.8*mm;
G4double windowFlange_zpos = 340.04*mm + windowFlange_total_length/2;
G4double windowFlange_inner_r = 51.5*mm;
G4double windowFlange_outer_r = 75.82*mm;


G4double xystage_total_length = 11.3*mm;
G4double xystage_zpos = 340.04*mm + windowFlange_total_length/2;
G4double xystage_inner_r = 0.0*mm;
G4double xystage_outer_r = 51.5*mm;

G4double degrader_total_length = 0.130*mm;
G4double degrader_zpos = 547.21*mm + degrader_total_length/2;
G4double degrader_inner_r = 0.0*mm;
G4double degrader_outer_r = 23.5*mm;

G4double air1_total_length = 790.55*mm;
G4double air1_zpos = 168.29*mm - air1_total_length/2;
G4double air1_inner_r = 381.0/2*mm;
G4double air1_outer_r = 508.0/2*mm;

G4double air2_total_length = 1113.9*mm;
G4double air2_zpos = 168.29*mm + air2_total_length/2;
G4double air2_inner_r = 247.65*mm;
G4double air2_outer_r = 508.0/2*mm;

G4double air3_total_length = 2146.4*mm;
G4double air3_inner_r = 1216.54/2*mm;
G4double air3_outer_r = 1200.0*mm;
G4double air3_zpos = 1192.9*mm - air3_total_length/2;

G4double air4_total_length = 348.49*mm;
G4double air4_zpos = 622.26*mm + air4_total_length/2;
G4double air4_inner_r = 60.0*mm;
G4double air4_outer_r = 508.0/2*mm;











// Insert dewar dimensions

G4double Lower1_total_length = 785.68*mm;
G4double Lower1_inner_r = 169.86*mm;
G4double Lower1_outer_r = 173.04*mm;
G4double Lower1_zpos = 602.26*mm - Lower1_total_length/2;

G4double Lower2_total_length = 785.68*mm;
G4double Lower2_inner_r = 180.91*mm;
G4double Lower2_outer_r = 182.5*mm;
G4double Lower2_zpos = 602.26*mm - Lower2_total_length/2;

G4double Lower3_total_length = 785.68*mm;
G4double Lower3_inner_r = 185.82*mm;
G4double Lower3_outer_r = 186.63*mm;
G4double Lower3_zpos = 602.26*mm - Lower3_total_length/2;

G4double Lower4_total_length = 785.68*mm;
G4double Lower4_inner_r = 188.22*mm;
G4double Lower4_outer_r = 190.5*mm;
G4double Lower4_zpos = 602.26*mm - Lower4_total_length/2;


G4double Bottombase_total_length = 20*mm;
G4double Bottombase_inner_r = 51.62*mm;
G4double Bottombase_outer_r = 190.5*mm;
G4double Bottombase_zpos = 622.26*mm - Bottombase_total_length/2;


G4double Upperbase_total_length = 15.13*mm;
G4double Upperbase_inner_r = 190.5*mm;
G4double Upperbase_outer_r = 247.65*mm;
G4double Upperbase_zpos = 183.42*mm - Upperbase_total_length/2;


G4double Upperbase2_total_length = 4.87*mm;
G4double Upperbase2_inner_r = 190.5*mm;
G4double Upperbase2_outer_r = 233.82*mm;
G4double Upperbase2_zpos = 188.29*mm - Upperbase2_total_length/2;

G4double Upper1_total_length = 1098.77*mm;
G4double Upper1_inner_r = 233.82*mm;
G4double Upper1_outer_r = 238.65*mm;
G4double Upper1_zpos = 183.42*mm + Upper1_total_length/2;

G4double Upper2_total_length = 1098.77*mm;
G4double Upper2_inner_r = 240.17*mm;
G4double Upper2_outer_r = 241.76*mm;
G4double Upper2_zpos = 183.42*mm + Upper2_total_length/2;

G4double Upper3_total_length = 1098.77*mm;
G4double Upper3_inner_r = 243.35*mm;
G4double Upper3_outer_r = 244.16*mm;
G4double Upper3_zpos = 183.42*mm + Upper3_total_length/2;

G4double Upper4_total_length = 1098.77*mm;
G4double Upper4_inner_r = 245.75*mm;
G4double Upper4_outer_r = 247.65*mm;
G4double Upper4_zpos = 183.42*mm + Upper4_total_length/2;


// Magnet Body dimensions

G4double solenoid_total_length = 1524*mm;
G4double solenoid_inner_r = 583.0/2*mm;
G4double solenoid_outer_r = 621.90/2*mm;
G4double solenoid_zpos = 716.88*mm - solenoid_total_length/2;


G4double innerTube_total_length = 2146.4*mm;
G4double innerTube_inner_r = 508.0/2*mm;
G4double innerTube_outer_r = 510.67/2*mm;
G4double innerTube_zpos = 1192.9*mm - innerTube_total_length/2;


G4double outerTube_total_length = 2146.4*mm;
G4double outerTube_inner_r = 1213.87/2*mm;
G4double outerTube_outer_r = 1216.54/2*mm;
G4double outerTube_zpos = 1192.9*mm - outerTube_total_length/2;


G4double lowerBase_total_length = 19.0*mm;
G4double lowerBase_inner_r = 508.0/2*mm;
G4double lowerBase_outer_r = 1371.60/2*mm;
G4double lowerBase_zpos = 953.5*mm + lowerBase_total_length/2;

G4double upperBase_total_length = 19.0*mm;
G4double upperBase_inner_r = 508.0/2*mm;
G4double upperBase_outer_r = 1371.60/2*mm;
G4double upperBase_zpos = 1192.9*mm + upperBase_total_length/2;





//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1DetectorConstruction::SetupMaterials()
{

  G4NistManager* nist = G4NistManager::Instance();

  copper = nist->FindOrBuildMaterial("G4_Cu");
  G4Color coppercolour(255/255.,151/255.,65/255.,1.0);
  coppervisattr = new G4VisAttributes(coppercolour);

  stainless = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
  G4Color stainlesscolour(128/255.,128/255.,128/255.,1.0);
  stainlessvisattr = new G4VisAttributes(stainlesscolour);

  Be = nist->FindOrBuildMaterial("G4_Be");
  G4Color Becolour(128/255.,128/255.,128/255.,1.0);
  Bevisattr = new G4VisAttributes(Becolour);
  
  invisibleattr = new G4VisAttributes(false, coppercolour);

  vacuum = nist->FindOrBuildMaterial("G4_Galactic");

  gold = nist->FindOrBuildMaterial("G4_Au");
  G4Color goldcolour(255/255.,255/255.,0/255.,1.0);
  goldvisattr = new G4VisAttributes(goldcolour);

  air = nist->FindOrBuildMaterial("G4_AIR");
  G4Color aircolour(255/255.,165.0/255.,0/255.,1.0);
  airvisattr = new G4VisAttributes(aircolour);


  Ti = nist->FindOrBuildMaterial("G4_Ti");
  G4Color Ticolour(128/255.,128/255.,128/255.,1.0);
  Tivisattr = new G4VisAttributes(Ticolour);

  Al = nist->FindOrBuildMaterial("G4_Al");
  G4Color Alcolour(128/255.,128/255.,128/255.,1.0);
  Alvisattr = new G4VisAttributes(Alcolour);

  C = new G4Element("Carbon", "C", 6, 12.01 * g/mole);
  H = new G4Element("Hydrogen", "H", 1, 1.01 * g /mole);
  O  = new G4Element("Oxygen" ,"O" , 8., 16.00*g/mole);
 
    
  G4Color FR4colour(0/255.,225/255.,0/255.,1.0);
 
  FR4_vis_ = new G4VisAttributes(FR4colour);
    
  Si = new G4Element("Silicon", "Si" ,  14., 28.09*g/mole);

  LHe = new G4Material("LiquidHe", 2, 4.003 * g/mole, 0.145 * g/cm3);
  G4Color LHecolour(0/255.,0/255.,255/255.,1.0);
  LHecolourvisattr = new G4VisAttributes(LHecolour);
    
  SiO2 = new G4Material("quartz", 2.200*g/cm3, 2);
  SiO2->AddElement(Si, 1);
  SiO2->AddElement(O , 2);
    
    
  Epoxy = new G4Material("Epoxy" , 1.2*g/cm3, 2);
  Epoxy->AddElement(H, 2);
  Epoxy->AddElement(C, 2);
    
    
  FR4_ = new G4Material("FR4", 1.86 * g / cm3, 2);
  FR4_->AddMaterial(SiO2, 0.528);
  FR4_->AddMaterial(Epoxy, 0.472);


}




B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
  {}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{ 

  SetupMaterials();



// Define world
G4double r_world_mm = 2000 * mm; 
G4double z_world_mm = 3000 * mm;
auto solidWorld = new G4Tubs("world",0,r_world_mm, z_world_mm/2., 0, 2*pi);
auto logicWorld = new G4LogicalVolume(solidWorld, vacuum, "world");
auto physWorld = new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), logicWorld, "world", nullptr, false, 0, true);
logicWorld->SetVisAttributes(invisibleattr);


// ################################
//           Ioffe Trap
// ################################



// upper electrode stack
auto solidElectrodes = new G4Tubs("electrodes", electrodes_inner_r, electrodes_outer_r, electrodes_total_length/2, 0, 2*pi);
auto logicElectrodes = new G4LogicalVolume(solidElectrodes, copper, "electrodes");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,electrodes_zpos), logicElectrodes, "electrodes", logicWorld, false, 0, true);
logicElectrodes->SetVisAttributes(coppervisattr);

// Cone electrode
auto solidCone = new G4Cons("cone",cone_inner_r2,cone_outer_r2,cone_inner_r1,cone_outer_r1,
  cone_total_length/2,0,2*pi);
auto logicCone = new G4LogicalVolume(solidCone, copper, "cone");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-cone_zpos), logicCone, "cone", logicWorld, false, 0, true);
logicCone->SetVisAttributes(coppervisattr);

// Gold plating cone electrode
auto solidGoldCone = new G4Cons("Goldcone",Goldcone_inner_r2,Goldcone_outer_r2,Goldcone_inner_r1,Goldcone_outer_r1,
  Goldcone_total_length/2,0,2*pi);
auto logicGoldCone = new G4LogicalVolume(solidGoldCone, gold, "Goldcone");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Goldcone_zpos), logicGoldCone, "Goldcone", logicWorld, false, 0, true);
logicGoldCone->SetVisAttributes(goldvisattr);


//Cone G-10 sleeve
auto solidConeG10_sleeve = new G4Tubs("ConeG10_sleeve", ConeG10_sleeve_inner_r, ConeG10_sleeve_outer_r, ConeG10_sleeve_total_length/2, 0, 2*pi);
auto logicConeG10_sleeve = new G4LogicalVolume(solidConeG10_sleeve, FR4_, "ConeG10_sleeve");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-ConeG10_sleeve_zpos), logicConeG10_sleeve, "ConeG10_sleeve", logicWorld, false, 0, true);
logicConeG10_sleeve->SetVisAttributes(FR4_vis_);

//Lower electrode stack
auto solidlowerelectrodes = new G4Tubs("lowerelectrodes", lowerelectrodes_inner_r, lowerelectrodes_outer_r, lowerelectrodes_total_length/2, 0, 2*pi);
auto logiclowerelectrodes = new G4LogicalVolume(solidlowerelectrodes, copper, "lowerelectrodes");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-lowerelectrodes_zpos), logiclowerelectrodes, "lowerelectrodes", logicWorld, false, 0, true);
logiclowerelectrodes->SetVisAttributes(coppervisattr);


// Gold plating lower electrode stack
auto solidGoldlowerelectrodes = new G4Tubs("Goldlowerelectrodes", Goldlowerelectrodes_inner_r, Goldlowerelectrodes_outer_r, Goldlowerelectrodes_total_length/2, 0, 2*pi);
auto logicGoldlowerelectrodes = new G4LogicalVolume(solidGoldlowerelectrodes,gold, "Goldlowerelectrodes");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Goldlowerelectrodes_zpos), logicGoldlowerelectrodes, "Goldlowerelectrodes", logicWorld, false, 0, true);
logicGoldlowerelectrodes->SetVisAttributes(goldvisattr);


// Bellows
auto solidBellows = new G4Tubs("Bellows", bellows_inner_r, bellows_outer_r, bellows_total_length/2, 0, 2*pi);
auto logicBellows = new G4LogicalVolume(solidBellows,stainless, "Bellows");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,bellows_zpos), logicBellows, "Bellows", logicWorld, false, 0, true);
logicBellows->SetVisAttributes(stainlessvisattr);

// Window flange
auto solidWindowFlange = new G4Tubs("WindowFlange", windowFlange_inner_r, windowFlange_outer_r, windowFlange_total_length/2, 0, 2*pi);
auto logicWindowFlange = new G4LogicalVolume(solidWindowFlange,Ti, "WindowFlange");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,windowFlange_zpos), logicWindowFlange, "WindowFlange", logicWorld, false, 0, true);
logicWindowFlange->SetVisAttributes(Tivisattr);

// XY Stage
auto solidxystage = new G4Tubs("xystage", xystage_inner_r, xystage_outer_r, xystage_total_length/2, 0, 2*pi);
auto logicxystage = new G4LogicalVolume(solidxystage,copper, "xystage");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,xystage_zpos), logicxystage, "xystage", logicWorld, false, 0, true);
logicxystage->SetVisAttributes(coppervisattr);

// Be Degrader
auto soliddegrader = new G4Tubs("degrader", degrader_inner_r, degrader_outer_r, degrader_total_length/2, 0, 2*pi);
auto logicdegrader = new G4LogicalVolume(soliddegrader,Be, "degrader");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-degrader_zpos), logicdegrader, "degrader", logicWorld, false, 0, true);
logicdegrader->SetVisAttributes(Bevisattr);



// Gold plating 200 um
auto solidAuPlate = new G4Tubs("AuPlate", AuPlate_inner_r, AuPlate_outer_r, AuPlate_total_length/2, 0, 2*pi);
auto logicAuPlate = new G4LogicalVolume(solidAuPlate, gold, "AuPlate");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,AuPlate_zpos), logicAuPlate, "AuPlate", logicWorld, false, 0, true);
logicAuPlate->SetVisAttributes(goldvisattr);


// G-10 sleeve
auto solidG10_sleeve = new G4Tubs("G10_sleeve", G10_sleeve_inner_r, G10_sleeve_outer_r, G10_sleeve_total_length/2, 0, 2*pi);
auto logicG10_sleeve = new G4LogicalVolume(solidG10_sleeve, FR4_, "G10_sleeve");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,G10_sleeve_zpos), logicG10_sleeve, "G10_sleeve", logicWorld, false, 0, true);
logicG10_sleeve->SetVisAttributes(FR4_vis_);



// Ti-sleeve
auto solidTi_sleeve = new G4Tubs("Ti_sleeve", Ti_sleeve_inner_r, Ti_sleeve_outer_r, Ti_sleeve_total_length/2, 0, 2*pi);
auto logicTi_sleeve = new G4LogicalVolume(solidTi_sleeve, Ti, "Ti_sleeve");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), logicTi_sleeve, "Ti_sleeve", logicWorld, false, 0, true);
logicTi_sleeve->SetVisAttributes(Tivisattr);


// G-10 holder
auto solidG10_holder = new G4Tubs("G10_holder", G10_holder_inner_r, G10_holder_outer_r, G10_holder_total_length/2, 0, 2*pi);
auto logicG10_holder = new G4LogicalVolume(solidG10_holder, FR4_, "G10_holder");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), logicG10_holder, "G10_holder", logicWorld, false, 0, true);
logicG10_holder->SetVisAttributes(FR4_vis_);


//G-10 side sleeves
auto solidG10_sideSleeve1 = new G4Tubs("G10_sideSleeve1", G10_sideSleeve_inner_r, G10_sideSleeve_outer_r, G10_sideSleeve_total_length/2, 0, 2*pi);
auto logicG10_sideSleeve1 = new G4LogicalVolume(solidG10_sideSleeve1, FR4_, "G10_sideSleeve1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-G10_sideSleeve1_zpos), logicG10_sideSleeve1, "G10_sideSleeve1", logicWorld, false, 0, true);
logicG10_sideSleeve1->SetVisAttributes(FR4_vis_);

auto solidG10_sideSleeve2 = new G4Tubs("G10_sideSleeve2", G10_sideSleeve_inner_r, G10_sideSleeve_outer_r, G10_sideSleeve_total_length/2, 0, 2*pi);
auto logicG10_sideSleeve2 = new G4LogicalVolume(solidG10_sideSleeve2, FR4_, "G10_sideSleeve2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,G10_sideSleeve1_zpos), logicG10_sideSleeve2, "G10_sideSleeve2", logicWorld, false, 0, true);
logicG10_sideSleeve2->SetVisAttributes(FR4_vis_);


// Coil 1 and 2
auto solidCoil1 = new G4Tubs("Coil1", Coil1_inner_r, Coil1_outer_r, Coil1_total_length/2, 0, 2*pi);
auto logicCoil1 = new G4LogicalVolume(solidCoil1, copper, "Coil1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Coil1_zpos), logicCoil1, "Coil1", logicG10_holder, false, 0, true);
logicCoil1->SetVisAttributes(coppervisattr);
auto solidCoil2 = new G4Tubs("Coil2", Coil1_inner_r, Coil1_outer_r, Coil1_total_length/2, 0, 2*pi);
auto logicCoil2 = new G4LogicalVolume(solidCoil2, copper, "Coil2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Coil1_zpos), logicCoil2, "Coil2", logicG10_holder, false, 0, true);
logicCoil2->SetVisAttributes(coppervisattr);

//Coil 3 and 4
auto solidCoil3 = new G4Tubs("Coil3", Coil2_inner_r, Coil2_outer_r, Coil2_total_length/2, 0, 2*pi);
auto logicCoil3 = new G4LogicalVolume(solidCoil3, copper, "Coil3");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Coil2_zpos), logicCoil3, "Coil3", logicG10_holder, false, 0, true);
logicCoil3->SetVisAttributes(coppervisattr);
auto solidCoil4 = new G4Tubs("Coil4", Coil2_inner_r, Coil2_outer_r, Coil2_total_length/2, 0, 2*pi);
auto logicCoil4 = new G4LogicalVolume(solidCoil4, copper, "Coil4");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Coil2_zpos), logicCoil4, "Coil4", logicG10_holder, false, 0, true);
logicCoil4->SetVisAttributes(coppervisattr);

//Coil 5 and 6
auto solidCoil5 = new G4Tubs("Coil5", Coil3_inner_r, Coil3_outer_r, Coil3_total_length/2, 0, 2*pi);
auto logicCoil5 = new G4LogicalVolume(solidCoil5, copper, "Coil5");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Coil3_zpos), logicCoil5, "Coil5", logicG10_holder, false, 0, true);
logicCoil5->SetVisAttributes(coppervisattr);
auto solidCoil6 = new G4Tubs("Coil6", Coil3_inner_r, Coil3_outer_r, Coil3_total_length/2, 0, 2*pi);
auto logicCoil6 = new G4LogicalVolume(solidCoil6, copper, "Coil6");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Coil3_zpos), logicCoil6, "Coil6", logicG10_holder, false, 0, true);
logicCoil6->SetVisAttributes(coppervisattr);


//Coil 7 and 8
auto solidCoil7 = new G4Tubs("Coil7", Coil4_inner_r, Coil4_outer_r, Coil4_total_length/2, 0, 2*pi);
auto logicCoil7 = new G4LogicalVolume(solidCoil7, copper, "Coil7");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Coil4_zpos), logicCoil7, "Coil7", logicG10_holder, false, 0, true);
logicCoil7->SetVisAttributes(coppervisattr);
auto solidCoil8 = new G4Tubs("Coil8", Coil4_inner_r, Coil4_outer_r, Coil4_total_length/2, 0, 2*pi);
auto logicCoil8 = new G4LogicalVolume(solidCoil8, copper, "Coil8");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Coil4_zpos), logicCoil8, "Coil8", logicG10_holder, false, 0, true);
logicCoil8->SetVisAttributes(coppervisattr);


//Liquid Helium 1
auto solidLHe1 = new G4Tubs("LHe1", LHe1_inner_r, LHe1_outer_r, LHe1_total_length/2, 0, 2*pi);
auto logicLHe1 = new G4LogicalVolume(solidLHe1, LHe, "LHe1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), logicLHe1, "LHe1", logicWorld, false, 0, true);
logicLHe1->SetVisAttributes(LHecolourvisattr);


// Liquid Helium 2 and 3
auto solidLHe2 = new G4Tubs("LHe2", LHe2_inner_r, LHe2_outer_r, LHe2_total_length/2, 0, 2*pi);
auto logicLHe2 = new G4LogicalVolume(solidLHe2, LHe, "LHe2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Lhe2_zpos), logicLHe2, "LHe2", logicWorld, false, 0, true);
logicLHe2->SetVisAttributes(LHecolourvisattr);
auto solidLHe3 = new G4Tubs("LHe3", LHe2_inner_r, LHe2_outer_r, LHe2_total_length/2, 0, 2*pi);
auto logicLHe3 = new G4LogicalVolume(solidLHe3, LHe, "LHe3");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Lhe2_zpos), logicLHe3, "LHe3", logicWorld, false, 0, true);
logicLHe3->SetVisAttributes(LHecolourvisattr);



//Titanium enclosure 1
auto solidTiEnclosure1 = new G4Tubs("TiEnclosure1", TiEnclosure1_inner_r, TiEnclosure1_outer_r, TiEnclosure1_total_length/2, 0, 2*pi);
auto logicTiEnclosure1 = new G4LogicalVolume(solidTiEnclosure1, Ti, "TiEnclosure1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), logicTiEnclosure1, "TiEnclosure1", logicWorld, false, 0, true);
logicTiEnclosure1->SetVisAttributes(Tivisattr);


//Titanium enclosure 2 and 3
auto solidTiEnclosure2 = new G4Tubs("TiEnclosure2", TiEnclosure2_inner_r, TiEnclosure2_outer_r, TiEnclosure2_total_length/2, 0, 2*pi);
auto logicTiEnclosure2 = new G4LogicalVolume(solidTiEnclosure2, Ti, "TiEnclosure2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,TiEnclosure2_zpos), logicTiEnclosure2, "TiEnclosure2", logicWorld, false, 0, true);
logicTiEnclosure2->SetVisAttributes(Tivisattr);
auto solidTiEnclosure3 = new G4Tubs("TiEnclosure3", TiEnclosure2_inner_r, TiEnclosure2_outer_r, TiEnclosure2_total_length/2, 0, 2*pi);
auto logicTiEnclosure3 = new G4LogicalVolume(solidTiEnclosure3, Ti, "TiEnclosure3");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-TiEnclosure2_zpos), logicTiEnclosure3, "TiEnclosure3", logicWorld, false, 0, true);
logicTiEnclosure3->SetVisAttributes(Tivisattr);




// ################################
//           Insert dewar
// ################################



// Lower tube 1
auto solidLower1 = new G4Tubs("Lower1", Lower1_inner_r, Lower1_outer_r, Lower1_total_length/2, 0, 2*pi);
auto logicLower1 = new G4LogicalVolume(solidLower1, stainless, "Lower1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Lower1_zpos), logicLower1, "Lower1", logicWorld, false, 0, true);
logicLower1->SetVisAttributes(stainlessvisattr);


// Lower tube 2
auto solidLower2 = new G4Tubs("Lower2", Lower2_inner_r, Lower2_outer_r, Lower2_total_length/2, 0, 2*pi);
auto logicLower2 = new G4LogicalVolume(solidLower2, stainless, "Lower2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Lower2_zpos), logicLower2, "Lower2", logicWorld, false, 0, true);
logicLower2->SetVisAttributes(stainlessvisattr);


// Lower tube 3
auto solidLower3 = new G4Tubs("Lower3", Lower3_inner_r, Lower3_outer_r, Lower3_total_length/2, 0, 2*pi);
auto logicLower3 = new G4LogicalVolume(solidLower3, stainless, "Lower3");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Lower3_zpos), logicLower3, "Lower3", logicWorld, false, 0, true);
logicLower3->SetVisAttributes(stainlessvisattr);


// Lower tube 4
auto solidLower4 = new G4Tubs("Lower4", Lower4_inner_r, Lower4_outer_r, Lower4_total_length/2, 0, 2*pi);
auto logicLower4 = new G4LogicalVolume(solidLower4, stainless, "Lower4");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Lower4_zpos), logicLower4, "Lower4", logicWorld, false, 0, true);
logicLower4->SetVisAttributes(stainlessvisattr);




// Bottom base
auto solidBottombase = new G4Tubs("Bottombase", Bottombase_inner_r, Bottombase_outer_r, Bottombase_total_length/2, 0, 2*pi);
auto logicBottombase = new G4LogicalVolume(solidBottombase, stainless, "Bottombase");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-Bottombase_zpos), logicBottombase, "Bottombase", logicWorld, false, 0, true);
logicBottombase->SetVisAttributes(stainlessvisattr);


// Upper base
auto solidUpperbase = new G4Tubs("Upperbase", Upperbase_inner_r, Upperbase_outer_r, Upperbase_total_length/2, 0, 2*pi);
auto logicUpperbase = new G4LogicalVolume(solidUpperbase, stainless, "Upperbase");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Upperbase_zpos), logicUpperbase, "Upperbase", logicWorld, false, 0, true);
logicUpperbase->SetVisAttributes(stainlessvisattr);

// Upper base2
auto solidUpperbase2 = new G4Tubs("Upperbase2", Upperbase2_inner_r, Upperbase2_outer_r, Upperbase2_total_length/2, 0, 2*pi);
auto logicUpperbase2 = new G4LogicalVolume(solidUpperbase2, stainless, "Upperbase2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Upperbase2_zpos), logicUpperbase2, "Upperbase2", logicWorld, false, 0, true);
logicUpperbase2->SetVisAttributes(stainlessvisattr);



// Upper tube 1
auto solidUpper1 = new G4Tubs("Upper1", Upper1_inner_r, Upper1_outer_r, Upper1_total_length/2, 0, 2*pi);
auto logicUpper1 = new G4LogicalVolume(solidUpper1, stainless, "Upper1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Upper1_zpos), logicUpper1, "Upper1", logicWorld, false, 0, true);
logicUpper1->SetVisAttributes(stainlessvisattr);


// Upper tube 2
auto solidUpper2 = new G4Tubs("Upper2", Upper2_inner_r, Upper2_outer_r, Upper2_total_length/2, 0, 2*pi);
auto logicUpper2 = new G4LogicalVolume(solidUpper2, stainless, "Upper2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Upper2_zpos), logicUpper2, "Upper2", logicWorld, false, 0, true);
logicUpper2->SetVisAttributes(stainlessvisattr);


// Upper tube 3
auto solidUpper3 = new G4Tubs("Upper3", Upper3_inner_r, Upper3_outer_r, Upper3_total_length/2, 0, 2*pi);
auto logicUpper3 = new G4LogicalVolume(solidUpper3, stainless, "Upper3");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Upper3_zpos), logicUpper3, "Upper3", logicWorld, false, 0, true);
logicUpper3->SetVisAttributes(stainlessvisattr);


// Upper tube 4
auto solidUpper4 = new G4Tubs("Upper4", Upper4_inner_r, Upper4_outer_r, Upper4_total_length/2, 0, 2*pi);
auto logicUpper4 = new G4LogicalVolume(solidUpper4, stainless, "Upper4");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,Upper4_zpos), logicUpper4, "Upper4", logicWorld, false, 0, true);
logicUpper4->SetVisAttributes(stainlessvisattr);



// ################################
//           Magnet Body
// ################################



// solenoid
auto solidSolenoid = new G4Tubs("solenoid", solenoid_inner_r, solenoid_outer_r, solenoid_total_length/2, 0, 2*pi);
auto logicSolenoid = new G4LogicalVolume(solidSolenoid, copper, "solenoid");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,solenoid_zpos), logicSolenoid, "solenoid", logicWorld, false, 0, true);
logicSolenoid->SetVisAttributes(coppervisattr);


// innerTube
auto solidinnerTube = new G4Tubs("innerTube", innerTube_inner_r, innerTube_outer_r, innerTube_total_length/2, 0, 2*pi);
auto logicinnerTube = new G4LogicalVolume(solidinnerTube, stainless, "innerTube");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,innerTube_zpos), logicinnerTube, "innerTube", logicWorld, false, 0, true);
logicinnerTube->SetVisAttributes(stainlessvisattr);


// outerTube
auto solidouterTube = new G4Tubs("outerTube", outerTube_inner_r, outerTube_outer_r, outerTube_total_length/2, 0, 2*pi);
auto logicouterTube = new G4LogicalVolume(solidouterTube, stainless, "outerTube");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,outerTube_zpos), logicouterTube, "outerTube", logicWorld, false, 0, true);
logicouterTube->SetVisAttributes(stainlessvisattr);


// lowerBase
auto solidlowerBase = new G4Tubs("lowerBase", lowerBase_inner_r, lowerBase_outer_r, lowerBase_total_length/2, 0, 2*pi);
auto logiclowerBase = new G4LogicalVolume(solidlowerBase, stainless, "lowerBase");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-lowerBase_zpos), logiclowerBase, "lowerBase", logicWorld, false, 0, true);
logiclowerBase->SetVisAttributes(stainlessvisattr);


// upperBase
auto solidupperBase = new G4Tubs("upperBase", upperBase_inner_r, upperBase_outer_r, upperBase_total_length/2, 0, 2*pi);
auto logicupperBase = new G4LogicalVolume(solidupperBase, stainless, "upperBase");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,upperBase_zpos), logicupperBase, "upperBase", logicWorld, false, 0, true);
logicupperBase->SetVisAttributes(stainlessvisattr);


// ################################################
//           Air volume (where detectors go)
// ################################################


// air1 (silicon detector mother volume)
auto solidAir1 = new G4Tubs("air1", air1_inner_r, air1_outer_r, air1_total_length/2, 0, 2*pi);
auto logicAir1 = new G4LogicalVolume(solidAir1, air, "air1");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,air1_zpos), logicAir1, "air1", logicWorld, false, 0, true);
logicAir1->SetVisAttributes(invisibleattr);


// air2
auto solidAir2 = new G4Tubs("air2", air2_inner_r, air2_outer_r, air2_total_length/2, 0, 2*pi);
auto logicAir2 = new G4LogicalVolume(solidAir2, air, "air2");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,air2_zpos), logicAir2, "air2", logicWorld, false, 0, true);
logicAir2->SetVisAttributes(invisibleattr);

// air3 (scintillator mother volume)
auto solidAir3 = new G4Tubs("air3", air3_inner_r, air3_outer_r, air3_total_length/2, 0, 2*pi);
auto logicAir3 = new G4LogicalVolume(solidAir3, air, "air3");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,air3_zpos), logicAir3, "air3", logicWorld, false, 0, true);
logicAir3->SetVisAttributes(invisibleattr);

// air4
auto solidAir4 = new G4Tubs("air4", air4_inner_r, air4_outer_r, air4_total_length/2, 0, 2*pi);
auto logicAir4 = new G4LogicalVolume(solidAir4, air, "air4");
new G4PVPlacement(nullptr, G4ThreeVector(0,0,-air4_zpos), logicAir4, "air4", logicWorld, false, 0, true);
logicAir4->SetVisAttributes(invisibleattr);





fScoringVolume = logicouterTube;



  return physWorld;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
