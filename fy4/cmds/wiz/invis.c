#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p") {
		me->set("wiz_invis",1);
		me->set("env/msg_mout","none");
		me->set("env/msg_min","none");
		me->set("env/invisibility",1);
		me->be_ghost(1);
		write("����ɹ���\n");
	}
	else {
		me->delete("wiz_invis");
		me->delete("env/invisibility");
		me->delete("env/msg_mout");
		me->delete("env/msg_min");
		me->be_ghost(0);
		write("ȡ������\n");
	}
	return 1;
}
		
int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	invis [-p][0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ�������������ģʽ��
��1������޷���Finger��Who�����������������
��2��Goto��Go������������ڷ�����ʾ��Ϣ��

[0;1;37m����������������������������������������������������������������[0m 
HELP	);
	return 1;
}