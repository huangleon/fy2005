#include <ansi.h>
inherit NPC;


int quest();
int change_area();
int change_maze();

void create()
{
	object weapon;
   	set_name("������ɮ", ({ "chuili seng", "seng" }) );
	set("gender", "����" );
	set("age", 191);
	set("title", BLU"����������"NOR);
	set("long","
û����ע�⵽ʲôʱ���𣬳������ж�����һλ��ĺɮ�˹Ҵ��ʹ���˻���
������������Ҳ�ᱻ��ɮһ����ɭɭ����ɱ֮���������鷳����ͷ���������
��һ���ƾɵĶ��ҵ�ס̩�����ݣ������ɮ������������ʮ����С����������
ʱ�����ܻ�о��������¿������ı���Ŀ��΢΢��ʹ��\n");
	
	set("combat_exp", 2000000);
	set("busy_immune",4);
	
	set("attitude", "friendly");
	set("per",1);
	set("NO_KILL","������ɮ����ؿ�����һ�ۣ������ס����һ����ս��ȫ����\n");
	set_skill("magic", 200);
	set_skill("sheolmagic", 200);
	map_skill("magic","sheolmagic");

	set("inquiry", ([
	       	"������֯": (: quest :),
	       	"��֯": 	(: quest :),
	       	"help": 	(: quest :),
	       	"job": 		(: quest :),	
	       	"task":		(: quest :),
	       	"�Ҳ���":	(: change_area :),
    		"lost":		(: change_area :),
    		"fail":		(: change_maze :),
    		"ʧ��":		(: change_maze :),
    ]) );
		
	setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("�����ɮ��", ({ "monk cloth","cloth" }) );
	weapon->set("long","һ��������ԭ����ɫ�İ���ɮ�ۣ���ע�⵽ɮ��һ������ʮ����С����\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name("�����", ({ "hat" }) );
	weapon->set("long","һ���������õĶ��ҡ�\n");
	weapon->set("value",0);
	weapon->wear();
}

int quest()
{
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei","eren",		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
		"biancheng", "zangbei","baiyun" ,"bat","changchun"});
	
	string *c_area =  ({"��ɽ","��ɽ","��ɽ","������","����С��",
				"��ѩɽׯ","ǧ��ɽ","��ƽɽׯ","����ɽ","��Դ��",
				"�½�", "��÷ɽׯ","���˹�",
			    "����ɽ","̩ɽ","���ɽׯ","��ɽ","ǧ��¥", 
			    "�߳�", "�ر�","���Ƶ�","����","������",
			    });
	
	string *word1 =  ({
	"��", "ͭ", "��", "ħ", "��", "��", "ʯ", "��", "��", 
			    });
	string *word2 =  ({
	"צ", "��", "ǹ", "��", "��", "�", "��", "ȭ", "Ӱ", 
			    });
	string *word3 =  ({
	"��", "��", "��", "��", "ʨ", "��", "��", "��", "ӥ", 
			    });
	string *word4 =  ({
	"��", "��", "��", "��", "��", "��", "��", "��", "��", 
			    });
	string *word5 =  ({
	"��", "��", "��", "��", "��", "��", "ɽ", "��", "��", 
			    });
	string arg, room_name, *files,orig_name;
	int i, n, m, nn, mm, size, reward, exp, num,chance;
	object room, silver,room2;
	object me = this_player();
	mapping quest,*s_quest;
	string	*act = ({ " ", "���»����ޱȣ����赥��ǰ��", "�ô���Ϊ���գ�����Ҹ�����","�ô���Ϊ���գ����Я��������ͬ��",});
	string	*aa  = ({ " ", "����", "���", "��������" });			
	object *dungeon_list;

//	testing
//	me->delete("s_quest");
//	testing ends

/*	([	TJ Quest
		"quest":	"̽�ô�����ɮ",
		"long":		"�������˵�����������������֯Ƶ������㲻��ȥ�ҳ�����ĺ��д���������",
		"short":	"ȥ�������Ҵ�����ɮ����������֯������",
		"owner":	"monk",		
		"location":	"������",		
		"duration":	1260,			
//		"cancel": 200,	// CC +200% 
		"difficulty":	400,			
		"exp_l":		6000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),*/
	
/*	if (!query("open")) {
		tell_object(me,"������ɮ���������������ڵ����У���ʱ�رա�\n");
		return 1;
	}*/
		
	if (me->query("quest/quest")!= "̽�ô�����ɮ") {
		tell_object(me,"��վ��Ƭ�̣�������ɮȴ��һ�Բ�����\n");
		return 1;
	}
	
	if ( me->query("quest_time")+ me->query("quest/duration") < time()) {
		tell_object(me,"������ɮ��ü�����㶯��̫�����Ѿ����˴��¡�\n");
		return 1;
	}
				
// ѡ�������ڼ���������
		m = random(sizeof(area));
		arg = "/d/"+area[m] +"/";
		files= get_dir(arg);

		while(1)
		{
			i = random(sizeof(files));
			size = sizeof(files[i]);
//			message_vision("file is "+ files[i] +"\n", me);
			if(files[i][(size-2)..size]==".c")
			{
				room_name = arg + files[i];
				room = find_object(room_name);
				if (!room)
					room = load_object(room_name);
				if (!room)	continue;
				if (!room->query("short")) 		continue;
				if (room->query("no_fly")) 		continue;
				if (room->query("no_fight")) 	continue;	
				if (room->query("underwater")) 	continue;
				break;
			}
		}

// testing
//			room_name = "/d/wiz/demoroom.c";
//			room = find_object(room_name);
// testing ends
			
		orig_name = word1[random(sizeof(word1))];
		orig_name += word2[random(sizeof(word2))];
		orig_name += word3[random(sizeof(word3))];
		orig_name += word4[random(sizeof(word4))];
		orig_name += word5[random(sizeof(word5))];


//	ѡ��Dungeon ����

		chance = random(100);
		if (me->query_team())
			num = sizeof(me->query_team());
		else
			num = 1;
		
		// for soloer, it's either solo dungeon, or 2ppl dungeon.
		// for group, it's solo, 2ppl, or multiple NPC dungeons.
		
		if (num == 1) {				// soloer 80% single, 20% duo
			if (chance>=20)	nn=1;
			else	nn = 2;
		}
		if (num ==2 ) {				// duo 30% chance single, 65% chance duo, 5% chance triplex
			if (chance>=95)			nn=3;
			else if (chance>=60)	nn=1;
				else nn=2;
		}
		
		if (num >=3) {				// triplex 20% chance single, 70% chance duo, 30% chance triple
			if (chance>=80)	nn = 1;
			else if (chance> 30) nn =2;
				else 		nn = 3;
		}
						
		me->set("private_maze/destination", room_name);
		me->set("private_maze/orig_name", orig_name);
		me->set("private_maze/type", nn);		// ����dungeon �����
		me->set("private_maze/difficulty",50);	// this is NPC's chance to perform
//		if (nn==3)	me->set("private_maze/difficulty",50);
		me->set("private_maze/create",1);		// a flag whether you create the maze yet
		me->set("private_maze/adjust",time());	// ����������ֲ������ʵ���Ҳ�������������ÿ���ֻ�һ���ط�����
		
//		write ("nn = "+nn);	
		arg = "����"HIR+orig_name+NOR CYN"�ǳ����񣬾�˵������һ���ݵ�����"+c_area[m]+"��"WHT+room->query("short")+CYN"������ȥ�������"+ act[nn]+"��\n"NOR;
				
		// ���뽫ԭ����Dungeon����, Using owner to search since sometimes the room/link is lost somehow
		dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
		mm = sizeof(dungeon_list);
		for (i=0;i<mm;i++){
			if (dungeon_list[i]->query_owner()== me->query("id")) {
				dungeon_list[i]->refresh_maze();
			}
		}
			
		tell_object(me, arg);
		
		if (me->query("marks/chuili_warning")<5) {
			tell_object(me, YEL"
������ɮ˵�������ҵ������ҵ��Ǹ��ط���ʹ��entermaze������ܽ��룬
�����ʹ��help entermaze�쿴��
���ڻ����ڲ��Խ׶Σ�����Ǹ��ط�ʵ���޷��ҵ���ÿ�������ӿɵ�����
�ﻻ���ط���ask chuili seng about lost�������ͷʵ��̫������ÿ��
�����Ҳ�ɵ������������ط���ask chuili seng about fail��\n"NOR);
			me->add("marks/chuili_warning",1);
		}
		
		
		// �ı����Quest��˵��		
		me->set("quest/quest","������ɮ������");
		me->set("quest/long","��"+c_area[m]+room->query("short")+ "ȥ�����ѽ���");
		me->set("quest/location",c_area[m]+room->query("short"));
		me->set("quest/short",aa[nn]+"��"+c_area[m]+room->query("short")+ "ȥ�����ѽ���");
		me->set("quest/duration",3600);
		me->set("quest/cancel",-1);
		me->set("quest_time",time());
		tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);

// 	testing
		if (wizardp(me)) {
			tell_object(me, sprintf("%O",me->query("private_maze")));
			tell_object(me, sprintf("%O",me->query("quest")));
		}
				
//	testing ends

		return 1;
	
//	return "����������׻ӻ���Ҳ���Լ���ƽʵ��ֻҪ���Ρ������룬���ӾͿ��Թ����������á�����ǰ��ȴ��ôҲ�β�͸��һ�㡣";

}


