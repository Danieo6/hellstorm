extends VBoxContainer

@onready var fps_label = $FPSCounter;
@onready var projectiles_label = $ProjectileCounter;

func _physics_process(delta: float) -> void:
  fps_label.text = "FPS: " + str(Engine.get_frames_per_second());
  projectiles_label.text = "Projectiles: " + str(HellStorm.get_projectiles_count());
