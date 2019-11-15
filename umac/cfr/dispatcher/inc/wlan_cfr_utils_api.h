/*
 * Copyright (c) 2019 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _WLAN_CFR_UTILS_API_H_
#define _WLAN_CFR_UTILS_API_H_

#include <wlan_objmgr_cmn.h>
#include <qal_streamfs.h>
#ifdef WLAN_ENH_CFR_ENABLE
#include <qdf_timer.h>
#endif

#define cfr_alert(format, args...) \
		QDF_TRACE_FATAL(QDF_MODULE_ID_CFR, format, ## args)

#define cfr_err(format, args...) \
		QDF_TRACE_ERROR(QDF_MODULE_ID_CFR, format, ## args)

#define cfr_warn(format, args...) \
		QDF_TRACE_WARN(QDF_MODULE_ID_CFR, format, ## args)

#define cfr_info(format, args...) \
		QDF_TRACE_INFO(QDF_MODULE_ID_CFR, format, ## args)

#define cfr_debug(format, args...) \
		QDF_TRACE_DEBUG(QDF_MODULE_ID_CFR, format, ## args)

#define DBR_EVENT_TIMEOUT_IN_MS_CFR 1
#define DBR_NUM_RESP_PER_EVENT_CFR 1
#define MAX_CFR_ENABLED_CLIENTS 10
#ifdef WLAN_ENH_CFR_ENABLE
#define MAX_CFR_MU_USERS 4
#define NUM_CHAN_CAPTURE_STATUS 4
#define NUM_CHAN_CAPTURE_REASON 6
#endif

enum cfrmetaversion {
	CFR_META_VERSION_NONE,
	CFR_META_VERSION_1,
	CFR_META_VERSION_2,
	CFR_META_VERSION_3,
	CFR_META_VERSION_MAX = 0xFF,
};

enum cfrdataversion {
	CFR_DATA_VERSION_NONE,
	CFR_DATA_VERSION_1,
	CFR_DATA_VERSION_MAX = 0xFF,
};

enum cfrplatformtype {
	CFR_PLATFORM_TYPE_NONE,
	CFR_PLATFORM_TYPE_MIPS,
	CFR_PLATFORM_TYPE_ARM,
	CFR_PLATFFORM_TYPE_MAX = 0xFF,
};

enum cfrradiotype {
	CFR_CAPTURE_RADIO_NONE,
	CFR_CAPTURE_RADIO_OSPREY,
	CFR_CAPTURE_RADIO_PEAKCOCK,
	CFR_CAPTURE_RADIO_SCORPION,
	CFR_CAPTURE_RADIO_HONEYBEE,
	CFR_CAPTURE_RADIO_DRAGONFLY,
	CFR_CAPTURE_RADIO_JET,
	CFR_CAPTURE_RADIO_PEREGRINE = 17,
	CFR_CAPTURE_RADIO_SWIFT,
	CFR_CAPTURE_RADIO_BEELINER,
	CFR_CAPTURE_RADIO_CASCADE,
	CFR_CAPTURE_RADIO_DAKOTA,
	CFR_CAPTURE_RADIO_BESRA,
	CFR_CAPTURE_RADIO_HKV2,
	CFR_CAPTURE_RADIO_CYP,
	CFR_CAPTURE_RADIO_MAX = 0xFF,
};

enum ack_capture_mode {
	CFR_LEGACY_ACK     = 0,
	CFR_DUP_LEGACY_ACK = 1,
	CFR_HT_ACK         = 2,
	CFR_VHT_ACK        = 3,
	CFR_INVALID_ACK, /*Always keep this at last*/
};

/* Similar to WMI_PEER_CFR_CAPTURE_METHOD used in one-shot capture */
enum cfr_capture_type {
	CFR_TYPE_METHOD_NULL_FRAME = 0,
	CFR_TYPE_METHOD_NULL_FRAME_WITH_PHASE = 1,
	CFR_TYPE_METHOD_PROBE_RESP = 2,
	CFR_TYPE_METHOD_TM = 3,
	CFR_TYPE_METHOD_FTM = 4,
	CFR_TYPE_METHOD_ACK_RESP_TO_TM_FTM = 5,
	CFR_TYPE_METHOD_TA_RA_TYPE_FILTER = 6,
	CFR_TYPE_METHOD_NDPA_NDP = 7,
	CFR_TYPE_METHOD_ALL_PACKET = 8,
	/* Add new capture methods before this line */
	CFR_TYPE_METHOD_LAST_VALID,
	CFR_TYPE_METHOD_AUTO = 0xff,
	CFR_TYPE_METHOD_MAX,
};

