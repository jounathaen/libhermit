/*
 * Copyright (c) 2017, Annika Wierichs, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * TODO: Documentation
 *
 */

#include "uhyve-ibv.h"

#include <infiniband/verbs.h>		// Linux include


/*
 * ibv_get_device_list
 */

void call_ibv_get_device_list(struct kvm_run * run, uint8_t * guest_mem) { // !
	printf("UHYVE call: call_ibv_get_device_list\n");
	unsigned data = *((unsigned *) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_device_list_t * args = (uhyve_ibv_get_device_list_t *) (guest_mem + data);

	int num_devices;
	struct ibv_device ** host_ret = ibv_get_device_list(&num_devices);

	if (args->num_devices != NULL) {
		*args->num_devices = num_devices;
	}
	for (int d = 0; d < num_devices; d++) {
		args->ret[d] = host_ret[d];
	}
}

void call_ibv_wc_status_str(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_wc_status_str\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_wc_status_str_t * args = (uhyve_ibv_wc_status_str_t *) (guest_mem + data);

	const char * host_ret = ibv_wc_status_str(args->status); // !
	memcpy(args->ret, host_ret, sizeof(host_ret)); // !
}

void call_ibv_rate_to_mult(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_rate_to_mult\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_rate_to_mult_t * args = (uhyve_ibv_rate_to_mult_t *) (guest_mem + data);

	args->ret = ibv_rate_to_mult(args->rate);
}

void call_mult_to_ibv_rate(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_mult_to_ibv_rate\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_mult_to_ibv_rate_t * args = (uhyve_mult_to_ibv_rate_t *) (guest_mem + data);

	args->ret = mult_to_ibv_rate(args->mult);
}

void call_ibv_rate_to_mbps(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_rate_to_mbps\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_rate_to_mbps_t * args = (uhyve_ibv_rate_to_mbps_t *) (guest_mem + data);

	args->ret = ibv_rate_to_mbps(args->rate);
}

void call_mbps_to_ibv_rate(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_mbps_to_ibv_rate\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_mbps_to_ibv_rate_t * args = (uhyve_mbps_to_ibv_rate_t *) (guest_mem + data);

	args->ret = mbps_to_ibv_rate(args->mbps);
}

void call_verbs_get_ctx(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_verbs_get_ctx\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_verbs_get_ctx_t * args = (uhyve_verbs_get_ctx_t *) (guest_mem + data);

	args->ret = verbs_get_ctx(args->ctx);
}

void call_ibv_free_device_list(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_free_device_list\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_free_device_list_t * args = (uhyve_ibv_free_device_list_t *) (guest_mem + data);
}

void call_ibv_get_device_name(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_get_device_name\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_device_name_t * args = (uhyve_ibv_get_device_name_t *) (guest_mem + data);

	const char * host_ret = ibv_get_device_name(args->device); // !
	memcpy(args->ret, host_ret, sizeof(host_ret)); // !
}

void call_ibv_get_device_guid(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_get_device_guid\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_device_guid_t * args = (uhyve_ibv_get_device_guid_t *) (guest_mem + data);

	args->ret = ibv_get_device_guid(args->device);
}

void call_ibv_open_device(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_open_device\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_open_device_t * args = (uhyve_ibv_open_device_t *) (guest_mem + data);

	args->ret = ibv_open_device(args->device);
}

void call_ibv_close_device(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_close_device\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_close_device_t * args = (uhyve_ibv_close_device_t *) (guest_mem + data);

	args->ret = ibv_close_device(args->context);
}

void call_ibv_get_async_event(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_get_async_event\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_async_event_t * args = (uhyve_ibv_get_async_event_t *) (guest_mem + data);

	args->ret = ibv_get_async_event(args->context, args->event);
}

void call_ibv_ack_async_event(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_ack_async_event\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_ack_async_event_t * args = (uhyve_ibv_ack_async_event_t *) (guest_mem + data);
}

void call_ibv_query_device(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_device\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_device_t * args = (uhyve_ibv_query_device_t *) (guest_mem + data);

	args->ret = ibv_query_device(args->context, args->device_attr);
}

void call_ibv_query_port(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_port\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_port_t * args = (uhyve_ibv_query_port_t *) (guest_mem + data);

	args->ret = ibv_query_port(args->context, args->port_num, args->port_attr);
}

void call____ibv_query_port(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call____ibv_query_port\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve____ibv_query_port_t * args = (uhyve____ibv_query_port_t *) (guest_mem + data);

	args->ret = ___ibv_query_port(args->context, args->port_num, args->port_attr);
}

void call_ibv_query_gid(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_gid\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_gid_t * args = (uhyve_ibv_query_gid_t *) (guest_mem + data);

	args->ret = ibv_query_gid(args->context, args->port_num, args->index, args->gid);
}

void call_ibv_query_pkey(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_pkey\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_pkey_t * args = (uhyve_ibv_query_pkey_t *) (guest_mem + data);

	args->ret = ibv_query_pkey(args->context, args->port_num, args->index, args->pkey);
}

void call_ibv_alloc_pd(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_alloc_pd\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_alloc_pd_t * args = (uhyve_ibv_alloc_pd_t *) (guest_mem + data);

	args->ret = ibv_alloc_pd(args->context);
}

void call_ibv_dealloc_pd(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_dealloc_pd\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_dealloc_pd_t * args = (uhyve_ibv_dealloc_pd_t *) (guest_mem + data);

	args->ret = ibv_dealloc_pd(args->pd);
}

void call_ibv_create_flow(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_flow\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_flow_t * args = (uhyve_ibv_create_flow_t *) (guest_mem + data);

	args->ret = ibv_create_flow(args->qp, args->flow);
}

void call_ibv_destroy_flow(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_destroy_flow\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_destroy_flow_t * args = (uhyve_ibv_destroy_flow_t *) (guest_mem + data);

	args->ret = ibv_destroy_flow(args->flow_id);
}

void call_ibv_open_xrcd(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_open_xrcd\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_open_xrcd_t * args = (uhyve_ibv_open_xrcd_t *) (guest_mem + data);

	args->ret = ibv_open_xrcd(args->context, args->xrcd_init_attr);
}

void call_ibv_close_xrcd(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_close_xrcd\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_close_xrcd_t * args = (uhyve_ibv_close_xrcd_t *) (guest_mem + data);

	args->ret = ibv_close_xrcd(args->xrcd);
}

void call_ibv_reg_mr(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_reg_mr\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_reg_mr_t * args = (uhyve_ibv_reg_mr_t *) (guest_mem + data);

	args->ret = ibv_reg_mr(args->pd, args->addr, args->length, args->access);
}

void call_ibv_rereg_mr(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_rereg_mr\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_rereg_mr_t * args = (uhyve_ibv_rereg_mr_t *) (guest_mem + data);

	args->ret = ibv_rereg_mr(args->mr, args->flags, args->pd, args->addr, args->length, args->access);
}

void call_ibv_dereg_mr(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_dereg_mr\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_dereg_mr_t * args = (uhyve_ibv_dereg_mr_t *) (guest_mem + data);

	args->ret = ibv_dereg_mr(args->mr);
}

void call_ibv_alloc_mw(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_alloc_mw\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_alloc_mw_t * args = (uhyve_ibv_alloc_mw_t *) (guest_mem + data);

	args->ret = ibv_alloc_mw(args->pd, args->type);
}

void call_ibv_dealloc_mw(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_dealloc_mw\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_dealloc_mw_t * args = (uhyve_ibv_dealloc_mw_t *) (guest_mem + data);

	args->ret = ibv_dealloc_mw(args->mw);
}

void call_ibv_inc_rkey(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_inc_rkey\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_inc_rkey_t * args = (uhyve_ibv_inc_rkey_t *) (guest_mem + data);

	args->ret = ibv_inc_rkey(args->rkey);
}

void call_ibv_bind_mw(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_bind_mw\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_bind_mw_t * args = (uhyve_ibv_bind_mw_t *) (guest_mem + data);

	args->ret = ibv_bind_mw(args->qp, args->mw, args->mw_bind);
}

void call_ibv_create_comp_channel(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_comp_channel\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_comp_channel_t * args = (uhyve_ibv_create_comp_channel_t *) (guest_mem + data);

	args->ret = ibv_create_comp_channel(args->context);
}

void call_ibv_destroy_comp_channel(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_destroy_comp_channel\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_destroy_comp_channel_t * args = (uhyve_ibv_destroy_comp_channel_t *) (guest_mem + data);

	args->ret = ibv_destroy_comp_channel(args->channel);
}

void call_ibv_create_cq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_cq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_cq_t * args = (uhyve_ibv_create_cq_t *) (guest_mem + data);

	args->ret = ibv_create_cq(args->context, args->cqe, args->cq_context, args->channel, args->comp_vector);
}

