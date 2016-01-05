#include <ansi.h>
inherit ITEM;
inherit F_ANNIE;

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);	

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");
	else 
	{
		add_action("do_putitem","put");
		add_action("do_getitem","get");
		add_action("do_pick","pick");
	}

   	add_action("do_look","look");
   	add_action("do_dismantle","dismantle");
}

int is_container()
{
	return 0;
}

int do_pick(string arg)
{
	return 0;
}

int is_closed()
{
	if (!environment()) return 1;	
	return userp(environment());
}

int restore_item()
{
	object item;
	mapping item_list,mitem;
	string *lists,str;
	int i,idx;

	item_list = environment()->query("stock_"+query("item_type"));
	if( !mapp(item_list) || !sizeof(item_list) )
			return 1;
	// û���κζ�����
	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
       if (!sscanf(lists[i],"%d",idx)) continue;
		mitem = environment()->query("stock_"+query("item_type")+"/"+lists[i]);
		item = new(mitem["item_basename"]);
		annie_itemmimic(item,mitem["data"],mitem["temp_data"]);
		item->set_name(mitem["item_name"],mitem["item_id"]);
		item->set_amount(mitem["amount"]);
		item->move(this_object());
	}
	return 1;
}


int reset_item_list(object dest)
{
	object room = environment(),obj,*inv;
	mapping item_list,item;
	mapping list,tlist;
	int i,j;
	if (!is_container())
		return 1;

	inv = all_inventory(dest);
	i = sizeof(inv);
	room->delete("stock_"+query("item_type"));
	for (j=0;j<i ;j++ )
	{
		obj = inv[j];
		list = (mapping)obj->query_entire_dbase();
		tlist = (mapping)obj->query_entire_temp_dbase();

			item =
			([
				"item_basename": base_name(obj),
				"data":list,
				"temp_data":tlist,
				"item_name": obj->query("name"),
				"item_id": obj->parse_command_id_list(),
				"amount": obj->query_amount(),
			]);
		room->set(("stock_"+query("item_type"))+"/"+(j+1),item);
	}
	room->save();
	return 1;
}

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
	if (!present("dismantle statue",me))
		return notify_fail("��û�к��ʵĹ��߽��в������Ҫ����ʯ��\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("����#13108��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	message_vision(CYN"$Nһ�������������ʯ����"+name()+NOR+CYN"����ȥ�������¾Ͱ�"+name()+NOR+CYN"�ҵ�ϡ�á�\n\n"NOR,me);
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
	
	// ������Ҫ˵��һ��,����ʹ�ô˲�����annieitem�����ǡ�lore�����ͣ�������ͻ��
	env->delete("stock_"+query("item_type")+"/text");
	env->delete("stock_"+query("item_type")+"/text2");
	env->delete("stock_"+query("item_type")+"/text3");
	
	
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));

	env->add("tax",-query("tax")*7);
	env->add("score_tax",-query("score_tax")*100);

	if (env->query("tax")<0)
		env->set("tax",0);	// ��bug
	if (env->query("score_tax")<0)
		env->set("score_tax",0);	// ��bug
	
	if (query("item_type") == "k")
	{
		// ˮԴ
		env->set("resource/water",0);
	    env->delete("liquid");
	}

	env->save();

	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
//	if (wizardp(this_player()))
//		set("long",query("desc")+"��ϸ��ȥ����Լ�ɼ�����С�֣��������졣\n");
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
//	if (env->query("outdoors") && !query("outdoors") )
//		return notify_fail(name()+"ֻ�ܱ����������ڡ�\n");
//	if (!env->query("outdoors") && query("outdoors") )
//		return notify_fail(name()+"ֻ�ܱ����������⡣\n");
	if (query("lore_item") && env->query("item/"+query("item_type")))
		return notify_fail("���ණ��ÿ��������ֻ�ܷ�һ����\n");
	move(env);
	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));

	env->add("tax",query("tax")*7);
	env->add("score_tax",query("score_tax")*100);

	env->set("item_list/"+env->query("item_index"),base_name(ob));

	if (query("item_type") == "k")
	{
		// ˮԴ
		env->set("resource/water",1);
	    env->set("liquid",query("liq"));
	}

	env->save();
	write("��Ʒ��װ��ϡ�\n");
	return 1;	
}