enum mac_freeze_capture_reason {
	FREEZE_REASON_TM = 0,
	FREEZE_REASON_FTM = 1,
	FREEZE_REASON_ACK_RESP_TO_TM_FTM = 2,
	FREEZE_REASON_TA_RA_TYPE_FILTER = 3,
	FREEZE_REASON_NDPA_NDP = 4,
	FREEZE_REASON_ALL_PACKET = 5,
	FREEZE_REASON_MAX,
};

enum chan_capture_status {
	CAPTURE_IDLE = 0,
	CAPTURE_BUSY,
	CAPTURE_ACTIVE,
	CAPTURE_NO_BUFFER,
	CAPTURE_MAX,
};

struct cfr_metadata_version_1 {
	u_int8_t    peer_addr[QDF_MAC_ADDR_SIZE];
	u_int8_t    status;
	u_int8_t    capture_bw;
	u_int8_t    channel_bw;
	u_int8_t    phy_mode;
	u_int16_t   prim20_chan;
	u_int16_t   center_freq1;
	u_int16_t   center_freq2;
	u_int8_t    capture_mode;
	u_int8_t    capture_type;
	u_int8_t    sts_count;
	u_int8_t    num_rx_chain;
	u_int32_t   timestamp;
	u_int32_t   length;
} __attribute__ ((__packed__));

#define HOST_MAX_CHAINS 8

struct cfr_metadata_version_2 {
	u_int8_t    peer_addr[QDF_MAC_ADDR_SIZE];
	u_int8_t    status;
	u_int8_t    capture_bw;
	u_int8_t    channel_bw;
	u_int8_t    phy_mode;
	u_int16_t   prim20_chan;
	u_int16_t   center_freq1;
	u_int16_t   center_freq2;
	u_int8_t    capture_mode;
	u_int8_t    capture_type;
	u_int8_t    sts_count;
	u_int8_t    num_rx_chain;
	u_int32_t   timestamp;
	u_int32_t   length;
	u_int32_t   chain_rssi[HOST_MAX_CHAINS];
	u_int16_t   chain_phase[HOST_MAX_CHAINS];
} __attribute__ ((__packed__));

#ifdef WLAN_ENH_CFR_ENABLE
struct cfr_metadata_version_3 {
	u_int8_t    status;
	u_int8_t    capture_bw;
	u_int8_t    channel_bw;
	u_int8_t    phy_mode;
	u_int16_t   prim20_chan;
	u_int16_t   center_freq1;
	u_int16_t   center_freq2;
	u_int8_t    capture_mode; /* ack_capture_mode */
	u_int8_t    capture_type; /* cfr_capture_type */
	u_int8_t    sts_count;
	u_int8_t    num_rx_chain;
	u_int32_t   timestamp;
	u_int32_t   length;
	u_int8_t    is_mu_ppdu;
	u_int8_t    num_mu_users;
	union {
		u_int8_t    su_peer_addr[QDF_MAC_ADDR_SIZE];
		u_int8_t    mu_peer_addr[MAX_CFR_MU_USERS][QDF_MAC_ADDR_SIZE];
	} peer_addr;
	u_int32_t   chain_rssi[HOST_MAX_CHAINS];
	u_int16_t   chain_phase[HOST_MAX_CHAINS];
} __attribute__ ((__packed__));
#endif

struct csi_cfr_header {
	u_int32_t   start_magic_num;
	u_int32_t   vendorid;
	u_int8_t    cfr_metadata_version;
	u_int8_t    cfr_data_version;
	u_int8_t    chip_type;
	u_int8_t    pltform_type;
	u_int32_t   Reserved;

	union {
		struct cfr_metadata_version_1 meta_v1;
		struct cfr_metadata_version_2 meta_v2;
#ifdef WLAN_ENH_CFR_ENABLE
		struct cfr_metadata_version_3 meta_v3;
#endif
	} u;
} __attribute__ ((__packed__));

/**
 * struct cfr_capture_params - structure to store cfr config param
 * bandwidth: bandwitdh of capture
 * period: period of capture
 * method: enum of method being followed to capture cfr data. 0-QoS null data
 */
struct cfr_capture_params {
	u_int8_t   bandwidth;
	u_int32_t  period;
	u_int8_t   method;
};

/**
 * struct psoc_cfr - private psoc object for cfr
 * psoc_obj: pointer to psoc object
 * is_cfr_capable: flag to determine if cfr is enabled or not
 */
struct psoc_cfr {
	struct wlan_objmgr_psoc *psoc_obj;
	uint8_t is_cfr_capable;
};

/**
 * struct cfr_wmi_host_mem_chunk - wmi mem chunk related
 * vaddr: pointer to virtual address
 * paddr: physical address
 * len: len of the mem chunk allocated
 * req_id: reqid related to the mem chunk
 */
struct cfr_wmi_host_mem_chunk {
	uint32_t *vaddr;
	uint32_t paddr;
	uint32_t len;
	uint32_t req_id;
};

