#include <ntddk.h>

//Prototypes
void DriverUnload(PDRIVER_OBJECT DriverObject);

NTSTATUS DriverCreateClose(PDEVICE_OBJECT DeviceObject, PIRP Irp);

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject)
{

	//To enabling opening of a handle for this driver
	DriverObject->MajorFunction[IRP_MJ_CREATE] = DriverCreateClose;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = DriverCreateClose;
	

	return STATUS_SUCCESS;
}

void DriverUnload(PDRIVER_OBJECT DriverObject)
{
	//empty for now
}


