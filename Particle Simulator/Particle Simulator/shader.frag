void main()
{
	vec2 pixelCoord = gl_FragCoord.xy;
    gl_FragColor =  vec4(pixelCoord.x/255.0,pixelCoord.y/255.0,0,255);
}