struct whal_cfir_dma_hdr {
	uint16_t
		// 'BA'
		tag                 : 8,
		// '02', length of header in 4 octet units
		length              : 6,
		// 00
		reserved            : 2;
	uint16_t
		// [16]
		upload_done         : 1,
		// [17:18], 0: invalid, 1: CFR, 2: CIR, 3: DebugH
		capture_type        : 3,
		// [19:20], 0: Legacy, 1: HT, 2: VHT, 3: HE
		preamble_type       : 2,
		// [21:23], 0: 1-stream, 1: 2-stream, ..., 7: 8-stream
		nss                 : 3,
		// [24:27], 0: invalid, 1: 1-chain, 2: 2-chain, etc.
		num_chains          : 3,
		// [28:30], 0: 20 MHz, 1: 40 MHz, 2: 80 MHz, 3: 160 MHz
		upload_pkt_bw       : 3,    // [31]
		sw_peer_id_valid    : 1;
	uint16_t
		sw_peer_id          : 16;   // [15:0]
	uint16_t
		phy_ppdu_id         : 16;   // [15:0]
};

#define MAX_LUT_ENTRIES 140 /* For HKv2 136 is max */

/**
 * struct look_up_table - Placeholder for 2 asynchronous events (DBR and
 * TXRX event)
 * dbr_recv: Indicates whether WMI for DBR completion is received or not
 * tx_recv: Indicates whether WMI for TX completion (or) WDI event for RX
 * status is received or not
 * data: pointer to CFR data that ucode DMAs to host memory
 * data_len: length of CFR data DMAed by ucode
 * dbr_ppdu_id: PPDU id retrieved from DBR completion WMI event
 * tx_ppdu_id: PPDU id retrieved from WMI TX completion event (or) PPDU status
 * TLV
 * dbr_address: Physical address of the CFR data dump retrieved from DBR
 * completion WMI event
 * tx_address1: Physical address of the CFR data from TX/RX event
 * tx_address2: Physical address of the CFR data from TX/RX event
 * csi_cfr_header: CFR header constructed by host
 * whal_cfir_enhanced_hdr: CFR header constructed by ucode
 * tx_tstamp: Timestamp when TX/RX event was received
 * dbr_tstamp: Timestamp when DBR completion event was received
 * header_length: Length of header DMAed by ucode in words
 * payload_length: Length of CFR payload
 */
struct look_up_table {
	bool dbr_recv;
	bool tx_recv;
	uint8_t *data; /* capture payload */
	uint32_t data_len; /* capture len */
	uint16_t dbr_ppdu_id; /* ppdu id from dbr */
	uint16_t tx_ppdu_id; /* ppdu id from TX event */
	qdf_dma_addr_t dbr_address; /* capture len */
	uint32_t tx_address1; /* capture len */
	uint32_t tx_address2; /* capture len */
	struct csi_cfr_header header;
	struct whal_cfir_dma_hdr dma_hdr;
	uint64_t txrx_tstamp;
	uint64_t dbr_tstamp;
	uint32_t header_length;
	uint32_t payload_length;
};

struct unassoc_pool_entry {
	struct qdf_mac_addr mac;
	struct cfr_capture_params cfr_params;
	bool is_valid;
};

/**
 * struct pdev_cfr - private pdev object for cfr
 * pdev_obj: pointer to pdev object
 * is_cfr_capable: flag to determine if cfr is enabled or not
 * cfr_timer_enable: flag to enable/disable timer
 * rx_tlv_evt_cnt: Number of CFR WDI events from datapath
 * lut_age_timer: Timer to flush pending TXRX/DBR events in lookup table
 * lut_timer_init: flag to determine if lut_age_timer is initialized or not
 * cfr_data_subscriber: CFR WDI subscriber object
 * bb_captured_channel_cnt: No. of PPDUs for which MAC sent Freeze TLV to PHY
 * bb_captured_timeout_cnt: No. of PPDUs for which CFR filter criteria matched
 * but MAC did not send Freeze TLV to PHY as time exceeded freeze tlv delay
 * count threshold
 * rx_loc_info_valid_cnt: No. of PPDUs for which PHY could find a valid buffer
   in ucode IPC ring
 * chan_capture_status[]: capture status counters
 *	[0] - No. of PPDUs with capture status CAPTURE_IDLE
 *	[1] - No. of PPDUs with capture status CAPTURE_BUSY
 *	[2] - No. of PPDUs with capture status CAPTURE_ACTIVE
 *	[3] - No. of PPDUs with capture status CAPTURE_NO_BUFFER
 * bb_captured_reason_cnt[]: capture reason counters
 *	[0] - No. PPDUs filtered due to freeze_reason_TM
 *	[1] - No. PPDUs filtered due to freeze_reason_FTM
 *	[2] - No. PPDUs filtered due to freeze_reason_ACK_resp_to_TM_FTM
 *	[3] - No. PPDUs filtered due to freeze_reason_TA_RA_TYPE_FILTER
 *	[4] - No. PPDUs filtered due to freeze_reason_NDPA_NDP
 *	[5] - No. PPDUs filtered due to freeze_reason_ALL_PACKET
 * release_err_cnt: No. of lookup table entries freed due to invalid CFR data
 * length
 */
