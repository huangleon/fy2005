#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("Сɳ��", ({ "sand bag"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "һ��ССССС��ɳ����\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","l");
	set("outdoors",1);
	set("size",1);
	set("value", 100000);
set("tax",10);
set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");

   	add_action("do_look","look");
}


int do_install(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!arg)
		return notify_fail("��Ҫ��װʲô������\n");
	if (present(arg,me) != ob)
		return 0;
	if (!env)
		return notify_fail("����#13107��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("��ͥ��Ʒֻ�������ӵ����˷��á�\n");
	if (env->query("free_space") - query("size") < 0)
		return notify_fail("������û���㹻�Ŀռ���Է���"+name()+"��\n");
	if (env->query("outdoors") && !query("outdoors") )
		return notify_fail(name()+"ֻ�ܱ����������ڡ�\n");
	if (!env->query("outdoors") && query("outdoors") )
		return notify_fail(name()+"ֻ�ܱ����������⡣\n");
	if (query("lore_item") && env->query("item/"+query("item_type")))
		return notify_fail("���ණ��ÿ��������ֻ�ܷ�һ����\n");

	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));


	env->add("tax",query("tax")*7);
	env->add("score_tax",query("score_tax")*100);

	ob = new(__DIR__"sandbag3");
	env->set("item_list/"+env->query("item_index"),base_name(ob));
	ob->move(env);

	env->save();
	write("Ok.\n");
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
