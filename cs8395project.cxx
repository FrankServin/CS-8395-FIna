#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkDivideImageFilter.h"
#include "itkNaryAddImageFilter.h"

#include "itkBinaryThresholdImageFilter.h"
#include "itkRegionOfInterestImageFilter.h"
#include <limits>
#include "string.h" 

int main(int argc, char* argv[])
{
    // Setup types
    const unsigned int nDims = 3;
    const unsigned int insideValue = 1;
    const unsigned int outsideValue = 0;
    typedef itk::Image< double, nDims > ImageType;
    const int UpperThreshold = std::numeric_limits<int>::max();
    const int LowerThreshold = 280;

    // Create and setup readers for images:
    typedef itk::ImageFileReader< ImageType >  ImageReaderType;
    ImageReaderType::Pointer Reader = ImageReaderType::New();
    Reader->SetFileName(argv[1]);
    Reader->Update();

    typedef itk::BinaryThresholdImageFilter <ImageType, ImageType> BinaryThresholdType;
    BinaryThresholdType::Pointer thresholder = BinaryThresholdType::New();
    thresholder->SetLowerThreshold(LowerThreshold);
    thresholder->SetUpperThreshold(UpperThreshold);
    thresholder->SetInsideValue(insideValue);
    thresholder->SetOutsideValue(outsideValue);

    typedef itk::RegionOfInterestImageFilter <ImageType, ImageType> RegionType;
    RegionType::Pointer ROI = RegionType::New();
    ROI->SetRegionOfInterest();

    // write out the result to:
    typedef itk::ImageFileWriter < ImageType > ImageWriterType;
    ImageWriterType::Pointer writer = ImageWriterType::New();
    writer->SetFileName("segmentation.nrrd");
    writer->SetInput(divider->GetOutput());
    writer->Update();

    // Done.
    return 0;
}