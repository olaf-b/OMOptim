// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR 
 * THIS OSMC PUBLIC LICENSE (OSMC-PL). 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE. 
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or  
 * http://www.openmodelica.org, and in the OpenModelica distribution. 
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)

 	@file Dymola.h
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 

  */
#ifndef _DYMOLA_H
#define _DYMOLA_H

/*!
 * \file Dymola.h
 * \brief File containing Dymola class description.
 * \author Hubert Thieriot (CEP-Armines)
 * \version 0.1
 */

#include <iostream>
#include <vector>
#include "Variable.h"
#include "MOVector.h"
#include <QtCore/QObject>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtCore/QTextStream>
#include "ModClass.h"
#include "MOVector.h"
#include "vqtconvert.h"
#include "MOParameter.h"

class Dymola
{
	/*! \class Dymola
   * \brief Class containing handling functions for Dymola.
   *
   *  All functions defined in this class are static. There are used to :
   *	-read input or output files
   *	-launch Dymosim application
   */

public:
	Dymola(void);
	~Dymola(void);


	static QString getExecutablePath();
        static bool firstRun(QString moPath,QString modelToConsider,QString storeFolder,QString logFilePath);
	static bool createDsin(QString moPath,QString modelToConsider,QString folder);
        static void start(QString path,int maxNSec=-1);
	static void verifyInstallation();
	//static QString getPreambleFromDsin(QTextStream *);
	static void getVariablesFromDsFile(QString, MOVector<Variable> *,QString _modelName);
	static void getVariablesFromDsFile(QTextStream *, MOVector<Variable> *,QString _modelName);

	static void getFinalVariablesFromDsFile(QString, MOVector<Variable> *,QString _modelName);
	static void getFinalVariablesFromDsFile(QTextStream *, MOVector<Variable> *,QString _modelName);

	static void setVariablesToDsin(QString fileName,QString modelName, MOVector<Variable> *,MOParameters *parameters);
        static void writeParameters(QString &allDsinText,MOParameters *parameters);
	static QString sciNumRx();
	//static QString Dymola::variableToValueLines(Variable* variable);


	// Parameters
        enum DymolaParameters{STOPTIME,TOLERANCE,NINTERVAL,SOLVER,MAXSIMTIME};
        enum DymolaSolvers{DASSL=8,EULER=11};

};

#endif