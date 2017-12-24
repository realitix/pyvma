import vulkan as vk
import pyvma as vma

appInfo = vk.VkApplicationInfo(
    sType=vk.VK_STRUCTURE_TYPE_APPLICATION_INFO,
    pApplicationName="Hello",
    applicationVersion=vk.VK_MAKE_VERSION(1, 0, 0),
    pEngineName="No Engine",
    engineVersion=vk.VK_MAKE_VERSION(1, 0, 0),
    apiVersion=vk.VK_API_VERSION_1_0)

createInfo = vk.VkInstanceCreateInfo(
    sType=vk.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    flags=0,
    pApplicationInfo=appInfo,
    enabledExtensionCount=0,
    ppEnabledExtensionNames=[],
    enabledLayerCount=0,
    ppEnabledLayerNames=[])

instance = vk.vkCreateInstance(createInfo, None)

physical_devices = vk.vkEnumeratePhysicalDevices(instance)
physical_device = physical_devices[0]

device_create = vk.VkDeviceCreateInfo(
    sType=vk.VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
    flags=0,
)

logical_device = vk.vkCreateDevice(physical_device, device_create, None)

# Simple example
vma_createinfo = vma.VmaAllocatorCreateInfo(physicalDevice=physical_device, device=logical_device)
vma_allocator = vma.vmaCreateAllocator(vma_createinfo)
vma_buffer_create = vk.VkBufferCreateInfo(size=65536, usage=vk.VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | vk.VK_BUFFER_USAGE_TRANSFER_DST_BIT)
vma_alloc_info = vma.VmaAllocationCreateInfo(usage=vma.VMA_MEMORY_USAGE_GPU_ONLY)
vma_buffer, vma_allocation, vma_allocation_info = vma.vmaCreateBuffer(vma_allocator, vma_buffer_create, vma_alloc_info);

# test functions
props = vma.vmaGetPhysicalDeviceProperties(vma_allocator)
print(props.deviceName)
props = vma.vmaGetMemoryProperties(vma_allocator)
print(props.memoryTypeCount)
props = vma.vmaGetMemoryTypeProperties(vma_allocator, 0)
print(props)
props = vma.vmaCalculateStats(vma_allocator)
print(props)
props = vma.vmaBuildStatsString(vma_allocator, False)
print(vma.ffi.string(props))
vma.vmaFreeStatsString(vma_allocator, props)
try:
    props = vma.vmaFindMemoryTypeIndex(vma_allocator, 0, vma_alloc_info)
    print(props)
except vk.VkErrorFeatureNotPresent:
    pass

# clean
vma.vmaDestroyBuffer(vma_allocator, vma_buffer, vma_allocation);
vma.vmaDestroyAllocator(vma_allocator);

print('It works')
