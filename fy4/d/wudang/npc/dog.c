// dog.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�����������Ұ����\n");

	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
		"Ұ���ñ�����������Ľš�\n",
		"Ұ������Ľű߰��������ģ����ֶ����ԡ�\n",
		"Ұ��������ҡ��ҡβ�͡�\n",
		"Ұ��������ץ��ץ�Լ��Ķ��䡣\n" }) );
	set("combat_exp",2000);		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

