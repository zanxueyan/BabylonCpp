#include <babylon/samples/samples_common.h>

namespace BABYLON {
namespace Samples {

_ISamplesIndex::_ISamplesIndex()
{
}

_ISamplesIndex::~_ISamplesIndex()
{
}

const std::unordered_map<string_t, Sample>& _ISamplesIndex::samples() const
{
  return _samples;
}

} // end of namespace Samples
} // end of namespace BABYLON
