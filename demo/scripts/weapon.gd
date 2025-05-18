extends Node2D

@export var projectile: ProjectileData;

var _can_shoot = false;
var _projectile_count = 0;
var _timer = 0;

func _enter_tree() -> void:
  HellStorm.initialize(get_canvas(), get_world_2d().space);
  
  call_deferred("enable_weapon");

func enable_weapon() -> void:
  _can_shoot = true;

func _physics_process(delta: float) -> void:
  if not _can_shoot:
    return;

  if _timer < 0.5:
    _timer += delta;
    return;

  #if _projectile_count > 100:
    #return;

  HellStorm.spawn_projectile(projectile, self.global_transform);
  _timer = 0;
  _projectile_count += 1;
