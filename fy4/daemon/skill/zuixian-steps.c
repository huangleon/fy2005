// zuixian-steps.c
inherit SKILL;

void setup() {
	set("name","�������²�");
	set("practice_limit",100);
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("difficulty",200);
	set("skill_class","yinshi");
	set("dodge_msg",			({
			"����$n����Ʈ��������һ�ݣ�һ�С��������¡�������׾ٵıܿ���һ����\n",
			"$n������ת��һʽ�����˾��ơ������Դܿ����ߣ����˿�ȥ��\n",
			"$n�������ϰ���һ�С��ѾƷ��ɡ���һ��ת����������֮�⡣\n"
			})
	);
}


int help(object me)
{
	write(@HELP   
L100	��������ơ���dodge.baxianzuijiu�������������
HELP
    );
    return 1;
}
