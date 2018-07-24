#pragma once

void registry_read(LPCTSTR subkey, LPCTSTR name, DWORD type) //Defines the function.
{
	HKEY key;
	TCHAR value[255];
	DWORD value_length = 255;
	RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);
	RegQueryValueEx(key, name, NULL, &type, (LPBYTE)&value, &value_length);
	RegCloseKey(key);
	retrieved = value;
}

unsigned int Hash(const std::string& str) //Defines the function.
{
	unsigned int hash = 0;
	unsigned int x = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = (hash << 4) + str[i];
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}

	return hash;
}

void gethwid()
{
	registry_read("SYSTEM\\CurrentControlSet\\Control\\IDConfigDB\\Hardware Profiles\\0001", "HwProfileGuid", REG_SZ); //Gets a HWID from the current computer.

	hwid = retrieved;

	registry_read("HARDWARE\\DESCRIPTION\\System\\BIOS", "BIOSReleaseDate", REG_SZ); //Gets a HWID from the current computer.

	hwid2 = retrieved;

	registry_read("HARDWARE\\DESCRIPTION\\System\\BIOS", "BaseBoardProduct", REG_SZ); //Gets a HWID from the current computer.

	hwid3 = retrieved;

	hwids = hwid + hwid2 + hwid3;

	hash = Hash(hwids); //Hashes that HWID and stores it in hash.
}