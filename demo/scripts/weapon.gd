extends Node2D

@export var projectile: HellStormProjectileData2D;
@export var initial_rotation: float = 0;
@export var rotation_speed: float = 1;
@export var interval: float = 0.5;

var _can_shoot = false;
var _projectile_count = 0;
var _timer = 0;

func _enter_tree() -> void:
  HellStorm.initialize(get_canvas(), get_world_2d().space);
  HellStorm.set_boundary(Rect2(-1152, -648, 1152 * 2.0, 648 * 2.0));

  call_deferred("enable_weapon");

func _ready() -> void:
  rotation_degrees = initial_rotation;

func enable_weapon() -> void:
  _can_shoot = true;

func _physics_process(delta: float) -> void:
  rotation_degrees += rotation_speed * delta;

  if not _can_shoot:
    return;

  if _timer < interval:
    _timer += delta;
    return;

  #if _projectile_count > 100:
    #return;

  HellStorm.spawn_projectile(projectile, self.global_transform);
  _timer = 0;
  _projectile_count += 1;
