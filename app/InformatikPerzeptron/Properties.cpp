// author: Raphael Enßlin

#include "Properties.h"

#include <algorithm>
#include <string>

#include "imgui.h"

namespace properties
{
    void RenderUI()
    {
        ImGui::DockSpaceOverViewport();
        ImGui::Begin("Perzeptron");
        // Minimalbedingung
        {
            ImGui::Text("Minimal-Bedingung:");
            ImGui::Columns(3);
            for (int i = 0; i < nodes; ++i)
            {
                std::string s = "Input " + std::to_string(i);
                values.push_back(0);
                weights.push_back(0);
                ImGui::InputInt(s.c_str(), &values.at(i));
                ImGui::NextColumn();
            }
            ImGui::InputInt("Ergebnis", &exp_res);
            ImGui::Columns(1);
            if(ImGui::Button("Train")) Fit();
        }
        if(ImGui::Button("Reset"))
        {
            nodes = 2;
            weights = {0,0};
            values = {0,0};
            exp_res = 0;
        }
        ImGui::Checkbox("Erweiterte Optionen", &advanced);
        if(advanced)
        {
            ImGui::InputInt("Node-Anzahl", &nodes);
            ImGui::Checkbox("Lernrate automatisch festlegen", &autoAdjustLearnrate);
            if(!autoAdjustLearnrate)
            {
                ImGui::InputDouble("Lernrate", &learnrate);
            }

        }
        RenderTables();
        ImGui::DockSpace(ImGui::GetID("Perzeptron"));
        ImGui::End();
        DrawPerceptron();
        if(autoAdjustLearnrate) learnrate = 1 / double(nodes);
        for (int i = 0; i < nodes; ++i) values.at(i) = values.at(i) >= 1 ? 1 : 0;
        exp_res = exp_res >= 1 ? 1 : 0;
    }


    void RenderTables()
    {
        // Werte-Tabelle
        {
            std::vector<std::vector<int>> vals(nodes + 1, std::vector<int>(nodes, 0));
            for (int i = 0; i < nodes + 1; ++i)
                for (int j = 0; j < i; ++j)
                    vals.at(i).at(j) = 1;
            ImGui::BeginTable("Werte-Tabelle", nodes+1, ImGuiTableFlags_Borders + ImGuiTableFlags_RowBg);
            for (int i = 0; i < nodes; ++i) ImGui::TableSetupColumn(("Wert " + std::to_string(i)).c_str());
            ImGui::TableSetupColumn("Ergebnis");
            ImGui::TableHeadersRow();
            for (int i = 0; i < nodes + 1; ++i)
            {
                for (int j = 0; j < nodes; ++j)
                {
                    ImGui::TableNextColumn();
                    ImGui::Text("%d", vals.at(i).at(j));
                }
                ImGui::TableNextColumn();
                ImGui::Text("%d", int(Step(Predict(vals.at(i)))));
            }
            ImGui::EndTable();
        }
        // Gewichtungen
        {
            ImGui::BeginTable("Gewichte", nodes, ImGuiTableFlags_Borders + ImGuiTableFlags_RowBg);
            for (int i = 0; i < nodes; ++i) ImGui::TableSetupColumn(("Gewichtung " + std::to_string(i)).c_str());
            ImGui::TableHeadersRow();
            for (int i = 0; i < nodes; ++i)
            {
                ImGui::TableNextColumn();
                ImGui::Text("%f", weights.at(i));
            }
            ImGui::EndTable();
        }
    }


    void DrawPerceptron()
    {
        ImGui::Begin("Abbildung");
        ImDrawList* draw = ImGui::GetWindowDrawList();
        ImVec2 pos = ImGui::GetWindowPos();
        elOne = std::count(values.begin(), values.end(), 1);
        elTwo = Test();
        ImU32 col1 = elOne ? IM_COL32(0,255,0,255) : IM_COL32(255,0,0,255);
        ImU32 col2 = elTwo ? IM_COL32(0,255,0,255) : IM_COL32(255,0,0,255);
        ImU32 col3 = exp_res == 1 ? IM_COL32(0,255,0,255) : IM_COL32(255,0,0,255);
        draw->AddCircle(ImVec2(pos.x + 300.0f, pos.y + 200.0f), 50, IM_COL32(0,0,255,255),0,4);
        draw->AddCircle(ImVec2(pos.x + 100.0f, pos.y + 100.0f), 40, col1, 2, 4);
        draw->AddCircle(ImVec2(pos.x + 100.0f, pos.y + 300.0f), 40, col2, 2, 4);
        draw->AddCircle(ImVec2(pos.x + 500.0f, pos.y + 200.0f), 40, col3, 2, 4);
        ImGui::End();
    }

    bool Test()
    {
        int sum = 0;
        for (auto value : values)
        {
            sum += value;
        }
        return sum == nodes;
    }


    double Predict(std::vector<int> inputs)
    {
        double pre_res = 0;
        for (int i = 0; i < nodes; ++i)
            pre_res += double(inputs.at(i))*weights.at(i);
        return pre_res;
    }

    double Step(double i)
    {
        return i > thresh ? 1 : 0;
    }


    void Fit()
    {
        double real_res = Predict(values);
        double d_weight = 0;
        int res = exp_res;
        if (int(real_res) != res)
        {
            for (int i = 0; i < nodes; ++i) d_weight += learnrate * (double(exp_res) - real_res) * values.at(i);
            double diff = d_weight / double(nodes) * 1.1;
            for (int i = 0; i < nodes; ++i) weights.at(i) += diff;
        }
    }
}
