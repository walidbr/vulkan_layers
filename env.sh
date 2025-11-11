export LD_LIBRARY_PATH=./libGPULayers/profiler/build/source/:$LD_LIBRARY_PATH
export VK_INSTANCE_LAYERS=VK_LAYER_LGL_Profiler
export VK_LAYER_PATH=./libGPULayers/profiler
export VK_LOADER_DEBUG=all

$1