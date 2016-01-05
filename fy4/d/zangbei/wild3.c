inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ԭ");
        set("long", @LONG
������ԭ�����������š���ɽ����������һƬ�����������ɫƽ���ߣ���ã�
����Ȼ��������˵صȴ������˸ߴ���ǰ������������ƴ��Ĳ�ԭ��Զ����ѩ�嵹
ӳ����������£�������һ���Ÿߴ�İ����������ڱ��ư�Ȼ������������ʮ�
(��·�����轻�����ƽ���С�)
LONG
        );
        set("long_night",@LONG
��ԭ��ҹ�Ǽ�į�ģ���Զ����ĸ߿գ������������ǵ㣬�����棬ҹ���˵ĵ�
��ҡҡ�ڰڣ������ӵ��еĹ�����裬�ڵ�·���ԣ�ȫ�Ǻڳ����İ������֣���ǰ
�棬�ޱߵĲ�ԭ�ڷ���ɪɪ���죬�����Ƶ����������·����ë���Ȼ��(��·����
�轻�����ƽ���С�)
LONG
        );
        
        set("exits", ([ 
		"southeast" : __DIR__"wild2",
		"west" : __DIR__"wild4",
		"south" : __DIR__"woods1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1600);
        set("coor/y",710);
        set("coor/z",0);
        set("no_lu_letter",1);
	set("map","zbwest");
	setup();
	
}


void reset() {
	object badguy,*inv,room,boss,village;
	int count,i;
	mixed current_time;
	string *boss_name=({"baimian langzhong","tu laohu","one eye"});
	string boss1;
	
	::reset();
	
	room=this_object();
	current_time=NATURE_D->get_current_time();

//	in the morning, first reset disappear	
	inv=all_inventory();
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("group")=="longhuzhai") {
			if (current_time[5]<1080 && current_time[5]>360) {
				if (inv[i]->query("id")=="bandit" && !userp(inv[i])) {
					inv[i]->ccommand("say ����Ҳ��������");
					message_vision("$Nһͷ����ϱߵ���������ʧ�ˡ�\n",inv[i]);
					destruct (inv[i]);
				} else {
					room=find_object(AREA_ZANGBEI"village");
					if (!room) destruct (inv[i]);
					else {
						inv[i]->move(room);
						message_vision("$N��ɽկ�������˽�����\n",inv[i]);
					}
				}
				
			} else count++;
		}
	}

//	in the evening, first reset appears
	if (current_time[5]>1080 || current_time[5]<360) {
		if (count<2) {
			for (i=0;i<3;i++)	{
				badguy=new(__DIR__"npc/bandit");
				badguy->set("attitude", "friendly");
				badguy->move(room);
			}
			message_vision("ֻ��ˢ����һ���죬·�Ե�������ܳ��˼������ˡ�\n",badguy);
			badguy->ccommand("say �ºڷ��ҹ��ɱ�˷Ż��졣");
		}	
		if (!present(boss_name[0],room) && !present(boss_name[1],room)
			&& !present(boss_name[2],room))
		for (i=0;i<6;i++) {
			boss1=boss_name[random(sizeof(boss_name))];
			boss=find_real_living(boss1);
			if (boss && !boss->is_fighting()) {
				badguy=present("bandit",room);
				message_vision(CYN"$N�ϻ̳Ͽֵ�˵������Ҳ���ˡ�\n"NOR,badguy);
				message_vision(CYN"$Nһ��������һ��˵������ȥ��������������������������\n"NOR,boss);
				boss->move(room);
				boss->set("attitude","friendly");
				boss->ccommand("pat bandit");
				return;
			}
		}	
	}
	return;
}


int valid_leave(object obj, string dir){
	int i;
	object *inv,*bandit;
	
	if(dir == "west"){
		if (obj->query_temp("wild4_pass") || obj->query("combat_exp")<1000000) return 1;
		inv = all_inventory(this_object());
		for (i=0;i<sizeof(inv);i++) {
			if (inv[i]->query("group")=="longhuzhai") 
				return notify_fail(inv[i]->name()+"˵������ɽ���ҿ������������ԣ�Ҫ���·����������·Ǯ����\n");
		}
		
	}	
	return 1;
}