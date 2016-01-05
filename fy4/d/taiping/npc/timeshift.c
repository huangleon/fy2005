#include <ansi.h>
#include <command.h>

// inherit SMART_NPC;
/*	ʱ���б�ο�

mapping *day_phase = ({
	([	"start_at"	:	0,
		"event_msg"	: 	"���ƺ����������İ������",
		"desc_msg"	:	"ҹĻ�ʹ�������һƬ����",
	]),
	([	"start_at"	:	240,
		"event_msg"	: 	"������������𽥳�����һ˿��ǰס�",
		"desc_msg"	:	"��������ո���һ˿����ɫ",
	]),
	
	([	"start_at"	:	360,
		"event_msg"	: 	"���������Խ��Խ�����������ֺ�ɫ��",
		"desc_msg"	:	"��ϼ�ڶ����ĵ�ƽ���ϸ���",
	]),
	([	"start_at"	:	480,
		"event_msg"	: 	"����ƺ�Խ��Խ��ֱ�ˡ�",
		"desc_msg"	:	"����ʼ����˷����������Ѿ���������",
	]),
	([	"start_at"	:	660,
		"event_msg"	: 	"���������ߣ��ƺ��Ѿ��������ˡ�",
		"desc_msg"	:	"���絽�ˣ�æµ�������ƺ�������һЩ",
	]),
	([	"start_at"	:	900,
		"event_msg"	: 	"���߿�ʼ������ƫ����",
		"desc_msg"	:	"�����ƺ���ʼƫ��������",
	]),
	([	"start_at"	:	1080,
		"event_msg"	: 	"��ϼ�����������ӳ��һƬ��졣",
		"desc_msg"	:	"һ��������ϼ���ǻ��������ĵ�ƽ����",
	]),
	([	"start_at"	:	1260,
		"event_msg"	: 	"�԰׵Ĵ��������ȫ��û�����һ˿������",
		"desc_msg"	:	"ҹĻ���֣���Χ���������˺ڰ���",
	])
});

*/


void time_greet(object ob); 

void shifting(object me) {
	
	object ob, start_room,end_room;
	mixed *current_time;
	string my_position, *type;
	int i;
	
	mapping shift_msg = ([
	"day_arrive"		: "$NЦ�Ǻǵ��߹���˵�������죬�����������á���\n",
	"day_leave" 		: "$N�Ҵ�ææ���뿪�ˡ�\n",
	"night_leave"		: "$N̽ͷ���˿���ɫ���漴�������˳�ȥ��\n",
	"night_arrive"		: "$Nһ����������˹�����\n",
	"dinner_leave"		: "$N���˸�����˵�����Է���ʱ�䵽ඡ���\n",
	"dinner_arrive"		: "$N�߹�������������������\n",
	"after_dinner"		: "$N����������˸����ã��߳����š�\n",
	"back_dinner"		: "$N���ŷ������˹�����\n",
	]);
	          
	ob=this_object();
	current_time=NATURE_D->get_current_time();
	
	if( !me || environment(me) != environment() ) return;
	if (ob->is_fighting()) return;

//	setting up default routine messages
        type=keys(shift_msg);     
        for (i=0;i<sizeof(type);i++) {
               if (this_object()->query("shift/"+type[i]))
			shift_msg[type[i]]=this_object()->query("shift/"+type[i]);                               
        }      

	
	my_position=file_name(environment(ob));

//	check to see if the NPC has dinner routine: hehe, ��ʵ����lunch.
	if (ob->query("dinner_room")) {
		if (current_time[5]<800 && current_time[5]>600)
		if (my_position==ob->query("day_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("dinner_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("dinner_room")); 
			message_vision(shift_msg["dinner_leave"],ob);
			ob->move(end_room);
			message_vision(shift_msg["dinner_arrive"],ob);
			time_greet(ob);
		}
		if (current_time[5]>800 || current_time[5]<600)
		if (my_position==ob->query("dinner_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("day_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("day_room")); 
			message_vision(shift_msg["after_dinner"],ob);
			ob->move(end_room);
			message_vision(shift_msg["back_dinner"],ob);
			time_greet(ob);
		}
	}

//	check to see if the NPC has night routine	
	if (ob->query("night_room"))  {
		if (current_time[5]<240||current_time[5]>1080)
		if (my_position==ob->query("day_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("night_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("night_room")); 
			message_vision(shift_msg["night_leave"],ob);
			ob->move(end_room);
			message_vision(shift_msg["night_arrive"],ob);
			time_greet(ob);
		}
	
		if (current_time[5]>=240 && current_time[5]<=1080)
		if (my_position==ob->query("night_room")) {
			start_room=environment(ob);
			end_room=find_object(ob->query("day_room"));
			if(!objectp(end_room)) 
	        		end_room = load_object(ob->query("day_room")); 
			message_vision(shift_msg["day_leave"],ob);
			ob->move(end_room);
			message_vision(shift_msg["day_arrive"],ob);
			time_greet(ob);
		}
	}

}


void time_greet(object ob) {
	object *inv;
	int i;
	
	inv=all_inventory(environment(ob));
	if (sizeof(inv)<=1) return;
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]==ob) continue;
		if (!inv[i]->is_character()) {
			command("hmm "+inv[i]->get_id());
			break;
		}
		command("greet "+inv[i]->get_id());
		break;
	}
	
}