typedef struct VkInstance_T* VkInstance;
typedef struct VkDeviceMemory_T *VkDeviceMemory;
typedef struct VkPhysicalDevice_T* VkPhysicalDevice;
typedef struct VkBuffer_T *VkBuffer;
typedef struct VkImage_T *VkImage;
typedef struct VkDevice_T* VkDevice;
typedef struct VkCommandBuffer_T* VkCommandBuffer;
typedef uint64_t VkDeviceSize;
typedef uint32_t VkFlags;
typedef uint32_t VkBool32;
typedef void ( *PFN_vkVoidFunction)(void);
typedef PFN_vkVoidFunction ( *PFN_vkGetInstanceProcAddr)(VkInstance instance, const char* pName);
typedef PFN_vkVoidFunction ( *PFN_vkGetDeviceProcAddr)(VkDevice device, const char* pName);
typedef enum VkMemoryPropertyFlagBits {
    VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 0x00000001,
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 0x00000002,
    VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 0x00000004,
    VK_MEMORY_PROPERTY_HOST_CACHED_BIT = 0x00000008,
    VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT = 0x00000010,
    VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkMemoryPropertyFlagBits;
typedef VkFlags VkMemoryPropertyFlags;
typedef enum VkMemoryHeapFlagBits {
    VK_MEMORY_HEAP_DEVICE_LOCAL_BIT = 0x00000001,
    VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkMemoryHeapFlagBits;
typedef VkFlags VkMemoryHeapFlags;
typedef enum VkResult {
    VK_SUCCESS = 0,
    VK_NOT_READY = 1,
    VK_TIMEOUT = 2,
    VK_EVENT_SET = 3,
    VK_EVENT_RESET = 4,
    VK_INCOMPLETE = 5,
    VK_ERROR_OUT_OF_HOST_MEMORY = -1,
    VK_ERROR_OUT_OF_DEVICE_MEMORY = -2,
    VK_ERROR_INITIALIZATION_FAILED = -3,
    VK_ERROR_DEVICE_LOST = -4,
    VK_ERROR_MEMORY_MAP_FAILED = -5,
    VK_ERROR_LAYER_NOT_PRESENT = -6,
    VK_ERROR_EXTENSION_NOT_PRESENT = -7,
    VK_ERROR_FEATURE_NOT_PRESENT = -8,
    VK_ERROR_INCOMPATIBLE_DRIVER = -9,
    VK_ERROR_TOO_MANY_OBJECTS = -10,
    VK_ERROR_FORMAT_NOT_SUPPORTED = -11,
    VK_ERROR_FRAGMENTED_POOL = -12,
    VK_ERROR_SURFACE_LOST_KHR = -1000000000,
    VK_ERROR_NATIVE_WINDOW_IN_USE_KHR = -1000000001,
    VK_SUBOPTIMAL_KHR = 1000001003,
    VK_ERROR_OUT_OF_DATE_KHR = -1000001004,
    VK_ERROR_INCOMPATIBLE_DISPLAY_KHR = -1000003001,
    VK_ERROR_VALIDATION_FAILED_EXT = -1000011001,
    VK_ERROR_INVALID_SHADER_NV = -1000012000,
    VK_ERROR_OUT_OF_POOL_MEMORY_KHR = -1000069000,
    VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR = -1000072003,
    VK_ERROR_NOT_PERMITTED_EXT = -1000174001,
    VK_RESULT_MAX_ENUM = 0x7FFFFFFF
} VkResult;
typedef enum VkPhysicalDeviceType {
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4,
    VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM = 0x7FFFFFFF
} VkPhysicalDeviceType;
typedef enum VkSampleCountFlagBits {
    VK_SAMPLE_COUNT_1_BIT = 0x00000001,
    VK_SAMPLE_COUNT_2_BIT = 0x00000002,
    VK_SAMPLE_COUNT_4_BIT = 0x00000004,
    VK_SAMPLE_COUNT_8_BIT = 0x00000008,
    VK_SAMPLE_COUNT_16_BIT = 0x00000010,
    VK_SAMPLE_COUNT_32_BIT = 0x00000020,
    VK_SAMPLE_COUNT_64_BIT = 0x00000040,
    VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkSampleCountFlagBits;
typedef VkFlags VkSampleCountFlags;
typedef struct VkPhysicalDeviceLimits {
    uint32_t maxImageDimension1D;
    uint32_t maxImageDimension2D;
    uint32_t maxImageDimension3D;
    uint32_t maxImageDimensionCube;
    uint32_t maxImageArrayLayers;
    uint32_t maxTexelBufferElements;
    uint32_t maxUniformBufferRange;
    uint32_t maxStorageBufferRange;
    uint32_t maxPushConstantsSize;
    uint32_t maxMemoryAllocationCount;
    uint32_t maxSamplerAllocationCount;
    VkDeviceSize bufferImageGranularity;
    VkDeviceSize sparseAddressSpaceSize;
    uint32_t maxBoundDescriptorSets;
    uint32_t maxPerStageDescriptorSamplers;
    uint32_t maxPerStageDescriptorUniformBuffers;
    uint32_t maxPerStageDescriptorStorageBuffers;
    uint32_t maxPerStageDescriptorSampledImages;
    uint32_t maxPerStageDescriptorStorageImages;
    uint32_t maxPerStageDescriptorInputAttachments;
    uint32_t maxPerStageResources;
    uint32_t maxDescriptorSetSamplers;
    uint32_t maxDescriptorSetUniformBuffers;
    uint32_t maxDescriptorSetUniformBuffersDynamic;
    uint32_t maxDescriptorSetStorageBuffers;
    uint32_t maxDescriptorSetStorageBuffersDynamic;
    uint32_t maxDescriptorSetSampledImages;
    uint32_t maxDescriptorSetStorageImages;
    uint32_t maxDescriptorSetInputAttachments;
    uint32_t maxVertexInputAttributes;
    uint32_t maxVertexInputBindings;
    uint32_t maxVertexInputAttributeOffset;
    uint32_t maxVertexInputBindingStride;
    uint32_t maxVertexOutputComponents;
    uint32_t maxTessellationGenerationLevel;
    uint32_t maxTessellationPatchSize;
    uint32_t maxTessellationControlPerVertexInputComponents;
    uint32_t maxTessellationControlPerVertexOutputComponents;
    uint32_t maxTessellationControlPerPatchOutputComponents;
    uint32_t maxTessellationControlTotalOutputComponents;
    uint32_t maxTessellationEvaluationInputComponents;
    uint32_t maxTessellationEvaluationOutputComponents;
    uint32_t maxGeometryShaderInvocations;
    uint32_t maxGeometryInputComponents;
    uint32_t maxGeometryOutputComponents;
    uint32_t maxGeometryOutputVertices;
    uint32_t maxGeometryTotalOutputComponents;
    uint32_t maxFragmentInputComponents;
    uint32_t maxFragmentOutputAttachments;
    uint32_t maxFragmentDualSrcAttachments;
    uint32_t maxFragmentCombinedOutputResources;
    uint32_t maxComputeSharedMemorySize;
    uint32_t maxComputeWorkGroupCount[3];
    uint32_t maxComputeWorkGroupInvocations;
    uint32_t maxComputeWorkGroupSize[3];
    uint32_t subPixelPrecisionBits;
    uint32_t subTexelPrecisionBits;
    uint32_t mipmapPrecisionBits;
    uint32_t maxDrawIndexedIndexValue;
    uint32_t maxDrawIndirectCount;
    float maxSamplerLodBias;
    float maxSamplerAnisotropy;
    uint32_t maxViewports;
    uint32_t maxViewportDimensions[2];
    float viewportBoundsRange[2];
    uint32_t viewportSubPixelBits;
    size_t minMemoryMapAlignment;
    VkDeviceSize minTexelBufferOffsetAlignment;
    VkDeviceSize minUniformBufferOffsetAlignment;
    VkDeviceSize minStorageBufferOffsetAlignment;
    int32_t minTexelOffset;
    uint32_t maxTexelOffset;
    int32_t minTexelGatherOffset;
    uint32_t maxTexelGatherOffset;
    float minInterpolationOffset;
    float maxInterpolationOffset;
    uint32_t subPixelInterpolationOffsetBits;
    uint32_t maxFramebufferWidth;
    uint32_t maxFramebufferHeight;
    uint32_t maxFramebufferLayers;
    VkSampleCountFlags framebufferColorSampleCounts;
    VkSampleCountFlags framebufferDepthSampleCounts;
    VkSampleCountFlags framebufferStencilSampleCounts;
    VkSampleCountFlags framebufferNoAttachmentsSampleCounts;
    uint32_t maxColorAttachments;
    VkSampleCountFlags sampledImageColorSampleCounts;
    VkSampleCountFlags sampledImageIntegerSampleCounts;
    VkSampleCountFlags sampledImageDepthSampleCounts;
    VkSampleCountFlags sampledImageStencilSampleCounts;
    VkSampleCountFlags storageImageSampleCounts;
    uint32_t maxSampleMaskWords;
    VkBool32 timestampComputeAndGraphics;
    float timestampPeriod;
    uint32_t maxClipDistances;
    uint32_t maxCullDistances;
    uint32_t maxCombinedClipAndCullDistances;
    uint32_t discreteQueuePriorities;
    float pointSizeRange[2];
    float lineWidthRange[2];
    float pointSizeGranularity;
    float lineWidthGranularity;
    VkBool32 strictLines;
    VkBool32 standardSampleLocations;
    VkDeviceSize optimalBufferCopyOffsetAlignment;
    VkDeviceSize optimalBufferCopyRowPitchAlignment;
    VkDeviceSize nonCoherentAtomSize;
} VkPhysicalDeviceLimits;
typedef struct VkPhysicalDeviceSparseProperties {
    VkBool32 residencyStandard2DBlockShape;
    VkBool32 residencyStandard2DMultisampleBlockShape;
    VkBool32 residencyStandard3DBlockShape;
    VkBool32 residencyAlignedMipSize;
    VkBool32 residencyNonResidentStrict;
} VkPhysicalDeviceSparseProperties;
typedef struct VkPhysicalDeviceProperties {
    uint32_t apiVersion;
    uint32_t driverVersion;
    uint32_t vendorID;
    uint32_t deviceID;
    VkPhysicalDeviceType deviceType;
    char deviceName[256];
    uint8_t pipelineCacheUUID[16];
    VkPhysicalDeviceLimits limits;
    VkPhysicalDeviceSparseProperties sparseProperties;
} VkPhysicalDeviceProperties;
typedef struct VkMemoryType {
    VkMemoryPropertyFlags propertyFlags;
    uint32_t heapIndex;
} VkMemoryType;
typedef struct VkMemoryHeap {
    VkDeviceSize size;
    VkMemoryHeapFlags flags;
} VkMemoryHeap;
typedef enum VkStructureType {
    VK_STRUCTURE_TYPE_APPLICATION_INFO = 0,
} VkStructureType;
typedef struct VkMemoryAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDeviceSize allocationSize;
    uint32_t memoryTypeIndex;
} VkMemoryAllocateInfo;
typedef enum VkSystemAllocationScope {
    VK_SYSTEM_ALLOCATION_SCOPE_COMMAND = 0,
    VK_SYSTEM_ALLOCATION_SCOPE_OBJECT = 1,
    VK_SYSTEM_ALLOCATION_SCOPE_CACHE = 2,
    VK_SYSTEM_ALLOCATION_SCOPE_DEVICE = 3,
    VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE = 4,
    VK_SYSTEM_ALLOCATION_SCOPE_MAX_ENUM = 0x7FFFFFFF
} VkSystemAllocationScope;
typedef enum VkInternalAllocationType {
    VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE = 0,
    VK_INTERNAL_ALLOCATION_TYPE_MAX_ENUM = 0x7FFFFFFF
} VkInternalAllocationType;
typedef void* ( *PFN_vkAllocationFunction)(
    void* pUserData,
    size_t size,
    size_t alignment,
    VkSystemAllocationScope allocationScope);
typedef void* ( *PFN_vkReallocationFunction)(
    void* pUserData,
    void* pOriginal,
    size_t size,
    size_t alignment,
    VkSystemAllocationScope allocationScope);
typedef void ( *PFN_vkFreeFunction)(
    void* pUserData,
    void* pMemory);
typedef void ( *PFN_vkInternalAllocationNotification)(
    void* pUserData,
    size_t size,
    VkInternalAllocationType allocationType,
    VkSystemAllocationScope allocationScope);
typedef void ( *PFN_vkInternalFreeNotification)(
    void* pUserData,
    size_t size,
    VkInternalAllocationType allocationType,
    VkSystemAllocationScope allocationScope);
typedef struct VkAllocationCallbacks {
    void* pUserData;
    PFN_vkAllocationFunction pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
} VkAllocationCallbacks;
typedef VkFlags VkMemoryMapFlags;
typedef struct VkMemoryRequirements {
    VkDeviceSize size;
    VkDeviceSize alignment;
    uint32_t memoryTypeBits;
} VkMemoryRequirements;
typedef enum VkBufferCreateFlagBits {
    VK_BUFFER_CREATE_SPARSE_BINDING_BIT = 0x00000001,
    VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT = 0x00000002,
    VK_BUFFER_CREATE_SPARSE_ALIASED_BIT = 0x00000004,
    VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkBufferCreateFlagBits;
typedef VkFlags VkBufferCreateFlags;
typedef enum VkSharingMode {
    VK_SHARING_MODE_EXCLUSIVE = 0,
    VK_SHARING_MODE_CONCURRENT = 1,
    VK_SHARING_MODE_MAX_ENUM = 0x7FFFFFFF
} VkSharingMode;
typedef enum VkBufferUsageFlagBits {
    VK_BUFFER_USAGE_TRANSFER_SRC_BIT = 0x00000001,
    VK_BUFFER_USAGE_TRANSFER_DST_BIT = 0x00000002,
    VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT = 0x00000004,
    VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT = 0x00000008,
    VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT = 0x00000010,
    VK_BUFFER_USAGE_STORAGE_BUFFER_BIT = 0x00000020,
    VK_BUFFER_USAGE_INDEX_BUFFER_BIT = 0x00000040,
    VK_BUFFER_USAGE_VERTEX_BUFFER_BIT = 0x00000080,
    VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT = 0x00000100,
    VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkBufferUsageFlagBits;
typedef VkFlags VkBufferUsageFlags;
typedef struct VkBufferCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkBufferCreateFlags flags;
    VkDeviceSize size;
    VkBufferUsageFlags usage;
    VkSharingMode sharingMode;
    uint32_t queueFamilyIndexCount;
    const uint32_t* pQueueFamilyIndices;
} VkBufferCreateInfo;
typedef VkFlags VkImageCreateFlags;
typedef enum VkImageType {
    VK_IMAGE_TYPE_1D = 0,
    VK_IMAGE_TYPE_2D = 1,
    VK_IMAGE_TYPE_3D = 2,
    VK_IMAGE_TYPE_MAX_ENUM = 0x7FFFFFFF
} VkImageType;
typedef enum VkFormat {
    VK_FORMAT_UNDEFINED = 0,
    VK_FORMAT_R4G4_UNORM_PACK8 = 1,
    VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
    VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
    VK_FORMAT_R5G6B5_UNORM_PACK16 = 4,
    VK_FORMAT_B5G6R5_UNORM_PACK16 = 5,
    VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
    VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
    VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
    VK_FORMAT_R8_UNORM = 9,
    VK_FORMAT_R8_SNORM = 10,
    VK_FORMAT_R8_USCALED = 11,
    VK_FORMAT_R8_SSCALED = 12,
    VK_FORMAT_R8_UINT = 13,
    VK_FORMAT_R8_SINT = 14,
    VK_FORMAT_R8_SRGB = 15,
    VK_FORMAT_R8G8_UNORM = 16,
    VK_FORMAT_R8G8_SNORM = 17,
    VK_FORMAT_R8G8_USCALED = 18,
    VK_FORMAT_R8G8_SSCALED = 19,
    VK_FORMAT_R8G8_UINT = 20,
    VK_FORMAT_R8G8_SINT = 21,
    VK_FORMAT_R8G8_SRGB = 22,
    VK_FORMAT_R8G8B8_UNORM = 23,
    VK_FORMAT_R8G8B8_SNORM = 24,
    VK_FORMAT_R8G8B8_USCALED = 25,
    VK_FORMAT_R8G8B8_SSCALED = 26,
    VK_FORMAT_R8G8B8_UINT = 27,
    VK_FORMAT_R8G8B8_SINT = 28,
    VK_FORMAT_R8G8B8_SRGB = 29,
    VK_FORMAT_B8G8R8_UNORM = 30,
    VK_FORMAT_B8G8R8_SNORM = 31,
    VK_FORMAT_B8G8R8_USCALED = 32,
    VK_FORMAT_B8G8R8_SSCALED = 33,
    VK_FORMAT_B8G8R8_UINT = 34,
    VK_FORMAT_B8G8R8_SINT = 35,
    VK_FORMAT_B8G8R8_SRGB = 36,
    VK_FORMAT_R8G8B8A8_UNORM = 37,
    VK_FORMAT_R8G8B8A8_SNORM = 38,
    VK_FORMAT_R8G8B8A8_USCALED = 39,
    VK_FORMAT_R8G8B8A8_SSCALED = 40,
    VK_FORMAT_R8G8B8A8_UINT = 41,
    VK_FORMAT_R8G8B8A8_SINT = 42,
    VK_FORMAT_R8G8B8A8_SRGB = 43,
    VK_FORMAT_B8G8R8A8_UNORM = 44,
    VK_FORMAT_B8G8R8A8_SNORM = 45,
    VK_FORMAT_B8G8R8A8_USCALED = 46,
    VK_FORMAT_B8G8R8A8_SSCALED = 47,
    VK_FORMAT_B8G8R8A8_UINT = 48,
    VK_FORMAT_B8G8R8A8_SINT = 49,
    VK_FORMAT_B8G8R8A8_SRGB = 50,
    VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
    VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
    VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
    VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
    VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
    VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
    VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
    VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
    VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
    VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
    VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
    VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
    VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
    VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
    VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
    VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
    VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
    VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
    VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
    VK_FORMAT_R16_UNORM = 70,
    VK_FORMAT_R16_SNORM = 71,
    VK_FORMAT_R16_USCALED = 72,
    VK_FORMAT_R16_SSCALED = 73,
    VK_FORMAT_R16_UINT = 74,
    VK_FORMAT_R16_SINT = 75,
    VK_FORMAT_R16_SFLOAT = 76,
    VK_FORMAT_R16G16_UNORM = 77,
    VK_FORMAT_R16G16_SNORM = 78,
    VK_FORMAT_R16G16_USCALED = 79,
    VK_FORMAT_R16G16_SSCALED = 80,
    VK_FORMAT_R16G16_UINT = 81,
    VK_FORMAT_R16G16_SINT = 82,
    VK_FORMAT_R16G16_SFLOAT = 83,
    VK_FORMAT_R16G16B16_UNORM = 84,
    VK_FORMAT_R16G16B16_SNORM = 85,
    VK_FORMAT_R16G16B16_USCALED = 86,
    VK_FORMAT_R16G16B16_SSCALED = 87,
    VK_FORMAT_R16G16B16_UINT = 88,
    VK_FORMAT_R16G16B16_SINT = 89,
    VK_FORMAT_R16G16B16_SFLOAT = 90,
    VK_FORMAT_R16G16B16A16_UNORM = 91,
    VK_FORMAT_R16G16B16A16_SNORM = 92,
    VK_FORMAT_R16G16B16A16_USCALED = 93,
    VK_FORMAT_R16G16B16A16_SSCALED = 94,
    VK_FORMAT_R16G16B16A16_UINT = 95,
    VK_FORMAT_R16G16B16A16_SINT = 96,
    VK_FORMAT_R16G16B16A16_SFLOAT = 97,
    VK_FORMAT_R32_UINT = 98,
    VK_FORMAT_R32_SINT = 99,
    VK_FORMAT_R32_SFLOAT = 100,
    VK_FORMAT_R32G32_UINT = 101,
    VK_FORMAT_R32G32_SINT = 102,
    VK_FORMAT_R32G32_SFLOAT = 103,
    VK_FORMAT_R32G32B32_UINT = 104,
    VK_FORMAT_R32G32B32_SINT = 105,
    VK_FORMAT_R32G32B32_SFLOAT = 106,
    VK_FORMAT_R32G32B32A32_UINT = 107,
    VK_FORMAT_R32G32B32A32_SINT = 108,
    VK_FORMAT_R32G32B32A32_SFLOAT = 109,
    VK_FORMAT_R64_UINT = 110,
    VK_FORMAT_R64_SINT = 111,
    VK_FORMAT_R64_SFLOAT = 112,
    VK_FORMAT_R64G64_UINT = 113,
    VK_FORMAT_R64G64_SINT = 114,
    VK_FORMAT_R64G64_SFLOAT = 115,
    VK_FORMAT_R64G64B64_UINT = 116,
    VK_FORMAT_R64G64B64_SINT = 117,
    VK_FORMAT_R64G64B64_SFLOAT = 118,
    VK_FORMAT_R64G64B64A64_UINT = 119,
    VK_FORMAT_R64G64B64A64_SINT = 120,
    VK_FORMAT_R64G64B64A64_SFLOAT = 121,
    VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
    VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
    VK_FORMAT_D16_UNORM = 124,
    VK_FORMAT_X8_D24_UNORM_PACK32 = 125,
    VK_FORMAT_D32_SFLOAT = 126,
    VK_FORMAT_S8_UINT = 127,
    VK_FORMAT_D16_UNORM_S8_UINT = 128,
    VK_FORMAT_D24_UNORM_S8_UINT = 129,
    VK_FORMAT_D32_SFLOAT_S8_UINT = 130,
    VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
    VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
    VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
    VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
    VK_FORMAT_BC2_UNORM_BLOCK = 135,
    VK_FORMAT_BC2_SRGB_BLOCK = 136,
    VK_FORMAT_BC3_UNORM_BLOCK = 137,
    VK_FORMAT_BC3_SRGB_BLOCK = 138,
    VK_FORMAT_BC4_UNORM_BLOCK = 139,
    VK_FORMAT_BC4_SNORM_BLOCK = 140,
    VK_FORMAT_BC5_UNORM_BLOCK = 141,
    VK_FORMAT_BC5_SNORM_BLOCK = 142,
    VK_FORMAT_BC6H_UFLOAT_BLOCK = 143,
    VK_FORMAT_BC6H_SFLOAT_BLOCK = 144,
    VK_FORMAT_BC7_UNORM_BLOCK = 145,
    VK_FORMAT_BC7_SRGB_BLOCK = 146,
    VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
    VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
    VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
    VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
    VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
    VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
    VK_FORMAT_EAC_R11_UNORM_BLOCK = 153,
    VK_FORMAT_EAC_R11_SNORM_BLOCK = 154,
    VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
    VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
    VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
    VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
    VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
    VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
    VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
    VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
    VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
    VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
    VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
    VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
    VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
    VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
    VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
    VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
    VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
    VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
    VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
    VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
    VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
    VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
    VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
    VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
    VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
    VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
    VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
    VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
    VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
    VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184,
    VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
    VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
    VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
    VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
    VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
    VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
    VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
    VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007,
    VK_FORMAT_G8B8G8R8_422_UNORM_KHR = 1000156000,
    VK_FORMAT_B8G8R8G8_422_UNORM_KHR = 1000156001,
    VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR = 1000156002,
    VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR = 1000156003,
    VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR = 1000156004,
    VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR = 1000156005,
    VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR = 1000156006,
    VK_FORMAT_R10X6_UNORM_PACK16_KHR = 1000156007,
    VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR = 1000156008,
    VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR = 1000156009,
    VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR = 1000156010,
    VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR = 1000156011,
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR = 1000156012,
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR = 1000156013,
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR = 1000156014,
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR = 1000156015,
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR = 1000156016,
    VK_FORMAT_R12X4_UNORM_PACK16_KHR = 1000156017,
    VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR = 1000156018,
    VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR = 1000156019,
    VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR = 1000156020,
    VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR = 1000156021,
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR = 1000156022,
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR = 1000156023,
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR = 1000156024,
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR = 1000156025,
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR = 1000156026,
    VK_FORMAT_G16B16G16R16_422_UNORM_KHR = 1000156027,
    VK_FORMAT_B16G16R16G16_422_UNORM_KHR = 1000156028,
    VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR = 1000156029,
    VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR = 1000156030,
    VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR = 1000156031,
    VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR = 1000156032,
    VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR = 1000156033,
    VK_FORMAT_MAX_ENUM = 0x7FFFFFFF
} VkFormat;
typedef struct VkExtent3D {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
} VkExtent3D;
typedef enum VkImageTiling {
    VK_IMAGE_TILING_OPTIMAL = 0,
    VK_IMAGE_TILING_LINEAR = 1,
    VK_IMAGE_TILING_MAX_ENUM = 0x7FFFFFFF
} VkImageTiling;
typedef VkFlags VkImageUsageFlags;
typedef enum VkImageLayout {
    VK_IMAGE_LAYOUT_UNDEFINED = 0,
    VK_IMAGE_LAYOUT_GENERAL = 1,
    VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL = 2,
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL = 3,
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL = 4,
    VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL = 5,
    VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL = 6,
    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL = 7,
    VK_IMAGE_LAYOUT_PREINITIALIZED = 8,
    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR = 1000001002,
    VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR = 1000111000,
    VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR = 1000117000,
    VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR = 1000117001,
    VK_IMAGE_LAYOUT_MAX_ENUM = 0x7FFFFFFF
} VkImageLayout;
typedef struct VkImageCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageCreateFlags flags;
    VkImageType imageType;
    VkFormat format;
    VkExtent3D extent;
    uint32_t mipLevels;
    uint32_t arrayLayers;
    VkSampleCountFlagBits samples;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkSharingMode sharingMode;
    uint32_t queueFamilyIndexCount;
    const uint32_t* pQueueFamilyIndices;
    VkImageLayout initialLayout;
} VkImageCreateInfo;
typedef struct VkImageMemoryRequirementsInfo2KHR {
        VkStructureType sType;
            const void* pNext;
                VkImage image;
} VkImageMemoryRequirementsInfo2KHR;
typedef struct VkMemoryRequirements2KHR {
        VkStructureType sType;
            void* pNext;
                VkMemoryRequirements memoryRequirements;
} VkMemoryRequirements2KHR;
typedef struct VkBufferMemoryRequirementsInfo2KHR {
        VkStructureType sType;
            const void* pNext;
                VkBuffer buffer;
} VkBufferMemoryRequirementsInfo2KHR;
typedef struct VkMemoryDedicatedAllocateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    VkBuffer buffer;
} VkMemoryDedicatedAllocateInfoKHR;
typedef struct VkMemoryDedicatedRequirementsKHR {
    VkStructureType sType;
    void* pNext;
    VkBool32 prefersDedicatedAllocation;
    VkBool32 requiresDedicatedAllocation;
} VkMemoryDedicatedRequirementsKHR;

typedef struct VkPhysicalDeviceMemoryProperties {
    uint32_t memoryTypeCount;
    VkMemoryType memoryTypes[32U];
    uint32_t memoryHeapCount;
    VkMemoryHeap memoryHeaps[16U];
} VkPhysicalDeviceMemoryProperties;
typedef void ( *PFN_vkGetPhysicalDeviceMemoryProperties)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
typedef VkResult ( *PFN_vkAllocateMemory)(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
typedef void ( *PFN_vkFreeMemory)(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
typedef VkResult ( *PFN_vkMapMemory)(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
typedef void ( *PFN_vkUnmapMemory)(VkDevice device, VkDeviceMemory memory);
typedef VkResult ( *PFN_vkBindBufferMemory)(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef VkResult ( *PFN_vkBindImageMemory)(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef void ( *PFN_vkGetBufferMemoryRequirements)(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
typedef void ( *PFN_vkGetImageMemoryRequirements)(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
typedef VkResult ( *PFN_vkCreateBuffer)(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
typedef void ( *PFN_vkDestroyBuffer)(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
typedef VkResult ( *PFN_vkCreateImage)(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
typedef void ( *PFN_vkDestroyImage)(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
typedef void ( *PFN_vkGetPhysicalDeviceProperties)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
typedef void ( *PFN_vkGetImageMemoryRequirements2KHR)(VkDevice device, const VkImageMemoryRequirementsInfo2KHR* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);
typedef void ( *PFN_vkGetBufferMemoryRequirements2KHR)(VkDevice device, const VkBufferMemoryRequirementsInfo2KHR* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);

typedef struct VkMappedMemoryRange {
    VkStructureType sType;
    const void* pNext;
    VkDeviceMemory memory;
    VkDeviceSize offset;
    VkDeviceSize size; 
} VkMappedMemoryRange;

typedef struct VkBufferCopy { 
    VkDeviceSize srcOffset;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
} VkBufferCopy;

typedef struct VkBindBufferMemoryInfo {
    VkStructureType sType;
    const void* pNext;
    VkBuffer buffer;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
} VkBindBufferMemoryInfo;
typedef struct VkBindImageMemoryInfo {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
} VkBindImageMemoryInfo;

typedef struct VkPhysicalDeviceMemoryProperties2 {
    VkStructureType sType;
    void* pNext;
    VkPhysicalDeviceMemoryProperties memoryProperties;
} VkPhysicalDeviceMemoryProperties2;

typedef struct VkImageSparseMemoryRequirementsInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
} VkImageSparseMemoryRequirementsInfo2;
typedef struct VkMemoryRequirements2 {
    VkStructureType sType;
    void* pNext; 
    VkMemoryRequirements memoryRequirements;
} VkMemoryRequirements2;

typedef enum VkImageAspectFlagBits {
    VK_IMAGE_ASPECT_COLOR_BIT = 0x00000001,
    VK_IMAGE_ASPECT_DEPTH_BIT = 0x00000002,
    VK_IMAGE_ASPECT_STENCIL_BIT = 0x00000004,
    VK_IMAGE_ASPECT_METADATA_BIT = 0x00000008,
    VK_IMAGE_ASPECT_PLANE_0_BIT = 0x00000010,
    VK_IMAGE_ASPECT_PLANE_1_BIT = 0x00000020,
    VK_IMAGE_ASPECT_PLANE_2_BIT = 0x00000040,
    VK_IMAGE_ASPECT_NONE = 0,
    VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT = 0x00000080,
    VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT = 0x00000100,
    VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT = 0x00000200,
    VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT = 0x00000400,
    VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkImageAspectFlagBits;


typedef struct VkDeviceBufferMemoryRequirements {
    VkStructureType sType;
    const void* pNext;
    const VkBufferCreateInfo* pCreateInfo;
} VkDeviceBufferMemoryRequirements;
typedef struct VkDeviceImageMemoryRequirements {
    VkStructureType sType;
    const void* pNext;
    const VkImageCreateInfo* pCreateInfo;
    VkImageAspectFlagBits planeAspect;
} VkDeviceImageMemoryRequirements;



typedef VkResult ( *PFN_vkFlushMappedMemoryRanges)(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef VkResult ( *PFN_vkInvalidateMappedMemoryRanges)(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef void ( *PFN_vkCmdCopyBuffer)(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);

typedef VkResult ( *PFN_vkBindBufferMemory2KHR)(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef VkResult ( *PFN_vkBindImageMemory2KHR)(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void ( *PFN_vkGetPhysicalDeviceMemoryProperties2KHR)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);

typedef void ( *PFN_vkGetDeviceBufferMemoryRequirements)(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void ( *PFN_vkGetDeviceImageMemoryRequirements)(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

typedef VkFlags VkExternalMemoryHandleTypeFlags;
typedef enum VkExternalMemoryFeatureFlagBits {
    VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT = 0x00000001,
    VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT = 0x00000002,
    VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT = 0x00000004,
    VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkExternalMemoryFeatureFlagBits;


typedef VkExternalMemoryHandleTypeFlags VkExternalMemoryHandleTypeFlagsKHR;


typedef enum VmaAllocatorCreateFlagBits
{
    VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT = 0x00000001,
    VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT = 0x00000002,
    VMA_ALLOCATOR_CREATE_KHR_BIND_MEMORY2_BIT = 0x00000004,
    VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT = 0x00000008,
    VMA_ALLOCATOR_CREATE_AMD_DEVICE_COHERENT_MEMORY_BIT = 0x00000010,
    VMA_ALLOCATOR_CREATE_BUFFER_DEVICE_ADDRESS_BIT = 0x00000020,
    VMA_ALLOCATOR_CREATE_EXT_MEMORY_PRIORITY_BIT = 0x00000040,
    VMA_ALLOCATOR_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VmaAllocatorCreateFlagBits;
typedef VkFlags VmaAllocatorCreateFlags;
typedef enum VmaMemoryUsage
{
    VMA_MEMORY_USAGE_UNKNOWN = 0,
    VMA_MEMORY_USAGE_GPU_ONLY = 1,
    VMA_MEMORY_USAGE_CPU_ONLY = 2,
    VMA_MEMORY_USAGE_CPU_TO_GPU = 3,
    VMA_MEMORY_USAGE_GPU_TO_CPU = 4,
    VMA_MEMORY_USAGE_CPU_COPY = 5,
    VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED = 6,
    VMA_MEMORY_USAGE_AUTO = 7,
    VMA_MEMORY_USAGE_AUTO_PREFER_DEVICE = 8,
    VMA_MEMORY_USAGE_AUTO_PREFER_HOST = 9,
    VMA_MEMORY_USAGE_MAX_ENUM = 0x7FFFFFFF
} VmaMemoryUsage;
typedef enum VmaAllocationCreateFlagBits
{
    VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT = 0x00000001,
    VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT = 0x00000002,
    VMA_ALLOCATION_CREATE_MAPPED_BIT = 0x00000004,
    VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT = 0x00000020,
    VMA_ALLOCATION_CREATE_UPPER_ADDRESS_BIT = 0x00000040,
    VMA_ALLOCATION_CREATE_DONT_BIND_BIT = 0x00000080,
    VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT = 0x00000100,
    VMA_ALLOCATION_CREATE_CAN_ALIAS_BIT = 0x00000200,
    VMA_ALLOCATION_CREATE_HOST_ACCESS_SEQUENTIAL_WRITE_BIT = 0x00000400,
    VMA_ALLOCATION_CREATE_HOST_ACCESS_RANDOM_BIT = 0x00000800,
    VMA_ALLOCATION_CREATE_HOST_ACCESS_ALLOW_TRANSFER_INSTEAD_BIT = 0x00001000,
    VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT = 0x00010000,
    VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT = 0x00020000,
    VMA_ALLOCATION_CREATE_STRATEGY_MIN_OFFSET_BIT = 0x00040000,
    VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT = VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT,
    VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT = VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT,
    VMA_ALLOCATION_CREATE_STRATEGY_MASK =
        VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT |
        VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT |
        VMA_ALLOCATION_CREATE_STRATEGY_MIN_OFFSET_BIT,
    VMA_ALLOCATION_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VmaAllocationCreateFlagBits;
typedef VkFlags VmaAllocationCreateFlags;
typedef enum VmaPoolCreateFlagBits
{
    VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT = 0x00000002,
    VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT = 0x00000004,
    VMA_POOL_CREATE_ALGORITHM_MASK =
        VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT,
    VMA_POOL_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VmaPoolCreateFlagBits;
typedef VkFlags VmaPoolCreateFlags;
typedef enum VmaDefragmentationFlagBits
{
    VMA_DEFRAGMENTATION_FLAG_ALGORITHM_FAST_BIT = 0x1,
    VMA_DEFRAGMENTATION_FLAG_ALGORITHM_BALANCED_BIT = 0x2,
    VMA_DEFRAGMENTATION_FLAG_ALGORITHM_FULL_BIT = 0x4,
    VMA_DEFRAGMENTATION_FLAG_ALGORITHM_EXTENSIVE_BIT = 0x8,
    VMA_DEFRAGMENTATION_FLAG_ALGORITHM_MASK =
        VMA_DEFRAGMENTATION_FLAG_ALGORITHM_FAST_BIT |
        VMA_DEFRAGMENTATION_FLAG_ALGORITHM_BALANCED_BIT |
        VMA_DEFRAGMENTATION_FLAG_ALGORITHM_FULL_BIT |
        VMA_DEFRAGMENTATION_FLAG_ALGORITHM_EXTENSIVE_BIT,
    VMA_DEFRAGMENTATION_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VmaDefragmentationFlagBits;
typedef VkFlags VmaDefragmentationFlags;
typedef enum VmaDefragmentationMoveOperation
{
    VMA_DEFRAGMENTATION_MOVE_OPERATION_COPY = 0,
    VMA_DEFRAGMENTATION_MOVE_OPERATION_IGNORE = 1,
    VMA_DEFRAGMENTATION_MOVE_OPERATION_DESTROY = 2,
} VmaDefragmentationMoveOperation;
typedef enum VmaVirtualBlockCreateFlagBits
{
    VMA_VIRTUAL_BLOCK_CREATE_LINEAR_ALGORITHM_BIT = 0x00000001,
    VMA_VIRTUAL_BLOCK_CREATE_ALGORITHM_MASK =
        VMA_VIRTUAL_BLOCK_CREATE_LINEAR_ALGORITHM_BIT,
    VMA_VIRTUAL_BLOCK_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VmaVirtualBlockCreateFlagBits;
typedef VkFlags VmaVirtualBlockCreateFlags;
typedef enum VmaVirtualAllocationCreateFlagBits
{
    VMA_VIRTUAL_ALLOCATION_CREATE_UPPER_ADDRESS_BIT = VMA_ALLOCATION_CREATE_UPPER_ADDRESS_BIT,
    VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT = VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT,
    VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT = VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT,
    VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MIN_OFFSET_BIT = VMA_ALLOCATION_CREATE_STRATEGY_MIN_OFFSET_BIT,
    VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MASK = VMA_ALLOCATION_CREATE_STRATEGY_MASK,
    VMA_VIRTUAL_ALLOCATION_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VmaVirtualAllocationCreateFlagBits;
typedef VkFlags VmaVirtualAllocationCreateFlags;
typedef struct VmaAllocator_T* VmaAllocator;
typedef struct VmaPool_T* VmaPool;
typedef struct VmaAllocation_T* VmaAllocation;
typedef struct VmaDefragmentationContext_T* VmaDefragmentationContext;
typedef struct VmaVirtualAllocation_T *VmaVirtualAllocation;;
typedef struct VmaVirtualBlock_T* VmaVirtualBlock;
typedef void (* PFN_vmaAllocateDeviceMemoryFunction)(
    VmaAllocator  allocator,
    uint32_t memoryType,
    VkDeviceMemory  memory,
    VkDeviceSize size,
    void*  pUserData);
typedef void (* PFN_vmaFreeDeviceMemoryFunction)(
    VmaAllocator  allocator,
    uint32_t memoryType,
    VkDeviceMemory  memory,
    VkDeviceSize size,
    void*  pUserData);
typedef struct VmaDeviceMemoryCallbacks
{
    PFN_vmaAllocateDeviceMemoryFunction  pfnAllocate;
    PFN_vmaFreeDeviceMemoryFunction  pfnFree;
    void*  pUserData;
} VmaDeviceMemoryCallbacks;
typedef struct VmaVulkanFunctions
{
    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
    PFN_vkFreeMemory  vkFreeMemory;
    PFN_vkMapMemory  vkMapMemory;
    PFN_vkUnmapMemory  vkUnmapMemory;
    PFN_vkFlushMappedMemoryRanges  vkFlushMappedMemoryRanges;
    PFN_vkInvalidateMappedMemoryRanges  vkInvalidateMappedMemoryRanges;
    PFN_vkBindBufferMemory  vkBindBufferMemory;
    PFN_vkBindImageMemory  vkBindImageMemory;
    PFN_vkGetBufferMemoryRequirements  vkGetBufferMemoryRequirements;
    PFN_vkGetImageMemoryRequirements  vkGetImageMemoryRequirements;
    PFN_vkCreateBuffer  vkCreateBuffer;
    PFN_vkDestroyBuffer  vkDestroyBuffer;
    PFN_vkCreateImage  vkCreateImage;
    PFN_vkDestroyImage  vkDestroyImage;
    PFN_vkCmdCopyBuffer  vkCmdCopyBuffer;
    PFN_vkGetBufferMemoryRequirements2KHR  vkGetBufferMemoryRequirements2KHR;
    PFN_vkGetImageMemoryRequirements2KHR  vkGetImageMemoryRequirements2KHR;
    PFN_vkBindBufferMemory2KHR  vkBindBufferMemory2KHR;
    PFN_vkBindImageMemory2KHR  vkBindImageMemory2KHR;
    PFN_vkGetPhysicalDeviceMemoryProperties2KHR  vkGetPhysicalDeviceMemoryProperties2KHR;
    PFN_vkGetDeviceBufferMemoryRequirements  vkGetDeviceBufferMemoryRequirements;
    PFN_vkGetDeviceImageMemoryRequirements  vkGetDeviceImageMemoryRequirements;
    ...;
} VmaVulkanFunctions;
typedef struct VmaAllocatorCreateInfo
{
    VmaAllocatorCreateFlags flags;
    VkPhysicalDevice  physicalDevice;
    VkDevice  device;
    VkDeviceSize preferredLargeHeapBlockSize;
    const VkAllocationCallbacks*  pAllocationCallbacks;
    const VmaDeviceMemoryCallbacks*  pDeviceMemoryCallbacks;
    const VkDeviceSize*  pHeapSizeLimit;
    const VmaVulkanFunctions*  pVulkanFunctions;
    VkInstance  instance;
    uint32_t vulkanApiVersion;
    const VkExternalMemoryHandleTypeFlagsKHR*  pTypeExternalMemoryHandleTypes;
} VmaAllocatorCreateInfo;
typedef struct VmaAllocatorInfo
{
    VkInstance  instance;
    VkPhysicalDevice  physicalDevice;
    VkDevice  device;
} VmaAllocatorInfo;
typedef struct VmaStatistics
{
    uint32_t blockCount;
    uint32_t allocationCount;
    VkDeviceSize blockBytes;
    VkDeviceSize allocationBytes;
} VmaStatistics;
typedef struct VmaDetailedStatistics
{
    VmaStatistics statistics;
    uint32_t unusedRangeCount;
    VkDeviceSize allocationSizeMin;
    VkDeviceSize allocationSizeMax;
    VkDeviceSize unusedRangeSizeMin;
    VkDeviceSize unusedRangeSizeMax;
} VmaDetailedStatistics;
typedef struct VmaTotalStatistics
{
    VmaDetailedStatistics memoryType[32U];
    VmaDetailedStatistics memoryHeap[16U];
    VmaDetailedStatistics total;
} VmaTotalStatistics;
typedef struct VmaBudget
{
    VmaStatistics statistics;
    VkDeviceSize usage;
    VkDeviceSize budget;
} VmaBudget;
typedef struct VmaAllocationCreateInfo
{
    VmaAllocationCreateFlags flags;
    VmaMemoryUsage usage;
    VkMemoryPropertyFlags requiredFlags;
    VkMemoryPropertyFlags preferredFlags;
    uint32_t memoryTypeBits;
    VmaPool  pool;
    void*  pUserData;
    float priority;
} VmaAllocationCreateInfo;
typedef struct VmaPoolCreateInfo
{
    uint32_t memoryTypeIndex;
    VmaPoolCreateFlags flags;
    VkDeviceSize blockSize;
    size_t minBlockCount;
    size_t maxBlockCount;
    float priority;
    VkDeviceSize minAllocationAlignment;
    void*  pMemoryAllocateNext;
} VmaPoolCreateInfo;
typedef struct VmaAllocationInfo
{
    uint32_t memoryType;
    VkDeviceMemory  deviceMemory;
    VkDeviceSize offset;
    VkDeviceSize size;
    void*  pMappedData;
    void*  pUserData;
    const char*  pName;
} VmaAllocationInfo;
typedef struct VmaAllocationInfo2
{
    VmaAllocationInfo allocationInfo;
    VkDeviceSize blockSize;
    VkBool32 dedicatedMemory;
} VmaAllocationInfo2;
typedef VkBool32 (* PFN_vmaCheckDefragmentationBreakFunction)(void*  pUserData);
typedef struct VmaDefragmentationInfo
{
    VmaDefragmentationFlags flags;
    VmaPool  pool;
    VkDeviceSize maxBytesPerPass;
    uint32_t maxAllocationsPerPass;
    PFN_vmaCheckDefragmentationBreakFunction  pfnBreakCallback;
    void*  pBreakCallbackUserData;
} VmaDefragmentationInfo;
typedef struct VmaDefragmentationMove
{
    VmaDefragmentationMoveOperation operation;
    VmaAllocation  srcAllocation;
    VmaAllocation  dstTmpAllocation;
} VmaDefragmentationMove;
typedef struct VmaDefragmentationPassMoveInfo
{
    uint32_t moveCount;
    VmaDefragmentationMove*  pMoves;
} VmaDefragmentationPassMoveInfo;
typedef struct VmaDefragmentationStats
{
    VkDeviceSize bytesMoved;
    VkDeviceSize bytesFreed;
    uint32_t allocationsMoved;
    uint32_t deviceMemoryBlocksFreed;
} VmaDefragmentationStats;
typedef struct VmaVirtualBlockCreateInfo
{
    VkDeviceSize size;
    VmaVirtualBlockCreateFlags flags;
    const VkAllocationCallbacks*  pAllocationCallbacks;
} VmaVirtualBlockCreateInfo;
typedef struct VmaVirtualAllocationCreateInfo
{
    VkDeviceSize size;
    VkDeviceSize alignment;
    VmaVirtualAllocationCreateFlags flags;
    void*  pUserData;
} VmaVirtualAllocationCreateInfo;
typedef struct VmaVirtualAllocationInfo
{
    VkDeviceSize offset;
    VkDeviceSize size;
    void*  pUserData;
} VmaVirtualAllocationInfo;
             VkResult vmaCreateAllocator(
    const VmaAllocatorCreateInfo*  pCreateInfo,
    VmaAllocator *  pAllocator);
             void vmaDestroyAllocator(
    VmaAllocator  allocator);
             void vmaGetAllocatorInfo(
    VmaAllocator  allocator,
    VmaAllocatorInfo*  pAllocatorInfo);
             void vmaGetPhysicalDeviceProperties(
    VmaAllocator  allocator,
    const VkPhysicalDeviceProperties* *  ppPhysicalDeviceProperties);
             void vmaGetMemoryProperties(
    VmaAllocator  allocator,
    const VkPhysicalDeviceMemoryProperties* *  ppPhysicalDeviceMemoryProperties);
             void vmaGetMemoryTypeProperties(
    VmaAllocator  allocator,
    uint32_t memoryTypeIndex,
    VkMemoryPropertyFlags*  pFlags);
             void vmaSetCurrentFrameIndex(
    VmaAllocator  allocator,
    uint32_t frameIndex);
             void vmaCalculateStatistics(
    VmaAllocator  allocator,
    VmaTotalStatistics*  pStats);
             void vmaGetHeapBudgets(
    VmaAllocator  allocator,
    VmaBudget*  pBudgets);
             VkResult vmaFindMemoryTypeIndex(
    VmaAllocator  allocator,
    uint32_t memoryTypeBits,
    const VmaAllocationCreateInfo*  pAllocationCreateInfo,
    uint32_t*  pMemoryTypeIndex);
             VkResult vmaFindMemoryTypeIndexForBufferInfo(
    VmaAllocator  allocator,
    const VkBufferCreateInfo*  pBufferCreateInfo,
    const VmaAllocationCreateInfo*  pAllocationCreateInfo,
    uint32_t*  pMemoryTypeIndex);
             VkResult vmaFindMemoryTypeIndexForImageInfo(
    VmaAllocator  allocator,
    const VkImageCreateInfo*  pImageCreateInfo,
    const VmaAllocationCreateInfo*  pAllocationCreateInfo,
    uint32_t*  pMemoryTypeIndex);
             VkResult vmaCreatePool(
    VmaAllocator  allocator,
    const VmaPoolCreateInfo*  pCreateInfo,
    VmaPool *  pPool);
             void vmaDestroyPool(
    VmaAllocator  allocator,
    VmaPool  pool);
             void vmaGetPoolStatistics(
    VmaAllocator  allocator,
    VmaPool  pool,
    VmaStatistics*  pPoolStats);
             void vmaCalculatePoolStatistics(
    VmaAllocator  allocator,
    VmaPool  pool,
    VmaDetailedStatistics*  pPoolStats);
             VkResult vmaCheckPoolCorruption(
    VmaAllocator  allocator,
    VmaPool  pool);
             void vmaGetPoolName(
    VmaAllocator  allocator,
    VmaPool  pool,
    const char* *  ppName);
             void vmaSetPoolName(
    VmaAllocator  allocator,
    VmaPool  pool,
    const char*  pName);
             VkResult vmaAllocateMemory(
    VmaAllocator  allocator,
    const VkMemoryRequirements*  pVkMemoryRequirements,
    const VmaAllocationCreateInfo*  pCreateInfo,
    VmaAllocation *  pAllocation,
    VmaAllocationInfo*  pAllocationInfo);
             VkResult vmaAllocateMemoryPages(
    VmaAllocator  allocator,
    const VkMemoryRequirements*  pVkMemoryRequirements,
    const VmaAllocationCreateInfo*  pCreateInfo,
    size_t allocationCount,
    VmaAllocation *  pAllocations,
    VmaAllocationInfo*  pAllocationInfo);
             VkResult vmaAllocateMemoryForBuffer(
    VmaAllocator  allocator,
    VkBuffer  buffer,
    const VmaAllocationCreateInfo*  pCreateInfo,
    VmaAllocation *  pAllocation,
    VmaAllocationInfo*  pAllocationInfo);
             VkResult vmaAllocateMemoryForImage(
    VmaAllocator  allocator,
    VkImage  image,
    const VmaAllocationCreateInfo*  pCreateInfo,
    VmaAllocation *  pAllocation,
    VmaAllocationInfo*  pAllocationInfo);
             void vmaFreeMemory(
    VmaAllocator  allocator,
    const VmaAllocation  allocation);
             void vmaFreeMemoryPages(
    VmaAllocator  allocator,
    size_t allocationCount,
    const VmaAllocation *  pAllocations);
             void vmaGetAllocationInfo(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VmaAllocationInfo*  pAllocationInfo);
             void vmaGetAllocationInfo2(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VmaAllocationInfo2*  pAllocationInfo);
             void vmaSetAllocationUserData(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    void*  pUserData);
             void vmaSetAllocationName(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    const char*  pName);
             void vmaGetAllocationMemoryProperties(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkMemoryPropertyFlags*  pFlags);
             VkResult vmaMapMemory(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    void* *  ppData);
             void vmaUnmapMemory(
    VmaAllocator  allocator,
    VmaAllocation  allocation);
             VkResult vmaFlushAllocation(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkDeviceSize offset,
    VkDeviceSize size);
             VkResult vmaInvalidateAllocation(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkDeviceSize offset,
    VkDeviceSize size);
             VkResult vmaFlushAllocations(
    VmaAllocator  allocator,
    uint32_t allocationCount,
    const VmaAllocation *  allocations,
    const VkDeviceSize*  offsets,
    const VkDeviceSize*  sizes);
             VkResult vmaInvalidateAllocations(
    VmaAllocator  allocator,
    uint32_t allocationCount,
    const VmaAllocation *  allocations,
    const VkDeviceSize*  offsets,
    const VkDeviceSize*  sizes);
             VkResult vmaCheckCorruption(
    VmaAllocator  allocator,
    uint32_t memoryTypeBits);
             VkResult vmaBeginDefragmentation(
    VmaAllocator  allocator,
    const VmaDefragmentationInfo*  pInfo,
    VmaDefragmentationContext *  pContext);
             void vmaEndDefragmentation(
    VmaAllocator  allocator,
    VmaDefragmentationContext  context,
    VmaDefragmentationStats*  pStats);
             VkResult vmaBeginDefragmentationPass(
    VmaAllocator  allocator,
    VmaDefragmentationContext  context,
    VmaDefragmentationPassMoveInfo*  pPassInfo);
             VkResult vmaEndDefragmentationPass(
    VmaAllocator  allocator,
    VmaDefragmentationContext  context,
    VmaDefragmentationPassMoveInfo*  pPassInfo);
             VkResult vmaBindBufferMemory(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkBuffer  buffer);
             VkResult vmaBindBufferMemory2(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkDeviceSize allocationLocalOffset,
    VkBuffer  buffer,
    const void*  pNext);
             VkResult vmaBindImageMemory(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkImage  image);
             VkResult vmaBindImageMemory2(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkDeviceSize allocationLocalOffset,
    VkImage  image,
    const void*  pNext);
             VkResult vmaCreateBuffer(
    VmaAllocator  allocator,
    const VkBufferCreateInfo*  pBufferCreateInfo,
    const VmaAllocationCreateInfo*  pAllocationCreateInfo,
    VkBuffer *  pBuffer,
    VmaAllocation *  pAllocation,
    VmaAllocationInfo*  pAllocationInfo);
             VkResult vmaCreateBufferWithAlignment(
    VmaAllocator  allocator,
    const VkBufferCreateInfo*  pBufferCreateInfo,
    const VmaAllocationCreateInfo*  pAllocationCreateInfo,
    VkDeviceSize minAlignment,
    VkBuffer *  pBuffer,
    VmaAllocation *  pAllocation,
    VmaAllocationInfo*  pAllocationInfo);
             VkResult vmaCreateAliasingBuffer(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    const VkBufferCreateInfo*  pBufferCreateInfo,
    VkBuffer *  pBuffer);
             VkResult vmaCreateAliasingBuffer2(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkDeviceSize allocationLocalOffset,
    const VkBufferCreateInfo*  pBufferCreateInfo,
    VkBuffer *  pBuffer);
             void vmaDestroyBuffer(
    VmaAllocator  allocator,
    VkBuffer  buffer,
    VmaAllocation  allocation);
             VkResult vmaCreateImage(
    VmaAllocator  allocator,
    const VkImageCreateInfo*  pImageCreateInfo,
    const VmaAllocationCreateInfo*  pAllocationCreateInfo,
    VkImage *  pImage,
    VmaAllocation *  pAllocation,
    VmaAllocationInfo*  pAllocationInfo);
             VkResult vmaCreateAliasingImage(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    const VkImageCreateInfo*  pImageCreateInfo,
    VkImage *  pImage);
             VkResult vmaCreateAliasingImage2(
    VmaAllocator  allocator,
    VmaAllocation  allocation,
    VkDeviceSize allocationLocalOffset,
    const VkImageCreateInfo*  pImageCreateInfo,
    VkImage *  pImage);
             void vmaDestroyImage(
    VmaAllocator  allocator,
    VkImage  image,
    VmaAllocation  allocation);
             VkResult vmaCreateVirtualBlock(
    const VmaVirtualBlockCreateInfo*  pCreateInfo,
    VmaVirtualBlock *  pVirtualBlock);
             void vmaDestroyVirtualBlock(
    VmaVirtualBlock  virtualBlock);
             VkBool32 vmaIsVirtualBlockEmpty(
    VmaVirtualBlock  virtualBlock);
             void vmaGetVirtualAllocationInfo(
    VmaVirtualBlock  virtualBlock,
    VmaVirtualAllocation  allocation, VmaVirtualAllocationInfo*  pVirtualAllocInfo);
             VkResult vmaVirtualAllocate(
    VmaVirtualBlock  virtualBlock,
    const VmaVirtualAllocationCreateInfo*  pCreateInfo,
    VmaVirtualAllocation *  pAllocation,
    VkDeviceSize*  pOffset);
             void vmaVirtualFree(
    VmaVirtualBlock  virtualBlock,
    VmaVirtualAllocation  allocation);
             void vmaClearVirtualBlock(
    VmaVirtualBlock  virtualBlock);
             void vmaSetVirtualAllocationUserData(
    VmaVirtualBlock  virtualBlock,
    VmaVirtualAllocation  allocation,
    void*  pUserData);
             void vmaGetVirtualBlockStatistics(
    VmaVirtualBlock  virtualBlock,
    VmaStatistics*  pStats);
             void vmaCalculateVirtualBlockStatistics(
    VmaVirtualBlock  virtualBlock,
    VmaDetailedStatistics*  pStats);
             void vmaBuildVirtualBlockStatsString(
    VmaVirtualBlock  virtualBlock,
    char* *  ppStatsString,
    VkBool32 detailedMap);
             void vmaFreeVirtualBlockStatsString(
    VmaVirtualBlock  virtualBlock,
    char*  pStatsString);
             void vmaBuildStatsString(
    VmaAllocator  allocator,
    char* *  ppStatsString,
    VkBool32 detailedMap);
             void vmaFreeStatsString(
    VmaAllocator  allocator,
    char*  pStatsString);
