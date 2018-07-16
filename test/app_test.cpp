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

#include <string.h>
#include "gtest/gtest.h"

#include "src/app.h"
#include "src/appinfo.h"

/* to use a test fixture, we derive from testing::Test */
class AppTest : public testing::Test {
 protected:
  /* will be called before each test is run */
  virtual void SetUp() { app = new App(); }

  /* will be called after each test is run */
  virtual void TearDown() { delete app; }
  App *app;
};

/* using test fixture with TEST_F instead of TEST */
TEST_F(AppTest, GetProjectName) {
  ASSERT_STREQ(app->getProjectName().c_str(), APPLICATION_NAME);
}

TEST_F(AppTest, GetProjectDetails) {
  ASSERT_STREQ(app->getProjectCodeName().c_str(), APPLICATION_CODENAME);
  ASSERT_STREQ(app->getProjectVendorID().c_str(), APPLICATION_VENDOR_ID);
  ASSERT_STREQ(app->getProjectVendorName().c_str(), APPLICATION_VENDOR_NAME);
  ASSERT_STREQ(app->getProjectID().c_str(), APPLICATION_ID);
  ASSERT_EQ(app->getProjectMajorVersion(), APPLICATION_VERSION_MAJOR);
  ASSERT_EQ(app->getProjectMinorVersion(), APPLICATION_VERSION_MINOR);
  ASSERT_EQ(app->getProjectPatchVersion(), APPLICATION_VERSION_PATCH);
  ASSERT_STREQ(app->getProjectVersion().c_str(), APPLICATION_VERSION_STRING);
  ASSERT_STREQ(app->getProjectCopyrightYears().c_str(),
               APPLICATION_COPYRIGHT_YEARS);
}
