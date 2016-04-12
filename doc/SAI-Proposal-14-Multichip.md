Switch Abstraction Interface Change Proposal
=====================

Title    | Multichip support
-------- | ---
Authors  | DELL & Microsoft
Status   | In review
Type     | Standards track
Created  | 04/12/2016
SAI-Version | 0.9.5


----------

## Overview

This document describe the approach to extend SAI to support multichip system. [Define multichip system here].

There are two approach to support multichip in SAI. One approach to abstract the multiple chip system as a single chip system and only expose single chip through the SAI. Then the underlying SAI library will need to setup the multichip and populate the tables on different chips. This approach adds complexity into the SAI library and also lose flexibility to setup the multi chip in different ways.

The other approach is to expose multi chips through the SAI and allow user to control each individual chip separately. This approach gives user maximum flexibility and add little complexity in SAI. 

This document focuses on providing multichip via the second approach. In this approach, SAI needs to be extended to add following support:

- **Enumerate multichip in the system**: SAI needs to provide API to allow user to enumerate multichip in the system. Besides, usually in the chassis system, module can be added or removed dynamically. Thus, notification needs to be provided when chips been added or removed.

- **Create SAI object on a specified chip in the system**: SAI needs to provide API to create SAI object on a specified chip. This can be achieved by adding a switch unit attribute to the SAI object and allow user to specify the attribute on the creation function call. However, since certain SAI objects are contained within other SAI objects, e.g., ports are contained within a switch object, queues are contained within a port object, only the root SAI object needs to be added with this unit attribute.

- **Reference remote SAI object in local SAI object**: In certain multichip system, remote SAI object can be directly referenced by a local SAI object, e.g., an local FDB entry can pointing to a remote port in another chip. Since each SAI object is identify via a UOID and this UOID should be unique across multichip system, the referencing a SAI object in a remote unit is allowed through the SAI API. However, whether such referencing is supported by the multi-chip system is decided by the SAI implementation. Meanwhile, to support such referencing, new attribute could be added to existing objects to put them into a special mode, e.g., trunking port mode.

## Spec

### Enumuate multichip in the system (TBD)

### Unit attribute

Following SAI objects (initial list, need further checks) need to add switch unit attribute (SAI\_OBJECT\_ATTR\_UNIT [sai\_uint\_16])

- SWITCH
- VIRTUAL_ROUTER
- VLAN
- STP
- ACL
- BUFFER_POOL
- NEXTHOPGROUP
- ACL_TABLE
- ACL_RANGE
- MIRROR
- SAMPLEPACKET
- WRED
- SCHEDULER
- SCHEDULER_GROUP
- UDF_GROUP
- UDF_MATCH
- HASH
- TUNNEL

Note:

- For backward compatibility, the SAI_OBJECT_ATTR_UNIT will have default value set to 0.
- Change VLAN to UOID. Since each chip can have its own vlan, to differentiate VLAN object on different chips, we need to use UOID to identify VLAN object.

### Remote SAI object referencing

New trunk port mode to be added to port.
