bool isLower(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}
bool isUpper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}


char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 'a' + (c - 'A');
	}
	return c;
}

char toUpper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return 'A' + (c - 'a');
	}
	return c;
}