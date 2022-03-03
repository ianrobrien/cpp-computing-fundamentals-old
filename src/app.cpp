/****************************************************************************
 * Copyright (c) 2018-present, Ian R. O'Brien                               *
 *                                                                          *
 * Licensed under the MIT License (the "License");                          *
 *  you may not use this file except in compliance with the License.        *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *     https://opensource.org/licenses/MIT                                  *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ***************************************************************************/
#include "app.h"
#include "appinfo.h"

string App::getProjectName() const {
    return APPLICATION_NAME;
}

string App::getProjectCodeName() const {
    return APPLICATION_CODENAME;
}

string App::getProjectVendorID() const {
    return APPLICATION_VENDOR_ID;
}

string App::getProjectVendorName() const {
    return APPLICATION_VENDOR_NAME;
}

string App::getProjectID() const {
    return APPLICATION_ID;
}

int App::getProjectMajorVersion() const {
    return APPLICATION_VERSION_MAJOR;
}

int App::getProjectMinorVersion() const {
    return APPLICATION_VERSION_MINOR;
}

int App::getProjectPatchVersion() const {
    return APPLICATION_VERSION_PATCH;
}

string App::getProjectVersion() const {
    return APPLICATION_VERSION_STRING;
}

string App::getProjectCopyrightYears() const {
    return APPLICATION_COPYRIGHT_YEARS;
}