void call_ibv_resize_cq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_resize_cq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_resize_cq_t * args = (uhyve_ibv_resize_cq_t *) (guest_mem + data);

	args->ret = ibv_resize_cq(args->cq, args->cqe);
}

void call_ibv_destroy_cq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_destroy_cq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_destroy_cq_t * args = (uhyve_ibv_destroy_cq_t *) (guest_mem + data);

	args->ret = ibv_destroy_cq(args->cq);
}

void call_ibv_get_cq_event(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_get_cq_event\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_cq_event_t * args = (uhyve_ibv_get_cq_event_t *) (guest_mem + data);

	args->ret = ibv_get_cq_event(args->channel, args->cq, args->cq_context);
}

void call_ibv_ack_cq_events(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_ack_cq_events\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_ack_cq_events_t * args = (uhyve_ibv_ack_cq_events_t *) (guest_mem + data);
}

void call_ibv_poll_cq(struct kvm_run * run, uint8_t * guest_mem) {
	/* printf("UHYVE call: call_ibv_poll_cq\n"); */
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_poll_cq_t * args = (uhyve_ibv_poll_cq_t *) (guest_mem + data);

	args->ret = ibv_poll_cq(args->cq, args->num_entries, args->wc);
}

void call_ibv_req_notify_cq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_req_notify_cq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_req_notify_cq_t * args = (uhyve_ibv_req_notify_cq_t *) (guest_mem + data);

	args->ret = ibv_req_notify_cq(args->cq, args->solicited_only);
}

