// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y,int z) {
	
	int exit_number;

		string name;

	name = "������";
	name += chinese_number(z+1);
	name += "��";
	
	exit_number= sizeof(room->query("exits"));
	
 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
	} else 	if (exit_number==1) {		//	Deadend
		room->set("pos","deadend");
	} else {							//	Normal description
		room->set("pos","normal");
	}
	
		room->set("long",@LONG
����������������Ĺ⾰���ྶͥ��ֻ������ǣ�ᣬ�����ܲ�������ķ�
�����̻ң�һ����������䣬�����������̨��֮�ϣ�����������ģ�������
����̴ľ��¥����������������ȥ��
LONG
	);

	room->set("short",MAG+name+NOR);

}

void 	setup_npc_obj(object room,int length, int width, int x, int y, int z)
{
		object icecave;
		int boss_x,boss_y;

		z++;
		
		room->set("objects",([				
			__DIR__"npc/maze_guard"+z:	1,
//			__DIR__"npc/maze_guard"+(random(z)+1):	!random(4),	
		]));	
		
		room->setup();
		
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
