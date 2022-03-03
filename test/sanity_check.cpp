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

#include "gtest/gtest.h"

TEST(SanityCheck, CheckIntrinsics) {
  /* we hope that true is true */
  ASSERT_TRUE(true);

  /* these values should be equal */
  ASSERT_EQ(2, 1 + 1);

  int x[] = {1, 2, 3};
  int y[] = {1, 2, 3};
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(x[i], y[i]);
  }

  double a = 1.51;
  double b = 1.52;
  ASSERT_NE(a, b);
}
