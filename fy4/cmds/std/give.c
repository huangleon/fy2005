// give.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// Last modification:
//		- 07/17/2001 by Daniel Q. Yu.
//			* Fix messages for give command.
//			* Changed the log message.

inherit F_CLEAN_UP;
string *files;

int do_give(object me, object obj, object who);

void create() {
	seteuid(getuid());
	files=explode(read_file("/adm/etc/give_deny"),"\n");
}

int main(object me, string arg) {
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) {
		return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");
	}

	if(sscanf(arg, "%s to %s", item, target)==2 || sscanf(arg, "%s %s", target, item)==2 );
	else {
		return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");
	}

	if(!objectp(who = present(target, environment(me)))) {
		return notify_fail("����û������ˡ�\n");
	}

	if(who->query_temp("is_unconcious"))
		return notify_fail("���������޷�������������\n");


	if ( userp(who) && sizeof(all_inventory(who))>=26)
		return notify_fail("�����Ѿ�����̫�ණ���ˣ�\n");

	if(!living(who)) {
		return notify_fail("����û������ˡ�\n");
	}

	if(me == who) {
		return notify_fail("������Ҫ�����ֶ�����\n");
	}

	if(userp(me) && who->query("env/no_give"))
		return notify_fail("���˲�Ը�����κ�������Ʒ��\n");
		
	if (environment(me)->query("tianji_square")) {
		if (userp(who) && userp(me))
			return notify_fail("����㳡�˶����ӣ����ʺ������ף������ط��ɡ�\n");
	}
	
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( obj->query("no_drop") && userp(who))
			return notify_fail("�����������������ˡ�\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û��������" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));


			if(!do_give(me, obj2, who)) {
				obj->set_amount( (int)obj->query_amount() + amount );
				return 0;
			}
			return 1;
		}
	} else if(item=="all") {
		if (environment(me)->query("tianji_square")) 
			return notify_fail("�������˵������������ô�ණ��������۶����ˡ�\n");
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		return 1;
	} else {
		if(!objectp(obj = present(item, me)))
			return notify_fail("������û������������\n");
		return do_give(me, obj, who);
	}
}

int do_give(object me, object obj, object who) {
	string str, name;
	object your_item, *your_inv;
	int j;

	if(obj->query("no_drop")&& userp(who)) {
		return notify_fail("�����������������ˡ�\n");
	}

	if (userp(who) && sizeof(all_inventory(who))>=26)
		return notify_fail("�����Ѿ�����̫�ණ���ˣ�\n");


//	not a good fix.. but a temperory one to fix making weapon/armor then give to NPCs.
	if (obj->query("owner"))
		return notify_fail("˽����Ʒ���������ˡ�\n");


	if ( obj->query("lore")) {
		your_inv = all_inventory(who);
		for(j=0;j<sizeof(your_inv);j++){
			your_item = your_inv[j];
			if(obj->query("name")==your_item->query("name")
				&& your_item->query("lore"))
			return notify_fail("�������������ֻ��ӵ��һ����\n");
			}
	}

	// check for dynamic_quests
	if(obj->query("dynamic_quest") && TASK_D->quest_reward(me,who,obj)) {
		return 1;
	}
		// check for flower delivery quests

	if(obj->query("delivery") && QUESTS_D->flower_delivery_reward(me,who,obj)) {
		return 1;
	}

		// check for perform reward
	if(obj->query("pfm_r1") && F_ABILITY->pfm_r1_book_reward(me,who,obj)) {
		return 1;
	}
		
	name = file_name(who);
	message_vision("$N�ݸ�$nһ" + obj->query("unit") + obj->name() + "��\n", me, who);
	if(!interactive(who)) {
		if(!who->accept_object(me, obj)) {
			str = query_notify_fail();
			return notify_fail(str? str : who->name() + "����Ҫ���" + obj->name() + "��\n");
		}
	}
//	A reminder here, don't destroy "who" in accept_object(). or it will cause error.
	
	log_file("ERROR_DEBUG",sprintf("target %s is destroyed when executing give command.\n",name));
	
	if(member_array(base_name(obj),files)!=-1) {
		str = sprintf("(%s) \n%s(%s) give %s(%s) to %s(%s)\n", ctime(time()),
			me->name(), userp(me)? me->query("id") : base_name(me),
			obj->name(), base_name(obj),
			who->name(), userp(who)? who->query("id") : base_name(who));
		log_file("GIVE_LOG", str);
	}

	if(!userp(who) && !who->query("can_carry")) {
		destruct(obj);
	} else if(!obj->move(who)) {
		return 0;
	} else if (obj->query("no_transfer"))
		obj->set("no_drop",1);
		
//	write(sprintf("��¼�ǡ���%O\n",files));
//	write(sprintf("��ǰ��Ʒ�ǣ�%s\n",base_name(obj)));
//	write(sprintf("�Ƿ��Ǽ�¼�еģ�%d\n",member_array(base_name(obj),files)));

//	if ( wizardp(me) )log_file("GIVE_LOG", str);

	return 1;
}
int help(object me) {
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	give <��Ʒ����> to <ĳ��>
      		�� : give <ĳ��> <��Ʒ����>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ��
����㲻Ը�����������Ʒ������set no_give 1

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
