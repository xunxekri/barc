#include <stdio.h>
#include <glib.h>
#include <NetworkManager.h>
#include "seg.h"

Seg network(NMClient *client) {
	Seg net;
	if (client == NULL) {
		sprintf(net.value, "Failed to create nm client.\n");
	} else {
		const GPtrArray *devices = nm_client_get_devices(client);

		for (int i = 0; i < devices->len; i++) {
			NMDevice *device = g_ptr_array_index(devices, i);
			if (nm_device_get_state(device) == NM_DEVICE_STATE_ACTIVATED) {
				NMAccessPoint *active_ap = nm_device_wifi_get_active_access_point(NM_DEVICE_WIFI(device));
				if (active_ap != NULL) {
					GBytes *active_ssid = nm_access_point_get_ssid(active_ap);
					guint8 strength = nm_access_point_get_strength(active_ap);

					NMIPConfig *device_ip4_config = nm_device_get_ip4_config(device);
					GPtrArray *device_addresses = nm_ip_config_get_addresses(device_ip4_config);
					const char *device_ip = nm_ip_address_get_address(g_ptr_array_index(device_addresses, 0));

					if (active_ssid != NULL) {
						char *active_ssid_str = nm_utils_ssid_to_utf8(g_bytes_get_data(active_ssid, NULL), g_bytes_get_size(active_ssid));
						sprintf(net.value, "%u%%%% %s %s", strength, active_ssid_str, device_ip);
						g_free(active_ssid_str);
					} else {
						sprintf(net.value, "%u%%%% SSID Unknown %s", strength, device_ip);
					}
				}
				break;
			}
		}
	}

	return net;
}
