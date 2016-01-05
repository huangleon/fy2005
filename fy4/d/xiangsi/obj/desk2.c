
#include <ansi.h>
inherit ITEM;
int do_put(object me,object obj,object  dest);

void create()
{
	set_name("ױ̨", ({"ױ̨","̨","desk","table"}) );
	set_weight(500);
	set_max_encumbrance(850);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("cat",1);
		set("long", "һ��СС�Ļ���ľױ̨��ױ̨��ſ��һֻ���ڴ�����Сè�䡣\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

void init()
{
	add_action("do_putitem","put");
}

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

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ���\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û��������" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_put(me, obj2, dest))
				{
					obj->set_amount( (int)obj->query_amount() - amount );
					return 1;
				}		
				if (obj2) destruct(obj2);
				return 0;
		}
	}

	if(item=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest  && !inv[i]->query("no_drop")) 
			do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_put(me, obj, dest);
}


int do_put(object me, object obj, object dest)
{
	string prep;
	int container_size;
	mixed *info;
	object cat;
	info = filter_array(call_out_info(), (: $1[0]==$2 :), obj);
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
                return notify_fail("�㲻������ô����\n");
	if (obj->is_container())
		return notify_fail("�㲻�ܰ�����������һ�������\n");	

	if( obj == dest)
			return notify_fail("�㲻������ô����\n");
	
	if(dest->is_closed())
		return notify_fail("��Ҫ�Ȱ�" + dest->name() + "�򿪡�\n");

	container_size = 2;

	if(sizeof(all_inventory(dest)) >= container_size)
	{
		tell_object(me,dest->name() + "�������ֻ�ܷ�" + chinese_number(container_size) +
				"����Ʒ��\n");
		return 1;
	}
	
	switch((string)dest->query("prep")) {
		case "on" :
			prep = "����" + dest->name() + "��";
			break;
		case "under" :
			prep = "����" + dest->name() + "��";
			break;
		case "behind" :
			prep = "����" + dest->name() + "����";
			break;
		case "insdie" :
			prep = "�Ž�" + dest->name() + "����";
			break;
		default :
			prep = "�Ž�" + dest->name() + "����";
			break;
	}
	if( obj->move(dest) ) {
		message_vision( sprintf("$N��һ%s%s%s��\n",
			obj->query("unit"), obj->name(), prep),
			me );
		if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore"))
			dest->add("no_give",1);

		if (obj->query("name") == "����������" && query("cat") == 1)
		{	
			cat=present("catty",dest);
			if (me->query_temp("annie/xiangsi_master") >= 3 && cat)
			{
				set("long", "һ��СС�Ļ���ľױ̨��\n");
				destruct(cat);
				set("cat",0);
				message_vision(CYN"Сè���˳���������۾�����צ����������䡣\n"NOR,me);
				message_vision(CYN"Сȩ̀�ۿ��˿�$N�����𿾴������⣢���һ�����˿�ȥ��\n"NOR,me);
				me->set_temp("annie/xiangsi_master",4);
				message_vision(CYN"\n�㿴��ԭ��Сèſ�ŵĵط��ƺ��и�ѹ�ñ���Сֽ��������\n\n"NOR,me);
				cat=new(__DIR__"drug");
				cat->move(dest);
				destruct(obj);
			}
		}

		return 1;
	}
	else return 0;
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
