// salt
inherit COMBINED_ITEM;
void create()
{
	set_name("�ΰ�", ({ "salt rock", "rock" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"����һ�����������ΰͣ������ܽ���ˮ������򣩾ͳ�����ˮ����������������\n" );
        set("unit", "��");
		set("base_value", 70);
		set("base_unit", "��");
		set("base_weight", 30);
	}
	set_amount(1);
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("ָ���ʽ: pour <�ΰ�> in <װˮ����>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩˮ�Ʋ����ܻ��ΰ͡�\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->set("liquid/name","��ˮ");
	ob->add("liquid/salt_effect", 10);
	message_vision("$N��һЩ" + name() + "���飬����" + ob->name() 
		+ "��ҡ���˼��¡�\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("salt_drug",
		(int)this_player()->query_condition("salt_drug") 
		+ (int)ob->query("liquid/salt_effect") );
	return 0;
}


