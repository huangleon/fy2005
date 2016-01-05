/*

Reminder: PPL's corpses will be moved to /d/fy/hiretem when maze is destructed

		if ( num>1)		// Team has several possibilities
			switch (random(num+1)) {
				case 0:		nn = 2;	act[2] = "���»����ޱȣ����赥��ǰ����";break;		// Single dungeon, only owner can enter
				case 1: 	nn = 3; act[3] = "������Ϊ���ܣ������˶ࡣ";break;		// 2ppl limit
				case 2: 	nn = 4;	act[4] = "";	break;	// No limit on boss, but narrow passage for 1 ppl somewhere in dungeon.
				default:	nn = 5;	act[5] = "";	break;	// No limit, normal dungeon, NPC scaled to ppl number
		}else {
			nn = 1;
			act[1] = "";
		}				// single normal dungeon	
*/

inherit ROOM;
#include <ansi.h>
object *get_players();

void create()
{
}


void setup_room_desc(object room,int length, int width, int x, int y,int z) {
	
	int exit_number;
	string name;
	if (z == 1)
		name = "��";
	else
		name = "��";
	
	if (y == 0)
		name += "��";
	else if (y == 1)
		name += "��";
	else
		name += "��";

	if (x == 0)
		name += "��";
	else if (x == 1)
		name += "��";
	else
		name += "��";

	exit_number= sizeof(room->query("exits"));
	if (exit_number == 3)
		name += "��";
	else if (exit_number == 2)
	{
		if (random(2))
			name += "·";
		else
			name += "��";
	}
	else
			name += "��";


	room->set("short",HIB BLK+name+NOR);
	room->set("long",@LONG

LONG
	);
	
}

void setup_room_obj(object room,int length, int width, int x, int y,int z)
{
	room->set("x",x);
	room->set("y",y);
	room->set("z",z);
    room->set_max_encumbrance(100000000000);

	room->setup();
}

/*
int destruct_maze()
{
	object user;
	user=find_player(query("mark_ob"));
	if (!user)
		return 0;	// �ȴ�600�����ٺ�ʽ��������
	user->query("private_maze/maze")->remove_all_players(user->query("private_maze/maze"),user->query_temp("maze_entry"),"ͻȻ����һ��������Ѱ�ĺ��������ŵ���æ����Թ���\nתͷ��ȥ�������Թ��Ѿ���������Ρ�\n");
	user->query("private_maze/maze")->refresh_maze();
	return 1;
}*/



int setup_entry_room()
{
//	add_action("do_out","out");
	return 1;
}

int init()
{
	object boss,user,blocker,room2;
	int diff, type;
	
//	user=find_player(query("owner"));

	if (query("entry_room")) {
		add_action("do_out","out");
	}
	
	if (query("exit_room")) {
		add_action("do_burn","burn");
	}
	
	/*
			room2->set("maze/owner", me);
			room2->set("maze/exp", s_quest[i]["exp"]); 
			room2->set("maze/exit", me->query("private_maze/destination"));
			room2->set("maze/name", me->query("private_maze/orig_name"));
			room2->set("maze/boss","/obj/dungeon/boss");	
			room2->set("maze/blocker","/obj/dungeon/blocker");	
	*/
	
	seteuid(getuid());
	
	room2 = find_object("/obj/dungeon/standardmaze/"+ query("mark_ob")+"/entry");
	if (!room2) {
		write ("something is wrong, call wizards, error 32323\n");
		return 1;
	}
	type = room2->query("maze/type");

/*	type :
	act[1] = "���»����ޱȣ����赥��ǰ��";		break;		// Single dungeon, only owner can enter
	act[2] = "�ô���Ϊ���գ�����Ҹ�����";		break;		// 2ppl limit, bandit/boss is a bit harder
	act[3] = "�ô���Ϊ���գ����Я��������ͬ��";	break;	// 3ppl limit, 2 blockers per spot
*/
	
	if (query("exit_room") && !query("exist"))	// �����Է���setup-exit�e
	{
		boss=new(room2->query("maze/boss"));
		if (!boss)
			return notify_fail("Error #13765. Please call wizard.\n");
		set("exist",1);
		
		boss->set("maze/name",room2->query("maze/name"));
		if (type == 3) {
			boss->set("attitude", "aggressive");
			if (room2->query("maze/exp")>= 7000000)
				boss->set("dd",2);
		}

		boss->invocation(room2->query("maze/exp"));
		boss->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));		
		boss->move(this_object());

/*		CHANNEL_D->do_sys_channel("sys",sprintf("created one %O %d\n", 
				room2->get_players(),sizeof(room2->get_players())
				));*/
				
		if(type == 3 || (type == 2 && random(2)) || sizeof(room2->get_players())>1 ) {
			blocker=new(room2->query("maze/blocker"));
			blocker->set("maze/name",room2->query("maze/name"));
//			if (type == 3  && room2->query("maze/exp")>= 7000000)	blocker->set("dd",2);
			blocker->invocation(room2->query("maze/exp"));
			blocker->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));
			blocker->move(this_object());
		}	
	}

	if (!query("exit_room") && !query("exist") && !query("entry_room"))	// �����Է���setup-exit�e
	{
				
		blocker=new(room2->query("maze/blocker"));
		if (!blocker)
			return notify_fail("Error #13764. Please call wizard.\n");
		set("exist",1);
		
		blocker->set("maze/name",room2->query("maze/name"));
		if (type == 1)
			blocker->set("toughness",65);
		else if (type == 2)
			blocker->set("toughness",80);					
		blocker->invocation(room2->query("maze/exp"));
				
		if ( type == 3) {
			blocker->set("attitude","aggressive");
		}

		blocker->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));
		blocker->move(this_object());
		set("blocker",blocker);
	
		if (type == 3 || (type==2 && !random(5-sizeof(room2->get_players())))) {
			blocker=new(room2->query("maze/blocker"));
			blocker->set("maze/name",room2->query("maze/name"));
			if (type == 3  && room2->query("maze/exp")>= 7000000)	blocker->set("dd",2);
			blocker->invocation(room2->query("maze/exp"));
			blocker->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));			
			blocker->move(this_object());
		}
	}
	return 1;
}

