#!/bin/bash
cd "$(dirname "$0")"
xvfb-run wine ./mario.exe
