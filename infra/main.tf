resource "aws_instance" "mqtt" {
  instance_type          = "t2.micro"
  ami                    = data.aws_ami.ubuntu_18_04.id
  key_name               = data.aws_key_pair.main.key_name
  vpc_security_group_ids = [aws_security_group.mqtt.id]
  subnet_id              = "subnet-06a3260e535246dde"

  root_block_device {
    volume_size = 30
    volume_type = "gp3"
  }

  tags = merge(
    local.tags,
    {
      "Name" = "MQTT Server IOT PENS 2023",
    },
  )

  provisioner "remote-exec" {
    inline = ["echo 'WAIT UNTIL SSH IS READY'"]

    connection {
      type        = "ssh"
      user        = "ubuntu"
      private_key = file("mqtt-server.pem")
      host        = aws_instance.mqtt.public_ip
    }
  }

  provisioner "local-exec" {
    command = "ansible-playbook -i ${aws_instance.mqtt.public_ip}, --private-key ./mqtt-server.pem main.yaml"
  }
}

resource "aws_instance" "web" {
  instance_type          = "t2.micro"
  ami                    = data.aws_ami.ubuntu_18_04.id
  key_name               = data.aws_key_pair.main.key_name
  vpc_security_group_ids = [aws_security_group.web.id]
  subnet_id              = "subnet-06a3260e535246dde"

  root_block_device {
    volume_size = 30
    volume_type = "gp3"
  }

  tags = merge(
    local.tags,
    {
      "Name" = "Demo Web Workshop IOT",
    },
  )

  provisioner "remote-exec" {
    inline = ["echo 'WAIT UNTIL SSH IS READY'"]

    connection {
      type        = "ssh"
      user        = "ubuntu"
      private_key = file("mqtt-server.pem")
      host        = aws_instance.web.public_ip
    }
  }

  provisioner "local-exec" {
    command = "ansible-playbook -i ${aws_instance.web.public_ip}, --private-key ./mqtt-server.pem web.yaml"
  }
}