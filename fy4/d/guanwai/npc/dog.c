// dog.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�����������Ұ����\n");
	
	set("str", 24);
	set("cor", 26);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
		"Ұ���ñ�����������Ľš�\n",
		"Ұ������Ľű߰��������ģ����ֶ����ԡ�\n",
		"Ұ��������ҡ��ҡβ�͡�\n",
		"Ұ��������ץ��ץ�Լ��Ķ��䡣\n" }) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "���˵���������������\n", environment());
		return 1;
	}
}
