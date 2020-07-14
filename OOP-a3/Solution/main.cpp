/* @Author
Student Name: Baris Incesu
Student ID: 150170092
Date: 23.05.2020 */

#include <iostream>
#include <cmath>
//#include <algorithm>
#include <fstream>

//#include "windows.h"
//#define _CRTDBG_MAP_ALLOC //to get more details
//#include <crtdbg.h>

#define w 0.1 // Automatically create the necessary W matrices and B vectors with proper shapes, fill them all with “0.1” value.
#define b 0.1
//#define max(a, b)  (((a) > (b)) ? (a) : (b)) 

using namespace std; 

class Neuron // Abstract Base Class
{ 
protected: 
    double z; // value (z)
    double a; // activated value (a)
public:
    virtual void activate() = 0; // pure virtual method

    double getZ() { return z; }
    double getA() { return a; }

    void setZ(double i) { z = i; }
    void setA(double i) { a = i; }
    
    Neuron()
    {
        //cout << "Neuron Created" << endl;
    }
    ~Neuron()
    {
        //cout << "Neuron Deleted" << endl;
    }
}; 

class SigmoidNeuron: public Neuron 
{ 
public:
    void activate() { setA( 1 / (1 + exp(-z))); } 

    SigmoidNeuron()
    {
        //cout << "SigmoidNeuron Created" << endl;
    }
    ~SigmoidNeuron()
    {
        //cout << "SigmoidNeuron Deleted" << endl;
    }
}; 

class ReluNeuron: public Neuron
{
public:
    void activate() { setA( max(0.0, z)); }

    ReluNeuron()
    {
        //cout << "ReluNeuron Created" << endl;
    }
    ~ReluNeuron()
    {
        //cout << "ReluNeuron Deleted" << endl;
    }
};

class LReluNeuron: public Neuron
{
public:
    void activate() { setA( max(0.1*z, z)); }

    LReluNeuron()
    { 
        //cout << "LReluNeuron Created" << endl; 
    }
    ~LReluNeuron()
    {
        //cout << "LReluNeuron Deleted" << endl;
    }
};

class Layer
{
private:
    int neuron_num;
    Neuron * neurons; // keep an array of “Neuron”s

public:
    Layer(int, int, double*);
    Layer() 
    { 
        //cout << "Layer Created" << endl; 
    }
    ~Layer() 
    {
        if (neurons)
        {
            for (int i = 0; i < neuron_num; i++)
            {
                neurons[i].Neuron::~Neuron(); 
            }
        }
        //cout << "**************" << endl;
        //cout << "Layer Deleted" << endl;
        //cout << "**************" << endl;
    }

    void print(bool z) // print Neuron values
    {
        if (neurons)
        {
            if (z == true)
            {
                for (int i = 0; i < neuron_num; i++)
                {
                    cout << neurons[i].getZ() << endl; 
                }
            }
            else
            {
                for (int i = 0; i < neuron_num; i++)
                {
                    cout << neurons[i].getA() << endl; 
                }
            }
        } 
    }
};

Layer::Layer(int layer_object_number, int layer_type, double* array)
{
    neuron_num = layer_object_number;
    neurons = NULL;

    //• 0 for “Sigmoid”
    //• 1 for “Leaky ReLU”
    //• 2 for “ReLU”

    if (layer_type == 0)
    {
        neurons = new SigmoidNeuron[neuron_num];
    }
    else if (layer_type == 1)
    {
        neurons = new LReluNeuron[neuron_num];
    }
    else if (layer_type == 2)
    {
        neurons = new ReluNeuron[neuron_num];
    }  
    for (int i = 0; i < neuron_num; i++)
    {
        neurons[i].setZ(array[i]); // set z values
        neurons[i].activate(); // set a values
    }
}

class Network
{
private:
    int layer_num; // keep current layer_num
    Layer *layers; // keep an array of “Layer”s
public:
    Layer *getLayer() { return layers; }
    Network(int laynum) 
    {   
        //cout << "Network Created" << endl;
        //layers = NULL;
        layer_num = 0;
        layers = new Layer[laynum];
    }
    void setNum(int i) { layer_num = i; }
    ~Network() // Deconstuctor
    {
        delete[] layers;
        //cout << "Network Deleted" << endl;
    }
    void layerpush(const Layer &a) // Addes layers to Network
    {
        layers[layer_num] = a;
        //a.~Layer();
        setNum(layer_num+1);
    }
};

double * new_matrix(int previous, int next, double* old_matrix) // Matrix Operation for calculate new layer z values.
{
    double *matrix;
    matrix = new double[next];
    
    for (int i = 0; i < next; i++)
    {
        double result = 0;
        for (int j = 0; j < previous; j++)
        {
            double temp;
            temp = w * old_matrix[j];
            result = result + temp;
            temp = 0;
        }
        matrix[i] = result + b;
    }
    return matrix;
}

int main(int argc, char** argv)
{
    //_CrtDumpMemoryLeaks();
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    string filepath = argv[1];

    ifstream textFile(filepath);
    int x;

    textFile >> x;
    int layer_number = x; // First line indicates how many layers to have.

    int *layer_obj_n = new int[layer_number]; // Second line indicates how many neurons these layers have.
    for(int i = 0 ; i < layer_number; i++)
    {
        textFile >> x;
        layer_obj_n[i] = x;
    }

    int *layer_t = new int[layer_number]; // Third line indicates the type of the neurons at that layer
    for(int i = 0 ; i < layer_number; i++)
    {
        try
        {
            textFile >> x;
            if (x > 2)
            {   
                // If given neuron type is invalid (out of 0-2 range)
                // you need to throw: “Unidentified activation function!”
                throw 1;
            }
            
            layer_t[i] = x;
        }
        catch(const int error)
        {
            if (error == 1)
            {
                cout << "Unidentified activation function!" << endl;
                exit(1);
            }
        }
    }
    
    double *new_values = new double[layer_number];
    for(int i = 0 ; i < layer_number; i++)
    {
        textFile >> x;
        new_values[i] = x;
    }

    try
    {
        if (textFile >> x)
        {
            // If the number of the input values does not match with the neuron size of layer 0
            // you need to throw: “Input shape does not match!”
            throw 2;
        }
    }
    catch(const int error)
    {
        if (error == 2)
        {
            
            cout << "Input shape does not match!" << endl;
            exit(1);
        }
    }
    
    Network n1(layer_number); // call Network Constructor
    
    for (int i = 0; i < layer_number; i++)
    {
        n1.layerpush(Layer(layer_obj_n[i],layer_t[i],new_values)); // Layer Created and directly pushed to Network
        if (i+1 != layer_number) // New z values creator for next layer
        {
            new_values = new_matrix(layer_obj_n[i],layer_obj_n[i+1],new_values);
        }

        bool z = false; // for print Layer 0 z values
            if (i == 0)
            {
                bool z = true;
                cout << "Layer" << i << ":" << endl;
                n1.getLayer()[i].print(z);
            }
            else
            {
                cout << "Layer" << i << ":" << endl;
                n1.getLayer()[i].print(z);
            }
    }

    delete [] layer_obj_n; // release memory
    delete [] layer_t; // release memory
    delete [] new_values; // release memory

    //n1.~Network();
    return 0; 
}