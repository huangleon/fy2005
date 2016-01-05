inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;
        if(!me->query("env/yesiknow")) return notify_fail("’‚∏ˆ÷∏¡Ó“—æ≠±ª∑œ≥˝¡À£°\n");
	if( !arg || arg=="" )
		return notify_fail("÷∏¡Ó∏Ò Ω£∫chinese <”¢Œƒ>==<÷–Œƒ>\n");

	if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		CHINESE_D->add_translate(key, chinz);
		write( key + " == " + chinz + "\nOk.\n");
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36mŒ◊ ¶÷∏¡Ó∏Ò Ω : 	chinese <”¢Œƒ>==<÷–Œƒ>[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

÷∏¡Ó∏Ò Ω£∫chinese <”¢Œƒ>==<÷–Œƒ>

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

HELP
	);
	return 1 ;
}
