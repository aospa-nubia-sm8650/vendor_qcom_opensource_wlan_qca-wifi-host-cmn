/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2021-2022 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _HAL_BE_API_MON_H_
#define _HAL_BE_API_MON_H_

#ifdef QCA_MONITOR_2_0_SUPPORT

#include <mon_ingress_ring.h>
#include <mon_destination_ring.h>
#include "hal_be_hw_headers.h"
#include <mon_ingress_ring.h>
#include <mon_destination_ring.h>
#include <hal_be_hw_headers.h>
#include "hal_api_mon.h"
#include <hal_generic_api.h>
#include <hal_generic_api.h>
#include <hal_api_mon.h>

#define HAL_MON_BUFFER_ADDR_INFO_0_BUFFER_ADDR_31_0_OFFSET 0x00000000
#define HAL_MON_BUFFER_ADDR_INFO_0_BUFFER_ADDR_31_0_LSB 0
#define HAL_MON_BUFFER_ADDR_INFO_0_BUFFER_ADDR_31_0_MASK 0xffffffff

#define HAL_MON_BUFFER_ADDR_INFO_1_BUFFER_ADDR_39_32_OFFSET 0x00000004
#define HAL_MON_BUFFER_ADDR_INFO_1_BUFFER_ADDR_39_32_LSB 0
#define HAL_MON_BUFFER_ADDR_INFO_1_BUFFER_ADDR_39_32_MASK 0x000000ff

#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_OFFSET 0x00000008
#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_LSB 0
#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_MSB 31
#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_MASK 0xffffffff

#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_OFFSET 0x0000000c
#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_LSB 0
#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_MSB 31
#define HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_MASK 0xffffffff

#define HAL_MON_PADDR_LO_SET(buff_addr_info, paddr_lo) \
		((*(((unsigned int *) buff_addr_info) + \
		(HAL_MON_BUFFER_ADDR_INFO_0_BUFFER_ADDR_31_0_OFFSET >> 2))) = \
		(paddr_lo << HAL_MON_BUFFER_ADDR_INFO_0_BUFFER_ADDR_31_0_LSB) & \
		HAL_MON_BUFFER_ADDR_INFO_0_BUFFER_ADDR_31_0_MASK)

#define HAL_MON_PADDR_HI_SET(buff_addr_info, paddr_hi) \
		((*(((unsigned int *) buff_addr_info) + \
		(HAL_MON_BUFFER_ADDR_INFO_1_BUFFER_ADDR_39_32_OFFSET >> 2))) = \
		(paddr_hi << HAL_MON_BUFFER_ADDR_INFO_1_BUFFER_ADDR_39_32_LSB) & \
		HAL_MON_BUFFER_ADDR_INFO_1_BUFFER_ADDR_39_32_MASK)

#define HAL_MON_VADDR_LO_SET(buff_addr_info, paddr_lo) \
		((*(((unsigned int *) buff_addr_info) + \
		(HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_OFFSET >> 2))) = \
		(paddr_lo << HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_LSB) & \
		HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_31_0_MASK)

#define HAL_MON_VADDR_HI_SET(buff_addr_info, paddr_hi) \
		((*(((unsigned int *) buff_addr_info) + \
		(HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_OFFSET >> 2))) = \
		(paddr_hi << HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_LSB) & \
		HAL_MON_MON_INGRESS_RING_BUFFER_VIRT_ADDR_63_32_MASK)

enum hal_dest_desc_end_reason {
	HAL_TX_MON_STATUS_BUFFER_FULL = 0,
	HAL_TX_MON_FLUSH_DETECTED,
	HAL_TX_MON_END_OF_PPDU,
	HAL_TX_MON_PPDU_TRUNCATED
};

/**
 * struct hal_mon_desc () - HAL Monitor descriptor
 *
 * @buf_addr: virtual buffer address
 * @ppdu_id: ppdu id
 *	     - TxMon fills scheduler id
 *	     - RxMON fills phy_ppdu_id
 * @end_offset: offset (units in 4 bytes) where status buffer ended
 *		i.e offset of TLV + last TLV size
 * @end_reason: 0 - status buffer is full
 *		1 - flush detected
 *		2 - TX_FES_STATUS_END or RX_PPDU_END
 *		3 - PPDU truncated due to system error
 * @initiator:	1 - descriptor belongs to TX FES
 *		0 - descriptor belongs to TX RESPONSE
 * @empty_descriptor: 0 - this descriptor is written on a flush
 *			or end of ppdu or end of status buffer
 *			1 - descriptor provided to indicate drop
 * @ring_id: ring id for debugging
 * @looping_count: count to indicate number of times producer
 *			of entries has looped around the ring
 */
