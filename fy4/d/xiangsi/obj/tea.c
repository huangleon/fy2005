// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("�׺�", ({ "tea", "bai hao", "baihao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("long", "����ɫ�Ĳ�Ҷ�ϴ�������ɫ����ë�������������˱ǡ�
����ˮ�����忪������һյ�ò衣��pour��\n");// ����ɹ��...
                set("value", 40);
                set("����", 1);
        }
	::init_item();
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
		return notify_fail("ָ���ʽ: pour <��Ҷ> in <��Ʒ>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩ��ˮ���ܳ忪��Ҷ��\n");
	if(ob->query("liquid/name") != "��ˮ")
		return notify_fail("ֻ�У���ˮ�����ܳ忪��Ҷ��\n");
	if (ob->query("liquid/remaining") > 30)
		return notify_fail("��ôһ�����Ҷ����ô����ô��ˮ�壿\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/kuzhu", 1+random(8));
	message_vision("$N��һЩ" + name() + "�Ž�" + ob->name() 
		+ "�����һ"+ob->query("unit")+"�²衣\n", this_player());
	ob->set("liquid/name","�׺�");
	destruct(this_object());
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("kuzhu",
		(int)this_player()->query_condition("kuzhu") 
		+ (int)ob->query("liquid/kuzhu") );
	return 0;
}
