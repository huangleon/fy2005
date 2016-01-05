// corpse.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
//	10/24/2002 by silencer
//	---- removed wield(), equip() for corpse in both chard and here.

inherit ITEM;

int decayed;

void create() {
	set_name("����ʬ��", ({ "corpse" }) );
	set("long", "����һ������ʬ�塣\n");
	set("unit", "��" );
	set("no_reset",1); // Will destruct itself
	decayed = 0;
	if( clonep(this_object()) ) {
//		call_out("release_stuff",0); --- chard.c�ﱾ����û��Ҫ��ʬ�崩����
		call_out("decay", 120, 1);
	}
}
int is_charater = 1;
int is_corpse() { return decayed < 2; }
int is_character() { return is_charater; }
int is_container() { return 1; }

string short() { 
	return name() + "(" + capitalize(query("id")) + ")"; 
}

void decay(int phase) {
	int time;
	decayed = phase;
	switch(phase) {
		case 1: 
			message_vision("$N��ʼ�����ˣ�����һ�����ŵĶ����\n", this_object());
/*			switch(query("gender")) {
				case "����": 
					set_name(name+"���õ���ʬ", ({ "corpse", "ʬ��" }) );
					break;	
				case "Ů��":
					set_name(name+"���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
					break;				
				default:
					set_name(name+"���õ�ʬ��", ({ "corpse", "ʬ��" }) );
					break;
			}*/
			
			set("long", "���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
			
			time = 600;
			
			if (environment())
			if (environment()->query("no_death_penalty"))
				time = 120;
					
			if (!query("player") && !query("boss"))
				call_out("decay", 120, phase + 1);
			else 
				call_out("decay", time, phase + 1);
			break;
		case 2:
			message_vision("$N���紵Ǭ�ˣ����һ�ߺ��ǡ�\n", this_object());
            set_name("��Ǭ�ĺ���", ({ "skeleton", "����" }));
			set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
			is_charater = 0;
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			message_vision("һ��紵������$N���ɹǻҴ�ɢ�ˡ�\n", this_object());
			if(environment()) {
				object *inv;
				int i;
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) {
					if (!query("player")) destruct(inv[i]);
					else {
						if((int) inv[i]->query("no_get") 
								|| ((int) !inv[i]->value() && (int) !inv[i]->query("value"))) {
							inv[i]->move(VOID_OB);
							destruct(inv[i]);
						} else {
							inv[i]->move(environment());
						}
					}
				}
			}
			this_object()->move(VOID_OB);
			destruct(this_object());
			break;
	}
}

/*
void release_stuff(){
	int i;
	mixed *inv;
	object poorcorpse;
	
	poorcorpse = this_object();
	
	inv = all_inventory(poorcorpse);
	if(sizeof(inv)) {
		for(i=0; i<sizeof(inv); i++) {
			inv -= ({ 0 });
			if(sizeof(inv)) {
				if(inv[i]->query("equipped")) {
					inv[i]->unequip();
				}
			}
		}
	}
}*/

object animate(object who, int level) {
	object zombie;
	string name;
	int zskill;
	
	if(!environment()) {
		return 0;
	}
	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name( (string)query("victim_name") + "�Ľ�ʬ", ({ "zombie" }) );
	zombie->move(environment());
	zombie->animate(who, level);
	destruct(this_object());
	return zombie;
}
 
