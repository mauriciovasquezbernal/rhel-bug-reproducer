// +build ignore

#include "vmlinux2.h"
#include "bpf/bpf_helpers.h"
#include "bpf/bpf_core_read.h"

SEC("tracepoint/syscalls/sys_exit_execve")
int ig_execve_x(struct trace_event_raw_sys_exit *ctx)
{
	// This line doesn't work. (max_ctx_offse: 32)
	bpf_printk("ret is %ld", ctx->ret);

	// This one works. (max_ctx_offset: 24)
	//bpf_printk("id is %ld", ctx->id);

	return 0;
}

char LICENSE[] SEC("license") = "GPL";
