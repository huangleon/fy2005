// mind_beast.c

inherit NPC;

void create()
{
	set_name("����", ({ "heaven lion", "lion" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 3);
	set("long", "�����ͨ����ǳ����ɫ��������ʨ��ʨ���������\n");
	
	set("str", 48);
	
	set("combat_exp", 200000);
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 140);

	setup();
}

void init()
{
	object me;
	me = this_player();
	if( interactive(me))
                if( me->query("class") )
                if( me->query("class") != "yinshi") 
		kill_ob(me);

}
