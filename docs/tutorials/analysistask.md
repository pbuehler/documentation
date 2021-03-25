---
sort: 1
title: Analysis Task
---

# Basic ingredients of an analysis task

```goal
This explains the basic blocks and structures an analysis task in O2 is built of.
```

## License agreement

At the very beginning of each analysis task we recommend to but the following license agreement. The task will also run without, but with these lines you confirm that your program is
<a href="https://www.gnu.org/philosophy/free-sw.html" target="_blank">free software</a>. You can find the full O2 license information <a href="https://alice-o2-project.web.cern.ch/license" target="_blank">here</a>.

`License agreement`
```cpp
// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
```

## Header files

The exact list of header files needed to be included in a task depends on the content of the task. There are however two which are needed in any case.

`Required header files`
```cpp
#include "Framework/runDataProcessing.h"
#include "Framework/AnalysisTask.h"
```

## Namespace

Namespaces provide a method for preventing name conflicts in large projects. The O2 analysis framework also uses namespaces. Use the namespaces `o2` and `o2::framework` in any analysis task and add more if needed.

`O2 basic name spaces`
```cpp
using namespace o2;
using namespace o2::framework;
```

```note
The tables of the ALICE O2 analysis data model reside in the namespace o2::aod. Thus e.g. the full specifier of the table Tracks is o2::aod::Tracks. Within the namespace o2 this hence becomes aod::Tracks.
```

## Tasks, workflows, data analysis

A task is a basic block of an analysis program. Several tasks can be put together to form a worklow. Workflows on the other hand can be chained - the output of one workflow is piped to the input of the other workflow.

This is discussed in more detail in the [Data Processing ](/docs/framework/framework.html#creating-tasks-to-process-the-data) section of these documentation pages.
