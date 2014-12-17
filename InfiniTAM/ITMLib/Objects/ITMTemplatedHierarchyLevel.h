// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../Objects/ITMImage.h"

namespace ITMLib
{
	namespace Objects
	{
		template <class ImageType>
		class ITMTemplatedHierarchyLevel
		{
		public:
			int levelId;

			bool rotationOnly;

			ImageType *depth;
			Vector4f intrinsics;
			bool manageData;

			ITMTemplatedHierarchyLevel(Vector2i imgSize, int levelId, bool rotationOnly, bool useGPU, bool skipAllocation = false)
			{
				this->manageData = !skipAllocation;
				this->levelId = levelId;
				this->rotationOnly = rotationOnly;

				if (!skipAllocation) this->depth = new ImageType(imgSize, useGPU);
			}

			void UpdateHostFromDevice()
			{ 
				this->depth->UpdateHostFromDevice();
			}

			void UpdateDeviceFromHost()
			{ 
				this->depth->UpdateHostFromDevice();
			}

			~ITMTemplatedHierarchyLevel(void)
			{
				if (manageData) delete depth;
			}

			// Suppress the default copy constructor and assignment operator
			ITMTemplatedHierarchyLevel(const ITMTemplatedHierarchyLevel&);
			ITMTemplatedHierarchyLevel& operator=(const ITMTemplatedHierarchyLevel&);
		};
	}
}