int valid_enter(object who){
	
	if (!query("entry_room") && !environment(who)->query("exit_room") && !environment(who)->query("entry_room"))
		return (environment(who)->query("cleared")|| query("cleared"));
	else
		return 1;
}

int do_out()
{
	object me = this_player();
	object room, e_room;
	
	room = environment(me);
	if (!room->query("maze/exit")
		|| !(e_room = find_object(room->query("maze/exit"))))
		
		return notify_fail("Error #13766. Please call wizard.\n");
	
	me->move(e_room);
	return 1;
}


object *get_players(){
	
	string fname;
	int x,y,z, l, m, h;
	object *maze_objs = ({}),*inv, link_room, room2;
	
	room2 = this_object();
	if (!room2->query("entry_room"))	return 0;
	
	fname = "/obj/dungeon/standardmaze/";
	fname += room2->query("mark_ob");
	
//	CHANNEL_D->do_sys_channel("sys", fname+"\n");
	
	if( objectp(link_room = find_object(sprintf("%s/entry",fname))) )
	{
		inv = all_inventory(link_room);
		for (int i = 0;i < sizeof(inv) ; i++)
			if (userp(inv[i]))
				maze_objs += ({ inv[i] });
	}

//	CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",maze_objs ));

	if( objectp(link_room = find_object(sprintf("%s/exit",fname))) )
	{
		inv = all_inventory(link_room);
		for (int i = 0;i < sizeof(inv) ; i++)
			if (userp(inv[i]))
				maze_objs += ({inv[i]});
	}
//	CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",maze_objs ));
	
	l = room2->query("x/l");
	m = room2->query("x/m");
	h = room2->query("x/h");
	
	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(link_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z)))){
						inv = all_inventory(link_room);
						for (int i = 0;i < sizeof(inv) ; i++)
						if (userp(inv[i]))
							maze_objs += ({inv[i]});
				}
//	CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",maze_objs ));
	maze_objs -= ({0});
	return maze_objs;
}


/*

obj/dungeon/standardmaze/silencer/entry->query("maze") = ([ sizeof() == 11
  "reward" : 1,
  "npc_killed" : 3,
  "type" : 2,
  "npc_pfm_chance" : 30,
  "blocker" : "/obj/dungeon/blocker",
  "exp" : 7000000,
  "boss" : "/obj/dungeon/boss",
  "sig" : obj/dungeon/standardmaze,
  "pwd" : 123,
  "name" : "ħǹ���ڹ�",
  "exit" : "/d/wiz/demoroom.c",
])

*/




int check_quest(int type){

	object room2, *rewardee, quester;
	int done,d_bonus,reward;
	
	room2 = this_object();
	if (!room2->query("entry_room"))	return 0;

	type = room2->query("maze/type");
	
	// Each Bandit counts as + 100% quest reward
	d_bonus = room2->query("maze/npc_killed")>= (9+type) ? (9+type): room2->query("maze/npc_killed");
	d_bonus = d_bonus*100;
	
	// There surely is a leader who counts as 120.
	d_bonus += 150 * room2->query("maze/leader_killed");
	
	switch (type) {
		case 2: d_bonus = d_bonus* 13/10; break;	// ���� 30% reward
		case 3: d_bonus = d_bonus* 17/10; break;	// ���� 70% reward	
		default:	break;
	}
		
	rewardee = get_players();
	if (!rewardee)	return 1;	// û�����ͣ�����ɡ�
	quester = find_player(room2->query("owner"));
	if (!quester) {
		tell_object(this_player(),HIR"���������������֮زز�������޷����������ǵ��������ɡ�\n"NOR);
//		room2->query("maze/sig")->refresh_maze();	// �ݻ� Maze
		return 1;
	}	// ���ǲ�Ҫ���Թ��������Թ�����������ߣ��Ա��ڴ���
	
	environment(this_player())->set("burned",1);	// ��ֹ����
	
	CHANNEL_D->do_sys_channel("sys",sprintf("Maze type %d, quester is %O, blocker killed %d, leader killed %d,
ppl inside %O. d_bonus is calculated to be %d \n", 
							room2->query("maze/type"),
							quester,
		 					room2->query("maze/npc_killed"),
		 					room2->query("maze/leader_killed"),
		 					rewardee,
		 					d_bonus ));
		
	QUESTS_D->dungeon_reward(quester, "������ɮ������", rewardee, d_bonus);
	room2->query("maze/sig")->refresh_maze();	// �ݻ� Maze
		
	return 1;	
}


int do_burn(){
	
	object ob,room2, me=this_player();
	int burned;
	
	if (ob=present("bandit",environment(me)) || ob=present ("bandit leader",environment(me))){
		tell_object(me,ob->name()+"˵�������ʲô��\n");
		return notify_fail("");
	}
	else if (!environment(me)->query("burned"))
		{
			room2 = find_object("/obj/dungeon/standardmaze/"+ query("owner")+"/entry");
			if (!room2){
				tell_object(me, "Error code dungeon 21230, please inform wiz\n");
				return 1;
			}
			room2->check_quest(1);
	} else
		tell_object(me,"����ط��Ѿ����ջ��ˡ�\n");	
	return 1;
}	

