#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkNormalizeImageFilter.h"
#include "itkStatisticsImageFilter.h"
 
#include <iomanip>
 
int main(int argc, char *argv[])
{
  if(argc < 2)
    {
    std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
    return EXIT_FAILURE;
    }
 
  typedef itk::Image<double, 3>  FloatImageType;
 
  typedef itk::ImageFileReader<FloatImageType> ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(argv[1]);
 
  typedef itk::NormalizeImageFilter< FloatImageType, FloatImageType > NormalizeFilterType;
  NormalizeFilterType::Pointer normalizeFilter = NormalizeFilterType::New();
  normalizeFilter->SetInput(reader->GetOutput());
 
  typedef itk::ImageFileWriter< FloatImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName( argv[2] );
  writer->SetInput( normalizeFilter->GetOutput() );

  try
    {
    writer->Update();
    }
  catch( itk::ExceptionObject & error )
    {
    std::cerr << "Error: " << error << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}

 
