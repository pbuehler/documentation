---
sort: 5
title: Creating Tables
---

# Creating and Modifying tables 


```goal
Learn how to create new tables, extend existing tables with additional columns and have them saved to disk.
```
source: <a href="https://github.com/AliceO2Group/AliceO2/blob/dev/Analysis/Tutorials/src/histograms.cxx" target="_blank">newCollections.cxx</a>

Before we come to discussing the tutorial [code](#atask) a few general words about creating tables.

<a name="declareTables"></a>
### Declaration of tables

The O2 framework provides a few methods to declare tables in analysis tasks. See the list below. Click on the titles to display information about the arguments and the resulting tables.

All methods have a `Name` and `Description` argument. The argument Name is used to define the type of the table and is `o2::aod::Name`. The Description argument is a string which is used within the framework to identify the table. It has a maximum length of 16 characters.

<div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_TABLE</button>
  <div class="panel">
    <div>
      DECLARE_SOA_TABLE(Name, Origin, Description, ...);
      <div>
        Declares a table of type `Name` with the columns specified in the argument list. The columns are specfied as a comma separated list of column types.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_EXTENDED_TABLE_USER</button>
  <div class="panel">
    <div>
      DECLARE_SOA_EXTENDED_TABLE_USER(Name, Table, Description, ...);
      <div>
        Declares a table of type `Name` which contains the columns of table `Table` and in addition the columns specified in the argument list.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_INDEX_TABLE_USER</button>
  <div class="panel">
    <div>
      DECLARE_SOA_INDEX_TABLE_USER(Name, Key, Description, ...);
      <div>
      
      </div>
    </div>
  </div>


  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_INDEX_TABLE_EXCLUSIVE_USER</button>
  <div class="panel">
    <div>
      DECLARE_SOA_INDEX_TABLE_EXCLUSIVE_USER(Name, Key, Description, ...);
      <div>
      </div>
    </div>
  </div>

</div>

<a name="declareColumns"></a>
### Declaration of columns

Tables are basically collections of columns. The O2 framework provides the methods to declare columns, which are listed below. Click on the titles to display information about the arguments and the resulting columns.

`Name` and `Getter` are the common arguments of all methods. Name is used to
define the type of the column which is `namespace::Name` where namespace is the
namespace the column is declared in. Getter is the method which allows to access
a column (tab.pt() e.g. gets the column which was declared with a Getter value
equal to pt of a table tab).

<div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_COLUMN_FULL</button>
  <div class="panel">
    <div>
      DECLARE_SOA_COLUMN_FULL(Name, Getter, Type, Label);
      <div>
        Dcelares a column of type `Name`. The elements are of type `Type` and the function to access the column is `Getter`(). The column is given a label `Label` which is used within the framework to identify the column.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_COLUMN</button>
  <div class="panel">
    <div>
      DECLARE_SOA_COLUMN(Name, Getter, Type);
      <div>
        Same as DECLARE_SOA_COLUMN_FULL but here the label is by default set to `Name`.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_EXPRESSION_COLUMN_FULL</button>
  <div class="panel">
    <div>
      DECLARE_SOA_EXPRESSION_COLUMN_FULL(Name, Getter, Type, Label, Expression);
      <div>
        Same as DECLARE_SOA_COLUMN_FULL but here the column element values are computed according to the expression `Expression`.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_EXPRESSION_COLUMN</button>
  <div class="panel">
    <div>
      DECLARE_SOA_EXPRESSION_COLUMN(Name, Getter, Type, Expression);
      <div>
        Same as DECLARE_SOA_EXPRESSION_COLUMN_FULL but here the label is by default set to `Name`.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_INDEX_COLUMN_FULL</button>
  <div class="panel">
    <div>
      DECLARE_SOA_INDEX_COLUMN_FULL(Name, Getter, Type, Table, Suffix);
      <div>
        Declares an index column of type `Name`Id to elements of the existing table `Table`s. The column elements are of type `Type` and can be retrieved with the method `Getter`(). `Suffix` can be used to distinguish several index columns to the same table. The label which is used within the framework to identify the column is set to fIndex`Table``Suffix`. If `Suffix` is not empty it must start with an underscore!
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_INDEX_COLUMN</button>
  <div class="panel">
    <div>
      DECLARE_SOA_INDEX_COLUMN_FULL(Name, Getter);
      <div>
        Same as DECLARE_SOA_INDEX_COLUMN_FULL but here element type is by default set to int_32, the referencing table to `Name`s, and the label which is used within the framework to identify the column is accrodingly set to fIndex`Name`.
      </div>
    </div>
  </div>

  <button class="myaccordion"><i class="fa fa-code"></i> DECLARE_SOA_DYNAMIC_COLUMN</button>
  <div class="panel">
    <div>
      DECLARE_SOA_DYNAMIC_COLUMN(Name, Getter, ...);
      <div>
        Similar to DECLARE_SOA_COLUMN but here the column element values are computed with the lambda which is provided as third argument to the declaration. The lambda also determines the type of the elements.
      </div>
    </div>
  </div>

</div>


<a name="atask"></a>
### ATask

In order to avoid naming conflicts between different tasks it is advicable to declare new columns in subspaces of the namespace o2::aod and the new tables in namespace o2::aod. 

```cpp
// declare columns in a sub-namespace of o2::aod
// and tables in namespace o2::aod
namespace o2::aod
{
namespace etaphi
{
DECLARE_SOA_COLUMN(Eta, eta, float);
DECLARE_SOA_COLUMN(Phi, phi, float);
} // namespace etaphi
DECLARE_SOA_TABLE(EtaPhi, "AOD", "ETAPHI",
                  etaphi::Eta, etaphi::Phi);
} // namespace o2::aod
```
Now that the table is defined we can use it to create a corresponding table object. This happens with the Produces class. Produces is a templated class and takes the table type to create as template argument. The table type in this case is aod::EtaPhi and the actual table object is etaphi.

The filling of the table etaphi is done with the method (... ) which takes as many arguments as columns are available.

```cpp
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
```
<a name="btask"></a>
### BTask and CTask

Within all tasks of a workflow the such created and filled table is available and hence can be use for further calculations. This is demonstrated with BTask and CTask of this tutorial.

<a name="dtask"></a>
### DTask

