// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include "Framework/runDataProcessing.h"
#include "Framework/AnalysisTask.h"

// define columns in a sub-namespace of o2::aod
// and tables in namespace o2::aod
namespace o2::aod
{
namespace etaphi
{
DECLARE_SOA_COLUMN(MEta, meta, float);
DECLARE_SOA_COLUMN(MPhi, mphi, float);
DECLARE_SOA_EXPRESSION_COLUMN(SPt, spt, float, nabs(track::sigma1Pt / track::signed1Pt));
} // namespace etaphi
DECLARE_SOA_TABLE(EtaPhi, "AOD", "ETAPHI",
                  etaphi::MEta, etaphi::MPhi);
} // namespace o2::aod

using namespace o2;
using namespace o2::framework;

struct ATask {
  // declare production of table etaphi
  Produces<aod::EtaPhi> etaphi;

  void process(aod::Tracks const& tracks)
  {
    for (auto& track : tracks) {
      float phi = asin(track.snp()) + track.alpha() + static_cast<float>(M_PI);
      float eta = log(tan(0.25f * static_cast<float>(M_PI) - 0.5f * atan(track.tgl())));

      // update the table etaphi
      etaphi(phi, eta);
    }
  }
};

struct BTask {
  // consume the table produced in ATask
  // process the entire table in one step
  void process(aod::EtaPhi const& etaPhis)
  {
    LOGF(INFO, "Number of etaPhis: %d", etaPhis.size());
    for (auto& etaPhi : etaPhis) {
      LOGF(INFO, "(%f, %f)", etaPhi.meta(), etaPhi.mphi());
    }
  }
};

struct CTask {
  using EtaPhiRow = aod::EtaPhi::iterator;
  
  // consume the table produced in ATask
  // process the table row by row
  void process(EtaPhiRow const& etaPhi)
  {
    LOGF(INFO, "(%f, %f)", etaPhi.meta(), etaPhi.mphi());
  }
};

WorkflowSpec defineDataProcessing(ConfigContext const& cfgc)
{
  return WorkflowSpec{
    adaptAnalysisTask<ATask>(cfgc, TaskName{"new-collections-tutorial_A"}),
    adaptAnalysisTask<BTask>(cfgc, TaskName{"new-collections-tutorial_B"}),
    adaptAnalysisTask<CTask>(cfgc, TaskName{"new-collections-tutorial_C"}),
  };
}
