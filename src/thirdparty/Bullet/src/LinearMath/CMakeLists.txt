
SET(LinearMath_SRCS
	btAlignedAllocator.cpp
	btConvexHull.cpp
	btConvexHullComputer.cpp
	btGeometryUtil.cpp
	btPolarDecomposition.cpp
	btQuickprof.cpp
	btReducedVector.cpp
	btSerializer.cpp
	btSerializer64.cpp
	btThreads.cpp
	btVector3.cpp
	TaskScheduler/btTaskScheduler.cpp
	TaskScheduler/btThreadSupportPosix.cpp
	TaskScheduler/btThreadSupportWin32.cpp
)

SET(LinearMath_HDRS
	btAabbUtil2.h
	btAlignedAllocator.h
	btAlignedObjectArray.h
	btConvexHull.h
	btConvexHullComputer.h
	btDefaultMotionState.h
	btGeometryUtil.h
	btGrahamScan2dConvexHull.h
	btHashMap.h
	btIDebugDraw.h
	btList.h
	btMatrix3x3.h
	btImplicitQRSVD.h
	btMinMax.h
	btModifiedGramSchmidt.h
	btMotionState.h
	btPolarDecomposition.h
	btPoolAllocator.h
	btQuadWord.h
	btQuaternion.h
	btQuickprof.h
	btReducedVector.h
	btRandom.h
	btScalar.h
	btSerializer.h
	btStackAlloc.h
	btThreads.h
	btTransform.h
	btTransformUtil.h
	btVector3.h
	TaskScheduler/btThreadSupportInterface.h
)

list(TRANSFORM LinearMath_HDRS PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
list(TRANSFORM LinearMath_SRCS PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(MOSP PRIVATE ${LinearMath_SRCS} ${LinearMath_HDRS})
