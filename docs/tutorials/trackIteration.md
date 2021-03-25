---
sort: 2
title: TrackIteration
---

# Looping over tracks

```goal
Learn how to access the tracks and their measured quantities.
```

source: <a href="https://github.com/AliceO2Group/AliceO2/blob/dev/Analysis/Tutorials/src/trackIteration.cxx" target="_blank">trackIteration.cxx</a>

<a name="atask"></a>
### ATask

Information about the tracks is contained in the tables `Tracks`, `TracksCov`, and `TracksExtra`. The respective iterators are defined as `Track`, `TrackCov`, and `TrackExtra`.

To loop over all available tracks contained in the input files subscribe to the iterator `Track`. 

```cpp
void process(Track const& track)
{
  // process the track `track` of type `Track`
  LOGF (INFO, "Momentum: %f",track.p());
}
```

In this case the variable `track` inside the process function is of type `Track`
which has a number of data members. Here we access the momentum P and print it
out. For a comprehensive list of data items included in the O2 data model see <a
href="/docs/framework/datamodel.html" target="_blank">The Data Model</a> section
of these documentation pages. 

The `Tracks` table only contains part of the available track information. In order to simulatneously access information of several tables, the tables can be joined using `soa::Join<>`.

To loop over all available tracks and having simultaneous access to the `Tracks` and `TracksExtra` information you could e.g. do

```cpp
void process(soa::Join<aod::Track, aod::TrackExtra> const& joinedTrack)
{
  // process the track `joinedTrack` of type `soa::Join<aod::Track, aod::TrackExtra>`

}
```

In this way also all three track tables could be joined. However, for this one can use the abbreviation `FullTrack`, which is a predefined join of all three track tables. A list of predefined joins is available in <a href="/docs/framework/datamodel.html" target="_blank">The Data Model</a> section of these documentation pages). 

```cpp
void process(aod::fullTrack const& fullTrack)
{
  // process the track `fullTrack` of type `o2::aod::fullTrack`
  // type `aod::fullTrack` is equal to ` soa::Join<aod::Track, aod::TrackCov, aod::TrackExtra>`

}
```

<a name="btask"></a>
### BTask

In the above <a href="#atask">example</a> the processing runs over all tracks of the input files. This is achieved by using the iterator version `Track` of table `Tracks`.
A run3 analysis however is more likely based on data frames and thus looping over data frames will often be required. This is achieved by subscribing to table `Tracks` or to any join of the track tables.

```cpp
// loop over data frames
void process(aod::Tracks const& tracks)
{

  // `tracks` is of type `o2::aod::Tracks`
  // and contains all tracks of a data frame
  
  // to loop over the tracks do
  for (auto track : tracks) {
  
    // process the track
    
  }
}
```
