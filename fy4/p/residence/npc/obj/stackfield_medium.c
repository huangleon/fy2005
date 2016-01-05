#include <ansi.h>
inherit ITEM;

#define MAX_ITEM 130

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);	

void create()
{
	set_name("������", ({ "stack field"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set_max_encumbrance(8000000);
	set("unit", "��");
	set("prep","in");
	set("desc", "һ�������������������ѡ�\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("outdoors",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","a");
	set("size",3);
	set("lore_item",1);
	set("value", 250000);
	seteuid(getuid());
}



// ����present()���efun,�����"name"�ıȽ� by siso_20050606 
object present(mixed str, object env) 
{ 
   object *inv; 
   int n; 

   if( !env->query_max_encumbrance() ) 
       return 0; 
   inv = all_inventory(env); 
   if( !sizeof(inv) ) 
       return 0; 
   if( str ) { 
       str = replace_string(str, "$BLK$", BLK); 
       str = replace_string(str, "$RED$", RED); 
       str = replace_string(str, "$GRN$", GRN); 
       str = replace_string(str, "$YEL$", YEL); 
       str = replace_string(str, "$BLU$", BLU); 
       str = replace_string(str, "$MAG$", MAG); 
       str = replace_string(str, "$CYN$", CYN); 
       str = replace_string(str, "$WHT$", WHT); 
       str = replace_string(str, "$HIR$", HIR); 
       str = replace_string(str, "$HIG$", HIG); 
       str = replace_string(str, "$HIY$", HIY); 
       str = replace_string(str, "$HIB$", HIB); 
       str = replace_string(str, "$HIM$", HIM); 
       str = replace_string(str, "$HIC$", HIC); 
       str = replace_string(str, "$HIW$", HIW); 
       str = replace_string(str, "$NOR$", NOR); 
   } 
   for(n=0; n<sizeof(inv); n++) { 
       if ( str ==  inv[n]->name() || str == (inv[n]->query("id")) ) 
           return  inv[n]; 
   } 
   return efun::present(str, env); 
} 



int is_container() {return 1;}
int is_closed(){	return userp(environment());}

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");
	else 
	{
	add_action("do_putitem","put");
	add_action("do_getitem","get");
	}
   	add_action("do_look","look");
   	add_action("do_dismantle","dismantle");
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
	if (!present("dismantle statue",me))
		return notify_fail("��û�к��ʵĹ����Խ��в����\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("����#13108��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	message_vision(CYN"$Nһ�������������ʯ����"+name()+"����ȥ�������¾Ͱ�"+name()+"�ҵ�ϡ�á�\n\n"NOR,me);
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
	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}

int do_look(string arg)
{

	mixed *inv;
	string *apply, msg, prep;
	mapping prop;
	int i;
    object obj;
              
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
	if (wizardp(this_player()))
		set("long",query("desc")+"��ϸ��ȥ����Լ�ɼ�����С�֣��������졣\n");


        obj = this_object();  
        write(obj->long());
        
        inv = all_inventory(obj);
                switch((string)obj->query("prep")) {
                        case "on":
                                prep = "��";
                                break;
                        case "under":
                                prep = "��";
                                break;
                        case "behind":
                                prep = "��";
                                break;
                        case "inside":
                                prep = "��";
                                break;
                        default:
                                prep = "��";
                                break;
                        }

		write("�������У�\n");
		for (i=0; i<sizeof(inv); i++)
			write(inv[i]->short()+"\n");
		

		return 1;
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

int reset_item_list(object dest)
{
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
		if (env->query("allow_to_loot")) {
			if (env->query("death_time")+15 > time()) {
				if ( member_array( me,env->query("allow_to_loot")) == -1
					&& env->query("victim_name")!= me->query("name"))
						return notify_fail("�����ڻ������������������\n");
			}
		}
	
		for(i=0; i<sizeof(inv); i++) {
			
			if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
				|| inv[i]->query("no_get") || inv[i]->query("lore")) continue;
			
			if (inv[i]->query("allow_to_loot")) {
			if (inv[i]->query("death_time")+15 > time()) {
				if ( member_array( me,inv[i]->query("allow_to_loot")) == -1
					&& inv[i]->query("victim_name")!= me->query("name"))
						return notify_fail("�����ڻ������������������\n");
				}
			}
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

//	15 sec corpse loot protection. Only killer/self can loot the corpse.	
	
	if (env->query("allow_to_loot")) {
		if (env->query("death_time")+15 > time()) {
			if ( member_array( me,env->query("allow_to_loot")) == -1
				&& env->query("victim_name")!= me->query("name"))
				return notify_fail("�����ڻ������������������\n");
		}
	}
	if (obj->query("allow_to_loot")) {
		if (obj->query("death_time")+15 > time()) {
			if ( member_array( me,obj->query("allow_to_loot")) == -1
				&& obj->query("victim_name")!= me->query("name"))
				return notify_fail("�����ڻ������������������\n");
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
					prep = "��" + old_env->name() + "�з��Ұ��죬�Գ�";
					break;
				default:
					prep = "��" + old_env->name() + "�з��Ұ��죬�Գ�";
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
	info = filter_array(call_out_info(), (: $1[0]==$2 :), obj);
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
                return notify_fail("�㲻������ô����\n");
	if (obj->is_container())
		return notify_fail("�㲻�ܰ�����������һ�������\n");	

	if( obj == dest)
			return notify_fail("�㲻������ô����\n");
	
	if(dest->is_closed())
		return notify_fail("��Ҫ�Ȱ�" + dest->name() + "�򿪡�\n");

	container_size = MAX_ITEM;

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
	if (obj->query("no_stack"))
	{
		tell_object(me,"���������޷���š�\n");
		return 1;
	}
	// -------------------------------------------------------------->
	
	switch((string)dest->query("prep")) {
		case "on" :
			prep = "�ӽ�" + dest->name() + "��";
			break;
		case "under" :
			prep = "�ӽ�" + dest->name() + "��";
			break;
		case "behind" :
			prep = "�ӽ�" + dest->name() + "����";
			break;
		case "insdie" :
			prep = "�ӽ�" + dest->name() + "��";
			break;
		default :
			prep = "�ӽ�" + dest->name() + "��";
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
