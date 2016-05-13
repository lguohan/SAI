#if !defined(__SAIL2MC_H_)
#define __SAIL2MC_H_

#include <saitypes.h>

/**
 *  L2 multicast entry key
 */
typedef struct _sai_l2mc_entry_t
{
    sai_vlan_id_t vlan_id;
    sai_ip_address_t source;
    sai_ip_address_t group;
} sai_l2mc_entry_t;

/**
 *  Attribute Id for L2 multicast entry
 */
typedef enum _sai_l2mc_entry_attr_t
{
    /** READ */

    /** READ-WRITE */

    /** Packet action [sai_packet_action_t]
     * (default to SAI_PACKET_ACTION_FORWARD) */
    SAI_L2MC_ATTR_PACKET_ACTION,

    /** Packet priority for trap/log actions [uint8_t]
     * (default to 0) */
    SAI_L2MC_ATTR_TRAP_PRIORITY,

    /** SAI port list [sai_object_id_t] (CREATE_AND_SET) */
    SAI_L2MC_ATTR_PORT_LIST,

    /** Custom range base value */
    SAI_L2MC_ATTR_CUSTOM_RANGE_BASE  = 0x10000000
} sai_l2mc_entry_attr_t;

/**
 * Routine Description:
 *    Create L2 multicast entry
 *
 * Arguments:
 *    [in] l2mc_entry - L2 multicast entry
 *    [in] attr_count - number of attributes
 *    [in] attr_list - array of attributes
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_create_l2mc_entry_fn)(
    _In_ const sai_l2mc_entry_t *l2mc_entry,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
    );

/**
 * Routine Description:
 *    Remove L2 multicast entry
 *
 * Arguments:
 *    [in] l2mc_entry - L2 multicast entry
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_remove_l2mc_entry_fn)(
    _In_ const sai_l2mc_entry_t *l2mc_entry
    );

/**
 * Routine Description:
 *    Set L2 multicast entry attribute value
 *
 * Arguments:
 *    [in] l2mc_entry - L2 multicast entry
 *    [in] attr - attribute
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_set_l2mc_entry_attribute_fn)(
    _In_ const sai_l2mc_entry_t *l2mc_entry,
    _In_ const sai_attribute_t *attr
    );

/**
 * Routine Description:
 *    Get L2 multicast entry attribute value
 *
 * Arguments:
 *    [in] l2mc_entry - L2 multicast entry
 *    [in] attr_count - number of attributes
 *    [inout] attr_list - array of attributes
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_get_l2mc_entry_attribute_fn)(
    _In_ const sai_l2mc_entry_t *l2mc_entry,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
    );

/**
 * Routine Description:
 *    Add ports to L2 multicast
 *
 * Arguments:
 *    [in] l2mc_entry - L2 multicast entry
 *    [in] port_count - number of ports
 *    [in] port_list  - port list
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_add_ports_to_l2mc_entry_fn)(
    _In_ const sai_l2mc_entry_t *l2mc_entry,
    _In_ uint32_t port_count,
    _In_ const sai_object_list_t *port_list
    );

/**
 * Routine Description:
 *    Remove ports from L2 multicast
 *
 * Arguments:
 *    [in] l2mc_entry - L2 multicast entry
 *    [in] port_count - number of ports
 *    [in] port_list  - port list
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_remove_ports_from_l2mc_entry_fn)(
    _In_ const sai_l2mc_entry_t *l2mc_entry,
    _In_ uint32_t port_count,
    _In_ const sai_object_list_t *port_list
    );

/**
 * L2 multicast method table retrieved with sai_api_query()
 */
typedef struct _sai_l2mc_api_t
{
    sai_create_l2mc_entry_fn              create_l2mc_entry;
    sai_remove_l2mc_entry_fn              remove_l2mc_entry;
    sai_set_l2mc_entry_attribute_fn       set_l2mc_entry_attribute;
    sai_get_l2mc_entry_attribute_fn       get_l2mc_entry_attribute;
    sai_add_ports_to_l2mc_entry_fn        add_ports_to_l2mc_entry;
    sai_remove_ports_from_l2mc_entry_fn   remove_ports_from_l2mc_entry;
} sai_l2mc_api_t;

#endif // __SAIL2MC_H_
