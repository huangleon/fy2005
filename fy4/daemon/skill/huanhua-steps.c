// huanhua-steps.c

inherit SKILL;

void setup() {
	set("name","佻�����");
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("skill_class","npc");
	set("dodge_msg", ({
		"$nһ�С���ˮ�صޡ��������ɵر��˿�ȥ��\n",
		"ֻ��$n��Ӱһ�Σ�һʽ��������̡����ѱ����߳�֮�⡣\n",
		"$nʹ������ת��С����������ɵ�������\n",
		"$n����һ�㣬һ�С���Ӱ�������ڿն��𣬱��˿�ȥ��\n",
		"����$nʹһ�С��綯�񶯡�����������Ʈ�˿�ȥ��\n",
		"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
		"����$nһ�С���ҡ�ɵء�ʹ���������Ƶ�$N���ᣡ\n"
	}) );
}

