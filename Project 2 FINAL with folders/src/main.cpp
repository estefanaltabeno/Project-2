#include "ImageMaker.h"

#include <iostream>

#include <vector>

#include <fstream>

using namespace std;

vector<Pixel> pixels;

vector<Pixel> pixels2;

vector<Pixel> pixels3;

vector<Pixel> pixels4;

vector<Pixel> finalProd;

vector<Pixel> testCasePixels;

unsigned short extraCreditHeight = 0;

unsigned short extraCreditWidth = 0;

Header h;

void FileOut(string name)
{
    if (name.at(0) == 't')
    {
	string temp = "input/";
	
	temp += name;

	name = temp; 
    }
    
    else
    {
	string temp = "output/";
    
        temp += name; 
    
        name = temp; 
    }

    ofstream outFile(name , ios_base::binary);

    outFile.write(&h.idLength, sizeof(h.idLength));

    outFile.write(&h.colorMapType, sizeof(h.colorMapType));

    outFile.write(&h.dataTypeCode, sizeof(h.dataTypeCode));

    outFile.write((char *)&h.colorMapOrigin, sizeof(h.colorMapOrigin));

    outFile.write((char *)&h.colorMapLength, sizeof(h.colorMapLength));

    outFile.write(&h.colorMapDepth, sizeof(h.colorMapDepth));

    outFile.write((char *)&h.xOrigin, sizeof(h.xOrigin));

    outFile.write((char *)&h.yOrigin, sizeof(h.yOrigin));

    outFile.write((char *)&h.width, sizeof(h.width));

    outFile.write((char *)&h.height, sizeof(h.height));

    outFile.write(&h.bitsPerPixel, sizeof(h.bitsPerPixel));

    outFile.write(&h.imageDescriptor, sizeof(h.imageDescriptor));

    //int byteSize = sizeof(h.idLength) + sizeof(h.colorMapType) + sizeof(h.dataTypeCode) + sizeof(h.colorMapOrigin) + sizeof(h.colorMapLength) + sizeof(h.colorMapDepth) + sizeof(h.xOrigin) + sizeof(h.yOrigin) + sizeof(h.width) + sizeof(h.height) + sizeof(h.bitsPerPixel) + sizeof(h.imageDescriptor);

    //cout << byteSize << endl;

    outFile.seekp(18);

    int sizeFile = (int)h.height * (int)h.height;

    for (int i = 0; i < finalProd.size(); i++)
    {
        Pixel pixel = finalProd.at(i);

        outFile.write((char *)&pixel.blue, sizeof(pixel.blue));

        outFile.write((char *)&pixel.green, sizeof(pixel.green));

        outFile.write((char *)&pixel.red, sizeof(pixel.red));
    }

}

