inherit SKILL;

void setup() {
	set("name","���㸡Ӱ");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",175);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","huashan");
	set("dodge_msg", ({
		"$n���������������Ʈ���÷���꣬����Ʈ�˿�ȥ��\n",
		"ֻ��$n������΢�ۣ�һʽ��ѩѹ÷֦���������ɱ��˿�ȥ��\n",
		"$n����һ�㣬�����ڿն���ǡ���ּ��仨������������\n",
		"$n���һ���������˺��˰˳ߣ����ɾ���Ư�������䡣\n",
	}) );
}


int help(object me)
{
	write(@HELP   
L50	��ҹѩ������(dodge.yexuechuji)
�����æ�����غϣ����ʧ��������æ�����غ�
HELP
    );
    return 1;
}
