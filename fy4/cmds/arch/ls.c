// ls.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col;
	string dir;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
		else
		return notify_fail("û�����Ŀ¼��\n");
	}

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
	}
	write("Ŀ¼��" + dir + "\n");
	col = 70 / (w+6);
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
			printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
				file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
				((i+1)%col)?"  ":"\n");
	else write("    û���κε�����\n");
	write("\n");
	
	return 1;	
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	ls [<·����>][0m
[0;1;37m����������������������������������������������������������������[0m   

�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
 
��:
'ls /' ���г�����λ춸�Ŀ¼�µĵ�������Ŀ¼.

[0;1;37m����������������������������������������������������������������[0m 
 
HELP
	);
	return 1;
}
