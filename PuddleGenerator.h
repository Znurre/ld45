#ifndef PUDDLEGENERATOR_H
#define PUDDLEGENERATOR_H

class PuddleGenerator
{
	public:
		static bool generate();

	private:
		static bool generate_impl(bool force);
};

#endif // PUDDLEGENERATOR_H
