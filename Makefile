build-godot:
	cd godot-cpp && scons platform=linux -j8 custom_api_file=./gdextension/extension_api.json
