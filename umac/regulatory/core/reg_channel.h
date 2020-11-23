/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
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

/**
 * DOC: reg_channel.h
 * This file provides prototypes of the channel list APIs in addition to
 * predefined macros.
 */

#ifndef __REG_CHANNEL_H_
#define __REG_CHANNEL_H_

#ifdef CONFIG_HOST_FIND_CHAN

/**
 * enum HOST_REGDMN_MODE:
 * @HOST_REGDMN_MODE_11A: 11a channels
 * @HOST_REGDMN_MODE_TURBO: 11a turbo-only channels
 * @HOST_REGDMN_MODE_11B: 11b channels
 * @HOST_REGDMN_MODE_PUREG: 11g channels (OFDM only)
 * @HOST_REGDMN_MODE_11G: historical
 * @HOST_REGDMN_MODE_108G: 11g+Turbo channels
 * @HOST_REGDMN_MODE_108A: 11a+Turbo channels
 * @HOST_REGDMN_MODE_11AC_VHT20_2G: 2GHz, VHT20
 * @HOST_REGDMN_MODE_XR: XR channels
 * @HOST_REGDMN_MODE_11A_HALF_RATE: 11a half rate channels
 * @HOST_REGDMN_MODE_11A_QUARTER_RATE: 11a quarter rate channels
 * @HOST_REGDMN_MODE_11NG_HT20: 11ng HT20 channels
 * @HOST_REGDMN_MODE_11NA_HT20: 11na HT20 channels
 * @HOST_REGDMN_MODE_11NG_HT40PLUS: 11ng HT40+ channels
 * @HOST_REGDMN_MODE_11NG_HT40MINUS: 11ng HT40- channels
 * @HOST_REGDMN_MODE_11NA_HT40PLUS: 11na HT40+ channels
 * @HOST_REGDMN_MODE_11NA_HT40MINUS: 11na HT40- channels
 * @HOST_REGDMN_MODE_11AC_VHT20: 5GHz, VHT20
 * @HOST_REGDMN_MODE_11AC_VHT40PLUS: 5GHz, VHT40+ channels
 * @HOST_REGDMN_MODE_11AC_VHT40MINUS: 5GHz, VHT40- channels
 * @HOST_REGDMN_MODE_11AC_VHT80: 5GHz, VHT80 channels
 * @HOST_REGDMN_MODE_11AC_VHT160: 5GHz, VHT160 channels
 * @HOST_REGDMN_MODE_11AC_VHT80_80: 5GHz, VHT80+80 channels
 * @HOST_REGDMN_MODE_11AXG_HE20: 11ax 2.4GHz, HE20 channels
 * @HOST_REGDMN_MODE_11AXA_HE20: 11ax 5GHz, HE20 channels
 * @HOST_REGDMN_MODE_11AXG_HE40PLUS: 11ax 2.4GHz, HE40+ channels
 * @HOST_REGDMN_MODE_11AXG_HE40MINUS: 11ax 2.4GHz, HE40- channels
 * @HOST_REGDMN_MODE_11AXA_HE40PLUS: 11ax 5GHz, HE40+ channels
 * @HOST_REGDMN_MODE_11AXA_HE40MINUS: 11ax 5GHz, HE40- channels
 * @HOST_REGDMN_MODE_11AXA_HE80: 11ax 5GHz, HE80 channels
 * @HOST_REGDMN_MODE_11AXA_HE160: 11ax 5GHz, HE160 channels
 * @HOST_REGDMN_MODE_11AXA_HE80_80: 11ax 5GHz, HE80+80 channels
 */
