// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void heal();

void create()
{	
	object weapon;
	set_name("СС����", ({ "healer"}) );
	set("combat_exp", 4000000);
	set("str",-100);
	set("attitude", "friendly");
	set("long","һ��ССССС���ˡ�\n");
	set("no_arrest",1);
	set("no_fly",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: heal() :),
	}) );
	set("chat_chance", 100);
	set("chat_msg", ({
		   (: heal() :),
	}) );

	setup();
}

void heal()
{
	object owner,me = this_object();
	owner = query("owner");
	if (environment() == environment(owner) && owner->is_fighting())
	{
		message_vision(CYN"$N�ɿ����$n��ߴ�����ȥ�������ű�ѩ����$n���ϡ�\n"NOR,me,owner);
		owner->receive_fulling("gin",500);		
		owner->receive_fulling("kee",500);		
		owner->receive_fulling("sen",500);		
		perform_busy(2);
	}
	else
	{
		message_vision(CYN"$N����һ�����ѩ����ȥ�ˡ�\n"NOR,me);
		destruct(this_object());
	}
}
