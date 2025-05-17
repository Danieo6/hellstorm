@tool
extends EditorPlugin

func _enter_tree() -> void:
  var hellstorm = HellStorm.new();
  hellstorm.test();