struct hal_mon_desc {
	uint64_t buf_addr;
	uint32_t ppdu_id;
	uint32_t end_offset:12,
		 reserved_3a:4,
		 end_reason:2,
		 initiator:1,
		 empty_descriptor:1,
		 ring_id:8,
		 looping_count:4;
};

typedef struct hal_mon_desc *hal_mon_desc_t;

/**
 * struct hal_mon_buf_addr_status () - HAL buffer address tlv get status
 *
 * @buf_addr_31_0: Lower 32 bits of virtual address of status buffer
 * @buf_addr_63_32: Upper 32 bits of virtual address of status buffer
 * @dma_length: DMA length
 * @msdu_continuation: is msdu size more than fragment size
 * @truncated: is msdu got truncated
 * @tlv_padding: tlv paddding
 */
struct hal_mon_buf_addr_status {
	uint32_t buffer_virt_addr_31_0;
	uint32_t buffer_virt_addr_63_32;
	uint32_t dma_length:12,
		 reserved_2a:4,
		 msdu_continuation:1,
		 truncated:1,
		 reserved_2b:14;
	uint32_t tlv64_padding;
};

/**
 * hal_be_get_mon_dest_status() - Get monitor descriptor
 * @hal_soc_hdl: HAL Soc handle
 * @desc: HAL monitor descriptor
 *
 * Return: none
 */
static inline void
hal_be_get_mon_dest_status(hal_soc_handle_t hal_soc,
			   void *hw_desc,
			   struct hal_mon_desc *status)
{
	struct mon_destination_ring *desc = hw_desc;

	status->buf_addr = HAL_RX_GET(desc, MON_DESTINATION_RING_STAT,
				      BUF_VIRT_ADDR_31_0) |
				      (((uint64_t)HAL_RX_GET(desc,
				      MON_DESTINATION_RING_STAT,
				      BUF_VIRT_ADDR_63_32)) << 32);

	status->ppdu_id = desc->ppdu_id;
	status->end_offset = desc->end_offset;
	status->end_reason = desc->end_reason;
	status->initiator = desc->initiator;
	status->empty_descriptor = desc->empty_descriptor;
	status->looping_count = desc->looping_count;
}

/**
 * hal_mon_buff_addr_info_set() - set desc address in cookie
 * @hal_soc_hdl: HAL Soc handle
 * @mon_entry: monitor srng
 * @desc: HAL monitor descriptor
 *
 * Return: none
 */
static inline
void hal_mon_buff_addr_info_set(hal_soc_handle_t hal_soc_hdl,
				void *mon_entry,
				void *mon_desc_addr,
				qdf_dma_addr_t phy_addr)
{
	uint32_t paddr_lo = ((u64)phy_addr & 0x00000000ffffffff);
	uint32_t paddr_hi = ((u64)phy_addr & 0xffffffff00000000) >> 32;
	uint32_t vaddr_lo = ((u64)mon_desc_addr & 0x00000000ffffffff);
	uint32_t vaddr_hi = ((u64)mon_desc_addr & 0xffffffff00000000) >> 32;

	HAL_MON_PADDR_LO_SET(mon_entry, paddr_lo);
	HAL_MON_PADDR_HI_SET(mon_entry, paddr_hi);
	HAL_MON_VADDR_LO_SET(mon_entry, vaddr_lo);
	HAL_MON_VADDR_HI_SET(mon_entry, vaddr_hi);
}

/**
 * hal_mon_buf_get() - Get monitor descriptor
 * @hal_soc_hdl: HAL Soc handle
 * @desc: HAL monitor descriptor
 *
 * Return: none
 */
static inline
void hal_mon_buf_get(hal_soc_handle_t hal_soc_hdl,
		     void *dst_ring_desc,
		     struct hal_mon_desc *mon_desc)
{
	struct mon_destination_ring *hal_dst_ring =
			(struct mon_destination_ring *)dst_ring_desc;

