---
sort: 6
title: The Data Model
---

# The data model

The ALICE O2 data model is a collection of tables. This includes tables which are read from the input files [AO2D files](#AO2D) and also such which are created by tasks. To produce some tables with commonly used quantities there exist a set of predefined [helper tasks](#helper_tasks) which can be included in user analysis work flows.

There is also a bunch of pre-defined [joins and iterators](#usings) which are summarized in the list further down.

### Table relations

Information contained in different tables can be related. E.g. a track belongs to a given collision, or signals in the FIT or Zdc detectors belong to a bunch crossing.

Hence the dependent tables need to hold an index which points to a specific row of the master table. For this the dependent table (e.g. table Tracks) has an index column [master]Id (in this case CollisionsId) which points to the related information in table master. See also e.g. master=BCs and dependent=CaloTriggers and many more.

```note
Be aware that tables can be [joined](framework.md#processing-related-tables) and be [extended](framework.html#expression-columns) with extra colums.
```

<a name="AO2D"></a>
## List of tables defined in the AO2D data files

The tables which are extracted from the AO2D files are declared in <a href="https://github.com/AliceO2Group/AliceO2/blob/dev/Framework/Core/include/Framework/AnalysisDataModel.h" target="_blank">Framework/AnalysisDataModel.h</a> and listed below. They are available by default when using an AO2D file as input to an analysis work flow.

Click on the labels to display the table details.

<!----------------------------------------------------------------------------->
<!--                                                                         -->
<!-- copy html version of AnalysisDataModel.h here below                     -->
<!--                                                                         -->
<!----------------------------------------------------------------------------->

####  AO2D files
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::BCs</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::BC = o2::aod::BCs::iterator</li>
        <li>o2::aod::BCsWithTimestamps = soa::Join<o2::aod::BCs, o2::aod::Timestamps></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::bc::RunNumber</td>
        <td>runNumber</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::bc::GlobalBC</td>
        <td>globalBC</td>
        <td>uint64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::bc::TriggerMask</td>
        <td>triggerMask</td>
        <td>uint64_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Collisions</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Collision = o2::aod::Collisions::iterator</li>
        <li>o2::aod::CollisionMatchedRun2Sparse = soa::Join<o2::aod::Collisions, o2::aod::Run2MatchedSparse>::iterator</li>
        <li>o2::aod::CollisionMatchedRun3Sparse = soa::Join<o2::aod::Collisions, o2::aod::Run3MatchedSparse>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::PosX</td>
        <td>posX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::PosY</td>
        <td>posY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::PosZ</td>
        <td>posZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CovXX</td>
        <td>covXX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CovXY</td>
        <td>covXY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CovXZ</td>
        <td>covXZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CovYY</td>
        <td>covYY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CovYZ</td>
        <td>covYZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CovZZ</td>
        <td>covZZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::Flags</td>
        <td>flags</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::NumContrib</td>
        <td>numContrib</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CollisionTime</td>
        <td>collisionTime</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CollisionTimeRes</td>
        <td>collisionTimeRes</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::collision::CollisionTimeMask</td>
        <td>collisionTimeMask</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredTracks</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TrackType</td>
        <td>trackType</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Alpha</td>
        <td>alpha</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Snp</td>
        <td>snp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Tgl</td>
        <td>tgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Signed1Pt</td>
        <td>signed1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::NormalizedPhi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Tracks</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Track = o2::aod::Tracks::iterator</li>
        <li>o2::aod::FullTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra></li>
        <li>o2::aod::FullTrack = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra>::iterator</li>
        <li>o2::aod::BigTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra, o2::aod::HFSelTrack></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TrackType</td>
        <td>trackType</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Alpha</td>
        <td>alpha</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Snp</td>
        <td>snp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Tgl</td>
        <td>tgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Signed1Pt</td>
        <td>signed1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::NormalizedPhi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Pt</td>
        <td>pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::P</td>
        <td>p</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RawPhi</td>
        <td>phiraw</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredTracksCov</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaY</td>
        <td>sigmaY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaZ</td>
        <td>sigmaZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaSnp</td>
        <td>sigmaSnp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaTgl</td>
        <td>sigmaTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Sigma1Pt</td>
        <td>sigma1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoZY</td>
        <td>rhoZY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoSnpY</td>
        <td>rhoSnpY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoSnpZ</td>
        <td>rhoSnpZ</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoTglY</td>
        <td>rhoTglY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoTglZ</td>
        <td>rhoTglZ</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoTglSnp</td>
        <td>rhoTglSnp</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtY</td>
        <td>rho1PtY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtZ</td>
        <td>rho1PtZ</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtSnp</td>
        <td>rho1PtSnp</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtTgl</td>
        <td>rho1PtTgl</td>
        <td>int8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::TracksCov</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::TrackCov = o2::aod::TracksCov::iterator</li>
        <li>o2::aod::FullTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra></li>
        <li>o2::aod::FullTrack = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra>::iterator</li>
        <li>o2::aod::BigTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra, o2::aod::HFSelTrack></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaY</td>
        <td>sigmaY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaZ</td>
        <td>sigmaZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaSnp</td>
        <td>sigmaSnp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::SigmaTgl</td>
        <td>sigmaTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Sigma1Pt</td>
        <td>sigma1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoZY</td>
        <td>rhoZY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoSnpY</td>
        <td>rhoSnpY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoSnpZ</td>
        <td>rhoSnpZ</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoTglY</td>
        <td>rhoTglY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoTglZ</td>
        <td>rhoTglZ</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::RhoTglSnp</td>
        <td>rhoTglSnp</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtY</td>
        <td>rho1PtY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtZ</td>
        <td>rho1PtZ</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtSnp</td>
        <td>rho1PtSnp</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Rho1PtTgl</td>
        <td>rho1PtTgl</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CYY</td>
        <td>cYY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CZY</td>
        <td>cZY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CZZ</td>
        <td>cZZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CSnpY</td>
        <td>cSnpY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CSnpZ</td>
        <td>cSnpZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CSnpSnp</td>
        <td>cSnpSnp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CTglY</td>
        <td>cTglY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CTglZ</td>
        <td>cTglZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CTglSnp</td>
        <td>cTglSnp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::CTglTgl</td>
        <td>cTglTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::C1PtY</td>
        <td>c1PtY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::C1PtZ</td>
        <td>c1PtZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::C1PtSnp</td>
        <td>c1PtSnp</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::C1PtTgl</td>
        <td>c1PtTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::C1Pt21Pt2</td>
        <td>c1Pt21Pt2</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::TracksExtra</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::TrackExtra = o2::aod::TracksExtra::iterator</li>
        <li>o2::aod::FullTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra></li>
        <li>o2::aod::FullTrack = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra>::iterator</li>
        <li>o2::aod::BigTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra, o2::aod::HFSelTrack></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::track::TPCInnerParam</td>
        <td>tpcInnerParam</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Flags</td>
        <td>flags</td>
        <td>uint32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::ITSClusterMap</td>
        <td>itsClusterMap</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCNClsFindable</td>
        <td>tpcNClsFindable</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCNClsFindableMinusFound</td>
        <td>tpcNClsFindableMinusFound</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCNClsFindableMinusCrossedRows</td>
        <td>tpcNClsFindableMinusCrossedRows</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCNClsShared</td>
        <td>tpcNClsShared</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TRDPattern</td>
        <td>trdPattern</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::ITSChi2NCl</td>
        <td>itsChi2NCl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCChi2NCl</td>
        <td>tpcChi2NCl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TRDChi2</td>
        <td>trdChi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TOFChi2</td>
        <td>tofChi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCSignal</td>
        <td>tpcSignal</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TRDSignal</td>
        <td>trdSignal</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TOFSignal</td>
        <td>tofSignal</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::Length</td>
        <td>length</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TOFExpMom</td>
        <td>tofExpMom</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::PIDForTracking</td>
        <td>pidForTracking</td>
        <td>uint32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCNClsFound</td>
        <td>tpcNClsFound</td>
        <td>int16_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCNClsCrossedRows</td>
        <td>tpcNClsCrossedRows</td>
        <td>int16_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::ITSNCls</td>
        <td>itsNCls</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::ITSNClsInnerBarrel</td>
        <td>itsNClsInnerBarrel</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCCrossedRowsOverFindableCls</td>
        <td>tpcCrossedRowsOverFindableCls</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TPCFractionSharedCls</td>
        <td>tpcFractionSharedCls</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TrackEtaEMCAL</td>
        <td>trackEtaEmcal</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::TrackPhiEMCAL</td>
        <td>trackPhiEmcal</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredMFTTracks</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Tgl</td>
        <td>tgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Signed1Pt</td>
        <td>signed1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::NClusters</td>
        <td>nClusters</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::MFTTracks</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::MFTTrack = o2::aod::MFTTracks::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Tgl</td>
        <td>tgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Signed1Pt</td>
        <td>signed1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::NClusters</td>
        <td>nClusters</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Pt</td>
        <td>pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::P</td>
        <td>p</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredFwdTracks</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::TrackType</td>
        <td>trackType</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Tgl</td>
        <td>tgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Signed1Pt</td>
        <td>signed1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::NClusters</td>
        <td>nClusters</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::PDca</td>
        <td>pDca</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RAtAbsorberEnd</td>
        <td>rAtAbsorberEnd</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2MatchMCHMID</td>
        <td>chi2MatchMCHMID</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2MatchMCHMFT</td>
        <td>chi2MatchMCHMFT</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::MatchScoreMCHMFT</td>
        <td>matchScoreMCHMFT</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::MatchMFTTrackID</td>
        <td>matchMFTTrackID</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::MatchMCHTrackID</td>
        <td>matchMCHTrackID</td>
        <td>int</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::FwdTracks</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::FwdTrack = o2::aod::FwdTracks::iterator</li>
        <li>o2::aod::FullFwdTracks = soa::Join<o2::aod::FwdTracks, o2::aod::FwdTracksCov></li>
        <li>o2::aod::FullFwdTrack = soa::Join<o2::aod::FwdTracks, o2::aod::FwdTracksCov>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::TrackType</td>
        <td>trackType</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Tgl</td>
        <td>tgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Signed1Pt</td>
        <td>signed1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::NClusters</td>
        <td>nClusters</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::PDca</td>
        <td>pDca</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RAtAbsorberEnd</td>
        <td>rAtAbsorberEnd</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2MatchMCHMID</td>
        <td>chi2MatchMCHMID</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Chi2MatchMCHMFT</td>
        <td>chi2MatchMCHMFT</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::MatchScoreMCHMFT</td>
        <td>matchScoreMCHMFT</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::MatchMFTTrackID</td>
        <td>matchMFTTrackID</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::MatchMCHTrackID</td>
        <td>matchMCHTrackID</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Pt</td>
        <td>pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::P</td>
        <td>p</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredFwdTracksCov</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaX</td>
        <td>sigmaX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaY</td>
        <td>sigmaY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaPhi</td>
        <td>sigmaPhi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaTgl</td>
        <td>sigmaTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Sigma1Pt</td>
        <td>sigma1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoXY</td>
        <td>rhoXY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoPhiY</td>
        <td>rhoPhiY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoPhiX</td>
        <td>rhoPhiX</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoTglX</td>
        <td>rhoTglX</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoTglY</td>
        <td>rhoTglY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoTglPhi</td>
        <td>rhoTglPhi</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtX</td>
        <td>rho1PtX</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtY</td>
        <td>rho1PtY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtPhi</td>
        <td>rho1PtPhi</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtTgl</td>
        <td>rho1PtTgl</td>
        <td>int8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::FwdTracksCov</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::FwdTrackCovFwd = o2::aod::FwdTracksCov::iterator</li>
        <li>o2::aod::FullFwdTracks = soa::Join<o2::aod::FwdTracks, o2::aod::FwdTracksCov></li>
        <li>o2::aod::FullFwdTrack = soa::Join<o2::aod::FwdTracks, o2::aod::FwdTracksCov>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaX</td>
        <td>sigmaX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaY</td>
        <td>sigmaY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaPhi</td>
        <td>sigmaPhi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::SigmaTgl</td>
        <td>sigmaTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Sigma1Pt</td>
        <td>sigma1Pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoXY</td>
        <td>rhoXY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoPhiY</td>
        <td>rhoPhiY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoPhiX</td>
        <td>rhoPhiX</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoTglX</td>
        <td>rhoTglX</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoTglY</td>
        <td>rhoTglY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::RhoTglPhi</td>
        <td>rhoTglPhi</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtX</td>
        <td>rho1PtX</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtY</td>
        <td>rho1PtY</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtPhi</td>
        <td>rho1PtPhi</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::Rho1PtTgl</td>
        <td>rho1PtTgl</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CXX</td>
        <td>cXX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CXY</td>
        <td>cXY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CYY</td>
        <td>cYY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CPhiX</td>
        <td>cPhiX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CPhiY</td>
        <td>cPhiY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CPhiPhi</td>
        <td>cPhiPhi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CTglX</td>
        <td>cTglX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CTglY</td>
        <td>cTglY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CTglPhi</td>
        <td>cTglPhi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::CTglTgl</td>
        <td>cTglTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::C1PtX</td>
        <td>c1PtX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::C1PtY</td>
        <td>c1PtY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::C1PtPhi</td>
        <td>c1PtPhi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::C1PtTgl</td>
        <td>c1PtTgl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fwdtrack::C1Pt21Pt2</td>
        <td>c1Pt21Pt2</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::UnassignedTracks</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::UnassignedTrack = o2::aod::UnassignedTracks::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::unassignedtracks::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::unassignedtracks::TrackId</td>
        <td>trackId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::UnassignedMFTTracks</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::UnassignedMFTTrack = o2::aod::UnassignedMFTTracks::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::unassignedmfttracks::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::unassignedmfttracks::MFTTrackId</td>
        <td>mfttrackId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::HMPIDs</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::HMPID = o2::aod::HMPIDs::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::hmpid::TrackId</td>
        <td>trackId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::hmpid::HMPIDSignal</td>
        <td>hmpidSignal</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::hmpid::HMPIDDistance</td>
        <td>hmpidDistance</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::hmpid::HMPIDQMip</td>
        <td>hmpidQMip</td>
        <td>short</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Calos</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Calo = o2::aod::Calos::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::calo::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calo::CellNumber</td>
        <td>cellNumber</td>
        <td>int16_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calo::Amplitude</td>
        <td>amplitude</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calo::Time</td>
        <td>time</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calo::CellType</td>
        <td>cellType</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calo::CaloType</td>
        <td>caloType</td>
        <td>int8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::CaloTriggers</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::CaloTrigger = o2::aod::CaloTriggers::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::FastOrAbsId</td>
        <td>fastOrAbsId</td>
        <td>int32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::L0Amplitude</td>
        <td>l0Amplitude</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::L0Time</td>
        <td>l0Time</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::L1TimeSum</td>
        <td>l1TimeSum</td>
        <td>int32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::NL0Times</td>
        <td>nl0Times</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::TriggerBits</td>
        <td>triggerBits</td>
        <td>int32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::calotrigger::CaloType</td>
        <td>caloType</td>
        <td>int8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredMuons</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::muon::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::InverseBendingMomentum</td>
        <td>inverseBendingMomentum</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::ThetaX</td>
        <td>thetaX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::ThetaY</td>
        <td>thetaY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::ZMu</td>
        <td>zMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::BendingCoor</td>
        <td>bendingCoor</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::NonBendingCoor</td>
        <td>nonBendingCoor</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Covariances</td>
        <td>covariances</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Chi2MatchTrigger</td>
        <td>chi2MatchTrigger</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::RAtAbsorberEnd</td>
        <td>rAtAbsorberEnd</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::PDca</td>
        <td>pDca</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Muons</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Muon = o2::aod::Muons::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::muon::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::InverseBendingMomentum</td>
        <td>inverseBendingMomentum</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::ThetaX</td>
        <td>thetaX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::ThetaY</td>
        <td>thetaY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::ZMu</td>
        <td>zMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::BendingCoor</td>
        <td>bendingCoor</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::NonBendingCoor</td>
        <td>nonBendingCoor</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Covariances</td>
        <td>covariances</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Chi2MatchTrigger</td>
        <td>chi2MatchTrigger</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::RAtAbsorberEnd</td>
        <td>rAtAbsorberEnd</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::PDca</td>
        <td>pDca</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Sign</td>
        <td>sign</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Pt</td>
        <td>pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muon::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::MuonClusters</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::MuonCluster = o2::aod::MuonClusters::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::TrackId</td>
        <td>trackId</td>
        <td>int</td>
        <td>pointer into table Muons</td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::X</td>
        <td>x</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::Y</td>
        <td>y</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::Z</td>
        <td>z</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::ErrX</td>
        <td>errX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::ErrY</td>
        <td>errY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::Charge</td>
        <td>charge</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::muoncluster::Chi2</td>
        <td>chi2</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Zdcs</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Zdc = o2::aod::Zdcs::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergyZEM1</td>
        <td>energyZEM1</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergyZEM2</td>
        <td>energyZEM2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergyCommonZNA</td>
        <td>energyCommonZNA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergyCommonZNC</td>
        <td>energyCommonZNC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergyCommonZPA</td>
        <td>energyCommonZPA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergyCommonZPC</td>
        <td>energyCommonZPC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergySectorZNA</td>
        <td>energySectorZNA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergySectorZNC</td>
        <td>energySectorZNC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergySectorZPA</td>
        <td>energySectorZPA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::EnergySectorZPC</td>
        <td>energySectorZPC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::TimeZEM1</td>
        <td>timeZEM1</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::TimeZEM2</td>
        <td>timeZEM2</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::TimeZNA</td>
        <td>timeZNA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::TimeZNC</td>
        <td>timeZNC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::TimeZPA</td>
        <td>timeZPA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::zdc::TimeZPC</td>
        <td>timeZPC</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::FV0As</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::FV0A = o2::aod::FV0As::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0a::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0a::Amplitude</td>
        <td>amplitude</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0a::Time</td>
        <td>time</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0a::TriggerMask</td>
        <td>triggerMask</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::FV0Cs</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::FV0C = o2::aod::FV0Cs::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0c::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0c::Amplitude</td>
        <td>amplitude</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fv0c::Time</td>
        <td>time</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::FT0s</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::FT0 = o2::aod::FT0s::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::ft0::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::ft0::AmplitudeA</td>
        <td>amplitudeA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::ft0::AmplitudeC</td>
        <td>amplitudeC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::ft0::TimeA</td>
        <td>timeA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::ft0::TimeC</td>
        <td>timeC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::ft0::TriggerMask</td>
        <td>triggerMask</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::FDDs</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::FDD = o2::aod::FDDs::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fdd::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fdd::AmplitudeA</td>
        <td>amplitudeA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fdd::AmplitudeC</td>
        <td>amplitudeC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fdd::TimeA</td>
        <td>timeA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fdd::TimeC</td>
        <td>timeC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::fdd::TriggerMask</td>
        <td>triggerMask</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredV0s</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::V0s = soa::Join<o2::aod::TransientV0s, o2::aod::StoredV0s></li>
        <li>o2::aod::V0 = soa::Join<o2::aod::TransientV0s, o2::aod::StoredV0s>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::v0::PosTrackId</td>
        <td>posTrackId</td>
        <td>int</td>
        <td>pointer into table Tracks</td>
      </tr>
      <tr>
        <td>o2::aod::v0::NegTrackId</td>
        <td>negTrackId</td>
        <td>int</td>
        <td>pointer into table Tracks</td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::StoredCascades</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Cascades = soa::Join<o2::aod::TransientCascades, o2::aod::StoredCascades></li>
        <li>o2::aod::Cascade = soa::Join<o2::aod::TransientCascades, o2::aod::StoredCascades>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::cascade::V0Id</td>
        <td>v0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::cascade::BachelorId</td>
        <td>bachelorId</td>
        <td>int</td>
        <td>pointer into table Tracks</td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run2BCInfos</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Run2BCInfo = o2::aod::Run2BCInfos::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::run2::EventCuts</td>
        <td>eventCuts</td>
        <td>uint32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::run2::TriggerMaskNext50</td>
        <td>triggerMaskNext50</td>
        <td>uint64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::run2::SPDClustersL0</td>
        <td>spdClustersL0</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::run2::SPDClustersL1</td>
        <td>spdClustersL1</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::McCollisions</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::McCollision = o2::aod::McCollisions::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::GeneratorsID</td>
        <td>generatorsID</td>
        <td>short</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::PosX</td>
        <td>posX</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::PosY</td>
        <td>posY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::PosZ</td>
        <td>posZ</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::T</td>
        <td>t</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::Weight</td>
        <td>weight</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollision::ImpactParameter</td>
        <td>impactParameter</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::McParticles</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::McParticle = o2::aod::McParticles::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::McCollisionId</td>
        <td>mcCollisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::PdgCode</td>
        <td>pdgCode</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::StatusCode</td>
        <td>statusCode</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Flags</td>
        <td>flags</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Mother0</td>
        <td>mother0</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Mother1</td>
        <td>mother1</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Daughter0</td>
        <td>daughter0</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Daughter1</td>
        <td>daughter1</td>
        <td>int</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Weight</td>
        <td>weight</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Px</td>
        <td>px</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Py</td>
        <td>py</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Pz</td>
        <td>pz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::E</td>
        <td>e</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Vx</td>
        <td>vx</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Vy</td>
        <td>vy</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Vz</td>
        <td>vz</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Vt</td>
        <td>vt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::Pt</td>
        <td>pt</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mcparticle::ProducedByGenerator</td>
        <td>producedByGenerator</td>
        <td>bool</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::McTrackLabels</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::McTrackLabel = o2::aod::McTrackLabels::iterator</li>
        <li>o2::aod::BigTracksMC = soa::Join<o2::aod::BigTracks, o2::aod::McTrackLabels></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::mctracklabel::McParticleId</td>
        <td>mcParticleId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mctracklabel::McMask</td>
        <td>mcMask</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::McCaloLabels</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::McCaloLabel = o2::aod::McCaloLabels::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::mccalolabel::McParticleId</td>
        <td>mcParticleId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccalolabel::McMask</td>
        <td>mcMask</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::McCollisionLabels</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::McCollisionLabel = o2::aod::McCollisionLabels::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::mccollisionlabel::McCollisionId</td>
        <td>mcCollisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mccollisionlabel::McMask</td>
        <td>mcMask</td>
        <td>uint16_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run2MatchedExclusive</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0CId</td>
        <td>fv0cId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run2MatchedSparse</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::CollisionMatchedRun2Sparse = soa::Join<o2::aod::Collisions, o2::aod::Run2MatchedSparse>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0CId</td>
        <td>fv0cId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run3MatchedExclusive</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run3MatchedSparse</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::CollisionMatchedRun3Sparse = soa::Join<o2::aod::Collisions, o2::aod::Run3MatchedSparse>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::MatchedBCCollisionsExclusive</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::MatchedBCCollisionsSparse</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run3MatchedToBCExclusive</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run3MatchedToBCSparse</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Run2MatchedToBCSparse</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::indices::BCId</td>
        <td>bcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::ZdcId</td>
        <td>zdcId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FT0Id</td>
        <td>ft0Id</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0AId</td>
        <td>fv0aId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FV0CId</td>
        <td>fv0cId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::indices::FDDId</td>
        <td>fddId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

<a name=helper_tasks></a>
## List of tables created with helper tasks

The AO2D data files contain the basic set of data which is available for data analysis and from which other quantities are deduced. There are however quantities like PID information, V0 characteristics, etc. which are commonly used in analysis. In order to prevent that tasks to compute such quantities are repeatingly developed, a set of helper tasks is provided by the O2 framework. These tasks are listed below together with the tables they provide.

Click on the labels to display the table details.

####  o2-analysis-centrality-table
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Cents</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Cent = o2::aod::Cents::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::cent::CentV0M</td>
        <td>centV0M</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-emcal-correction-task
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::EMCALClusters</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::EMCALCluster = o2::aod::EMCALClusters::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::soa::Index</td>
        <td>index</td>
        <td>int64_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::emcalcluster::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::emcalcluster::Energy</td>
        <td>energy</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::emcalcluster::Eta</td>
        <td>eta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::emcalcluster::Phi</td>
        <td>phi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::emcalcluster::M02</td>
        <td>m02</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-event-selection
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::EvSels</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::EvSel = o2::aod::EvSels::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::evsel::Alias</td>
        <td>alias</td>
        <td>int32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBT0A</td>
        <td>bbT0A</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBT0C</td>
        <td>bbT0C</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBV0A</td>
        <td>bbV0A</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBV0C</td>
        <td>bbV0C</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGV0A</td>
        <td>bgV0A</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGV0C</td>
        <td>bgV0C</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBZNA</td>
        <td>bbZNA</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBZNC</td>
        <td>bbZNC</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBFDA</td>
        <td>bbFDA</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBFDC</td>
        <td>bbFDC</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGFDA</td>
        <td>bgFDA</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGFDC</td>
        <td>bgFDC</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::SEL7</td>
        <td>sel7</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::SEL8</td>
        <td>sel8</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::FoundFT0</td>
        <td>foundFT0</td>
        <td>int64_t</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::BcSels</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::BcSel = o2::aod::BcSels::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::evsel::Alias</td>
        <td>alias</td>
        <td>int32_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBT0A</td>
        <td>bbT0A</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBT0C</td>
        <td>bbT0C</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBV0A</td>
        <td>bbV0A</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBV0C</td>
        <td>bbV0C</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGV0A</td>
        <td>bgV0A</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGV0C</td>
        <td>bgV0C</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBZNA</td>
        <td>bbZNA</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBZNC</td>
        <td>bbZNC</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBFDA</td>
        <td>bbFDA</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BBFDC</td>
        <td>bbFDC</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGFDA</td>
        <td>bgFDA</td>
        <td>bool</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::evsel::BGFDC</td>
        <td>bgFDC</td>
        <td>bool</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-multiplicity-table
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Mults</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Mult = o2::aod::Mults::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::mult::MultV0A</td>
        <td>multV0A</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultV0C</td>
        <td>multV0C</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultT0A</td>
        <td>multT0A</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultT0C</td>
        <td>multT0C</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultZNA</td>
        <td>multZNA</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultZNC</td>
        <td>multZNC</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultV0M</td>
        <td>multV0M</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultT0M</td>
        <td>multT0M</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::mult::MultTracklets</td>
        <td>multTracklets</td>
        <td>int</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-pid-tof
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFbeta</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtofbeta::Beta</td>
        <td>beta</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtofbeta::BetaError</td>
        <td>betaerror</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtofbeta::ExpBetaEl</td>
        <td>expbetael</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtofbeta::ExpBetaElError</td>
        <td>expbetaelerror</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtofbeta::SeparationBetaEl</td>
        <td>separationbetael</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtofbeta::DiffBetaEl</td>
        <td>diffbetael</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOF</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::BigTracksPID = soa::Join<o2::aod::BigTracks, o2::aod::pidRespTPC, o2::aod::pidRespTOF></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffEl</td>
        <td>tofExpSignalDiffEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffMu</td>
        <td>tofExpSignalDiffMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffPi</td>
        <td>tofExpSignalDiffPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffKa</td>
        <td>tofExpSignalDiffKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffPr</td>
        <td>tofExpSignalDiffPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffDe</td>
        <td>tofExpSignalDiffDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffTr</td>
        <td>tofExpSignalDiffTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffHe</td>
        <td>tofExpSignalDiffHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffAl</td>
        <td>tofExpSignalDiffAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaEl</td>
        <td>tofExpSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaMu</td>
        <td>tofExpSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaPi</td>
        <td>tofExpSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaKa</td>
        <td>tofExpSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaPr</td>
        <td>tofExpSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaDe</td>
        <td>tofExpSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaTr</td>
        <td>tofExpSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaHe</td>
        <td>tofExpSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaAl</td>
        <td>tofExpSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaEl</td>
        <td>tofNSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaMu</td>
        <td>tofNSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaPi</td>
        <td>tofNSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaKa</td>
        <td>tofNSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaPr</td>
        <td>tofNSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaDe</td>
        <td>tofNSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaTr</td>
        <td>tofNSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaHe</td>
        <td>tofNSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaAl</td>
        <td>tofNSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-pid-tof-split
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFEl</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffEl</td>
        <td>tofExpSignalDiffEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaEl</td>
        <td>tofExpSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaEl</td>
        <td>tofNSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFMu</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffMu</td>
        <td>tofExpSignalDiffMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaMu</td>
        <td>tofExpSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaMu</td>
        <td>tofNSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFPi</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffPi</td>
        <td>tofExpSignalDiffPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaPi</td>
        <td>tofExpSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaPi</td>
        <td>tofNSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFKa</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffKa</td>
        <td>tofExpSignalDiffKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaKa</td>
        <td>tofExpSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaKa</td>
        <td>tofNSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFPr</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffPr</td>
        <td>tofExpSignalDiffPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaPr</td>
        <td>tofExpSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaPr</td>
        <td>tofNSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFDe</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffDe</td>
        <td>tofExpSignalDiffDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaDe</td>
        <td>tofExpSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaDe</td>
        <td>tofNSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFTr</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffTr</td>
        <td>tofExpSignalDiffTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaTr</td>
        <td>tofExpSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaTr</td>
        <td>tofNSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFHe</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffHe</td>
        <td>tofExpSignalDiffHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaHe</td>
        <td>tofExpSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaHe</td>
        <td>tofNSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTOFAl</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSignalDiffAl</td>
        <td>tofExpSignalDiffAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFExpSigmaAl</td>
        <td>tofExpSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtof::TOFNSigmaAl</td>
        <td>tofNSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-pid-tpc
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPC</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::BigTracksPID = soa::Join<o2::aod::BigTracks, o2::aod::pidRespTPC, o2::aod::pidRespTOF></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffEl</td>
        <td>tpcExpSignalDiffEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffMu</td>
        <td>tpcExpSignalDiffMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffPi</td>
        <td>tpcExpSignalDiffPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffKa</td>
        <td>tpcExpSignalDiffKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffPr</td>
        <td>tpcExpSignalDiffPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffDe</td>
        <td>tpcExpSignalDiffDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffTr</td>
        <td>tpcExpSignalDiffTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffHe</td>
        <td>tpcExpSignalDiffHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffAl</td>
        <td>tpcExpSignalDiffAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaEl</td>
        <td>tpcExpSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaMu</td>
        <td>tpcExpSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaPi</td>
        <td>tpcExpSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaKa</td>
        <td>tpcExpSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaPr</td>
        <td>tpcExpSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaDe</td>
        <td>tpcExpSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaTr</td>
        <td>tpcExpSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaHe</td>
        <td>tpcExpSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaAl</td>
        <td>tpcExpSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaEl</td>
        <td>tpcNSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaMu</td>
        <td>tpcNSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaPi</td>
        <td>tpcNSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaKa</td>
        <td>tpcNSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaPr</td>
        <td>tpcNSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaDe</td>
        <td>tpcNSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaTr</td>
        <td>tpcNSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaHe</td>
        <td>tpcNSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaAl</td>
        <td>tpcNSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-pid-tpc-split
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCEl</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffEl</td>
        <td>tpcExpSignalDiffEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaEl</td>
        <td>tpcExpSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaEl</td>
        <td>tpcNSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCMu</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffMu</td>
        <td>tpcExpSignalDiffMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaMu</td>
        <td>tpcExpSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaMu</td>
        <td>tpcNSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCPi</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffPi</td>
        <td>tpcExpSignalDiffPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaPi</td>
        <td>tpcExpSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaPi</td>
        <td>tpcNSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCKa</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffKa</td>
        <td>tpcExpSignalDiffKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaKa</td>
        <td>tpcExpSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaKa</td>
        <td>tpcNSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCPr</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffPr</td>
        <td>tpcExpSignalDiffPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaPr</td>
        <td>tpcExpSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaPr</td>
        <td>tpcNSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCDe</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffDe</td>
        <td>tpcExpSignalDiffDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaDe</td>
        <td>tpcExpSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaDe</td>
        <td>tpcNSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTr</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffTr</td>
        <td>tpcExpSignalDiffTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaTr</td>
        <td>tpcExpSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaTr</td>
        <td>tpcNSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCHe</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffHe</td>
        <td>tpcExpSignalDiffHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaHe</td>
        <td>tpcExpSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaHe</td>
        <td>tpcNSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCAl</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSignalDiffAl</td>
        <td>tpcExpSignalDiffAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCExpSigmaAl</td>
        <td>tpcExpSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc::TPCNSigmaAl</td>
        <td>tpcNSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-pid-tpc-tiny
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTEl</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreEl</td>
        <td>tpcNSigmaStoreEl</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaEl</td>
        <td>tpcNSigmaEl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTMu</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreMu</td>
        <td>tpcNSigmaStoreMu</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaMu</td>
        <td>tpcNSigmaMu</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTPi</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStorePi</td>
        <td>tpcNSigmaStorePi</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaPi</td>
        <td>tpcNSigmaPi</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTKa</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreKa</td>
        <td>tpcNSigmaStoreKa</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaKa</td>
        <td>tpcNSigmaKa</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTPr</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStorePr</td>
        <td>tpcNSigmaStorePr</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaPr</td>
        <td>tpcNSigmaPr</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTDe</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreDe</td>
        <td>tpcNSigmaStoreDe</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaDe</td>
        <td>tpcNSigmaDe</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTTr</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreTr</td>
        <td>tpcNSigmaStoreTr</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaTr</td>
        <td>tpcNSigmaTr</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTHe</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreHe</td>
        <td>tpcNSigmaStoreHe</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaHe</td>
        <td>tpcNSigmaHe</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::pidRespTPCTAl</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaStoreAl</td>
        <td>tpcNSigmaStoreAl</td>
        <td>int8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::pidtpc_tiny::TPCNSigmaAl</td>
        <td>tpcNSigmaAl</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-timestamp
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::Timestamps</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::BCsWithTimestamps = soa::Join<o2::aod::BCs, o2::aod::Timestamps></li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::timestamp::Timestamp</td>
        <td>timestamp</td>
        <td>uint64_t</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-trackextension
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::TracksExtended</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::track::DcaXY</td>
        <td>dcaXY</td>
        <td>float</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::DcaZ</td>
        <td>dcaZ</td>
        <td>float</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-trackselection
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::TrackSelection</button>
  <div class="panel">
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::track::IsGlobalTrack</td>
        <td>isGlobalTrack</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
      <tr>
        <td>o2::aod::track::IsGlobalTrackSDD</td>
        <td>isGlobalTrackSDD</td>
        <td>uint8_t</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

####  o2-analysis-weak-decay-indices
<div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::TransientV0s</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::V0s = soa::Join<o2::aod::TransientV0s, o2::aod::StoredV0s></li>
        <li>o2::aod::V0 = soa::Join<o2::aod::TransientV0s, o2::aod::StoredV0s>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::v0::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

  <button class="myaccordion"><i class="fa fa-table"></i> o2::aod::TransientCascades</button>
  <div class="panel">
    <div>Is used in:
      <ul>
        <li>o2::aod::Cascades = soa::Join<o2::aod::TransientCascades, o2::aod::StoredCascades></li>
        <li>o2::aod::Cascade = soa::Join<o2::aod::TransientCascades, o2::aod::StoredCascades>::iterator</li>
      </ul>
    </div>
    <table class=DataModel>
      <tr>
        <th>Column</th>
        <th>Name</th>
        <th>Type</th>
        <th>Comment</th>
      </tr>
      <tr>
        <td>o2::aod::cascade::CollisionId</td>
        <td>collisionId</td>
        <td>int32</td>
        <td></td>
      </tr>
    </table>
  </div>

</div>

<a name="usings"></a>
## List of defined joins and iterators
<div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::BC</button>
  <div class="panel">
    <ul>
        <li>o2::aod::BC = o2::aod::BCs::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::BCsWithTimestamps</button>
  <div class="panel">
    <ul>
        <li>o2::aod::BCsWithTimestamps = soa::Join<o2::aod::BCs, o2::aod::Timestamps></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Collision</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Collision = o2::aod::Collisions::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Track</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Track = o2::aod::Tracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::TrackCov</button>
  <div class="panel">
    <ul>
        <li>o2::aod::TrackCov = o2::aod::TracksCov::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::TrackExtra</button>
  <div class="panel">
    <ul>
        <li>o2::aod::TrackExtra = o2::aod::TracksExtra::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FullTracks</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FullTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FullTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FullTrack = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra>::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::MFTTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::MFTTrack = o2::aod::MFTTracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FwdTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FwdTrack = o2::aod::FwdTracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FwdTrackCovFwd</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FwdTrackCovFwd = o2::aod::FwdTracksCov::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FullFwdTracks</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FullFwdTracks = soa::Join<o2::aod::FwdTracks, o2::aod::FwdTracksCov></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FullFwdTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FullFwdTrack = soa::Join<o2::aod::FwdTracks, o2::aod::FwdTracksCov>::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::UnassignedTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::UnassignedTrack = o2::aod::UnassignedTracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::UnassignedMFTTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::UnassignedMFTTrack = o2::aod::UnassignedMFTTracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::HMPID</button>
  <div class="panel">
    <ul>
        <li>o2::aod::HMPID = o2::aod::HMPIDs::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Calo</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Calo = o2::aod::Calos::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CaloTrigger</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CaloTrigger = o2::aod::CaloTriggers::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Muon</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Muon = o2::aod::Muons::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::MuonCluster</button>
  <div class="panel">
    <ul>
        <li>o2::aod::MuonCluster = o2::aod::MuonClusters::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Zdc</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Zdc = o2::aod::Zdcs::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FV0A</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FV0A = o2::aod::FV0As::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FV0C</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FV0C = o2::aod::FV0Cs::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FT0</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FT0 = o2::aod::FT0s::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::FDD</button>
  <div class="panel">
    <ul>
        <li>o2::aod::FDD = o2::aod::FDDs::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::V0s</button>
  <div class="panel">
    <ul>
        <li>o2::aod::V0s = soa::Join<o2::aod::TransientV0s, o2::aod::StoredV0s></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::V0</button>
  <div class="panel">
    <ul>
        <li>o2::aod::V0 = soa::Join<o2::aod::TransientV0s, o2::aod::StoredV0s>::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Cascades</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Cascades = soa::Join<o2::aod::TransientCascades, o2::aod::StoredCascades></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Cascade</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Cascade = soa::Join<o2::aod::TransientCascades, o2::aod::StoredCascades>::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Run2BCInfo</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Run2BCInfo = o2::aod::Run2BCInfos::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::McCollision</button>
  <div class="panel">
    <ul>
        <li>o2::aod::McCollision = o2::aod::McCollisions::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::McParticle</button>
  <div class="panel">
    <ul>
        <li>o2::aod::McParticle = o2::aod::McParticles::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::McTrackLabel</button>
  <div class="panel">
    <ul>
        <li>o2::aod::McTrackLabel = o2::aod::McTrackLabels::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::McCaloLabel</button>
  <div class="panel">
    <ul>
        <li>o2::aod::McCaloLabel = o2::aod::McCaloLabels::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::McCollisionLabel</button>
  <div class="panel">
    <ul>
        <li>o2::aod::McCollisionLabel = o2::aod::McCollisionLabels::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CollisionMatchedRun2Sparse</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CollisionMatchedRun2Sparse = soa::Join<o2::aod::Collisions, o2::aod::Run2MatchedSparse>::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CollisionMatchedRun3Sparse</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CollisionMatchedRun3Sparse = soa::Join<o2::aod::Collisions, o2::aod::Run3MatchedSparse>::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Cent</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Cent = o2::aod::Cents::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CFCollision</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CFCollision = o2::aod::CFCollisions::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CFTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CFTrack = o2::aod::CFTracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::EMCALCluster</button>
  <div class="panel">
    <ul>
        <li>o2::aod::EMCALCluster = o2::aod::EMCALClusters::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::EvSel</button>
  <div class="panel">
    <ul>
        <li>o2::aod::EvSel = o2::aod::EvSels::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::BcSel</button>
  <div class="panel">
    <ul>
        <li>o2::aod::BcSel = o2::aod::BcSels::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::BigTracks</button>
  <div class="panel">
    <ul>
        <li>o2::aod::BigTracks = soa::Join<o2::aod::Tracks, o2::aod::TracksCov, o2::aod::TracksExtra, o2::aod::HFSelTrack></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::BigTracksMC</button>
  <div class="panel">
    <ul>
        <li>o2::aod::BigTracksMC = soa::Join<o2::aod::BigTracks, o2::aod::McTrackLabels></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::BigTracksPID</button>
  <div class="panel">
    <ul>
        <li>o2::aod::BigTracksPID = soa::Join<o2::aod::BigTracks, o2::aod::pidRespTPC, o2::aod::pidRespTOF></li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::HfCandProng2</button>
  <div class="panel">
    <ul>
        <li>o2::aod::HfCandProng2 = o2::aod::HfCandProng2Ext</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::HfCandProng3</button>
  <div class="panel">
    <ul>
        <li>o2::aod::HfCandProng3 = o2::aod::HfCandProng3Ext</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Jet</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Jet = o2::aod::Jets::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::JetConstituent</button>
  <div class="panel">
    <ul>
        <li>o2::aod::JetConstituent = o2::aod::JetConstituents::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::JetConstituentSub</button>
  <div class="panel">
    <ul>
        <li>o2::aod::JetConstituentSub = o2::aod::JetConstituentsSub::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Mult</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Mult = o2::aod::Mults::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedEvent</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedEvent = o2::aod::ReducedEvents::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedEventExtended</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedEventExtended = o2::aod::ReducedEventsExtended::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedEventVtxCov</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedEventVtxCov = o2::aod::ReducedEventsVtxCov::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedTrack</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedTrack = o2::aod::ReducedTracks::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedTrackBarrel</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedTrackBarrel = o2::aod::ReducedTracksBarrel::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedTrackBarrelCov</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedTrackBarrelCov = o2::aod::ReducedTracksBarrelCov::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedTrackBarrelPID</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedTrackBarrelPID = o2::aod::ReducedTracksBarrelPID::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedMuon</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedMuon = o2::aod::ReducedMuons::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::ReducedMuonExtended</button>
  <div class="panel">
    <ul>
        <li>o2::aod::ReducedMuonExtended = o2::aod::ReducedMuonsExtended::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::Dilepton</button>
  <div class="panel">
    <ul>
        <li>o2::aod::Dilepton = o2::aod::Dileptons::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::V0Data</button>
  <div class="panel">
    <ul>
        <li>o2::aod::V0Data = o2::aod::V0Datas::iterator</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CascDataOrigin</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CascDataOrigin = o2::aod::CascData</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::aod::CascDataFull</button>
  <div class="panel">
    <ul>
        <li>o2::aod::CascDataFull = o2::aod::CascDataExt</li>
    </ul>
  </div>

  <button class="myaccordion"><i class="fa fa-map-pin"></i> o2::pid::pidvar_t</button>
  <div class="panel">
    <ul>
        <li>o2::pid::pidvar_t = o2::pid::float</li>
    </ul>
  </div>
</div>
