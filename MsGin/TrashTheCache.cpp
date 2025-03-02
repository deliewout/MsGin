#include "TrashTheCache.h"
#include <chrono>
#include <algorithm>
#include <numeric>

#include "imgui.h"
#include "implot.h"


void dae::TrashTheCache::RenderEx1()
{
    ImGui::Begin("Int Exercise");

    if (ImGui::Button("Trash the cache"))
    {
        ExInts();
    }
    ImGui::InputInt("samples", &m_IntSamplesAmount);
    if (!m_IntSamples.empty())
    {
        if (ImPlot::BeginPlot("Int Plot"))
        {
            ImPlot::PlotLine("Line Plot", m_IntSamples.data(), static_cast<int>(m_IntSamples.size()));
            ImPlot::EndPlot();
        }
    }

    ImGui::End();
}

void dae::TrashTheCache::RenderEx2()
{
    ImGui::Begin("GameObject Exercise");
    ImGui::InputInt("samples", &m_GOSamplesAmount);
    if (ImGui::Button("Trash the cache with GameObject3D"))
    {
        ExGameObject();
    }

    if (!m_GameObjectSamples.empty())
    {
        if (ImPlot::BeginPlot("GameObject Plot"))
        {
            ImPlot::PlotLine("GameObject Line", m_GameObjectSamples.data(), static_cast<int>(m_GameObjectSamples.size()));
            ImPlot::EndPlot();
        }
    }

    if (ImGui::Button("Trash the cache with AltGameObject3D"))
    {
        ExAltGameObject();
    }

    if (!m_AltGameObjectSamples.empty())
    {
        if (ImPlot::BeginPlot("AltGameObject Plot"))
        {
            ImPlot::PlotLine("AltGameObject Line", m_AltGameObjectSamples.data(), static_cast<int>(m_AltGameObjectSamples.size()));
            ImPlot::EndPlot();
        }
    }

    if(!m_GameObjectSamples.empty()&& !m_AltGameObjectSamples.empty())
    {
        if (ImPlot::BeginPlot("Combined Plot"))
        {
            ImPlot::PlotLine("Combined Line", m_GameObjectSamples.data(), static_cast<int>(m_GameObjectSamples.size()));
            ImPlot::SetNextLineStyle(ImVec4{ 0,1,1,0 });
            ImPlot::PlotLine("AltGameObject Line", m_AltGameObjectSamples.data(), static_cast<int>(m_AltGameObjectSamples.size()));
            ImPlot::EndPlot();
        }
    }

    ImGui::End();

}

void dae::TrashTheCache::ExInts()
{
    std::vector<int> buffer{};
    buffer.resize(m_BufferAmount);

    // Go over every step size
    for (int stepSize = 1; stepSize <= 1024; stepSize *= 2) 
    {
        std::vector<float> stepTimes{};
  
        for (int currentSamples = 0; currentSamples < m_IntSamplesAmount; ++currentSamples)
        {
            auto startTime = std::chrono::high_resolution_clock::now();
  
  			// Multiply every number in the buffer by 2
  			for (size_t i = 0; i < buffer.size(); i += stepSize) 
  			{
  				buffer[i] *= 2;
  			}
  
  			auto finalTime = std::chrono::high_resolution_clock::now();
  			auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(finalTime - startTime).count();
  			stepTimes.emplace_back(static_cast<float>(elapsedTime));
        }
        std::sort(stepTimes.begin(), stepTimes.end());
        const float average{ std::accumulate(stepTimes.begin() + 1,stepTimes.end() - 1,0.0f) / (stepTimes.size() - 2) };
        m_IntSamples.push_back(average);
    }
    
}

void dae::TrashTheCache::ExGameObject()
{
    std::vector<GameObject3D> buffer{};
    buffer.resize(m_BufferAmount);

    // Go over every step size
    for (int stepSize = 1; stepSize <= 1024; stepSize *= 2)
    {
        std::vector<float> stepTimes{};

        for (int currentSamples = 0; currentSamples < m_GOSamplesAmount; ++currentSamples)
        {
            auto startTime = std::chrono::high_resolution_clock::now();

            // Multiply every number in the buffer by 2
            for (size_t i = 0; i < buffer.size(); i += stepSize)
            {
                buffer[i].ID *= 2;
            }

            auto finalTime = std::chrono::high_resolution_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(finalTime - startTime).count();
            stepTimes.emplace_back(static_cast<float>(elapsedTime));
        }
        std::sort(stepTimes.begin(), stepTimes.end());
        const float average{ std::accumulate(stepTimes.begin() + 1,stepTimes.end() - 1,0.0f) / (stepTimes.size() - 2) };
        m_GameObjectSamples.push_back(average);
    }
}

void dae::TrashTheCache::ExAltGameObject()
{
    std::vector<AltGameObject3D> buffer{};
    buffer.resize(m_BufferAmount);

    // Go over every step size
    for (int stepSize = 1; stepSize <= 1024; stepSize *= 2)
    {
        std::vector<float> stepTimes{};

        for (int currentSamples = 0; currentSamples < m_GOSamplesAmount; ++currentSamples)
        {
            auto startTime = std::chrono::high_resolution_clock::now();

            // Multiply every number in the buffer by 2
            for (size_t i = 0; i < buffer.size(); i += stepSize)
            {
                buffer[i].ID *= 2;
            }

            auto finalTime = std::chrono::high_resolution_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(finalTime - startTime).count();
            stepTimes.emplace_back(static_cast<float>(elapsedTime));
        }
        std::sort(stepTimes.begin(), stepTimes.end());
        const float average{ std::accumulate(stepTimes.begin() + 1,stepTimes.end() - 1,0.0f) / (stepTimes.size() - 2) };
        m_AltGameObjectSamples.push_back(average);
    }
}
