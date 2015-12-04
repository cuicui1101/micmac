/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/
#include "StdAfx.h"
#include "kugelhupf.h"


#if ELISE_windows
    #define uint unsigned
#endif



/**
 * TestPointHomo: read point homologue entre 2 image après Tapioca
 * Inputs:
 *  - Nom de 2 images
 *  - Fichier de calibration du caméra
 * Output:
 *  - List de coordonné de point homologue
 *  - serie1_Line$ mm3d PHO_MI "soussol_161015_001_0000[6-8].tif" Ori-Serie1/
 * */

struct PtTrip
{
    Pt2dr P1;
    Pt2dr P2;
    Pt2dr P3;
};

struct PtDoub
{
    Pt2dr P1;
    Pt2dr P2;
};

void StdCorrecNameHomol_G(std::string & aNameH,const std::string & aDir)
{

    int aL = strlen(aNameH.c_str());
    if (aL && (aNameH[aL-1]==ELISE_CAR_DIR))
    {
        aNameH = aNameH.substr(0,aL-1);
    }

    if ((strlen(aNameH.c_str())>=5) && (aNameH.substr(0,5)==std::string("Homol")))
       aNameH = aNameH.substr(5,std::string::npos);

    std::string aTest =  ( isUsingSeparateDirectories()?MMOutputDirectory():aDir ) + "Homol"+aNameH+ ELISE_CAR_DIR;
}

