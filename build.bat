call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64

IF NOT EXIST build mkdir build

pushd build

cmake -G "Visual Studio 14 2015 Win64" ..

devenv ProjectStructureExample.sln /Build

popd