int change_area(){
	object me = this_player();
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei","eren",		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
		"biancheng", "zangbei","baiyun" ,"bat","changchun"});
	
	string *c_area =  ({"��ɽ","��ɽ","��ɽ","������","����С��",
				"��ѩɽׯ","ǧ��ɽ","��ƽɽׯ","����ɽ","��Դ��",
				"�½�", "��÷ɽׯ","���˹�",
			    "����ɽ","̩ɽ","���ɽׯ","��ɽ","ǧ��¥", 
			    "�߳�", "�ر�","���Ƶ�","����","������",
			    });
	string arg, room_name, *files,orig_name;
	int i, n, m, nn, size, reward, exp, num, dur;
	object room, silver,room2;
		string	*act = ({ " ", "���»����ޱȣ����赥��ǰ��", "�ô���Ϊ���գ�����Ҹ�����","�ô���Ϊ���գ����Я��������ͬ��",});
	string	*aa  = ({ " ", "����", "���", "��������" });			    
	
	if (me->query("quest/quest")!= "������ɮ������") {
		tell_object(me, "������ɮ˵������Ϲ����ʲô��\n");
		return 1;
	}
	
	if (!me->query("private_maze/create")) {
		tell_object(me,"������ɮ˵���㲻���Ѿ��ҵ��˷���ô�����ǰȥ����\n");
		return 1;
	}
	
	if (me->query("quest_time")+ me->query("quest/duration")< time()) {
		tell_object(me,"̫���ˣ������Ѿ��ŷ�ת�ƣ��������ʧ���ˡ�\n");
		return 1;
	}

	dur = me->query("private_maze/adjust")+ 180 - time();
	if (dur > 0 ) {
		tell_object(me,"������ɮ������˵�����Ƿ���ϸ�ҹ�����ȥ��"+ dur+"���Ӱɡ�\n");
		return 1;
	}
		
	// ����ѡ�������ڼ���������
		m = random(sizeof(area));
		arg = "/d/"+area[m] +"/";
		files= get_dir(arg);

		while(1)
		{
			i = random(sizeof(files));
			size = sizeof(files[i]);
//			message_vision("file is "+ files[i] +"\n", me);
			if(files[i][(size-2)..size]==".c")
			{
				room_name = arg + files[i];
				room = find_object(room_name);
				if (!room)
					room = load_object(room_name);
				if (!room)	continue;
				if (!room->query("short")) 		continue;
				if (room->query("no_fly")) 		continue;
				if (room->query("no_fight")) 	continue;	
				if (room->query("underwater")) 	continue;
				break;
			}
		}
		
		me->set("private_maze/destination", room_name);
		me->set("private_maze/adjust",time());
		
		nn = me->query("private_maze/type");
			
		// �ı����Quest��˵��		
		me->set("quest/long","��"+c_area[m]+room->query("short")+ "ȥ�����ѽ���");
		me->set("quest/location",c_area[m]+room->query("short"));
		me->set("quest/short",aa[nn]+"��"+c_area[m]+room->query("short")+ "ȥ�����ѽ���");
		me->set("quest/duration",3600);
		me->set("quest_time",time());
		
		arg = HIR+me->query("private_maze/orig_name")+NOR CYN"��˵�ѰѾݵ��Ƶ�"+c_area[m]+"��"WHT+room->query("short")+CYN"�����ٸ�ȥ�������"+ act[nn]+"��\n"NOR;
		tell_object(me, arg);		
		tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);

