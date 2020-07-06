#ifndef RUN_TIME_POLYMORPHISM
#define RUN_TIME_POLYMORPHISM
#include <iostream>
#include <chrono>
#define HEADER std::cout<<"\n ===================="<<__FUNCTION__<<"===============\n";

//To store dimension of an image.
class Dimension {
public:
    Dimension(int _X, int _Y) :mX(_X), mY(_Y) {}
private:
    int mX, mY;
};


//Base class for all image types.
class Image {
public:
    virtual void Draw() = 0;
    virtual Dimension GetDimensionInPixels() = 0;

protected:
    int dimensionX, dimensionY;
};


class TiffImage :public Image
{
public:
    void Draw()override { std::cout << " I am draw fucntion from Tiffimage\n "; }
    Dimension GetDimensionInPixels()
    {
        return Dimension(dimensionX, dimensionY);
    }
};

void run_dynamic_polymorphism()
{
	HEADER;
    Image* pImage = new TiffImage;
    
    for (int i = 0; i < 5; i++)
    {
        pImage->Draw();
    }

   ;
}
#endif