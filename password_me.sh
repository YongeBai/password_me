#!/bin/bash

cd "$(dirname "$0")"
PASSWORD=$(./password_me)
echo "$PASSWORD" | xsel --clipboard
notify-send "Password copied to clipboard"