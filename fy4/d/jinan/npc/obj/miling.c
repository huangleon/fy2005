#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"����"NOR, ({ "secret order" }) );
	set_weight(1972);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "paper");
        set("long", "
һ����Ѻ�������õ������δ��֪����ӡ��û���κο�����֤����
�Ϸ���ǩ��������԰����������˿���show��\n");
	}
    ::init_item();
}

void init()
{
        add_action("do_show", "show");
        add_action("do_look","look");
}
void del_show_order(object ob)
{
	if (ob){
		ob->delete_temp("show_order");
		if (environment(ob)->query("jinan_prison"))
			tell_object(ob,YEL"������һ�����ӵĽŲ������ƺ����������Ѿ��������ġ�\n"NOR);
	}	
	destruct(this_object());
	return;
}

int do_look (string arg)
{
	string str;
	str="һ����Ѻ�������õ����\n";
	if (arg=="secret order")
	{

	if (this_object()->query("sealed")!=1)
		str += "��δ��֪����ӡ��\n";
	else 
		str += "�������һ��֪����ӡ��\n";

	if (crypt(query("real")+"3","wHGJZgPRCuvVs") == "wHGJZgPRCuvVs")
		str += "�������ɷ����д���������֣�������\n";
	else 
		str += "û���κο�����֤����Ϸ���ǩ����\n";

	str += "����԰����������˿���show��\n";
	tell_object(this_player(),str);
	return 1;
	}
	return 0;
}	

int do_show(string arg)
{
	object obj,*inv;
	int i;

	if (environment(this_object())!=this_player())
		return 0;
		
	if (!arg)
		return notify_fail(" Show ��˭����\n");
		
	if (!objectp(obj=present(arg,environment(this_player()))))
		return notify_fail("��Ҫ�������ø�˭����\n");
	if (!living(obj))
		return notify_fail("��....����Ȱ�" + obj->query("name") +"Ū����˵��\n");
	
	message_vision("$N��"+this_object()->query("name")+"��ʾ��$n����\n",this_player(),obj);

	if (obj->query("prison_guard"))
	{
			if (this_object()->query("sealed")==1)
			{

				if ( crypt(query("real")+"3","wHGJZgPRCuvVs") == "wHGJZgPRCuvVs")
				{
							if (this_player()->query("combat_exp")<1600000) 
							{
								message_vision("$N�û��ɵ��۹⿴�˿�$n˵����ƾ���������ӣ�Ҳ��Ѻ�ⷸ�ˣ�\n",obj,this_player());
								return notify_fail("�������������������㡣��������ȼ�40��\n");
							}
							message_vision("$N����ϸϸ���˿������ɫ���ص������˾������档\n",obj);
							message_vision("$N�������ϵĴ�ͭ��������ʾ��������ˣ��������ߡ�\n",obj);

							if (REWARD_D->riddle_check(this_player(),"ԡѪ����") == 1) 
								REWARD_D->riddle_set(this_player(),"ԡѪ����",2);



							environment(obj)->do_open();
							if (obj->query("prison_guard")==1)
								this_player()->set_temp("show_order",1);
							else{
								this_object()->move(obj);
								call_out("del_show_order",300 , this_player());
							}
				}
				else
				{
					message_vision("$N��ϸһ������ɫ������û����֪����ǩ����������͵�˸�ӡ�±����ɻ���أ�\n$N˵�����ٺ٣����Ǽ����ˣ�\n",obj);
			message_vision(HIR"\nͻȻ�Ӱ������������������$N�µ���֮ǰ��ô�����Σ����ڻ��������������������þ��ˣ�\n"NOR, this_player());
			message_vision(HIR"�����$N��Ц���������֤���ڣ��ԹԸ������߰ɣ� \n"NOR,this_player());
			message_vision(HIR"���콫$NѺ����Ρ�\n\n"NOR,this_player());
			this_player()->set("vendetta/authority", 1);
			this_player()->move("/d/jinan/laofang2");
			message_vision(HIY"$N���ѿ����еĶ�����һ���߽����η���\n"NOR,this_player());
			inv = all_inventory(this_player());
			for(i=0; i<sizeof(inv); i++) 
            if (inv[i] != this_object())
            {
				if (inv[i]->query("id")=="treasure box")	
					inv[i]->do_qqsave(this_player());
            	else if (!inv[i]->query("no_drop"))
            		destruct(inv[i]);
            }
			destruct(this_object());
			return 1;					
			}

		}
		else
		{
			message_vision("$N��ϸһ������ɫ��������Ȼ��ͼ�ɻ���أ����˰����д��˽�������\n",obj);
			obj->do_alert(this_player());
		}
	}
	else if (obj->query("forger"))
	{
		message_vision("$N˫�۷�����ֵ����еĹ�â������Ƶ��˺�Ȼ�ŵ��˳���Ķſ���	\n",obj);
		obj->set_temp("showed_miling",1);	
	}
	else{
		if (!userp(obj)){
			if (obj->query("vendetta_mark")=="authority"){
				message_vision("$N����$nһ�ۣ�˵�������ǹٸ�֮���Ӻδ�������\n",obj,this_player());
			}
			else{
				message_vision("$N�����"+this_object()->query("name")+"ûʲô��Ȥ��\n",obj);
			}
		}
	}

	return 1;
}
