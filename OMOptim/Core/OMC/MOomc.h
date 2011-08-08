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

 	@file MOOptVector.h
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 

  */
#ifndef OMS_H
#define OMS_H

#include <exception>
#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QProcess>
#include <QtCore/QStringList>

#include "InfoSender.h"
#include "omc_communication.h"
#include "OMCHelper.h"
#include "StringHandler.h"
#include "Modelica.h"
#include "omc_communicator.h"
#include "VariableType.h"



class Project;
class Variable;

class MOomc : public QObject
{
	Q_OBJECT

public:
	MOomc(QString appName,bool start = true);
	~MOomc();


public :

	//Thread management for MO
	void addUsingThread(QThread*,QString);
	void removeUsingThread(QThread*);
	QList<QThread*> getThreads();
	QStringList getThreadsNames();

	//Modelica functions
	QStringList getClassNames(QString parentClass = "");
	QStringList getPackages(QString parentClass);
	QStringList getModels(QString parentClass);
	QStringList getElementInfos(QString parentClass);

	QStringList getParameterNames(QString parentClass, bool includeInherited=false);
	QStringList getInheritedClasses(QString parentClass);
	QStringList getComponentModifierNames(QString componentName);
	QString getComponentModifierValue(QString componentName,QString modifierName);
	bool setComponentModifiers(QString compName,QString model, QStringList modNames,QStringList modValues);
	
	QString getAnnotation(QString compName,QString compClass);

	int getConnectionNumber(QString className);
	void getConnections(QString curComp,QStringList &aNames, QStringList &bNames);
	bool deleteConnection(QString org,QString dest,QString model);
	bool deleteConnections(QStringList orgs,QStringList dests,QString model);
	bool deleteConnections(QStringList orgs,QList<QStringList> dests,QString model);

	bool addConnection(QString org, QString dest);
	bool addConnections(QStringList orgs, QStringList dests);
	bool addConnections(QStringList orgs, QList<QStringList> dests);
	
	void getInheritedComponents(QString parentClass, QStringList & names, QStringList & classes);
	void getContainedComponents(QString parentClass, QStringList & compNames,QStringList & compClasses);
	
	void readElementInfos(QString parentClass,QStringList &packagesClasses,QStringList &modelsClasses,QStringList &compsNames,QStringList &compsClasses);

	void loadModel(QString filename,bool force,bool &ok,QString & Error);
	QStringList getDependenciesPaths(QString fileName,bool commentImportPaths);
	void loadStandardLibrary();


	bool isConnector(QString ClassName);
	bool isModel(QString ClassName);
	bool isPackage(QString ClassName);
	bool isPrimitive(QString ClassName);
	bool isComponent(QString name);
	QString getPrimitiveClass(QString className);
	bool isPrimitivelyInteger(QString className);
	bool isPrimitivelyReal(QString className);
	bool isPrimitivelyBoolean(QString className);
        VariableType getPrimitiveDataType(QString className);
	QString getComponentClass(QString parameter);
	Modelica::ClassRestr getClassRestriction(QString ClassName);

	bool translateModel(QString model);
	
	bool deleteComponent(QString compName);
	bool save(QString model);
	bool addComponent(QString name,QString className, QString modelName,QString annotation);

	// added functions
	QString getFileOfClass(QString);
	QStringList getClassesOfFile(QString);
	QString runScript(QString);
        QString changeDirectory(QString directory);
        QString getResult();
        bool isStarted();

	//Communication functions
	QString evalCommand(QString comm);
        //void setCommand(QString comm);
//	void evalCommand();
	void exit();
	bool startServer();
	void stopServer();
	void clear();

	
        //OmcCommunicator* getCommunicator();

	

signals:
	void startOMCThread(QString);
	void finishOMCThread(QString);
	


private:
//	void exceptionInEval(std::exception &e);

//	QString command;
	int nbCalls;

        //OmcCommunicator* mCommunicator;

	
	QString omc_version_;
	
	bool mHasInitialized;
	QString mName;
        QString mResult;
        QString mObjectRefFile;
	OmcCommunication_var mOMC;

	QList<QThread*> threads;
	QStringList threadsNames;


};

#endif