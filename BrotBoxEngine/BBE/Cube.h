#pragma once

#include "../BBE/VulkanBuffer.h"
#include "../BBE/VWTransform.h"
#include "../BBE/Vector3.h"

namespace bbe
{
	namespace INTERNAL
	{
		namespace vulkan
		{
			class VulkanManager;
		}
	}

	class Cube
	{
		friend class PrimitiveBrush3D;
		friend class INTERNAL::vulkan::VulkanManager;
	private:
		VWTransform m_transform;
		INTERNAL::vulkan::VulkanBuffer m_transformBuffer;

		static void s_init(VkDevice device, VkPhysicalDevice physicalDevice, INTERNAL::vulkan::VulkanCommandPool &commandPool, VkQueue queue);
		static void s_initIndexBuffer(VkDevice device, VkPhysicalDevice physicalDevice, INTERNAL::vulkan::VulkanCommandPool &commandPool, VkQueue queue);
		static void s_initVertexBuffer(VkDevice device, VkPhysicalDevice physicalDevice, INTERNAL::vulkan::VulkanCommandPool &commandPool, VkQueue queue);
		static void s_destroy();
		static bbe::INTERNAL::vulkan::VulkanBuffer s_indexBuffer;
		static bbe::INTERNAL::vulkan::VulkanBuffer s_vertexBuffer;

		mutable bool m_bufferDirty = true;

	public:
		Cube();
		Cube(const Vector3 &pos, const Vector3 &scale, const Vector3 &rotationVector, float radians);
		Cube(const Matrix4 &transform);

		void set(const Vector3 &pos, const Vector3 &scale, const Vector3 &rotationVector, float radians);

		Vector3 getPos() const;
		float getX() const;
		float getY() const;
		float getZ() const;

		Vector3 getScale() const;
		float getWidth() const;
		float getHeight() const;
		float getDepth() const;

		Matrix4 getTransform() const;
	};
}