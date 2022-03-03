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

#include <boost/program_options.hpp>
#include <cstdlib>
#include <iostream>
#include "app.h"

using namespace std;
namespace po = boost::program_options;

po::options_description getDescription() {
  po::options_description desc("Options");
  desc.add_options()("help,h", "Display this message")(
      "version,v", "Display the version number");

  return desc;
}

int main(int argc, char *argv[]) {
  po::options_description desc = getDescription();
  po::variables_map varmap;

  try {
    store(po::command_line_parser(argc, argv).options(desc).run(), varmap);
    notify(varmap);
  } catch (po::error &error) {
    cerr << error.what() << endl;
    return EXIT_FAILURE;
  }

  if (varmap.count("help")) {
    cout << desc << endl;
  }

  if (varmap.count("version")) {
    App app;
    cout << app.getProjectVersion() << endl;
  }

  return EXIT_SUCCESS;
}