void call_ibv_create_srq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_srq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_srq_t * args = (uhyve_ibv_create_srq_t *) (guest_mem + data);

	args->ret = ibv_create_srq(args->pd, args->srq_init_attr);
}

void call_ibv_create_srq_ex(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_srq_ex\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_srq_ex_t * args = (uhyve_ibv_create_srq_ex_t *) (guest_mem + data);

	args->ret = ibv_create_srq_ex(args->context, args->srq_init_attr_ex);
}

void call_ibv_modify_srq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_modify_srq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_modify_srq_t * args = (uhyve_ibv_modify_srq_t *) (guest_mem + data);

	args->ret = ibv_modify_srq(args->srq, args->srq_attr, args->srq_attr_mask);
}

void call_ibv_query_srq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_srq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_srq_t * args = (uhyve_ibv_query_srq_t *) (guest_mem + data);

	args->ret = ibv_query_srq(args->srq, args->srq_attr);
}

void call_ibv_get_srq_num(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_get_srq_num\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_srq_num_t * args = (uhyve_ibv_get_srq_num_t *) (guest_mem + data);

	args->ret = ibv_get_srq_num(args->srq, args->srq_num);
}

void call_ibv_destroy_srq(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_destroy_srq\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_destroy_srq_t * args = (uhyve_ibv_destroy_srq_t *) (guest_mem + data);

	args->ret = ibv_destroy_srq(args->srq);
}

