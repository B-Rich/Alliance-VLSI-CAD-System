/*------------------------------------------------------------\
|                                                             |
| Tool    :                    DRUC                           |
|                                                             |
| File    :                  DEFEXCLU.C                       |
|                                                             |
| Authors :                Renaud Patrick                     |
|                                                             |
| Date    :                   26/07/94                        |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mph.h"
#include "mut.h"
#include "rds.h"
#include "rwi.h"
#include "rut.h"
#include "rtl.h"
#include "rfm.h"
#include "rpr.h"

#include "drucutil.h"
#include "vmctools.h"
#include "deftools.h"
#include "defexclu.h"
/*------------------------------------------------------------\
|                                                             |
|                       DefExclu  Fonctions                   |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         DrucDefineExclusion                 |
| Definit un layer temporaire caracterise par l'operateur     |
| contenu dans l'instruction ayant les deux layers source     |
| comme operandes                                             |
| range le resultat dans le tableau des layers userdefini par |
| l'instruction                                               |
\------------------------------------------------------------*/

void DrucDefineExclusion ( DrucFigureRds,
                           DrucRdsWindow,
                           DrucInstructionCourante
                         )
     rdsfig_list               *DrucFigureRds;
     rdswindow                 *DrucRdsWindow;
     DrucTypeStructInstruction *DrucInstructionCourante;

{

         chain_list      *PtChaine;
         rdsrec_list     *TmpRectangleSource;
         rdswin_list     *TmpWindowSource2;
         long             UnaireX;
         long             UnaireDX;
         long             UnaireY;
         long             UnaireDY;
register int              TabIndex2;
register rdswinrec_list  *TabRectangleSource2 = NULL;

  for ( TmpRectangleSource  = DrucFigureRds->LAYERTAB [ DrucInstructionCourante->LAYER_1 ];
        TmpRectangleSource != (rdsrec_list *)NULL;
        TmpRectangleSource  = TmpRectangleSource->NEXT
      )
  {
   /*\
    *  recuperer toutes les fenetres liees au rectangle
   \*/
    DrucCalculOperationUnaire (   DrucRdsWindow,
                                  DrucInstructionCourante,
                                  TmpRectangleSource,
                                & UnaireX,
                                & UnaireDX,
                                & UnaireY,
                                & UnaireDY
                              );

    PtChaine = getrdswindow   ( UnaireX,
                                UnaireY,
                                UnaireDX,
                                UnaireDY,
                                DrucRdsWindow
                              );

    while ( PtChaine != (chain_list *)NULL
          )
    {
    /*\
     * parcours de chaque fenetre
    \*/
      TmpWindowSource2    = ( rdswin_list *) PtChaine->DATA;
      PtChaine            = PtChaine ->NEXT;
      TabRectangleSource2 = TmpWindowSource2->LAYERTAB
                                 [ DrucInstructionCourante->LAYER_2 ];
      /*\
       * parcours des tableaux de la fenetre du layer 2
      \*/
      while ( TabRectangleSource2 != (rdswinrec_list *)NULL
            )
      {
        /*\
         * parcourir tous les rectangles du layer B
        \*/
        TabIndex2 = 0;

        while ( TabIndex2 < RWI_MAX_REC
              )
        {
          if ( MACRO_RECT_SOURCE2 [ TabIndex2 ] != ( rdsrec_list *)NULL )
          {
            DrucMarqueInclusion ( UnaireX,
                                  UnaireDX,
                                  UnaireY,
                                  UnaireDY,
                                  TmpRectangleSource,
                                  MACRO_RECT_SOURCE2 [ TabIndex2 ]
                                );
          }

          TabIndex2 ++;
        } /* while les rectangles d'un tableau du layer 2 */
        TabRectangleSource2 = TabRectangleSource2->NEXT;
      } /* while les tableaux du layer 2 */
    } /* while les fenetres du layer 2 */

    if ( ( TmpRectangleSource->FLAGS &
           DRUC_FLAG_REC_INCLUS   ) == DRUC_NOFLAGS
       )
    {
      DrucExclusionRectangle ( DrucFigureRds,
                               DrucRdsWindow,
                               TmpRectangleSource,
                               DrucInstructionCourante,
                               UnaireX,
                               UnaireDX,
                               UnaireY,
                               UnaireDY
                             );
    }
  } /* for le parcours des rectangles du layer 1 */

  DrucClearFlag          ( DrucFigureRds->LAYERTAB[ DrucInstructionCourante->LAYER_1 ],
                           DRUC_FLAG_REC_INCLUS
                         );
}
