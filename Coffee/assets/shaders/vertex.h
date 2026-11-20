#pragma once

#include <string_view>
constexpr std::string_view VertexShader = R"(
    // pseudo code, not real!

    vec3 inPosition; vec3 outPosition;
    vec3 inColor; vec3 outColor;
    vec3 inNormal; vec3 outNormal;

    uniform Object {
       mat4 modelMatrix;
    };

    uniform Camera {
       mat4 viewMatrix;
       mat4 projMatrix;
    };

    void main() {
        // world space position
        vec4 vertexPos = modelMatrix * vec4(inPosition, 1.);
        // clip space position
        vec4 clipPos = projMatrix * viewMatrix * vertexPos;
        // passing vertex colors and normals to the frag shader
        outColor = inColor;
        outNormal = inNormal;
    }
)";
