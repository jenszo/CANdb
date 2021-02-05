[![Build Status](https://travis-ci.org/jenszo/CANdb.svg?branch=master)](https://travis-ci.org/jenszo/CANdb) (customized fork)
<br />

# CANdb - Customized
Library for parsing CAN bus database description formats - **credits to the people from GENIVI for a great and clean, grammar-based DBC implementation!**

**What is different ?**
For their toolchain they use a rolling release approach pulling in dependencies through submodules (see src/3rdParty).
This is not suitable for my own needs and projects which I prefer to tie to specific release tags of dependencies only.
Furthermore, some of my compilation and installation parameters simply differ from theirs.

*Changes:*
- Building the library with -fPIC
- Allowing installation of Debug and Release variants for bundled distribution
- Distributing small CMake script to pull in CANdb as a dependancy in external projects
- Versioning / Tagging (using the release date)
- Removing spdlog dependancy to their development branch; replacing it with a cmake find script with release version requirement to avoid linking issues with my own libraries when spdlog changes it's API.
- Travis builds ARM Linux as well (I need this to run on Raspberry) but dumps appveyor (I dont need Windows builds)
- `CANdb::DBCSimpleParser` wrapping around internal std::expected usage to avoid a) this particular dependency when linking and b) potential binary conflicts in the long run.

Down the line, the branch 'genivi' is supposed to be merged with changes from genivi's 'master' branch.
I do my work on this master branch and merge stable revisions from there.

Changes that could be suitable for a pull request are merged with 'genivi' for pull requests.