void ReadingData(string name, int n)
{
    if (name.at(0) == 'E')
    {
        string temp = "examples/";

	temp += name;

	name = temp;
    }

    else
    {
    	string temp = "input/";
    
   	temp += name;
    
    	name = temp; 
    }
    ifstream file (name, ios_base::binary);

    file.read(&h.idLength, sizeof(h.idLength));

    file.read(&h.colorMapType, sizeof(h.colorMapType));

    file.read(&h.dataTypeCode, sizeof(h.dataTypeCode));

    file.read((char *)&h.colorMapOrigin, sizeof(h.colorMapOrigin));

    file.read((char *)&h.colorMapLength, sizeof(h.colorMapLength));

    file.read(&h.colorMapDepth, sizeof(h.colorMapDepth));

    file.read((char *)&h.xOrigin, sizeof(h.xOrigin));

    file.read((char *)&h.yOrigin, sizeof(h.yOrigin));

    file.read((char *)&h.width, sizeof(h.width));

    file.read((char *)&h.height, sizeof(h.height));

    file.read(&h.bitsPerPixel, sizeof(h.bitsPerPixel));

    file.read(&h.imageDescriptor, sizeof(h.imageDescriptor));

    //int byteSize = sizeof(h.idLength) + sizeof(h.colorMapType) + sizeof(h.dataTypeCode) + sizeof(h.colorMapOrigin) + sizeof(h.xOrigin) + sizeof(h.yOrigin) + sizeof(h.width) + sizeof(h.height) + sizeof(h.bitsPerPixel) + sizeof(h.imageDescriptor);

    //cout << byteSize << endl;

    int sizeFile = (int)h.width * (int)h.height;

    file.seekg(18);

    if (n == 0)
    {
        for (int i = 0; i < sizeFile; i++)
        {
            Pixel pixel;

            file.read((char *)&pixel.blue, sizeof(pixel.blue));

            file.read((char *)&pixel.green, sizeof(pixel.green));

            file.read((char *)&pixel.red, sizeof(pixel.red));

            pixels.push_back(pixel);
        }
    }
    else if (n == 1)
    {
        for (int i = 0; i < sizeFile; i++)
        {
            Pixel pixel;

            file.read((char *)&pixel.blue, sizeof(pixel.blue));

            file.read((char *)&pixel.green, sizeof(pixel.green));

            file.read((char *)&pixel.red, sizeof(pixel.red));

            pixels2.push_back(pixel);
        }
    }

    else if (n == 2)
    {
        for (int i = 0; i < sizeFile; i++)
        {
            Pixel pixel;

            file.read((char *)&pixel.blue, sizeof(pixel.blue));

            file.read((char *)&pixel.green, sizeof(pixel.green));

            file.read((char *)&pixel.red, sizeof(pixel.red));

            testCasePixels.push_back(pixel);
        }
    }

    else if (n == 3)
    {
        for (int i = 0; i < sizeFile; i++)
        {
            Pixel pixel;

            file.read((char *)&pixel.blue, sizeof(pixel.blue));

            file.read((char *)&pixel.green, sizeof(pixel.green));

            file.read((char *)&pixel.red, sizeof(pixel.red));

            pixels3.push_back(pixel);
        }
    }

    else if (n == 4)
    {
        for (int i = 0; i < sizeFile; i++)
        {
            Pixel pixel;

            file.read((char *)&pixel.blue, sizeof(pixel.blue));

            file.read((char *)&pixel.green, sizeof(pixel.green));

            file.read((char *)&pixel.red, sizeof(pixel.red));

            pixels4.push_back(pixel);
        }
    }
}

Pixel Multiply(Pixel a, Pixel b)
{
    Pixel temp;

    float red = ((float)a.red / 255) * ((float)b.red / 255);

    float green = ((float)a.green / 255) * ((float)b.green / 255);

    float blue = ((float)a.blue / 255) * ((float)b.blue / 255);

    /*
    cout << "blue " << blue << " " << blue * 255 << endl;

    cout << "green " << green << " " << green * 255 << endl;

    cout << "red " << red << " " << red * 255 << endl;
     */

    temp.red = (unsigned char)((red * 255) + 0.5f);

    temp.green = (unsigned char)((green * 255) + 0.5f);

    temp.blue = (unsigned char)((blue * 255) + 0.5f);

    //cout << "temp blue " << (int)temp.blue << endl;

    //cout << "temp green " << (int)temp.green << endl;

    //cout << "temp red " << (int)temp.red << endl;

    return temp;
}

int turnBack(int n)
{
    if (n < 0)
    {
        return 0;
    }

    else if (n > 255)
    {
        return 255;
    }

    return n;
}

Pixel Subtract(Pixel a, Pixel b)
{
    Pixel temp;

    int red = (int)a.red - (int)b.red;

    red = turnBack(red);

    int green = (int)a.green - (int)b.green;

    green = turnBack(green);

    int blue = (int)a.blue - (int)b.blue;

    blue = turnBack(blue);

    temp.red = (unsigned char)red;

    temp.green = (unsigned char)green;

    temp.blue = (unsigned char)blue;

    return temp;
}



Pixel Screen(Pixel a, Pixel b)
{
    Pixel temp;

    temp.red = 255;

    temp.green = 255;

    temp.blue = 255;

    Pixel resultA = Subtract(temp, a);

    Pixel resultB = Subtract(temp, b);

    Pixel finally = Multiply(resultA, resultB);

    finally = Subtract(temp, finally);

    /*
    int red = (1 - (1 - ((int) a.red / 255))) * (1 - (1 - ((int) b.red / 255)));

    int green = (1 - (1 - ((int) a.green / 255))) * (1 - (1 - ((int) b.green / 255)));

    int blue = (1 - (1 - ((int) a.blue / 255))) * (1 - (1 - ((int) b.blue / 255)));

    temp.red = red * 255;

    temp.green = green * 255;

    temp.blue = blue * 255;

     */

    return finally;
}

bool Checker(float inval)
{
    float comparison = 1.0f/2;

    if (inval > comparison)
    {
        return true;
    }

    return false;
}

