data "aws_key_pair" "main" {
  key_name           = "mqtt-server"
  include_public_key = true

  filter {
    name   = "tag:Name"
    values = ["mqtt-server"]
  }
}