int do_getitem(string arg)
{
	object me = this_player(),env=this_object();
	string from, item;
	object obj, *inv,  obj2;
	object *my_inv, my_item;
	int i, j, amount, num;
	string arg1, from1;

	if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
	if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
		if (num==0 || num ==1)
			return notify_fail("���ػ���ʹ��get xxx from xxx 0/1��\n");
	}

	if( sscanf(arg, "%s from %s", arg, from)!=2 )
		return 0;
		// ��������getָ���
	if (present(from,environment(me)) != env)
		return 0;

	if (!environment()->is_owner(me->query("id")))
	{
		tell_object(me,"����������ֻ�����˲���ʹ�á�\n");
		return 1;
	}

	if (!is_container())
		return notify_fail("�ⲻ��������\n");

	if (sizeof(all_inventory(me))>=26)
		return notify_fail("���Ѿ�����̫�ණ���ˣ�\n");


	
	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("����û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
		if( amount < 1 )
			return notify_fail("�����ĸ���������һ����\n");
		if( amount > obj->query_amount() ) {
			return notify_fail("����û��������" + obj->name() + "��\n");
		} else if(amount == (int)obj->query_amount()) {
			return do_get(me, obj, env);	
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->move(me);		
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(3);
			return do_get(me, obj2, env);	
		}
	}

	// Check if we are making a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	
			return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if( !env->query_max_encumbrance() )	return notify_fail("�ǲ���������\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("������û���κζ�����\n");
		
	//	15 sec corpse loot protection. Only killer/self can loot the corpse.	
	
		for(i=0; i<sizeof(inv); i++) {
			
			if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
				|| inv[i]->query("no_get") || inv[i]->query("lore")) continue;
			
			do_get(me, inv[i], env);	
		}
		write("Ok��\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry")))
		return notify_fail("�㸽��û������������\n");

	if( obj->query("no_get") )
		return notify_fail("��������ò�������\n");

// 	lore item, you can only own one in your inventory at a time
	if ( obj->query("lore")) {
		my_inv = all_inventory(me);
		for(j=0;j<sizeof(my_inv);j++){
			my_item = my_inv[j];
			if(obj->query("name")==my_item->query("name")
				&& my_item->query("lore"))
			return notify_fail("�������������ֻ����һ����\n");
			}
	}


	
	return do_get(me, obj, env);	
}




