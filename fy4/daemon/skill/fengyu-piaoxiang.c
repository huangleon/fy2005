// fengyu-piaoxiang.c  ����Ʈ�㲽

inherit SKILL;
void setup() {
	set("name","����Ʈ�㲽");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","bat");
	set("dodge_msg", ({
		    "$nһ����ĮĮ�����ء�������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
		    "$nʹ��һ�С�ڤڤ��ȥ�١�����Ȼ�������࣬���$N���˸��ա�\n",
		    "$n����һҡ���ó�������Ӱ��һ�С�ɽ�紵���֡������$N�Ĺ��ơ�\n",
		    "$nһ�С�ǧ��ͬһɫ������Ծ��ٿ��������$N���\n",
		    "$n��һҡ����һ�Σ�һ�С�����ȥ�岨��������������\n",
		    "$n˫��һ�㣬бб����ʹ����������֡�������$N��ࡣ\n",
	}) );

}
