// annie 07.2003


inherit SKILL;
void setup(){
	set("name","���鰵ʶ");
	set("skill_class","legend");
	set("type","knowledge");
	set("effective_level",150);
	set("difficulty",120);
}

int valid_learn(object me)
{
	if (me->query("class")!= "legend")
		return notify_fail("Ψ����ѩ���ӷ����������鰵ʶ֮����\n");
	return ::valid_learn(me);
}

int help(object me)
{
	write(@HELP   
���鰵ʶ����ѩ�����书�Ļ������ܹ��������ɱ��ʱ�̸赶�͵���
�������˺�����L100������ÿ10������1�����ܹ�����20��
HELP
    );
    return 1;
}
