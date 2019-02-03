#ifndef B1DetectorConstruction_h
#define B1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Element;
class G4VisAttributes;
class G4Element;
class G4Material;
class G4NistManager;




class B1DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    B1DetectorConstruction();

    virtual ~B1DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

    void SetupMaterials();

  protected:
    G4LogicalVolume* fScoringVolume;

    
    G4Element* C;
    G4Element* H;
    G4Element* O;
    G4Element* Si;

    G4VisAttributes* FR4_vis_;
    G4VisAttributes* coppervisattr;
    G4VisAttributes* airvisattr;
    G4VisAttributes* invisibleattr;
    G4VisAttributes* stainlessvisattr;
    G4VisAttributes* goldvisattr;
    G4VisAttributes* Tivisattr;
    G4VisAttributes* Bevisattr;
    G4VisAttributes* LHecolourvisattr;
    G4VisAttributes* Alvisattr;


    G4Material* LHe;
    G4Material* air;
    G4Material* copper;
    G4Material* stainless;
    G4Material* vacuum;
    G4Material* Ti;
    G4Material* Be;
    G4Material* Al;
    G4Material* gold;
	G4Material* SiO2;
    G4Material* Epoxy;
    G4Material* FR4_;

    //std::map<G4String, G4Material*> mateirlaMap;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

