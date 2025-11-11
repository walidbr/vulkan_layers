set -x

cd libGPULayers
LAYER="profiler"
rm -rf ${LAYER}
# ln  -s ../${LAYER} ./
cp -r ../${LAYER} ./

generate_files(){
    git submodule update --init
    python3 ./generator/generate_vulkan_common.py
    OUTPUT_DIR="layer_demo"
    if [ -d "$OUTPUT_DIR" ]; then
        echo "Removing existing output directory: $OUTPUT_DIR"
        rm -rf "$OUTPUT_DIR"
    fi
    python3 ./generator/generate_vulkan_layer.py --project-name VkLayerDemo --output "$OUTPUT_DIR"
}

# Build the layer_example
build_layer() {
    LAYER_DIR=$1
    BUILD_DIR="${LAYER_DIR}/build"  # Use a consistent build directory
    echo "Building layer in ${LAYER_DIR} with build directory ${BUILD_DIR}"
    rm -rf "${BUILD_DIR}"  # Clear existing build directory
    mkdir -p "${BUILD_DIR}"
    cmake -S "${LAYER_DIR}" -B "${BUILD_DIR}" -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON
    cmake --build "${BUILD_DIR}"
}

build_layer ${LAYER}