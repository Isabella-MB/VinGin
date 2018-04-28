#include "src/graphics/window.h"
#include "src/graphics/shader.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderable2d.h"
#include "src/graphics/sprite.h"
#include "src/graphics/batch_renderer2d.h"

#include "src/utils/timer.h"

#include <vector>

int main()
{
	using namespace vingin;
	using namespace graphics;
	
	Window window("VinGin", 960, 540);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");

	shader.enable();
	
	shader.setUniformMat4("projection", math::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
	shader.setUniformMat4("view", math::mat4::translate(math::vec3(0.0f, 0.0f, -1.0f)));

	std::vector<Renderable2D*> sprites;

	for (float y = 0.0f; y < 9.0f; y += 0.1f)
	{
		for (float x = 0.0f; x < 16.0f; x += 0.1f)
		{
			sprites.push_back(new Sprite(x, y, 0.09f, 0.09f, math::vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1)));
		}
	}

	BatchRenderer2D renderer;
	
	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_position", math::vec2(x * 16.0f / 960.0f, y * 9.0f / 540.0f));

		renderer.begin();
		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}
		renderer.end();
		renderer.flush();

		window.update();

		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}