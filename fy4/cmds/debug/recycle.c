#include <ansi.h>
inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist, *ilist;
	int i, j=0;
	int k=0, num;
	string file;
	
 	ulist = objects();
	i = sizeof(ulist);
	write(HIR"\n����������Ʒ�б�����\n"NOR);
	while (i--) {
		if (!ulist[i])
			continue;
		if (environment(ulist[i]))
			continue;
		if (ulist[i]->query("short"))
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// ��֪����ʲô����
			continue;
		if (ulist[i]->query("kee"))
			k++;
		else
			j++;
		if (!arg || arg != "-s")
		{
			write("�ݻ����޻�����"+ulist[i]->query("name")+"("+ulist[i]->query("id")+")");
			write ("��\n");
		}
		destruct(ulist[i]);
	}
	write(HIG"���������������\n"NOR);
	write(HIW"һ�������"+(j+k)+"���޻�������Ʒ��������"+k+"�������\n\n"NOR);
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	recycle[-s] [0m
[0;1;37m����������������������������������������������������������������[0m   

�����޻�����������Ʒ��
* ��ָ��δ���濼����ʹ��ǰ��ע�������������	 annie.08.2003

[0;1;37m����������������������������������������������������������������[0m   
HELP
);
        return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

