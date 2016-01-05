// begging.c

inherit SKILL;

void setup() {
	set("name","�Ů��");
	set("effective_level",200);
	set("type","knowledge");
	set("skill_class","shenshui");
	set("no_refund", ({"nine-moon-sword","nine-moon-claw" }));
	set("difficulty",200);
	set("no_refund",({"qingpingforce","qingpingsword","chaos-steps"}));
}


int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	if((string)me->query("class") != "shenshui" ) 
		return notify_fail("�Ů������ˮ�����Ӷ��е��书��\n");
	return 1;
}


int help(object me)
{
	write(@HELP   
���Ի�������exert mihunshu��
��ʽ��50���Ů�񹦷���ʹ�ã����������һ�ֲ���������Ѫ����
�˺������Ů�񹦵ȼ���أ��ɹ��ʼ��ߣ����۳ɰܶ�û������æ�ң�
ÿ14��ʹ��һ�Σ�ÿ�κķ�100��������
HELP
    );
    return 1;
}
