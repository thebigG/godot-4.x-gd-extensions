#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>


// #include "godot_cpp/classes/core/os/memory.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include "godot_cpp/classes/path2d.hpp"
#include "godot_cpp/classes/curve2d.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/animation.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "godot_cpp/templates/vector.hpp"
#include <memory>


using namespace godot;

namespace godot {

//TODO: I should make AnimationUtils a singleton
class AnimationUtils : public RefCounted {
	GDCLASS(AnimationUtils, RefCounted);
	int count;

protected:
	static void _bind_methods();

public:
	enum HZ_MODE { UP = 1,
		DOWN = 2 };
	void add(int p_value);
	void reset();
	int get_total() const;
	Ref<Animation> animation;
	//TODO:This function really should be static...
	Ref<Animation> get_animation(NodePath node_path, String text, String delimeter = " ");
	Vector2 h_line_pattern(Ref<Curve2D> path, Vector2 origin, int length);
	Vector2 v_line_pattern(Ref<Curve2D> path, Vector2 origin, int length);
	Vector2 hz_line_pattern(Ref<Curve2D> path, Vector2 origin, int length, HZ_MODE mode);
	Vector2 zig_zag_pattern(Ref<Curve2D> path, Vector2 origin, int width, int height);
	Vector2 rectangle_pattern(Ref<Curve2D> path, Vector2 origin, int width, int height);

	//	Vector2 hz_line_pattern(Curve2D path,Vector2 origin,  int length);
	AnimationUtils();
};

}

VARIANT_ENUM_CAST(AnimationUtils::HZ_MODE);

#endif // CORE_UTILS_H
