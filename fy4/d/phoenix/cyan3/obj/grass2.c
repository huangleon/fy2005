#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�ݴ�", ({ "grass"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("long", "ϸխˮ�������ߣ���̵�Ұ�ݳ��÷���ï�ܡ�\n");
	set("desc", "��̵�Ұ�ݳ��÷���ï�ܡ�\n");
	set("no_sell",1);
	set("no_stack",1);
	set("no_reset",1);
		set("no_drop",1); 
	set("item_type","j");
	set("outdoors",1);
	set("size",1);
	set("lore",1);
	set("value", 0);
	seteuid(getuid());
}

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");

	if (environment()->query("short") != "����")
	{
		set("no_shown",0);
		add_action("do_look","look");
		add_action("do_dismantle","dismantle");
	}
	else
		set("no_shown",1);

}

int reset_item_list(object dest);

int do_dismantle(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	object *inv;
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	if (!env)
		return notify_fail("����#13106��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("��ͥ��Ʒֻ�������ӵ����˲����\n");
	if (!present("fatangel statue",me))
		return notify_fail("��û�к��ʵĹ����Խ��в����\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("����#13108��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	message_vision(CYN"$Nһ��������������ʹ��ʯ����"+name()+"����ȥ�������¾Ͱ�"+name()+"�ҵ�ϡ�á�\n\n"NOR,me);
//	env->add("item_index",-1);	
	inv = all_inventory(ob);
	while (sizeof(inv))
	{
		inv = all_inventory(ob);
		destruct(inv[0]);
	}
	ob->reset_item_list(ob);

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = env->query("item_list/"+lists[i]);
		if (mitem == base_name(ob))
			env->delete("item_list/"+lists[i]);
	}
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));
	env->save();
	destruct(ob);
	destruct(present("fatangel statue",me));
	return 1;	
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
	if (wizardp(this_player()))
		set("long",query("desc")+"��ϸ��ȥ����Լ�ɼ�����С�֣��������졣\n");
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
	move(env);
	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));
	env->set("item_list/"+env->query("item_index"),base_name(ob));

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
