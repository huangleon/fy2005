#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "jiang jun" }) );
        set("gender", "����");
        set("class", "ghost");
        create_family("����ɽׯ", 2, "����");
        set("combat_exp", 50000);
        set("reward_npc", 1);
	set("difficulty", 1);
        set("no_arrest",1);
        set("long",
		"��߰˳߰˴磬����һ����ʮ�����磬���أ�˫�ȴ������ɡ�\n"
	);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 100);
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 100);
        set_skill("bloodystrike", 100);
	map_skill("iron-cloth", "jin-gang");
	map_skill("unarmed", "bloodystrike");
        setup();
	carry_object(__DIR__"obj/cloth2")->wear();

}

void init()
{
	object	me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
	if (!objectp(me) || environment(me)!= environment() || me->is_ghost()) 
		return 1;
	if( (string)me->query("family/family_name")!="����ɽׯ" ) {
		message_vision(HIY "\n$N����ľ�׶�$n�ȵ���" + me->name() + "���������⣡��������\n"NOR, this_object(), me);
	}
	return 1;
}
