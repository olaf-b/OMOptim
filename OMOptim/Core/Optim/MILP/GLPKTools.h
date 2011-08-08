﻿// $Id$
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

 	@file GLPKTools.h
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 

  */
#ifndef _GLPKTOOLS_H
#define _GLPKTOOLS_H


#include <QtCore/QObject>
#include <QtCore/QVector>
#include <QtCore/QStringList>

#include "MilpVariableResult.h"
#include <glpk.h>

class GlpkTools
{
public :
	
static QString listToSet(QString setName, QStringList list);
static QString listToSet(QString setName, QList<double> _list);
static void fill(MilpVariableResult0D &var, glp_prob * glpProblem,double defaultValue,QStringList colNames = QStringList());
static void fill(MilpVariableResult1D &var, glp_prob * glpProblem,QStringList colNames = QStringList());
static void fill(MilpVariableResult2D &var, glp_prob * glpProblem,QStringList colNames = QStringList());
static void fill(MilpVariableResult3D &var, glp_prob * glpProblem,QStringList colNames = QStringList());
static void fill(MilpVariableResult4D &var, glp_prob * glpProblem,QStringList colNames = QStringList());
static QStringList getColNames(glp_prob *glpProblem);


};



#endif