void call_ibv_post_srq_recv(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_post_srq_recv\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_post_srq_recv_t * args = (uhyve_ibv_post_srq_recv_t *) (guest_mem + data);

	args->ret = ibv_post_srq_recv(args->srq, args->recv_wr, args->bad_recv_wr);
}

void call_ibv_create_qp(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_qp\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_qp_t * args = (uhyve_ibv_create_qp_t *) (guest_mem + data);

	args->ret = ibv_create_qp(args->pd, args->qp_init_attr);
}

void call_ibv_create_qp_ex(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_qp_ex\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_qp_ex_t * args = (uhyve_ibv_create_qp_ex_t *) (guest_mem + data);

	args->ret = ibv_create_qp_ex(args->context, args->qp_init_attr_ex);
}

void call_ibv_query_device_ex(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_device_ex\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_device_ex_t * args = (uhyve_ibv_query_device_ex_t *) (guest_mem + data);

	args->ret = ibv_query_device_ex(args->context, args->input, args->attr);
}

void call_ibv_open_qp(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_open_qp\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_open_qp_t * args = (uhyve_ibv_open_qp_t *) (guest_mem + data);

	args->ret = ibv_open_qp(args->context, args->qp_open_attr);
}

void call_ibv_modify_qp(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_modify_qp\n");

	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_modify_qp_t * args = (uhyve_ibv_modify_qp_t *) (guest_mem + data);

	args->ret = ibv_modify_qp(args->qp, args->attr, args->attr_mask);
}

void call_ibv_query_qp(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_query_qp\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_query_qp_t * args = (uhyve_ibv_query_qp_t *) (guest_mem + data);

	args->ret = ibv_query_qp(args->qp, args->attr, args->attr_mask, args->init_attr);
}

void call_ibv_destroy_qp(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_destroy_qp\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_destroy_qp_t * args = (uhyve_ibv_destroy_qp_t *) (guest_mem + data);

	args->ret = ibv_destroy_qp(args->qp);
}

void call_ibv_post_send(struct kvm_run * run, uint8_t * guest_mem) {
	/* printf("UHYVE call: call_ibv_post_send\n"); */
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_post_send_t * args = (uhyve_ibv_post_send_t *) (guest_mem + data);

	args->ret = ibv_post_send(args->qp, args->wr, args->bad_wr);
}

void call_ibv_post_recv(struct kvm_run * run, uint8_t * guest_mem) {
	/* printf("UHYVE call: call_ibv_post_recv\n"); */
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_post_recv_t * args = (uhyve_ibv_post_recv_t *) (guest_mem + data);

	args->ret = ibv_post_recv(args->qp, args->wr, args->bad_wr);
}

void call_ibv_create_ah(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_ah\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_ah_t * args = (uhyve_ibv_create_ah_t *) (guest_mem + data);

	args->ret = ibv_create_ah(args->pd, args->attr);
}

void call_ibv_init_ah_from_wc(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_init_ah_from_wc\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_init_ah_from_wc_t * args = (uhyve_ibv_init_ah_from_wc_t *) (guest_mem + data);

	args->ret = ibv_init_ah_from_wc(args->context, args->port_num, args->wc, args->grh, args->ah_attr);
}

void call_ibv_create_ah_from_wc(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_create_ah_from_wc\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_ah_from_wc_t * args = (uhyve_ibv_create_ah_from_wc_t *) (guest_mem + data);

	args->ret = ibv_create_ah_from_wc(args->pd, args->wc, args->grh, args->port_num);
}

void call_ibv_destroy_ah(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_destroy_ah\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_destroy_ah_t * args = (uhyve_ibv_destroy_ah_t *) (guest_mem + data);

	args->ret = ibv_destroy_ah(args->ah);
}

void call_ibv_attach_mcast(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_attach_mcast\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_attach_mcast_t * args = (uhyve_ibv_attach_mcast_t *) (guest_mem + data);

	args->ret = ibv_attach_mcast(args->qp, args->gid, args->lid);
}

