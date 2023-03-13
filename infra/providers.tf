terraform {
  backend "s3" {
    bucket                  = "pratamaizzat-directive-tf-state"
    key                     = "workshop/pens/iot/2023/terraform.tfstate"
    region                  = "ap-southeast-1"
    dynamodb_table          = "terraform-state-locking"
    encrypt                 = true
    shared_credentials_file = "~/.aws/credentials"
    profile                 = "vscode"
  }

  required_providers {
    aws = {
      source = "hashicorp/aws"
    }
  }
}

provider "aws" {
  region                   = "ap-southeast-1"
  shared_credentials_files = ["~/.aws/credentials"]
  profile                  = "vscode"
}