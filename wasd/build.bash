#!/bin/bash
set -e

# === SETTINGS ===
BUILD_TYPE=${1:-debug}   # "debug" or "release"
PROJECT_DIR="/f/Learning-C/wasd"
SRC_FILE="main.c"
OUT_FILE="main"
RAYLIB_BASE="/c/raylib"
RAYLIB_SRC="$RAYLIB_BASE/raylib/src"
RAYLIB_INCLUDE="$RAYLIB_BASE/include"
RAYLIB_LIB="$RAYLIB_BASE/lib"

# === CLEAN OLD FILES ===
echo "=== Cleaning old build files ==="
rm -f "$PROJECT_DIR/$OUT_FILE" "$PROJECT_DIR/$OUT_FILE.exe"

# === DETECT OS ===
UNAME_OUT="$(uname -s)"
case "${UNAME_OUT}" in
    Linux*)     
        OS_NAME="Linux"
        ;;
    MINGW*|MSYS*|CYGWIN*)
        OS_NAME="Windows"
        ;;
    *)
        echo "Unknown OS: ${UNAME_OUT}"
        exit 1
        ;;
esac
echo "Detected OS: $OS_NAME"

# === BUILD RAYLIB ===
echo "=== Building Raylib ==="
if [ "$OS_NAME" = "Linux" ]; then
    cd "$RAYLIB_SRC"
    make PLATFORM=PLATFORM_DESKTOP
else
    cd "$RAYLIB_SRC"
    mingw32-make PLATFORM=PLATFORM_DESKTOP
fi

# === COPY HEADERS & LIBS ===
mkdir -p "$RAYLIB_INCLUDE"
mkdir -p "$RAYLIB_LIB"
cp raylib.h "$RAYLIB_INCLUDE"/
cp libraylib.a "$RAYLIB_LIB"/

# === COMPILER FLAGS ===
if [ "$BUILD_TYPE" = "debug" ]; then
    CFLAGS="-std=c99 -Wall -g"
else
    CFLAGS="-std=c99 -Wall -O2"
fi

# === BUILD PROJECT ===
echo "=== Building project ($BUILD_TYPE) ==="
cd "$PROJECT_DIR"

if [ "$OS_NAME" = "Linux" ]; then
    gcc "$SRC_FILE" -o "$OUT_FILE" $CFLAGS \
        -I"$RAYLIB_INCLUDE" \
        -L"$RAYLIB_LIB" \
        -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
else
    gcc "$SRC_FILE" -o "$OUT_FILE.exe" $CFLAGS \
        -I"$RAYLIB_INCLUDE" \
        -L"$RAYLIB_LIB" \
        -lraylib -lopengl32 -lgdi32 -lwinmm
fi

echo "=== Build successful! ==="