void call_ibv_detach_mcast(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_detach_mcast\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_detach_mcast_t * args = (uhyve_ibv_detach_mcast_t *) (guest_mem + data);

	args->ret = ibv_detach_mcast(args->qp, args->gid, args->lid);
}

void call_ibv_fork_init(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_fork_init\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_fork_init_t * args = (uhyve_ibv_fork_init_t *) (guest_mem + data);

	args->ret = ibv_fork_init();
}

void call_ibv_node_type_str(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_node_type_str\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_node_type_str_t * args = (uhyve_ibv_node_type_str_t *) (guest_mem + data);

	const char * host_ret = ibv_node_type_str(args->node_type); // !
	memcpy(args->ret, host_ret, sizeof(host_ret)); // !
}

void call_ibv_port_state_str(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_port_state_str\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_port_state_str_t * args = (uhyve_ibv_port_state_str_t *) (guest_mem + data);

	const char * host_ret = ibv_port_state_str(args->port_state); // !
	memcpy(args->ret, host_ret, sizeof(host_ret)); // !
}

void call_ibv_event_type_str(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_event_type_str\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_event_type_str_t * args = (uhyve_ibv_event_type_str_t *) (guest_mem + data);

	const char * host_ret = ibv_event_type_str(args->event); // !
	memcpy(args->ret, host_ret, sizeof(host_ret)); // !

}

void call_ibv_is_qpt_supported(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_is_qpt_supported\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_is_qpt_supported_t * args = (uhyve_ibv_is_qpt_supported_t *) (guest_mem + data);

	args->ret = ibv_is_qpt_supported(args->caps, args->qpt);
}

void call_ibv_get_mr_lkey(struct kvm_run * run, uint8_t * guest_mem) {
	/* printf("UHYVE call: call_ibv_get_mr_lkey\n"); */
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_mr_lkey_t * args = (uhyve_ibv_get_mr_lkey_t *) (guest_mem + data);

	args->ret = args->mr->lkey;
}

void call_ibv_get_qp_num(struct kvm_run * run, uint8_t * guest_mem) {
	printf("UHYVE call: call_ibv_get_qp_num\n");
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_get_qp_num_t * args = (uhyve_ibv_get_qp_num_t *) (guest_mem + data);

	args->ret = args->qp->qp_num;
}



void call_ibv_cq_ex_to_cq(struct kvm_run * run, uint8_t * guest_mem) {
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_cq_ex_to_cq_t * args = (uhyve_ibv_cq_ex_to_cq_t *) (guest_mem + data);

	args->ret = ibv_cq_ex_to_cq(args->cq);
}

void call_ibv_start_poll(struct kvm_run * run, uint8_t * guest_mem) {
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_start_poll_t * args = (uhyve_ibv_start_poll_t *) (guest_mem + data);

	args->ret = ibv_start_poll(args->cq, args->attr);
}

void call_ibv_next_poll(struct kvm_run * run, uint8_t * guest_mem) {
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_next_poll_t * args = (uhyve_ibv_next_poll_t *) (guest_mem + data);

	args->ret = ibv_next_poll(args->cq);
}

void call_ibv_end_poll(struct kvm_run * run, uint8_t * guest_mem) {
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_end_poll_t * args = (uhyve_ibv_end_poll_t *) (guest_mem + data);

	ibv_end_poll(args->cq);
}

void call_ibv_wc_read_completion_ts(struct kvm_run * run, uint8_t * guest_mem) {
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_wc_read_completion_ts_t * args = (uhyve_ibv_wc_read_completion_ts_t *) (guest_mem + data);

	args->ret = ibv_wc_read_completion_ts(args->cq);
}

void call_ibv_create_cq_ex(struct kvm_run * run, uint8_t * guest_mem) {
	unsigned data = *((unsigned*) ((size_t) run + run->io.data_offset));
	uhyve_ibv_create_cq_ex_t * args = (uhyve_ibv_create_cq_ex_t *) (guest_mem + data);

	args->ret = ibv_create_cq_ex(args->context, args->cq_attr);
}
