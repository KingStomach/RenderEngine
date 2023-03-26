#include "RenderManager.h"

int RERenderManager::RenderManager::InitializeImpl()
{
	m_thread = std::thread(&RenderManager::runThread, this);
	return 0;
}

void RERenderManager::RenderManager::FinalizeImpl()
{
	return;
}

void RERenderManager::RenderManager::TickImpl()
{
	return;
}