/*
 * To be extended if we get more capbality info
 * from FW's extended service ready event.
 */
struct pdev_cfr {
	struct wlan_objmgr_pdev *pdev_obj;
	uint8_t is_cfr_capable;
	uint8_t cfr_timer_enable;
	struct cfr_wmi_host_mem_chunk cfr_mem_chunk;
	uint16_t cfr_max_sta_count;
	uint16_t cfr_current_sta_count;
	uint32_t num_subbufs;
	uint32_t subbuf_size;
	struct qal_streamfs_chan *chan_ptr;
	struct qal_dentry_t *dir_ptr;
	struct look_up_table lut[MAX_LUT_ENTRIES];
	uint32_t dbr_buf_size;
	uint32_t dbr_num_bufs;
	uint64_t tx_evt_cnt;
	uint64_t dbr_evt_cnt;
	uint64_t release_cnt;
#ifdef WLAN_ENH_CFR_ENABLE
	struct cfr_rcc_param rcc_param;
	struct ta_ra_cfr_cfg global[MAX_TA_RA_ENTRIES];
	uint64_t rx_tlv_evt_cnt;
	qdf_timer_t lut_age_timer;
	uint8_t lut_timer_init;
	void *cfr_data_subscriber;
	uint64_t bb_captured_channel_cnt;
	uint64_t bb_captured_timeout_cnt;
	uint64_t rx_loc_info_valid_cnt;
	uint64_t chan_capture_status[CAPTURE_MAX];
	uint64_t bb_captured_reason_cnt[FREEZE_REASON_MAX];
	uint64_t flush_dbr_cnt;
	uint64_t flush_all_dbr_cnt;
	uint64_t flush_all_txrx_cnt;
	uint64_t invalid_dma_length_cnt;
	uint64_t flush_timeout_dbr_cnt;
	uint64_t flush_timeout_txrx_cnt;
	uint64_t clear_dbr_event;
	uint64_t clear_txrx_event;
#endif
	struct unassoc_pool_entry unassoc_pool[MAX_CFR_ENABLED_CLIENTS];
};

#define PEER_CFR_CAPTURE_ENABLE   1
#define PEER_CFR_CAPTURE_DISABLE  0
/**
 * struct peer_cfr - private peer object for cfr
 * peer_obj: pointer to peer_obj
 * request: Type of request (start/stop)
 * bandwidth: bandwitdth of capture for this peer
 * capture_method: enum determining type of cfr data capture.
 *                 0-Qos null data
 */
struct peer_cfr {
	struct wlan_objmgr_peer *peer_obj;
	u_int8_t   request;            /* start/stop */
	u_int8_t   bandwidth;
	u_int32_t  period;
	u_int8_t   capture_method;
};

/**
 * cfr_initialize_pdev() - cfr initialize pdev
 * @pdev: Pointer to pdev_obj
 *
 * Return: status of cfr pdev init
 */
QDF_STATUS cfr_initialize_pdev(struct wlan_objmgr_pdev *pdev);

/**
 * cfr_deinitialize_pdev() - cfr deinitialize pdev
 * @pdev: Pointer to pdev_obj
 *
 * Return: status of cfr pdev deinit
 */
QDF_STATUS cfr_deinitialize_pdev(struct wlan_objmgr_pdev *pdev);

/**
 * wlan_cfr_init() - Global init for cfr.
 *
 * Return: status of global init pass/fail
 */
QDF_STATUS wlan_cfr_init(void);

/**
 * wlan_cfr_deinit() - Global de-init for cfr.
 *
 * Return: status of global de-init pass/fail
 */
QDF_STATUS wlan_cfr_deinit(void);

/**
 * wlan_cfr_pdev_open() - pdev_open function for cfr.
 * @pdev: pointer to pdev object
 *
 * Return: status of pdev_open pass/fail
 */
QDF_STATUS wlan_cfr_pdev_open(struct wlan_objmgr_pdev *pdev);

/**
 * wlan_cfr_pdev_close() - pdev_close function for cfr.
 * @pdev: pointer to pdev object
 *
 * Return: status of pdev_close pass/fail
 */
QDF_STATUS wlan_cfr_pdev_close(struct wlan_objmgr_pdev *pdev);
#endif
