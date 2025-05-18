@tool
extends EditorPlugin

const AUTOLOAD_NAME = "HellStorm";

func _enter_tree() -> void:
  add_autoload_singleton(AUTOLOAD_NAME, "res://addons/hellstorm/hellstorm.tscn");
  pass;

func _exit_tree() -> void:
  remove_autoload_singleton(AUTOLOAD_NAME);
  pass;
