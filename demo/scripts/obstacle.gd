extends StaticBody2D

func _on_hellstorm_projectile_hit(meta: Dictionary) -> void:
  print("Hit by " + meta['name']);
