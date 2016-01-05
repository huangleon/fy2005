#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"����ʴ�ǲ�"NOR, ({ "grass","herb" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "grass");
            set("long", "һ�����ɫ��С�ݣ���Լ͸��һ��������\n");
			set("desc_ext", "���ݣ�pour��"); 
			set("no_stack",1);
			set("real",1);
			set("value",0);
			set("lore",1);
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
		return notify_fail("ָ���ʽ: pour <��Ʒ> in <��Ʒ>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩˮ���ܳ忪��ҩ��\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	message_vision("$N��һЩ" + name() + "�Ž�" + ob->name() 
		+ "�����һ"+ob->query("unit")+"ҩ�ơ�\n", this_player());
	ob->set("liquid/name","ҩ��");
	destruct(this_object());
	return 1;
}

int drink_drug(object ob)
{
	object me = this_player();
	message_vision(HIR"\n$N��������ͻȻ������Ѫ�����Ӷ�ʧ���ģ����ڵ��ϡ�\n\n"NOR,me);
	me->set_temp("last_damage_from","�����ƶ�����");
	me->die();
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