// 	testing
		if (wizardp(me)) {
			tell_object(me, sprintf("%O",me->query("private_maze")));
			tell_object(me, sprintf("%O",me->query("quest")));
		}
				
//	testing ends
		
		return 1;
}

int change_maze(){
	object me=this_player();
	object *dungeon_list, room2;
	int i, mm,dur,killed;
	
	if (me->query("quest/quest")!= "������ɮ������") {
		tell_object(me, "������ɮ˵������Ϲ����ʲô��\n");
		return 1;
	}
	
	if (me->query("private_maze/create")) {
		tell_object(me,"������ɮ˵���Ҳ����Ѿ�����������ô����ô������ȥ��\n");
		return 1;
	}
	
	if (me->query("quest_time")+ me->query("quest/duration")< time()) {
		tell_object(me,"̫���ˣ������Ѿ��ŷ�ת�ƣ��������ʧ���ˡ�\n");
		return 1;
	}

	dur = me->query("quest_time")+ 300 - time();
	if (dur > 0 ) {
		tell_object(me,"������ɮ����Ƭ�̵�����ȥ���ԣ����֪���Ƿ����У���ȥ��"+ dur+"���Ӱɡ�\n");
		return 1;
	}
	
		// ��ԭ����Dungeon����
			dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
			mm = sizeof(dungeon_list);
			for (i=0;i<mm;i++){
				if (dungeon_list[i]->query_owner()== me->query("id")) {
					if (dungeon_list[i]->has_player()) {
						tell_object(me,"������ɮ˵�����ͬ�黹������������ǳ���ɡ�\n");
						return 1;
					}
//					CHANNEL_D->do_sys_channel("sys",sprintf("file is %s\n", file_name(dungeon_list[i])));					
					room2 = find_object("/obj/dungeon/standardmaze/" + me->query("id")+"/entry");
					if (room2) {
						if (room2->query("maze/cleared")) {
							tell_object(me,"������ɮ�����˵������ƭ�ң��Ŷ�û�У�\n");
							return 1;
						}
						killed = room2->query("maze/npc_killed");
//						CHANNEL_D->do_sys_channel("sys", sprintf("killed is %d\n", killed));
					}										
					dungeon_list[i]->refresh_maze();
				}
			}

		tell_object(me,"������ɮ˵���������㳢�ԣ�δ�سɹ�����������˵�������˷���������и������ȥ������\n");			
		
		me->set("private_maze/create",1);
		if (killed>=6)
			me->set("private_maze/carried_npc",killed);		// last failed one carried over, if it's failed, at least killed 6
		me->set("quest_time",time());
		tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
			
	// 	testing
		if (wizardp(me)) {
			tell_object(me, sprintf("%O",me->query("private_maze")));
			tell_object(me, sprintf("%O",me->query("quest")));
		}
				
//	testing ends
		
		return 1;
}

		