Pixel Overlay(Pixel a, Pixel b)
{
    Pixel temp;

    float result;

    float tempA;

    float tempB;

    tempA = ((float)a.red / 255.0f);

    tempB = ((float)b.red / 255.0f);

    bool check = Checker(tempB);

    if (check)
    {
        result = (1.0f - (2.0f * (1.0f - tempA) * (1.0f - tempB)));

        result *= 255.0f;

        temp.red = (unsigned char)(result + 0.5f);
    }
    else
    {
        result = (2 * tempA * tempB);

        result *= 255.0f;

        temp.red = (unsigned char)(result + 0.5f);
    }

    tempA = ((float)a.green / 255.0f);

    tempB = ((float)b.green / 255.0f);

    check = Checker(tempB);

    if (check)
    {
        result = (1.0f - (2.0f * (1.0f - tempA) * (1.0f - tempB)));

        result *= 255.0f;

        temp.green = (unsigned char)(result + 0.5f);
    }
    else
    {
        result = (2 * tempA * tempB);

        result *= 255.0f;

        temp.green = (unsigned char)(result + 0.5f);
    }

    tempA = ((float)a.blue / 255.0f);

    tempB = ((float)b.blue / 255.0f);

    check = Checker (tempB);

    if (check)
    {
        result = (1.0f - (2.0f * (1.0f - tempA) * (1.0f - tempB)));

        result *= 255.0f;

        temp.blue = (unsigned char)(result + 0.5f);
    }
    else
    {
        result = (2 * tempA * tempB);

        result *= 255.0f;

        temp.blue = (unsigned char)(result + 0.5f);
    }

    return temp;
}


void TestCase(string name)
{
    bool check = true;

    //"layer1.tga"

    //"pattern1.tga"

    ReadingData(name, 2);

    cout << finalProd.size() << endl;

    for (unsigned int i = 0; i < finalProd.size(); i++)
    {
        Pixel temp1 = testCasePixels.at(i);

        Pixel temp2 = finalProd.at(i);

        if (temp1.red != temp2.red)
        {
            cout << "correct red " << (int)temp1.red << endl;

            cout << "My red " << (int)temp2.red << endl;

            check = false;
        }
        else if (temp1.green != temp2.green)
        {

            cout << "correct green " << (int)temp1.green << endl;

            cout << "My green " << (int)temp2.green << endl;

            check = false;
        }
        else if (temp1.blue != temp2.blue)
        {
            cout << "correct blue " << (int)temp1.blue << endl;

            cout << "My blue " << (int)temp2.blue << endl;

            check = false;
        }
    }

    if (check)
    {
        cout << "Passed!" << endl;
    }

    else
    {
        cout << "Cap." << endl;
    }
}

void Clear()
{
    pixels.clear();

    pixels2.clear();

    pixels3.clear();

    finalProd.clear();

    testCasePixels.clear();
}

Pixel Combine(Pixel a, int value)
{
    Pixel temp;

    int green = (int)a.green + value;

    green = turnBack(green);

    temp.green = (unsigned char)green;

    temp.red = a.red;

    temp.blue = a.blue;

    return temp;
}

void Loop()
{
    int cond = (int)h.width / 2;

    int var = 0;

    //This was all thanks to that picture labeling all of the pixels 0-... it was super helpful in visualization. Thank you Professor Fox!
    //I feel very proud for coming up with this below and it was all on my own!
    //My very own idea!

    for (int i = 0; i < (int)h.height / 2; i++)
    {
        for (int z = 0; z < cond; z++)
        {
            finalProd.push_back(pixels4.at(z + var));
        }

        for (int j = 0; j < cond; j++)
        {
            finalProd.push_back(pixels3.at(j + var));
        }

        var += cond;
    }

    var = 0;

    for (int i = 0; i < (int)h.height / 2; i++)
    {
        for (int z = 0; z < cond; z++)
        {
            finalProd.push_back(pixels.at(z + var));
        }

        for (int j = 0; j < cond; j++)
        {
            finalProd.push_back(pixels2.at(j + var));
        }

        var += cond;
    }
}

