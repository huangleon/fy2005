// purge.c

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string file;
	string *tmp;
	int loop;
        if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
	file = read_file(arg);
	tmp = explode(file,"\n");
	for(loop=0; loop<sizeof(tmp); loop++)
	{
	write(tmp[loop]+"\n");
	write_file("/"+tmp[loop],"",1);	
	}
	return 1;
}
