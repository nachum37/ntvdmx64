typedef struct _KEY_VALUE_PARTIAL_INFORMATION {
	ULONG TitleIndex;
	ULONG Type;
	ULONG DataLength;
	UCHAR Data[1];
} KEY_VALUE_PARTIAL_INFORMATION, *PKEY_VALUE_PARTIAL_INFORMATION;

typedef struct _KEY_VALUE_FULL_INFORMATION {
	ULONG   TitleIndex;
	ULONG   Type;
	ULONG   DataOffset;
	ULONG   DataLength;
	ULONG   NameLength;
	WCHAR   Name[1];
} KEY_VALUE_FULL_INFORMATION, *PKEY_VALUE_FULL_INFORMATION;


typedef enum _KEY_VALUE_INFORMATION_CLASS {
	KeyValueBasicInformation,
	KeyValueFullInformation,
	KeyValuePartialInformation,
	KeyValueFullInformationAlign64,
	KeyValuePartialInformationAlign64
} KEY_VALUE_INFORMATION_CLASS;

NTSYSAPI NTSTATUS NTAPI NtQueryValueKey(HANDLE, const UNICODE_STRING *, KEY_VALUE_INFORMATION_CLASS, void *, DWORD, DWORD *);
NTSYSAPI NTSTATUS NTAPI NtCreateKey(PHANDLE, ACCESS_MASK, const OBJECT_ATTRIBUTES*, ULONG, const UNICODE_STRING*, ULONG, PULONG);
NTSYSAPI NTSTATUS NTAPI NtSetValueKey(HANDLE, const UNICODE_STRING *, ULONG, ULONG, const void *, ULONG);
NTSYSAPI NTSTATUS NTAPI NtOpenKey(OUT PHANDLE pKeyHandle, IN ACCESS_MASK DesiredAccess, IN POBJECT_ATTRIBUTES ObjectAttributes);
