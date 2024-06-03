#!/bin/bash

PASSWORD=$(./password_me)
echo "$PASSWORD" | xsel --clipboard
notify-send "Password copied to clipboard"