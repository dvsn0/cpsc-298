#include <string>
#include <iostream>
#include <fstream>


class CentralPolygonalNumbers
{
public:
    /* data */
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int nMax);
    ~CentralPolygonalNumbers();
    void display();
    bool save(std::string strFilename);

private:
    int m_nMax;
    int* mp_iNumbers;
};

CentralPolygonalNumbers::CentralPolygonalNumbers()
{
    m_nMax = 0;
    mp_iNumbers = new int[1];
    mp_iNumbers[0] = 1;
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax)
{
    m_nMax = nMax;
    mp_iNumbers = new int[nMax + 1];
    for(int i = 0; i <= nMax; i++){
        mp_iNumbers[i] = ((i*i) + i + 2) / 2;
    }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
    // for(int i = 0; i <= m_nMax; i++){
    //     delete[] mp_iNumbers[i];
    // }
    delete[] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display()
{
    for(int i = 0; i <= m_nMax; i++){
        std::cout << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << std::endl;
    }
}

bool CentralPolygonalNumbers::save(std::string strFilename){
    std::ofstream ofsNumbers;
    ofsNumbers.open(strFilename);
    if(!ofsNumbers.is_open()){
        std::cout << "please check your input file name again" << std::endl;
        return false;
    }

    for(int i = 0; i <= m_nMax; i++){
        ofsNumbers << mp_iNumbers[i] << std::endl;
    }

    ofsNumbers.close();

    return true;

}

int main(){
    CentralPolygonalNumbers cpn(10);
    cpn.display();
    cpn.save("CPN");
}
