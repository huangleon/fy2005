// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("С��", ({ "xiao wu","wu","xiaowu" }) );
        set("title",RED"��Ҷ��"NOR);
		set("nickname",WHT"�Ӵ˲��ٵ���"NOR);
        set("gender", "Ů��" );

//		set("group","couple");

		set("age",16);

set("long","С��ԭ�����ޣ��������ǰһλ����ͬ�������Ժ�ΪС�ޡ�ֻ����
�������Ǹ�ϲ��������û�С���������Ϊ�޾���û�У�������Ϊ��
���ֵ�ʱ����ͻ�û�з��գ������˵�ʱ����ͻ�û��΢Ц��
�������˸����������������һ����Ӵˡ�û�С���
\n");

	set("chat_chance",1);
	set("chat_msg", ({
		"С������Զɽ�����Ƶ�����ô�����ˣ���������С�����ѵ�����֪��������û���ҩ�óԵ�ô��\n",
		"С��΢Ц�����Ҳ���˵��ô���޵õ�����һ��ͷ�ͳ������������ԣ����Ǳ㲻Ҫ�ٻ�ͷ��\n",
		"С��ҡ��ҡͷ�����������£����������ֻ�ܶ��Լ����ûڵġ�\n",
	}) );

        set("reward_npc", 1);
        set("difficulty",11);	// Big big npc.

		set("no_arrest",1);

        set("combat_exp", 10000000);
		set("class","moon");

		set_skill("force",320);
		set_skill("divineforce",200);
		map_skill("force","divineforce");


		set_skill("dodge",320);
		set_skill("stormdance",200);
		map_skill("dodge","stormdance");

		set_skill("sword",320);
		set_skill("qiuzhi-sword",200);
		map_skill("sword","qiuzhi-sword");

		set_skill("parry",320);
		map_skill("parry","qiuzhi-sword");


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

		setup();

        carry_object(__DIR__"obj/xiaosword")->wield();
        carry_object(__DIR__"obj/xiaocloth")->wear();

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
	ccommand("perform hanmeiluo");
}


void die()
{
	object me = this_object();
	object he;
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");

	message_vision(CYN"\nС���½���磬��ܵ������±�"NOR,me);

	he = present("xiao fang",environment());
	if (he)
		message_vision(CYN"������ؿ���$Nһ�ۣ���ǻ�����һ˿ǳǳ��΢Ц��\n\n"NOR,he);
	else
		message_vision(CYN"��\n\n"NOR,me);
	message_vision(HIB"С������غ���һ������ת�������±�Ծ�£���ɫ����ȹ�ڷ�������һֻ����ĺ�����\n\n"NOR,me);
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


	message_vision(CYN"С�޵���ɫһ����ת˲����չ¶�����õ�Ц�ݣ��������$N�������ա�\n\n"NOR,he);
	message_vision(CYN"С���۲���ת����Ц�����Ⱳ���Ҳ���ԭ���㡣Ȼ���ҿ��Ը���һ�����ᡭ��\n\n"NOR,he);
	message_vision(CYN"$N�ֳ���ο����ɫ���ӵ����������±��ӻ���һ��\n\n"NOR,he);
	message_vision(HIY"$NͬС�����Ӷ�Ц��˫˫�����±�Ծ�£�һ��΢�������Ӵ˲����ټ���\n\n"NOR,he);

	move(room);
	::die();
}
