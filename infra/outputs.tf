output "public_ip_server_mqtt" {
  value       = aws_instance.mqtt.public_ip
  sensitive   = false
  description = "Public IP server MQTT"
}