	mon_desc->buf_addr =
		((u64)hal_dst_ring->stat_buf_virt_addr_31_0 |
		 ((u64)hal_dst_ring->stat_buf_virt_addr_63_32 << 32));
	mon_desc->ppdu_id = hal_dst_ring->ppdu_id;
	mon_desc->end_offset = hal_dst_ring->end_offset;
	mon_desc->end_reason = hal_dst_ring->end_reason;
	mon_desc->initiator = hal_dst_ring->initiator;
	mon_desc->ring_id = hal_dst_ring->ring_id;
	mon_desc->empty_descriptor = hal_dst_ring->empty_descriptor;
	mon_desc->looping_count = hal_dst_ring->looping_count;
}

/* TX monitor */
#define TX_MON_STATUS_BUF_SIZE 2048

#define HAL_INVALID_PPDU_ID    0xFFFFFFFF

enum hal_tx_tlv_status {
	HAL_MON_TX_FES_SETUP,
	HAL_MON_TX_FES_STATUS_END,
	HAL_MON_RX_RESPONSE_REQUIRED_INFO,
	HAL_MON_RESPONSE_END_STATUS_INFO,

	HAL_MON_TX_PCU_PPDU_SETUP_INIT,

	HAL_MON_TX_MPDU_START,
	HAL_MON_TX_MSDU_START,
	HAL_MON_TX_BUFFER_ADDR,
	HAL_MON_TX_DATA,

	HAL_MON_TX_FES_STATUS_START,

	HAL_MON_TX_FES_STATUS_PROT,
	HAL_MON_TX_FES_STATUS_START_PROT,

	HAL_MON_TX_FES_STATUS_START_PPDU,
	HAL_MON_TX_FES_STATUS_USER_PPDU,

	HAL_MON_RX_FRAME_BITMAP_ACK,
	HAL_MON_RX_FRAME_BITMAP_BLOCK_ACK_256,
	HAL_MON_RX_FRAME_BITMAP_BLOCK_ACK_1K,
	HAL_MON_COEX_TX_STATUS,

	HAL_MON_MACTX_HE_SIG_A_SU,
	HAL_MON_MACTX_HE_SIG_A_MU_DL,
	HAL_MON_MACTX_HE_SIG_B1_MU,
	HAL_MON_MACTX_HE_SIG_B2_MU,
	HAL_MON_MACTX_HE_SIG_B2_OFDMA,
	HAL_MON_MACTX_L_SIG_A,
	HAL_MON_MACTX_L_SIG_B,
	HAL_MON_MACTX_HT_SIG,
	HAL_MON_MACTX_VHT_SIG_A,

	HAL_MON_MACTX_USER_DESC_PER_USER,
	HAL_MON_MACTX_USER_DESC_COMMON,
	HAL_MON_MACTX_PHY_DESC,

	HAL_MON_TX_STATUS_PPDU_NOT_DONE,
};

/**
 * hal_tx_status_get_next_tlv() - get next tx status TLV
 * @tx_tlv: pointer to TLV header
 *
 * Return: pointer to next tlv info
 */
static inline uint8_t*
hal_tx_status_get_next_tlv(uint8_t *tx_tlv) {
	uint32_t tlv_len, tlv_tag;

	tlv_len = HAL_RX_GET_USER_TLV32_LEN(tx_tlv);
	tlv_tag = HAL_RX_GET_USER_TLV32_TYPE(tx_tlv);

	return (uint8_t *)(((unsigned long)(tx_tlv + tlv_len +
					    HAL_RX_TLV32_HDR_SIZE + 3)) & (~3));
}

/*
 * hal_txmon_status_free_buffer() - api to free status buffer
 * @hal_soc: HAL soc handle
 * @status_frag: qdf_frag_t buffer
 *
 * Return void
 */
static inline void
hal_txmon_status_free_buffer(hal_soc_handle_t hal_soc_hdl,
			     qdf_frag_t status_frag)
{
	struct hal_soc *hal_soc = (struct hal_soc *)hal_soc_hdl;

	hal_soc->ops->hal_txmon_status_free_buffer(status_frag);
}
#endif /* QCA_MONITOR_2_0_SUPPORT */
#endif /* _HAL_BE_API_MON_H_ */