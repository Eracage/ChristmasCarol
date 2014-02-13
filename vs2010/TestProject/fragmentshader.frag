uniform sampler2D unifSampler;

varying vec2 texCoord;

void main() 
{
	gl_FragColor = texture2D(unifSampler,texCoord);
}