int main()
{
    ReadingData("layer1.tga" , 0);

    ReadingData("pattern1.tga" , 1);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Multiply(pixels.at(i), pixels2.at(i)));
    }

    FileOut("part1.tga");

    TestCase("EXAMPLE_part1.tga");

    Clear();

    ReadingData("layer2.tga", 0);

    ReadingData("car.tga", 1);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Subtract(pixels2.at(i), pixels.at(i)));
    }

    FileOut("part2.tga");

    TestCase("EXAMPLE_part2.tga");

    Clear();

    ReadingData("layer1.tga", 0);

    ReadingData("pattern2.tga", 1);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Multiply(pixels.at(i), pixels2.at(i)));
    }

    pixels.clear();

    ReadingData("text.tga", 0);

    for(unsigned int i = 0; i < finalProd.size(); i++)
    {
        finalProd.at(i) = Screen(pixels.at(i), finalProd.at(i));
    }

    FileOut("part3.tga");

    TestCase("EXAMPLE_part3.tga");

    Clear();

    ReadingData("layer2.tga", 0);

    ReadingData("circles.tga", 1);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Multiply(pixels.at(i), pixels2.at(i)));
    }

    FileOut("temp.tga");

    Clear();

    ReadingData("pattern2.tga", 0);

    ReadingData("temp.tga", 1);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Subtract(pixels2.at(i), pixels.at(i)));
    }

    FileOut("part4.tga");

    TestCase("EXAMPLE_part4.tga");

    Clear();

    ReadingData("layer1.tga", 0);

    ReadingData("pattern1.tga", 1);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Overlay(pixels.at(i), pixels2.at(i)));
    }

    FileOut("part5.tga");

    TestCase("EXAMPLE_part5.tga");

    Clear();

    ReadingData("car.tga", 0);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        finalProd.push_back(Combine(pixels.at(i), 200));
    }

    FileOut("part6.tga");

    TestCase("EXAMPLE_part6.tga");

    Clear();

    ReadingData("car.tga", 0);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        if (((int)pixels.at(i).red * 4) > 255)
        {
            pixels.at(i).red = 255;
        }
        else
        {
            pixels.at(i).red *= 4;
        }

        pixels.at(i).blue = 0;

        finalProd.push_back(pixels.at(i));
    }

    FileOut("part7.tga");

    TestCase("EXAMPLE_part7.tga");

    Clear();

    ReadingData("car.tga", 0);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        Pixel temp;

        temp.red = pixels.at(i).red;

        temp.green = pixels.at(i).red;

        temp.blue = pixels.at(i).red;

        finalProd.push_back(temp);
    }

    FileOut("part8_r.tga");

    TestCase("EXAMPLE_part8_r.tga");

    Clear();

    ReadingData("car.tga", 0);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        Pixel temp;

        temp.red = pixels.at(i).green;

        temp.green = pixels.at(i).green;

        temp.blue = pixels.at(i).green;

        finalProd.push_back(temp);
    }

    FileOut("part8_g.tga");

    TestCase("EXAMPLE_part8_g.tga");

    Clear();

    ReadingData("car.tga", 0);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        Pixel temp;

        temp.red = pixels.at(i).blue;

        temp.green = pixels.at(i).blue;

        temp.blue = pixels.at(i).blue;

        finalProd.push_back(temp);
    }

    FileOut("part8_b.tga");

    TestCase("EXAMPLE_part8_b.tga");

    Clear();

    ReadingData("layer_red.tga", 0);

    ReadingData("layer_green.tga", 1);

    ReadingData("layer_blue.tga", 3);

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        Pixel temp;

        temp.red = pixels.at(i).red;

        temp.green = pixels2.at(i).green;

        temp.blue = pixels3.at(i).blue;

        finalProd.push_back(temp);
    }

    FileOut("part9.tga");

    TestCase("EXAMPLE_part9.tga");

    Clear();

    ReadingData("text2.tga", 0);

    unsigned int sizething = pixels.size() - 1;

    for (unsigned int i = sizething; i > 0; i--)
    {
        finalProd.push_back(pixels.at(i));
    }

    finalProd.push_back(pixels.at(0));

    FileOut("part10.tga");

    TestCase("EXAMPLE_part10.tga");

    Clear();

    ReadingData("car.tga", 0);

    ReadingData("circles.tga", 1);

    ReadingData("pattern1.tga", 3);

    ReadingData("text.tga", 4);

    extraCreditWidth = 2 * (short)h.width;

    extraCreditHeight = 2 * (short)h.height;

    h.width = extraCreditWidth;

    h.height = extraCreditHeight;

    Loop();

    FileOut("extracredit.tga");

    TestCase("EXAMPLE_extracredit.tga");

    return 0;
}
