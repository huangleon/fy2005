// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("С��", ({ "xiao fang","fang","xiaofang" }) );
        set("title",RED"��Ҷ��"NOR);
		set("nickname",WHT"ֻ����������"NOR);
        set("gender", "����" );

//		set("group","couple");

		set("age",16);

set("long","\n");

	set("chat_chance",1);
	set("chat_msg", ({
		"С��ɦ��ͷ˵������Ĳ�Ը�����һ�λ��ᣬ���������ǹ�ȥ�����¿�ʼ��\n",
		"С��̾����ֻ������֮���̣��ұ㿪ʼ����ˣ���ڵ����Ը��ӡ�\n",
		"С����Ц�����ҴӲ������㡣����������һ�β��У�\n",
	}) );

        set("reward_npc", 1);
        set("difficulty",11);	// Big big npc.

		set("no_arrest",1);

        set("combat_exp", 10000000);
		set("class","wudang");

		set_skill("changelaw",320);

		set_skill("force",320);
		set_skill("divineforce",200);
		map_skill("force","divineforce");


		set_skill("dodge",320);
		set_skill("stormdance",200);
		map_skill("dodge","stormdance");

		set_skill("sword",320);
		set_skill("taiji-sword",240);
		map_skill("sword","taiji-sword");

		set_skill("parry",320);
		map_skill("parry","taiji-sword");


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

		setup();

        carry_object(__DIR__"obj/xiaosword2")->wield();
        carry_object(__DIR__"obj/xiaocloth2")->wear();

}


void smart_fight()
{
	object me,target;
	me = this_object();
	target = select_opponent();

	if (ccommand("perform force.check_gspm"))
	{
		ccommand("perform force.guishenpomie");
		stop_busy();
		return;
	}
	ccommand("perform sancai");
}


void die()
{
	object me = this_object();
	object he;
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");

	message_vision(CYN"\nС������ײײ����ܵ������±�"NOR,me);

	he = present("xiao wu",environment());
	if (he)
		message_vision(CYN"����������$N�����մ����Ѫ�����ơ�\n\n"NOR,he);
	else
	{
		message_vision(CYN"��\n\n"NOR,me);
	message_vision(CYN"С��̾�˿�����������������������һ�μ����㣮��\n\n"NOR,me);
	message_vision(HIB"С��һŤͷ��������ֱԾ���£�������ʧ����Ӱ��\n\n"NOR,me);
	}
	if (he)
		he->icic(me);
	
	move(room);
	::die();

}

int icic(object he)
{
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");


	message_vision(CYN"С��һ�������������������±ߣ�Ȼ��ֻ�а�����磬�������޶��ǻ���\n\n"NOR,he);
	message_vision(HIY"С��������ס���г���������������Ȼ���һ����������£�����\n\n"NOR,he);

	move(room);
	::die();
}