int do_get(object me, object obj,object env)	
{
	object old_env, *enemy;
	int equipped;
	object target;
	string	prep;

	target = me;
	if( !obj ) return 0;
	old_env = env;	
	if( obj->is_character()  && !obj->is_corpse()) {
		return notify_fail("�㲻�ܱ������\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

		if (sizeof(all_inventory(me))>=26)
		return notify_fail("���Ѿ�����̫�ණ���ˣ�\n");


	if( obj->query("equipped") ) equipped = 1;
	if( obj->query("yes_carry")) target = environment(me);
	if( obj->move(target) ) {
		if((int)obj->query("no_transfer")){
			obj->set("no_get",1); 
			obj->set("no_drop",1);
		}

		reset_item_list(this_object());

		if(me->is_fighting()) 
			me->start_busy(1);
		if( obj->is_character()  && !obj->query("yes_carry"))
			message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
		else {
			if(old_env==environment(me)) prep =  "����";
			else if(old_env->is_character()) prep =  "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�");
			else switch( old_env->query("prep") ) {
				case "on":
					prep = "��" + old_env->name() + "������";
					break;
				case "under":
					prep = "��" + old_env->name() + "���ó�";
					break;
				case "behind":
					prep = "��" + old_env->name() + "���ó�";
					break;
				case "inside":
					prep = "��" + old_env->name() + "���ó�";
					break;
				default:
					prep = "��" + old_env->name() + "���ó�";
					break;
			};
			message_vision( sprintf("$N%sһ%s$n��\n", prep,
				obj->query("unit")), me, obj );
		}
		return 1;
	}
	else return 0;
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
	
	if (!is_container())
		return notify_fail("�ⲻ��������\n");

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
			{
//				write("1"+inv[i]->query("name"));
				do_put(me, inv[i], dest);
			}
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
	info = filter_array(call_out_info(), (: $1[0]==$2 :), obj);
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
                return notify_fail("�㲻������ô����\n");
	if (obj->is_container())
		return notify_fail("�㲻�ܰ�����������һ�������\n");	

	if( obj == dest)
			return notify_fail("�㲻������ô����\n");
	
	if(dest->is_closed())
		return notify_fail("��Ҫ�Ȱ�" + dest->name() + "�򿪡�\n");

	container_size = query("max_item");

	// �����б�����ͨputָ���˲���return notify_fail�� annie 08.2003
	// <--------------------------------------------------------------
	if (!environment()->is_owner(me->query("id")))
	{
		tell_object(me,"����������ֻ�����˲���ʹ�á�\n");
		return 1;
	}
	if(sizeof(all_inventory(dest)) >= container_size)
	{
		tell_object(me,dest->name() + "�������ֻ�ܷ�" + chinese_number(container_size) +
				"����Ʒ��\n");
		return 1;
	}
/*	if (obj->query("value") < 4)	// �޷��䵱�Ķ�������Ϊ��unique item��
	{
		tell_object(me,"������������ֵ����Ǯ��û��С�ı���ı�Ҫ��\n");
		return 1;
	}*/
	// NO STOCK��Ʒ���ܴ�š�
	// Ǯ���ܴ�š�
	// TASK���ܴ�š�
	// ��CALL OUT�Ķ������ܴ�š�
	if (obj->query("no_stack"))
	{
		tell_object(me,"���������޷���š�\n");
		return 1;
	}
	if (obj->query("money_id"))
	{
		tell_object(me,"���������޷���š�\n");
		return 1;
	}
	if (obj->query("dynamic_quest"))
	{
		tell_object(me,"���������޷���š�\n");
		return 1;
	}
	if (sizeof(info))	
	{
		tell_object(me,"���������޷���š�\n");
		return 1;
	}


	if( obj->query("generate_item") )
		return notify_fail("���ֶ���ֻ�ܴ���ں�ɫ�Ĵ������С�\n");

//	Now we just use ������ to save all temperary items

/*	if (!obj->query("armor_prop") && query("item_type") == "c")				// �³�
	{
		tell_object(me,name()+"��ֻ�ܴ�����\n");
		return 1;
	}

	if (!obj->query("weapon_prop") && query("item_type") == "b")			// ������
	{
		tell_object(me,name()+"��ֻ�ܴ��������\n");
		return 1;
	}

	if (!obj->query("skill/max_skill") && query("item_type") == "d")		// ���
	{
		tell_object(me,name()+"��ֻ�ܴ���鼮��\n");
		return 1;
	}

	if (!obj->query("food_supply") && !obj->query("liquid") && query("item_type") == "e")		// ʳ��
	{
		tell_object(me,name()+"��ֻ�ܴ��ʳˮ��\n");
		return 1;
	}

	if ((obj->query("food_supply") || obj->query("liquid") || obj->query("weapon_prop") 		// others in ��ľ��
		 || obj->query("armor_prop")  || obj->query("skill/max_skill")) &&  query("item_type") == "f")
	{
		tell_object(me,obj->name()+"���ʺϷŵ�ר�õĵط�����Ҫ�����ﶪ��һ��\n");
		return 1;
	}*/

	// -------------------------------------------------------------->
	
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


		reset_item_list(dest);
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
