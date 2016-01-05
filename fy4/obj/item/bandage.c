
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("����", ({ "bandage"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "��");
		set("base_weight",20);
		set("unit", "��");
		set("volumn",5);
		set("material", "cloth");
		set("armor_type", "bandage");
		set("desc_ext","���ˣ��������壩");
		set("value",0);
	}
	set_amount(5);
}

void init()
{
	add_action("do_bandage", "bandage");
}

int do_bandage(string arg)
{
	object ob,*mem;

	if (this_player()->is_busy())
		return notify_fail("��������æ��\n");

	if( !arg ) ob = this_player();
	else {
		ob = present(arg, environment(this_player()));
		if( !ob || !ob->is_character() )
			return notify_fail("��Ҫ��˭���ˣ�\n");
	}

/*	if( this_player()->is_fighting()
	||	ob->is_fighting() )
		return notify_fail("ս���в��ܹ��ˡ�\n");*/
	
	if (ob!= this_player()) {
		mem = this_player()->query_team();
		if (!pointerp(mem) || member_array(ob,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е��˹��ˡ�\n");
	}
			 
	if( (int)ob->query("eff_kee") == (int)ob->query("max_kee") )
		return notify_fail( (ob==this_player()? "��" : ob->name())+ "��û���ܵ��κ����ˡ�\n");

	if( ob->query_condition("bandaged"))
		return notify_fail( (ob==this_player()? "��" : ob->name())+ "���ϵ����Ѿ��������������ˡ�\n");

	if( ob==this_player() )
		message_vision("$N��" + name() + "���Լ����ˡ�\n", this_player());
	else
		message_vision("$N��" + name() + "��$n���ˡ�\n", this_player(), ob);

	ob->set_temp("pfm/bandaged", this_player()->query_skill("manjianghong",1));
	ob->apply_condition("bandaged", 10);	
	if (ob->is_fighting())
		ob->perform_busy(1);
	add_amount(-1);
	return 1;
}
