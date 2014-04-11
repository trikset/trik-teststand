/* Copyright 2013 Roman Kurbatov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtXml/QDomDocument>

class Configurer : public QObject
{
	Q_OBJECT
public:
	Configurer();

	struct Stage
	{
		QString generatorPort, capturePort;
	};

	QList<Stage> stages();

	struct Value {
		int frequency;
		int duty;
	};

	QList<Value> values();

private:
	QDomDocument config;
	QList<Stage> mStages;

	QList<Value> mValues;

	void initStages();
	void initValues();
};
