#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("���", ({ "chick girl","girl" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("per", 30);
	set("long", @LONG
����ǣ�������������Ȥ�Ļ����루����������
LONG
);
	set("combat_exp", 2000);
	set("attitude", "friendly");

	setup();
	
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}


int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ���ᣮ��������");
        return 1;
}


void init()
{
	::init();
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
	object me;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
	message_vision("$N���������ڱǿף�Ȼ����$n�߹���������\n",this_object(),me);
	
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        {
        if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		if(!DROP_CMD->do_drop(me, inv[i])) {
			destruct(inv[i]);
		}
	}
	tell_object(me, "�������Щ��������������������պϰɡ�������\n");
	me->unconcious();
	me->apply_condition("hualiu_poison",10+random(20));
	return 1;
}
