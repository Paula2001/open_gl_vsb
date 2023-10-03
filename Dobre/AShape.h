#pragma once
class AShape
{
	public:
		AShape* setColor(char color);
		AShape* setPostion();
		const char* getColor();
		const char* getPosition();
		virtual void draw() = 0;

	private:
		const char* color;
		const char* position;
};

