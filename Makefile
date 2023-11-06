build-godot:
	cd godot-cpp && scons platform=linux -j8 custom_api_file=./gdextension/extension_api.json
build-linux:
	scons platform=linux

build-windows:
	scons platform=windows

build-mac:
	scons platform=macos

build-container:
	docker build . -t godot-4.x-modules:latest
