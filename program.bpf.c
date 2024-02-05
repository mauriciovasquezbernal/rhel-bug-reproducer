// +build ignore

#include "vmlinux.h"
#include "bpf/bpf_helpers.h"
#include "bpf/bpf_core_read.h"

SEC("tracepoint/syscalls/sys_exit_execve")
int ig_execve_x(struct trace_event_raw_sys_exit *ctx)
{
	bpf_printk("retval is %ld", ctx->ret);
	return 0;
}

char LICENSE[] SEC("license") = "GPL";
