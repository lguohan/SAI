#if !defined(__SAIIPMC_H_)
#define __SAIIPMC_H_

#include <saitypes.h>

/**
 *  IP multicast entry key
 */
typedef struct _sai_ipmc_entry_t
{
    sai_object_id_t vr_id;
    sai_ip_address_t source;
    sai_ip_prefix_t  group;
} sai_ipmc_entry_t;

/**
 *  Attribute Id for IP multicast entry
 */
typedef enum _sai_ipmc_entry_attr_t
{
    /** READ */

    /** READ-WRITE */

    /** Packet action [sai_packet_action_t]
     * (default to SAI_PACKET_ACTION_FORWARD) */
    SAI_IPMC_ATTR_PACKET_ACTION,

    /** Packet priority for trap/log actions [uint8_t]
     * (default to 0) */
    SAI_IPMC_ATTR_TRAP_PRIORITY,

    /** Output router interface list [sai_object_list_t] */
    SAI_IPMC_ATTR_OUTPUT_ROUTER_INTERFACE_LIST,

    /** RPF router interface list [sai_object_list_t] */
    SAI_IPMC_ATTR_RPF_ROUTER_INTERFACE_LIST,

    /** Custom range base value */
    SAI_IPMC_ATTR_CUSTOM_RANGE_BASE  = 0x10000000
} sai_ipmc_entry_attr_t;

/**
 *  IPMC event type
 */
typedef enum sai_ipmc_event_t
{
    /** IPMC entry aged */
    SAI_IPMC_EVENT_AGED,
} sai_ipmc_event_t;

/**
 * Routine Description:
 *    Create IP multicast entry
 *
 * Arguments:
 *    [in] ipmc_entry - IP multicast entry
 *    [in] attr_count - number of attributes
 *    [in] attr_list - array of attributes
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_create_ipmc_entry_fn)(
    _In_ const sai_ipmc_entry_t* ipmc_entry,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
    );

/**
 * Routine Description:
 *    Remove IP multicast entry
 *
 * Arguments:
 *    [in] ipmc_entry - IP multicast entry
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_remove_ipmc_entry_fn)(
    _In_ const sai_ipmc_entry_t* ipmc_entry
    );

/**
 * Routine Description:
 *    Set IP multicast entry attribute value
 *
 * Arguments:
 *    [in] IP multicast - IP multicast entry
 *    [in] attr - attribute
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_set_ipmc_entry_attribute_fn)(
    _In_ const sai_ipmc_entry_t* ipmc_entry,
    _In_ const sai_attribute_t *attr
    );

/**
 * Routine Description:
 *    Get IP multicast entry attribute value
 *
 * Arguments:
 *    [in] ipmc_entry - IP multicast entry
 *    [in] attr_count - number of attributes
 *    [inout] attr_list - array of attributes
 *
 * Return Values:
 *    SAI_STATUS_SUCCESS on success
 *    Failure status code on error
 */
typedef sai_status_t (*sai_get_ipmc_entry_attribute_fn)(
    _In_ const sai_ipmc_entry_t* ipmc_entry,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
    );

/**
 * IP multicast method table retrieved with sai_api_query()
 */
typedef struct _sai_ipmc_api_t
{
    sai_create_ipmc_entry_fn              create_ipmc_entry;
    sai_remove_ipmc_entry_fn              remove_ipmc_entry;
    sai_set_ipmc_entry_attribute_fn       set_ipmc_entry_attribute;
    sai_get_ipmc_entry_attribute_fn       get_ipmc_entry_attribute;
} sai_ipmc_api_t;

#endif // __SAIIPMC_H_
