call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64

set ACTION=build
if /I "%1" == "do_test" (set ACTION=do_test) 

set BUILD_TYPE=Debug
if /I "%2" == "release" (set BUILD_TYPE=Release) 

IF NOT EXIST build mkdir build

pushd build

if %ACTION% == do_test goto DoTest

cmake -G "Visual Studio 14 2015 Win64" ..

devenv ProjectStructureExample.sln /Build %BUILD_TYPE%

:DoTest

ctest -C %BUILD_TYPE% -L unit --verbose

popd