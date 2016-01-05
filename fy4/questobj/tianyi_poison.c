// TIE@FY3
#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
	set_name(HIW"��һ��ˮ"NOR, ({ "tianyi poison", "poison" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ����ɫ����ζ���涾�ޱȵ�Һ�壬���Ե���(di)�ھ�ˮ֮�к��ˡ�\n" );
		set("unit", "��");
//        set("base_value", 700);
		set("base_unit", "��");
		set("base_weight", 30);
	}
	set_amount(1);
}
void init()
{
	add_action("do_pour", "di");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("ָ���ʽ: di <��ˮ> in <��Ʒ>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩҺ��ſ��ԡ�\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/slumber_effect", 100);
	message_vision("$N��һ��" + name() + "С������ص���" + ob->name() 
		+ "��ҡ���˼��¡�\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("tianyi",
		(int)this_player()->query_condition("tianyi") 
		+ (int)ob->query("liquid/slumber_effect") );
	return 0;
}