enum {
	HOST_REGDMN_MODE_11A = 0x00000001,
	HOST_REGDMN_MODE_TURBO = 0x00000002,
	HOST_REGDMN_MODE_11B = 0x00000004,
	HOST_REGDMN_MODE_PUREG = 0x00000008,
	HOST_REGDMN_MODE_11G = 0x00000008,
	HOST_REGDMN_MODE_108G = 0x00000020,
	HOST_REGDMN_MODE_108A = 0x00000040,
	HOST_REGDMN_MODE_11AC_VHT20_2G = 0x00000080,
	HOST_REGDMN_MODE_XR = 0x00000100,
	HOST_REGDMN_MODE_11A_HALF_RATE = 0x00000200,
	HOST_REGDMN_MODE_11A_QUARTER_RATE = 0x00000400,
	HOST_REGDMN_MODE_11NG_HT20 = 0x00000800,
	HOST_REGDMN_MODE_11NA_HT20 = 0x00001000,
	HOST_REGDMN_MODE_11NG_HT40PLUS = 0x00002000,
	HOST_REGDMN_MODE_11NG_HT40MINUS = 0x00004000,
	HOST_REGDMN_MODE_11NA_HT40PLUS = 0x00008000,
	HOST_REGDMN_MODE_11NA_HT40MINUS = 0x00010000,
	HOST_REGDMN_MODE_11AC_VHT20 = 0x00020000,
	HOST_REGDMN_MODE_11AC_VHT40PLUS = 0x00040000,
	HOST_REGDMN_MODE_11AC_VHT40MINUS = 0x00080000,
	HOST_REGDMN_MODE_11AC_VHT80 = 0x00100000,
	HOST_REGDMN_MODE_11AC_VHT160 = 0x00200000,
	HOST_REGDMN_MODE_11AC_VHT80_80 = 0x00400000,
	HOST_REGDMN_MODE_11AXG_HE20 = 0x00800000,
	HOST_REGDMN_MODE_11AXA_HE20 = 0x01000000,
	HOST_REGDMN_MODE_11AXG_HE40PLUS = 0x02000000,
	HOST_REGDMN_MODE_11AXG_HE40MINUS = 0x04000000,
	HOST_REGDMN_MODE_11AXA_HE40PLUS = 0x08000000,
	HOST_REGDMN_MODE_11AXA_HE40MINUS = 0x10000000,
	HOST_REGDMN_MODE_11AXA_HE80 = 0x20000000,
	HOST_REGDMN_MODE_11AXA_HE160 = 0x40000000,
	HOST_REGDMN_MODE_11AXA_HE80_80 = 0x80000000,
	HOST_REGDMN_MODE_ALL = 0xffffffff
};

#define WIRELESS_11AX_MODES  (HOST_REGDMN_MODE_11AXG_HE20 \
			      | HOST_REGDMN_MODE_11AXG_HE40PLUS \
			      | HOST_REGDMN_MODE_11AXG_HE40MINUS \
			      | HOST_REGDMN_MODE_11AXA_HE20 \
			      | HOST_REGDMN_MODE_11AXA_HE40PLUS \
			      | HOST_REGDMN_MODE_11AXA_HE40MINUS \
			      | HOST_REGDMN_MODE_11AXA_HE80 \
			      | HOST_REGDMN_MODE_11AXA_HE160 \
			      | HOST_REGDMN_MODE_11AXA_HE80_80)

#define WIRELESS_11AC_MODES  (HOST_REGDMN_MODE_11AC_VHT20 \
			      | HOST_REGDMN_MODE_11AC_VHT40PLUS \
			      | HOST_REGDMN_MODE_11AC_VHT40MINUS \
			      | HOST_REGDMN_MODE_11AC_VHT80 \
			      | HOST_REGDMN_MODE_11AC_VHT160 \
			      | HOST_REGDMN_MODE_11AC_VHT80_80)

#define WIRELESS_11N_MODES   (HOST_REGDMN_MODE_11NG_HT20 \
			      | HOST_REGDMN_MODE_11NA_HT20 \
			      | HOST_REGDMN_MODE_11NG_HT40PLUS \
			      | HOST_REGDMN_MODE_11NG_HT40MINUS \
			      | HOST_REGDMN_MODE_11NA_HT40PLUS \
			      | HOST_REGDMN_MODE_11NA_HT40MINUS)

#define WIRELESS_11G_MODES   (HOST_REGDMN_MODE_PUREG \
			      | HOST_REGDMN_MODE_11G \
			      | HOST_REGDMN_MODE_108G)

#define WIRELESS_11B_MODES   (HOST_REGDMN_MODE_11B)

#define WIRELESS_11A_MODES   (HOST_REGDMN_MODE_11A \
			      | HOST_REGDMN_MODE_TURBO \
			      | HOST_REGDMN_MODE_108A \
			      | HOST_REGDMN_MODE_11A_HALF_RATE \
			      | HOST_REGDMN_MODE_11A_QUARTER_RATE)

