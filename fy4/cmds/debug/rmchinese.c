inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;
        if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��rmchinese <Ӣ��>\n");

	if( sscanf(arg, "<%s>", key)==1 ) {
		CHINESE_D->remove_translate(key);
		write( "remove " + key + "\nOk.\n");
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	rmchinese <Ӣ��>[0m
[0;1;37m����������������������������������������������������������������[0m   
ָ���ʽ��rmchinese <Ӣ��>

[0;1;37m����������������������������������������������������������������[0m   
HELP
	);
	return 1 ;
}
