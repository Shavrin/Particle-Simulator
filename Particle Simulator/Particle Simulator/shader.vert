void main()
{
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;


	vertex.xy = vec2(vertex.x,vertex.y);

   
	gl_Position = gl_ProjectionMatrix * vertex;
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;
}