#define WIRELESS_40_MODES    (HOST_REGDMN_MODE_11NG_HT40PLUS \
			      | HOST_REGDMN_MODE_11NG_HT40MINUS \
			      | HOST_REGDMN_MODE_11NA_HT40PLUS \
			      | HOST_REGDMN_MODE_11NA_HT40MINUS \
			      | HOST_REGDMN_MODE_11AC_VHT40PLUS \
			      | HOST_REGDMN_MODE_11AC_VHT40MINUS \
			      | HOST_REGDMN_MODE_11AXG_HE40PLUS \
			      | HOST_REGDMN_MODE_11AXG_HE40MINUS \
			      | HOST_REGDMN_MODE_11AXA_HE40PLUS \
			      | HOST_REGDMN_MODE_11AXA_HE40MINUS)

#define WIRELESS_80_MODES    (HOST_REGDMN_MODE_11AC_VHT80 \
			      | HOST_REGDMN_MODE_11AXA_HE80)

#define WIRELESS_160_MODES   (HOST_REGDMN_MODE_11AC_VHT160 \
			      | HOST_REGDMN_MODE_11AXA_HE160)

/**
 * REG_IS_CHAN_DISABLED() - In the regulatory channel list, a channel
 * may be disabled by the regulatory/device or by radar. Radar is temporary
 * and a radar disabled channel does not mean that the channel is permanently
 * disabled. The API checks if the channel is disabled, but not due to radar.
 * @chan - Regulatory channel object
 *
 * Return - True,  the channel is disabled, but not due to radar, else false.
 */
static bool reg_is_chan_disabled(struct regulatory_channel chan)
{
	return (((chan).chan_flags & REGULATORY_CHAN_DISABLED) &&
		((chan).state == CHANNEL_STATE_DISABLE) &&
		(!((chan).nol_chan)) && (!((chan).nol_history)));
}

/**
 * reg_is_phymode_chwidth_allowed() - Check if requested phymode is allowed
 * @pdev_priv_obj: Pointer to regulatory pdev private object.
 * @phy_in: phymode that the user requested.
 * @ch_width: Channel width that the user requested.
 * @primary_freq: Input primary frequency.
 *
 * Return: true if phymode is allowed, else false.
 */
bool reg_is_phymode_chwidth_allowed(
		struct wlan_regulatory_pdev_priv_obj *pdev_priv_obj,
		enum reg_phymode phy_in,
		enum phy_ch_width ch_width,
		qdf_freq_t primary_freq);

/**
 * reg_set_chan_blocked() - Set is_chan_hop_blocked to true for a frequency
 * in the current chan list.
 * @pdev: Pointer to pdev.
 * @freq: Channel frequency in MHz.
 *
 * Return: void.
 */
void reg_set_chan_blocked(struct wlan_objmgr_pdev *pdev, qdf_freq_t freq);

/**
 * wlan_reg_is_chan_blocked() - Check if is_chan_hop_blocked to true for a
 * frequency in the current chan list.
 * @pdev: Pointer to pdev.
 * @freq: Channel frequency in MHz.
 *
 * Return: true if is_chan_hop_blocked is true for the input frequency, else
 * false.
 */
bool reg_is_chan_blocked(struct wlan_objmgr_pdev *pdev, qdf_freq_t freq);

/**
 * reg_is_chan_blocked() - Clear is_chan_hop_blocked for channel in the
 * current chan list.
 * @pdev: Pointer to pdev.
 *
 * Return: void.
 */
void reg_clear_allchan_blocked(struct wlan_objmgr_pdev *pdev);

/*
 * reg_is_band_present() - Check if input band channels are present
 * in the regulatory current channel list.
 * @pdev: pdev pointer.
 * @reg_band: regulatory band.
 *
 */
bool reg_is_band_present(struct wlan_objmgr_pdev *pdev,
			 enum reg_wifi_band reg_band);
#else
static inline bool reg_is_phymode_chwidth_allowed(
		struct wlan_regulatory_pdev_priv_obj *pdev_priv_obj,
		enum reg_phymode phy_in,
		enum phy_ch_width ch_width,
		qdf_freq_t primary_freq);
{
	return false;
}

static inline
void reg_set_chan_blocked(struct wlan_objmgr_pdev *pdev, qdf_freq_t freq)
{
}

static inline
bool reg_is_chan_blocked(struct wlan_objmgr_pdev *pdev, qdf_freq_t freq)
{
	return false;
}

static inline void reg_clear_allchan_blocked(struct wlan_objmgr_pdev *pdev)
{
}

static inline bool
reg_is_band_present(struct wlan_objmgr_pdev *pdev, enum reg_wifi_band reg_band)
{
	return false;
}
#endif /* CONFIG_HOST_FIND_CHAN */

#endif /* __REG_CHANNEL_H_ */
