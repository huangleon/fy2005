#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("Խ�ٵ�", ({ "bilberry lawn"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set_max_encumbrance(10000);
	set("unit", "Ƭ");
	set("desc", "һƬ���ǵ��׺��Խ�ٵ������Ƥ��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","h");
	set("outdoors",1);
	set("size",1);
set("tax",10);
set("score_tax",1);
	set("value", 100000);
	seteuid(getuid());
}

int is_container(){	return 1;}

int do_putitem(string arg)
{
	object me = this_player(),dest=this_object();
	string target, item;
	object obj, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��ʲ�ᶫ���Ž����\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");

	if (present(target,environment(me)) != dest)
		return 0;
	
	write("�뱣�ֻ�����࣬��Ҫ��������"+name()+"���Ҷ���\n");
	return 1;
}

int reset_item_list(object dest)
{
	return 1;
}

int do_pick(string arg)
{
 	object me = this_player(),env=environment(me),ob=this_object(),herb,*inv;

	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	if (!arg)
		return 0;
	if (arg != "bilberry")
		return 0;
	if (query("pick_time") + 60 > time())
		return notify_fail("Խ�ٵ���ֻʣ��һЩ���̵ľ��ˣ��Ĺ����ǰɣ�����\n");

	inv = all_inventory(ob);
	if (sizeof(inv))
		return notify_fail( "Խ�ٵ����Ѿ���ЩԽ�ٱ�ժ�����ˡ�\n");

	message_vision(CYN"\n$N��Խ�ٵ���ժ����һЩС���Ƶ�Խ�١�\n"NOR, me);
	set("pick_time",time());
	herb = new(__DIR__"bilberry.c");
	herb->set_amount(5);
	herb->move(ob);
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
