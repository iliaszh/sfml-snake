# How to build

The project is built with CMake.

Clone the repo with all submodules:
```sh
git clone --recurse-submodules <repo>
```

1. Run vcpkg's bootstrap script in repository's ./vcpkg directory:

- if on Windows:
	```powershell
	cd vcpkg && .\bootstrap-vcpkg.bat -disableMetrics
	```
- if on Linux:
	```sh
	cd vcpkg
	chmod +x ./bootstrap-vcpkg.sh
	./bootstrap-vcpkg.sh -disableMetrics
	```
2. If on Linux, install SFML's dependencies.
3. Build with CMake.