int PHO_MI_main(int argc,char ** argv)
{
    cout<<"*********************"<<endl;
    cout<<"* P : Points        *"<<endl;
    cout<<"* H : Homologues    *"<<endl;
    cout<<"* O : Observés sur  *"<<endl;
    cout<<"* M : Modèle        *"<<endl;
    cout<<"* I : Initial       *"<<endl;
    cout<<"*********************"<<endl;

    std::string aFullPatternImages = ".*.tif", aOriInput, aNameHomol="Homol/", aHomolOutput="Homol_Filtered/", bStrategie = "1";
    bool ExpTxt = false;
    ElInitArgMain			//initialize Elise, set which is mandantory arg and which is optional arg
    (
    argc,                   //nb d’arguments
    argv,                   //chaines de caracteres contenants tous les arguments
    //mandatory arguments - arg obligatoires
    LArgMain()  << EAMC(aFullPatternImages, "Pattern of images to compute",  eSAM_IsPatFile)
                << EAMC(aOriInput, "Input Initial Orientation",  eSAM_IsExistDirOri),
    //optional arguments - arg facultatifs
    LArgMain()  << EAM(aNameHomol, "HomolIn", true, "Name of input Homol foler, Homol par default")
                << EAM(ExpTxt,"ExpTxt",true,"Ascii format for in and out, def=false")
                << EAM(aHomolOutput, "HomolOut" , true, "Output corrected Homologues folder")
                << EAM(bStrategie, "Strategie" , true, "Strategie de filtre les points homols")
    );
    if (MMVisualMode) return EXIT_SUCCESS;

    ELISE_fp::AssertIsDirectory(aNameHomol);

    // Initialize name manipulator & files
    std::string aDirImages, aPatImages;
    SplitDirAndFile(aDirImages,aPatImages,aFullPatternImages);
    StdCorrecNameOrient(aOriInput,aDirImages);//remove "Ori-" if needed

    cInterfChantierNameManipulateur * aICNM=cInterfChantierNameManipulateur::BasicAlloc(aDirImages);
    const std::vector<std::string> aSetImages = *(aICNM->Get(aPatImages));

    ELISE_ASSERT(aSetImages.size()>1,"Number of image must be > 1");
 //============================================================
    std::string anExt = ExpTxt ? "txt" : "dat";

    std::string aKHIn =   std::string("NKS-Assoc-CplIm2Hom@")
                       +  std::string(aNameHomol)
                       +  std::string("@")
                       +  std::string(anExt);
    std::string aKHOut =   std::string("NKS-Assoc-CplIm2Hom@")
                        +  std::string(aHomolOutput)
                        +  std::string("@")
                        +  std::string("txt");
    std::string aKHOutDat =   std::string("NKS-Assoc-CplIm2Hom@")
                        +  std::string(aHomolOutput)
                        +  std::string("@")
                        +  std::string("dat");

    vector< Pt2dr > NewHomoFile;
    vector< Pt2dr > HomoImg1;
    vector< Pt2dr > HomoImg2;
            
             //read image 1 & 2 & 3
             std::string aNameIm1 = aSetImages[0];
             std::string aNameIm2 = aSetImages[1];
             std::string aNameIm3 = aSetImages[2];
             Tiff_Im mTiffImg1(aNameIm1.c_str());                     
             Im2D<U_INT1,INT4> mImg1(mTiffImg1.sz().x,mTiffImg1.sz().y);     
             ELISE_COPY(                                                   
                         mTiffImg1.all_pts(),
                         mTiffImg1.in(),
                         mImg1.out()
                       );
             Tiff_Im mTiffImg2(aNameIm2.c_str());
             Im2D<U_INT1,INT4> mImg2(mTiffImg2.sz().x,mTiffImg2.sz().y);
             ELISE_COPY(
                         mTiffImg2.all_pts(),
                         mTiffImg2.in(),
                         mImg2.out()
                       );
             Tiff_Im mTiffImg3(aNameIm3.c_str());
             Im2D<U_INT1,INT4> mImg3(mTiffImg3.sz().x,mTiffImg3.sz().y);
             ELISE_COPY(
                         mTiffImg3.all_pts(),
                         mTiffImg3.in(),
                         mImg3.out()
                      );
             //read file point homo 1 & 2
             std::string aHomoIn1_2 = aICNM->Assoc1To2(aKHIn,aNameIm1,aNameIm2,true);  
             StdCorrecNameHomol_G(aHomoIn1_2,aDirImages);
             ElPackHomologue aPackIn1_2 =  ElPackHomologue::FromFile(aHomoIn1_2);   
             //read file point homo 3 & 1
             std::string aHomoIn3_1 = aICNM->Assoc1To2(aKHIn,aNameIm3,aNameIm1,true);
             StdCorrecNameHomol_G(aHomoIn3_1,aDirImages);
             ElPackHomologue aPackIn3_1 =  ElPackHomologue::FromFile(aHomoIn3_1);
             //read file point homo 2 & 3
             std::string aHomoIn2_3 = aICNM->Assoc1To2(aKHIn,aNameIm2,aNameIm3,true);
             StdCorrecNameHomol_G(aHomoIn2_3,aDirImages);
             ElPackHomologue aPackIn2_3 =  ElPackHomologue::FromFile(aHomoIn2_3);
             //read file point homo 3 & 2
             std::string aHomoIn3_2 = aICNM->Assoc1To2(aKHIn,aNameIm3,aNameIm2,true);
             StdCorrecNameHomol_G(aHomoIn3_2,aDirImages);
             ElPackHomologue aPackIn3_2 =  ElPackHomologue::FromFile(aHomoIn3_2);
             //read file point homo 1 & 3
             std::string aHomoIn1_3 = aICNM->Assoc1To2(aKHIn,aNameIm1,aNameIm3,true);
             StdCorrecNameHomol_G(aHomoIn1_3,aDirImages);
             ElPackHomologue aPackIn1_3 =  ElPackHomologue::FromFile(aHomoIn1_3);

             cout<<aPackIn1_2.size()<<" pts homo entre 1_2"<<endl;
             cout<<aPackIn1_3.size()<<" pts homo entre 1_3"<<endl;
             cout<<aPackIn2_3.size()<<" pts homo entre 2_3"<<endl;


                  //       Orientation      Projection      Distortion
                  //   R3 -------------> L3------------>C2------------->F2
             //get orientation information of 3 cameras
             std::string aNameOri1 = aICNM->Assoc1To1("NKS-Assoc-Im2Orient@-"+aOriInput,aNameIm1,true);
             std::string aNameOri2 = aICNM->Assoc1To1("NKS-Assoc-Im2Orient@-"+aOriInput,aNameIm2,true);
             std::string aNameOri3 = aICNM->Assoc1To1("NKS-Assoc-Im2Orient@-"+aOriInput,aNameIm3,true);
             CamStenope * aCam1 = CamOrientGenFromFile(aNameOri1 , aICNM);
             CamStenope * aCam2 = CamOrientGenFromFile(aNameOri2 , aICNM);
             CamStenope * aCam3 = CamOrientGenFromFile(aNameOri3 , aICNM);

      vector<PtTrip> PtTripGood;
      if (bStrategie == "1")
      {
             //for each point homo 1&2, search for its triplet in homo 2&3 (search P2 in homo 2_3)
             //If it is a point triplet, for each point homo 1&2, reprojeter vers img3 pour voir le distance

             for (ElPackHomologue::const_iterator itP=aPackIn1_2.begin(); itP!=aPackIn1_2.end() ; itP++)
             {
                 //lire les point homo
                 Pt2dr aP1 = itP->P1();  //Point img1
                 Pt2dr aP2 = itP->P2();  //Point img2
                 double d;
                 Pt3dr PInter1_2= aCam1->ElCamera::PseudoInter(aP1, *aCam2, aP2, &d);	//use Point img1 & 2 to search point 3d
                 Pt2dr PReproj3 = aCam3->ElCamera::R3toF2(PInter1_2);					//use point 3d to search Point img3

                 //search for point trilet P2 in fime homo 2_3
                 const ElCplePtsHomologues  * aTriplet2_3 = aPackIn2_3.Cple_Nearest(aP2,true);
                 double distP2 = sqrt(pow((aTriplet2_3->P1().x - aP2.x),2) + pow((aTriplet2_3->P1().y - aP2.y),2));
                 if (distP2 < 2)
                 {
                     //cout<<"Triplet= "<<aP1<<aP2<<aTriplet2_3->P2();
                     double distP3Reprj = sqrt(pow((aTriplet2_3->P2().x - PReproj3.x),2) + pow((aTriplet2_3->P2().y - PReproj3.y),2));
                     if (distP3Reprj < 2)
                     {
                         //cout<<"P3 verified = "<<PReproj3<<" ++ "<<distP3Reprj<<" pxls"<<endl;
                         PtTrip PointTrip; PointTrip.P1 = aP1; PointTrip.P2 = aP2; PointTrip.P3 = aTriplet2_3->P2();
                         PtTripGood.push_back(PointTrip);
                     }

                     else
                     {//cout<<"P3 and triplet not good "<< " ++ "<<distP3Reprj<<" pxls"<<endl;
                     }
                 }
             }
       }

      if (bStrategie == "2")
      {
           //for each point homo 1&2, find point P3 in cam3 by reprojection
          int w = 3; //size imagette

          for (ElPackHomologue::const_iterator itP=aPackIn1_2.begin(); itP!=aPackIn1_2.end() ; itP++)
          {
              //lire les point homo
              Pt2dr aP1 = itP->P1();  //Point img1
              Pt2dr aP2 = itP->P2();  //Point img2
              double d;
              Pt3dr PInter1_2= aCam1->ElCamera::PseudoInter(aP1, *aCam2, aP2, &d);	//use Point img1 & 2 to search point 3d
              Pt2dr PReproj3 = aCam3->ElCamera::R3toF2(PInter1_2);					//use point 3d to search Point img3
              //compute correlation b/w imagette P1 & P3
              cCorrelImage::setSzW(w);
              cCorrelImage Imgette1, Imgette2, Imgette3;
              Imgette1.getFromIm(&mImg1, aP1.x, aP1.y);
              Imgette2.getFromIm(&mImg2, aP2.x, aP2.y);
              Imgette3.getFromIm(&mImg3, PReproj3.x, PReproj3.y);
              //compute correlation b/w imagette P2 & P3
              double corr1_3 = Imgette1.CrossCorrelation(Imgette3);
              double corr2_3 = Imgette2.CrossCorrelation(Imgette3);
              //if correlation ok, keep P1 & P2
              if ((corr1_3 > 0.8) && (corr2_3 > 0.8))
                {
                  //search for point trilet P2 in fime homo 2_3
                  const ElCplePtsHomologues  * aTriplet2_3 = aPackIn2_3.Cple_Nearest(aP2,true);
                  double distP2 = sqrt(pow((aTriplet2_3->P1().x - aP2.x),2) + pow((aTriplet2_3->P1().y - aP2.y),2));
                  if (distP2 < 2)
                  {
                      //compute correlation b/w imagette P1 & P3origin and P2 & P3origin
                      //cout<<"P1 & P2 good "<<corr1_3<<" "<<corr2_3;
                      cCorrelImage Imgette3origin;
                      Imgette3origin.getFromIm(&mImg3, aTriplet2_3->P2().x, aTriplet2_3->P2().y);
                      double corr1_3o = Imgette1.CrossCorrelation(Imgette3origin);
                      double corr2_3o = Imgette2.CrossCorrelation(Imgette3origin);
                      double distP3 = sqrt( pow((aTriplet2_3->P2().x - PReproj3.x),2) + pow((aTriplet2_3->P2().y - PReproj3.y),2) );
                      if ((corr1_3o > corr1_3) && (corr2_3o > corr2_3))
                      {
                       //cout << " ++ P3 Origin better "<<corr1_3o<<" "<<corr2_3o<<" DistP3 = " <<distP3<<endl;
                        PtTrip PointTrip; PointTrip.P1 = aP1; PointTrip.P2 = aP2; PointTrip.P3 = aTriplet2_3->P2();
                        PtTripGood.push_back(PointTrip);
                      }
                      else
                      {
                        //cout<<" ++ P3 Reproject better"<<" DistP3 = " <<distP3<<endl;
                        PtTrip PointTrip; PointTrip.P1 = aP1; PointTrip.P2 = aP2; PointTrip.P3 = PReproj3;
                        PtTripGood.push_back(PointTrip);
                      }
                  }
                }
          }

      }

      if (bStrategie == "3")
      {
          double distP3_H32, distP3_H31;
          PtTrip PointTrip;
          //Search triplet [P1,P2,P3] from file Homol1-3 & 2-3
        for (ElPackHomologue::const_iterator itP=aPackIn1_2.begin(); itP!=aPackIn1_2.end() ; itP++)
        {
          Pt2dr aP1 = itP->P1();
          Pt2dr aP2 = itP->P2();
          const ElCplePtsHomologues  * aTriplet2_3 = aPackIn2_3.Cple_Nearest(aP2,true);
          double distP2 = sqrt(pow((aTriplet2_3->P1().x - aP2.x),2) + pow((aTriplet2_3->P1().y - aP2.y),2));
          if (distP2 < 1)
          {
            PointTrip.P1 = aP1; PointTrip.P2 = aP2; PointTrip.P3 = aTriplet2_3->P2();
            //Search for point P3 in file Homol3-1 (search by P1)
            const ElCplePtsHomologues  * aTriplet3_1 = aPackIn3_1.Cple_Nearest(aP1,false);
            double distP1 = sqrt(pow((aTriplet3_1->P2().x - aP1.x),2) + pow((aTriplet3_1->P2().y - aP1.y),2));
            if (distP1 < 1)
            {
              distP3_H31 = sqrt(pow((aTriplet3_1->P1().x - PointTrip.P3.x),2) + pow((aTriplet3_1->P1().y - PointTrip.P3.y),2));
              //Search for point P3 in file Homol3-2 (search by P2)
              const ElCplePtsHomologues  * aTriplet3_2 = aPackIn3_2.Cple_Nearest(aP2,false);
              distP2 = sqrt(pow((aTriplet3_2->P2().x - aP2.x),2) + pow((aTriplet3_2->P2().y - aP2.y),2));
              if (distP2 < 1)
              {
                distP3_H32 = sqrt(pow((aTriplet3_2->P1().x - PointTrip.P3.x),2) + pow((aTriplet3_2->P1().y - PointTrip.P3.y),2));
                //Decide by distance b/w P3 of triplet and P3 in Homol3-1 and 3-2
                if ((distP3_H31 < 2) && (distP3_H32 < 2))
                {
                  //cout<<"Good Triplet"<<endl;
                  PtTripGood.push_back(PointTrip);
                }
              }
            }
          }
        }

      }

      cout<<"There are "<<PtTripGood.size()<<" pts triplet good"<<endl;

      //===============TEST ------ Creat new file Homo -------===============//
      std::string aNameH1_2 = aICNM->Assoc1To2(aKHOut, aNameIm1, aNameIm2, true);
      std::string aNameH1_3 = aICNM->Assoc1To2(aKHOut, aNameIm1, aNameIm3, true);
      std::string aNameH2_1 = aICNM->Assoc1To2(aKHOut, aNameIm2, aNameIm1, true);
      std::string aNameH2_3 = aICNM->Assoc1To2(aKHOut, aNameIm2, aNameIm3, true);
      std::string aNameH3_2 = aICNM->Assoc1To2(aKHOut, aNameIm3, aNameIm2, true);
      std::string aNameH3_1 = aICNM->Assoc1To2(aKHOut, aNameIm3, aNameIm1, true);

      std::string aNameH1_2d = aICNM->Assoc1To2(aKHOutDat, aNameIm1, aNameIm2, true);
      std::string aNameH1_3d = aICNM->Assoc1To2(aKHOutDat, aNameIm1, aNameIm3, true);
      std::string aNameH2_1d = aICNM->Assoc1To2(aKHOutDat, aNameIm2, aNameIm1, true);
      std::string aNameH2_3d = aICNM->Assoc1To2(aKHOutDat, aNameIm2, aNameIm3, true);
      std::string aNameH3_2d = aICNM->Assoc1To2(aKHOutDat, aNameIm3, aNameIm2, true);
      std::string aNameH3_1d = aICNM->Assoc1To2(aKHOutDat, aNameIm3, aNameIm1, true);

      ElPackHomologue PairPoint1_2, PairPoint2_1, PairPoint1_3, PairPoint3_1, PairPoint3_2, PairPoint2_3;
      for (uint i=0; i<PtTripGood.size(); i++)
      {
          Pt2dr aP1 = PtTripGood[i].P1;
          Pt2dr aP2 = PtTripGood[i].P2;
          Pt2dr aP3 = PtTripGood[i].P3;

          PairPoint1_2.Cple_Add( ElCplePtsHomologues(aP1,aP2) );
          PairPoint2_1.Cple_Add( ElCplePtsHomologues(aP2,aP1) );
          PairPoint1_3.Cple_Add( ElCplePtsHomologues(aP1,aP3) );
          PairPoint3_1.Cple_Add( ElCplePtsHomologues(aP3,aP1) );
          PairPoint3_2.Cple_Add( ElCplePtsHomologues(aP3,aP2) );
          PairPoint2_3.Cple_Add( ElCplePtsHomologues(aP2,aP3) );
      }
      PairPoint1_2.StdPutInFile(aNameH1_2);
      PairPoint2_1.StdPutInFile(aNameH2_1);
      PairPoint1_3.StdPutInFile(aNameH1_3);
      PairPoint3_1.StdPutInFile(aNameH3_1);
      PairPoint3_2.StdPutInFile(aNameH3_2);
      PairPoint2_3.StdPutInFile(aNameH2_3);

      PairPoint1_2.StdPutInFile(aNameH1_2d);
      PairPoint2_1.StdPutInFile(aNameH2_1d);
      PairPoint1_3.StdPutInFile(aNameH1_3d);
      PairPoint3_1.StdPutInFile(aNameH3_1d);
      PairPoint3_2.StdPutInFile(aNameH3_2d);
      PairPoint2_3.StdPutInFile(aNameH2_3d);


return EXIT_SUCCESS;
}



/*strategie à faire:
1)
Homol1_2 => P1 & P2, Homol2_3 => P2 & P3, triplet [P1, P2, P3].
Pt3d P3' reprojeter ves cam3 à partir P1 et P2
P3' = P3 ?
si OK => fabriquer Homol nouvel avec P1 P2 P3 pour tout les sens

2)
Homol1_2 => P1 & P2 => Pt3d ===reprojeter==> P3
Corellation entre P1 et P3
Corellation entre P2 et P3
si OK => garde P1 et P2
=> P3 juste pour validation point homo entre P1 et P2
Q: comment choisir le pose bien pour cam3 ? (avant ou apres cam1 et cam2)
    
3)
Homol cohérent, pas besoins l'orientation du caméra => si camera orientation est pas bonne, on peut eviter
Homol1_2 => P1 & P2, Homol2_3 => P2 & P3, triplet [P1, P2, P3].
P3 => chercher dans Homol3_1 => si trop loin avec P3 => pas bonne ????????????????????????????????????????
P3 => chercher dans Homol3_2 => si trop loin avec P3 => pas bonne couple P2 P3 ???????????????????????????
Comment faire une methode de validation plus efficace ?
*/
