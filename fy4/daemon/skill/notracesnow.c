// notracesnow.c

inherit SKILL;
void setup(){
	set("name","̤ѩ�޺�");
	set("practice_limit",100);
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("difficulty",200);
	set("skill_class","taoist");
	set("dodge_msg", ({
	        "$nһ�С�Ϧ����ѩ���������ɵر��˿�ȥ��\n",
	        "ֻ��$n��Ӱһ�Σ�һʽ�����Ƽ������ѱ����߳�֮�⡣\n",
	        "$nʹ�����������졹���������ɵ�������\n",
	        "$n����һ�㣬һ�С������ƶˡ��ڿն��𣬱��˿�ȥ��\n",
	        "����$nʹһ�С�̤ѩ�޺ۡ�����������Ʈ�˿�ȥ��\n",
	        "$n��Ӱ΢�����Ѿ���һ�С������������������\n"
	}) );
}

int help(object me)
{
	write(@HELP   
L30�������ѩ����mantianfeixue�����������������
HELP
    );
    return 1;
}
