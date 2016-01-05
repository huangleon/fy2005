// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "������" NOR, ({ "supergod" }) );
	set("age", 7006);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 0);
	set("per", 0);

	set("combat_exp", 5000000);
	
	set("NO_KILL","����Ц�ɣ������ϵͳô��\n");
	
	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
        message("system",
                HIW     "����������Ӻ������������ңţ£ϣϣԣ���\n\n" NOR,
                users() );
    call_out("countdown", 60, 5);

}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIR	"\t\t������" + chinese_number(min) + "���Ӻ������������ңţ£ϣϣԣ���\n\n",
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "���������������ңţ£ϣϣԣ�������\n",
			users() );
		call_out("do_shutdown", 3);
	}
}

private void do_shutdown()
{
        object *user, link_ob;
        int i;
        user = users();
        for(i=0; i<sizeof(user); i++) {
                if( !environment(user[i]) ) continue;
                user[i]->save();
                link_ob = user[i]->query_temp("link_ob");
                if( objectp(link_ob) ) link_ob->save();
        }
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n������һ�������ߺޡ����֡���Ұ�ް���������쳹������ա�\n\n"
		HIW "������" HIR "˻�Ƶغ������ɶ��" + ob->name(1) + "����һ���ᱨ��ġ�����\n\n"
			"Ȼ��һ����ɫ�����Х�������ƶˣ�����ָֻ���������\n\n" NOR,
		users() );
	destruct(this_object());
}
