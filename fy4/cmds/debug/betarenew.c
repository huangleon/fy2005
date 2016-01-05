// exert.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *cont = ({ "betrayal", "divorced", "marry", "m_success", "marks", "timer", 
				"death", "family" });
 	if (!arg)
 		return notify_fail("help renew1\n");
	if (member_array(arg, cont)==-1)
		return notify_fail("�ο�help betarenew\n");
 	if (arg == "death")
 		me->delete("attr_apply/strength");
 	else if (arg == "class" || arg == "family") {
 		me->delete("family");
 		me->delete("once_menpai");
 		me->delete("class");
 		me->delete("betrayal");
 	} else
 		me->delete(arg);
 	write("���"+arg+"��¼������ˡ�\n");
 	return 1; 
}


int help (object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ��renew1 <����> [0m
[0;1;37m����������������������������������������������������������������[0m

�������ר��ָ�ȥ�������йؼǺ�

betarenew betrayal : ��	ȥ����ʦ��¼
betarenew divorced :�� 	ȥ������¼
betarenew marry		ȥ������¼
betarenew m_success	ȥ���콾��¼
betarenew marks		ȥ�����������¼(�����updateһ���Լ�)
betarenew timer		ȥ������ʱ�����Ƽ�¼������ghostcurse�ģ�
betarenew death		ȥ������str penalty
betarenew family	ȥ�����а�ʦ��¼

[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
