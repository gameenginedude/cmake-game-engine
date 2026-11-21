
// pseudo code, not real!

vec4 inColor, vec4 outColor;
vec4 inNormal;

uniform LightData {
    vec3 direction;
    vec3 color; // rgb values:)
};

void main() {
    vec3 normal = normalize(inNormal);
    vec3 lightDir = normalize(direction);

    // lambertian diffuse lighting model (it's easy to understand,
    // look it up if you're interested:))
    float diffuse = max(dot(normal, lightDir), .0);
    float ambient = .1; // subtle light that's always visible!

    vec3 color = inColor * (diffuse + ambient);
    outColor = vec4(color, 1.);

    // done!
}
